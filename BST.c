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

PTreeNode _minValueNode(PTreeNode node)
{
    PTreeNode current = node;

    while (current->PLeft != NULL)
        current = current->PLeft;

    return current;
}

PTreeNode Delete(PTreeNode root, DataType data)
{

    if (root == NULL)
        return root;

    if (data.totalcount < root->data.totalcount)
        root->PLeft = Delete(root->PLeft, data);

    else if (data.totalcount > root->data.totalcount)
        root->Pright = Delete(root->Pright, data);

    else
    {
        if ((root->PLeft == NULL) || (root->Pright == NULL))
        {
            PTreeNode temp = root->PLeft ? root->PLeft : root->Pright;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            PTreeNode temp = _minValueNode(root->Pright);

            root->data = temp->data;

            root->Pright = Delete(root->Pright, temp->data);
        }
    }
    return root;
}