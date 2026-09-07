class Solution {
public:
    void f(int i,int n,int target,vector<int>& nums,vector<int>& dp,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(dp);
            return;
        }

        for(int ind=i;ind<n;ind++){
            if(ind>i && nums[ind]==nums[ind-1])
            continue;

            if(nums[ind]>target)
            break;

            dp.push_back(nums[ind]);
            f(ind+1,n,target-nums[ind],nums,dp,ans);
            dp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> dp;
        int n=nums.size();

        f(0,n,target,nums,dp,ans);
        return ans;
    }
};