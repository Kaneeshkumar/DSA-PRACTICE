class Solution {
public:
    int calcMaxSum(int start,int end,vector<int>& nums){
        int prev1=nums[start];
        int prev2=0;

        for(int i=start+1;i<=end;i++){
            int pick=nums[i]+prev2;
            int notpick=0+prev1;
            prev2=prev1;
            prev1=max(pick,notpick);
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);

        int case1=calcMaxSum(0,n-2,nums);
        int case2=calcMaxSum(1,n-1,nums);

        return max(case1,case2);
    }
};