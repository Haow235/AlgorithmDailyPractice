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
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        
        return maxsum;
        
    }
    
private:
    int maxsum = INT_MIN;
    
    int maxPathSumUtil(TreeNode* root)
    {
        if(root== nullptr)
            return 0;
        
        int leftmax = maxPathSumUtil(root->left);
        int rightmax = maxPathSumUtil(root->right);
        
        int curmax = max(leftmax+rightmax+root->val, max(rightmax, leftmax)+root->val);
        maxsum = max(maxsum, curmax);
        
        return max(0, max(max(leftmax, rightmax)+root->val, root->val));
        
    }
};/**
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
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        
        return maxsum;
        
    }
    
private:
    int maxsum = INT_MIN;
    
    int maxPathSumUtil(TreeNode* root)
    {
        if(root== nullptr)
            return 0;
        
        int leftmax = maxPathSumUtil(root->left);
        int rightmax = maxPathSumUtil(root->right);
        
        int curmax = max(leftmax+rightmax+root->val, max(rightmax, leftmax)+root->val);
        maxsum = max(maxsum, curmax);
        
        return max(0, max(max(leftmax, rightmax)+root->val, root->val));
        
    }
};
