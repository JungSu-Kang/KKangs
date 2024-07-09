CC = gcc
CFLAG = -Wall
TARGET = ust
OBJS = us1.o us2.o us3.o us4.o
LIBS = wiringPi

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -l$(LIBS)

us1.o : uSonic.c
	gcc -c -o us1.o uSonic.c

us2.o : us.c
	gcc -c -o us2.o us.c

us3.o : Trig.c
	gcc -c -o us3.o Trig.c
	
us4.o : usong.c
	gcc -c -o us4.o usong.c

d : 
	rm -f *.o
	
song : song.c
	gcc -o song song.c -l$(LIBS)
