class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Coaching Analysis:
        // Your logic is correct for finding missing elements between the
        // minimum and maximum values. Time Complexity: O(N) where N is the
        // number of elements in nums. Space Complexity: O(N) to store the
        // elements in the unordered_set. This is the optimal time complexity
        // for this problem.

        int n = nums.size();
        unordered_set<int> s;
        vector<int> ans;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int val : nums) {
            mini = min(mini, val);
            maxi = max(maxi, val);
            s.insert(val);
        }

        for (int i = mini + 1; i < maxi; i++) {
            if (s.find(i) == s.end())
                ans.push_back(i);
        }

        return ans;
    }
};