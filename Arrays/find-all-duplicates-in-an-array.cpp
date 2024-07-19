// Time Complexity O(n) and Space Complexity O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(n+1,0);
        for(auto ele: nums){
            freq[ele]++;
            if(freq[ele] == 2){
                ans.push_back(ele);
            }
        }

        return ans;
    }
};

// Time Complexity O(n) and Space Complexity O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto ele : nums){
            if(nums[abs(ele) - 1] < 0){
                ans.push_back(abs(ele));
            }
            nums[abs(ele) - 1] = nums[abs(ele) - 1]*-1;
        }

        return ans;
    }
};
