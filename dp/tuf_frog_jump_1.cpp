class Solution {
public:
    // int recursion(int idx,vector<int>& heights,vector<int>& dp){
    //     if(idx==0)
    //     return 0;

    //     int left=recursion(idx-1,heights,dp)+abs(heights[idx]-heights[idx-1]);
    //     int right=INT_MAX;

    //     if(dp[idx]!=-1)
    //     return dp[idx];

    //     if(idx>1){
    //          right=recursion(idx-2,heights,dp)+abs(heights[idx]-heights[idx-2]);
    //     }

    //     return dp[idx]=min(left,right);
    // }
    int frogJump(vector<int>& heights) {
        // return recursion(n-1,heights,dp);
        int n=heights.size();


        int prev1=0;
        int prev2=0;
        int curr=0;

        for(int i=1;i<n;i++){
            int left=prev1+abs(heights[i]-heights[i-1]);
            int right=INT_MAX;
            if(i>1)
            right=prev2+abs(heights[i]-heights[i-2]);

             curr=min(left,right);
            prev2=prev1;
            prev1=curr;
        }

    return curr;

    }
};