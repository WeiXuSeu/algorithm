/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param index: index.
     * @param value: value
     * @return: 
     */
    // assume index in the range[root->start, root->end];
    int max(SegmentTreeNode * left, SegmentTreeNode * right) {
        return left->max > right->max ? left->max : right->max;
    }
    
    void modify(SegmentTreeNode * root, int index, int value) {
        // write your code here
        // condition 1: reach the end;
        if(root == NULL) {
            return;
        }
        modify(root->left, index, value);
        modify(root->right, index, value);
        
        // condition: reach the target leaf node
        if(index == root->start && index == root->end) {
            root->max = value;
        }
        // condition: backward traversal, update from bottom to top
        else if(index >= root->start && index <= root->end) {
            root->max = max(root->left, root->right);
        }
        // condition: not in the range, return.
        else {
            return;
        }
    }
};