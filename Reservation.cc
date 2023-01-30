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
    Date end = checkIn;
    end.addDays(length);
    Date rend = r.checkIn;
    rend.addDays(r.length);

    if(end.equals(r.checkIn) || rend.equals(checkIn))
        return false;

    if(rend.lessThan(checkIn)){
        return false;
    }
    if(end.lessThan(r.checkIn)){
        return false;
    }
    return true;
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
