class Solution {
public:
    bool checkGoodInteger(int n) {
        string nums=to_string(n);
        int digitsum=0,squaresum=0;
        for(char num:nums){
            int i=num-'0';
            digitsum+=i;
            squaresum+=i*i;
        }
        return squaresum-digitsum>=50;
    }
};