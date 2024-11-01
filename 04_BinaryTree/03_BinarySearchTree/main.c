#include "binarySearchTree.h"

void test01()
{
    Element arr[] = {3, 4, 12, 34, 55, 9};
    Tree * tree = createBinarySearchTree();
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        insertBinarySearchTree(tree, arr[i]);
    }
    midOredrBinarySearchTree(tree);
    printf("\n");
    delBinarySearchTree(tree, 3);
    midOredrBinarySearchTree(tree);
    printf("\n");
    releaseBinarySearchTree(tree);
}

int main()
{
    test01();


    return 0;
}

