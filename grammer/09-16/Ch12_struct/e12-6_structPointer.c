#include <stdio.h>
struct sin {
    char name[20];
    int kor;
    int eng;
    int mat;
    int tot;
    float avg;
};

int main() 
{
    struct sin kk= {"�Ǳ⼮", 100, 100, 100};
    struct sin *pt;
    pt = &kk;
    (*pt).tot = (*pt).kor + (*pt).eng + (*pt).mat;
    (*pt).avg = (*pt).tot/3.0f;
    printf("���� = %5d  ��� = %.2f \n", kk.tot, kk.avg);
    //(*pt).kor�� pt->kor�� ��� ����
    pt -> kor = 90;
    pt -> eng = 90;
    pt -> mat = 90;
    pt -> tot = pt->kor + pt->eng + pt->mat;
    pt->avg = pt->tot/3.0f;

    printf("���� = %5d  ��� = %.2f \n", kk.tot, kk.avg);
    printf("(*pt).name= %s, pt->name= %s\n", (*pt).name, pt->name);

    return 0;
}