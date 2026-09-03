class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid){
        int rows=grid.size();
        int cols=grid[0].size();
        if(row<0 || row>=rows || col<0 || col>=cols || grid[row][col]!='1'){
            return;
        }
        grid[row][col]='2';
        vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
        for(auto [dr,dc]:dir){
            dfs(dr+row,dc+col,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};