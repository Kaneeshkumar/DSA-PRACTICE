class Solution{
  public:
    int f(int idx,int maxLen,vector<int>& price,vector<vector<int>>& dp){
        if(idx==0){
            return maxLen*price[idx];
        }

        if(dp[idx][maxLen]!=-1)
        return dp[idx][maxLen];

        int notTake=0+f(idx-1,maxLen,price,dp);
        int take=INT_MIN;
        if(idx+1<=maxLen){
            take=price[idx]+f(idx,maxLen-(idx+1),price,dp);
        }

        return dp[idx][maxLen]=max(take,notTake);
        
    }
    int rodCutting(vector<int> price, int n) {
    int N=n;
    vector<vector<int>> dp(n,vector<int> (N+1,-1));
    //  return f(n-1,N,price,dp);

    for(int i=0;i<=N;i++){
        dp[0][i]=(i)*price[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=N;j++){
            
        int notTake=0+dp[i-1][j];
        int take=INT_MIN;
        if(i+1<=j){
            take=price[i]+dp[i][j-(i+1)];
        }

         dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][N];
    }
};
