class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        if(n<=2)
        return n;

        int maxi=INT_MIN,mini=INT_MAX;
        int mxi=-1,mi=-1;

        for(int i=0;i<n;i++){
            int val=nums[i];
            if(val>maxi){
                maxi=val;
                mxi=i;
            }

            if(val<mini){
                mini=val;
                mi=i;
            }
        }

        int ans=max(mxi,mi)+1;
        int start=-1,end=-1,backAns=-1;
    

        if(mxi<mi){
            start=mxi+1;
            end=n-mi;
            backAns=end+(mi-mxi);
        }else{
            start=mi+1;
            end=n-mxi;
            backAns=end+(mxi-mi);
        }

        ans=min(ans,(start+end));

        ans=min(ans,backAns);

        return ans;





    }
};