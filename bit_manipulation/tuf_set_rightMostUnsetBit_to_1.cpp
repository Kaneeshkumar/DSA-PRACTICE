class Solution {
public:
    int setRightmostUnsetBit(int n) {
        // Your code goes here
        int num=1;


    while(num<=n){
        if((n & num)==0){
            return n ^ num;
        }

        num=num<<1;

    }

    return n;

        return 0;
    }
};