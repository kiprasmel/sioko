# SIOKO

## Dependencies

### Libraries

- [IRremote ^2.2.3](https://github.com/z3t0/Arduino-IRremote)
- [Teensy LC](https://www.pjrc.com/teensy/td_download.html)

### URGENT TODOS

- PERDARYT MATKĘ (patį balų skaičiavimą @ inicializuoti.h ir inicializuoti.ino ir kurYraOponentas)

- PERDARYT BALŲ APSKAIČIAVIMĄ PINAMS, NES DABAR Š GAUNAS

  - #sukimosiSkaiciavimas - skaičiuot ne pagal 90 laipsnių, o naudojant vieną laipsnį ir turint nusistačius, kiek maždaug suktis, priklausomai kokie sensoriai mato (kiek kuris sensorius reiškia sukimosi laipsnių)

- Patikrint, ar teisingai išdėlioti pinai

### Important todos

- Bandyt su laipnsiais skaičiuot (90deg, 45deg, ~20deg)

- Perkelt Line() ir atnaujintiJutikliuDuomenis() į vairuotiRobota()

- Linijos checkinimas yra visiškai broken, nes gi perdėliojom pinus į vietas kitaip (pagal stiprumą, inicializuoti.h)

- Jeigu break'ina per anksti - perdaryt `arVidurysKaNorsMato` funkciją (vietoj 5 padaryt 3, palikt tik middle)

- Ištestuot, per kiek laiko apsisuka robotas, jeigu sukimosi greitis yra `1`

- Strategijos (pradinės) yra rip. Naudoja delayjus etc.

---

- Pakeist matieką. Kuo mažiau sensorių mato, tuo taikliau ir tuo aštriau pasisukęs (šonams)

- Testuot keletą laikų

- Bandyt padaryt time'out'us, kad jeigu sukosi į vieną pusę, tai kad kažkiek ms nesisuktų į kitą, o eitų tiesiai

- Bandyt po posukio pasiųst atvirkštinius greičius kelioms ms, kad sustabdyt inerciją

### Questions

- DIR1 ir DIR2. Kodėl jie du? PWM1 ir PWM2 yra kairys ir dešinys motorai, o kam DIR2 ir DIR2 skirti?

- Kaip testuoti kodą?

  - Ar išeina pvz `Serial.print("kažkas")` ir išsaugot visą outputą, kad patikrint, kokias komandas vykdė robotas? taip
  - Arba išsaugot visą info į failą?

- Ar galima motorui siųsti neigiamą greitį (kad važiuotų atgal)? Taip

  - Jeigu taip, tai reikia tvarkyti su tag'u `WARN`, nes neišnaudojam viso potencialo

### Todos

- Per kiek ms robotas pilnai apsisuka? Įsivestume konstantą ir galėtume manipuliuot su laiku žymiai patogiau.

- SpinLeft/Right: kai `t` = 0.1 imamas kaip `int`, tai išeina 0. Taigi, motoras kviečiamas tik 1 kartą lul, fix it (@ void loop)

  - Taip pat, `t` yra `int`, o time / millis yra `unsigned int`!

- Kaip sucentruoti, kad neišbalancuotų sukiojantis?

- Reikia nepamiršt, kad remotai nesocolidintu. Tai yra, kad nesutaptų hex kodai

### Notes

- `while` ciklai veikia kaip ir `delay` - kol jie vyksta, programa tarsi sustojusi ir niekas kitkas nevyksta (su niuansais)

  - https://forum.arduino.cc/index.php?topic=392766.0
  - https://www.arduino.cc/reference/en/language/functions/time/delay/
  - https://www.arduino.cc/reference/en/language/functions/time/millis/
  - https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

- Receiveriai yra du

* Sensoriai mato 90cm

- StartModule kai low, robotas vietoje, o kai HIGH, pradeda judėti. Čia yra mėlyna lemputė

* Bytes in arduino. All are identical

```cpp
byte data[] = { 0xFF, 0xF0, 0x0F, 0x11 };
byte data[] = { 255, 240, 15, 17 };
byte data[] = { B11111111, B11110000, B00001111, B00010001 };
```

- PWM means "pulse width modulation" - PWM reiškia "pulsas plotis moduliav[imas|cija]"
  - https://www.pjrc.com/teensy/td_pulse.html
  - https://www.overclock.net/forum/246-air-cooling/989566-pwm-fans-what-does-mean.html#post13109939

## Licence

Copyright (c) 2019 Vismantas Masiokas, Neilas Antanavicius, Kipras Melnikovas
