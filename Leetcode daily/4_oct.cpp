 
class Solution {
public:
    bool isPath(TreeNode* root,int target){
        if(!root){
            return 0;
        }
        if(!root->left and !root->right){
            if(root->val == target){
                return 1;
            }
            return 0;
        }
        bool left = false, right = false;
       
        left = isPath(root->left,target-root->val);
        right = isPath(root->right,target - root->val);
        
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isPath(root,targetSum);
    }
};