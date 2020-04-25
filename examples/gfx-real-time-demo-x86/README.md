# tGFX real-time drawing mode demo for x86

This is tGFX real-time drawing mode demo for x86 on MacOSX or Linux using X11.

## Install

It depends on X11, so you should install X11 first.

For MacOSX, go to https://www.xquartz.org/ to download and install it.

For Linux, see https://en.wikipedia.org/wiki/X_Window_System for details.

For RaspberryPI running Raspbian system, run `sudo apt-get install libx11-dev` to install it.

## Build

```shell
cd examples/gfx-real-time-demo-x86
mkdir build
cmake ..
make
```

## Run

```shell
./gfx-real-time-demo-x86
```

**It takes a few seconds to start X11 for the first time. The program was not stuck.**
