usi	: usMain.o Trig.o usISR.o
	gcc -o usi usMain.o Trig.o usisr.o -lwiringPi

Trig.o : Trig.c
	gcc -c -o Trig.o Trig.c
usMain.o : usMain.c
	gcc -c -o usMain.o usMain.c
usISR.o : usisr.c
	gcc -c -o usisr.o usisr.c
