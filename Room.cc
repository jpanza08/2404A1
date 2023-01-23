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
    return this->bedType == bt && this->capacity == cap && this->hasFridge == f;
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
    for(int i = 0; i < size; ++i){
        if(this->reservations[i]->overlaps(*r)){
            cout<<"HERE"<<endl;
            return false;
        }
    }
    
    // //Edge cases
    if(this->size == 0){ //Empty array
        this->reservations[0] = r;
        this->size++;
        return true;
    }
    int pos = 0;
    while(pos < this->size){
        if(r->lessThan(*this->reservations[pos])){
            break;
        }
        pos++;
    }

    for(int j = size; j > pos; j--){
        this->reservations[j] = this->reservations[j-1];
    }

    this->reservations[pos] = r;
    this->size++;
    return true;
}

void Room::printReservations(){
    cout<<"Room Number "<<this->roomNumber<<" has "<<size<<" reservations: "<<endl;
    for(int i = 0; i < this->size; ++i){
        this->reservations[i]->print();
        cout<<endl;
    }
    

}

void Room::print(){
    cout<<"Room Number "<<this->roomNumber<<" has "<<size<<" reservations."<<endl;
}