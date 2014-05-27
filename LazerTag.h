#ifndef _LazerTag_h
#define _LazerTag_h

#include "Arduino.h"
#include "IRremote.h"

typedef struct Protocol {
    int header_mark;
    int header_space;
    int one;
    int zero;
    int space;
} Protocol;

class LazerTag {
public:
    LazerTag();
    LazerTag(int ammo);
    void setAmmo(int ammo) { _ammo = ammo; };
    void setSpeed(int khz) { _speed = khz; };
    bool empty();
    void fire(int damage);
    // void receivePin(int pin);
private:
    Protocol _protocol;
    IRsend _send;
    int _speed;
    int _ammo;
    void _setProtocol();
    void send(unsigned long data, int nbits);
    void preamble();
};


#endif