class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cumsum=0;
        int maxlen=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cumsum--;
            }
            else{
                cumsum++;
            }
            if(mp.count(cumsum)){
                maxlen=max(maxlen,i-mp[cumsum]);
            }
            else{
                mp[cumsum]=i;
            }
        }
        return maxlen;
    }
};