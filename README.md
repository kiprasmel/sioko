# SIOKO

🤖⚡ Kovinio roboto programinė įranga, remastered

## Installation

```sh
git clone https://github.com/sarpik/sioko.git
# or:  git clone git@github.com:sarpik/sioko.git
cd sioko/
```

## Running

Tau reikės [platformio core (CLI)](https://docs.platformio.org/en/latest/installation.html) arba [platformio IDE (extension'as VSCode'ui)](https://platformio.org/platformio-ide).

```sh
platformio run
platformio run --target upload
platformio device monitor --baud 9600
```

## Dependencies

- [IRremote ^2.2.3](https://github.com/z3t0/Arduino-IRremote)
- [Teensy LC](https://www.pjrc.com/teensy/td_download.html)
- For building on linux for teensy - [teensyduino](https://www.pjrc.com/teensy/td_download.html)

## Configuration

> todo - get rid of this & dependencies since we're now using platformio

`board`: `Teensy 3.5` (not `uno`! (analogWriteFrequency etc.))
`programmer`: `AVRISP mk11`

note - linux's port of the device you connect through a USB will probably be `/dev/ttyACM*` or `/dev/ttyUSB*`

## [Licence](./LICENSE)

> [GPL-3.0](./LICENSE)

Copyright (c) 2019 [Kipras Melnikovas](https://github.com/sarpik)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
