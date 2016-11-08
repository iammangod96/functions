    #include <iostream>
    #include <vector>
    #include <queue>
     
    using namespace std;
     
    bool visited[10001];
    vector<int> adj[10001];
    int depth[10001];
     
    int bfs(int s) {
        queue <int> q;
        q.push(s);
        int max=0,newsource=1;
        visited[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int i = 0;i < adj[ p ].size() ; i++)
            {
                if(visited[ adj[ p ][ i ] ] == false)
                {
                    depth[adj[p][i]] = depth[p]+1;
    				q.push(adj[ p ][ i ]);
                    visited[adj[ p ][ i ]] = true;
                    if(max < depth[adj[p][i]]){
                    	max = depth[adj[p][i]];
                    	newsource = adj[p][i];
                    }
      			}
            }
        }
        
        return newsource;
    }
     
    int main(){
    	
    	int n;
    	cin>>n;
    	--n;
    	while(n--){
    		int x,y;
    		cin>>x>>y;
    		adj[x].push_back(y);
    		adj[y].push_back(x);
    	}
    	for(int i=0;i<10001;i++){
    		visited[i] = false;
    		depth[i] = 0;
    	}
    	int newsource = bfs(1);
    	depth[newsource] = 0;
    	for(int i=0;i<10001;i++){
    		visited[i] = false;
    	}
    	int req = bfs(newsource);
    	cout<<depth[req];
    	return 0;
    } 