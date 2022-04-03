# DeathBalls
This game is a realization of Linnchoeuh and Elania.   
This achievement is on the occasion of the Ludum Dare 50.  
The theme is delay the inevitable.  
This game is made using the LibLapin, in C.  

# Installing liblapin on your machine

## 0. Prerequisites

Have a graphical session on Debian/Ubuntu

Have made the following installations:

```sh
# Sur ubuntu/debian
apt update
apt install emacs-nox tree build-essential valgrind make git gdb
```

## 1. Dependencies

On ubuntu/debian you need to do:

```sh
apt install libopencv-dev libusb-dev libffcall-dev libsfml-dev libpthread-stubs0-dev libudev-dev
```

## 2. Download

Run the following command:
```sh
git clone https://github.com/Damdoshi/LibLapin.git

cd LibLapin

make -j4

./school_install.sh

source ~/.bashrc
```
It's going to take a long time, but in the end you'll have the liblapin.

## 3. Profit!

Normally everything is fine.

You can do the following commands to make sure the Lib works:
```sh
cd examples/demo/crossed_bar

make

./crossed_bar
```

You should see a colored window appear.

