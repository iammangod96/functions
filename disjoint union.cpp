#include<iostream>
#include<set>
using namespace std;
//------------------------------------------
//disjoint union 2

void init(int arr[],int n){
	for(int i=1;i<=n;i++){
		arr[i] = i;
	}
}

int root(int n,int arr[]){
	while(arr[n]!= n){
		arr[n] = arr[arr[n]];
		n = arr[n];
	}
	return n;
}

bool find(int arr[],int a,int b){
	if(root(a,arr)==root(b,arr)){
		return true;
	}else{
		return false;
	}
}
//parent of a is b
void unionit (int arr[],int a,int b){
	arr[root(a,arr)]=root(b,arr);
}
//--------------------------------------------
//weighted disjoint union

void initw(int size[],int arr[],int n){
	for(int i=1;i<=n;i++){
		arr[i] = i;
		size[i] = 1;
	}
}

void unionitw(int arr[],int size[],int a,int b){
	int root_a = root(a,arr);
	int root_b = root(b,arr);
	if(size[root_a]<size[root_b]){
		arr[root_a] = arr[root_b];
		size[root_b]+=size[root_a];
	}else{
		arr[root_b] = arr[root_a];
		size[root_a]+=size[root_b];
	}
}

//--------------------------------------------
int main()
{
   int n,k;
   cin>>n>>k;
   int A[n+1];
   int S[n+1];
   initw(S,A,n);
   set<int> set1;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		unionitw(A,S,x,y);
	}
	for(int i=1;i<=n;i++){
		set1.insert(A[i]);
	}
	cout<<set1.size();
    return 0;
}

