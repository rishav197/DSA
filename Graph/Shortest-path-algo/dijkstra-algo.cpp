#include <bits/stdc++.h> 


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // Creation of distance array with infinite val initially
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    // Creation of set on basis (distance, node)
    set<pair<int,int>> st;

    //Initialise distance and set with source node
    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        //remove top record now (pop)
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){

            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                //if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDist + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }

    }

    return dist;

}
