/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode * root) {
        // write your code here
        if(root == NULL) {
            return;
        }
        TreeNode * tmp;
        if(root->left == NULL && root->right == NULL) {
            return;
        }
        else{
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};