class DisjointSet{
    public:
        vector<int> rank,parent;
        
        DisjointSet(int V){
            rank.resize(V,0);
            parent.resize(V);
        
        
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        }
        
        int find_par(int node){
            if(parent[node]==node)
            return node;
            
            return parent[node]=find_par(parent[node]);
        }
        
        void union1(int u,int v){
            int x=find_par(u);
            int y=find_par(v);
            
            if(x==y)
            return;
            
            else{
                if(rank[x]<rank[y]){
                    parent[x]=y;
                }else if(rank[x]>rank[y]){
                    parent[y]=x;
                }else{
                    parent[x]=y;
                    rank[y]++;
                }
            }
        }
    
    
};
class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // // code here
        // int sum=0;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        
        // vector<int> vis(n,0);
        // pq.push({0,0});
        
        
        // vector<pair<int,int>> adj[n];
        // for(auto it:edges){
        //     int u=it[0];
        //     int v=it[1];
            
        //     int wt=it[2];
            
        //     adj[u].push_back({v,wt});
        //     adj[v].push_back({u,wt});
        // }
        
        
        // while(!pq.empty()){
        //     auto it=pq.top();
            
        //     int wt=it.first;
        //     int node=it.second;
        //     pq.pop();
            
        //     if(!vis[node]){
        //         vis[node]=1;
        //         sum+=wt;
                
                
        //         for(auto it:adj[node]){
        //             int adjnode=it.first;
        //             int wt1=it.second;
        //             if(!vis[adjnode]){
        //                 pq.push({wt1,adjnode});
        //             }
        //         }
        //     }
            
            
            
        // }
        
        
        // return sum;
        
        
        
        vector<pair<int,pair<int,int>>> allEdges;
        
    
            for(auto it:edges){
                auto node=it[0];
                auto adjnode=it[1];
                auto wt=it[2];
                
                allEdges.push_back({wt,{node,adjnode}});
            }
            
        
        
        DisjointSet obj(n);
     
        
        sort(allEdges.begin(),allEdges.end());
        int mstwt=0;
        
        
            for(auto it:allEdges){
                int wt=it.first;
                int node=it.second.first;
                int adjnode=it.second.second;
                
                if(obj.find_par(node)!=obj.find_par(adjnode)){
                    mstwt+=wt;
                    obj.union1(node,adjnode);
                    
                }
            }
        
        
        
        
        
        return mstwt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};