class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Your code goes here
        
        if(n==0 || n<0)
        return false;


        return !(n & (n-1));
    }
};