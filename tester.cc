#include "Room.h"

int main(int argc, char const *argv[]){
    Date date1 = Date(2023, 12, 3);
    Date date2 = Date(2023, 12, 7);
    Date date3 = Date(2023, 12, 5);
    
    // Reservation r1("victor", date1, 1);
    // Reservation r2("eaaa", date2, 2);
    // Reservation r3("josh", date3, 5);

    Room *room1 = new Room(2, "double", 2, 1);
    Room room2(2, "single", 1, 0);
    room1->addReservation("victor", date1, 1);
    room1->printReservations();
    room1->addReservation("eaaa", date2, 1);
    room1->printReservations();
    room1->addReservation("josh", date3, 1);
    room1->printReservations();
    

    


}