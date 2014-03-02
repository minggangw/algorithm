#include <climits>
#include <cstddef>

struct TreeNode {
    TreeNode* m_left;
    TreeNode* m_right;
    int m_val;
};

bool isValidBST(TreeNode* node, int min, int max)
{
    if (node == NULL)
        return true;

    if (node->m_val <= min || node->m_val >= max)
        return false;

    return isValidBST(node->m_left, min, node->m_val) && isValidBST(node->m_right, node->m_val, max);
}

int main()
{
    TreeNode* root;
    isValidBST(root, INT_MAX, INT_MIN);
    return 0;
}
