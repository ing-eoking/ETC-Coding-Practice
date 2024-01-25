#include<stdio.h>

int main(int argc, char** argv)
{
    char st[6], ed[6];
    int mst, med, sum = 0;
    for(int i = 0; i < 5; i++){
        scanf("%s %s",st, ed);
        st[2] = ed[2] = '\0';
        mst = 60 * atoi(st) + atoi(&st[3]);
        med = 60 * atoi(ed) + atoi(&ed[3]);
        sum += med - mst;
    }
    printf("%d\n", sum);
   return 0;
}
