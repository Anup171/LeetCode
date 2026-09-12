class Solution {
public:
    int next_number(int num){
        int sum=0;
        while(num>0){
            int last=num%10;
            num/=10;
            sum+=last*last;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(!set.count(n) && n!=1){
            set.insert(n);
            n=next_number(n);
        }
        if(n==1) return true;
        else return false;
    }
};