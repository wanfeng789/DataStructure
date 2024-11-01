
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef DS_THREADBTREE_H
#define DS_THREADBTREE_H

typedef int Element;

typedef struct _node_
{
    Element e;
    struct _node_* left;
    struct _node_* right;
    int lflag;
    int rflag;
}Treenode;

// 树头
typedef struct
{
    // 根节点
    Treenode * root;
    int count;
    int flag;
}BinaryTree;

// 创建二叉树
BinaryTree * createBinaryTree();
// 创建节点
Treenode * createTreenode(Element e);
// 初始化树头
void initBinaryTreeRoot(BinaryTree* root, Treenode* node);
// 插入节点
void insertBinaryTree(BinaryTree* root, Treenode* parent, Treenode* left, Treenode* right);
// 释放树
int releaseBinaryTree(BinaryTree* root);
int threadTree(BinaryTree* root);
int midOrderTree(BinaryTree* root);
#endif //DS_THREADBTREE_H
