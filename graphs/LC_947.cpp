class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;
        for (auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for (auto &it : stones) {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;

            ds.unionBySize(rowNode, colNode);

            nodes.insert(rowNode);
            nodes.insert(colNode);
        }

        int components = 0;

        for (auto node : nodes) {
            if (ds.findPar(node) == node) {
                components++;
            }
        }

        return n - components;
    }
};