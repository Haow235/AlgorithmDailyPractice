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
    void recoverTree(TreeNode* root) {
        TreeNode* prenode = nullptr;
        stack<TreeNode*> nodes;
        
        while(!nodes.empty() || root != nullptr)
        {
            while(root)
            {
                nodes.push(root);
                root = root->left;
            }
            
            // curnode
            root = nodes.top();
            nodes.pop();
            
            if(prenode != nullptr && root->val < prenode->val)
            {
                second = root;
                
                if(first == nullptr)
                {
                    first = prenode;
                }
                else
                {
                    break;
                }
            }
            
            prenode = root;
            
            // one step to the right
            root = root->right;
        }
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
};
