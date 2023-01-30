all: Room.o Date.o Reservation.o main.cc
	g++ -g -o a1 Room.o Date.o Reservation.o main.cc

Room.o: Room.cc Room.h
	g++ -g -c Room.cc

Date.o: Date.cc Date.h
	g++ -g -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -g -c Reservation.cc

clean:
	rm Room.o Reservation.o Date.o a1

