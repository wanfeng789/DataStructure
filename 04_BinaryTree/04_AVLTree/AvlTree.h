
#ifndef DS_AVLTREE_H
#define DS_AVLTREE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// AVL树的创建
typedef int Element;
typedef struct _avlnode
{
    Element data;
    struct _avlnode* left;
    struct _avlnode* right;
    int height;
}AVLNode;

// 头
typedef struct
{
    AVLNode * root;
    int cnt;
}AVLTree;


AVLTree * createAVLTree();
void releaseAVLTree(AVLTree*tree);
AVLNode * createAVLNode(AVLTree* tree, Element e);
// 插入节点
void insertAVLTree(AVLTree* tree, Element e);
void MidOrderAVLTree(AVLTree* tree);
// 删除节点
void delAVLTree(AVLTree* tree, Element e);

#endif //DS_AVLTREE_H
