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
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        // write your code here
        // maximum positive int
        // right forward move will take its symbol bit(+/-)
        int result = (unsigned(-1))>>1;
        int len = 0;
        if (NULL == root) {
            result = 0;
        }
        else {
            //cannot meet the condition when the tree is empty
            minDepthCore(root, result, len);
        }
        return result;
    }
    
    /*
    root: the root node of the tree;
    result: store the result -- minimum depth;
    len: the initial depth of the subtree root node; (initializtion: 0)
    */
    void minDepthCore(TreeNode *root, int &result, int len) {
        // if tree is empty, return, 
        if(NULL == root) {
            return;
        }
        //if meet the leaf node, len + 1, and compare with previous result;
        if(root->left == NULL && root-> right == NULL) {
            len = len + 1;
            if(len < result) {
                result = len;
            }
            return;
        }
        //travel to the left subtree, depth + 1    
        minDepthCore(root->left, result, len + 1);
        //travel to the right subtree, depth + 1
        minDepthCore(root->right, result, len + 1);
    }
 };