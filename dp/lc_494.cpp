class Solution {
public:

    int f(int idx,
          int target,
          vector<int>& nums,
          vector<vector<int>>& dp,
          int offset){

        // OUT OF RANGE
        if(abs(target) > offset)
            return 0;

        // Base case
        if(idx == 0){

            if(target == 0 && nums[0] == 0)
                return 2;

            if(target == nums[0] ||
               target == -nums[0])
                return 1;

            return 0;
        }

        // DP check
        if(dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        int takeP = f(idx-1,
                      target - nums[idx],
                      nums,
                      dp,
                      offset);

        int notP = f(idx-1,
                     target + nums[idx],
                     nums,
                     dp,
                     offset);

        return dp[idx][target + offset]
               = takeP + notP;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        int n = nums.size();

        int ts = 0;

        for(int val : nums)
            ts += val;

        if(abs(target) > ts)
            return 0;

        int offset = ts;

        vector<vector<int>> dp(
            n,
            vector<int>(2*ts + 1, -1)
        );

        return f(n-1,
                 target,
                 nums,
                 dp,
                 offset);
    }
};