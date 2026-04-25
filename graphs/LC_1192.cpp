class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& visited,vector<vector<int>>& bridges,int low[],int tin[]){
        visited[node]=1;
        low[node]=timer;
        tin[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent)
            continue;

            if(visited[it]==0){
                dfs(it,node,adj,visited,bridges,low,tin);
                low[node]=min(low[it],low[node]);

                if(low[it]>tin[node])
                bridges.push_back({it,node});
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& nums) {
        vector<int> adj[n];
        for(auto it:nums){
            int cnode=it[0];
            int tnode=it[1];

            adj[cnode].push_back(tnode);
            adj[tnode].push_back(cnode);
        }
        int low[n];
        int tin[n];
        vector<int> visited(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,visited,bridges,low,tin);
        return bridges;

    }
};