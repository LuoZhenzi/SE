#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
struct LinkTable
{
    tLinkTableNode* pHead;
    tLinkTableNode* pTail;
    int SumOfNode;
};
tLinkTable* CreateLinkTable()
{
    tLinkTable* pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if (pLinkTable == NULL)
        return NULL;
    pLinkTable -> pHead = NULL;
    pLinkTable -> pTail = NULL;
    pLinkTable -> SumOfNode = 0;
    return pLinkTable;
}
int DeleteLinkTable(tLinkTable* pLinkTable)
{
    if (pLinkTable == NULL)
        return FAILURE;
    while (pLinkTable -> pHead != NULL)
    {
        tLinkTableNode* p = pLinkTable -> pHead;
        pLinkTable -> pHead = pLinkTable -> pHead -> pNext;
        pLinkTable -> SumOfNode -= 1;
        free(p);
    }
    pLinkTable -> pHead = NULL;
    pLinkTable -> pTail = NULL;
    pLinkTable -> SumOfNode = 0;
    free(pLinkTable);
    return SUCCESS;
}
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
        return FAILURE;
    pNode -> pNext = NULL;
    if (pLinkTable -> pHead == NULL)
        pLinkTable -> pHead = pNode;
    if (pLinkTable -> pTail == NULL)
        pLinkTable -> pTail = pNode;
    else
    {
        pLinkTable -> pTail -> pNext = pNode;
        pLinkTable -> pTail = pNode;
    }
    pLinkTable -> SumOfNode += 1;
    return SUCCESS;
}
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
        return FAILURE;
    if (pLinkTable -> pHead == pNode)
    {
        pLinkTable -> pHead = pLinkTable -> pHead -> pNext;
        pLinkTable -> SumOfNode -= 1;
        if (pLinkTable -> SumOfNode == 0)
            pLinkTable -> pTail = NULL;
        return SUCCESS;
    }
    tLinkTableNode* pTempNode = pLinkTable -> pHead;
    while (pTempNode != NULL)
    {
        if (pTempNode -> pNext == pNode)
        {
            pTempNode -> pNext = pTempNode -> pNext -> pNext;
            pLinkTable -> SumOfNode -= 1;
            if (pLinkTable -> SumOfNode == 0)
                pLinkTable -> pTail = NULL;
            return SUCCESS;
        }
        pTempNode = pTempNode -> pNext;
    }
    return FAILURE;
}
tLinkTableNode* SearchLinkTableNode(tLinkTable* pLinkTable, int
Condition(tLinkTableNode* pNode, void* args), void* args)
{
    if (pLinkTable == NULL || Condition == NULL)
        return NULL;
    tLinkTableNode* pNode = pLinkTable -> pHead;
    while (pNode != NULL)
    {
        if (Condition(pNode, args) == SUCCESS)
            return pNode;
        pNode = pNode -> pNext;
    }
    return NULL;
}
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable)
{
    if (pLinkTable == NULL)
        return NULL;
    return pLinkTable -> pHead;
}
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode*
pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
        return NULL;
    tLinkTableNode* pTempNode = pLinkTable -> pHead;
    while (pTempNode != NULL)
    {
        if (pTempNode == pNode)
            return pTempNode -> pNext;
        pTempNode = pTempNode -> pNext;
    }
    return NULL;
}
