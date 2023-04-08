/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* helper(Node* node,vector<Node*> &v){
        Node* newNode=new Node(node->val);
        v[node->val]=newNode;
        int n=node->neighbors.size();
        for(int i=0;i<n;i++){
            int val=node->neighbors[i]->val;
            if(!v[val]){
                Node* temp=helper(node->neighbors[i],v);
                newNode->neighbors.push_back(temp);
            }
            else{
                newNode->neighbors.push_back(v[val]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        vector<Node*> v(101);
        return helper(node,v);
    }
};