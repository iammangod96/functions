

#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n)
{LL ret=1;LL b=a;while(n) {if(n&1)
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXK 100005
#define MAXN 1000000000
int ar[MAXK];
int get(int n, int k){
    int i=0;
    while(i<k and ar[i]<=n)i++;
    return n-i;
}
vector<int> adj[10000];
bool visited[10000];
int level[10000];

void init(){
	for(int i=0;i<10000;i++){
		visited[i] = false;
		level[i]=0;
	}
}

void bfs(int s){
    int lev=0;
    level[s]=0;
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	Q.push(-1);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
        if(v == -1)
        {
            lev++;
            Q.push(-1);
            if(Q.front() == -1) break;
        }
        else
        {
            level[v]=lev;
            for(int i=0;i<adj[v].size();i++){
                if(visited[adj[v][i]]==false){
                    Q.push(adj[v][i]);
                    visited[adj[v][i]]= true;
                }
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
		for(int i=1;i<=n;i++)
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
		for(int i=1;i<=n;i++)
        {
            cout<<i<<" : "<<level[i]<<endl;
        }
	}

	return 0;

}

