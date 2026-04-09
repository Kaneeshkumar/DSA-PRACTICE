    class Solution {
    public:
        bool checking(int i,vector<vector<int>> & graph,vector<int>& visited){
             int r=graph.size();
            int c=graph[0].size();

            
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int firstele=q.front();
                int markedprev=visited[firstele];
                q.pop();

                for(auto it:graph[firstele]){
                    if(visited[it]==-1){
                        visited[it]=!markedprev;
                        q.push(it);
                    }else if(visited[it]==markedprev){
                        return false;
                    }
                }
            }
            return true;

        }
        bool isBipartite(vector<vector<int>>& graph) {
            int r=graph.size();
            int c=graph[0].size();

         vector<int> visited(r,-1);

            for(int i=0;i<r;i++){
                if(visited[i]==-1){
                    bool b1=checking(i,graph,visited);
                    if(!b1)
                    return false;
                }
            }
            return true;


        }
    };