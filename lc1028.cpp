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
    TreeNode* recoverFromPreorder(string S) {
        int p = 0;
        return recoverFromPreorderUtil(S, p, 0);
    }
    
private:
    TreeNode* recoverFromPreorderUtil(string s, int& p, int level)
    {
        if(p >= s.size())
            return nullptr;
        
        int original = p;
        int k = 0;
        while(s[original] == '-')
        {
            k++;
            original++;
        }
        
        if(k != level)
        {
            return nullptr;
        }
        
        p = original;
        
        int value = 0;
        while(p<s.size() && s[p] != '-')
        {
            value = value*10 + (s[p]-'0');
            p++;
        }
        
        TreeNode* re = new TreeNode(value);
        // p++;
        re->left = recoverFromPreorderUtil(s, p, level+1);
        re->right = recoverFromPreorderUtil(s, p, level+1);
        
        return re;
    }
};
