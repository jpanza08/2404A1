all: Room.o Date.o Reservation.o
	g++ -o tester tester.cc Room.o Date.o Reservation.o

Room.o: Room.cc Room.h
	g++ -c Room.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

clean:
	rm Room.o Reservation.o Date.o tester
