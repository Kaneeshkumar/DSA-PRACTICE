class Solution {
  public:
    void dfs(int i, vector<int>& visited, stack<int>& st, vector<pair<int,int>> adj[]) {
        visited[i] = 1;
        
        for(auto it : adj[i]) {
            int v = it.first;
            if(!visited[v]) {
                dfs(v, visited, st, adj);
            }
        }
        st.push(i);
    }

    vector<int> shortestPath(int n, int E, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n];
        vector<int> visited(n, 0);
        stack<int> st;
        
        // build graph
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // topo sort
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, st, adj);
            }
        }
        
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        // relax edges in topo order
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(dist[node] != INT_MAX) { // ✅ important
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // unreachable → -1
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};