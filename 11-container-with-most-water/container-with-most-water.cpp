class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=INT_MIN;
        int curr_area=INT_MIN;
        int n=height.size();
        int left=0,right=n-1;
        while(left<right){
            curr_area=min(height[right],height[left])*(right-left);
            max_area=max(curr_area,max_area);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max_area;
    }
};