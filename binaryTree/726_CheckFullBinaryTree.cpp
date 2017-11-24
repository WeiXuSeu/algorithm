class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        // write your code here
        if(root == NULL) {
            return true;
        }
        if((root->left == NULL && root->right != NULL) || \
        root->left != NULL && root->right == NULL) {
            return false;
        }
        return isFullTree(root->left) && isFullTree(root->right);
    }
};