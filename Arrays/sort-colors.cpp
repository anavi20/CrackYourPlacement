// Time Complexity O(n) Space Complexity : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), ptr0 = 0, ptr1 = 0, ptr2 = n-1;

        while (ptr1 <= ptr2){
            if(nums[ptr1] == 0){
                swap(nums[ptr0++],nums[ptr1++]);
            }else if(nums[ptr1] == 1){
                ptr1++;
            }
            else{
                swap(nums[ptr1], nums[ptr2--]);
            }
        }
    }
};
