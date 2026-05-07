class Solution {
public:

    int f(int idx,
          int amt,
          vector<int>& nums,
          vector<vector<int>>& dp){

        if(idx == 0){

            if(amt % nums[0] == 0)
                return amt / nums[0];

            return 1e9;
        }

        if(dp[idx][amt] != -1)
            return dp[idx][amt];

        int notTake = f(idx-1, amt, nums, dp);

        int take = 1e9;

        if(nums[idx] <= amt){
            take = 1 + f(idx,
                         amt - nums[idx],
                         nums,
                         dp);
        }

        return dp[idx][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& nums, int amt) {

        int n = nums.size();

        vector<vector<int>> dp(n,
                               vector<int>(amt+1, -1));

        int ans = f(n-1, amt, nums, dp);

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};