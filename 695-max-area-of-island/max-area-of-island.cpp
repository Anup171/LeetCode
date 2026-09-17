class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int &count){
        int rows=grid.size();
        int cols=grid[0].size();
        if(row<0||row>=rows||col<0||col>=cols||grid[row][col]!=1){
            return;
        }
        grid[row][col]=2;
        count++;
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto ele:dir){
            int drow=ele.first;
            int dcol=ele.second;
            int frow=drow+row;
            int fcol=dcol+col;
            dfs(grid,frow,fcol,count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(grid,i,j,count);
                    max_count=max(count,max_count);
                }
            }
        }
        return max_count;
    }
};