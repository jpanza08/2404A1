#include "Reservation.h"

Reservation::Reservation(string customerName, Date& checkIn, int duration){
    this->reserver = customerName;
    this->checkIn = checkIn;
    this->length = duration;

}

void Reservation::setDuration(int duration){this->length = duration;}
Date& Reservation::getDate(){return this->checkIn;}

bool Reservation::overlaps(Reservation& r){
    //If start2 < end1 they overlap
    //If start1 < end2 they overlap
    Date end1 = checkIn;
    end1.addDays(r.length);
    Date end2 = r.checkIn;
    end2.addDays(r.length);
    if(checkIn.lessThan(end2))
        return true;
    if(checkIn.lessThan(end1))
        return true;
    return false;
}

bool Reservation::lessThan(Reservation& r){
    if(this->lessThan(r.getDate())){
        return true;
    }

    return false;
}

bool Reservation::lessThan(Date& d){
    Date temp(d.getYear(), d.getMonth(), d.getDay());
    //Bit more that goes into this lessThan function
   
    if(checkIn.lessThan(d)){
        return true;
    }
    return false;
 }

void Reservation::print(){
    cout<<"Reservation for "<<this->reserver<<" on "<<this->checkIn.toString()<<" for "<<this->length<<" day(s)."<<endl;
}
