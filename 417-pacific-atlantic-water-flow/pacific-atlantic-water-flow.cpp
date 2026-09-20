class Solution {
public:
    int rows,cols;
    void dfs(vector<vector<int>>&heights,vector<vector<bool>>&vis,int row,int col){
        vis[row][col]=true;
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int nr=row+dir[i].first;
            int nc=col+dir[i].second;
            if(nr<0||nr>=rows||nc<0||nc>=cols){
                continue;
            }
            if(vis[nr][nc]){
                continue;
            }
            if(heights[nr][nc]<heights[row][col]){
                continue;
            }
            dfs(heights,vis,nr,nc);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));
        for(int i=0;i<cols;i++){
            if(pacific[0][i]==false){
                dfs(heights,pacific,0,i);
            }
        }
        for(int j=0;j<rows;j++){
            if(pacific[j][0]==false){
                dfs(heights,pacific,j,0);
            }
        }
        for(int i=0;i<cols;i++){
            if(atlantic[rows-1][i]==false){
                dfs(heights,atlantic,rows-1,i);
            }
        }
        for(int j=0;j<rows;j++){
            if(atlantic[j][cols-1]==false){
                dfs(heights,atlantic,j,cols-1);
            }
        }
        vector<vector<int>> ans;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }
};