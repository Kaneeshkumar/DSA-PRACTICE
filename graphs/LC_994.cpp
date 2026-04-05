class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue <pair<pair<int,int>,int>> q;
        int visited[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }else{
                    visited[i][j]=0;
                }              
            }
        }

        int time=0;
        int drow1[]={-1,0,+1,0};
        int dcol1[]={0,+1,0,-1};
        while(!q.empty()){
            int crow=q.front().first.first;
            int ccol=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);

            for(int i=0;i<4;i++){
                int nrow=drow1[i]+crow;
                int ncol=dcol1[i]+ccol;

                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                }
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1)
                return -1;
            }
        }
return time;
    }
};