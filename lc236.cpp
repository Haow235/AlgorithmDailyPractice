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
        stack<TreeNode*> ancestor;
        
        // if(find)
        
        findTarget(root, p, ancestor);
        
        if(issubtree(p, q))
        {
            return p;
        }
        
        TreeNode* pre=ancestor.top();
        ancestor.pop();
        while(!ancestor.empty())
        {
            TreeNode* curnode = ancestor.top();
            ancestor.pop();
            if(curnode->val == q->val)
                return curnode;
            
            if(pre != curnode->left && issubtree(curnode->left, q))
                return curnode;
            
            if(pre != curnode->right && issubtree(curnode->right, q))
                return curnode;  
            
            pre = curnode;
        }
        
        return nullptr;
    }
    
private:
    bool findTarget(TreeNode* curnode, TreeNode* target, stack<TreeNode*>& ancestor)
    {
        if(curnode == nullptr)
            return false;
        
        ancestor.push(curnode);
        
        if(curnode->val == target->val)
            return true;
        
        if(findTarget(curnode->left, target, ancestor) || findTarget(curnode->right, target, ancestor))
        {
            return true;
        }
        else
        {
            ancestor.pop();
            return false;
        }
    }
    
    bool issubtree(TreeNode* curnode, TreeNode* target)
    {
        if(curnode == nullptr)
            return false;
        
        if(curnode->val == target->val)
            return true;
        
        if(issubtree(curnode->left, target) || issubtree(curnode->right, target))
            return true;
        return false;
    }
};
