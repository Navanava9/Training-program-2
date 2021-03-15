#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

PTreeNode FindMin(PTreeNode T)
{
    if (!T)
        return NULL;
    else if (!T->PLeft)
        return T;
    else
        return FindMin(T->PLeft);
}

PTreeNode FindMax(PTreeNode T)
{
    if (T)
    {
        while (T->Pright)
            T = T->Pright;
    }
    return T;
}

void ProOrderTraversal(PTreeNode T)
{
    if (T)
    {
        printf("%d ", T->data);
        ProOrderTraversal(T->PLeft);
        ProOrderTraversal(T->Pright);
    }
}

PTreeNode Insert(DataType data, PTreeNode T)
{
    if (!T)
    {
        T = (PTreeNode *)malloc(sizeof(PTreeNode));
        T->data = data;
        T->PLeft = T->Pright = NULL;
    }
    else if (data.totalcount > T->data.totalcount)
        T->Pright = Insert(data, T->Pright);
    else if (data.totalcount < T->data.totalcount)
        T->PLeft = Insert(data, T->PLeft);
    else
        printf("Element already exists, insert failed!");
    return T;
}

PTreeNode Delete(DataType data, PTreeNode T)
{
    PTreeNode Tmp;

    if (!T)
        printf("Element to be deleted not found!");
    else if (data.totalcount > T->data.totalcount)
        T->Pright = Delete(data, T->Pright);
    else if (data.totalcount < T->data.totalcount)
        T->PLeft = Delete(data, T->PLeft);
    else if (T->PLeft && T->Pright)
    {
        Tmp = FindMax(T->PLeft);
        T->data = Tmp->data;
        T->PLeft = Delete(T->data, T->PLeft);
    }
    else
    {
        Tmp = T;
        if (!T->Pright)
            T = T->PLeft;
        else if (!T->PLeft)
            T = T->Pright;
        free(Tmp);
    }
    return T;
}

void DestroyBSTree(PTreeNode *pRoot)
{
    if (*pRoot)
    {
        DestroyBSTree(&(*pRoot)->PLeft);
        DestroyBSTree(&(*pRoot)->Pright);
        free(*pRoot);
        *pRoot = NULL;
    }
    else
        return;
}

PTreeNode Find(char *tar, PTreeNode T)
{
    if (!strcmp(tar, T->data.name))
        return T;
    if (!T)
        return;
    if (strcmp(tar, T->PLeft->data.name))
        return Find(tar, T->PLeft);
    if (strcmp(tar, T->Pright->data.name))
        return Find(tar, T->Pright->data.name);
    return;
}