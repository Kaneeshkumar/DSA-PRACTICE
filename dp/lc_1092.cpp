class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        vector<vector<int>> dp(l1+1,vector<int> (l2+1,0));

        for(int i=0;i<=l1;i++){
            dp[i][0]=0;
        }

        for(int j=0;j<=l2;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];

                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

      int x=l1;
      int y=l2;

      string ans="";

      while(x!=0 && y!=0){
        if(s[x-1]==t[y-1]){
            ans+=s[x-1];
            x--;
            y--;
        }else if(dp[x][y-1]>dp[x-1][y]){
            ans+=t[y-1];
            y--;

        }else{
            ans+=s[x-1];
            x--;
        }
      }

      while(x!=0){
        ans+=s[x-1];
        x--;
      }

      while(y!=0){
        ans+=t[y-1];
        y--;

      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};