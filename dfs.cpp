

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

vector<int> adj[MAXK];
bool visited[MAXK];

void init()
{
    memset(visited,false,sizeof visited);
}

void dfs(int s)
{
    if(visited[s] == true) return;
    visited[s] = true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
        }
    }
}

int main(){

    int t;sd(t);

    while(t--)
    {
        init();

        int n;sd(n);
        int e;sd(e);
        for(int i=0;i<n;i++)
        {
        	adj[i].clear();
        }
            
        for(int i=0;i<e;i++)
        {
            int x,y;cin>>x>>y;
            adj[x].pb(y);adj[y].pb(x);
        }
        int num=0;

        for(int i=0;i<n;i++)
        {
            if(visited[i] == false){
                num++;dfs(i);
            }
        }

        cout<<num<<endl;


    }

    return 0;
}

