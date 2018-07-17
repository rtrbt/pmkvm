#!/bin/bash
VMNAME="win10"
virsh attach-device $VMNAME mouse.xml &
virsh attach-device $VMNAME keyboard.xml &

