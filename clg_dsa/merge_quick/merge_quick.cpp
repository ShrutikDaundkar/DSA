#include<iostream>
using namespace std;

class Menu {
public:
    int item_ID;
    string item_name;
    int item_calories;
    int item_preparation;
};

class Restaurant {
public:
    Menu m[50];
    int n;

    void input() {
        cout << "Enter number of menu items: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter Item ID: ";
            cin >> m[i].item_ID;
            cin.ignore();
            cout << "Enter Item Name: ";
            getline(cin, m[i].item_name);
            cout << "Enter Item Calories: ";
            cin >> m[i].item_calories;
            cout << "Enter Preparation Time (in minutes): ";
            cin >> m[i].item_preparation;
        }
    }

    void display() {
        cout << "\nMenu Details:\n";
        cout << "-----------------------------------------------\n";
        cout << "ID\tName\t\tCalories\tPrep Time\n";
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << m[i].item_ID << "\t" << m[i].item_name << "\t\t"
                 << m[i].item_calories << "\t\t" << m[i].item_preparation << " min\n";
        }
    }

    
    int partition(int low, int high) {
        int pivot = m[high].item_calories;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (m[j].item_calories < pivot) {
                i++;
                Menu temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
        Menu temp = m[i + 1];
        m[i + 1] = m[high];
        m[high] = temp;
        return i + 1;
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    
    void merge(int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        Menu L[25], R[25];
        for (int i = 0; i < n1; i++)
            L[i] = m[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = m[mid + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i].item_preparation <= R[j].item_preparation) {
                m[k] = L[i];
                i++;
            } else {
                m[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            m[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            m[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(l, mid);
            mergeSort(mid + 1, r);
            merge(l, mid, r);
        }
    }
};

int main() {
    Restaurant r;
    int ch;
    r.input();
    do {
        cout << "\n1. Display Menu\n2. Sort by Calories (Quick Sort)\n3. Sort by Preparation Time (Merge Sort)\n4. Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1)
            r.display();
        else if (ch == 2) {
            r.quickSort(0, r.n - 1);
            cout << "\nMenu Sorted by Calories:\n";
            r.display();
        }
        else if (ch == 3) {
            r.mergeSort(0, r.n - 1);
            cout << "\nMenu Sorted by Preparation Time:\n";
            r.display();
        }
    } while (ch != 4);
    return 0;
}