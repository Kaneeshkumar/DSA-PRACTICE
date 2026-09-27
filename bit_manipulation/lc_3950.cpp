class Solution {
public:
    bool consecutiveSetBits(int n) {
        int x=n;
        if(x==0)
            return false;

        int cnt=0;
        int prev=0;

        while(x!=0){
            int curr=x%2;

            if(cnt>1)
                return false;
            
            if(curr==prev && prev==1)
                cnt++;

            prev=curr;
            x=x/2;

        }
        return cnt==1;
    }
};