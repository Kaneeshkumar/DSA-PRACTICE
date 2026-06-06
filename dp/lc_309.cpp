class Solution {
public:
     int f(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size())
        return 0;

        if(dp[i][buy]!=-1)
        return dp[i][buy];

        if(buy){
            int buy1=-prices[i]+f(i+1,0,prices,dp);
            int buy0=0+f(i+1,1,prices,dp);
            return dp[i][buy]=max(buy1,buy0);
        }

        int sell1=prices[i]+f(i+2,1,prices,dp);
        int sell0=0+f(i+1,0,prices,dp);
        return dp[i][buy]=max(sell1,sell0);


    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(0,1,prices,dp);
    }
};