class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int right=height[j];
        int left=height[0];
        int sum=0;
        while(i<j){
             if (left <= right) {
                sum += (left - height[i]);
                i++;
                left = max(left, height[i]);
            } else {
                sum += (right - height[j]);
                j--;
                right = max(right, height[j]);
            }
        }
        
        
        return t;
    }
};
