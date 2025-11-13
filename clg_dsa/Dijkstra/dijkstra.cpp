#include <iostream>
using namespace std;

#define INF 9999

class ShortestPath {
private:
    int cityCount;
    int graph[20][20];
    int distance[20];
    int visited[20];

public:
    void readData() {
        cout << "Enter total number of cities: ";
        cin >> cityCount;
        cout << "Enter the cost matrix (use 0 if no direct connection):\n";
        for (int i = 0; i < cityCount; i++) {
            for (int j = 0; j < cityCount; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == 0 && i != j)
                    graph[i][j] = INF;
            }
        }
    }

    void findShortestPath(int start) {
        for (int i = 0; i < cityCount; i++) {
            distance[i] = graph[start][i];
            visited[i] = 0;
        }
        distance[start] = 0;
        visited[start] = 1;

        for (int count = 1; count < cityCount - 1; count++) {
            int minimum = INF, nextCity = -1;

            for (int i = 0; i < cityCount; i++) {
                if (!visited[i] && distance[i] < minimum) {
                    minimum = distance[i];
                    nextCity = i;
                }
            }

            visited[nextCity] = 1;

            for (int i = 0; i < cityCount; i++) {
                if (!visited[i] && (distance[nextCity] + graph[nextCity][i] < distance[i])) {
                    distance[i] = distance[nextCity] + graph[nextCity][i];
                }
            }
        }
    }

    void showResults(int start) {
        cout << "\nMinimum travel cost from city " << start << " to others:\n";
        for (int i = 0; i < cityCount; i++) {
            if (i != start) {
                cout << "To city " << i << " = " << distance[i] << "\n";
            }
        }
    }
};

int main() {
    ShortestPath sp;
    int startCity;

    sp.readData();
    cout << "Enter the source city: ";
    cin >> startCity;

    sp.findShortestPath(startCity);
    sp.showResults(startCity);

    return 0;
}