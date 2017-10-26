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
     * @param A: an integer array
     * @return: A tree node
     */
    TreeNode * sortedArrayToBST(vector<int> &A) {
        // write your code here
        TreeNode *root = NULL;
        int begin = 0;
        int end = A.size() - 1;
        sortedArrayToBSTCore(root, A, begin, end);
        return root;
    }
    
    void sortedArrayToBSTCore(TreeNode * &root, vector<int> &A, int begin, int end) {
        //check the array need to be converted to BST;
        //when this array contain noting, return;
        if(begin > end) {
            return;
        }
        //get the mid (tend to left) point --> root
        int mid = (begin+end)/2;
        root = new TreeNode(A[mid]);
        //recursively convert the left sub array (left sub tree)
        sortedArrayToBSTCore(root->left, A, begin, mid-1);
        //recursively convert the right sub array (right sub tree)
        sortedArrayToBSTCore(root->right, A, mid+1, end);
    }
};