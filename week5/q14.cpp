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
    TreeNode* getIS(TreeNode* root){
        while(root != NULL && root-> left!= NULL){
            root = root->left;
        }
        return  root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key> root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* IS = getIS(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right,IS->val);
            }

        }
        return root;
    }
};