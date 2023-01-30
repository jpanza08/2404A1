#include "Room.h"


Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->size = 0;
    

}

int Room::getRoomNumber(){return roomNumber;}
int Room::getSize(){return size;}
Reservation* Room::getResos(){return reservations[0];}
bool Room::isMatch(string bt, int cap, bool f){
    if(this->bedType == bt && this->capacity >= cap){
        if(f == true && this->hasFridge == false)
            return false;
        return true;
    }
    
    return false;
}

bool Room::lessThan(Room& r){return this->roomNumber < r.roomNumber;}

bool Room::checkOverlap(Reservation& r){
    if(this->size == 0)
        return false;
    
    
    
    for(int i = 0; i < size; ++i){
        if(this->reservations[i]->overlaps(r))
            return true;
    }


    return false;
}

int Room::findInsertion(Reservation &r){

    for(int i = 0; i < this->size; ++i){
        if(r.lessThan(*this->reservations[i])){ //Found new greatest room
            return i;    
        }
    }
    
    return this->size;
}

bool Room::addReservation(string customerName, Date& d, int duration){
    if(this->size == MAX_RES){
        return false;
    }
    Reservation* r = new Reservation(customerName, d, duration);
    if(size == 0){
        reservations[0] = r;
        size++;
        return true;
    }   
    if(!checkOverlap(*r)){
        //No overlaps, find insertion position
        int pos = -1;
        for(int i = 0; i < size; ++i){
            if(r->lessThan(reservations[i]->getDate())){
                pos = i;
            }
        }
        
        if(pos == -1){
            reservations[size] = r;
            size++;
            return true;
        }else{
            for(int i = size; i > pos; --i){
                reservations[i] = reservations[i-1];
            }
            reservations[pos] = r;
            size++;
            return true;
        }
    }

    return false;
}   

void Room::printReservations(){
    print();
    for(int i = 0; i < this->size; ++i){
        this->reservations[i]->print();
        cout<<endl;
    }
    

}

void Room::print(){
    cout<<"Room Number "<<this->roomNumber<<" has "<<size<<" reservations."<<endl;
}