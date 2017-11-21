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
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        bool flagA = false;
        bool flagB = false;
        vector<TreeNode *> pathA;
        vector<TreeNode *> pathB;
        TreeNode * LCA = NULL;
        findPath(root, A, pathA, flagA);
        findPath(root, B, pathB, flagB);
        LCA = findLCA(pathA, pathB);
        return LCA;
    }
    
    void findPath(TreeNode *root, TreeNode * A, vector<TreeNode *> & path, bool &result) {
        if(result == true || root == NULL) {
            return;
        }
        //(1) push "node -- root" to path first;
        //(2) check whether node is the target, if yes, return; else check 
        //    whether the target exist in its children subtree.
        //(3) if exist in its children subtree, return the path,
        //    else remove the "root -- node"
        path.push_back(root);
        if(root == A) {
            result = true;
            return;
        }
        findPath(root->left, A, path, result);
        findPath(root->right, A, path, result);
        if(result == false) {
            path.pop_back();
        }
    }
    
    TreeNode * findLCA(vector<TreeNode *> pathA, vector<TreeNode *> pathB) {
        int lenA = pathA.size();
        int lenB = pathB.size();
        TreeNode * LCA = NULL;
        int shortLen = lenA < lenB ? lenA : lenB;
        int i = 0;
        for(i = 0; i < shortLen; i++) {
            if(pathA[i] != pathB[i])
                break;
        }
        if(i > 0) {
            LCA = pathA[i-1];
        }
        return LCA;
    }
};