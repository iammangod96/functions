#include<iostream>
#include<vector>

using namespace std;

// DEPTH FIRST SEARCH TO TRAVERSE GRAPH

vector<int> adj[10];
bool visited[10];

void dfs(int s){
	visited[s] = true;
	for(int i=0;i<adj[s].size();i++){
		if(visited[adj[s][i]]==false){
			dfs(adj[s][i]);
		}
	}
}

void init(){
	for(int i=0;i<10;i++){
		visited[i] = false;
	}
}

int main(){
	
	
	int nodes,edges,x,y;
	cin>>nodes>>edges;
	for(int i=0;i<nodes;i++)
        {
        	adj[i].clear();
      }
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	init();
	
	for(int i=1;i<=nodes;i++){
		if(visited[i]==false){
			dfs(i);
			//code required
			
		}
	}
	
	return 0;
}
