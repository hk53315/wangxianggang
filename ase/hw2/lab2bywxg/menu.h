/**************************************************************************************************/
/* Copyright (C) xxxxxxx.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  WangXianggang                                                        */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is menu's head file                                             */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wxg, 2014/09/21
 */

#ifndef _MENU_H_
#define _MENU_H_

/*
 * MenuItem Type
 */
typedef struct Node DataNode;
/*
 * Add the menuitem according the user's requirement
 */
DataNode * AddMenuItem(tLinkTable *pLinkTable, char* cmd, char* desc,int (*handler)());

/*
 * Add some common menuitem to the menubar
 */
DataNode * InitMenuItem(tLinkTable *pLinkTable);

/*
 * Run the menu according the cmd
 */
int RunMenu(tLinkTable *pLinkTable, char *cmd);

#endif /* _LINK_TABLE_H_ */
