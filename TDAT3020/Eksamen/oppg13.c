#include <stdio.h>

int main(int argc, char *argv[])
{
    char buff[32];
    char *p = argv[1];
    int i=0;
    while (*p != '\0')
    {
      buff[i++] = *p;
      *p++;
    }
    printf("%s\n", buff);
}