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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        // initialize result to be zero (not bigger than any possible length >=0)
        int result = 0;
        int len = 0;
        maxDepthCore(root, result, len);
        return result;
        
    }
    
    void maxDepthCore(TreeNode *root, int &result, int len) {
        if(NULL == root) {
            return;
        }
        //reach the leaf, still len + 1, then return;
        if(NULL == root->left && NULL == root->right) {
            len = len + 1;
            if(len > result) {
                result = len;
            }
            return;
        }
        //not reach a leaf yet, the current len(from root to current node) is (len + 1)
        maxDepthCore(root->left, result, len + 1);
        maxDepthCore(root->right, result, len + 1);
    }
};