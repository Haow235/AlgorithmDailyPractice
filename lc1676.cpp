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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        
        if(nodes.size() ==1)
            return nodes[0];
        
        unordered_set<TreeNode*> target(nodes.begin(), nodes.end());
        
        lowestCommonAncestorUtil(root, target);
        
        return re;
    }
    
private:
    TreeNode* re = nullptr;
    
    int lowestCommonAncestorUtil(TreeNode* root, unordered_set<TreeNode*>& target)
    {
        if(root == nullptr)
            return 0;
        
        int number = 0;
        if(target.find(root) != target.end())
        {
            number++;
        }
        
        number += lowestCommonAncestorUtil(root->left, target);
        number += lowestCommonAncestorUtil(root->right, target);
        
        if(re == nullptr && number == target.size())
        {
            re = root;
        }
        
        return number;
    }
};
