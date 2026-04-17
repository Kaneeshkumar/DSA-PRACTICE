class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                dist[i][j]=0;
            }
        }

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }


        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                  
                    if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX || i==j)
                    continue;
                    
                    if(dist[i][via]+dist[via][j]<dist[i][j])
                    dist[i][j]=dist[i][via]+dist[via][j];
                }
            }
        }

        vector<int> checkDist(n,0);

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j)
                continue;
                if(dist[i][j]<=dt)
                cnt++;
            }
            checkDist[i]=cnt;
        }

        int mini=INT_MAX;
        int city=-1;

        for(int i=0;i<n;i++){
            if(checkDist[i]<=mini){
            mini=checkDist[i];
            city=i;
            }
        }
        return city;
    }
};