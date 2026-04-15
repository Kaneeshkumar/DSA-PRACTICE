class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});

        if(grid[0][0]==1)
        return -1;

        int row[]={-1,0,+1,0,+1,-1,-1,+1};
        int col[]={0,+1,0,-1,+1,+1,-1,-1};



        while(!q.empty()){
            auto currdist=q.front().first;
            auto currrow=q.front().second.first;
            auto currcol=q.front().second.second;   
            q.pop();

            if(currdist>dist[currrow][currcol])
            continue;

            if(currrow==n-1 && currcol==n-1){
                return currdist+1;
            }

            for(int i=0;i<8;i++){
                int nrow=currrow+row[i];
                int ncol=currcol+col[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    if(grid[nrow][ncol]==1)
                    continue;
                    if(currdist+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=currdist+1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX){
            return -1;
        }
        return ans+1;
    }
};