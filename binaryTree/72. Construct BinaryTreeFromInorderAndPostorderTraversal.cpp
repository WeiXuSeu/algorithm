class Solution {
public:
    /*
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        TreeNode * root;
        int iStart = 0;
        int pStart = 0;
        int iEnd = inorder.size() - 1;
        int pEnd = postorder.size() - 1;
        root = buildTreeCore(inorder, iStart, iEnd, postorder, pStart, pEnd);
        return root;
    }
    
    TreeNode * buildTreeCore(vector<int> &inorder, int iStart, int iEnd, \
               vector<int> &postorder, int pStart, int pEnd) {
                   if(iStart > iEnd) {
                       return NULL;
                   }
                   TreeNode * root = new TreeNode(postorder[pEnd]);
                   int index = iStart;
                   for(; index <= iEnd; index++) {
                       if(postorder[pEnd] == inorder[index]) {
                           break;
                       }
                   }
                   root->left = buildTreeCore(inorder, iStart, index-1,\
                                postorder, pStart, pStart + index - iStart - 1);
                   root->right = buildTreeCore(inorder, index+1, iEnd,\
                                 postorder, pStart + index - iStart, pEnd - 1);
                   return root;
               }
};