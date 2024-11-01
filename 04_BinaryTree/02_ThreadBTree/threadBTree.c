
#include "threadBTree.h"
BinaryTree *createBinaryTree()
{
    BinaryTree * root = (BinaryTree*)malloc(sizeof(BinaryTree));
    if(root == NULL)
    {
        printf("root malloc err\n");
        return NULL;
    }
    root->count = 0;
    root->root = NULL;
    root->flag = 0;
    return root;
}

Treenode *createTreenode(Element e)
{
    Treenode * node = (Treenode*)malloc(sizeof (Treenode));
    if(node == NULL)
    {
        printf("node malloc err\n");
        return NULL;
    }
    node->e = e;
    node->left = node->right = NULL;
    node->lflag = node->rflag = 0;
    return node;
}

void initBinaryTreeRoot(BinaryTree *root, Treenode *node)
{
    if(node && root)
    {
        root->root = node;
        ++root->count;
    }
}

void insertBinaryTree(BinaryTree *root, Treenode *parent, Treenode *left, Treenode *right)
{
    if(!root || !parent )
    {
        return;
    }
    parent->left = left;
    parent->right = right;
    if(left)
    {
        ++root->count;
    }
    if(right)
    {
        ++root->count;
    }

}
int releaseTreeNode(BinaryTree *root,Treenode* node)
{
    if(node)
    {
        releaseTreeNode(root, node->left);
        releaseTreeNode(root,node->right);
        --root->count;
        free(node);
    }
    return 0;
}
int releaseBinaryTree(BinaryTree *root)
{
    if(root)
    {
        releaseTreeNode(root, root->root);
        printf("count = %d\n", root->count);
        free(root);
    }

    return 0;
}
static Treenode* son = NULL;
// 中序遍历的前驱节点
static void threadNode(Treenode* node)
{
    if(node)
    {
        threadNode(node->left);
        // 初始化 前驱 和 后继
        if(node->left == NULL)
        {
            node->left = son;
            node->lflag = 1;
        }
        if(son && son->right == NULL)
        {
            son->right = node;
            son->rflag = 1;
        }
        son = node;
        threadNode(node->right);
    }
}
int threadTree(BinaryTree *root)
{
    if(root)
    {
        threadNode(root->root);
        root->flag = 2;
    }

    return 0;
}
// 打印节点函数
void printTreenode(Treenode *node)
{
    printf("%c\t", node->e);
}
static void midOrderThreadTree(Treenode* node)
{
    while(node)
    {
        // 正常找中序点
        while(node->lflag == 0)
        {
            node = node->left;
        }
        printTreenode(node);
        // 判断右边是否为线索化
        while(node->rflag && node->right)
        {
            node = node->right;
            printTreenode(node);
        }
        node = node->right;
    }
}
int midOrderTree(BinaryTree *root)
{
    if(root)
    {
        if(root->flag)
        {
            midOrderThreadTree(root->root);
        }
    }
    return 0;
}
