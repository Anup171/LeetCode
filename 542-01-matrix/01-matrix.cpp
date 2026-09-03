class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(auto [dr,dc]:directions){
                int newrow=dr+row;
                int newcol=dc+col;
                if (newrow >= 0 && newrow < rows &&
    newcol >= 0 && newcol < cols &&
    dist[newrow][newcol] == -1){
                    dist[newrow][newcol] = dist[row][col] + 1;
                    q.push({newrow, newcol});
                }
            }
        }
        return dist;
    }
};