class Solution {
public:
    int f(int idx1,int idx2,string& s1,string& s2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0)
        return 0;

        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];

        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=1+f(idx1-1,idx2-1,s1,s2,dp);
        }

        return dp[idx1][idx2]=max(f(idx1-1,idx2,s1,s2,dp),f(idx1,idx2-1,s1,s2,dp));

        
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));

        int lps=f(len1-1,len2-1,word1,word2,dp);
        return len1-lps+len2-lps;
    }
};