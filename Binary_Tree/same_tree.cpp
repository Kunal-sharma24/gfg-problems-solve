class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p==q;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};


/*
    approach: 
    1. we will check if both the nodes are null then return true
    2. if one of the node is null then return false
    3. if both the nodes are not null then check if their values are equal or
    not if not equal return false
    4. if equal then check for left and right subtree recursively
    
*/