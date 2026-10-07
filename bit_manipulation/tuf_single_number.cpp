class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        int n=nums.size();

        int xor1=0;

        for(auto val:nums){
            xor1=xor1^val;
        }

        return xor1;

    }
};