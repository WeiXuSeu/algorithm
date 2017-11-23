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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> result;
        searchRangeCore(root, k1, k2, result);
        return result;
    }
    
    void searchRangeCore(TreeNode * root, int k1, int k2, vector<int> & result) {
        if(root == NULL) {
            return;
        }
        searchRangeCore(root->left, k1, k2, result);
        if(root->val >= k1 && root->val <= k2) {
            result.push_back(root->val);
        }
        searchRangeCore(root->right, k1, k2, result);
    }
};