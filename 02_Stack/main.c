
#include "Linkstack.h"

#define N 5
void test01()
{
    Linkstack * stack = createLinkstack();
    if(stack == NULL)
    {
        perror("stack");
        return;
    }
    for(int i =11; i < 21; ++i)
    {
        pushLinkstack(stack, i);
    }
    Element e;

    TraverseStack(stack);
    while(popLinkstack(stack, &e) != -1)
    {
        printf("%d\t", e);
    }
    printf("\n");

    TraverseStack(stack);


    releaseLinkstack(stack);


}
int main()
{
    test01();


    return 0;
}

