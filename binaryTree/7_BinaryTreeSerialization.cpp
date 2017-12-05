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
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */

    string serialize(TreeNode * root) {
        // write your code here
        ostringstream out;
        serializeCore(root, out);
        return out.str();
        
    }
    
    void serializeCore(TreeNode * root, ostringstream & out) {
        if(root == NULL) {
            out << '#' << ' ';
            return;
        }
        
        out << root->val << ' ';
        serializeCore(root->left, out);
        serializeCore(root->right, out);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        istringstream in(data);
        TreeNode * root = deserializeCore(in);
        return root;
    }
    
    TreeNode * deserializeCore(istringstream & in) {
        string str;
        in >> str;
        if(str == "#") {
            return NULL;
        }
        
        TreeNode * root = new TreeNode(stoi(str));
        root->left = deserializeCore(in);
        root->right = deserializeCore(in);
        return root;
    }
};