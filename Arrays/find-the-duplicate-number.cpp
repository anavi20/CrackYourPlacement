// With Time-Complexity:- O(nlogn + n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }

        return -1;
    }
};

// With Time-Complexity:- O(n) and Space Complexity:- O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        for(auto num: nums){
            if(mp.find(num) != mp.end()){
                return num;
            }
            mp[num] = true;
        }

        return -1;
    }
};

//With Time-Complexity:- O(n) and Space Complexity:-O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
