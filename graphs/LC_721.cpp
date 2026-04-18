class DisjointSet{
    public:
    vector<int> rank,parent;

    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n,0);

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

        else{
            if(rank[x]<rank[y]){
                parent[x]=y;
            }else if(rank[x]>rank[y]){
                parent[y]=x;
            }else{
                parent[y]=x;
                rank[x]++;
            }
        }
    }




};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
    //     vector<vector<string>> ans;
        // int n=nums.size();

    //     set<string> s;
    //     unordered_set<int> us;

    //     for(int i=0;i<n;i++){
    //         if(us.find(i)!=us.end())
    //         continue;

    //         auto currstring=nums[i][0];
    //         bool found=false;
    //         vector<string> subans;

    //         for(int j=1;j<nums[i].size();j++){
    //             s.insert(nums[i][j]);
    //         }
    //         for(int k=i+1;k<n;k++){
    //             if(nums[k][0]==currstring){
    //                 for(int p=1;p<nums[k].size();p++){
    //                     if(s.find(nums[k][p])!=s.end()){
    //                         found=true;
    //                         us.insert(k);
    //                         break;
    //                     }
    //                 }
    //                 if(found){
    //                     for(int p=1;p<nums[k].size();p++){
    //                         s.insert(nums[k][p]);
    //                     }
    //                     found=false;
    //                 }
    //             }
    //         }
    //         subans.push_back(currstring);
    //         while(!s.empty()){
    //             auto it=*(s.begin());
    //             subans.push_back(it);
    //             s.erase(it);
    //         }
    //         ans.push_back(subans);
    //     }

    // return ans;


 
    int n=nums.size();
       DisjointSet obj (n);
    unordered_map<string,int> m;

    for(int i=0;i<n;i++){
        for(int j=1;j<nums[i].size();j++){
            auto currmail=nums[i][j];
            if(m.find(currmail)!=m.end()){
                obj.union1(m[currmail],i);
            }
            m[currmail]=i;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<nums[i].size();j++){
              auto currmail=nums[i][j];
              m[currmail]=obj.findPar(m[currmail]);
        }
    }


  
    vector<vector<string>> ans(n);
    vector<vector<string>> ans1;

    for(auto it:m){
        auto curr=it.first;
        auto index=it.second;

        ans[index].push_back(curr);

    }

    for(int i=0;i<n;i++){
          vector<string> subans;
        for(int j=0;j<ans[i].size();j++){
            subans.push_back(ans[i][j]);
        }
        if(subans.size()!=0){
        sort(subans.begin(),subans.end());
        subans.insert(subans.begin(),nums[i][0]);
        ans1.push_back(subans);
        }

    }

return ans1;






















    }
};