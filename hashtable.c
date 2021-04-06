#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int HarshKey(char *Key)
{
    int num = strlen(Key);
    int value = 0;
    for (int i = 0; i < num; i++)
    {
        value += Key[i] * (BASE ^ i);
    }
    return value;
}

void HarshInsert(DataType Key, PHarshNode *harshTable)
{
    PHarshNode pHarshNodeHead = NULL;
    PHarshNode pNewNode = NULL;

    int pos = HarshKey(Key.name) % TABIESIZE;

    pHarshNodeHead = harshTable[pos];

    while (NULL != pHarshNodeHead)
        pHarshNodeHead = pHarshNodeHead->pNext;

    pNewNode = (HarshNode *)malloc(sizeof(HarshNode));
    if (NULL == pNewNode)
        return;
    pNewNode->key = Key;

    pNewNode->pNext = NULL;

    pHarshNodeHead = pNewNode;
    harshTable[pos] = pHarshNodeHead;
}

// 根据键值Key来查找对应的哈希节点
PHarshNode FindHarshNode(char *Key, PHarshNode *HarshTable)
{
    PHarshNode pHarshHead = NULL;
    if (NULL == Key)
        return NULL;

    int pos = HarshKey(Key) % TABIESIZE;

    pHarshHead = HarshTable[pos];

    while (NULL != pHarshHead)
    {
        if (strcmp(Key, pHarshHead->key.name) == 0)
            return pHarshHead;

        pHarshHead = pHarshHead->pNext;
    }
    return NULL;
}

void DestoryHarsh(PHarshNode *HarshTable)
{
    PHarshNode pHarshHead = NULL;
    PHarshNode tmp = NULL;
    for (int i = 0; i < TABIESIZE; i++)
    {
        pHarshHead = HarshTable[i];
        while (pHarshHead != NULL)
        {
            tmp = pHarshHead;
            pHarshHead = pHarshHead->pNext;
            free(tmp);
        }
    }
}
