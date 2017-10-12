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
     * @param root: the root of binary tree
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        int sum = 0;
        convertBSTCore(root, sum);
        return root;
    } 
    
    void convertBSTCore(TreeNode * root, int &sum) {
        // write your code here
        /* middle search,
        use sum to keep the state
        */
        if(root == NULL) {
            return;
        }
        convertBSTCore(root->right, sum);
        sum = sum + root->val;
        root->val = sum;
        convertBSTCore(root->left, sum); 

    }
};