/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void add(TreeNode* root, int val, int depth, int h){
        
        if(h == depth-1){
            TreeNode* left = new TreeNode(val, root->left, NULL);
            TreeNode* right = new TreeNode(val, NULL, root->right);
            root->left = left;
            root->right = right;
            return;
        }
        
        if(root->left)
            add(root->left, val, depth, h+1);
        if(root->right)
            add(root->right, val, depth, h+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* temp = new TreeNode(val, root, NULL);
            return temp;
        }
        
        add(root, val, depth, 1);
        return root;
    }
};