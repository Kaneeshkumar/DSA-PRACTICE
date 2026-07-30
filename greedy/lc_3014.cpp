class Solution {
public:
    int minimumPushes(string word) {
        
        int n=word.size();
        int minPush=0;
        int i=0;
        int mul=1;
        
        for(char c:word){
            i++;
            if(i==8){
                minPush+=mul*8;
                mul++;
                i=0;
            }
        }

        minPush+=i*mul;

        return minPush;
    }
};