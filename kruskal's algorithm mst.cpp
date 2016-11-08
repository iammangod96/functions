#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>


using namespace std;

const int MAX = 1e4+5;
int id[MAX],nodes,edges;
vector< pair<long long,pair<int,int> > > p;

void init(){
	for(int i=0;i<MAX;i++){
		id[i] = i;
	}
}

int root(int x){
	while(id[x]!=x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void unionit(int x,int y){
	id[root(x)] = id[root(y)];
}

long long kruskal(vector<pair<long long,pair<int,int> > > p){
	int x,y;
	long long minimumCost=0,cost=0;;
	for(int i=0;i<edges;i++){
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if (root(x)!=root(y))
		{
			minimumCost += cost;
			unionit(x,y);
		}
	}
	return minimumCost;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		
	
	int x,y;
	long long cost,minimumCost,weight;
	init();
	cin>>nodes>>edges;
	for (int i = 0; i < edges; ++i)
	{
		cin>>x>>y>>weight;
		p.push_back(make_pair(weight,make_pair(x,y)));
	}
	sort(p.begin(),p.end());
	minimumCost = kruskal(p);
	cout<<minimumCost<<endl;
	
	}
	return 0;
}

/*----------------------------------------------------------*/

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
#define MAXK 100000
#define MAXN 1000000000
int ar[MAXK];
int get(int n, int k){
    int i=0;
    while(i<k and ar[i]<=n)i++;
    return n-i;
}

pair<LL,pair<int, int> > P[MAXK];
int nodes,edges;

void init()
{
    for(int i=0;i<MAXK;i++)
    {
        ar[i] = i;
    }
}

int root(int x)
{
    while(ar[x]!=x)
    {
        ar[x] = ar[ar[x]];
        x = ar[x];
    }
    return x;
}

void union1(int x, int y)
{
    ar[root(x)] = ar[root(y)];
    return;
}

LL kruskal(pair<LL , pair<int,int> > p[])
{
    int x,y;
    LL cost,min_cost=0;
    for(int i=0;i<edges;i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            min_cost += cost;
            union1(x,y);
        }
    }
    return min_cost;
}

int main()
{
    init();
    int x,y;
    LL weight;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        P[i] = make_pair(weight, make_pair(x,y));
    }
    sort(P,P+edges);
    cout<<kruskal(P)<<endl;

    return 0;
}
