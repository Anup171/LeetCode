class Solution {
public:
    int n;

    bool ispalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void backtracking(int index, string &s,
                      vector<string> &curr,
                      vector<vector<string>> &ans) {

        if (index == n) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < n; i++) {

            if (ispalindrome(s, index, i)) {

                curr.push_back(s.substr(index, i - index + 1));

                backtracking(i + 1, s, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        n = s.size();

        vector<string> curr;
        vector<vector<string>> ans;

        backtracking(0, s, curr, ans);

        return ans;
    }
};