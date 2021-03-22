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

//根据键值对向哈希表中添加节点，如果key已经存在则直接更新键值
void HarshInsert(DataType Key)
{
    PHarshNode *harshTable = HarshInit();
    PHarshNode pHarshNodeHead = NULL;
    PHarshNode pNewNode = NULL;

    int pos = HarshKey(Key.name) % TABIESIZE;

    pHarshNodeHead = harshTable[pos];

    while (NULL != pHarshNodeHead) // 如果这个位置对应的不是这一串中最后一个节点的话，那就要向后移动了
    {
        if (strcmp(pHarshNodeHead->key.name, Key.name) == 0) //如果这个键值对已经存在，只更新键值即可
        {
            pHarshNodeHead->key = Key;
            return 0;
        }
        pHarshNodeHead = pHarshNodeHead->pNext; //向后移动,肯定会有NULL的时候
    }

    pNewNode = (HarshNode *)malloc(sizeof(HarshNode));
    if (NULL == pNewNode)
        return;
    memset(pNewNode, 0, sizeof(HarshNode));

    pNewNode->key.name = (char *)malloc(strlen(Key.name) + 1); //申请一块Key大小的内存
    memset(pNewNode->key.name, 0, strlen(Key.name) + 1);

    strcpy(pNewNode->key.name, Key.name); //将Key的内容赋给 pNewNode -> Key
    pNewNode->= ;               //键值也复制过来

    pNewNode->pNext = NULL; //由于是新节点，也是尾节点，所以pNext指向NULL

    pHarshNodeHead = pNewNode;
    harshTable[pos] = pHarshNodeHead; //最后一定要让数组中的这个位置指向这个头指针

    g_harsh_table_size++;

    return 0;
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
