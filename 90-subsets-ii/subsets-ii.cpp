class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;
    void backtrack(vector<int>&nums,int index){
        res.push_back(current);
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i-1]==nums[i]) continue;
            current.push_back(nums[i]);
            backtrack(nums,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
};