class Solution {
public:
    int hcal(TreeNode* node){
        if(node==NULL) return 0;
        return 1+max(hcal(node->left),hcal(node->right));
    }

    bool isBalanced(TreeNode* root) {
        TreeNode* node = root;
        if(node==NULL) return true;
        int lefth =  hcal(node->left);
        int righth = hcal(node->right);
        if(abs(lefth-righth) > 1) return false;
        bool balanceleft = isBalanced(node->left);
        bool balanceright = isBalanced(node->right);
        if(!balanceleft || !balanceright) return false;
        return true;  
    }
};