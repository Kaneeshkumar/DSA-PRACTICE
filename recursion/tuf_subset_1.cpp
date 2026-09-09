class Solution {
  public:
    void f(int idx,int n,vector<int>& nums,vector<int>& subans,vector<vector<int>>& ans,vector<int>& final1){
        
        int sum=0;
        for(int val:subans)
        sum+=val;

        final1.push_back(sum);


        for(int i=idx;i<n;i++){
            subans.push_back(nums[i]);
            f(i+1,n,nums,subans,ans,final1);
            subans.pop_back();
        }

        return;
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> subans;
        vector<int> final1;
        int n=nums.size();

        f(0,n,nums,subans,ans,final1);

        return final1;


    }
};