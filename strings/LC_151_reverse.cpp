class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int curr=0;
        int i=0;
           string fans="";
           string ans="";
        while(s[i]==' '){
            curr++;
            i++;
        }

            while(i<s.size()){
                ans="";
            while(i<s.size() && s[i]!=' '){
                ans+=s[i];
                i++;
            }
            reverse(ans.begin(),ans.end());
            fans+=ans+" ";
            i++;

            while(i<s.size() && s[i]==' '){
                i++;
            }

            }
            fans.erase(fans.length()-1);
            return fans;
    }
};