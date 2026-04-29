class Solution {
public:
    int f(int day,int last,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last)
                maxi=max(maxi,matrix[day][i]);
            }
            return maxi;
        }

        if(dp[day][last]!=-1)
        return dp[day][last];

        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int points=matrix[day][i]+f(day-1,i,matrix,dp);
                maxi=max(maxi,points);
            }
        }
        return dp[day][last]=maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // vector<vector<int>> dp(n,vector<int> (4,-1));
        // return  f(n-1,3,matrix,dp);


        //2
        int n=matrix.size();
        vector<int> prev(4,0);

        prev[0]=max(matrix[0][1],matrix[0][2]);  
        prev[1]=max(matrix[0][0],matrix[0][2]);
        prev[2]=max(matrix[0][1],matrix[0][0]);  
        prev[3]=max(max(matrix[0][1],matrix[0][2]),matrix[0][0]);

        for(int day=1;day<n;day++){
            vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                temp[last]=0;

                for(int i=0;i<3;i++){
                    if(i!=last){
                        int point=matrix[day][i]+prev[i];
                        temp[last]=max(point,temp[last]);
                    }
                }
            }
            prev=temp;
        }
        return prev[3];
    }
};