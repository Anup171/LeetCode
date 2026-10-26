class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int target=sum/2;
        unordered_set<int>dp={0};
        for(int i=nums.size()-1;i>=0;i--){
            unordered_set<int> nextdp;
            for(int ele:dp){
                if(ele+nums[i]==target||ele==target){
                    return true;
                }
                nextdp.insert(ele+nums[i]);
                nextdp.insert(ele);
            }
            dp=nextdp;
        }
        return false;
    }
};