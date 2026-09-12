class Solution {
public:
    void f(int idx,int n,vector<int>& nums,vector<int>& subans,vector<vector<int>>& ans){
        ans.push_back(subans);

        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1])
            continue;

            subans.push_back(nums[i]);
            f(i+1,n,nums,subans,ans);
            subans.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subAns;
        vector<vector<int>> ans;
        int n=nums.size();

        f(0,n,nums,subAns,ans);
        return ans;
    }
};