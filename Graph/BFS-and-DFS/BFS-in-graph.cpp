void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of the frontNode
        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }

    }

}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    
    vector<int> ans; //
    unordered_map<int, bool> visited;


    bfs(adj, visited, ans, 0);

    return ans;
}