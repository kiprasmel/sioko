#pragma once

/**
 * DĖMESIO
 *
 * Šitas VEIKIA masyvams, kurie yra `stack`e,
 * bet ne `heap`e!
 *
 * Šitas NEVEIKIA, jeigu masyvas buvo paduotas kaip funkcijos parametras,
 * nes jis tampa `pointer`iu ir nebeišeina patikrinti jo dydžio!
 *
 * Skaityti daugiau:
 *
 * https://stackoverflow.com/a/18078435/9285308
 *
 * https://stackoverflow.com/a/10349610
 * https://stackoverflow.com/a/37539
 *
 * TODO rename į masyvoDydis() arba išvis pradėt naudot std::vector (yeet)
 *
 */
// // // // #define gautiMasyvoDydi(x) (sizeof(x) / sizeof((x)[0]))
template<class T, size_t N>
constexpr size_t gautiMasyvoDydi(T (&)[N]) { return N; }

void atnaujintiJutikliuDuomenis();

int kiekMatoKazkuriPuse(const int pinaiSkenavimui[], const int masyvoDydis);

bool arVidurysKaNorsMato();
bool arKaireKaNorsMato();
bool arDesineKaNorsMato();

bool arBetKuriPuseKaNorsMato();

void ledasON();
void ledasOFF();

bool arMato(int &pinas);
bool arMatoLinija(int &pinas);
bool arMatoLazeris(int &pinas);
