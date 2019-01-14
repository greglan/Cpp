#ifndef PROGS_UNWEIGHTEDGRAPH_H
#define PROGS_UNWEIGHTEDGRAPH_H

#include <exception>
#include <map>
#include <vector>
using namespace std;


template <class T>
class UnweightedGraph {
    public:
        map<T, vector<T>> adjacency_list;

        UnweightedGraph();
        int insert_vertex(T vertex);
        vector<T> neighbors(T vertex);
        bool directed_graph();
        void bfs(T start);
};


struct VertexAlreadyInGraphException : public std::exception {
    const char * what () const throw () {
        return "The given vertex is already a node of the graph";
    }
};


#endif //PROGS_UNWEIGHTEDGRAPH_H
