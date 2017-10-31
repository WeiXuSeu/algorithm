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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        inorderTravelsalCore(root, result);
        return result;
    }
    
    void inorderTravelsalCore(TreeNode * root, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        
        inorderTravelsalCore(root->left, result);
        result.push_back(root->val);
        inorderTravelsalCore(root->right, result);
    }
};	