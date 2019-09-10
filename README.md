# SIOKO

🤖⚡ Kovinio roboto programinė įranga, remastered

## Dependencies

- [IRremote ^2.2.3](https://github.com/z3t0/Arduino-IRremote)
- [Teensy LC](https://www.pjrc.com/teensy/td_download.html)
- For building on linux for teensy - [teensyduino](https://www.pjrc.com/teensy/td_download.html)

## Configuration

`board`: `Teensy 3.5` (not `uno`! (analogWriteFrequency etc.))
`programmer`: `AVRISP mk11`

note - linux's port of the device you connect through a USB will probably be `/dev/ttyACM*` or `/dev/ttyUSB*`

## Questions

- DIR1 ir DIR2. Kodėl jie du? PWM1 ir PWM2 yra kairys ir dešinys motorai, o kam DIR2 ir DIR2 skirti?

- Kaip testuoti kodą?

  - Ar išeina pvz `Serial.print("kažkas")` ir išsaugot visą outputą, kad patikrint, kokias komandas vykdė robotas?
    - taip
  - Arba išsaugot visą info į failą?
		-	naudot ne `arduino` IDE, o arduino-bare-project + arduino-makefile

- Ar galima motorui siųsti neigiamą greitį (kad važiuotų atgal)?
  - Taip
  - Jeigu taip, tai reikia tvarkyti su tag'u `WARN`, nes neišnaudojam viso potencialo


## TODOS

### URGENT

- 

### Important

- Strategijos (pradinės) yra rip. Naudoja `delay`s etc.
	-	 Perdaryt

### Regular

- SpinLeft/Right: kai `t` = 0.1 imamas kaip `int`, tai išeina 0. Taigi, motoras kviečiamas tik 1 kartą lul, fix it (@ void loop)

  - Taip pat, `t` yra `int`, o time / millis yra `unsigned int`!

- Reikia nepamiršt, kad remotai nesu'colide'intų. Tai yra, kad nesutaptų hex kodai

- MAYBE - #sukimosiSkaiciavimas - skaičiuot ne pagal tai, per kiek ms apsisukam 90 laipsnių, o per kiek ms apsisukam 1 laipsnį ir turint nusistačius, kiek tiksliai suktis, priklausomai kokie sensoriai mato (kiek kuris sensorius reiškia sukimosi laipsnį)
	- Laipsniai ir sukimosi milisekundės progresuoja netolygiai, taigi, keičiantis vienam, kitas keičiasi šiek tiek kitaip, todėl gali būti nepatikima. Reikia rasti sweet-spot'ą.

### Notes

- Minimaliai pakeitus motor funkciją ji nebeveikia normaliai. Keista.

- Kartais, ypač po `upload`inimo, būna bėdų su paleidimu (nereaguoja į pultelį)

- `while` ciklai veikia kaip ir `delay` - kol jie vyksta, programa tarsi sustojusi ir niekas kitkas nevyksta (su niuansais)

  - https://forum.arduino.cc/index.php?topic=392766.0
  - https://www.arduino.cc/reference/en/language/functions/time/delay/
  - https://www.arduino.cc/reference/en/language/functions/time/millis/
  - https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

- Receiveriai yra du

- Sensoriai mato 90cm

- kai `START_MODULE` yra `LOW`, roboto motorus reikia sustabdyti. O kai tampa `HIGH`, reikia paleisti judėti.

- Bytes in arduino. All are identical
	- Actually, they're just `uint8_t`s, so it's just c++ in general.

```cpp
byte data[] = { 0xFF, 0xF0, 0x0F, 0x11 };
byte data[] = { 255, 240, 15, 17 };
byte data[] = { B11111111, B11110000, B00001111, B00010001 };
uint8_t data[] = { B11111111, B11110000, B00001111, B00010001 };
```

- PWM means "pulse width modulation" - PWM reiškia "pulsas plotis moduliav[imas|cija]"
  - https://www.pjrc.com/teensy/td_pulse.html
  - https://www.overclock.net/forum/246-air-cooling/989566-pwm-fans-what-does-mean.html#post13109939

## Licence

Copyright (c) 2019 Kipras Melnikovas, Neilas Antanavičius, Vismantas Masiokas
