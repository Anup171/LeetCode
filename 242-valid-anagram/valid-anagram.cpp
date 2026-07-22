class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
            if(!mp.count(ch)){
                return false;
            }
            mp[ch]--;
        }
        for(auto ele:mp){
            if(ele.second!=0) return false;
        }
        return true;
    }
};