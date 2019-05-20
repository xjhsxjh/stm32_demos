stm32_demos
======

stm32f103x simple demos

trees
====
▾ blinky/
  ▸ ldscripts/
    main.c
    Makefile
    startup_stm32f10x_md.s
    stm32f10x_conf.h
    system_stm32f10x.c
▾ STM32_USB-FS-Device_Lib_V4.1.0/
  ▸ _htmresc/
  ▸ Libraries/
  ▸ Projects/
  ▸ Utilities/
    Release_Notes.html
  .gitignore
  LICENSE
  README.md

build
=======
1. prepare arm-none-eabi- toolchain

2. how to
    cd blinky
    make clean
    make all

run
====
1. prepare st-link hardware & enviroment

2. hwo to
    make burn
    (just use st-flash write *.bin 0x08000000)
