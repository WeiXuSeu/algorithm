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
     * @return: 
     */
    void flatten(TreeNode * root) {
        // write your code here
        // keep the state of right child
        stack<TreeNode *> reserve;
        // loop while root != NULL || !reserve.empty()
        while(root != NULL || !reserve.empty()) {
            // if right child exist, keep its state
            if(root->right) {
                reserve.push(root->right);
            }
            // no state of right child, also no value of left child, return
            if(root->left == NULL && reserve.empty()) {
                return;
            }
            // if no value of left child, but have the state of right child, 
            // just concatenate the neaest right child state
            else if(root->left == NULL) {
                root->right = reserve.top();
                reserve.pop();
            }
            // if have value of left child, just concatenate the left child
            // fllow the forward traversal;
            else if(root->left != NULL) {
                root->right = root->left;
                root->left = NULL;
            }
            // forward to the next node following the forward tarversal
            root = root->right;
        }
    }
    
};