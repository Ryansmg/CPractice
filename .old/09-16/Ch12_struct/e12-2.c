#include <stdio.h>

struct sungjuk
{
    char name[15];
    int kor;
    int eng;
    int computer;
    int tot;
    float ave;
};

int main()
{
    struct sungjuk soo;
    printf("�̸�: "); gets(soo.name);
    printf("����: "); scanf(" %d", &soo.kor);
    printf("����: "); scanf(" %d", &soo.eng);
    printf("��ǻ��: "); scanf(" %d", &soo.computer);

    soo.tot = soo.kor + soo.eng + soo.computer;
    soo.ave = soo.tot / 3.;

    printf("�̸� :%s\n����: %d\n����: %d\n��ǻ��: %d\n", soo.name, soo.kor, soo.eng, soo.computer);
    printf("����: %d ���: %.0f\n", soo.tot, soo.ave);
}