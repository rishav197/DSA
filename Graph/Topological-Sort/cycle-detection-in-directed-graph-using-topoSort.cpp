#include<list>
#include<queue>
#include<unordered_map>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj list
  unordered_map<int, list<int>> adj;

  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first-1;
    int v = edges[i].second-1;

    adj[u].push_back(v);
  }

  //step1: find all indegrees
  vector<int> indegree(n);
  for(auto i : adj){

    for(auto j : i.second){
      indegree[j]++;
    }
  }

  //step2: 0 indegree walo ko push kardo
  queue<int> q;
  for(int i=0; i<n; i++){

    if(indegree[i]==0){
      q.push(i);
    }
  }

  //step3: do bfs
  int count = 0;
  while(!q.empty()){
    int frontNode = q.front();
    q.pop();

    //increase count
    count++;

    //neighbour indegree update
    for(auto neighbour : adj[frontNode]){

      indegree[neighbour]--;

      if(indegree[neighbour]==0){
        q.push(neighbour);
      }
    }

  }

  if(count!=n){ //Valid TopoSort and acyclic
      return true;
  }
  return false; //Invalid TopoSort and cyclic

}