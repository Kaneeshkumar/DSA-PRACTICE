class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int> m;
        string sample="IVXLCDM";
        vector<int> v={1,5,10,50,100,500,1000};

        for(int i=0;i<sample.size();i++){
            m[sample[i]]=v[i];
        }
        
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1 && m[s[i+1]]>m[s[i]]){
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }else{
                ans+=m[s[i]];
            }
        }
        return ans;
    }
};