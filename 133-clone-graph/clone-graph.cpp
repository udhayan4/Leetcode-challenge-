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
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> vis;
        Node* cr=new Node(node->val);
        vis[node]=cr;
        while(!q.empty()){
            Node* NODE=q.front();
            q.pop();
            for(Node* neighbor:NODE->neighbors){
                if(vis.find(neighbor)==vis.end()){
                    Node* nc=new Node(neighbor->val);
                    q.push(neighbor);
                    vis[neighbor]=nc;
                }
                vis[NODE]->neighbors.push_back(vis[neighbor]);
            }
        }
        return cr;;
    }
};