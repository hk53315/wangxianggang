/**************************************************************************************************/
/* Copyright (C) xxxxxxx.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  WangXianggang                                                        */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is demo to show the mechanism of menu program                   */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wxg, 2014/09/21
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linktable.h"
#include"menu.h"

#define debug

typedef struct Node
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
    /*int data;*/
}DataNode;

DataNode * AddMenuItem(tLinkTable *pLinkTable, char* cmd, char* desc,int (*handler)());
int Help(tLinkTable *pLinkTable);
int Version(tLinkTable *pLinkTable);
int Exit(tLinkTable *pLinkTable);

DataNode * Search(tLinkTable *pLinkTable, char* cmd);
int SearchConditon(tLinkTableNode * pLinkTableNode);

int RunMenu(tLinkTable *pLinkTable, char *cmd)
{
    DataNode* pTempNode = Search(pLinkTable, cmd);
    if(NULL == pTempNode)
    {
        printf("This is a wrong cmd!\n");
        return;
    }
    pTempNode->handler(pLinkTable);
}


DataNode * Search(tLinkTable *pLinkTable, char* cmd)
{
    DataNode * pNode = (DataNode*)GetLinkTableHead(pLinkTable);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (DataNode*)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
    }
    return NULL;
}

DataNode * InitMenuItem(tLinkTable *pLinkTable)
{
    AddMenuItem(pLinkTable, "help", "this is help cmd!", Help);
    AddMenuItem(pLinkTable, "version", "menu program v1.0", Version);
    AddMenuItem(pLinkTable, "exit", "exit the menu", Exit);
}

DataNode * AddMenuItem(tLinkTable *pLinkTable, char* cmd, char* desc,int (*handler)())
{
    DataNode* pNode = (DataNode*)malloc(sizeof(DataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
}

int SearchConditon(tLinkTableNode * pLinkTableNode)
{
    DataNode * pNode = (DataNode *)pLinkTableNode;
    if(!strcmp(pNode->cmd, "help"))
    {
        return  SUCCESS;
    }
    return FAILURE;       
}


/* show the cmd which the menu contains */
int Help(tLinkTable *pLinkTable)
{
    DataNode * pNode = (DataNode*)GetLinkTableHead(pLinkTable);
    while(pNode != NULL)
    {
        printf("%-12s - %s\n", pNode->cmd, pNode->desc);
        pNode = (DataNode*)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
    }
    return 0; 
}

/* show version information */
int Version(tLinkTable *pLinkTable)
{
    printf("version1.0 released 2014/09/15\n");
    return 0; 
}

/* exit the menu */
int Exit(tLinkTable *pLinkTable)
{
    exit(0);
    return 0;
}

