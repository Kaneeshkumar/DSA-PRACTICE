class Solution {
public:
    int calcProd(int n){
        int prod=1;

        while(n!=0){
            int last=n%10;
            prod=prod*last;
            n=n/10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        
    
        int curr=n;
        while(true){
            int product=calcProd(n);
            if(product%t==0)
            return n;

            else
            n=n+1;
        }
        return -1;       
      }
};