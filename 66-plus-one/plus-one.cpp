class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int num=digits[i]+carry;
            carry=num/10;
            digits[i]=num%10;
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};