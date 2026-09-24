class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int mini=INT_MAX;

        for(int i=0;i<nums.size();i++){
            int val=nums[i],sum=0;
            while(val!=0){
                 sum+=val%10;
                val=val/10;    
            }

            if(sum==i)
            mini=min(mini,i);
        }

        return (mini==INT_MAX) ? -1:mini; 
    }
};