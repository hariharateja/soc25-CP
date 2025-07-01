#include<iostream>
using namespace std;
#include<string>
#include<vector>
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
    vector<int> result;

    void dfs(TreeNode* node, int level) {
        if (!node) return;
        if (level == result.size()) {
            result.push_back(node->val);
        }
        dfs(node->right, level + 1);
        dfs(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};