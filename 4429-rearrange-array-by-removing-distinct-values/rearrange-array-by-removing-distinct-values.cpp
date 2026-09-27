class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > heap;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto ele : mp) {
            heap.push({ele.first, ele.second});
        }

        while (!heap.empty()) {
            int n = heap.size();
            vector<pair<int, int>> temp;

            while (n--) {
                auto ele = heap.top();
                heap.pop();

                res.push_back(ele.first);

                ele.second--;

                if (ele.second > 0) {
                    temp.push_back(ele);
                }
            }

            for (auto ele : temp) {
                heap.push(ele);
            }
        }

        return res;
    }
};