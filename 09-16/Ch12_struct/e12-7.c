#include <stdio.h>

struct person {
    char name[20];
    char part[20];
    int age;
};
void per(struct person kk)
{
    printf("�̸�: %s\n", kk.name);
    printf("�μ�: %s\n", kk.part);
    printf("����: %d\n", kk.age);
}

int main()
{
    struct person kk;
    printf("�̸��� �Է��ϼ���");
    scanf("%s", kk.name);
    printf("\n�μ��� �Է��Ͻÿ�");
    scanf("%s", kk.part);
    printf("\n���̸� �Է��ϼ���");
    scanf("%d", &kk.age);

    per(kk);
    return 0;
}