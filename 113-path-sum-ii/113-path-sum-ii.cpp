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
    vector<vector<int>> ans;
    
    void inorder(vector<int> path, TreeNode* root, int tsum){
        
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        tsum -= root->val;
        
        if(tsum == 0 && root->left == NULL && root->right == NULL)
            ans.push_back(path);
        
        
        inorder(path, root->left, tsum);
        inorder(path, root->right, tsum);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int tsum) {
        
        if(root == NULL)
            return {};
        
        int tgt = tsum - root->val;
        
        if(tgt == 0 && !root->left && !root->right)
            return {{root->val}};
        
        inorder({root->val}, root->left, tgt);
        inorder({root->val}, root->right, tgt);
        
        return ans;
    }
};