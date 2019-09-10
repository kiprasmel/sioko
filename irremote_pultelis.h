#pragma once

/** broken */
// #include "IRremote/IRremote.h"
// #include "./IRremote/IRremote.h"

/** actuall works */
#include <IRremote.h>

// Siųstuvo nustatymai
const byte RECV_PIN = 30;
IRrecv irrecv(RECV_PIN);
decode_results results;

void pulteliuNustatytiStrategijas();
void lauktiEnterPaspaudimo();
void lauktiKazkokioMygtukoPaspaudimo();
