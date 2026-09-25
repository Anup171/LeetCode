class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;
    void backtrack(vector<int>&candidates,int index,int target){
        if(target==0){
            res.push_back(current);
        }
        if(target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backtrack(candidates,i,target-candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,0,target);
        return res;
    }
};