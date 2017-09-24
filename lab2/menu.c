#include <stdio.h>
#include <stdlib.h>
void help();
void hello();
void add();
void sub();

int main()
{
    char cmd[128];
    while (1)
    {
        printf("Menu: ");
        scanf("%s", cmd);
        if (strcmp(cmd, "help") == 0)
            help();
        else if (strcmp(cmd, "hello") == 0)
            hello();
        else if (strcmp(cmd, "date") == 0)
            system(cmd);
        else if (strcmp(cmd, "ls") == 0)
            system(cmd);
        else if (strcmp(cmd, "add") == 0)
            add();
        else if (strcmp(cmd, "sub") == 0)
            sub();
        else if (strcmp(cmd, "exit") == 0)
            exit(0);
        else
            printf("Wrong! You can use help to get help.\n");
    }
}

void help()
{
    printf("help\tget help\n");
    printf("hello\tsay hello\n");
    printf("date\tshow date\n");
    printf("ls\tlist files\n");
    printf("add\taddition operation\n");
    printf("sub\tsubtraction operation\n");
    printf("exit\texit this program\n");
}

void hello()
{
    printf("Hello, Da Lao!\nPlease give me a high score!\n");
}

void add()
{
    int a, b, add;
    printf("Please input to integers: ");
    scanf("%d%d", &a, &b);
    add = a + b;
    printf("%d\n", add);
}

void sub()
{
    int a, b, sub;
    printf("Please input to integers: ");
    scanf("%d%d", &a, &b);
    sub = a - b;
    printf("%d\n",  sub);
}
