class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int maxlen=0;
        unordered_map<int,int> seen;
        for(int right=0;right<fruits.size();right++){
            seen[fruits[right]]++;
            while(seen.size()>2){
                seen[fruits[left]]--;
                if(seen[fruits[left]]==0){
                    seen.erase(fruits[left]);
                }
                left++;
            }
            maxlen=max(right-left+1,maxlen);
        }
        return maxlen;
    }
};