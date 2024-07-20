class Solution {
public:
    int solve(TreeNode* root, int& diameter){
        if(root==NULL){
            return 0;
        }
        if(root->left == NULL && root->right==NULL){
            return 1;
        }
        int leftDepth = solve(root->left, diameter);
        int rightDepth = solve(root->right, diameter);
        diameter = max(diameter, leftDepth+rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};
