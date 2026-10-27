class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>heap;
        for(auto &ele:mp){
            heap.push({ele.second,ele.first});
        }
        vector<int> ans;
        int count=k;
        while(count>0){
            ans.push_back(heap.top().second);
            heap.pop();
            count--;
        }
        return ans;
    }
};