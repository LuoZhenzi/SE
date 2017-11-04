#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
int Quit(int argc, char* argv[])
{
    exit(0);
}
int Add(int argc, char* argv[])
{
    if(argc !=3)
    {
        printf("Please input two integers!\n");
        return 0;
    }
    printf("%s + %s = %d\n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]));
    return 0;
}
int Sub(int argc, char* argv[])
{
    if(argc !=3)
    {
        printf("Please input two integers!\n");
        return 0;
    }
    printf("%s - %s = %d\n", argv[1], argv[2], atoi(argv[1]) - atoi(argv[2]));
    return 0;
}
int main(int argc, char* argv[])
{
    SetPrompt("Menu >> ");
    MenuConfig("version", "Menu v7.0", NULL);
    MenuConfig("quit", "quit from Menu", Quit);
    MenuConfig("add", "add two integers", Add);
    MenuConfig("sub", "sub two integers", Sub);
    ExecuteMenu();
}
