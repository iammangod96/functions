#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[10000];
bool visited[10000];

void init(){
	for(int i=0;i<10000;i++){
		visited[i] = false;
	}
}

void bfs(int s){
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(int i=0;i<adj[v].size();i++){
			if(visited[adj[v][i]]==false){
				Q.push(adj[v][i]);
				visited[adj[v][i]]= true;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
        {
        	adj[i].clear();
        }
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		init();
		bfs(1);
	}

	return 0;

}

