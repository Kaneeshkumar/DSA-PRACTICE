#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        // Step 1: BFS to build adjacency (only shortest paths)
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (auto& w : currentLevel) dict.erase(w); // avoid revisiting
            unordered_set<string> nextLevel;

            for (auto& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char orig = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = orig;
                }
            }
            currentLevel = move(nextLevel);
        }

        // Step 2: Backtracking to build all paths
        vector<vector<string>> res;
        vector<string> path{endWord};
        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                return;
            }
            for (auto& p : parents[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        if (found) dfs(endWord);
        return res;
    }
};
