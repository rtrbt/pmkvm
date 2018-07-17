// The poor man's KVM switch
#include "Keyboard.h"

const int monitorSwitchPin = 9;
const int MKBSwitchPin = 10;
int prevMonState = HIGH;
int prevMKBState = HIGH;

void sendKeyCombination(char key)
{
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.press(KEY_LEFT_CTRL);  
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);  
}

void checkButton(int buttonPin, int *lastButtonState, char keyToEnable, char keyToDisable)
{
  int buttonState = digitalRead(buttonPin);  
  if (buttonState != *lastButtonState)
    sendKeyCombination(buttonState == HIGH ? keyToEnable : keyToDisable);
  *lastButtonState = buttonState;
}

void setup() {
  // make the pushButton pin an input:
  pinMode(monitorSwitchPin, INPUT_PULLUP);
  pinMode(MKBSwitchPin, INPUT_PULLUP);
  
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  checkButton(monitorSwitchPin,  &prevMonState, 'W', 'S');
  checkButton(MKBSwitchPin,         &prevMKBState, 'R', 'F');
}
