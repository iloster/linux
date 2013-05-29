OBJS=main.o copy.o get.o put.o file.o
signalmove:$(OBJS) signalmove.h
	gcc $(OBJS) -o signalmove -lpthread
main.o:main.c signalmove.h
	gcc -c main.c -lpthread
copy.o:copy.c signalmove.h
	gcc -c copy.c
get.o:get.c signalmove.h
	gcc -c get.c
put.o:put.c signalmove.h
	gcc -c put.c
file.o:file.c signalmove.h
	gcc -c file.c

