
#include "threadBTree.h"

BinaryTree *initBinaryTree() {
    BinaryTree *root = createBinaryTree();
    if (root == NULL) {
        return NULL;
    }
    Treenode *nodeA = createTreenode('A');
    Treenode *nodeB = createTreenode('B');
    Treenode *nodeC = createTreenode('C');
    Treenode *nodeD = createTreenode('D');
    Treenode *nodeE = createTreenode('E');
    Treenode *nodeF = createTreenode('F');
    Treenode *nodeG = createTreenode('G');
    Treenode *nodeH = createTreenode('H');
    Treenode *nodeK = createTreenode('K');
    // 初始化树头
    initBinaryTreeRoot(root, nodeA);
    // 插入节点
    insertBinaryTree(root, nodeA, nodeB, nodeE);
    insertBinaryTree(root, nodeB, NULL, nodeC);
    insertBinaryTree(root, nodeE, NULL, nodeF);
    insertBinaryTree(root, nodeC, nodeD, NULL);
    insertBinaryTree(root, nodeF, nodeG, NULL);
    insertBinaryTree(root, nodeD, NULL, NULL);
    insertBinaryTree(root, nodeG, nodeH, nodeK);
    insertBinaryTree(root, nodeH, NULL, NULL);
    insertBinaryTree(root, nodeK, NULL, NULL);

    return root;
}
void test()
{
    BinaryTree * root = initBinaryTree();
    threadTree(root);
    midOrderTree(root);
}
int main()
{
    test();

    return 0;
}


