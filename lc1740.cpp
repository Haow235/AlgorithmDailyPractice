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
    int findDistance(TreeNode* root, int p, int q) {
        
        if(p == q)
            return 0;
        
        findDistanceUtil(root, p, q);
        
        return re;
    }
    
private:
    int re = -1;
    bool findDistanceUtil(TreeNode* root, int p, int q)
    {
        if(root == nullptr)
            return false;
        
        int count = 0;
        if(root->val == p || root->val == q)
        {
            count++;
        }
        
        if(findDistanceUtil(root->left, p, q))
        {
            count++;
        }
        
        if(findDistanceUtil(root->right, p, q))
        {
            count++;
        }
        
        if(count == 2)
        {
            re = findDist(root, p) + findDist(root, q);
        }
        
        return count;
    }
    
    int findDist(TreeNode* root, int t)
    {
        if(root == nullptr)
            return -1;
            
        if(root->val == t)
            return 0;
        
        int re =  findDist(root->left, t);
        if(re != -1)
        {
            return 1 + re;
        }
        
        re =  findDist(root->right, t);
        if(re != -1)
        {
            return 1 + re;
        }
        
        return -1;
    }
};
