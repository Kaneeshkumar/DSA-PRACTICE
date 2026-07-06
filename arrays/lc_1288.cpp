#include<bits/stdc++.h>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        
        int n=nums.size();
        int cnt=n;

        vector<int> found(n,-1);
        int cfirst,csecond;

        for(int i=0;i<n-1;i++){
            if(found[i]==-1){
             cfirst=nums[i][0];
             csecond=nums[i][1];
            }else
            continue;

            for(int j=i+1;j<n;j++){
                if(found[j]==-1){
                int mfirst=nums[j][0];
                int msecond=nums[j][1];

                if(mfirst>=cfirst && msecond<=csecond){
                    found[j]=1;
                    cnt--;
                }
                

                else if(mfirst<=cfirst && msecond>=csecond){
                    found[i]=1;
                    cnt--;
                    break;
                }
                }else{
                    continue;
                }
                
            }
        }
        return cnt;

    }
};