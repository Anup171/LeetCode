class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool dfs(vector<vector<char>>& board,string word,int index,int row,int col){
        int rows=board.size();
        int cols=board[0].size();
        if(row<0||row>=rows||col<0||col>=cols){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        if(index==word.size()-1){
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        for(auto d:dir){
            int nrow=d.first+row;
            int ncol=d.second+col;
            if(dfs(board,word,index+1,nrow,ncol)){
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};