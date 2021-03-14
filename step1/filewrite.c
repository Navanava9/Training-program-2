#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int filewrite(PNode hand)
{
    FILE *out;
    PNode temp = hand;
    char c[LENGTH];
    out = fopen("result.txt", "w+");
    if (out == NULL)
        return CREATE_FILE_ERROR;
    while (1)
    {
        fputs(temp->data.name, out);
        fputc(',', out);
        itoa(temp->data.totalcount, c, 10);
        fputs(c, out);
        fputc('\n', out);
        temp = temp->next;
        if (temp->next == NULL)
        {
            fputs(temp->data.name, out);
            fputc(',', out);
            itoa(temp->data.totalcount, c, 10);
            fputs(c, out);
            break;
        }
    }
    fclose(out);
    return OK;
}