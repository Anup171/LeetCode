class Solution {
public:
    unordered_set<int> factors(int num){
        unordered_set<int> set;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                set.insert(i);
                while(num%i==0){
                    num/=i;
                }
            }
        }
        if(num>1){
            set.insert(num);
        }
        return set;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prime_count;
        int length=0;
        int left=0;
        for(int right=0;right<n;right++){
            auto current=factors(nums[right]);
            for(int curr:current){
                prime_count[curr]++;
            }
            while(prime_count.size()>k){
                auto remove=factors(nums[left]);
                for(int ele:remove){
                    prime_count[ele]--;
                    if(prime_count[ele]==0){
                        prime_count.erase(ele);
                    }
                }
                left++;
            }
            length=max(right-left+1,length);
        }
        return length;
    }
};