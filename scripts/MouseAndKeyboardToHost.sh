#!/bin/bash
VMNAME="win10"
virsh detach-device $VMNAME mouse.xml &
virsh detach-device $VMNAME keyboard.xml &

