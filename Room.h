#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include<string>
#include "Reservation.h"
#include "defs.h"
using namespace std;

class Room{

    private: 
        int roomNumber;
        string bedType;
        int capacity;
        bool hasFridge;
        Reservation* reservations[MAX_RES];
        int size;

    public:
        //Constructor
        Room(int, string, int, bool);
        //Destructor

        //Getters
        int getRoomNumber();
        int getSize();
        
        //Misc
        bool isMatch(string, int, bool);
        bool lessThan(Room&);
        bool checkOverlap(Reservation&);
        int findInsertion(Reservation&);
        bool addReservation(string, Date&, int);
        void printReservations();
        Reservation* getResos();
        void print();

};


#endif