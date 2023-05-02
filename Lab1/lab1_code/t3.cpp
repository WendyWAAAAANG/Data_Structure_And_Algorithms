#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[50];
    scanf("%s", str);
    char c;
    int count = 0;
    do {
        c = str[count];
        count ++;
    } while (c != '\0');
    printf("%d", count - 1);
    return 0;
}
