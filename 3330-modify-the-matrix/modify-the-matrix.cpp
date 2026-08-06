class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> answer(n,vector<int>(m));
        vector<int> max_array(m);
        for(int i=0;i<m;i++){
            int colmax=INT_MIN;
            for(int j=0;j<n;j++){
                colmax=max(colmax,matrix[j][i]);
                answer[j][i]=matrix[j][i];
            }
            max_array[i]=colmax;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(answer[j][i]==-1){
                    answer[j][i]=max_array[i];
                }
            }
        }
        return answer;
    }
};