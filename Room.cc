#include "Room.h"


Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->size = 0;
    

}

int Room::getRoomNumber(){return roomNumber;}
bool Room::isMatch(string bt, int cap, bool f){
    return this->bedType == bt && this->capacity == cap && this->hasFridge == f;
}

bool Room::lessThan(Room& r){return this->roomNumber < r.roomNumber;}

bool Room::checkOverlap(Reservation& r){
    if(this->size == 0)
        return false;
    
    for(int i = 0; i <= size; ++i){
        if(this->reservations[i]->overlaps(r))
            return true;
    }

    return false;
}

int Room::findInsertion(Reservation &r){

    for(int i = 0; i < this->size; ++i){
        if(this->reservations[i]->lessThan(r)){ //Found new greatest room
            return i;
        }
    }
    
    return this->size;
}

bool Room::addReservation(string customerName, Date& d, int duration){
    if(this->size == MAX_RES){
        return false;
    }
    Reservation r = Reservation(customerName, d, duration);
    if(checkOverlap(r)){
        

  //Edge cases
    if(this->size == 0){
        this->reservations[0] = &r;
        this->size++;
        return;
    }

    if(this->size == 1){
        if(r.lessThan(*(this->reservations[0]))){
            this->reservations[1] = &r;
            this->size++;
            return;
            
        }else{
            this->reservations[1] = this->reservations[0];
            this->reservations[0] = &r;
            this->size++;
            return;

        }

        int location = findInsertion(r);
        for(int i = this->size; i > location; --i){
            this->reservations[i] = this->reservations[i-1];
        }

        this->reservations[location] = &r; 
        this->size++;
        return;   
  }

    }
}

void Room::printReservations(){
    cout<<"Room Number "<<this->roomNumber<<" has "<<size<<" reservations: "<<endl;
    for(int i = 0; i <= this->size; ++i){
        this->reservations[i]->printRes();
        cout<<endl;
    }
    
}