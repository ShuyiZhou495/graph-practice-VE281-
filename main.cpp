//
// Created by 周舒意 on 2020/8/6.
//
#include "graph.h"
#include <sstream>
#include <iostream>

using namespace std;
int main(){
    string temp;
    getline(cin, temp);
    stringstream ss(temp);
    int number, from, to, weight;
    ss >> number;
    graph this_graph = graph(number);
    while (getline(cin, temp)) {
        if (!temp.empty()) {
            stringstream ss2(temp);
            ss2 >> from >> to >> weight;
            this_graph.add_edge(from, to, weight);
        }
    }
    this_graph.show_is_DAG();
    this_graph.show_mst_weight();

    return 0;
}