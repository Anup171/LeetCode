class Solution {
public:
    int largestInteger(int n, int s) {
        int j=pow(10,n)-1;
        for(int i=j;i>=0;i--){
            int sum=0;
            int num=i;
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            if(sum==s){ 
                return i;
            }
        }
        return -1;
    }
};