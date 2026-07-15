class Solution {
public:
    int calcGcd(int a,int b){

        while(1){
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
    int gcdOfOddEvenSums(int n) {
        
        int oddSum=0;
        int evenSum=0;

        int ca=1;
        int cb=2;

        for(int i=1;i<=n;i++){
            oddSum+=ca;
            evenSum+=cb;

            ca+=2;
            cb+=2;
        }


        return calcGcd(oddSum,evenSum);
    }
};