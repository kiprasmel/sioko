/**
 *
 * https://stackoverflow.com/questions/3627941/global-variable-within-multiple-files
 * https://stackoverflow.com/a/10422050/9285308
 *
 */

#pragma once

#include <Arduino.h>

extern const double tolimiausioPinoLaipsnis;
extern const double greitisVaziavimoPirmyn;
extern const double greitisSukimosi;
extern const double perKiekMsApsisukam360Sukdamiesi255;
extern const double perKiekMsApsisukam90Sukdamiesi255;
extern const byte LEDas;
extern const int Middle1; /** lazeris ilgas, padėtas pačiame viduryje */
extern const int Middle2; /** ne lazeris, žiūri į vidurinį (irgi pačiame viduryje) */
extern const int Middle3; /** lazeris trumpas, padėtas pačiame viduryje */
extern const byte Rightback;
extern const byte Leftback;
extern const int ziurintysIDesineSensoriai[][2];
extern const int ziurintysIDesineSensoriaiDydis;
// extern const int ziurintysIDesinePinai[ziurintysIDesineSensoriaiDydis];
// extern const int* ziurintysIDesinePinai;
extern const int ziurintysIDesinePinai[];
extern const int ziurintysIDesinePinaiDydis;
extern const int ziurintysIViduriSensoriai[][2];
extern const int ziurintysIViduriSensoriaiDydis;
// extern const int ziurintysIViduriPinai[ziurintysIViduriSensoriaiDydis];
extern const int ziurintysIViduriPinai[];
extern const int ziurintysIViduriPinaiDydis;
extern const int ziurintysIKaireSensoriai[][2];
extern const int ziurintysIKaireSensoriaiDydis;
// extern const int ziurintysIKairePinai[ziurintysIKaireSensoriaiDydis];
extern const int ziurintysIKairePinai[];
extern const int ziurintysIKairePinaiDydis;
extern const int kiekYraSensoriuPinu;
extern const int visiPinaiDydis; /** alias */
// extern int pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[kiekYraSensoriuPinu][2];
extern int pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[][2];
// extern int visiPinai[kiekYraSensoriuPinu];
extern int visiPinai[];
extern int linijuSensoriai[];
extern const size_t linijuSensoriaiDydis;
// #define MY_PROTOCOL NEC
// #define Number1 0xFF906F
// #define Number2 0xFFB847
// #define Number3 0xFFF807
// #define Number4 0xFF9867
// #define Number5 0xFFD827
// #define Number6 0xFF8877
// #define Number7 0xFFE817
// #define Number8 0xFF48B7
// #define Number9 0xFF9A65
// #define Enter 0xFFE01F
extern byte myLINE;
extern byte myLINEBACK;
extern byte mySIDES;
extern byte myFRONT;
extern byte myMOUSE; //8
extern const byte PWM1;	// kairysis motoras
extern const byte PWM2;	// dešinysis motoras
extern const byte DIR1;	// ?
extern const byte DIR2; // ?
extern int k;
extern int b;
extern const byte START_MODULE;
extern const byte SPEED_NORMAL;
extern const byte SPEED_TURN;
extern const byte SPEED_TURN2;
extern const byte SPEED_GO_BACK_LINE;
extern const byte SPEED_GO_BACK_LINE_TURN;
extern const byte SPEED_GO_BACK_LINE_TURN2;
extern const unsigned short TIME_FOR_GO_BACK;		//60
extern const unsigned short TIME_FOR_GO_BACK_1; //105
extern byte START_STRATEGY_STATE;
extern byte MAIN_STRATEGY_STATE;
extern unsigned long time;

/**
 * TODO - atsirinkti, ko reikia, o kitką išmest
 *
 * Toliau eina legacy dalykai, kuriuos sukūriau ne aš, bet kurie dar
 * pilnai nepertvarkyti ir kol kas reikalingi naudojimui.
 *
 * Rekomenduojama jų nenaudoti, taip pat, jeigu įmanoma - perrašyti
 * esantį kodą su jais į naują kodą su atnaujintais kintamaisiais etc.
*/

// protokolas (atrodo, jog nereikalingas)
#define MY_PROTOCOL NEC

//Pultelio hex kodai ir nustatymai
#define Number1 0xFF906F
#define Number2 0xFFB847
#define Number3 0xFFF807
#define Number4 0xFF9867
#define Number5 0xFFD827
#define Number6 0xFF8877
#define Number7 0xFFE817
#define Number8 0xFF48B7
#define Number9 0xFF9A65
#define Enter 0xFFE01F
