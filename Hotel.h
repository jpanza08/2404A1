#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Reservation.h"
#include "Room.h"
using namespace std;
    
    class Hotel{
        private:
            Room *rooms[MAX_ROOMS]; 
            int size;

        public:
            //Constructor
            Hotel();
            int findInsertion(Room&);
            int findRoom(int roomNumber);
            void shift(int);
            bool containsRoom(int);
            bool addRoom(int, string, int, bool);
            bool deleteRoom(int);
            bool getRoom(int, Room**);
            bool addReservation(string, string, int, bool, Date&, int);
            void print();
            void printReservations();
    };


#endif