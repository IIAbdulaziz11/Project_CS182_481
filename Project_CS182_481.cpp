#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string surname;
    int age;

public:
    Person() {
        name = "none";
        surname = "none";
        age = 0;
    }
    Person(string n, string s, int a) {
        name = n;
        surname = s;
        age = a;
    }
    Person(const Person& other) {
        name = other.name;
        surname = other.surname;
        age = other.age;
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
    }
};

class Guest : public Person {
private:
    int guestId;

public:
    Guest() : Person() {
        guestId = 0;
    }
    Guest(string n, string s, int a, int id) : Person(n, s, a) {
        guestId = id;
    }
    Guest(const Guest& other) : Person(other) {
        guestId = other.guestId;
    }
    int getId() {
        return guestId;
    }
    void displayGuest() {
        display();
        cout << "Guest ID: " << guestId << endl;
    }
};

class Worker {
private:
    string position;
    double salary;

public:
    Worker() {
        position = "none";
        salary = 0.0;
    }
    Worker(string p, double sal) {
        position = p;
        salary = sal;
    }
    Worker(const Worker& other) {
        position = other.position;
        salary = other.salary;
    }
    void displayWorker() {
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << " Riyal" << endl;
    }
};

class Employee : public Person, public Worker {
public:
    Employee() : Person(), Worker() {
    }
    Employee(string n, string s, int a, string p, double sal)
        : Person(n, s, a), Worker(p, sal) {
    }
    Employee(const Employee& other) : Person(other), Worker(other) {
    }
    void displayEmployee() {
        display();
        displayWorker();
    }
};

class Room {
private:
    string roomNumber;
    string roomType;
    int floor;
    int capacity;
    double nightlyPrice;
    bool available;

public:
    Room() {
        roomNumber = "none";
        roomType = "none";
        floor = 0;
        capacity = 0;
        nightlyPrice = 0.0;
        available = false;
    }
    Room(string rn, string rt, int f, int cap, double price, bool av) {
        roomNumber = rn;
        roomType = rt;
        floor = f;
        capacity = cap;
        nightlyPrice = price;
        available = av;
    }
    Room(const Room& other) {
        roomNumber = other.roomNumber;
        roomType = other.roomType;
        floor = other.floor;
        capacity = other.capacity;
        nightlyPrice = other.nightlyPrice;
        available = other.available;
    }
    bool isAvailable() {
        return available;
    }
    void setAvailability(bool av) {
        available = av;
    }
    double getPricePerNight() {
        return nightlyPrice;
    }
    string getRoomNumber() {
        return roomNumber;
    }
    bool operator==(const Room& other) const {
        return roomNumber == other.roomNumber;
    }
    bool operator<(const Room& other)  const {
        return nightlyPrice < other.nightlyPrice;
    }
    void display() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Floor: " << floor << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Price Per Night: " << nightlyPrice << " Riyal" << endl;
        cout << "Available: ";
        if (available) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
};

class Hotel {
private:
    string hotelName;
    string address;
    Room rooms[50];
    Guest guests[50];
    Employee employees[10];
    int roomCount;
    int guestCount;
    int employeeCount;

public:
    Hotel() {
        hotelName = "none";
        address = "none";
        roomCount = 0;
        guestCount = 0;
        employeeCount = 0;
    }
    Hotel(string name, string addr) {
        hotelName = name;
        address = addr;
        roomCount = 0;
        guestCount = 0;
        employeeCount = 0;
    }
    Hotel(const Hotel& other) {
        hotelName = other.hotelName;
        address = other.address;
        roomCount = other.roomCount;
        guestCount = other.guestCount;
        employeeCount = other.employeeCount;

        for (int i = 0; i < roomCount; i++) {
            rooms[i] = other.rooms[i];
        }
        for (int i = 0; i < guestCount; i++) {
            guests[i] = other.guests[i];
        }
        for (int i = 0; i < employeeCount; i++) {
            employees[i] = other.employees[i];
        }
    }

