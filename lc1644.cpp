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
        unordered_set<TreeNode*> pp;
        
        findPP(root, p, pp);
        if(pp.size() == 0)
            return nullptr;
        
        findre(root, q, pp);
        
        return re;
    }
    
private:
    TreeNode* re = nullptr;
    
    bool findPP(TreeNode* root, TreeNode* p, unordered_set<TreeNode*>&pp)
    {
        if(root == nullptr)
            return false;
        
        if(root == p)
        {
            pp.insert(root);
            return true;
        }
        
        if(findPP(root->left, p, pp) || findPP(root->right, p, pp))
        {
            pp.insert(root);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool findre(TreeNode* root, TreeNode* q, unordered_set<TreeNode*>&pp)
    {
        if(root == nullptr)
            return false;
        
        if(root == q)
        {
            if(pp.find(q) != pp.end())
            {
                re = root;
            }
            
            return true;
        }
        
        if(findre(root->left, q, pp) || findre(root->right, q, pp))
        {
            if(re == nullptr && pp.find(root) != pp.end())
            {
                re = root;
            }
            
            return true;
        }
        else
        {
            return false;
        }
    }
};
