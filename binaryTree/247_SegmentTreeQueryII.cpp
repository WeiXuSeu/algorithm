/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
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
     * @return: The count number in the interval [start, end]
     */
     
    // assume [start, end] in range [root->start, root->end]
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(root == NULL) {
            return 0;
        }
        //if beyond the range, then set it equal to the range.
        if(end > root->end) {
            end = root->end;
        }
        if(start < root->start) {
            start = root->start;
        }
        //meet the range, in middle node or leaf;
        if(root->start == start && root->end == end) {
            return root->count;
        }                          
        int mid = (root->start + root->end)/2;
        //check the distribution of range[start, end] depend on mid
        //mid in range [start, end), splite to two range
        if(mid >= start && mid < end) {
            return query(root->left, start, mid) + query(root->right, mid+1, end);
        }
        //mid in range (-00, start), on right child
        else if(mid < start) {
            return query(root->right, start, end);
        }
        //mid in range[end, +00), on left child
        else if(mid >= end) {
            return query(root->left, start, end);
        }
        
    }
};