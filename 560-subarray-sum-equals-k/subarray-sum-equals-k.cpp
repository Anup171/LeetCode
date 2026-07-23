class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long prefixsum=0;
        int count=0;
        unordered_map<long long,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(mp.count(prefixsum-k)){
                count+=mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};