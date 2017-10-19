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
/*
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. 
That is, if you cut off the tree at node n, the two trees would be identical.

T1 cut off from a node, so it must contain some left;
so all left of T2 must match left of T1
*/
    bool flag;
	//subtree match check
    bool check(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 != NULL)
            return false;
        if (T1 != NULL && T2 == NULL)
            return false;

        if (T1 == NULL && T2 == NULL)
            return true;
        if (T1->val != T2->val)
            return false;
        
        return check(T1->left, T2->left) && check(T1->right, T2->right);
    }

    void dfs(TreeNode *T1, TreeNode *T2) {
        //if (flag) return;
        if (check(T1, T2)) {
            flag = true;
            return;
        }
        if (T1 == NULL)            
            return;
    
        dfs(T1->left, T2);
        dfs(T1->right, T2);
        
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        flag = false;
        dfs(T1, T2);
        return flag;
    }
};