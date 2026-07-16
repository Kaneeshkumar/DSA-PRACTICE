class Solution {
public:
    int calcGcd(int a,int b){

      while(true){  
        if(a>b){
            a=a%b;
            if(a==0)
            return b;
        }else{
            b=b%a;
            if(b==0)
            return a;
        }
      }

        return -1;

    }
    long long gcdSum(vector<int>& nums) {
        
        int maxi=0;
        int n=nums.size();
        vector<int> myArr;

        for(int i=0;i<n;i++){
            int curr=nums[i];
            maxi=max(maxi,nums[i]);

            int gcd=calcGcd(curr,maxi);
            myArr.push_back(gcd);
        }

        sort(myArr.begin(),myArr.end());
        int l=0;
        int r=myArr.size()-1;

        long long sum=0;


        while(l<r){
            int gcd=calcGcd(myArr[l],myArr[r]);
            sum+=gcd;
            l++;
            r--;
        }

        return sum;
    }
};