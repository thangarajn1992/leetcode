// 589 N-Ary preorder Traversal Solution

class Solution {
public:
    vector<int> result;
    void preorderutil(Node * root) {
        result.push_back(root->val);
        int size = root->children.size();
        for(int i = 0; i< size; i++)
            preorderutil(root->children[i]);
    }
    vector<int> preorder(Node* root) {  
        if(!root)
            return {};
        preorderutil(root);
        return result;

    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
