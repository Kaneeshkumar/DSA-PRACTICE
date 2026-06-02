class Solution {
public:
    int f(int idx1,int idx2,string& s,string& t,vector<vector<int>>& dp){

        if(idx1<0 && idx2<0)
        return true;
//idx2->t and idx1->s
        if(idx1>=0 && idx2<0)
        return false;

        if(idx1<0 && idx2>=0){
            for(int p=0;p<=idx2;p++){
                if(t[p]!='*')
                return false;
            }
            return true;
        }

        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];


        if(s[idx1]==t[idx2] || t[idx2]=='?')
        return dp[idx1][idx2]=f(idx1-1,idx2-1,s,t,dp);

        if(t[idx2]=='*')
        return dp[idx1][idx2]=f(idx1-1,idx2,s,t,dp) || f(idx1,idx2-1,s,t,dp);

        return dp[idx1][idx2]=false;
    }
    bool isMatch(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));

        // return f(m-1,n-1,s,t,dp);

        dp[0][0]=1;


        for(int i=1;i<=m;i++){
            dp[i][0]=0;
        }

        // bool foundNoStar=false;
        // for(int j=1;j<=n;j++){
        //     dp[0][j]=1;
        //     if(t[j-1]!='*'){
        //         foundNoStar=true;
        //     }
        // }

        // for(int j=1;j<=n;j++){
        //     if(foundNoStar)
        //     dp[0][j]=0;
        // }

        for(int j=1;j<=n;j++)
{
    if(t[j-1]=='*')
        dp[0][j]=dp[0][j-1];
    else
        dp[0][j]=0;
}

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(s[i-1]==t[j-1] || t[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];

                else if(t[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];

                else
                dp[i][j]=0;
            }
        }

        return dp[m][n];

        
        




    }
};