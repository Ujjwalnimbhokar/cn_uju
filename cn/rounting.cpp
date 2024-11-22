#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

void distanceVectorRouting(int n, vector<vector<int>> &cost) {
    vector<vector<int>> distance = cost;  // Initialize distance matrix
    vector<vector<int>> nextHop(n, vector<int>(n, -1)); // Next-hop matrix

    // Initialize next-hop matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cost[i][j] != INF && i != j) {
                nextHop[i][j] = j;
            }
        }
    }

    // Bellman-Ford Algorithm
    bool updated;
    do {
        updated = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (distance[i][k] != INF && distance[k][j] != INF &&
                        distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        updated = true;
                    }
                }
            }
        }
    } while (updated);

    // Print the routing tables
    for (int i = 0; i < n; ++i) {
        cout << "Routing table for router " << i + 1 << ":\n";
        cout << "Destination\tCost\tNext Hop\n";
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] == INF) {
                cout << j + 1 << "\t\tINF\t-\n";
            } else {
                cout << j + 1 << "\t\t" << distance[i][j] << "\t" << (nextHop[i][j] + 1) << "\n";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of routers: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n, INF));

    cout << "Enter the cost matrix (use " << INF << " for no direct link):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
            if (i == j) cost[i][j] = 0; // Cost to self is always 0
        }
    }

    distanceVectorRouting(n, cost);
    return 0;
}



// Output:
// Routing table for router 1:
// Destination	Cost	Next Hop
// 1		0	1
// 2		1	2
// 3		3	2
// 4		6	3

// Routing table for router 2:
// Destination	Cost	Next Hop
// 1		1	1
// 2		0	2
// 3		2	3
// 4		5	3

// Routing table for router 3:
// Destination	Cost	Next Hop
// 1		3	2
// 2		2	2
// 3		0	3
// 4		3	4

// Routing table for router 4:
// Destination	Cost	Next Hop
// 1		6	3
// 2		5	3
// 3		3	3
// 4		0	4