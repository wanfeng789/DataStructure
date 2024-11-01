
#ifndef DS_SEQ_LIST_H
#define DS_SEQ_LIST_H
#include <stdlib.h>
#include <stdio.h>
typedef char Element;
typedef struct
{
    Element *data;
    int capacity;
    int len;
}Seqlist;

Seqlist * createSeqlist(int n);
void releaseSeqlist(Seqlist* seq);

// 尾插法
int push_back_Seqlist(Seqlist* seq, Element e);
int delSeqlist(Seqlist* seq, Element e);
void printSeqlist(Seqlist* seq);
int insertSeqlist(Seqlist* seq, int pos, Element e);
#endif //DS_SEQ_LIST_H
