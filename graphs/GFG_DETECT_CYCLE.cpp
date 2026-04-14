
bool checkCycle(vector<int> adj[],vector<int>& visited,int i){
    
    queue<pair<int,int>> q;
    
    visited[i]=1;
    
    q.push({i,-1});
    
    while(!q.empty()){
        int curr=q.front().first;
        int parent=q.front().second;
        q.pop();
        
        for(auto it:adj[curr]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,curr});
            }else if(parent!=it)
            return true;
        
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {

    vector<int> adj[V];
    vector<int> visited(V,0);
    

    
    for(int i=0;i<E;i++){
        int first=edges[i][0];
        int second=edges[i][1];
        
        adj[first].push_back(second);
        adj[second].push_back(first);
        
        
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
           bool b1=checkCycle(adj,visited,i);
           if(b1)
           return true;
        }
    }
    return false;
    
}