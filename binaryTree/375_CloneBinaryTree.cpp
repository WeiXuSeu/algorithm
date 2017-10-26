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
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
        // write your code here
        TreeNode *cloneRoot = NULL;
        cloneTreeCore(cloneRoot, root);
        //value copy & return -- (cloneRoot)
        return cloneRoot;
    }

    void cloneTreeCore(TreeNode * &cloneRoot, TreeNode *root) {
        if(root == NULL) {
            return;
        }
        //forward traversal & copy.
        cloneRoot = new TreeNode(root->val);
        cloneTreeCore(cloneRoot->left, root->left);
        cloneTreeCore(cloneRoot->right, root->right);
    }
};