#include <stdio.h>
#include <stdlib.h>
#ifndef DS_BINARYSEARCHTREE_H
#define DS_BINARYSEARCHTREE_H
typedef int Element;
// 二分搜索树
typedef struct _node_
{
    struct _node_* left;
    struct  _node_* right;
    Element e;
}Node;

typedef struct
{
    Node* root;
    int count;
}Tree;
Tree * createBinarySearchTree();
void releaseBinarySearchTree(Tree* root);
// 搜索树的插入
void insertBinarySearchTree(Tree* root, Element e);
void midOredrBinarySearchTree(Tree* root);
void visitBinarySearchNode(Node* node);
// 搜索树的删除
void delBinarySearchTree(Tree* root, Element e);
#endif //DS_BINARYSEARCHTREE_H
