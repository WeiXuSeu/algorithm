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
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        vector<int> vec;
        vector<vector<TreeNode *>> container(2);
        int index = 0;
        if(root != NULL) {
            container[index & 1].push_back(root);
        }
        while((container[0].empty() != true) || (container[1].empty() != true)) {
            for(vector<TreeNode *>::iterator iter = container[index & 1].begin();\
            iter != container[index & 1].end(); iter++) {
                if((*iter)->left != NULL) {
                    container[(index+1) & 1].push_back((*iter)->left);
                }
                if((*iter)->right != NULL) {
                    container[(index+1) & 1].push_back((*iter)->right);
                }
                vec.push_back((*iter)->val);
            }
            //insert positon is "iterator"
            result.insert(result.begin(), vec);
            vec.clear();
            container[index & 1].clear();
            index++;
        }
        return result;
        
    }
};