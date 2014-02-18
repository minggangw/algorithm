#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 21

struct btree
{
    struct btree *lchild, *rchild;
    char data;
};

struct stack
{
    int top;
    struct btree* arr[LEN];
};

char order_str[LEN], pre_str[LEN], compare_order[LEN], compare_pre[LEN];

struct btree* create_searchtree(struct btree *t, char temp);
void order_traverse(struct btree *t, char *A);
void pre_traverse(struct btree *t, char *A);
void clean_searchtree(struct btree *t);

int main()
{
    int i, j, n, len, clen;
    char str1[LEN], str2[LEN];

    while (scanf("%d", &n) != EOF && n != 0) {

        // 接收客户端数据输入
        scanf("%s", str1);
        struct btree *t;
        for (i = 0, len = strlen(str1), t = NULL; i < len; i ++) {
            t = create_searchtree(t, str1[i]);
        }

        // 中序遍历二叉树
        order_traverse(t, order_str);

        // 前序遍历二叉树
        pre_traverse(t, pre_str);


        // 接收比较序列
        for (i = 0; i < n; i ++) {
            scanf("%s", str2);
            struct btree *r;

            for (j = 0, clen = strlen(str2), r = NULL; j < clen; j ++) {
                r = create_searchtree(r, str2[j]);
            }

            order_traverse(r, compare_order);

            if (strcmp(order_str, compare_order) != 0) {
                printf("NO\n");
            }else {
                pre_traverse(r, compare_pre);
                if (strcmp(pre_str, compare_pre) != 0) {
                    printf("NO\n");
                }else {
                    printf("YES\n");
                }
            }
            clean_searchtree(r);
        }
        clean_searchtree(t);
    }

    return 0;
}

/**
 * Description:构建二叉查找树
 */
struct btree* create_searchtree(struct btree *t, char temp)
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
    }else if (t->data > temp) {   // 如果比当前结点小，则插入左子树
        t->lchild = create_searchtree(t->lchild, temp);
    }else if (t->data < temp){    // 如果比当前结点大，则插入右子树
        t->rchild = create_searchtree(t->rchild, temp);
    }

    return t;
}

void order_traverse(struct btree *t, char *A)
{
    struct stack *s = (stack*)malloc(sizeof(struct stack));
    s->top = 0;
    struct btree *p = t;
    memset(A, 0, sizeof(A));
    int i = 0;

    while (s->top || p) {
        if (p) {
            s->arr[s->top ++] = p;
            p = p->lchild;
        } else {
            p = s->arr[-- s->top];
            A[i ++] = p->data;
            p = p->rchild;
        }
    }
}

void pre_traverse(struct btree *t, char *A)
{
    struct stack *s = (stack*)malloc(sizeof(struct stack));
    s->top = 0;
    struct btree *p = t;
    memset(A, 0, sizeof(A));
    int i = 0;

    while (s->top || p) {
        if (p) {
            A[i ++] = p->data;
            s->arr[s->top ++] = p;
            p = p->lchild;
        } else {
            p = s->arr[-- s->top];
            p = p->rchild;
        }
    }

}

void clean_searchtree(struct btree *t)
{
    if (t) {
        clean_searchtree(t->lchild);
        clean_searchtree(t->rchild);
        free(t);
    }
}
/**************************************************************
    Problem: 1009
    User: wangzhengyi
    Language: C
    Result: Accepted
    Time:10 ms
    Memory:908 kb
****************************************************************/
