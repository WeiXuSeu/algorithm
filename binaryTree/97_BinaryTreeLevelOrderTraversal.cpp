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

/*
Care about the usage about vector,
the capacity, and the index,

*/


class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        // vector<vector<int>>, we can push back a vector<int> to it;
        // add element to it dynamically.
        vector<vector<int>> result;
        // two queue, to keep each level as a state;
        // initialize capcity to "2", so we can use index (0, 1) directly.
        // make sure the size (alreay exist, enough), we can use index to access to directly
        vector<queue<TreeNode *>> states(2);
        // initialize, put root to a queue as a level state (if not none, only one node)
        if(NULL != root) {
            states[0].push(root);
        }
        // initialize index of vector to 0;
        // and the index of states to be index & 1
        int index = 0;
        TreeNode *node = NULL;
        vector<int> tmpVec;
        while(!states[index&1].empty()) {
            node = states[index&1].front();
            tmpVec.push_back(node->val);
            //push child level to another state queue
            if(node->left) {
                states[(index+1)&1].push(node->left);
            }
            if(node->right) {
                states[(index+1)&1].push(node->right);
            }
            //after make full use of the node in current state queue, pop it out    
            states[index&1].pop();
            //if current state queue empty, index + 1, go to another state queue,
            //and puth their values to next vector -- vector[index + 1]
            if(states[index&1].empty()) {
                result.push_back(tmpVec);
                tmpVec.clear();
                index = index + 1;
            }
        }
        return result;
    }
};