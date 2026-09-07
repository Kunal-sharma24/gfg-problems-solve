class Solution {
  public:
  
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* temp = q.front().first;
            int idx = q.front().second;
            mp.insert({idx,temp->data});
            q.pop();
            if(temp->left!=NULL) q.push({temp->left,idx-1});
            if(temp->right!=NULL) q.push({temp->right,idx+1});
        }
        for(auto map : mp){
            ans.push_back(map.second);
        }
        return ans;
    }
};