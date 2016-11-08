#include<iostream>
#include<vector>
#include<stack>

using namespace std;



int main(){
    vector<int> arr;
    vector<int> dp;
    vector<int> lis;
	stack<int> S;
	int maxl = 1;
	int bestend = 0;
	int t;cin>>t;
	while(t--){
        int x;
        cin>>x;arr.push_back(x);
    }

    dp.push_back(1);
    lis.push_back(-1);
    for(int i=1;i<arr.size();i++)
    {
        dp.push_back(1);
        lis.push_back(-1);
        for(int j=i-1;j>=0;j--)
        {
            if((arr[j] < arr[i]) && ((dp[j] + 1) > dp[i]))
                {
                    lis[i] = j;
                    dp[i] = dp[j] + 1;
                }
        }
        if(dp[i]>maxl){
            maxl = dp[i];
            bestend = i;
        }
    }
    /*
    9
    2 6 3 4 1 2 9 5 8
    */
    cout<<endl;
    int current = bestend;
    while(current != -1)
    {
        S.push(arr[current]);
        current = lis[current];
    }
    
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
	return 0;
}

