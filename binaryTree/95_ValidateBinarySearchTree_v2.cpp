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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        TreeNode * prev = NULL;
        bool result = true;
        inorderTraversal(root, prev, result);
        return result;
    }
    
    //inorderTraversal & keep previous node in prev
    void inorderTraversal(TreeNode * root, TreeNode * &prev, bool &result) {
        if(root == NULL || result == false) {
            return;
        }
        inorderTraversal(root->left, prev, result);
        if(prev == NULL) {
            prev = root;
        }
        else if(prev->val >= root->val) {
            result = false;
            return;
        }
        else {
            prev = root;
        }
        inorderTraversal(root->right, prev, result);
    } 
};