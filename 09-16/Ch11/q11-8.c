#include <stdio.h>
#include <string.h>

int main()
{
    int type, i;
    char input[100];
    char *korDict[5] = {"å", "��ǻ��", "���α׷�", "Ű����", "���콺"};
    char *engDict[5] = {"book", "computer", "program", "keyboard", "mouse"};
    printf("(���� : 1, �ѿ� : 2): ");
    scanf(" %d", &type);
    if(type==1)
    {
        printf("���� �ܾ �Է��ϼ���: ");
        scanf(" %s", input);
        for(i=0; i<5; i++)
        {
            if(strcmp(engDict[i], input) == 0)
            {
                printf("'%s'�� �ѱ۷� '%s'�Դϴ�.", input, korDict[i]);
            }
        }
    }
    else if(type==2)
    {
        printf("�ѱ� �ܾ �Է��ϼ���: ");
        scanf(" %s", input);
        for(i=0; i<5; i++)
        {
            if(strcmp(korDict[i], input) == 0)
            {
                printf("'%s'�� ����� '%s'�Դϴ�.", input, engDict[i]);
            }
        }
    }
}