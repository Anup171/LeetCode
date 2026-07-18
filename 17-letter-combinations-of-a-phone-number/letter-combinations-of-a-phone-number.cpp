class Solution {
public:
    vector<string> ans;
    unordered_map<char,vector<char>> mp;
    void solve(int index,string current,string digits){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        vector<char> letters=mp[digits[index]];
        for(char character:letters){
            current.push_back(character);
            solve(index+1,current,digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        mp={{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},
        {'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
        solve(0,"",digits);
        return ans;
    }
};