

#include "AvlTree.h"
void test01()
{
    AVLTree * tree = createAVLTree();
    Element data[] = {10,20,30,40,50,60,68,80,25,7,55};
    for(int i = 0; i < 10; ++i)
    {
        insertAVLTree(tree,data[i]);
    }
    MidOrderAVLTree(tree);
    printf("\n");
    delAVLTree(tree, 50);
    MidOrderAVLTree(tree);
    printf("\n");
    delAVLTree(tree, 40);
    MidOrderAVLTree(tree);
    printf("\n");
    delAVLTree(tree, 25);
    MidOrderAVLTree(tree);
    printf("\n");
    releaseAVLTree(tree);
}
int main()
{
    test01();

    return 0;
}

