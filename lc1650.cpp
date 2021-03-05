/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> p_parents;
        
        Node* curnode = p;
        while(curnode != nullptr)
        {
            p_parents.insert(curnode);
            curnode = curnode->parent;
        }
        
        curnode = q;
        while(curnode != nullptr)
        {
            if(p_parents.find(curnode) != p_parents.end())
            {
                return curnode;
            }
            
            curnode = curnode->parent;
        }
        
        return nullptr;
    }
};
