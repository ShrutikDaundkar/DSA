#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 10; 

class Gamer {
public:
    int gamerID;
    string userName;
    int points;
    int rank;
    int nextIndex;

    Gamer() {
        gamerID = -1;
        userName = "";
        points = 0;
        rank = 0;
        nextIndex = -1;
    }
};


int computeHash(int id) {
    return id % SIZE;
}

class GameLeaderboard {
public:
    
    void setup() {
        ofstream file("game_data.dat", ios::binary);
        Gamer g;
        for (int i = 0; i < SIZE; i++)
            file.write((char*)&g, sizeof(g));
        file.close();
        cout << "\nLeaderboard initialized successfully.\n";
    }

    
    void insertGamer() {
        fstream file("game_data.dat", ios::in | ios::out | ios::binary);
        Gamer newGamer, temp;
        
        cout << "\nEnter Gamer ID: ";
        cin >> newGamer.gamerID;
        cin.ignore();
        cout << "Enter Username: ";
        getline(cin, newGamer.userName);
        cout << "Enter Score: ";
        cin >> newGamer.points;
        cout << "Enter Rank: ";
        cin >> newGamer.rank;
        newGamer.nextIndex = -1;

        int hashPos = computeHash(newGamer.gamerID);
        int bytePos = hashPos * sizeof(Gamer);
        file.seekg(bytePos);
        file.read((char*)&temp, sizeof(temp));

        
        if (temp.gamerID == -1) {
            file.seekp(bytePos);
            file.write((char*)&newGamer, sizeof(newGamer));
        } 
        else {
            int previous = hashPos;
            
            while (temp.nextIndex != -1) {
                previous = temp.nextIndex;
                file.seekg(previous * sizeof(Gamer));
                file.read((char*)&temp, sizeof(temp));
            }

            
            for (int i = 0; i < SIZE; i++) {
                file.seekg(i * sizeof(Gamer));
                file.read((char*)&temp, sizeof(temp));

                if (temp.gamerID == -1) {
                    
                    file.seekp(i * sizeof(Gamer));
                    file.write((char*)&newGamer, sizeof(newGamer));

                    
                    file.seekg(previous * sizeof(Gamer));
                    file.read((char*)&temp, sizeof(temp));
                    temp.nextIndex = i;
                    file.seekp(previous * sizeof(Gamer));
                    file.write((char*)&temp, sizeof(temp));
                    break;
                }
            }
        }

        file.close();
        cout << "Gamer added successfully.\n";
    }

    
    void showLeaderboard() {
        ifstream file("game_data.dat", ios::binary);
        Gamer g;

        cout << "\n--- Leaderboard Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            file.read((char*)&g, sizeof(g));
            cout << i << " : ";
            if (g.gamerID != -1)
                cout << g.gamerID << "  " << g.userName << "  " 
                     << g.points << "  " << g.rank << "  Next-> " << g.nextIndex << endl;
            else
                cout << "Empty Slot\n";
        }
        file.close();
    }

    
    void searchGamer() {
        ifstream file("game_data.dat", ios::binary);
        int id;
        cout << "\nEnter Gamer ID to search: ";
        cin >> id;

        int hashPos = computeHash(id);
        Gamer g;
        file.seekg(hashPos * sizeof(Gamer));
        file.read((char*)&g, sizeof(g));

        bool found = false;
        while (g.gamerID != -1) {
            if (g.gamerID == id) {
                cout << "\nGamer Found:\n";
                cout << g.gamerID << "  " << g.userName << "  "
                     << g.points << "  " << g.rank << endl;
                found = true;
                break;
            }
            if (g.nextIndex == -1) break;
            file.seekg(g.nextIndex * sizeof(Gamer));
            file.read((char*)&g, sizeof(g));
        }

        if (!found) cout << "Gamer not found.\n";
        file.close();
    }
};

int main() {
    GameLeaderboard board;
    int choice;

    board.setup();

    do {
        cout << "\n====== Game Leaderboard Menu ======\n";
        cout << "1. Add Gamer\n";
        cout << "2. View Leaderboard\n";
        cout << "3. Search Gamer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: board.insertGamer(); break;
            case 2: board.showLeaderboard(); break;
            case 3: board.searchGamer(); break;
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}