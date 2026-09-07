/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty()){
            Node* temp = q.front().first;
            int idx = q.front().second;
            mp[idx]=temp->data;
            q.pop();
            if(temp->left!=NULL) q.push({temp->left,idx-1});
            if(temp->right!=NULL) q.push({temp->right,idx+1});
        }
        for(auto v : mp){
            ans.push_back(v.second);
        }
        return ans;
    }
};