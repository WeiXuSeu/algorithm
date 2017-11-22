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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        TreeNode * root;
        int pStart = 0 ;
        int iStart = 0;
        int pEnd = preorder.size() - 1;
        int iEnd = inorder.size() - 1;
        buildTree(root, preorder, pStart, pEnd, inorder, iStart, iEnd);
        return root;
    }
    
    //assume both the preorder & inorder are right;
    //not check the condition from which the tree not exist
    void buildTree(TreeNode * &root, vector<int> &preorder, int pStart, int pEnd,\
         vector<int> &inorder, int iStart, int iEnd) {
             if(pStart > pEnd) {
                 return;
             }
             root = new TreeNode(preorder[pStart]);
             int index = iStart;
             for(; index <= iEnd; index++) {
                 if(inorder[index] == preorder[pStart]) {
                     break;
                 }
             }
             buildTree(root->left, preorder, pStart+1, pStart+index-iStart,\
                       inorder, iStart, index - 1);
             buildTree(root->right, preorder, pStart+index-iStart+1, pEnd,\
                       inorder, index+1, iEnd);
         }    

};