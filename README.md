# SIOKO

## Dependencies

### Libraries

- [IRremote ^2.2.3](https://github.com/z3t0/Arduino-IRremote)
- [Teensy LC](https://www.pjrc.com/teensy/td_download.html)

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
