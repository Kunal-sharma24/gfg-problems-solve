class Solution {
public:
    int maximumpathsum(TreeNode* root,int &maxi){
        TreeNode* node = root;
        if(node==NULL) return 0;
        int left = max(0,maximumpathsum(node->left,maxi));
        int right = max(0,maximumpathsum(node->right,maxi));

        int current = node->val + left + right;
        maxi = max(maxi,current);
        return node->val+ max(left,right);        
        /*
        we need a path so we have 2 options so from a particular node
            2
           / \
          -1  3  -> so from here we have two options -1 and 3 so we will take
                    the max(-1,3) -> 3 that is right. Thats why
                    we used max(left,right) in return;
                    whereas we calculated the maximum path value as 
                    val + (0,left) + (0,right);  => 2 + 0 + 3 = 5
        */
    }

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maximumpathsum(root,maxi);
        return maxi;
    }
};