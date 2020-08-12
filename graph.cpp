//
// Created by 周舒意 on 2020/8/6.
//

#include "graph.h"
#include <set>
#include <iostream>

void graph::add_edge(int from, int to, int weight) {
    my_graph[from].push_back(pair<int, int>(to, weight));
    undirected_insert(from, to, weight);
    undirected_insert(to, from, weight);
    incoming_edge[to]++;
}

bool graph::is_DAG() {
    if(number_nodes==0) return false;
    map<int, int> incoming_edge_here = incoming_edge;//edge, key
    while(!incoming_edge_here.empty()){
        int temp_node = find_0_key(incoming_edge_here);
        if(temp_node==-1) return false;
        for(auto & it : my_graph[temp_node]) incoming_edge_here[it.first] --;
        incoming_edge_here.erase(temp_node);
    }
    return true;
}

int graph::find_0_key(const map<int, int> &input) {
    for(auto it : input) if(it.second==0) return it.first;
    return -1;
}

void graph::show_is_DAG() {
    if(is_DAG()) cout<<"The graph is a DAG"<<endl;
    else cout<<"The graph is not a DAG"<<endl;
}

int graph::mst_weight() {
    map<int, double> distance;
    int total_weight = 0;
    if(number_nodes==0) return -1;
    distance[0] = 0;
    for(int i = 1; i<number_nodes; i++) distance[i] = 0.5;
    while(!distance.empty()){
        pair<int,int> temp_node = find_min_key(distance);
        if(temp_node.first==-1) return -1;
        distance.erase(temp_node.first);
        total_weight += temp_node.second;
        for(auto & it : my_undirected_graph[temp_node.first]) {
            if (distance.count(it.first) &&
                (distance[it.first] == 0.5 || (distance[it.first] != 0.5 && distance[it.first] > it.second)))
                distance[it.first] = it.second;
        }
    }

    return total_weight;
}

pair<int, int> graph::find_min_key(const map<int, double> &input) {
    int min, min_key = -1;
    auto it = input.begin();
    for(;it!=input.end();it++) if(int(it->second)==it->second){
            min = int(it->second);
            min_key = it->first;
            break;
    };
    for(;it!=input.end();it++) if(int(it->second)==it->second && it->second<min) {
            min = int(it->second);
            min_key = it->first;
    }
    return pair<int, int>(min_key, min);
}

void graph::show_mst_weight() {
    int mst_weight_ = mst_weight();
    if(mst_weight_==-1) cout<<"No MST exists!"<<endl;
    else cout<<"The total weight of MST is "<<mst_weight_<<endl;
}

void graph::undirected_insert(int from, int to, int weight) {
    for(auto it=my_undirected_graph[from].begin(); it != my_undirected_graph[from].end(); it++){
        if(it->first==to){
            if(weight<it->second) {
                it->second = weight;
            }
            return;
        }
    }
    my_undirected_graph[from].push_back(pair<int, int>(to, weight));
}
