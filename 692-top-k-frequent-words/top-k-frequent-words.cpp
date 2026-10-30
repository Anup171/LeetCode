class Solution {
public:
    struct compare{
        bool operator()(pair<string,int>a,pair<string,int>b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string,int> mp;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> heap;
        for(string word:words){
            mp[word]++;
        }
        for(auto ele:mp){
            heap.push({ele.first,ele.second});
        }
        for(int i=0;i<k;i++){
            result.push_back(heap.top().first);
            heap.pop();
        }
        return result;
    }
};