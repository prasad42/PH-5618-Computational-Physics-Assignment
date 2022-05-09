CC=gcc
CFLAGS=-I/usr/include/gsl
LDIR=/usr/lib

LIBS=-lm -lgsl -lgslcblas

Default:
	#add functions here to compile into .a
	$(CC) freeEn.c -c
	$(CC) powell.c -c
	$ ar -rc funcLib.a *.o
	#add functions here to compile into .a
		
	$(CC) -o main.exe main.c funcLib.a -lm

debug:
	#add functions here to compile into .a
	$(CC) freeEn.c -c
	$(CC) powell.c -c
	$ ar -rc funcLib.a *.o
	#add functions here to compile into .a
	
	$(CC) -Wall -g -o main-debug.exe main.c funcLib.a -lm

profilePrime: 
	#add functions here to compile into .a
	$(CC) freeEn.c -c
	$(CC) powell.c -c
	$ ar -rc funcLib.a *.o
	#add functions here to compile into .a
	
	$(CC) -pg -no-pie -fno-builtin -o main-gprof.exe main.c funcLib.a -lm
	
#save the gmon.out data(which you get after running the .exe) to a text file
profileText: 
	$ gprof main-gprof.exe gmon.out > analyze.txt
	$ gprof main-gprof.exe gmon.out > analyze.txt

#CLEAN
clean:
	rm -f *.o *.a *~ *.exe *.txt *.out
