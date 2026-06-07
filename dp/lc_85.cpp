class Solution {
public:
    int histo(vector<int>& nums){
        stack<int> st;
        int maxi=0;
        int n=nums.size();
        int wt;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n ||nums[i]<nums[st.top()])){
                int ht=nums[st.top()];
                st.pop();
                if(st.empty())
                wt=i;
                else
                  wt=i-st.top()-1;
                maxi=max(maxi,ht*wt);
            }
            st.push(i);
        }
        return maxi;


    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> temp(m,0);   
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }else
                temp[j]=temp[j]+1;
            }
            maxi=max(histo(temp),maxi);

        }
        return maxi;
    }
};