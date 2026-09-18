class Solution {
public:

    void solve(int row, int col,
               vector<vector<int>>& grid,
               vector<vector<int>>& vis,
               string path,
               vector<string>& ans) {

        int n = grid.size();

        // Reached destination
        if(row == n-1 && col == n-1) {
            ans.push_back(path);
            return;
        }

        // Down
        if(row+1 < n && grid[row+1][col] == 1 && !vis[row+1][col]) {
            vis[row][col] = 1;
            solve(row+1, col, grid, vis, path + 'D', ans);
            vis[row][col] = 0;
        }

        // Left
        if(col-1 >= 0 && grid[row][col-1] == 1 && !vis[row][col-1]) {
            vis[row][col] = 1;
            solve(row, col-1, grid, vis, path + 'L', ans);
            vis[row][col] = 0;
        }

        // Right
        if(col+1 < n && grid[row][col+1] == 1 && !vis[row][col+1]) {
            vis[row][col] = 1;
            solve(row, col+1, grid, vis, path + 'R', ans);
            vis[row][col] = 0;
        }

        // Up
        if(row-1 >= 0 && grid[row-1][col] == 1 && !vis[row-1][col]) {
            vis[row][col] = 1;
            solve(row-1, col, grid, vis, path + 'U', ans);
            vis[row][col] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<string> ans;

        if(grid[0][0] == 0 || grid[n-1][n-1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, grid, vis, "", ans);

        return ans;
    }
};