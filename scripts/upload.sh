#!/bin/sh
# upload.sh

teensy_loader_cli -mmcu=mk64fx512 -w -v ../../build/FooProject/uno/FooProject.hex
