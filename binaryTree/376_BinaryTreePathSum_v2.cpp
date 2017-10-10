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
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> path;
        int sum = 0;
        binaryTreePathSumCore(root, target, result, path, sum);
        return result;
    }
    
    void binaryTreePathSumCore(TreeNode *root, int target,\
         vector<vector<int>> &result, vector<int> path, int sum) {
             //for single child or empty tree
             //path, sum pass by value, when return from its child, restore its state automatically.
             if(root == NULL)
                return;
             sum = sum + root->val;
             path.push_back(root->val);
             if(root->left == NULL && root->right == NULL) {
                 if(sum == target) {
                     result.push_back(path);
                 }
                 return;
             }
             binaryTreePathSumCore(root->left, target, result, path, sum);
             //if left child exist
             //if(root->left) {
             //    sum = sum - root->left->val;
             //    path.pop_back();
             //}
             binaryTreePathSumCore(root->right, target, result, path, sum);
             //if right child exist
             //if(root->right) {
             //    sum = sum - root->right->val;
             //    path.pop_back();
             //}
         }
};