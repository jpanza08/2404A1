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
            Room *rooms[MAX_ROOMS]; //TODO: figure out what kind of array
            int size;

        public:
            //Constructor
            Hotel();
            bool addRoom(int, string, int, bool);
            bool deleteRoom(int);
            bool getRoom(int, Room**);
            bool addReservation(string, string, int, bool, Date&, int);
            void printRooms();
            void printReservations();
    };


#endif