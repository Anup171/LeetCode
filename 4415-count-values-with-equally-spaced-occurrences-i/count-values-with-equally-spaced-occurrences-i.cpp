class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto ele:mp){
            vector<int> arr=ele.second;
            bool flag=true;
            if(arr.size()==3){
                int a=arr[0];
                int d=arr[1]-arr[0];
                for(int i=0;i<arr.size();i++){
                    if(arr[i]!=a+d*i){
                        flag=false;
                    }
                }
                if(flag){
                    sum+=1;
                }
            }
        }
        return sum;
    }
};