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
    int count=0;
        pair<int, int>postOrder(TreeNode*node){
            if(node==nullptr) return{0,0};
            auto left= postOrder(node->left);
            auto right=postOrder(node->right);
            int totalSum=left.first+right.first+node->val;
            int totalCount=left.second+right.second+1;
            if(node->val== totalSum/totalCount){
                count++;
            }
            return {totalSum,totalCount};
        }
    
    
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
       return count;
    }
};