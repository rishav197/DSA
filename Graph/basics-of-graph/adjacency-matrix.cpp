#include <bits/stdc++.h>
using namespace std;


class graph{
public:
    int V; //vertices or nodes
    vector<vector<int>> mat; //adjacency 2d matrix    

    //constructor 
    graph(int nodes) : V(nodes), mat(nodes, vector<int>(nodes, 0)) {}

    void addEdge(int i, int j, int direction){
        mat[i][j] = 1;
        
        if(direction==0){ //graph is undirected
            mat[j][i] = 1;
        }
    }

    void printGraph(){
        int n = mat.size();
        cout<<"Display:"<<endl;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                
                cout<<mat[row][col]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int vertices = 4; //no. of nodes

    graph g(vertices);

    //add edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    g.printGraph();




    return 0;
}