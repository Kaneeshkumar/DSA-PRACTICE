class Solution {
public:	
    void f(int idx,int n,vector<int>& nums,vector<int>& subAns,vector<vector<int>>& ans){
        ans.push_back(subAns);
        

        for(int i=idx;i<n;i++){
            subAns.push_back(nums[i]);
            f(i+1,n,nums,subAns,ans);
            subAns.pop_back();
        }

        return;


    }
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<int> subAns;
        vector<vector<int>> ans;
        int n=nums.size();
        
        f(0,n,nums,subAns,ans);
        return ans;
    }
};