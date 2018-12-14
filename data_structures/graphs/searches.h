#ifndef PROGS_SEARCHES_H
#define PROGS_SEARCHES_H

#include <map>
#include <vector>
using namespace std;


template <class T> using UnweightedGraph = map<T, vector<T>>;

template <class T>
void dfs_imp(UnweightedGraph<T> graph, T start);

template <class T>
void bfs_imp(UnweightedGraph<T> graph);

#endif //PROGS_SEARCHES_H
