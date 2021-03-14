#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

PTreeNode fileread(void)
{
    char y;
    PTreeNode head = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\box\\code\\Training-program-2\\user_login.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        int x = 0;
        DataType a;
        char s[LENGTH] = {0};
        for (int i = 0; i < LENGTH; i++)
            a.name[i] = 0;
        fgets(s, LENGTH, user_login);
        while (1)
        {
            y = s[x];
            if (y == ',')
                break;
            a.name[x] = y;
            x++;
        }
        a.totalcount = 1;
        Insert(a,head);
    }
    fclose(user_login);
    return head;
}