class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), ptr = 0, i=1;
        while(i<n){
            if(nums[ptr] != nums[i]){
                ptr++;
                swap(nums[ptr],nums[i]);
            }
            i++;
        }

        return ptr+1;
    }
};
