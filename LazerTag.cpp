#include "LazerTag.h"

LazerTag::LazerTag() {
    _setProtocol();
    setAmmo(10);  // default
    setSpeed(36); // default 36khz
}

LazerTag::LazerTag(int ammo) {
    _setProtocol();
    setAmmo(ammo); // default 10
    setSpeed(36);  // default 36khz
}

void LazerTag::_setProtocol() {
    _protocol.header_mark = 3000;
    _protocol.header_space = 6000;
    _protocol.one = 2000;
    _protocol.zero = 1000;
    _protocol.space = 2000;
}

bool LazerTag::empty() {
    if (_ammo > 0) return false;
    return true;
}


void LazerTag::fire(int damage) {
    // do `damage` amount of damage (1-4)
    if (!empty()) {
        send(damage-1, 7);
        // _ammo -= damage;  // disabled ammo for now (reload not built in yet)
    }
    else {
        Serial.println("EMPTY!");
    }
}

void LazerTag::send(unsigned long data, int nbits) {
    preamble();

    for (int i = 0; i < nbits; i++) {
        _send.space(_protocol.space);
        bool d = data & (1 << (nbits-1));
        if (d) _send.mark(_protocol.one);
        else _send.mark(_protocol.zero);
        data = data << 1;
    }

    _send.space(_protocol.space);
}

void LazerTag::preamble() {
    _send.enableIROut(_speed);
    _send.mark(_protocol.header_mark);
    _send.space(_protocol.header_space);
    _send.mark(_protocol.header_mark);
}
