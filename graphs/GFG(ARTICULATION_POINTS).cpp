// User function Template for C++

class Solution {
  public:
  int timer=1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& visited,int low[],int tin[],vector<int>& mark){
        visited[node]=1;
        low[node]=timer;
        tin[node]=timer;
        timer++;
        
        int child=0;
        
        for(auto it:adj[node]){
            if(it==parent)
            continue;
            
            else if(!visited[it]){
                dfs(it,node,adj,visited,low,tin,mark);
                low[node]=min(low[node],low[it]);
                child++;
                
                if(parent!=-1 && low[it]>=tin[node]){
                    mark[node]=1;
                }
            }else{//visited
                low[node]=min(low[node],tin[it]);
            }
            
        }
        if(parent==-1 && child>1){
            mark[node]=1;
        }
    }
    
    
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> visited(n,0);
        int low[n];
        int tin[n];
        
        vector<int> ans;
        vector<int> mark(n,0);
        
        for(int i=0;i<n;i++){
            if(!visited[i])
            dfs(i,-1,adj,visited,low,tin,mark);
        }
        
        
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0)
        return {-1};
        
        return ans;
        
    }
};