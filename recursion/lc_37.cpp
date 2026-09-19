class Solution {
public:
    bool isValid(int i,int j,int k,vector<vector<char>>& board){
        
        int srow=i/3;
        srow=srow*3;
        int scol=j/3;
        scol=scol*3;
        
        for(int p=0;p<9;p++){
            if(board[p][j]==k+'0')
            return false;

            if(board[i][p]==k+'0')
            return false;

            int crow=srow+p/3;
            int ccol=scol+p%3;

            if(board[crow][ccol]==k+'0')
            return false;

        }

        return true;
    }
    bool f(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    for(int k=1;k<=9;k++){
                    if(isValid(i,j,k,board)){   
                        board[i][j]=k+'0';
                        if(f(board)==true)
                        return true;
                        else
                        board[i][j]='.';
                    }
                    }
                    return false;  
                    
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);

        return;
    }
};