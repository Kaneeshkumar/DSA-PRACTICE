class Solution {
public:
    // int calcMaxSum(int idx,vector<int>& nums,vector<int>& dp){
    //     if(idx==0)
    //     return nums[0];
    //     if(idx<0)
    //     return 0;

    //     if(dp[idx]!=-1)
    //     return dp[idx];

    //     int pick= nums[idx]+calcMaxSum(idx-2,nums,dp);
    //     int np=0+calcMaxSum(idx-1,nums,dp);

    //     return dp[idx]=max(pick,np);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return calcMaxSum(n-1,nums,dp);

        int prev1,prev2;
         prev2=nums[0];
        if(n>1)
         prev1=max(nums[0],nums[1]);

        if(n==1)
        return prev2;

        if(n==2)
        return prev1;

        for(int i=2;i<n;i++){
            int pc=nums[i]+prev2;
            int np=0+prev1;

            prev2=prev1;
            prev1=max(pc,np);
        }
        return prev1;




    }
};