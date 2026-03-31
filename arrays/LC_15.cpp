class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int f,s,t,val;
        vector<vector<int>> ans;
        
        for(int i=0;i<n-1;i++){
            
              if(i > 0 && nums[i] == nums[i-1])
                continue;
            f=i;
            s=i+1;
           t=n-1;

           while(s<t){
            val=nums[f]+nums[s]+nums[t];
            if((val)==0){
                ans.push_back({nums[f],nums[s],nums[t]});
                s++;
                t--;

                while(s < t && nums[s] == nums[s-1]) s++;

                    // Skip duplicates for t
                    while(s < t && nums[t] == nums[t+1]) t--;

            }else if(val<0){
                s++;
            }else {
                t--;
            }
           }
        }
        return ans;
    }
};