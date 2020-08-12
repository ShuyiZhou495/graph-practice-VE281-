//
// Created by 周舒意 on 2020/8/6.
//

#ifndef CODING5_GRAPH_H
#define CODING5_GRAPH_H

#include <map>
#include <list>

using namespace std;

class graph {
private:
    int number_nodes = 0;
    map<int, list<pair<int, int>>> my_graph, my_undirected_graph; //from_key: (to_key, weight)
    map<int, int> incoming_edge; // key: incoming_edge
public:
    explicit graph(int number_nodes): number_nodes(number_nodes){
        for(int i = 0; i<number_nodes;i++){
            my_graph[i] = list<pair<int, int>>();
            incoming_edge[i] = 0;
        }
    }
    void add_edge(int from, int to, int weight);
    bool is_DAG();
    void show_is_DAG();
    static int find_0_key(const map<int, int> & input); // return key of 0 incoming edge
    int mst_weight();
    static pair<int, int> find_min_key(const map<int, double> & input); //return (key, min_value)
    void show_mst_weight();
    void undirected_insert(int from, int to, int weight);
};


#endif //CODING5_GRAPH_H
