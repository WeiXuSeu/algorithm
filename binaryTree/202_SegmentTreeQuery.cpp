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
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    
    int max(int A, int B) {
        return A > B ? A : B;
    } 
     
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        // match the range [start, end], no matter in node of leaf;
        if(root->start == start && root->end == end) {
            return root->max;
        }
        // mid is seperater, [root->left, mid], [mid+1, root->right]
        // so we should check range[start, end], in which scope
        // left scope, right scope, or both
        // also notice, when root->end = root->start + 1, then mid = root->start
        //     seperate to two scope, each scope one node.
        int mid = (root->start + root->end)/2;           
        if(mid >= start && mid < end) {
            return max(query(root->left, start, mid), query(root->right, mid+1, end));
        }
        else if(end <= mid) {
            return query(root->left, start, end);
        }
        else if(start > mid) {
            return query(root->right, start, end);
        }
    }
};