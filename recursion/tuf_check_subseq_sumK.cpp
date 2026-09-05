class Solution{
    public:
    bool f(int idx,int n,int target,vector<int>& nums){
        if(target==0)
        return true;

        if(idx==n){
            return false;
        }


        if(nums[idx]<=target){
            if(f(idx+1,n,target-nums[idx],nums))
            return true;
        }

         if(f(idx+1,n,target,nums))
         return true;

         return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here

        int n=nums.size();
         return f(0,n,k,nums);
    }
};