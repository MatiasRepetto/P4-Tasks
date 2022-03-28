# --------------------------------------------
# 	Grupo 05
#  Makefile de laboratorio 0.

#  Laboratorio de Programación 4.
#  InCo-FIng-UDELAR	
	
# --------------------------------------

MODULOS = DTFecha DTHabitacion DTHuesped DTReserva Habitacion Huesped Reserva sistema

CC = g++
LD = -g -Wall
MC = -c

ODIR = obj

OBJ  = $(MODULOS:%=$(ODIR)/%.o)

main: $(OBJ) main.cpp
	$(CC) $(LD) $(OBJ) main.cpp -o main

obj/DTHabitacion.o: include/DTHabitacion.h src/DTHabitacion.cpp
	$(CC) $(LD) $(MC) src/DTHabitacion.cpp -o obj/DTHabitacion.o

obj/DTFecha.o: include/DTFecha.h src/DTFecha.cpp
	$(CC) $(LD) $(MC) src/DTFecha.cpp -o obj/DTFecha.o

obj/DTHuesped.o: include/DTHuesped.h src/DTHuesped.cpp
	$(CC) $(LD) $(MC) src/DTHuesped.cpp -o obj/DTHuesped.o

obj/DTReserva.o: include/DTReserva.h src/DTReserva.cpp
	$(CC) $(LD) $(MC) src/DTReserva.cpp -o obj/DTReserva.o

obj/Habitacion.o: include/Habitacion.h src/Habitacion.cpp
	$(CC) $(LD) $(MC) src/Habitacion.cpp -o obj/Habitacion.o
	
obj/Huesped.o: include/Huesped.h src/Huesped.cpp
	$(CC) $(LD) $(MC) src/Huesped.cpp -o obj/Huesped.o

obj/Reserva.o: include/Reserva.h src/Reserva.cpp
	$(CC) $(LD) $(MC) src/Reserva.cpp -o obj/Reserva.o

obj/sistema.o: include/sistema.h src/sistema.cpp
	$(CC) $(LD) $(MC) src/sistema.cpp -o obj/sistema.o

clean:
	rm -f $(OBJ) main

rebuild:
	make clean
	make