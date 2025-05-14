#include <stdio.h>
#include <string.h>

struct Subject
{
    char name[50];
    int marks;
    int credits;
};

void calculateCGPA(struct Subject subjects[], int numSubjects) 
{
    float totalPoints = 0;
    int totalCredits = 0;
    for (int i = 0; i < numSubjects; i++) 
    {
        if (subjects[i].credits > 0) 
        {
            float grade = (subjects[i].marks / 100.0) * 10;
            totalPoints += grade * subjects[i].credits;
            totalCredits += subjects[i].credits;
        }
    }
    float cgpa = totalPoints / totalCredits;
    printf("CGPA: %.2f\n", cgpa);
}

int main() 
{
    struct Subject subjects[10];
    int numSubjects;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);
    if (numSubjects < 1 || numSubjects > 10) 
    {
        printf("Invalid number of subjects. Please enter a number between 1 and 10.\n");
        return 1;
    }
    for (int i = 0; i < numSubjects; i++) 
    {
        printf("Enter subject %d name: ", i + 1);
        scanf("%s", subjects[i].name);
        printf("Enter marks obtained for %s: ", subjects[i].name);
        scanf("%d", &subjects[i].marks);
        if (subjects[i].marks < 0 || subjects[i].marks > 100) 
        {
            printf("Invalid marks. Please enter a number between 0 and 100.\n");
            return 1;
        }
        printf("Enter the number of credits for %s: ", subjects[i].name);
        scanf("%d", &subjects[i].credits);
        if (subjects[i].credits < 0 || subjects[i].credits > 5) 
        {
            printf("Invalid credits. Please enter a number between 0 and 5.\n");
            return 1;
        }
    }
    calculateCGPA(subjects, numSubjects);
    return 0;
}