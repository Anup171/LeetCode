class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;
    void backtrack(vector<int> &nums,int index){
        res.push_back(current);
        for(int i=index;i<nums.size();i++){
            current.push_back(nums[i]);
            backtrack(nums,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
};