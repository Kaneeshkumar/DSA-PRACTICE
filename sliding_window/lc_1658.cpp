class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum=0,n=nums.size();
        for(auto val:nums)
        sum+=val;

        int target=sum-x;
        int curr=0;

        int l=0,r=0,maxi=0;

        if(target==0)
        return n;

         if(target < 0)
            return -1;

        while(l<=r && r<n){
            curr+=nums[r];

            while(curr>target){
                curr=curr-nums[l];
                l++;
            }

            if(curr==target)
            maxi=max(r-l+1,maxi);

            r++;
        }

        return (maxi==0) ? -1:n-maxi;



    }
};