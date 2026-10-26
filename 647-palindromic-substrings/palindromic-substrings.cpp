class Solution {
public:
    int count=0;
    void solve(string s,int left,int right){
        while(left>=0&&right<=s.size()&&s[left]==s[right]){
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            solve(s,i,i);
            solve(s,i,i+1);
        }
        return count;
    }
};