#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 123456789;

    int flag = (num == *(int*)(float*)&num);
    printf("%d\n", flag);

    flag = (num == (int)(float)num);

    printf("%d\n", flag);
    return 0;
}
