#include <stdio.h>
struct sung {
    char name[20];
    int kor;
    int eng;
    int mat;
    int tot;
};
int main()
{
    struct sung kk[5];
    int i;
    printf("�̸� ���� ���� ����\n");
    for(i=0; i<5; i++){
        {
            scanf("%s %d %d %d", kk[i].name, &kk[i].kor, &kk[i].eng, &kk[i].mat);
            kk[i].tot = kk[i].kor + kk[i].eng + kk[i].mat;
        }
    }
    
    printf("���� ��Ȳ \n");
    printf("�̸� ���� ���� ����\n");
    for(i=0; i<5; i++)
    {
        printf("%s %5d %5d %5d %5d\n", kk[i].name, kk[i].kor, kk[i].eng, kk[i].mat, kk[i].tot);
    }

    return 0;
}