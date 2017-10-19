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
        result = subResult;
        isSubtreeCore(T1->left, T2, result);
        isSubtreeCore(T1->right, T2, result);
    }
    
	/*
	judge whether T1 contains T2; --- T2 in T1
	so do not need T2 match T1's leave;
	*/
    void isIdentical(TreeNode *T1, TreeNode *T2, bool &result) {
		//end point1, T2 reach the end, keep the defaule result value(true);
		//end point2, result is false --- once false, all false;
        if(T2 == NULL || result == false) {
            return;
        }
		//a false point, T1: null, T2: not null
        else if(T1 == NULL) {
            result = false;
            return;
        }
		//a false point, both have value, but not equal
        else if(T1->val != T2->val) {
            result = false;
            return;
        }
        
        isIdentical(T1->left, T2->left, result);
        isIdentical(T1->right, T2->right, result);
    }
};