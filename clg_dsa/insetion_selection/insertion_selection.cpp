#include <iostream>
using namespace std;

class BookInfo {
public:
    int id;
    string title;
    int year;
};

class LibrarySystem {
private:
    BookInfo books[50];
    int count;

public:
    void addBooks() {
        cout << "Enter number of books: ";
        cin >> count;
        cin.ignore();

        for (int i = 0; i < count; i++) {
            cout << "\nEnter Book ID: ";
            cin >> books[i].id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, books[i].title);

            cout << "Enter Publication Year: ";
            cin >> books[i].year;
        }
    }

    void showBooks() {
        cout << "\nBook Details:\n";
        for (int i = 0; i < count; i++) {
            cout << books[i].id << "  " << books[i].title << "  " << books[i].year << "\n";
        }
    }

    void sortByTitle() {
        for (int i = 1; i < count; i++) {
            BookInfo key = books[i];
            int j = i - 1;
            while (j >= 0 && books[j].title > key.title) {
                books[j + 1] = books[j];
                j--;
            }
            books[j + 1] = key;
        }
    }

    void sortByYear() {
        for (int i = 0; i < count - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < count; j++) {
                if (books[j].year < books[minIndex].year)
                    minIndex = j;
            }
            if (minIndex != i) {
                BookInfo temp = books[i];
                books[i] = books[minIndex];
                books[minIndex] = temp;
            }
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n1. Display All Books"
                 << "\n2. Sort by Title (Insertion Sort)"
                 << "\n3. Sort by Year (Selection Sort)"
                 << "\n4. Exit"
                 << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    showBooks();
                    break;
                case 2:
                    sortByTitle();
                    cout << "\nBooks Sorted by Title:\n";
                    showBooks();
                    break;
                case 3:
                    sortByYear();
                    cout << "\nBooks Sorted by Year:\n";
                    showBooks();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    LibrarySystem lib;
    lib.addBooks();
    lib.menu();
    return 0;
}