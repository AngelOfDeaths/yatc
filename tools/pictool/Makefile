CFLAGS= -O0 -g3 -Wall
all:  pictool
clean: 
	rm main.o picfuncs.o ../../sprdata.o 

rebuild: clean all

pictool: main.o picfuncs.o ../../sprdata.o
	$(CC) main.o picfuncs.o ../../sprdata.o -o pictool  -lSDL -O0 -g3

YATC.pic: pictool ../../yatc.bmp ../../inv.bmp
	cp ../../850/Tibia.pic YATC.pic
	convert ../../yatc.png ../../yatc.bmp
	./pictool YATC.pic 0 ../../yatc.bmp --topic
	./pictool YATC.pic 1 ../../inv.bmp --topic
	./pictool YATC.pic 3 ../../ui.bmp --topic
#	cp YATC.pic Tibia.pic
	cp YATC.pic ../../Tibia.pic

main.c: picfuncs.h ../../sprdata.h

picfuncs.c: picfuncs.h
