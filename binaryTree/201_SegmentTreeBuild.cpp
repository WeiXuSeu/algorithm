/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end) {
            return NULL;
        }
        SegmentTreeNode * root = new SegmentTreeNode(start, end);
        int mid = (start + end)/2;
        //make start > mid, prevent loop when start == end;
        if(start == end) {
            start = mid + 1;
        }
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        return root;
    }
};