/**************************************************************************************************/
/* Copyright (C) xxxxxxx.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  WangXianggang                                                        */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/15                                                           */
/*  DESCRIPTION           :  This is demo to show the mechanism of menu program                   */
/**************************************************************************************************/

/*
 * Revision log:
 * Created by Wxg, 2014/08/31
 */


#include <stdio.h>
#include <stdlib.h>

int Help();
int Version();
int Exit();

#define CMD_MAX_LEN 128
#define DESC_LEN    512
#define CMD_LEN     16

/* ths struct to hold the cmd data */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct DataNode * pNext;
} tDataNode;


/* find a cmd in the menu linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode * head, char * cmd)
{
    tDataNode * pNode = head;
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = pNode->pNext;
    }
    return NULL;
}


/* show all cmd in listlist */
int ShowAllCmd(tDataNode * head)
{
    tDataNode * pNode = head;
    while(pNode != NULL)
    {
        printf("%-12s - %s\n", pNode->cmd, pNode->desc);
        pNode = pNode->pNext;
    }
    return 0;
}


/* menu list */
static tDataNode data[] = 
{
    {"help", "this is help cmd!", Help, &data[1]},
    {"version", "menu program v1.0", Version, &data[2]},
    {"exit", "exit the menu", Exit, NULL},
};


tDataNode * head = NULL;


main()
{ 
    head = &data[0];

    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        /*printf("%-12s - %-50s\n", p->cmd, p->desc);*/

        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

/* show the cmd which the menu contains */
int Help()
{
    ShowAllCmd(head);
    return 0; 
}

/* show version information */
int Version()
{
    printf("version1.0 released 2014/09/15\n");
    return 0; 
}

/* exit the menu */
int Exit()
{
    exit(0);
    return 0;
}
