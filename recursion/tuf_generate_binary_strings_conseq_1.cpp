class Solution {
public:
    void f(int idx,int n,string curr,vector<string>& ans){
        if(idx==n){
            ans.push_back(curr);
            return;
        }

        f(idx+1,n,curr+"0",ans);

        if(idx==0 || curr[idx-1]!='1')
        f(idx+1,n,curr+"1",ans);


        return;


    }
    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
        vector<string> ans;
        f(0,n,"",ans);

        return ans;

    }
};
