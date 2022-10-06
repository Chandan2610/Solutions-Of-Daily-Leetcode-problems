
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void solve(TreeNode* root,int val, int depth,int level=0){
        if(root){
            if(level==depth-1){
                    TreeNode* newroot= new TreeNode(val);
                    newroot->left=root->left;
                    root->left=newroot;
                    newroot= new TreeNode(val);
                    newroot->right=root->right;
                    root->right=newroot;
            }
                solve(root->left,val,depth,level+1);
                solve(root->right,val,depth,level+1);   
        }
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot= new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        solve(root,val,depth,1);
        return root;
        
    }
};