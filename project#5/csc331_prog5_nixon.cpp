//JEMON NIXON
// CSC 331 501L[38867]
// Project 5
// Due Date: 12/7/23
// environment : CLion and visual studio code



#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;




int main() {
    int V = 3;
    Graph g(V);

    string u, v;
    int w;
    while (cin >> u >> v >> w) {
        if (u == "end-of-file") break;
        g.addEdge(u[0] - 'A', v[0] - 'A', w);
    }

    g.primMST();

    return 0;
}

