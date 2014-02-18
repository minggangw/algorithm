#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct btree
{
    struct btree *lchild, *rchild;
    char data;
};

void printNode(struct btree* t, int value)
{
    if(!t) {
        printf("%d\n", value);
    }
}

struct btree* create_searchtree(struct btree *t, char temp, struct btree* parent)
{
    if (t == NULL) {    // 若当前树为空
        t = (struct btree *)malloc(sizeof(struct btree) * 1);
        if (t == NULL) {
            printf("内存分配失败!\n");
            exit(EXIT_FAILURE);
        }
        t->data = temp;
        t->lchild = NULL;
        t->rchild = NULL;

        if (parent)
            printf("%d\n", parent->data);
        else
            printf("%d\n", -1);
    }else if (t->data > temp) {   // 如果比当前结点小，则插入左子树
        t->lchild = create_searchtree(t->lchild, temp, t);
    }else if (t->data < temp){    // 如果比当前结点大，则插入右子树
        t->rchild = create_searchtree(t->rchild, temp, t);
    }

    return t;
}

int main()
{
    int arr[] = {2, 5, 1, 3, 4};

    struct btree *root = NULL;
    struct btree *parent = NULL;
    int i;
    int len = 5;
    for (i = 0, root = NULL; i < len; i ++) {
        root = create_searchtree(root, arr[i], parent);
    }

    return 0;
}
