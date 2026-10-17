class Solution {
public:
    int countSumOfDigits(int val){
        int sum=0;

        while(val>0){
            int last=val%10;
            sum+=last;
            val=val/10;
        }

        return sum;

    }

    int minSwaps(vector<int>& nums) {
        int cnt=0,n=nums.size();
        unordered_map<int,int> m,index;
        vector<int> temp;

        for(int i=0;i<n;i++){
            m[nums[i]]=countSumOfDigits(nums[i]);
            index[nums[i]]=i;
        }

        for(auto it:m){
            temp.push_back(it.first);
        }


        sort(temp.begin(),temp.end(),[&m](int& a,int& b){
        
            if(m[a]!=m[b]){
                return m[a]<m[b];
            }
                return a<b;
            

            return a<b;
        });



      for(int i=0;i<n;i++){
    if(nums[i]!=temp[i]){
        cnt++;
        int j=index[temp[i]];     // where the correct element currently sits
        index[nums[i]]=j;         // the element at i is about to move to j
        index[temp[i]]=i;         // the correct element is about to land at i
        swap(nums[i],nums[j]);
    }
}

        return cnt;



        
    }
};