#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int main(void)
{
    /* 
    PTreeNode bst;
    bst = Fileread();
    DestroyBSTree(&bst);
    */

    PAVLNode avl;
    avl = fileread();
    DestroyAVL(&avl);

    return 0;
}