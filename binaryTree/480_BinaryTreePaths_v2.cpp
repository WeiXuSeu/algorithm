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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
     
    /*
    output format:
    [
     "1->2->5",
     "1->3"
    ]
    
    out put the path, combine each item with "->";
    so we should convert each int to string using "to_sing()"
    
    (1) keep each path using vector<int>
    (2) convert items in vector<int> to string with each item combined with "->"
    */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> target;
        vector<vector<int>> result;
        vector<int> path;
        binaryTreePathsCore(root, result, path);
        string formatStr;
        int size = result.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < result[i].size() - 1; j++) {
                formatStr += to_string(result[i][j]);
                formatStr += "->";
            }
            formatStr += to_string(result[i][result[i].size() - 1]);
            target.push_back(formatStr);
            formatStr.clear();
        }
        return target;
    }
    //forward search
    void binaryTreePathsCore(TreeNode *root, vector<vector<int>> &result, vector<int> path) {
        if(root == NULL) {
            return;
        }
        //if root != NULL, keep the item
        path.push_back(root->val);
        //if reach leaf node, get the path
        if(root->left == NULL && root->right == NULL) {
            if(!path.empty()) {
                result.push_back(path);
            }
            return;
        }
        binaryTreePathsCore(root->left, result, path);
        //when return from chiled root->left, pop the item, restore the previous state
        //if(root->left) {
        //    path.pop_back();
        //}
        binaryTreePathsCore(root->right, result, path);
        //when return from chiled root->right, pop the item, restore the previous state
        //if(root->right) {
        //    path.pop_back();
        //}
    }
};