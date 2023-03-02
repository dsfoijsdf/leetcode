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
    bool visited, ans;
    int val;
    bool isValidBST(TreeNode* root) {
        ans = true, visited = false;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root->left) dfs(root->left);
        if(!visited) {visited=true;}
        else{
            if(root->val <= val) ans = false;
        }
        val = root->val;
        if(root->right) dfs(root->right);
    }
};