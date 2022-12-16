run : codage.o decodage.o cle.o main.o
	gcc -o run codage.o decodage.o main.o cle.o

main.o : main.c 
	gcc -o main.o -c main.c 

cle.o : cle.c 
	gcc -o cle.o -c cle.c

codage.o : codage.c 
	gcc -o codage.o -c codage.c 

decodage.o : decodage.c 
	gcc -o decodage.o -c decodage.c

clean :
	rm -f *.o