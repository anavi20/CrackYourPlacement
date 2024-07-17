// Time Complexity O(n) , Space Complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n = nums.size();
      int i=0, positionPtr = 0;
      while(i<n){
        if(nums[i] != 0){
            nums[positionPtr] = nums[i];
            positionPtr++;
        }
        i++;
      }

      for(int j=positionPtr; j<n; j++){
        nums[j] = 0;
      }
      
    }
};
