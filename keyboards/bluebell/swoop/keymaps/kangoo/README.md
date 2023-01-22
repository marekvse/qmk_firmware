# Convert .json from QMK Configurator
To convert the rsthd.json fine coming from the QMK Configurator (https://config.qmk.fm/#/bluebell/swoop/LAYOUT_split_3x5_3) run the following command in the console:
qmk json2c rsthd.json

This seems to just produce the outpit in the console, which then needs to be put into keymap.c file and edited. Specifically the end of lines must be removed from the definitions of each layer as the console breaks them arbitrarily, often in a middle of a term.

# Notes in the source files
I have included notes in `keymap.c`, `config.h` and `rules.mk` for all the interesting options I'm using or may want to use in the future, containing links to the docs as well.

# To compile the firmware
1) First run `make clean` to clean the build directory, which may retain older file versions of the setup files it seems.
2) Run `make bluebell/swoop:kangoo:avrdude`

# Useful stuff
## Macros
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
## Using timers in keymap.c
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md - at the end.

