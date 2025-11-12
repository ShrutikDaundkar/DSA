#include <iostream>
using namespace std;

#define SIZE 5  // Fixed queue size

// ----- Circular Queue ADT -----
class CircularQueue {
private:
    int front, rear;
    int queue[SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more customers.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = data;
        cout << "Customer " << data << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No customer to serve.\n";
            return;
        }

        cout << "Customer " << queue[front] << " has been served.\n";

        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Next customer to serve: " << queue[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCurrent Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

// ----- Application: Ticket Booking -----
int main() {
    CircularQueue ticketQueue;
    int choice, customerID = 1;

    cout << "=== Ticket Booking System (Circular Queue ADT) ===\n";

    do {
        cout << "\n1. Add Customer\n2. Serve Customer\n3. View Next Customer\n4. Display Queue\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ticketQueue.enqueue(customerID++);
                break;
            case 2:
                ticketQueue.dequeue();
                break;
            case 3:
                ticketQueue.peek();
                break;
            case 4:
                ticketQueue.display();
                break;
            case 5:
                cout << "Exiting Ticket System...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
