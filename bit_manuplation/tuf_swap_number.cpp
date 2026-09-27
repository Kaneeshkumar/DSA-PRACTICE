class Solution {
public:
    void swap(int &a, int &b) {
        // Your code goes here

        a=a^b;
        b=b^a;
        a=a^b;
    }
};