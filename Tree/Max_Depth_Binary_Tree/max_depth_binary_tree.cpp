#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    TreeNode* constructTree(const vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> q;
        q.push(root);

        size_t i = 1;
        while (!q.empty() && i < nums.size()) {
            TreeNode* current = q.front();
            q.pop();

            if (i < nums.size() && nums[i] != INT_MIN) {
                current->left = new TreeNode(nums[i]);
                q.push(current->left);
            }
            i++;

            if (i < nums.size() && nums[i] != INT_MIN) {
                current->right = new TreeNode(nums[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    
    Solution solution;
    TreeNode* root = solution.constructTree(nums);
    int depth = solution.maxDepth(root);

    cout << "Maximum Depth of the Binary Tree: " << depth << endl;

    // Don't forget to free the allocated memory
    // (You may want to use a separate function for this in a real application)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
