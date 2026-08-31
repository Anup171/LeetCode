class Solution {
public:
    vector<int> dirr={-1,1,0,0};
    vector<int> dirc={0,0,-1,1};
    void dfs(vector<vector<int>> &image,int row,int col,int color,int oldcolor){
        image[row][col]=color;
        for(int i=0;i<4;i++){
            int nr=dirr[i]+row;
            int nc=dirc[i]+col;
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && image[nr][nc]==oldcolor){
                image[nr][nc]=color;
                dfs(image,nr,nc,color,oldcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor==color){
            return image;
        }
        dfs(image,sr,sc,color,oldcolor);
        return image;
    }
};