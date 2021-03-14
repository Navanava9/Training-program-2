#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char y;
    PNode hand = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\box\\code\\Training-program-2\\step1\\data.txt", "r");
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
        PushBack(&hand, a);
    }
    fclose(user_login);
    return hand;
}