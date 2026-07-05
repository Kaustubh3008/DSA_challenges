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
    int hieght(TreeNode* temp){
        if(temp == NULL) return 0;
        int left = hieght(temp->left);
        int right = hieght(temp->right);
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left_hieght = hieght(root->left);
        int right_hieght = hieght(root->right);
        int diff = abs(left_hieght - right_hieght);
        if(diff > 1) return false;
        bool a = isBalanced(root->left);
        bool b = isBalanced(root->right);
        return a&&b;
    }
};