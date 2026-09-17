class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){

        int crow=row;
        int ccol=col;


        for(int c=col;c>=0;c--){
            if(board[row][c]=='Q')
            return false;
        }


        //upper diagnol

        while(crow>=0 && ccol>=0){
            if(board[crow][ccol]=='Q')
            return false;

            crow--;
            ccol--;
        }

        //lower diagnol
        crow=row;
        ccol=col;

        while(crow<n && ccol>=0){
            if(board[crow][ccol]=='Q')
            return false;

            crow++;
            ccol--;
        }

        return true;
    }
    void f(int col,int n,vector<string>& board,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int r=0;r<n;r++){
            if(isSafe(r,col,board,n)){
                board[r][col]='Q';
                f(col+1,n,board,ans);
                board[r][col]='.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s;
        for(int i=0;i<n;i++)
        s.push_back('.');


        for(int i=0;i<n;i++){
            board[i]=s;
        }

        f(0,n,board,ans);

        return ans;

    }
};