class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        targetSum -= root->val;

        if(root->left == NULL && root->right==NULL){
            if(targetSum == 0){
                return true;
            }
            return false;
        }

        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);

    }
};
