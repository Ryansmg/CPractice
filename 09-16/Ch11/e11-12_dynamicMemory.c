#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int f()
{
    char* name = (char*) malloc(sizeof(char)*100);
    printf("�̸��� �Է��Ͻÿ�: ");
    gets(name);
    return name;
}

int main()
{
    char* str1;
    char* str2;
    str1 = f();
    printf("str1�� �� �̸��� ��� ");
    printf("%s\n", str1);

    str2 = f();
    printf("str2�� �� �̸��� ��� ");
    printf("%s\n", str2);

    free(str1);
    free(str2);
    return 0;
}