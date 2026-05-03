class Solution {
public:
    int calcMaxChoco(int i,int j1,int j2,int r,int c,vector<vector<int>>& g,  vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=c || j2<0 || j2>=c)
        return -1e8;

            if(i==r-1){
                if(j1==j2)
                return g[i][j1];

                else
                return g[i][j1]+g[i][j2];
            }

            if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];

            int maxi=INT_MIN;
            int val;
            for(int dj1=-1;dj1<=1;dj1++){
                for(int dj2=-1;dj2<=1;dj2++){
                      val=g[i][j1];
               if(j1!=j2){
                        val+=g[i][j2];
                    }

                   maxi=max((val+calcMaxChoco(i+1,j1+dj1,j2+dj2,r,c,g,dp)),maxi);
                }
            }

            return dp[i][j1][j2]=maxi;
          

    }
    int maxChocolates(vector<vector<int>>& g) {
        // Your code goes here
        int r=g.size();
        int c=g[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

        // return calcMaxChoco(0,0,c-1,r,c,g,dp);

        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2)
                dp[r-1][j1][j2]=g[r-1][j1];
                else 
                dp[r-1][j1][j2]=g[r-1][j1]+g[r-1][j2];
            }
        }


        for(int i=r-2;i>=0;i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxi=INT_MIN;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int val=g[i][j1];
                            if(j1!=j2)
                            val+=g[i][j2];

                            
                            if(dj1+j1>=0 && dj1+j1<c && dj2+j2>=0 && dj2+j2<c)
                            maxi=max(maxi,(val+dp[i+1][j1+dj1][j2+dj2]));
                            else maxi=max(maxi,val+(-1e8));
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }


        return dp[0][0][c-1];

    }
};