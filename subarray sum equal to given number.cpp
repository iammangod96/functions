#include <iostream>
#include<vector>
using namespace std;

string equal_sub_array(vector<int> arr,int x){
	int start = 0, sum = 0,flag=0;
	sum+=arr[0];
	if(sum==x){
		flag=1;
	}else{
		for(int i=1;i<arr.size();i++){
			while(sum>x){
				sum -= arr[start];
				start++;
			}
			if(sum==x){
				flag=1;break;
			}
			sum+=arr[i];
		}
	}
	while(sum>x){
		sum-=arr[start];
		start++;
	}
	if(sum==x){
		flag = 1;
	}
	if(flag==1){
		return "yes";
	}else{
		return "no";
	}
	
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    for(int i=0;i<n;i++){
    	int q;
    	cin>>q;
    	arr.push_back(q);
    }
    cout<<equal_sub_array(arr,x);
    return 0;
}

