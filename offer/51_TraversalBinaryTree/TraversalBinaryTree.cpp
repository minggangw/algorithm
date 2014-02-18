#include <cstdio>
#include <cstddef>
#include <stack>
#include <iostream>

#include "BinaryTree.h"

using namespace std;
//二叉树的遍历
void PreorderRecursion(struct BinaryTreeNode* node)
{
	if (node != NULL) {
		printf("%d\t", node->m_nValue);
		PreorderRecursion(node->m_pLeft);
		PreorderRecursion(node->m_pRight);
	}
}

void Preorder(struct BinaryTreeNode* root)
{
	std::stack<BinaryTreeNode*> _stack;
    while (!_stack.empty() || root) {
        if (root) {
            printf("%d\t", root->m_nValue);
            _stack.push(root);
            root = root->m_pLeft;
        } else {
            root = _stack.top();
            _stack.pop();
            root = root->m_pRight;
        }
    }
}

void PostorderRecursion(struct BinaryTreeNode* node)
{
	if(node != NULL) {
		PostorderRecursion(node->m_pLeft);
		PostorderRecursion(node->m_pRight);
		printf("%d\t", node->m_nValue);
	}
}

void Postorder(BinaryTreeNode *root)    //非递归后序遍历
{
    stack<BinaryTreeNode*> s;
    BinaryTreeNode *p = root;
    BinaryTreeNode* pre = NULL;

    while (p || !s.empty()) {
        if (p) {             //沿左子树一直往下搜索，直至出现没有左子树的结点
            s.push(p);
            p = p->m_pLeft;
        } else {
            p = s.top();
            s.pop();
            if(p->m_pRight == NULL || p->m_pRight == pre) {     //表示是第一次出现在栈顶
                cout << p->m_nValue << "\t";
                pre = p;
                p = NULL;
            } else {                        //第二次出现在栈顶
                s.push(p);
                p = p->m_pRight;
            }
        }
    }
}

void InorderRecursion(struct BinaryTreeNode* node)
{
    if(node != NULL) {
        InorderRecursion(node->m_pLeft);
        printf("%d\t", node->m_nValue);
        InorderRecursion(node->m_pRight);
    }
}

void Inorder(struct BinaryTreeNode* root)
{
	std::stack<BinaryTreeNode*> _stack;
	while (root || !_stack.empty()) {
        if (root) {
            _stack.push(root);
            root = root->m_pLeft;
        } else {
            root = _stack.top();
            _stack.pop();
            printf("%d\t", root->m_nValue);
            root = root->m_pRight;
        }
	}
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// Ã»ÓÐÂ·Ÿ¶ÉÏµÄœáµãºÍÎª15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode4, pNode7);
    
    printf("Prorder\nRecursion:");
    PreorderRecursion(pNode10);
    printf("\nLoop:");
    Preorder(pNode10);
    printf("\n");

    printf("Inorder\nRecursion:");
    InorderRecursion(pNode10);
    printf("\nLoop:");
    Inorder(pNode10);
    printf("\n");
    
    printf("Postorder\nRecursion:");
    PostorderRecursion(pNode10);
    printf("\nLoop:");
    Postorder(pNode10);
    printf("\n");
    
    
    DestroyTree(pNode10);
}

int main()
{
    Test2();
    
    return 0;
}