    void addRoom(Room r) {
        if (roomCount < 50) {
            rooms[roomCount] = r;
            roomCount++;
        }
    }
    void addGuest(Guest g) {
        if (guestCount < 50) {
            guests[guestCount] = g;
            guestCount++;
        }
    }
    void addEmployee(Employee e) {
        if (employeeCount < 10) {
            employees[employeeCount] = e;
            employeeCount++;
        }
    }

    void showAvailableRooms() {
        cout << "Available Rooms in " << hotelName << endl;
        cout << "Hotel Address: " << address << endl;
        cout << "------------------------------" << endl;

        for (int i = 0; i < roomCount; i++) {
            if (rooms[i].isAvailable()) {
                rooms[i].display();
                cout << "------------------------------" << endl;
            }
        }
    }

    void processReservation(Guest guest, Room &room) {
        cout << "Reservation Process" << endl;
        cout << "------------------------------" << endl;

        cout << "Guest Information:" << endl;
        guest.displayGuest();
        cout << endl;

        for (int i = 0; i < roomCount; i++) {
            if (rooms[i] == room) {
                cout << "Room Information:" << endl;
                rooms[i].display();
                cout << endl;

                if (rooms[i].isAvailable()) {
                    double totalCost = rooms[i].getPricePerNight() * 5;

                    cout << "Stay Duration: 5 nights" << endl;
                    cout << "Total Cost: " << totalCost << " Riyal" << endl;

                    rooms[i].setAvailability(false);
                    room.setAvailability(false);
                }
                else {
                    cout << "This room is not available for reservation." << endl;
                }
                cout << "------------------------------" << endl;
                return;
            }
        }
        cout << "Room not found in hotel." << endl;
        cout << "------------------------------" << endl;
    }
};

int main() {
    Hotel hotel("Royal Hotel", "Riyadh, Saudi Arabia");

    Room room1("101", "Single", 1, 1, 300.0, true);
    Room room2("102", "Double", 1, 2, 250.0, true);
    Room room3("201", "Suite", 2, 4, 450.0, true);

    Guest guest1("Ahmed", "Ali", 25, 101);
    Guest guest2("Sara", "Khalid", 30, 102);
    Guest guest3("Omar", "Saleh", 28, 103);

    Employee emp1("Fahad", "Nasser", 35, "Manager", 7000.0);
    Employee emp2("Mona", "Hassan", 29, "Receptionist", 5000.0);

    hotel.addRoom(room1);
    hotel.addRoom(room2);
    hotel.addRoom(room3);

    hotel.addGuest(guest1);
    hotel.addGuest(guest2);
    hotel.addGuest(guest3);

    hotel.addEmployee(emp1);
    hotel.addEmployee(emp2);

    cout << "1. Display Available Rooms" << endl;
    hotel.showAvailableRooms();
    cout << endl;

    cout << "2. Compare Rooms by Room Number Using ==" << endl;
    if (room1 == room2)
        cout << "The two rooms have the same room number." << endl;
    else
        cout << "The two rooms have different room numbers." << endl;
    cout << endl;

    cout << "3. Compare Rooms by Price Per Night Using <" << endl;
    if (room2 < room3)
        cout << "Room 2 is cheaper than Room 3." << endl;
    else
        cout << "Room 2 is not cheaper than Room 3." << endl;
    cout << endl;

    cout << "4. Process Reservation" << endl;
    hotel.processReservation(guest1, room1);
    cout << endl;

    cout << "5. Available Rooms After Reservation" << endl;
    hotel.showAvailableRooms();
    cout << endl;

    cout << "6. Display Guest Information" << endl;
    guest1.displayGuest();
    guest2.displayGuest();
    guest3.displayGuest();
    cout << endl;

    cout << "7. Display Employee Information" << endl;
    emp1.displayEmployee();
    emp2.displayEmployee();

    return 0;
}