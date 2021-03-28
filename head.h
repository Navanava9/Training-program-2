#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 30
#define TABIESIZE 1000
#define BASE 31

typedef struct User
{
    char name[LENGTH];
    int totalcount;
} DataType;

typedef struct TreeNode
{
    DataType data;
    struct TreeNode *PLeft;
    struct TreeNode *Pright;
} TreeNode, *PTreeNode;

typedef struct AVLNode
{
    DataType data;
    int height;
    struct TreeNode *PLeft;
    struct TreeNode *PRight;
} AVLNode, *PAVLNode;

typedef struct HarshNode
{
    DataType key;
    int Value;
    struct HarshNode *pNext;
} HarshNode, *PHarshNode;

PAVLNode fileread(void);
PTreeNode Fileread(void);
PHarshNode HarshFileread(void);

void DestroyBSTree(PTreeNode *pRoot);
int Delete(PTreeNode *Root, DataType a);
void Insert(PTreeNode *root, DataType a);
void ProOrderTraversal(PTreeNode T);

PAVLNode insert(PAVLNode node, DataType data);
PAVLNode deleteNode(PAVLNode root, DataType data);
void DestroyAVL(PAVLNode *pRoot);

void HarshInsert(DataType Key, PHarshNode *HarshTable);
void DestoryHarsh(PHarshNode *HarshTable);
PHarshNode FindHarshNode(char *Key, PHarshNode *HarshTable);
PHarshNode *HarshInit(void);