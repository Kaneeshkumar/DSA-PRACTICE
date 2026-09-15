class Solution {
public:
    bool isPal(int st,int end,string& s){
        int i=st;
        int j=end;
        while(i<j){
            if(s[i]!=s[j])
            return false;

            i++;
            j--;
        }

        return true;
    }
    void f(int idx,string& s,vector<vector<string>>& ans,vector<string>& subans){
        
    if(idx==s.size()){
        ans.push_back(subans);
        return;
    } 

    for(int i=idx;i<s.size();i++){
        if(isPal(idx,i,s)){
            subans.push_back(s.substr(idx,i-idx+1));
            f(i+1,s,ans,subans);
            subans.pop_back();
        }
    }

    return;

    }
    vector<vector<string> > partition(string s) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> subans;

        f(0,s,ans,subans);

        return ans;
    }
};