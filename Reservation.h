#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Reservation{
    private:
        Date checkIn;
        string reserver;
        int length;

    public:
        Reservation(string, Date&, int);
        
        //Setters/Getters
        void setDuration(int);
        Date& getDate();
        
        //Misc
        bool overlaps(Reservation&);
        bool lessThan(Reservation&);
        bool lessThan(Date&);
        void print();
        
        

};



#endif