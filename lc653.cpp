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
    bool findTarget(TreeNode* root, int k) {
        
//         // Method 1
//         unordered_map<int, bool> nums;
        
//         // BFS search all node
//         queue<TreeNode*> candidate;
//         candidate.push(root);
//         TreeNode* curnode;
        
//         while(candidate.size())
//         {
//             curnode = candidate.front();
//             candidate.pop();
            
//             // if the complement of the curnum exist return true
//             if(nums.find(k-curnode->val) != nums.end())
//                 return true;
            
//             nums[curnode->val] = true;
//             if(curnode->left != nullptr)
//                 candidate.push(curnode->left);
//             if(curnode->right != nullptr)
//                 candidate.push(curnode->right);
            
//         }
        
//         return false;
        
        // Method 2
        // Convert BFS tree to sorted array, then use two pointer solution
        
        // convert to array
        vector<int> nums;
        convert_to_nums(root, nums);
        
        // two pointers
        int i=0, j=nums.size()-1;
        int cursum;
        
        while(i<j)
        {
            cursum = nums[i] + nums[j];
            if(cursum == k)
                return true;
            else if(cursum < k)
            {
                i++;
            }
            else
                j--;
        }
        
        return false;
        
    }
    
private:
    void convert_to_nums(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr)
            return;
        
        convert_to_nums(root->left, nums);
        nums.push_back(root->val);
        convert_to_nums(root->right, nums);
        
        return;
    }
};
