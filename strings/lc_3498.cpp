class Solution {
public:
    int reverseDegree(string s) {
        int sum=0,i=1;

        for(char c:s){
            sum+=(('z'- c)+1)*i;
            i++;
        }

        return sum;
    }
};