#include <iostream>
#include <stack>
#include <set>
#include "searches.h"


template <class T>
void dfs_imp(UnweightedGraph<T> graph, T start){
    set<T> visited_vertices; // Use a set instead of a vector to increase the search time
                             // Also, no need to check if an element is not in the set already
    T current;

    stack<T> to_visit;
    to_visit.push(start);

    while (to_visit.size() != 0) {
        current = to_visit.top();
        to_visit.pop();
        visited_vertices.insert(current);
        cout << current << endl;

        vector<T> &neighbors = graph[current];
        for (auto neighbor = neighbors.cbegin(); neighbor != neighbors.cend() ;++neighbor) {
            if (visited_vertices.find(*neighbor) == visited_vertices.end())
                to_visit.push(*neighbor);
        }
    }
}

int main(){
    UnweightedGraph<int> g1;
    g1.insert(pair<int,vector<int>>(0, vector<int>()));
    g1[0].push_back(1);
    g1[0].push_back(2);
    g1.insert(pair<int,vector<int>>(1, vector<int>()));
    g1[1].push_back(3);
    g1[1].push_back(4);
    g1.insert(pair<int,vector<int>>(2, vector<int>()));
    g1.insert(pair<int,vector<int>>(3, vector<int>()));
    g1.insert(pair<int,vector<int>>(4, vector<int>()));

    dfs_imp(g1, 0);
}