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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(root==NULL) return ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->right!=NULL) s.push(node->right);
            if(node->left!=NULL) s.push(node->left);
        }
        return ans;
    }
};



/*

START
   ↓
Create empty vector ANS
   ↓
Create empty stack S
   ↓
Is ROOT NULL?
   ├── YES → Return ANS
   └── NO
        ↓
     Push ROOT into S
        ↓
   Is S empty?
   ├── YES → Return ANS → END
   └── NO
        ↓
   Take top node from S
        ↓
   Add node's value to ANS
        ↓
   Pop node from S
        ↓
   Does node have RIGHT child?
   ├── YES → Push RIGHT child into S
   └── NO
        ↓
   Does node have LEFT child?
   ├── YES → Push LEFT child into S
   └── NO
        ↓
   Go back to "Is S empty?"

*/