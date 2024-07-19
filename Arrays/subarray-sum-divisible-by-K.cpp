// Time Complexity O(n) Space Complexity O(k)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> prefSum;
        prefSum[0]++;
        for(int i=0; i<n; i++){
            sum = (sum + nums[i]%k + k)%k;
            ans += prefSum[sum];
            prefSum[sum]++;
        }

        return ans;
    }
};
