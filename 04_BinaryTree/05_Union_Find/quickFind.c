#include "quickFind.h"

QuickFindSet *createQuickFindSet(int n)
{
    QuickFindSet * QFset = (QuickFindSet*) malloc(sizeof(QuickFindSet));
    QFset->data = (Element*) malloc(sizeof(Element) * n);
    QFset->group = (int*)malloc(sizeof(int) * n);
    QFset->capacity = n;
    QFset->n = 0;
    return QFset;
}

void releaseQuickFindSet(QuickFindSet *QFset)
{
    if(QFset)
    {
        free(QFset->data);
        free(QFset->group);
        free(QFset);
    }
}

void initQuickFindSet(QuickFindSet *QFset, const Element *data, int n)
{
    for(int i = 0; i < n; ++i)
    {
        QFset->data[i] = data[i];
        QFset->group[i] = i;
    }
    QFset->n = n;
}
static int findIndex(QuickFindSet* QFset, Element e)
{
    for(int i = 0; i < QFset->n; ++i)
    {
        if(QFset->data[i] == e)
        {
            return i;
        }
    }
    return -1;
}
void unionQuickFindSet(QuickFindSet *QFset, Element a, Element b)
{
    // 把b的老大们都合并到a
    int ID = QFset->group[findIndex(QFset,b)];
    for(int i = 0; i < QFset->n; ++i)
    {
        if(QFset->group[i] == ID)
        {
            QFset->group[i] = QFset->group[findIndex(QFset,a)];
        }
    }
}

int isSameQuickFindSet(QuickFindSet *QFset, Element a, Element b)
{
    int indexA = findIndex(QFset, a);
    int indexB = findIndex(QFset, b);

    return QFset->group[indexA] == QFset->group[indexB];
}
