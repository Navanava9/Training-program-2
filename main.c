#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int main(void)
{
    PTreeNode bst;
    bst = Fileread();
    ProOrderTraversal(bst);
    DestroyBSTree(&bst);

    return 0;
}