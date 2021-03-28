#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

void ProOrderTraversal(PTreeNode T)
{
    if (T)
    {
        printf("%s ", T->data.name);
        ProOrderTraversal(T->PLeft);
        ProOrderTraversal(T->Pright);
    }
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

void Get(PTreeNode root, char Key[], PTreeNode tar)
{
    if (!root)
        return;
    if (strcmp(Key, root->data.name))
    {
        tar = root;
        return;
    }
    Get(root->PLeft, Key, tar);
    Get(root->Pright, Key, tar);
}

void Insert(PTreeNode *root, DataType a)
{
    if (!(*root))
    {
        (*root) = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->data = a;
        (*root)->PLeft = (*root)->Pright = NULL;
        return;
    }
    PTreeNode Temp = (PTreeNode)malloc(sizeof(TreeNode));
    PTreeNode Go = (*root);
    while (Go)
    {
        if (Go->data.totalcount > a.totalcount)
        {
            if (!Go->PLeft)
            {
                Temp->data = a;
                Temp->PLeft = Temp->Pright = NULL;
                Go->PLeft = Temp;
                return;
            }
            else
                Go = Go->PLeft;
        }
        else
        {
            if (!Go->Pright)
            {
                Temp->data = a;
                Temp->PLeft = Temp->Pright = NULL;
                Go->Pright = Temp;
                return;
            }
            else
                Go = Go->Pright;
        }
    }
}

int Delete(PTreeNode *Root, DataType a)
{
    if (strcmp((*Root)->data.name, a.name))
    {
        if (!(*Root)->PLeft && (*Root)->Pright)
        {
            (*Root) = (*Root)->Pright;
            free((*Root));
            return 1;
        }
        else if ((*Root)->PLeft && !(*Root)->Pright)
        {
            (*Root) = (*Root)->PLeft;
            free((*Root));
            return 1;
        }
        PTreeNode Min = (PTreeNode)malloc(sizeof(TreeNode));
        Min = (*Root)->Pright;
        PTreeNode ParentMin = (PTreeNode)malloc(sizeof(TreeNode));
        ParentMin = (*Root);
        while (Min->PLeft)
        {
            ParentMin = Min;
            Min = Min->PLeft;
        }
        ParentMin->PLeft = Min->Pright;
        Min->PLeft = (*Root)->PLeft;
        Min->Pright = (*Root)->Pright;
        (*Root) = Min;
        return 1;
    }
    PTreeNode Parent = (*Root);
    PTreeNode Go = (*Root);
    while (Go)
    {
        if (Go->data.totalcount == a.totalcount)
            break;
        else if (Go->data.totalcount > a.totalcount)
        {
            Parent = Go;
            Go = Go->PLeft;
        }
        else
        {
            Parent = Go;
            Go = Go->Pright;
        }
    }
    if (!Go)
        return -1;
    if (!Go->PLeft && Go->Pright)
    {
        if (Parent->PLeft == Go)
            Parent->PLeft = Go->Pright;
        else
            Parent->Pright = Go->Pright;
        free(Go);
        return 1;
    }
    else if (Go->PLeft && !Go->Pright)
    {
        if (Parent->PLeft == Go)
            Parent->PLeft = Go->PLeft;
        else
            Parent->Pright = Go->PLeft;
        free(Go);
        return 1;
    }
    else if (!Go->PLeft && !Go->Pright)
    {
        if (Parent->PLeft == Go)
            Parent->PLeft = NULL;
        else
            Parent->Pright = NULL;
        free(Go);
        return 1;
    }
    else
    {
        PTreeNode Min = (PTreeNode)malloc(sizeof(TreeNode));
        Min = Go->Pright;
        PTreeNode ParentMin = (PTreeNode)malloc(sizeof(TreeNode));
        ParentMin = Go;
        while (Min->PLeft)
        {
            ParentMin = Min;
            Min = Min->PLeft;
        }
        if (Parent->PLeft == Go)
        {
            Parent->PLeft = Min;
            ParentMin->PLeft = Min->Pright;
            Min->PLeft = Go->PLeft;
            Min->Pright = Go->Pright;
        }
        else
        {
            Parent->Pright = Min;
            ParentMin->PLeft = Min->Pright;
            Min->PLeft = Go->PLeft;
            Min->Pright = Go->Pright;
        }
    }
    return 1;
}//返回值-1表示删除非法.1代表成功.