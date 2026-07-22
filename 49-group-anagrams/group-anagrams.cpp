class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(string str:strs){
            string key=str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for(auto &ele:mp){
            result.push_back(ele.second);
        }
        return result;
    }
};