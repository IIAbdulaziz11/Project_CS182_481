[README.md](https://github.com/user-attachments/files/35281925/README.md)
# 🏨 Hotel Reservation Management System (C++)

A C++ console program that manages a hotel's rooms, guests, employees, and reservations. Created as a project for **Computer Programming 3 (CS182)** at Qassim University 💻.

## ✨ Features

- 🛏️ Add rooms with number, type, floor, capacity, and nightly price (in Saudi Riyals)
- 🧑‍💼 Add guests and employees to the hotel
- 📋 Display all available rooms
- ⚖️ Compare rooms by room number (`==`) and by price per night (`<`) using operator overloading
- 💰 Process a 5-night reservation and calculate the total cost
- 🔒 Automatically mark a reserved room as unavailable
- 👥 Display guest and employee information

## 🧩 Project Structure

The project has six classes and uses both single and multiple inheritance:

| Class | Role |
|---|---|
| `Person` | Base class: name, surname, age |
| `Guest` | Inherits from `Person` (single inheritance), adds a guest ID |
| `Worker` | Independent class: position and salary |
| `Employee` | Inherits from `Person` and `Worker` (multiple inheritance) |
| `Room` | Room details, availability, and overloaded `==` and `<` operators |
| `Hotel` | Manages arrays of rooms, guests, and employees, and processes reservations |

### OOP concepts used

- Classes and objects
- Encapsulation (private data with getters/setters)
- Single and multiple inheritance
- Constructors (default, parameterized, and copy)
- Arrays of objects
- Passing objects by value and by reference
- Operator overloading

## 📄 Sample Output

```
4. Process Reservation
Reservation Process
------------------------------
Guest Information:
Name: Ahmed
Surname: Ali
Age: 25
Guest ID: 101

Room Information:
Room Number: 101
Room Type: Single
Floor: 1
Capacity: 1
Price Per Night: 300 Riyal
Available: Yes

Stay Duration: 5 nights
Total Cost: 1500 Riyal
------------------------------
```

After the reservation, room `101` no longer appears in the list of available rooms.

## 📝 Notes

- 📚 This project was made for practice and learning.
- 🛠️ No external libraries needed, just standard C++.
- 💵 All prices are in Saudi Riyals, and the reservation simulates a fixed 5-night stay (price per night × 5).
