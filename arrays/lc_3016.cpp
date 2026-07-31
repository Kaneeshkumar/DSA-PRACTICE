class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alpa(26,0);

        for(char c:word){
            alpa[c-'a']++;
        }

        sort(alpa.begin(),alpa.end());
        reverse(alpa.begin(),alpa.end());

        int mul=1;
        int push=0;
        int i=0;
        int cnt=0;

        while(i<26 && alpa[i]!=0){
            push+=alpa[i]*mul;
            cnt++;
            i++;
            if(cnt==8){
                mul++;
                cnt=0;
            }

        }

        return push;


    }
};