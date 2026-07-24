class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longest=0;
        for(int num:nums){
            set.insert(num);
        }
        for(int ele:set){
            if(!set.count(ele-1)){
                int current=ele;
                int count=1;
                while(set.count(current+1)){
                    current++;
                    count++;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};