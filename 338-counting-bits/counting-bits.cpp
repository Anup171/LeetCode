class Solution {
public:
    int count(int num){
        int count=0;
        while(num){
            count+=num&1;
            num=num>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=count(i);
        }
        return ans;
    }
};