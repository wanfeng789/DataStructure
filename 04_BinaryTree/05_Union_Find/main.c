#include "quickFind.h"
#include "quickUnion.h"

void test01()
{
    QuickFindSet * QFset = createQuickFindSet(16);
    Element data[9];
    memset(data, 0, sizeof(data));
    for(int i = 0; i < 9; ++i)
    {
        data[i] = '0' + i;
    }
    initQuickFindSet(QFset, data, 9);
    unionQuickFindSet(QFset, '3', '4');
    unionQuickFindSet(QFset, '8', '0');
    unionQuickFindSet(QFset, '2', '3');
    unionQuickFindSet(QFset, '5', '6');
    if(isSameQuickFindSet(QFset, '0', '2'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }    if(isSameQuickFindSet(QFset, '2', '4'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    unionQuickFindSet(QFset, '5', '1');
    unionQuickFindSet(QFset, '7', '3');
    unionQuickFindSet(QFset, '1', '6');
    unionQuickFindSet(QFset, '4', '8');
    if(isSameQuickFindSet(QFset, '0', '2'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    if(isSameQuickFindSet(QFset, '2', '4'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
void test02()
{
    QuickUnionSet * QUset = createQuickUnionSet(16);
    value_t data[9];
    memset(data, 0, sizeof(data));
    for(int i = 0; i < 9; ++i)
    {
        data[i] = '0' + i;
    }
    initQuickUnionSet(QUset, data, 9);
    unionQuickUnionSet(QUset, '3', '4');
    unionQuickUnionSet(QUset, '8', '0');
    unionQuickUnionSet(QUset, '2', '3');
    unionQuickUnionSet(QUset, '5', '6');
    if(isSameQuickUnionSet(QUset, '0', '2'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    if(isSameQuickUnionSet(QUset, '2', '4'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    unionQuickUnionSet(QUset, '5', '1');
    unionQuickUnionSet(QUset, '7', '3');
    unionQuickUnionSet(QUset, '1', '6');
    unionQuickUnionSet(QUset, '4', '8');
    if(isSameQuickUnionSet(QUset, '0', '2'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    if(isSameQuickUnionSet(QUset, '2', '4'))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    releaseQuickUnionSet(QUset);
}
int main()
{
    test02();
    return 0;
}
