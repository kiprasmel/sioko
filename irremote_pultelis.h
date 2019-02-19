#pragma once

// Siųstuvo nustatymai
const byte RECV_PIN = 30;
IRrecv irrecv(RECV_PIN);
decode_results results;

void pulteliuNustatytiStrategijas();
void lauktiEnterPaspaudimo();
