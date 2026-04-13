class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        // vector<pair<int,int>> adj[n];
        // for(int i=0;i<edges.size();i++){
        //     int u=edges[i][0];
        //     int v=edges[i][1];
        //     int wt=edges[i][2];
            
        //     adj[u].push_back({v,wt});
        //     adj[v].push_back({u,wt});
        // }
        
        // vector<int> dist(n,INT_MAX);
        // dist[src]=0;
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq.push({0,src});
        
        // while(!pq.empty()){
        //     int dist1=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
            
        // if(dist1 > dist[node]) continue;

            
        //     for(auto it:adj[node]){
        //         auto adjnode=it.first;
        //         auto wt=it.second;
                
        //         if(dist1+wt<dist[adjnode]){
        //             dist[adjnode]=dist1+wt;
        //             pq.push({dist[adjnode],adjnode});
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(dist[i]==INT_MAX)
        //     dist[i]=-1;
        // }
        // return dist;
        
        vector<pair<int,int>> adj[n];
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        set<pair<int,int>> s;
        s.insert({0,src});
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        
        while(!s.empty()){
            auto it=*(s.begin());
            auto currdist=it.first;
            auto node=it.second;
            s.erase(it);
            
            if(currdist>dist[node])
            continue;
            
            for(auto it:adj[node]){
                int nextnode=it.first;
                int wt=it.second;
                
                if(currdist+wt<dist[nextnode]){
                     if(dist[nextnode] != INT_MAX){
                        s.erase({dist[nextnode], nextnode});
                    }
                    
                    dist[nextnode]=currdist+wt;
                    s.insert({dist[nextnode],nextnode});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
    }
};