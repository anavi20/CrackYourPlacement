class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode *leftTree = lowestCommonAncestor(root->left,p,q);
        TreeNode *rightTree = lowestCommonAncestor(root->right,p,q);

        if(leftTree && rightTree){
            return root;
        }

        return (leftTree != NULL) ? leftTree : rightTree;
    }
};
