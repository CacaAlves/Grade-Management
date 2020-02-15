typedef struct Grades
{
    float grade;
    float weight;
    struct Grades *next;
}Grades;

int task();
void createNewSubject(char subjectName[]);
void inputNewGrade(char subjectName[], float grade, float weight);
Grades *newGrade();
void insertAtEnd(Grades **grade, float note, float weight);
void showGrades(char subjectName[]);