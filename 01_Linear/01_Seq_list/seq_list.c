
#include "seq_list.h"
static int findIndex(Seqlist* seq, Element e)
{
    for(int i = 0; i < seq->len; ++i)
    {
        if(seq->data[i] == e)
        {
            return i;
        }
    }
    return -1;
}
void releaseSeqlist(Seqlist *seq)
{
    if(seq)
    {
        if(seq->data)
        {
            free(seq->data);
        }
        free(seq);
    }

}

Seqlist *createSeqlist(int n)
{
    Seqlist *seq = (Seqlist*)malloc(sizeof(Seqlist));
    if(seq == NULL)
    {
        perror("malloc seq");
        return NULL;
    }
    seq->data = (Element*)malloc(sizeof(Element) * n);
    seq->capacity = n;
    seq->len = 0;

    return seq;
}

int push_back_Seqlist(Seqlist *seq, Element e)
{
    if(seq->len >= seq->capacity)
    {
        printf("full\n");
        return -1;
    }

    seq->data[seq->len] = e;
    ++seq->len;
    return 0;
}

void printSeqlist(Seqlist *seq)
{
    for(int i = 0; i < seq->len; ++i)
    {
        printf("%c\t", seq->data[i]);
    }
    printf("\n");

}

int delSeqlist(Seqlist *seq, Element e)
{
    int index = findIndex(seq, e);
    if(index == -1)
    {
        printf("not find\n");
        return -1;
    }
    for(int i = index + 1; i < seq->len; ++i)
    {
        seq->data[i - 1] = seq->data[i];
    }
    --seq->len;
    return 0;
}

int insertSeqlist(Seqlist *seq, int pos, Element e)
{
    if(seq->len >= seq->capacity)
    {
            printf("full\n");
    }
    for(int i = seq->len - 1; i >= pos; --i)
    {
        seq->data[i + 1] = seq->data[i];
    }
    seq->data[pos] = e;
    ++seq->len;
    return 0;
}
