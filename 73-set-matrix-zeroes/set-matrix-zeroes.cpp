class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        unordered_set<int> row_zero;
        unordered_set<int> col_zero;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    row_zero.insert(i);
                    col_zero.insert(j);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(row_zero.count(i)||col_zero.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};