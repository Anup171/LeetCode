class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        unordered_map<int,int> num1_index;
        for(int i=0;i<nums1.size();i++){
            num1_index[nums1[i]]=i;
        }
        stack<int> st;
        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                int val=st.top();
                ans[num1_index[val]]=num;
                st.pop();
            }
            if(num1_index.count(num)){
                st.push(num);
            }
        }
        return ans;
    }
};