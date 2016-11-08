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

#define ull unsigned long long int

vector <int> v[2000 + 10];
int dis[1000 + 10];


int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        v[i].clear();
        dis[i] = 2e9;
    }
    int from,next,weight;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d", &from,&next,&weight);
        v[i].pb(from);
        v[i].pb(next);
        v[i].pb(weight);
    }
    dis[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int j=0;
        while(v[j].size() !=0)
        {
            if(dis[ v[j][0] ] + v[j][2] < dis[ v[j][1] ])
            {
                dis[ v[j][1] ] = dis[ v[j][0] ] + v[j][2];
            }
            j++;
        }
    }
    cout<<"Distances :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dis[i]<<endl;
    }
    return 0;
}
