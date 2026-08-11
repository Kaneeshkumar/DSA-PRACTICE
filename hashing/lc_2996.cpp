class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;

        if(n==1)
        return nums[0]+1;


        int sum=nums[0];

        bool flag=true;
        unordered_set<int> s;
        

        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]+1  && flag){
                sum+=nums[i];
            }else if(i!=0 && nums[i]!=nums[i-1]+1){
                flag=false;
            }
            s.insert(nums[i]);
        }

        bool flag2=true;
        while(flag2){
            int present=0;
            for(auto it:s){
                if(it==sum){
                    sum=sum+1;
                    present=1;
                    break;
                }
            }
            if(!present)
            return sum;
        }

        return sum;
    }
};