#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int transform(char *string)
{
    int num = 0;
    while (*string++)
        num = num * 10 + num - '0';
    return num;
}

PTreeNode fileread(void)
{
    char y;
    PTreeNode head = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\box\\code\\Training-program-2\\data.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        int x = 0, v = 0;
        DataType a;
        char s[LENGTH] = {0};
        char o[LENGTH] = {0};
        for (int i = 0; i < LENGTH; i++)
            a.name[i] = 0;
        fgets(s, LENGTH, user_login);
        while (1)
        {
            y = s[x];
            if (y == ',')
            {
                x++;
                break;
            }
            a.name[x] = y;
            x++;
        }
        while (1)
        {
            y = o[v];
            if (y == '\n')
                break;
            v++;
        }
        a.totalcount = transform(o);
        Insert(a, head);
    }
    fclose(user_login);
    return head;
}

PTreeNode fileread(void)
{
    char y;
    PTreeNode head = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\box\\code\\Training-program-2\\data.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        int x = 0, v = 0;
        DataType a;
        char s[LENGTH] = {0};
        char o[LENGTH] = {0};
        for (int i = 0; i < LENGTH; i++)
            a.name[i] = 0;
        fgets(s, LENGTH, user_login);
        while (1)
        {
            y = s[x];
            if (y == ',')
            {
                x++;
                break;
            }
            a.name[x] = y;
            x++;
        }
        while (1)
        {
            y = o[v];
            if (y == '\n')
                break;
            v++;
        }
        a.totalcount = transform(o);
        insert(head, a);
    }
    fclose(user_login);
    return head;
}