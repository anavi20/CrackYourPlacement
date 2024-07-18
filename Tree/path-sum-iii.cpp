class Solution {
public:
    int solveHelper(TreeNode* node, long long targetSum){
        if(node==NULL){
            return 0;
        }
        int count = 0;
        if(targetSum == node->val){
            count += 1;
        }
        targetSum -= node->val;
        count += solveHelper(node->left,targetSum);
        count += solveHelper(node->right,targetSum);

        return count;
    }
    int solve(TreeNode* node,int targetSum) {
        if (node == NULL) {
            return 0;
        }

        return solve(node->left,targetSum) + solve(node->right,targetSum) + solveHelper(node,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};



class Solution {
public:
    int solve(TreeNode* node, long runningSum, long targetSum, unordered_map<long,int>& mp){
        if(node == NULL){
            return 0;
        }
        runningSum += node->val;
        int count = mp[runningSum - targetSum];
        mp[runningSum]++;
        count += solve(node->left,runningSum,targetSum,mp);
        count += solve(node->right,runningSum,targetSum,mp);
        mp[runningSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> mp;
        mp[0] = 1;
        return solve(root,0, targetSum, mp);
    }
};
