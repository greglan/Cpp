#ifndef PROGS_UNWEIGHTEDGRAPH_H
#define PROGS_UNWEIGHTEDGRAPH_H

#include <vector>
using namespace std;


template <class T>
class UnweightedGraph {
    public:
        vector<vector<T>> adjacency_list;

        vector<T> neighbors(T vertex);
        bool directed_graph();
        void bfs(T start);
};


#endif //PROGS_UNWEIGHTEDGRAPH_H
