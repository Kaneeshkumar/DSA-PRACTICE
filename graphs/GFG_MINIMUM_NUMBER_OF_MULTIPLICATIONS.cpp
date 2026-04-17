// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        queue<pair<int,long long>> q;
        q.push({0,start});
        
        if(start==end)
        return 0;
        
        vector<int> dist(100000,INT_MAX);
        dist[start]=0;
        
        while(!q.empty()){
            auto pushes=q.front().first;
            auto endval=q.front().second;
            q.pop();
            
            
            
            if(endval==end)
            return pushes;
            
            for(int i=0;i<arr.size();i++){
                long long mynewval=endval*arr[i]%100000;
                if(dist[mynewval]==INT_MAX){
                    dist[mynewval]=pushes+1;
                q.push({pushes+1,mynewval});
                }
            }
        }
        return -1;
        
    }
};
