/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curnode = root;
        
        while(curnode)
        {
            if(p->val < curnode->val && q->val < curnode->val)
            {
                curnode = curnode->left;
            }
            else if(p->val > curnode->val && q->val > curnode->val)
            {
                curnode = curnode->right;
            }
            else
            {
                return curnode;
            }
        }
        
        return nullptr;
    }
};
