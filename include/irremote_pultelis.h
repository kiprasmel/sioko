#pragma once

#include <IRremote.h>
#include "inicializuoti.h"
#include "strategijos.h"

/** Siųstuvo nustatymai */
extern const byte RECV_PIN;
extern IRrecv irrecv;
extern decode_results results;

void pulteliuNustatytiStrategijas();
void lauktiEnterPaspaudimo();
void lauktiKazkokioMygtukoPaspaudimo();

StrategijosPagalHex lauktiMygtukoPaspaudimoIrGautiMygtukoKoda();
