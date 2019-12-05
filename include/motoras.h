#pragma once

typedef enum
{
	kryptisPirmyn = 0,
	kryptisAtgal = 1
} VaziavimoKryptys;

int kokiaKryptis(int);
bool arStabdytiMotorus();

void motor(int, int);

void motoraiKolPriekisPamato(int kairioMotoroGreitis, int desinioMotoroGreitis);
void motoraiSuLaiku(int, int, unsigned long);
void motoraiSuLaikuNereguojantysIPrieki(int, int, unsigned long);
bool siunciamPirmynJeiguPriekisMato(bool);
void siunciamIrUzlokinamPirmynKolPriekisMato(bool);
