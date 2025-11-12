#include<iostream>
using namespace std;

class Zone {
public:
    int zone_ID;
    string zone_Name;
    float reading;
};

class SensorData {
public:
    Zone z[50];
    int n;

    void input() {
        cout << "Enter number of zones: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter Zone ID: ";
            cin >> z[i].zone_ID;
            cin.ignore();
            cout << "Enter Zone Name: ";
            getline(cin, z[i].zone_Name);
            cout << "Enter Sensor Reading: ";
            cin >> z[i].reading;
        }
    }

    void heapify(int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && z[l].reading > z[largest].reading)
            largest = l;
        if (r < n && z[r].reading > z[largest].reading)
            largest = r;

        if (largest != i) {
            Zone temp = z[i];
            z[i] = z[largest];
            z[largest] = temp;
            heapify(n, largest);
        }
    }

    void heapSort() {
        
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        
        for (int i = n - 1; i > 0; i--) {
            Zone temp = z[0];
            z[0] = z[i];
            z[i] = temp;
            heapify(i, 0);
        }
    }

    void displayAll() {
        cout << "\nZone Details (Sorted by Reading):\n";
        cout << "----------------------------------------\n";
        cout << "ID\tZone Name\tReading\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << z[i].zone_ID << "\t" << z[i].zone_Name << "\t\t" << z[i].reading << "\n";
        }
    }

    void top5() {
        cout << "\nTop 5 Zones with Highest Readings:\n";
        cout << "----------------------------------------\n";
        cout <<"ID\tZone Name\tReading\n";
        cout <<"----------------------------------------\n";
        int limit = (n < 5) ? n : 5;
        for (int i = n - 1; i >= n - limit; i--) {
            cout << z[i].zone_ID << "\t" << z[i].zone_Name << "\t\t" << z[i].reading << "\n";
        }
    }
};

int main() {
    SensorData s;
    s.input();
    s.heapSort();
    s.displayAll();
    s.top5();
    return 0;
}