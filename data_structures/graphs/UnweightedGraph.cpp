#include "UnweightedGraph.h"
#include <stack>
#include <set>


template <class T>
vector<T> UnweightedGraph<T>::neighbors(T vertex) {
    return this->adjacency_list[vertex];
}


template <class T>
void UnweightedGraph<T>::bfs(T start) {
    set<T, less<T>> visited;
    stack<T> to_visit(start);

    while (not to_visit.empty()) {
        T current = to_visit.top();
        visited.insert(current);
        to_visit.pop();

        vector<T> neighbors = this->neighbors(current);

        for(auto neighbor = neighbors.begin(); neighbor != neighbors.end(); ++neighbor) {
            if (visited.find(*neighbor) == nullptr)
                visited.insert(*neighbor);
        }
    }
}