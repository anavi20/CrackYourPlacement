class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxIdxJump = 0;
        for(int i=0; i<n; i++){
            if(maxIdxJump < i){
                return false;
            }
            maxIdxJump = max(maxIdxJump, i+nums[i]);
        }

        return true;
    }
};
