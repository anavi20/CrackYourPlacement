// Time Complexity O(n) Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = floor(nums.size()/2);
        for(auto num: nums){
            mp[num]++;
        }

        for(auto [ele,freq] : mp){
            if(freq > n){
                return ele;
            }
        }

        return -1;
    }
};

// Time Complexity O(n) Space Complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, n = nums.size(), count =0;
        for(int i=0; i<n; i++){
            if(count == 0){
                count=1;
                ele = nums[i];
            }else if(nums[i] == ele){
                count++;
            }else{
                count--;
            }
        }

        return ele;

    }
};
