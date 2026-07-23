class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> freq;
        int left=0;
        int result=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            freq[ch]++;
            int maxValue = INT_MIN;
            for (auto &p : freq) {
                maxValue = max(maxValue, p.second);
            }
            if((right-left+1-maxValue)<=k){
                result=max(result,right-left+1);
            }
            else{
                freq[s[left]]--;
                left++;
            }
        }
        return result;
    }
};