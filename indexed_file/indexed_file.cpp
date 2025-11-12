#include <iostream>
#include <fstream>
using namespace std;

class Reservation {
public:
    int id;
    string passenger;
    string flight;
    string travelDate;
    string seat;

    void readData() {
        cout << "Enter Booking ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Passenger Name: ";
        getline(cin, passenger);
        cout << "Enter Flight Number: ";
        getline(cin, flight);
        cout << "Enter Travel Date (DD-MM-YYYY): ";
        getline(cin, travelDate);
        cout << "Enter Seat Number: ";
        getline(cin, seat);
    }

    void showData() {
        cout << id << "  " << passenger << "  " << flight << "  " 
             << travelDate << "  " << seat << endl;
    }
};

class AirlineSystem {
public:
    void newReservation() {
        Reservation r;
        fstream dataFile, indexFile;
        r.readData();

        dataFile.open("reservations.txt", ios::app);
        indexFile.open("index_res.txt", ios::app);

        long position = dataFile.tellp();
        dataFile << r.id << " " << r.passenger << " " << r.flight << " " 
                 << r.travelDate << " " << r.seat << endl;
        indexFile << r.id << " " << position << endl;

        dataFile.close();
        indexFile.close();
    }

    void viewAll() {
        ifstream file("reservations.txt");
        if (!file) {
            cout << "No reservations found.\n";
            return;
        }

        Reservation r;
        cout << "\nAll Reservations:\n";
        while (file >> r.id >> r.passenger >> r.flight >> r.travelDate >> r.seat)
            r.showData();

        file.close();
    }

    void findReservation() {
        int searchID;
        cout << "Enter Booking ID to search: ";
        cin >> searchID;

        ifstream idx("index_res.txt"), file("reservations.txt");
        if (!idx || !file) {
            cout << "No data available.\n";
            return;
        }

        int storedID;
        long pos;
        bool found = false;

        while (idx >> storedID >> pos) {
            if (storedID == searchID) {
                file.seekg(pos);
                Reservation r;
                file >> r.id >> r.passenger >> r.flight >> r.travelDate >> r.seat;
                cout << "\nReservation Found:\n";
                r.showData();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Booking ID not found.\n";

        idx.close();
        file.close();
    }
};

int main() {
    AirlineSystem as;
    int choice;
    do {
        cout << "\n1. Add Reservation\n2. View All Reservations\n3. Search Reservation\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: as.newReservation(); break;
            case 2: as.viewAll(); break;
            case 3: as.findReservation(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}