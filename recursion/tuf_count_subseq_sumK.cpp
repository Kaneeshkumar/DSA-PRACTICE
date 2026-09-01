class Solution{
    public: 
    int f(int idx,int target,vector<int>& nums){
        if(target==0)
        return 1;

        if(idx==-1)
        return 0;

        int left=0;
        if(nums[idx]<=target){
         left=f(idx-1,target-nums[idx],nums);
        }

        int right=f(idx-1,target,nums);
        return left + right;
    }   	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here

        int n=nums.size();
        return f(n-1,k,nums);
        
    }
};