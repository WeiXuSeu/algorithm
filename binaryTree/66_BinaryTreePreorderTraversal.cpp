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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        preorderTraversalCore(root, result);
        return result;
    }
    
    void preorderTraversalCore(TreeNode * root, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        
        result.push_back(root->val);
        preorderTraversalCore(root->left, result);
        preorderTraversalCore(root->right,result);
    }
};