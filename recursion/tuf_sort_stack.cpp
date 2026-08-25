class Solution {
public:
    void f(int curr,int n,stack<int>& st,vector<int>& ans){
        if(curr==0)
        return;

        int top=st.top();
        st.pop();

        int idx=0;

        while(!ans.empty() && idx<ans.size() && ans[idx]<top)
        idx++;

        if(ans.empty() || idx==ans.size())
        ans.push_back(top);

        else{
        ans.insert(ans.begin()+idx,top);
        }

        f(curr-1,n,st,ans);

        
    }
    void sortStack(stack<int> &st) {
        // Your code goes here
        int n=st.size();

        vector<int> ans;
        f(n,n,st,ans);
        while(!st.empty()){
            st.pop();
        }

        for(int val:ans){
            st.push(val);
        }

        return;
    }
};