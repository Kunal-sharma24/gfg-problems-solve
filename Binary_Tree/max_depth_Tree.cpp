class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1+max(l,r);
    }
};    //recursive way



class Solution {
public:
    int maxDepth(TreeNode* root) {
        int height=0;
        if(root==NULL) return 0;
        TreeNode* node=root;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            height++;
            int n = q.size();
            while(n--){
                TreeNode * curr = q.front();
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return height;
    }
}; //iterative way Level order traversal


/*
    approach:
    1. Recursive way:
        - If the root is NULL, return 0.
        - Recursively call the function for the left and right subtrees.
        - Return 1 + the maximum of the left and right subtree depths.
    2. Iterative way (Level order traversal):
        - If the root is NULL, return 0.
        - Use a queue to perform level order traversal.
        - For each level, increment the height and process all nodes at that level.
        
*/
