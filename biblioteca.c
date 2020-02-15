#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "biblioteca.h"
int task()
{
    char question[] = "What do you have in mind ?";
    char option1[] = "Input 1 to save a new subject";
    char option2[] = "Input 2 to input a new grade in a existent subject";
    char option3[] = "Input 3 to check your grades";
    char option4[] = "Input 0 to exit";

    printf("%s\n%s\n%s\n%s\n%s\n", question, option1, option2, option3, option4);

    int taskValue = -1;
    bool VALID_OPTION = false;
    while (VALID_OPTION != true)
    {
        scanf("%i", &taskValue);
        VALID_OPTION = (taskValue >= 0 && taskValue <= 3);
        if (VALID_OPTION == false)
        {
            printf("Input a valid value\n");
        }
    }
    printf("You chose : ");
    switch (taskValue)
    {
    case 0:
        printf("exit\n");
        break;
    case 1:
        printf("create a new subject\n");
        break;
    case 2:
        printf("input a new grade\n");
        break;
    case 3:
        printf("show your grades\n");
        break;
    default:
        break;
    }
    return taskValue;
}
void createNewSubject(char subjectName[])
{
    char dir[] = "files/";
    char txt[] = ".txt";
    char nameFile[20];
    sprintf(nameFile, "%s%s%s", dir, subjectName, txt);
    FILE *file = fopen(nameFile, "w");

    printf("How many tests / homeworks do you have ?\n");
    int gradesNumber;
    scanf("%i", &gradesNumber);
    fprintf(file, "%s\n", subjectName);
    fprintf(file, "%i\n", gradesNumber);
    fclose(file);
}
void inputNewGrade(char subjectName[], float grade, float weight)
{
    char dir[] = "files/";
    char txt[] = ".txt";
    char nameFile[30];
    sprintf(nameFile, "%s%s%s", dir, subjectName, txt);
    FILE *file = fopen(nameFile, "a");

    char c = ' ';
    while (c != EOF)
    {
        c = fgetc(file);
    }
    fprintf(file, "%.2f %.2f\n", grade, weight);
    fclose(file);
}
Grades *newGrade()
{
    Grades *grade;
    grade = malloc(sizeof(Grades));
    grade->next = NULL;
    return grade;
}
void insertAtEnd(Grades **grade, float note, float weight)
{
    Grades *new = newGrade();
    if ((*grade) == NULL)
    {
        new->grade = note;
        new->weight = weight;
        (*grade) = new;
    }
    else
    {
        Grades *aux = (*grade);
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        new->grade = note;
        new->weight = weight;
        aux->next = new;
    }
}
float calculateGrade(Grades *grade)
{
    float final = 0;
    while (grade->next != NULL)
    {
        final += (grade->grade) * ((grade->weight) / 10);
        grade = grade->next;
    }
    final += (grade->grade) * ((grade->weight) / 10);
    return final;
}
void showGrades(char subjectName[])
{

    char dir[] = "files/";
    char txt[] = ".txt";
    char nameFile[30];
    sprintf(nameFile, "%s%s%s", dir, subjectName, txt);
    FILE *file = fopen(nameFile, "r");
    char name[30];
    int numberOfGrades;
    fscanf(file, "%s%i", name, &numberOfGrades);

    printf("\n");
    Grades *grade = NULL;
    for (int k = 0; k < numberOfGrades; k++)
    {
        float note = 0;
        float weight = 0;
        fscanf(file, "%f%f", &note, &weight);
        printf("%.2f %.2f\n", note, weight);
        insertAtEnd(&grade, note, weight);
    }
    float finalGrade = calculateGrade(grade);
    printf("The current grade for %s is %.2f\n\n", subjectName, finalGrade);
    fclose(file);
}
