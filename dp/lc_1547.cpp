class Solution {
public:
    int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i>j)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int operations=arr[j+1]-arr[i-1]+f(i,idx-1,arr,dp)+f(idx+1,j,arr,dp);
            mini=min(mini,operations);
        }

        return dp[i][j]=mini;
    }
    int minCost(int m, vector<int>& cuts) {
        int n=cuts.size();//initial size
        cuts.push_back(m);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        // return f(1,n,cuts,dp);

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){

                if(i>j)
                continue;
                
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                int ops=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,ops);
                }

                   dp[i][j]=mini;
            }
         
        }

        return dp[1][n];

    }
};