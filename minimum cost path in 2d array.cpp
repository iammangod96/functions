#includeiostream
#includevector
#includealgorithm

using namespace std;

int mini(int a, int b, int c){
    int d = min(a,b);
    return min(d,c);
}

int min_cost_path(int arr[3][3], int m,int  n){
    int dp[3][3];
    dp[0][0] = arr[0][0];
    for(int i=1;i=m;i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    for(int j=1;j=n;j++){
        dp[0][j] = dp[0][j-1] + arr[0][j];
    }

  for(int i=1;i=m;i++){
    for(int j=1;j=n;j++){
        dp[i][j] = arr[i][j] +mini(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[m][n];
}

int main(){
    int cost[3][3] = {{1,2,3},{4,8,2},{1,5,3}};
    cout<<min_cost_path(cost, 2, 2)<<endl;
return 0;
}

