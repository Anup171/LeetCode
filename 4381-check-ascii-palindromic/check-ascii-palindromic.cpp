class Solution {
public:
    bool ispalindrome(string nums){
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            if(nums[left]!=nums[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string nums="";
        for(char ch:s){
            nums+=bitset<8>(ch).to_string();
        }
        return ispalindrome(nums);
    }
};