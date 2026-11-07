class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n=colors.size();
        vector<vector<int>> stack;
        for(int i=0;i<n;i++){
            int color=colors[i];
            int type=types[i];
            if(!stack.empty()&&stack.back()[0]==color&&stack.back()[1]==type){
                stack.back()[2]++;
            }
            else{
                stack.push_back({color,type,1});
            }
            if(groupSize[type]==stack.back()[2]){
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};