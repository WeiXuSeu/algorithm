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
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        bool result = false;
        if (T2 == NULL) {
            result = true;
        }
        isSubtreeCore(T1, T2, result);
        return result;
    }
    
    void isSubtreeCore(TreeNode *T1, TreeNode *T2, bool &result) {
        if(result) {
            return;
        }
        
        
        if(T1 == NULL) {
            return;
        }
        bool subResult = true;
        isIdentical(T1, T2, subResult);
        //if subResult become true, global result become true, all recursion
        //will return when entering
        result = subResult;
        isSubtreeCore(T1->left, T2, result);
        isSubtreeCore(T1->right, T2, result);
    }
    
    /*
	point: subtree match, must reach leaf
    assume the result is true;
    any false condition is an end point;
    another end condition is reaching the leaf (near NULL)
    */
    void isIdentical(TreeNode *T1, TreeNode *T2, bool &result) {
        //end point: false result
        if(result == false) {
            return;
        }
        //end point: normal end (both reach end, keep the default result-true)
        else if(T1 == NULL && T2 ==NULL) {
            return;
        }
        //end point: only one reach end, change result to false 
        else if(T1 == NULL || T2 == NULL) {
            result = false;
            return;
        }
        //one condition to change result to false
        //both have value, but not equal
        else if(T1->val != T2->val) {
            result = false;
            return;
        }
        
        isIdentical(T1->left, T2->left, result);
        isIdentical(T1->right, T2->right, result);
    }
};