#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char pastFile[] = "files/";
    char subjectName[] = "matematica";
    char txt[] = ".txt";
    char nameFile[20];
    sprintf(nameFile, "%s%s%s", pastFile, subjectName, txt);
    printf("%s\n", nameFile);
    // char *str1 = "12";
    // char *str2 = "30";

    // char resultado[256];

    // sprintf( resultado, "%s:%s", str1, str2);
    // printf("%s\n", resultado);
}