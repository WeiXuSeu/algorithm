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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        postorderTraversalCore(root, result);
        return result;
    }
    
    void postorderTraversalCore(TreeNode * root, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        postorderTraversalCore(root->left, result);
        postorderTraversalCore(root->right, result);
        result.push_back(root->val);
    }
};