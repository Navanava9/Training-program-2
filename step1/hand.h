
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 30
#define CREATE_FILE_ERROR -3
#define OK 1

typedef struct User
{
    char name[LENGTH];
    int totalcount;
} DataType;

//链表的节点
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
} Node, *PNode;

PNode CreateNode(DataType data);
void PushBack(PNode *hand, DataType data);
void PopBack(PNode *hand);
void DestroyList(PNode *hand);
void ListTraverse(PNode hand);
PNode CombineList(PNode *hand);

PNode fileread(void);
int filewrite(PNode hand);


void QSort(PNode *hand);