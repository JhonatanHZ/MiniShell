# Proyecto 1: Minishell #
# César Carios & Jhonatan Homsany #

all: Proyecto

clean:
	rm -rf Proyecto.o

Proyecto:	Proyecto.o
	gcc -o Proyecto Proyecto.o

Proyecto.o: 
	gcc -c Proyecto.c -o Proyecto.o
