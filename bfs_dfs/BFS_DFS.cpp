#include <iostream>
using namespace std;

class ComputerNetwork {
private:
    int nodes;
    int matrix[20][20];
    int visited[20];

public:
    void createNetwork() {
        cout << "Enter total number of computers: ";
        cin >> nodes;

        cout << "Enter adjacency matrix (use 1 for connection, 0 for no connection):\n";
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void performBFS(int startNode) {
        int q[20];
        int front = 0, rear = 0;

        for (int i = 0; i < nodes; i++)
            visited[i] = 0;

        visited[startNode] = 1;
        q[rear++] = startNode;

        cout << "\nInfection spread sequence using BFS: ";
        while (front < rear) {
            int current = q[front++];
            cout << current << " ";

            for (int i = 0; i < nodes; i++) {
                if (matrix[current][i] == 1 && visited[i] == 0) {
                    q[rear++] = i;
                    visited[i] = 1;
                }
            }
        }
        cout << "\n";
    }

    void dfsRecursive(int v) {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < nodes; i++) {
            if (matrix[v][i] == 1 && visited[i] == 0)
                dfsRecursive(i);
        }
    }

    void performDFS(int startNode) {
        for (int i = 0; i < nodes; i++)
            visited[i] = 0;

        cout << "\nTracing infection path using DFS: ";
        dfsRecursive(startNode);
        cout << "\n";
    }
};

int main() {
    ComputerNetwork network;
    int infected;

    network.createNetwork();
    cout << "Enter the initially infected computer: ";
    cin >> infected;

    network.performBFS(infected);
    network.performDFS(infected);

    return 0;
}