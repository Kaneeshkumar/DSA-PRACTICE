class Solution {
public:
    int CalcMinSum(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1)
        return triangle[i][j];

        if(dp[i][j]!=-1)
        return dp[i][j];

        int down=triangle[i][j]+CalcMinSum(i+1,j,triangle,dp);
        int downRight=triangle[i][j]+CalcMinSum(i+1,j+1,triangle,dp);

        return dp[i][j]=min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return CalcMinSum(0,0,triangle,dp);

        vector<int> prev(n,0);
        vector<int> temp;
        for(int i=0;i<n;i++){
            prev[i]=triangle[m-1][i];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> temp(triangle[i].size());
            for(int j=0;j<triangle[i].size();j++){
                int up=triangle[i][j]+prev[j];
                int upright=triangle[i][j]+prev[j+1];

                temp[j]=min(up,upright);
                }
                prev.resize(temp.size()-1);
                prev=temp;
        }

        return prev[0];

    
    }
};