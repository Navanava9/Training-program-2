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

//打印数组中对应的某个位置的那一串哈希值
void print_harsh_node(int pos)
{
    HarshNode *pHarshNodeHead = NULL;

    if (pos >= TABIESIZE)
        return;

    pHarshNodeHead = harshTable[pos];

    if (NULL == pHarshNodeHead)
        printf("NULL == pHarshNodeHead\n");
    while (NULL != pHarshNodeHead)
    {
        printf("come here \n");
        printf("Position:%d, Key:%s, :%d \n", pos, pHarshNodeHead->Key, pHarshNodeHead->);
        pHarshNodeHead = pHarshNodeHead->pNext;
    }
}

// 根据键值Key来查找对应的哈希节点
HarshNode *harsh_table_lookup(const char *Key)
{
    unsigned int pos = 0x0;
    HarshNode *pHarshHead = NULL;

    if (NULL == Key)
    {
        return NULL;
    }

    pos = HarshKey(Key) % TABIESIZE; //计算出在哈希数组中的位置

    pHarshHead = harshTable[pos];

    while (NULL != pHarshHead)
    {
        if (strcmp(Key, pHarshHead->Key) == 0) //找到了
            return pHarshHead;

        pHarshHead = pHarshHead->pNext; // 没有找到的话来到下一个节点
    }

    return NULL;
}
