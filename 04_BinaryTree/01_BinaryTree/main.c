#include "binarytree.h"

BinaryTree *initBinaryTree1() {
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

void test01()
{
    BinaryTree * root = initBinaryTree1();
    if(root == NULL)
    {
        return;
    }

    printf("count = %d\n", root->count);
    preOrderBinaryTree(root);
    printf("\n");
    midOrderBinaryTree(root);
    printf("\n");
    lastOrderBinaryTree(root);
    printf("\n");
    levelOrderBinaryTree(root);
    printf("\n");

    int leafAns = leafCountBinaryTree(root);
    printf("leafans = %d\n", leafAns);
    int twodegreeAns = twoDegreeBinaryTree(root);
    printf("twodegreeans = %d\n", twodegreeAns);

    releaseBinaryTree(root);
}
void test02()
{


}
int main()
{
    test01();

    return 0;
}