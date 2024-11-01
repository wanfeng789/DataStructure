//
// Created by 晚风 on 2024/9/17.
//

#include "binarySearchTree.h"

Tree *createBinarySearchTree()
{
    Tree * tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
static void releaseBinarySearchNode(Tree *tree, Node* node)
{
    if(node)
    {
        releaseBinarySearchNode(tree,node->left);
        releaseBinarySearchNode(tree,node->right);
        --tree->count;
        free(node);
    }
}
void releaseBinarySearchTree(Tree* root)
{
    if(root)
    {
        releaseBinarySearchNode(root, root->root);
        printf("count = %d\n", root->count);
    }
}
static Node * createBinarySearchNode(Element e, Tree *tree)
{
    Node * node = (Node*) malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->e = e;
    ++tree->count;
    return node;
}
Node * insertBinarySearchNode(Node * node, Element e, Tree *tree)
{
    if(node == NULL)
    {
        return createBinarySearchNode(e, tree);
    }
    if(node->e < e)
    {
        node->right = insertBinarySearchNode(node->right, e, tree);
    }
    else if( node->e > e)
    {
        node->left = insertBinarySearchNode(node->left, e, tree);
    }
    return node;
}
void insertBinarySearchTree(Tree *root, Element e)
{
    root->root = insertBinarySearchNode(root->root, e, root);
}
static void midOredrBinarySearchNode(Node* node)
{
    if(node)
    {
        midOredrBinarySearchNode(node->left);
        visitBinarySearchNode(node);
        midOredrBinarySearchNode(node->right);
    }
}
void midOredrBinarySearchTree(Tree *root)
{
    midOredrBinarySearchNode(root->root);
}

void visitBinarySearchNode(Node *node)
{
    printf("%d\t", node->e);
}
static Node * findNode(Node* node)
{
    while(node->left)
    {
        node = node->left;
    }
    return node;
}
static Node* delBinarySearchNode(Tree *tree, Node *node, Element e)
{
    if(node)
    {
        if(node->e < e)
        {
            node->right = delBinarySearchNode(tree, node->right, e);
        }
        else if(node->e > e)
        {
            node->left = delBinarySearchNode(tree, node->left, e);
        }
        else
        {
            Node* tmp = NULL;
            // 找到
            if(node->left == NULL)
            {
                tmp = node;
                node = node->right;
                --tree->count;
                free(tmp);
            }
            else if(node->right == NULL)
            {
                tmp = node;
                node = node->left;
                --tree->count;
                free(tmp);
            }
            else
            {
                // 左右节点都不为空, 转变研究对象
                // 找后置节点, 比当前节点大的中的最小值
                tmp = findNode(node->right);
                node->e = tmp->e;
                node->right = delBinarySearchNode(tree, node->right, node->e);
            }
        }
    }
    return node;
}
void delBinarySearchTree(Tree *root, Element e)
{
    if(root)
    {
        root->root = delBinarySearchNode(root, root->root, e);
    }
}
