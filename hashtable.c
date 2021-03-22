#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

// 定义一个哈希表的节点
typedef struct HarshNode
{
    DataType key;
    int Value;
    HarshNode *pNext;
} HarshNode, *PHarshNode;

//初始化哈希表
PHarshNode *HarshInit(void)
{
    PHarshNode harshTable[TABIESIZE] = memset(harshTable, 0, sizeof(HarshNode *) * TABIESIZE);
    return harshTable;
}

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

void HarshInsert(DataType Key)
{
    PHarshNode *harshTable = HarshInit();
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
