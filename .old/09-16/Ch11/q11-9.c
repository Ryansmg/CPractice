#include <stdio.h>

int main()
{
    char name[5][20];
    int tempNum, kor[5], eng[5], math[5], sum[5], avg[5], rank[5], i, j;
    int num = 5;
    for(i=0; i<num; i++)
    {
        scanf(" %d %s %d %d %d", &tempNum, name[i], kor+i, eng+i, math+i);
        sum[i] = kor[i] + eng[i] + math[i];
        avg[i] = sum[i]/3;
    }

    for(i=0; i<num; i++)
    {
        rank[i] = 1;
        for(j=0; j<num; j++)
        {
            if(sum[i] < sum[j]) rank[i]++;
        }
    }

    printf("%5s %5s %5s %5s %5s %5s %5s %5s\n", "��ȣ", "�̸�", "����", "����", "����", "����", "���", "����");
    for(i=0; i<num; i++)
    {
        printf("%5d %5s %5d %5d %5d %5d %5d %5d\n", i+1, name[i], kor[i], eng[i], math[i], sum[i], avg[i], rank[i]);
    }
}

/*
1 ������ 90 100 100
2 �Ǳ⼮ 100 98 99
3 �չα� 33 92 100
4 �̸� 80 90 100
5 ��� 30 72 19
*/