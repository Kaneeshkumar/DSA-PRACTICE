class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            unordered_map<int,int> m; 
            for(int j=i;j>=0;j--){
                m[nums[j]]++;
                
                int currSize=m.size();
                cnt+=(currSize*currSize);
        }
        }

        return cnt;
    }
};