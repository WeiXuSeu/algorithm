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
        vector<int> vec;
        //if(root == NULL)
        //    return true;
        inorderTraversal(root, vec);
        bool result = true;
        if(vec.empty()) {
            return true;
        }
        for(int i = 0; i < vec.size() - 1; i++) {
            if(vec[i] >= vec[i+1]) {
                result = false;
                break;
            }
        }
        return result;
    }
    
    void inorderTraversal(TreeNode * root, vector<int> &vec) {
        if(root == NULL) {
            return;
        }
        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right, vec);
    } 
};