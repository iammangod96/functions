#include<iostream>
#include<vector>

using namespace std;

//kadane's algorithm
int max_subarray_sum(vector<int> arr){
	int max_so_far = 0;int max_ending_here = 0;
	for(int i=0;i<arr.size();i++){
		max_ending_here += arr[i];
		if(max_ending_here < 0){max_ending_here = 0;}
		if(max_ending_here > max_so_far){max_so_far = max_ending_here;}}
	return max_so_far;
}

int main(){
	int t;
	cin>>t;
	vector<int> arr;
	
	for(int i=0;i<t;i++){
		int q;
		cin>>q;
		arr.push_back(q);
	}
	
	cout<<max_subarray_sum(arr);
	return 0;
}
