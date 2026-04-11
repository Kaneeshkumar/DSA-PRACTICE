class Solution {
public:
    bool dfs(int i,vector<int>& visited,vector<int>& pathvisited,vector<int>adj[],vector<int>& ans){       
        visited[i]=1;
        pathvisited[i]=1;

        for(auto it:adj[i]){
            if(!visited[it]){
            bool b1=dfs(it,visited,pathvisited,adj,ans);
            if(!b1)
            return false;
            }else if(pathvisited[it]==1)
            return false;
        }

        pathvisited[i]=0;
        ans.push_back(i);
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i])
            bool b1=dfs(i,visited,pathvisited,adj,ans);
        }


        sort(ans.begin(),ans.end());
        return ans;
    }
};