class Solution {
public:
    int f(int idx,int prev_idx,vector<int>& nums,vector<vector<int>> &dp){

        if(idx==nums.size())
        return 0;

        if(dp[idx][prev_idx+1]!=-1)
        return dp[idx][prev_idx+1];

        int notTake=0+f(idx+1,prev_idx,nums,dp);
        int take=INT_MIN;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx])
        take=1+f(idx+1,idx,nums,dp);

        return dp[idx][prev_idx+1]=max(take,notTake);
    }
    int LIS(vector<int>& nums) {
      int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    //   return f(0,-1,nums,dp);


      for(int i=0;i<=n;i++){
        dp[n][i]=0;
      }

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notTake=0+dp[i+1][j+1];
                int take=0;

                if(j==-1 ||  nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }

                dp[i][j+1]=max(take,notTake);
            }
        }

      return dp[0][0];
    }    
};