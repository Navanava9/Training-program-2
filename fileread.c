#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

PTreeNode Fileread(void)
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
            if (y == ',' || y == '\0')
            {
                x++;
                break;
            }
            a.name[x] = y;
            x++;
        }
        while (1)
        {
            y = s[x];
            if (y == '\n' || y == '\0')
                break;
            o[v] = y;
            v++;
            x++;
        }
        a.totalcount = atoi(o);
        Insert(a, head);
    }
    fclose(user_login);
    return head;
}

PAVLNode fileread(void)
{
    char y;
    PAVLNode head = NULL;
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
            if (y == ',' || y == '\0')
            {
                x++;
                break;
            }
            a.name[x] = y;
            x++;
        }
        while (1)
        {
            y = s[x];
            if (y == '\n' || y == '\0')
                break;
            o[v] = y;
            v++;
            x++;
        }
        a.totalcount = atoi(o);
        insert(head, a);
    }
    fclose(user_login);
    return head;
}

/*PHarshNode HarshFileread(void)
{
    char y;
    PHarshNode *head = HarshInit();
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
            if (y == ','|| y == '\0')
            {
                x++;
                break;
            }
            a.name[x] = y;
            x++;
        }
        while (1)
        {
            y = s[x];
            if (y == '\n'|| y == '\0')
                break;
            o[v] = y;
            v++;
            x++;
        }
        a.totalcount = atoi(o);
        HarshInsert(a, head);
    }
    fclose(user_login);
    return head;
}*/