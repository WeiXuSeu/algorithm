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
     * @param a: the root of binary tree a.
     * @param b: the root of binary tree b.
     * @return: true if they are identical, or false.
     */
    bool isIdentical(TreeNode * a, TreeNode * b) {
        // write your code here  
        bool result = true;
        isIdenticalCore(a, b, result);
        return result;
    }
    //forward traversal
    void isIdenticalCore(TreeNode *a, TreeNode *b, bool &result) {
        //if false happen, all subTree return
        if(!result) {
            return;
        }
        //in order to check the value of two tree points, we should first check if the points exist
        //both come to the end
        if(a == NULL && b == NULL) {
            return;
        }
        //only one reach the end: false
        else if(a == NULL || b == NULL) {
            result = false;
            return;
        }
        //both not reach the end, but with different value
        else if (a->val != b->val){
            result = false;
            return;
        }
        
        isIdenticalCore(a->left, b->left, result);
        isIdenticalCore(a->right, b->right, result);        
    }
};