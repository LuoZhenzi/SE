typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
} tDataNode;

tDataNode* FindCmd(tDataNode* head, char* cmd);

int showallcmd(tDataNode* head);
