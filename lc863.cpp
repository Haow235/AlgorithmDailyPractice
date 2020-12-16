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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, TreeNode*> parents;
        
        dfs(root, nullptr, parents);
        
        // start from target, do BFS search, until the K level
        queue<TreeNode*> nodes;
        unordered_map<int, bool> visited;
        nodes.push(target);
        visited[target->val] = true;
        
        int level = 0;
        
        vector<int> re;
        
        while(!nodes.empty() && level<=K)
        {
            int size = nodes.size();
            for(int i{0}; i<size; i++)
            {
                TreeNode* curnode = nodes.front();
                nodes.pop();
                if(level == K)
                {
                    re.push_back(curnode->val);
                }
                else
                {
                    if(curnode->left != nullptr && visited.find(curnode->left->val) == visited.end())
                    {
                        visited[curnode->left->val] = true;
                        nodes.push(curnode->left);
                    }
                    if(curnode->right != nullptr && visited.find(curnode->right->val) == visited.end())
                    {
                        visited[curnode->right->val] = true;
                        nodes.push(curnode->right);
                    }
                    if(parents[curnode->val] != nullptr && visited.find(parents[curnode->val]->val) == visited.end())
                    {
                        visited[parents[curnode->val]->val] = true;
                        nodes.push(parents[curnode->val]);
                    }
                }
            }
            
            level++;
        }
        
        return re;
    }
    
private:
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<int, TreeNode*>& parents)
    {
        if(root != nullptr)
        {
            parents[root->val] = parent;
            dfs(root->left, root, parents);
            dfs(root->right, root, parents);
        }
    }
};
