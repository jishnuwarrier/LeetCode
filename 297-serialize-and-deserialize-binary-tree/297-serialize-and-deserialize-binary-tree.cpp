/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void preorder(TreeNode* root, string &code){
        if(root == NULL){
            code += "n,";
            return;
        }
        
        code.append(to_string(root->val));
        code += ',';
        
        preorder(root->left, code);
        preorder(root->right, code);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code;
        preorder(root, code);
        
        code.pop_back();
        return code;
    }

    TreeNode* helper(queue<string> &q){
        
        string str = q.front();
        q.pop();
        
        if(str == "n")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(str));
        root->left = helper(q);
        root->right = helper(q);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        queue<string> q;
        string str;
        for(int i=0; i<data.size(); i++){
            
            if(data[i] == ',')
                q.push(str), str = "";
            
            else
                str += data[i];
        }
        
        if(str != "")
            q.push(str);
        
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));