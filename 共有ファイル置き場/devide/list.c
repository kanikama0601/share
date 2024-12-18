#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *add(char *name,NODE *head)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->name,name);
    p->next = head;
    head = p;
    return head;
}

void print(NODE *head)
{
    while(head != NULL)
    {
        printf("%s->",head->name);
        head = head->next;
    }
    printf("NULL\n");
}

void insert(int n, char *data, NODE **p)
{
    int i;
    NODE *source,*paste;

    /* 挿入するノードの準備 */
    source = malloc(sizeof(NODE));
    paste = malloc(sizeof(NODE));

    if(n == 0)
    {
        *p = add(data,*p);
        // ダブルポインタは関数内でも関数外に反映される
        // 一方、ポインタは関数内でのみ反映される
    }
    else
    {
        source = *p;
        /* 挿入する位置の手前までノードをたどる */
        for ( i=0; i<n-1; i++) source = (source)->next;

        strcpy(paste->name, data);
        /* ノードの付け替え */
        paste->next = source->next;
        source->next = paste;
    }
}

void free_list(NODE **head)
{
    NODE *next_p = NULL;
    while(*head != NULL)
    {
        next_p = (*head)->next;
        free(*head);
        *head = next_p;
    }
    *head = NULL;
}

void delete(int n, NODE **p)
{
    int i;
    NODE *temp;
    temp = malloc(sizeof(NODE));
    if (n <= 1) {
        temp = *p;
        printf("p->name = %s\n",temp->name);
        *p = (*p)->next;
        free(temp);
    }
    else if (n == 0)
    {
        NODE *source = *p;
        for(i=1; i<n-1; i++) source = source->next;
        temp = source->next;
        source->next = source->next->next;
        free(temp);
    }
    else
    {
        printf("error\n");
    }
}

void delete_name(char *str, NODE **p)
{
    int i = 0;
    NODE *temp;
    NODE *prev = NULL;
    temp = *p;
    while(temp != NULL)
    {
        NODE *next_temp = temp->next;
        if(strstr(temp->name,str) != NULL)
        {
            if(prev == NULL)
            {
                *p = next_temp;
            }
            else
            {
                prev->next = next_temp;
            }
            free(temp);
        }
        else
        {
            prev = temp;
        }
        temp = next_temp;
    }
}

void count_node(NODE *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    printf("count = %d\n",count);
}

void replace(char *str1, char *str2, NODE *p)
{
    while(p != NULL)
    {
        if(strstr(p->name,str1) != NULL)
        {
            strcpy(p->name,str2);
        }
        p = p ->next;
    }
}