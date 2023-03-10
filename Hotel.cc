#include "Hotel.h"

Hotel::Hotel(){
    this->size = 0;
}

int Hotel::findInsertion(Room& r){
    for(int i = 0; i <= this->size; ++i){
        if(r.lessThan(*(this->rooms[i])))
            return i;
    }
    return this->size;
}

int Hotel::findRoom(int roomNumber){
    for(int i = 0; i <= this->size; ++i){
        if(this->rooms[i]->getRoomNumber() == roomNumber)
            return i;
    }
    return -1;
}

void Hotel::shift(int pos){
    for(int i = pos; i < this->size; ++i){
        this->rooms[i] = this->rooms[i+1];
    }
}

bool Hotel::containsRoom(int roomNumber){
    for(int i = 0; i <= this->size; ++i){
        if(this->rooms[i]->getRoomNumber() == roomNumber){
            return true;
        }
    }
    return false;
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
    if(this->size == MAX_ROOMS)
        return false;
    if(containsRoom(roomNumber))
        return false;
    
    Room r(roomNumber, bedType, capacity, fr);
    
    if(this->size == 0){
        this->rooms[0] = &r;
        this->size++;
        return;
    }

    if(this->size == 1){
        if(r.lessThan(*(this->rooms[0]))){
            this->rooms[1] = &r;
            this->size++;
            return;
            
        }else{
            this->rooms[1] = this->rooms[0];
            this->rooms[0] = &r;
            this->size++;
            return;

        }

        int location = findInsertion(r);
        for(int i = this->size; i > location; --i){
            this->rooms[i] = this->rooms[i-1];
        }

        this->rooms[location] = &r; 
        this->size++;
        return;   
  }


}

bool Hotel::deleteRoom(int roomNumber){
    int removal = this->findRoom(roomNumber);
    if(removal != -1){
        //TODO: Need a destructor here
        this->shift(removal);
        this->size--;
    }
}

bool Hotel::getRoom(int roomNumber, Room** room){
    int location = this->findRoom(roomNumber);
    if(location != -1){
        room = &this->rooms[location];
        return true;
    }
    return false;
}
bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    Room* addRoom;
    bool match = false;
    for(int i = 0; i < size; ++i){
        if(rooms[i]->isMatch(bedType, capacity, fr)){
            addRoom = rooms[i];
            match = true;
            break;
        }
    }

    if(!match){
        return false;
    }

    if(addRoom->addReservation(customer, date, duration)){
        return true;
    }else{
        return false;
    }

}

void Hotel::print(){for(int i = 0; i <= this->size; ++i){ this->rooms[i]->print();}}

void Hotel::printReservations(){
    for(int i = 0; i < size; ++i){
        rooms[i]->printReservations();
    }

}