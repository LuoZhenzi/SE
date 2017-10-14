#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#define SUCCESS 0
#define FAILURE (-1)
typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
}tLinkTableNode;
typedef struct LinkTable tLinkTable;
tLinkTable *CreateLinkTable();
int DeleteLinkTable(tLinkTable *pLinkTable);
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode
*pNode);
#endif
