class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int m=k+1;m<n;m++){
                        long long sum = nums[i]+nums[j];
                        sum += nums[k];
                        sum += nums[m];
                        if(sum == target){
                            vector<int> t = {nums[i],nums[j],nums[k],nums[m]};
                            sort(t.begin(),t.end());
                            st.insert(t);
                        }
                    }
                }
            }
        }
        for(auto it= st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                set<long long> hashSet;
                for(int k=j+1;k<n;k++){
                    long long sum = (nums[i] + nums[j]);
                    sum += nums[k];
                    long long lastEle = target - sum;
                    if(hashSet.find(lastEle) != hashSet.end()){
                        vector<int> t = {nums[i], nums[j], nums[k], (int)lastEle};
                        sort(t.begin(),t.end());
                        st.insert(t);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        for(auto it= st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){continue;}
            for(int j=i+1; j<n; j++){
                if(j>(i+1) && nums[j] == nums[j-1]){continue;}
                int k = j + 1;
                int m = n - 1;
                while(k<m){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[m];
                    if(sum == target){
                        vector<int> t = {nums[i],nums[j],nums[k],nums[m]};
                        ans.push_back(t);
                        k++;
                        m--;
                        while(k<m && nums[k] == nums[k-1]){k++;}
                        while(k<m && nums[m] == nums[m+1]){m--;}
                    }else if(sum<target){
                        k++;
                    }else{
                        m--;
                    }
                }
            }
        }
        return ans;
    }
};
