#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int height(PAVLNode N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

PAVLNode CreatNode(DataType data)
{
    PAVLNode node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->PLeft = NULL;
    node->PRight = NULL;
    node->height = 1;
    return node;
}

PAVLNode ll_rotate(PAVLNode y)
{
    PAVLNode x = y->PLeft;
    y->PLeft = x->PRight;
    x->PRight = y;

    y->height = max(height(y->PLeft), height(y->PRight)) + 1;
    x->height = max(height(x->PLeft), height(x->PRight)) + 1;

    return x;
}

PAVLNode rr_rotate(PAVLNode y)
{
    PAVLNode x = y->PRight;
    y->PRight = x->PLeft;
    x->PLeft = y;

    y->height = max(height(y->PLeft), height(y->PRight)) + 1;
    x->height = max(height(x->PLeft), height(x->PRight)) + 1;

    return x;
}

int getBalance(PAVLNode N)
{
    if (N == NULL)
        return 0;
    return height(N->PLeft) - height(N->PRight);
}

PAVLNode insert(PAVLNode node, DataType data)
{

    if (node == NULL)
        return CreatNode(data);

    if (data.totalcount < node->data.totalcount)
        node->PLeft = insert(node->PLeft, data);
    else if (data.totalcount > node->data.totalcount)
        node->PRight = insert(node->PRight, data);
    else
        return node;

    node->height = 1 + max(height(node->PLeft), height(node->PRight));

    int balance = getBalance(node);

    if (balance > 1 && data.totalcount < node->PLeft->data.totalcount) //LL型
        return ll_rotate(node);

    if (balance < -1 && data.totalcount > node->PRight->data.totalcount) //RR型
        return rr_rotate(node);

    if (balance > 1 && data.totalcount > node->PLeft->data.totalcount) //LR型
    {
        node->PLeft = rr_rotate(node->PLeft);
        return ll_rotate(node);
    }

    if (balance < -1 && data.totalcount < node->PRight->data.totalcount) //RL型
    {
        node->PRight = ll_rotate(node->PRight);
        return rr_rotate(node);
    }

    return node;
}

PAVLNode minValueNode(PAVLNode node)
{
    PAVLNode current = node;

    while (current->PLeft != NULL)
        current = current->PLeft;

    return current;
}

PAVLNode deleteNode(PAVLNode root, DataType data)
{

    if (root == NULL)
        return root;

    if (data.totalcount < root->data.totalcount)
        root->PLeft = deleteNode(root->PLeft, data);

    else if (data.totalcount > root->data.totalcount)
        root->PRight = deleteNode(root->PRight, data);

    else
    {
        if ((root->PLeft == NULL) || (root->PRight == NULL))
        {
            PAVLNode temp = root->PLeft ? root->PLeft : root->PRight;

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
            PAVLNode temp = minValueNode(root->PRight);

            root->data = temp->data;

            root->PRight = deleteNode(root->PRight, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->PLeft), height(root->PRight));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->PLeft) >= 0) //LL型
        return ll_rotate(root);

    if (balance > 1 && getBalance(root->PLeft) < 0) //LR型
    {
        root->PLeft = rr_rotate(root->PLeft);
        return ll_rotate(root);
    }

    if (balance < -1 && getBalance(root->PRight) <= 0) //RR型
        return rr_rotate(root);

    if (balance < -1 && getBalance(root->PRight) > 0) //Rl型
    {
        root->PRight = ll_rotate(root->PRight);
        return rr_rotate(root);
    }

    return root;
}

void DestroyAVL(PAVLNode *pRoot)
{
    if (*pRoot)
    {
        DestroyAVL(&(*pRoot)->PLeft);
        DestroyAVL(&(*pRoot)->PRight);
        free(*pRoot);
        *pRoot = NULL;
    }
    else
        return;
}