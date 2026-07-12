class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        vector<int> temp(arr.begin(),arr.end());

        vector<int> ans;
        sort(temp.begin(),temp.end());

        int r=1;

        for(int val:temp){
            if(m.find(val)==m.end()){
                m[val]=r;
                r++;
            }
        }

        for(int val:arr){
            int crank=m[val];
            ans.push_back(crank);
        }


        return ans;


    }
};