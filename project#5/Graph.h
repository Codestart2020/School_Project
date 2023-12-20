//
// Created by jemon nixon on 11/17/23.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;



class Graph {
private:
    int V;
    vector<vector<int> > adjMatrix;

    int minKey(vector<int> key, vector<bool> inMST) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
            if (inMST[v] == false && key[v] < min)
                min = key[v], min_index = v;

        return min_index;
    }

    void printMST(vector<int> parent) {
        cout << "Spanning tree:\n";
        for (int i = 1; i < V; i++)
            cout << (char)('A' + parent[i]) << " " << (char)('A' + i) << "\n";
    }

public:
    Graph(int vertices) : V(vertices), adjMatrix(V, vector<int>(V, 0)) {}

    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = adjMatrix[v][u] = w;
    }

    void primMST() {
        vector<int> parent(V);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            for (int v = 0; v < V; v++)
                if (adjMatrix[u][v] && inMST[v] == false && adjMatrix[u][v] < key[v])
                    parent[v] = u, key[v] = adjMatrix[u][v];
        }

        printMST(parent);
    }
};





#endif //PROJECT_5_GRAPH_H
