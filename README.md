I was going to wait to share this but a friend insisted I put it up "NOW!"

## Hardware

* Arduino
* IR LED (940nm or 950nm)
* IR receiver (38khz standard) - 3-pin!

If you're using an Uno, you'll need to use pin 3 for output and pin 11 for input. I'm using the IRremote library (temporarily?) which I've stripped down a bit.

## Usage

This is meant to be prototyped on an Arduino. You'll probably want to use the Arduino serial window for communication. There are 4 modes of firing; if you send '1' it will fire a shot of 1 damage. You can also send '2', '3', or '4' for shots at those damages. You can also shoot the device and it will print "OUCH!" to Serial.


## Roadmap

This is really up in the air at this point, but I plan to add health and several abstractions: game, team, player, weapon.