#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("output.txt", "w");

    if(fp == NULL){
        printf("���� ���� ����\n");
        return 1;
    }

    fputs("���ڿ� ����ϱ�\n", fp);
    fputs("�� ������ ����ϱ�", fp);

    fclose(fp);
    return 0;
}