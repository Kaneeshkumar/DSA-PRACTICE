class Solution {
public:
    int totalNumbers(vector<int>& nums) {

        vector<int> freq(10, 0);

        for (int x : nums) {
            freq[x]++;
        }

        int cnt = 0;

        // Choose the last digit.
        // It must be even.
        for (int last = 0; last <= 8; last += 2) {

            if (freq[last] == 0)
                continue;

            freq[last]--;

            // Choose the first digit.
            // It cannot be 0.
            for (int first = 1; first <= 9; first++) {

                if (freq[first] == 0)
                    continue;

                freq[first]--;

                // Choose the second digit.
                for (int second = 0; second <= 9; second++) {

                    if (freq[second] > 0) {
                        cnt++;
                    }
                }

                freq[first]++;
            }

            freq[last]++;
        }

        return cnt;
    }
};