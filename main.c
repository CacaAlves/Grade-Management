#include <stdio.h>
#include "biblioteca.h"
void main()
{   
    int goal = -1;
    while(goal != 0)
    {
        goal = task();
        switch (goal)
        {
        char name[15];
        case 1:
            printf("Input the subject's name ( *NO SEPARATE NAMES* ) :\n");
            scanf("%s", name);
            createNewSubject(name);
            break;
        case 2 :
            printf("Input the subject's name :\n");
            scanf("%s", name);
            printf("Input the grade :\n");
            float grade;
            scanf("%f", &grade);
            printf("Input the weight of this one :\n");
            float weight;
            scanf("%f", &weight);
            inputNewGrade(name, grade, weight);
            break;
        case 3 :
            printf("Input the subject's name : \n");
            scanf("%s", name);
            showGrades(name);
            break;
        default:
            break;
        }
    }
}