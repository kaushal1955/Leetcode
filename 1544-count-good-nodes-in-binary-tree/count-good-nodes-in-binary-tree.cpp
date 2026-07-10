class Solution {
public:
    void solve(TreeNode* root,int& count,int max){
        if(root==NULL){
            return;
        }
        if(root->val>=max){
            count++;
            max=root->val;
        }
        solve(root->left,count,max);
        solve(root->right,count,max);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,count,root->val);
        return count;
    }
};