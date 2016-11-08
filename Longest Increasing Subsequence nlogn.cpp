#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int main(){
    int s;cin>>s;
    while(s--){
            vector<int> arr;
            vector<int> lis;
            int t;cin>>t;
            while(t--){
                int x;
                cin>>x;arr.push_back(x);
            }
            lis.push_back(arr[0]);
            for(int i=1;i<arr.size();i++){
                if(arr[i] > lis[lis.size()-1]){
                    lis.push_back(arr[i]);
                }else{
                    int left = 0,right = (lis.size())-1;
                    while(left<right){
                        int mid = left + (right-left)/2;
                        if(lis[mid] >= arr[i]){
                            right = mid;
                        }else{
                            left = mid+1;
                        }
                    }
                    lis[left] = arr[i];
                }
                for(int i=0;i<lis.size();i++)
                    cout<<lis[i]<<endl;
                cout<<endl;
            }

    }

return 0;
}

