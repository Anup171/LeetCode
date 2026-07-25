class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;

    for (char task : tasks) {
        freq[task]++;
    }
    priority_queue<int> maxHeap;

    for (auto &p : freq) {
        maxHeap.push(p.second);
    }
    int time=0;
    while (!maxHeap.empty()) {

        vector<int> temp;
        int cycle = n + 1;
        while (cycle > 0 && !maxHeap.empty()) {

            int cnt = maxHeap.top();
            maxHeap.pop();

            cnt--;

            if (cnt > 0)
                temp.push_back(cnt);

            time++;
            cycle--;
        }
        for (int cnt : temp)
            maxHeap.push(cnt);

        if (maxHeap.empty())
            break;

        time += cycle;
    }
    return time;
    }
};