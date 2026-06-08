class Solution {
public:
    int currCost(int i,int j,vector<int>& arr){
        int n=j-i+1;
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            maxi=max(maxi,arr[k]);
        }

        return maxi*n;
    }
    int f(int i,int k,vector<int>& arr,vector<int>& dp){
        if(i>=arr.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int maxi=INT_MIN;
        for(int j=i;j<i+k && j<arr.size();j++){
            int cost=currCost(i,j,arr)+f(j+1,k,arr,dp);
            maxi=max(maxi,cost);
        }

        return dp[i]=maxi;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        // return f(0,k,arr,dp);

        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int maxi=INT_MIN;
            for(int j=i;j<i+k && j<n ;j++){
                int cost=currCost(i,j,arr)+dp[j+1];
                maxi=max(cost,maxi);
            }
            dp[i]=maxi;
        }
        return dp[0];
    }
};