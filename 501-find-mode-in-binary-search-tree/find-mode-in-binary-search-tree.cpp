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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int currVal = 0;
        int currCount = 0;
        int maxCount = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            if (node->val == currVal) {
                currCount++;
            } else {
                currVal = node->val;
                currCount = 1;
            }

            if (currCount > maxCount) {
                maxCount = currCount;
                result.clear();
                result.push_back(currVal);
            } else if (currCount == maxCount) {
                result.push_back(currVal);
            }

            inorder(node->right);
        };

        inorder(root);
        return result;
    }
};