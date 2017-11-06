class Solution {
public:
    /*
     * @param : the given tree
     * @return: the tree after swapping
     */
    //swap can hapen betweent any two nodes
    TreeNode * bstSwappedNode(TreeNode * root) {
        // write your code here
        TreeNode * first = NULL;
        TreeNode * middle = NULL;
        TreeNode * last = NULL;
        TreeNode * previous = NULL;
        bstSwappedNodeCore(root, first, middle, last, previous);
        if(last) {
            swap(first, last);
        }
        else if(first) {
            swap(first, middle);
        }
        return root;
    }
    
    void bstSwappedNodeCore(TreeNode * root, TreeNode * &first, TreeNode * &middle, \
         TreeNode * &last, TreeNode * &previous) {
        if(root == NULL) {
            return;
        }
        bstSwappedNodeCore(root->left, first, middle, last, previous);
        if(previous && previous->val > root->val) {
            if(first == NULL) {
                first = previous;
                middle = root;
            }
            else {
                last = root;
            }
        }
        //middle traversal, previous keep the node of middle traversal order [samll, ]
        previous = root;
        bstSwappedNodeCore(root->right, first, middle, last, previous);
    }
    
    void swap(TreeNode * &ptr1, TreeNode * &ptr2) {
        int tmp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = tmp;
    }

};