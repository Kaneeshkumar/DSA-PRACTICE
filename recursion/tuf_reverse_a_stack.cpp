    class Solution {
public:
    void f(int idx,int n,vector<int>& ans,stack<int>& st){
        if(idx==0)
        return;

        int top=st.top();
        st.pop();
        ans.push_back(top);

        f(idx-1,n,ans,st);

    }
    void reverseStack(stack<int> &st) {
        // Your code goes here

        int n=st.size();

        vector<int> ans;
        f(n,n,ans,st);

        while(!st.empty()){
            st.pop();
        }

        for(int val:ans)
        st.push(val);

        return;
    }
};