class Solution {
public:
    int CalcMinSum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){

        if(j<0 || j>=matrix.size())
        return 1e9+7;
        if(i==0)
        return matrix[i][j];

        if(dp[i][j]!=-1)
        return dp[i][j];


        int up=matrix[i][j]+CalcMinSum(i-1,j,matrix,dp);
        int left=matrix[i][j]+CalcMinSum(i-1,j-1,matrix,dp);
        int right=matrix[i][j]+CalcMinSum(i-1,j+1,matrix,dp);



        return dp[i][j]=min(up,min(left,right));

        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int mini=INT_MAX;
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> prev(n,0);
        // for(int j=0;j<n;j++){
        //     int currval=CalcMinSum(n-1,j,matrix,dp);
        //     mini=min(currval,mini);
        // }

        // return mini;


        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }
        int upleft,upright;

        for(int i=1;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                upleft=upright=1e9+7;
                int up=matrix[i][j]+prev[j];
                if(j>0)
                 upleft=matrix[i][j]+prev[j-1];
                if(j<n-1)
                 upright=matrix[i][j]+prev[j+1];

                 temp[j]=min(up,min(upleft,upright));
            }
            prev=temp;
        }

        for(int i=0;i<n;i++){
            mini=min(prev[i],mini);
        }

        return mini;
    }
};