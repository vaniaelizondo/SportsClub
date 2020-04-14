# Sports Club Reservation Program

For my Object-Oriented Programming course I developed a sports club reservation program in C++. The project uses the concepts of inheritance, polymorphism, abstract classes, friend functions, operator overloading and pointers to objects.

The objective of the program is to be able to reserve sports courts or gym machines at a sports club. The main program has a menu that shows the user the services available, the list of reservations, the reservations of a specific service, the reservations given a specific hour and lets the user reserve a service.

### Servicios.txt 
The file saves the services available in the club, each entry is composed of 6 columns:
1. First column indicates the service code. The first letter determines if the service is either a court or a machine. B, C and E are machines corresponding to Bicycle, Treadmill and Climber. Letters F, T, V correspond to courts being Fronton, Tennis and Volleyball. The number after the slash indicates the ID of the service. Each ID should be unique. 
2. Second column indicates the maximum time allowed for the service.
3. Third column indicates the type of service with a character as in the first column.
4. Fourth column indicates the cost for 15 minutes in the case of a machine or the cost per hour in the case of a field. 
5. Fifth column will show a T/F value for machines indicating if an instructor is available for the machine and a number if it's a field indicating the maximum number of players to use the field.
6. Last column shows a brief description of the service. 

### Reserva.txt 
The file contains the reservations made in a 5-column format.
1. First column shows the ID of the service.
2. Second column shows the hour of the reservation.
3. Third column shows the minute of the reservation.
4. Fourth column shows the duration of the reservation.
5. Fifth column shows the ID of the member doing the reservation. 

### Servicio.h
This header file contains the Servicio class declaration. This is an abstract class that is used for the *Aparato.h* and *Cancha.h* classes.

### Aparato.h
This is a derived class from *Servicio.h*. The class has the next attributes:
- string code: machine's ID.
- int maximum time: maximum time allowed for the machine.
- char type: B (Bicycle), C (Treadmill) and E (Climber).
- double cost for 15 minutes: the cost of the machine per 15 minutes.
- bool instructor: true if an instructor is available for the machine, false if it doesn't.
- string description: brief description of the machine.

### Cancha.h
This is a derived class from *Servicio.h*. The class has the next attributes:
- string code: field's ID.
- int maximum time: maximum time allowed for the field.
- char type: F (Fronton), T (Tennis) and V (Volleyball).
- double cost per hour: the cost of the field for an hour.
- int maximum quantity: maximum capacity in field. 
- string description: brief description of the machine.

### Hora.h
This class is used for *Reserva.h* to determine time. It can add minutes to an hour and compare >=, <=, ==, >>, <<. Its attributes are:
- int hour
- int minutes

### Reserva.h
This class is used to create reservation objects to then save them in a file. Its attributes are:
- string code: service code.
- int client ID: ID of member doing reservation
- Hora hour: start time
- int duration: duration of reservation

### main.cpp
Main program which reads from the *Servicios.txt* file and saves each entry in a *Servicio* object pointer, depending on the type of service, a *Aparato* or a *Cancha* object is saved. After this, the program does the same for the *Reserva.txt* saving each entry in a *Reserva* object.

The program then performs the menu cycle until the user is done. The menu insludes:
- a) Check the list of services
- b) Check the list of reservations
- c) Check the reservations for a service
- d) Check the reservations for a specific time
- e) Make a reservation
- f) End program
