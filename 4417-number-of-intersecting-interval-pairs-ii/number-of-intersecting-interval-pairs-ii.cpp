class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> heap;
        sort(intervals.begin(),intervals.end());
        for(auto &interval:intervals){
            int m=interval[1];
            int n=interval[0];
            while(!heap.empty()&&heap.top()<n){
                heap.pop();
            }
            ans+=heap.size();
            heap.push(m);
        }
        return ans;
    }
};