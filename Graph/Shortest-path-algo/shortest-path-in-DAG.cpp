#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }

    void prtAdj(){
        for(auto i : adj){
            cout<<i.first << "->";

            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool> &vis, stack<int> &topo){
        vis[node]=true;

        for(auto neighbour : adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first, vis, topo);
            }
        }

        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo){
        dist[src]=0;

        while(!topo.empty()) {
            int top = topo.top();
            topo.pop();

            if(dist[top]!=INT_MAX){
                
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
            
        }
    }
};


int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.prtAdj();


    int n = 6;
    //topological sort
    unordered_map<int,bool> visited;
    stack<int> topo;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, topo);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, topo);

    cout<<"answer is : "<<endl;

    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;


    return 0;
}


/*Code2 : Using dfs() and getShortestPath() function outside the graph class */
#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
	unordered_map<int, list<pair<int,int>>> adj;
	
	
	void addEdge(int u, int v, int weight){
		pair<int,int> p = make_pair(v, weight);
		adj[u].push_back(p);
	}
	
	void prtAdj(){
		for(auto i : adj){
			cout<<i.first<<"->";
			
			for(auto j : i.second){
				cout<<j.first<<","<<j.second<<" ";
			}
			cout<<endl;
		}
	}
};


void dfs(int node, unordered_map<int,bool> &vis, stack<int> &topo, unordered_map<int, list<pair<int,int>>> &adj){
	vis[node]=1;
	
	for(auto neighbhor : adj[node]){
		if(!vis[neighbhor.first]){
			dfs(neighbhor.first, vis, topo, adj);
		}
		
	}
	
	topo.push(node);
}


void getShortestPath(int src, vector<int> &dist, stack<int> &topo, unordered_map<int, list<pair<int,int>>> &adj){
	dist[src]=0;
	
	while(!topo.empty()){
		int top = topo.top();
		topo.pop();
		
		if(dist[top]!=INT_MAX){
			
			for(auto i : adj[top]){
				if(dist[top]+i.second < dist[i.first]){
					dist[i.first] = dist[top] + i.second;
				}
			}
		}
	}
}

int main() {
	
	Graph g;
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 6);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
	

	g.prtAdj();
	
	int n = 6;
	//step1: topo sort
	unordered_map<int,bool> vis;
	stack<int> topo;
	// unordered_map<int, list<pair<int,int>>> adj = g.adj;
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			dfs(i, vis, topo, g.adj);
		}
	}
	
	//step2: 
	int src=1;	
	vector<int> dist(n);
	for(int i=0; i<n; i++){
		dist[i] = INT_MAX;
	}

	getShortestPath(src, dist, topo, g.adj);
	
	cout<<"Answer : ";
	for(int i=0; i<dist.size(); i++){
		cout<<dist[i]<<" ";
	}

	return 0;
}