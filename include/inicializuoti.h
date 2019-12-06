#pragma once

/*
 * inicializuoti.h
 *
 * inicializavimo header failas su visais globaliais kintamaisiais ir
 * funkcijomis, kurių reikia inicializacijai ir visam programos
 * veikimui.
 *
 * Naudojamas pagrindiniame projekto faile (sioko.ino)
 * ir suteikia globalius kintamuosius visiems failams.
 *
 * Copyright (c) 2019 Kipras Melnikovas
 *
*/

#include "config.h"
#include "pagalbines_funkcijos.h"

void inicializuoti();

void sukurtiBendraPinuMasyva();
void suteiktiPinModusViskam();
void suteiktiPinModeMasyvui(const int pinuMasyvas[], size_t masyvoDydis, int pinModas);
void paruostiGeneralConfiga();
