class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j = height.size() - 1, maxArea = 0;

        while(i < j){
            int h = min(height[i], height[j]);
            maxArea = max(maxArea, (h*(j-i)));
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }

        return maxArea;
    }
};
