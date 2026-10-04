class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cols=board[0].size();
        int rows=board.size();
        unordered_map<int,unordered_set<char>>row_map;
        unordered_map<int,unordered_set<char>>col_map;
        unordered_map<string,unordered_set<char>>box_map;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == '.')
                    continue;
                if(row_map[i].count(board[i][j])){
                    return false;
                }
                row_map[i].insert(board[i][j]);
                if(col_map[j].count(board[i][j])){
                    return false;
                }
                col_map[j].insert(board[i][j]);
                if(box_map[to_string(i / 3) + "," + to_string(j / 3)].count(board[i][j])){
                    return false;
                }
                box_map[to_string(i / 3) + "," + to_string(j / 3)].insert(board[i][j]);
            }
        }
        return true;
    }
};