#include <stdio.h>

int main(void)
{
    int a, b, NUM;
    scanf("%d", &NUM);
    for(int i = 1; i <= NUM; i++){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i, a + b);
    }
    return 0;
}
