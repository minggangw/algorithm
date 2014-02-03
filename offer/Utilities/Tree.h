// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#pragma once

#include <vector>

struct TreeNode 
{
    int                    m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

TreeNode* CreateTreeNode(int value);
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
void PrintTreeNode(TreeNode* pNode);
void PrintTree(TreeNode* pRoot);
void DestroyTree(TreeNode* pRoot);
