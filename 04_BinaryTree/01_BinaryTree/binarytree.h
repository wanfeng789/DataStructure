

#ifndef DS_BINARYTREE_H
#define DS_BINARYTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Element;

// 树的节点
typedef struct _node_
{
    Element e;
    struct _node_* left;
    struct _node_* right;
}Treenode;

// 树头
typedef struct
{
    // 根节点
    Treenode * root;
    int count;
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

// 先序遍历
int preOrderBinaryTree(BinaryTree* root);

// 中序遍历
int midOrderBinaryTree(BinaryTree* root);

// 后序遍历
int lastOrderBinaryTree(BinaryTree* root);

// 广度遍历
int levelOrderBinaryTree(BinaryTree* root);

// 获取叶子节点
int leafCountBinaryTree(BinaryTree* root);
int twoDegreeBinaryTree(BinaryTree* root);


















#endif //DS_BINARYTREE_H
