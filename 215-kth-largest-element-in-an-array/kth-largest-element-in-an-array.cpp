class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
        }
        for(int i=1;i<k;i++){
            heap.pop();
        }
        return heap.top();
    }
};