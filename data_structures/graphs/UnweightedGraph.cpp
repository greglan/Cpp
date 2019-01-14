#include "UnweightedGraph.h"
#include <stack>
#include <set>
#include <iostream>


template <class T>
UnweightedGraph<T>::UnweightedGraph() {

}


template <class T>
int UnweightedGraph<T>::insert_vertex(T vertex) {
    if (this->adjacency_list.find(vertex) == this->adjacency_list.end()) {
        this->adjacency_list[vertex] = vector<T>();
        return 0;
    } else
        throw VertexAlreadyInGraphException();
}


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


/*int main() {
    UnweightedGraph<int> g;
    std::cout << (g.adjacency_list.size() == 0);
    g.insert_vertex(0);
    g.insert_vertex(1);
}*/
