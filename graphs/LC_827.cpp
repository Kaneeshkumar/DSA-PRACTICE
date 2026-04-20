class DisjointSet{
    public:
    vector<int> parent,usize;

    DisjointSet(int n){
        parent.resize(n+1);
        usize.resize(n+1,1);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(parent[node]==node)
        return node;

        return parent[node]=findPar(parent[node]);
    }

    void union1(int u,int v){
        int x=findPar(u);
        int y=findPar(v);

        if(x==y)
        return;

        if(usize[x]<usize[y]){
            parent[x]=y;
            usize[y]+=usize[x];
        }else{
            parent[y]=x;
            usize[x]+=usize[y];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                continue;
            
                for(int k=0;k<4;k++){
                    int crow=i+row[k];
                    int ccol=j+col[k];


                    if(crow>=0 && crow<n && ccol>=0 && ccol<n && grid[crow][ccol]==1){
                        int node=i*n+j;
                        int adjnode=crow*n+ccol;
                        ds.union1(node,adjnode);
                    }
                }

            }
        }
    int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                continue;


                set<int> connections;
                for(int k=0;k<4;k++){
                    int crow=i+row[k];
                    int ccol=j+col[k];


                    if(crow>=0 && crow<n && ccol>=0 && ccol<n && grid[crow][ccol]==1){
                        int newnode=crow*n+ccol;
                      int up=ds.findPar(newnode);
                      connections.insert(up);
                    }
            }

            int ts=0;
          for(auto it:connections){
            ts+=ds.usize[it];
          }
            maxi=max(maxi,ts+1);
        }
    }
    for(int cno=0;cno<n*n;cno++){
        maxi=max(maxi,ds.usize[ds.findPar(cno)]);
    }
    return maxi;
}
};