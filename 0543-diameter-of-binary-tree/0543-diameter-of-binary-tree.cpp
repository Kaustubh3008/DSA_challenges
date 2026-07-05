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
    int height(TreeNode* root,int& maxi){
        if(root == NULL) return 0;
        int left_h = height(root->left,maxi);
        int right_h = height(root->right,maxi);
        int sum = left_h + right_h;
        maxi = max(maxi,sum);
        return 1 + max(left_h, right_h);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi =0;
        height(root, maxi);
        return maxi;
    }
};