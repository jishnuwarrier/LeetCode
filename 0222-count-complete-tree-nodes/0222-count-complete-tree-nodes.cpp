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
    int ans = 0;
    
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        int lh=1, rh=1;
        for(; left!=NULL; left=left->left, lh++);
        for(; right!=NULL; right=right->right, rh++);
        
        if(lh == rh){
            ans += pow(2, lh)-1;
            return;
        }
        
        ans++;
        helper(root->left);
        helper(root->right);
    }
    
    int countNodes(TreeNode* root) {
        
        helper(root);
        return ans;
    }
};