#include <stdio.h>

struct person {
    char name[20];
    char part[20];
    int age;
};
void per(struct person *kk)
{
    int i;
    for(i=0; i<3; i++){
        printf("�̸�: %s\n", kk->name);
        printf("�μ�: %s\n", kk->part);
        printf("����: %d\n", kk->age);
        kk++;
    }
}

int main()
{
    struct person kk[3];
    int i;
    for(i=0; i<3; i++){
    printf("�̸��� �Է��ϼ���");
    scanf("%s", kk[i].name);
    printf("\n�μ��� �Է��Ͻÿ�");
    scanf("%s", kk[i].part);
    printf("\n���̸� �Է��ϼ���");
    scanf("%d", &kk[i].age);
    }

    per(kk);
    return 0;
}