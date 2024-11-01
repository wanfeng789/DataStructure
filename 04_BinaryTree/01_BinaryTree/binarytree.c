
#include "binarytree.h"

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
// 打印节点函数
void printTreenode(Treenode *node)
{
    printf("%c\t", node->e);
}

// 先序遍历的递归函数
void preOrderTreeNode(Treenode* node)
{
    if(node)
    {
        // 1 打印
        printTreenode(node);
        // 2 左遍历
        preOrderTreeNode(node->left);
        // 3 右遍历
        preOrderTreeNode(node->right);
    }
}
int preOrderBinaryTree(BinaryTree *root)
{
    if(root->root)
    {
        printf("先序遍历: ");
        preOrderTreeNode(root->root);
    }
    return 0;
}
// 中序遍历的递归函数
void midOrderTreeNode(Treenode* node)
{
    if(node)
    {
        // 1. 左遍历
        midOrderTreeNode(node->left);
        // 2. 打印
        printTreenode(node);
        // 3 右遍历
        midOrderTreeNode(node->right);
    }
}
int midOrderBinaryTree(BinaryTree *root)
{
    if(root->root)
    {
        printf("中序遍历: ");
        midOrderTreeNode(root->root);
    }
    return 0;
}

// 后序遍历的递归函数
void lastOrderTreeNode(Treenode* node)
{
    if(node)
    {
        // 1. 左遍历
        lastOrderTreeNode(node->left);
        // 2. 右遍历
        lastOrderTreeNode(node->right);
        // 3. 打印
         printTreenode(node);
    }
}
int lastOrderBinaryTree(BinaryTree *root)
{
    if(root->root)
    {
        printf("后序遍历: ");
        lastOrderTreeNode(root->root);
    }
    return 0;
}

int levelOrderBinaryTree(BinaryTree *root)
{
    int len = root->count;
    Treenode * data[len];
    Treenode * node;
    int front = 0, rear = 0;
    data[rear++] = root->root;
    while(front != rear)
    {
        // 先出队
        node = data[front];
        printTreenode(node);
        front = (front + 1) % len;
        if(node->left)
        {
            data[rear] = node->left;
            rear = (rear + 1) % len;
        }
        if(node->right)
        {
            data[rear] = node->right;
            rear = (rear + 1) % len;
        }

    }
    return 0;
}
static void leafCountBinaryNode(Treenode* node, int* cnt)
{
    if(node)
    {
        leafCountBinaryNode(node->left, cnt);
        leafCountBinaryNode(node->right, cnt);
        if(node->left == NULL && node->right == NULL)
        {
            ++(*cnt);
        }
    }
}
int leafCountBinaryTree(BinaryTree *root)
{
    int cnt = 0;
    if(root)
    {
        leafCountBinaryNode(root->root, &cnt);
    }
    return cnt;
}

static void twoDegreeBinaryNode(Treenode* node, int* cnt)
{
    if(node)
    {
        if(node->left && node->right)
        {
            ++(*cnt);
        }
        twoDegreeBinaryNode(node->left, cnt);
        twoDegreeBinaryNode(node->right, cnt);
    }
}
int twoDegreeBinaryTree(BinaryTree *root)
{
    int cnt = 0;
    if(root)
    {
        twoDegreeBinaryNode(root->root, &cnt);
    }
    return cnt;
}
















