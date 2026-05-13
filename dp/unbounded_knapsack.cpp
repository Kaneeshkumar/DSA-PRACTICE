class Solution
{
    public:
    int f(int idx,int maxWeight,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(idx==0){
            return (int)(maxWeight/wt[0])*val[0];
        }

        if(dp[idx][maxWeight]!=-1)
        return dp[idx][maxWeight];

        int notTake=0+f(idx-1,maxWeight,val,wt,dp);
        int take=INT_MIN;
        if(wt[idx]<=maxWeight){
            take=val[idx]+f(idx,maxWeight-wt[idx],val,wt,dp);
        }

        return dp[idx][maxWeight]=max(take,notTake);
    }
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {

            // vector<vector<int>> dp(n,vector<int> (W+1,-1));
            vector<int> prev(W+1,0);
            
            // return f(n-1,W,val,wt,dp);

            for(int i=0;i<=W;i++){
                prev[i]=(int)(i/(wt[0]))*val[0];
            }

            for(int i=1;i<n;i++){
                for(int j=0;j<=W;j++){
                    int notTake=prev[j];
                    int take=INT_MIN;

                    if(wt[i]<=j)
                    take=val[i]+prev[j-wt[i]];

                prev[j]=max(take,notTake);
                }
            }

            return prev[W];
       }
};
