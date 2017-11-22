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
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        vector<deque<TreeNode *>> container(2);
        if(root != NULL ) {
            container[0].push_back(root);
        }
        int index = 0;
        vector<int> vec;
        while(true != container[0].empty() || true != container[1].empty()) {
            for(deque<TreeNode *>::iterator i = container[index & 1].begin();\
                i != container[index & 1].end(); i++) {
                    if((*i)->left != NULL) {
                        container[(index + 1) & 1].push_back((*i)->left);
                    }
                    if((*i)->right != NULL) {
                        container[(index + 1) & 1].push_back((*i)->right);
                    }
                }
                if(!(index & 1)) {
                    for(deque<TreeNode *>::iterator i = container[index&1].begin();\
                        i != container[index & 1].end(); i++) {
                            vec.push_back((*i)->val);
                        }
                }
                else {
                    for(deque<TreeNode *>::reverse_iterator i = container[index&1].rbegin();\
                        i != container[index & 1].rend(); i++) {
                            vec.push_back((*i)->val);
                        }
                }
                result.push_back(vec);
                container[index & 1].clear();
                vec.clear();
                index++;
        }
        return result;
    }
};