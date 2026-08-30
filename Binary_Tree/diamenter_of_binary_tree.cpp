class Solution {
public:
    int diameter=0;
    int heightnode(TreeNode* node){
        if(node==NULL) return 0;
        int leftidx = heightnode(node->left);
        int rightidx = heightnode(node->right);

        diameter=max(leftidx+rightidx , diameter);
        return 1+max(leftidx,rightidx);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightnode(root);
        return diameter;
    }
};


/*
        approach 
        1.declare the diameter as global
        2.we have to check the diamter at every node as height(left)+heights(right)
        3.we will use the height function to calculate the height of left and right subtree and update the diameter at every node
        4.in diameter we will max(diameter,leftheight+righttree);
        5.we will return the diameter


        example -
               1
            2     3
                4    5
              6        7 
             8           9

             the root node is not maximum diameter it is 3(node).


*/