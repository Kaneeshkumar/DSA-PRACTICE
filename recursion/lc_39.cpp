class Solution {
public:
    void f(int idx,int n,int target,vector<int>& nums,vector<int>& sub,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(sub);
            return;
        }
        if(idx==n){
            return;
        }

        if(nums[idx]<=target){
            sub.push_back(nums[idx]);
            f(idx,n,target-nums[idx],nums,sub,ans);
            sub.pop_back();
        }

        f(idx+1,n,target,nums,sub,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n=nums.size();

        f(0,n,target,nums,sub,ans);


        return ans;

    }
};