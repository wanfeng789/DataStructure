
#include "AvlTree.h"
static int getheight(AVLNode* node)
{
    if(node)
    {
        return node->height;
    }
    return 0;
}
static int max(int x, int y)
{
    return x > y ? x : y;
}
// 左旋操作  因为是右边的节点重
static AVLNode *leftAVLNode(AVLNode* x)
{
    AVLNode * y = x->right;
    x->right = y->left;
    y->left = x;
    // 更新高度
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}
// 右旋操作  因为左边节点重
static AVLNode *rightAVLNode(AVLNode* x)
{
    AVLNode * y = x->left;
    x->left = y->right;
    y->right = x;
    // 更新高度
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}
static int getBalance(AVLNode* node)
{
    return getheight(node->left) - getheight(node->right);
}
AVLTree *createAVLTree()
{
    AVLTree * tree = (AVLTree*)malloc(sizeof(AVLTree));

    tree->root = NULL;
    tree->cnt = 0;
    return tree;
}
static AVLNode * insertAVLNode(AVLTree* tree, AVLNode* node, Element e)
{
    if(node == NULL)
    {
        return createAVLNode(tree, e);
    }
    if(e < node->data)
    {
        node->left = insertAVLNode(tree, node->left, e);
    }
    else if(e > node->data)
    {
        node->right = insertAVLNode(tree, node->right, e);
    }
    else
    {
        return node;
    }
    node->height = max(getheight(node->left), getheight(node->right)) + 1;
    // 判断是否平衡
    int balance = getBalance(node);
    // 说明是 LL 或者是 LR
    if(balance > 1)
    {
        // 判断是否为 LR >> LL
        if(e > node->left->data)
        {
            // 先对 node->left 进行左选变成 LL
            node->left = leftAVLNode(node->left);
        }
        // 进行 右旋操作
        return rightAVLNode(node);
    }
    // 说明是 RR 或者是  RL
    else if(balance < -1)
    {
        // 判断是不是RL 进行右旋操作
        if(e < node->right->data)
        {
            node->right = rightAVLNode(node->right);
        }
        return leftAVLNode(node);
    }
    return node;
}
void insertAVLTree(AVLTree *tree, Element e)
{
    if(tree)
    {
        tree->root = insertAVLNode(tree, tree->root, e);
    }
}

AVLNode *createAVLNode(AVLTree *tree, Element e)
{
   AVLNode * node = (AVLNode*) malloc(sizeof(AVLNode));

   node->left = node->right = NULL;
   node->data = e;
   node->height = 1;
   ++tree->cnt;
    return node;
}
void releaseAVLNode(AVLTree*tree, AVLNode* node)
{
    if(node)
    {
        releaseAVLNode(tree,node->left);
        releaseAVLNode(tree,node->right);

        --tree->cnt;
        free(node);
    }
}
void releaseAVLTree(AVLTree*tree)
{
    if(tree)
    {
        releaseAVLNode(tree, tree->root);
        printf("cnt = %d\n", tree->cnt);
        free(tree);
    }
}
static void visitAVLNode(AVLNode *node)
{
    printf("<%d, %d> ", node->data,node->height);
}
void MidOrderAVLNode(AVLNode* node)
{
    if(node)
    {
        MidOrderAVLNode(node->left);
        visitAVLNode(node);
        MidOrderAVLNode(node->right);
    }
}
void MidOrderAVLTree(AVLTree *tree)
{
    if(tree)
    {
        MidOrderAVLNode(tree->root);
    }
}

static AVLNode* delAVLNode(AVLTree* tree, AVLNode* node, Element e)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(e < node->data)
    {
        node->left = delAVLNode(tree, node->left, e);
    }
    else if(e > node->data)
    {
        node->right = delAVLNode(tree, node->right, e);
    }
    else
    {
        // 找到删除节点
        AVLNode * tmp = NULL;
        if(node->left == NULL || node->right == NULL)
        {
            // 备份相应左或者右孩子节点
            tmp = node->left ? node->left : node->right;
            free(node);
            --tree->cnt;
            return tmp;
        }
        else        // 删除节点度为 2
        {
            // 找前置节点
            tmp = node->left;
            while(tmp->right)
            {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            // 转换研究对象
            node->left = delAVLNode(tree, node->left, tmp->data);
        }
    }
    // 开始更新当前节点的信息
    node->height = max(getheight(node->left), getheight(node->right)) + 1;
    // 平衡因子
    int balance = getBalance(node);
    // LL 或者 LR
    if(balance > 1)
    {
        // LR
        if(getBalance(node->left) < 0)
        {
            node->left = leftAVLNode(node->left);
        }
        return rightAVLNode(node);
    }
    // RR 或者 RL
    else if(balance < -1)
    {
        // RL
        if(getBalance(node->right) > 0)
        {
            node->right = rightAVLNode(node->right);
        }
        return leftAVLNode(node);
    }
    return node;
}

void delAVLTree(AVLTree *tree, Element e)
{
    if(tree)
    {
        tree->root = delAVLNode(tree, tree->root, e);
    }
}




