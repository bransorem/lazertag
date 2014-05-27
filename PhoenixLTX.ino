#include "LazerTag.h"

LazerTag gun;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // start listening for input
}

void loop() {
  char c = Serial.read();
  if (c != -1){
    switch (c) {
      case 49: gun.fire(1); Serial.println("Fired 1 shot"); break;
      case 50: gun.fire(2); Serial.println("Fired 2 shots"); break;
      case 51: gun.fire(3); Serial.println("Fired 3 shots"); break;
      case 52: gun.fire(4); Serial.println("Fired 4 shots"); break;
      default: break;
    }
    irrecv.enableIRIn(); // keep listening for input
  }
  else {
    if (irrecv.decode(&results)) {
//      Serial.println(results.value, HEX);
      if (results.value == 0x3FA025D3) {
        Serial.println("OUCH!");
      }
      irrecv.resume(); // Receive the next value
    }
  }
}
