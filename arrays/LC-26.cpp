class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            int val=nums[i];
            if(val!=curr){
                nums[k++]=val;
                curr=val;
            }
        }
        return k;
    }
};