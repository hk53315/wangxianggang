/**************************************************************************************************/
/* Copyright (C) xxxxxxx.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  WangXianggang                                                        */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is test of menu module                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wxg, 2014/09/21
 */

#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
#include"menu.h"

#define CMD_MAX_LEN 10

int add1(tLinkTable *pLinkTable);
int add2(tLinkTable *pLinkTable);

int main()
{
    int i;
    
    tLinkTable * pLinkTable = CreateLinkTable();
    /* init menu whih the common item, help, version, and exit */
    InitMenuItem(pLinkTable);

    /* Add new item to the exist menu dynamicly */
    AddMenuItem(pLinkTable, "add1", "add menu1", add1);
    AddMenuItem(pLinkTable, "add2", "add menu2", add1);

    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        /* call the func to run the menu */
        RunMenu(pLinkTable, cmd);
    }
    DeleteLinkTable(pLinkTable);
}

/* show version information */
int add1(tLinkTable *pLinkTable)
{
    printf("add menu one\n");
    return 0; 
}

int add2(tLinkTable *pLinkTable)
{
    printf("add menu two\n");
    return 0; 
}



