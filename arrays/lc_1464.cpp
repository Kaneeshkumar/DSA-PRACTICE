class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=-1;
        int sl=-1;

        if(nums.size()<2)
        return -1;

        for(int val:nums){
            if(val>l){
                sl=l;
                l=val;
            }else if(val>sl)
            sl=val;
        }

        return (sl-1)*(l-1);
    }
};