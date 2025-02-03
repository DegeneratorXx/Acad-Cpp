#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 15

typedef struct {
    char name[50];
    int rollNo;
    int age;
    char address[100];
    char email[50];
    char mobile[20];
    char program[10];
    int semester;
    int compulsory[2];
    int elective[2];
} Student;

typedef struct {
    char name[50];
    int capacity;
    int semester;
    int roster[MAX_STUDENTS];
} Subject;

Subject subjects[MAX_SUBJECTS];
int numSubjects = 0;
Student* students[MAX_STUDENTS];
int numStudents = 0;

void registerStudent() {
    Student* newStudent = malloc(sizeof(Student));
    printf("\nEnter name: ");
    scanf("%s", newStudent->name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent->rollNo);
    printf("Enter age: ");
    scanf("%d", &newStudent->age);
    printf("Enter address: ");
    scanf("%s", newStudent->address);
    printf("Enter email: ");
    scanf("%s", newStudent->email);
    printf("Enter mobile number: ");
    scanf("%s", newStudent->mobile);
    printf("Enter program (BTech/MTech): ");
    scanf("%s", newStudent->program);
    printf("Enter semester: ");
    scanf("%d", &newStudent->semester);
    
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNo == newStudent->rollNo) {
            found = 1;
            printf("\nStudent with roll number %d already exists.\n", newStudent->rollNo);
            break;
        }
    }
    
    if (!found) {
        students[numStudents] = newStudent;
        numStudents++;
        printf("\nRegistration successful!\n");
        printf("Compulsory courses allocated: %d, %d\n", subjects[newStudent->semester * 2 - 2].capacity, subjects[newStudent->semester * 2 - 1].capacity);
    }
}

void viewSubjects() {
    printf("\nList of subjects:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("%d. %s (Semester %d, Capacity: %d)\n", i+1, subjects[i].name, subjects[i].semester, subjects[i].capacity);
    }
    return;
}

void optSubject(int index) {
    if (index < 0 || index >= numSubjects) {
        printf("\nInvalid subject index!\n");
        return;
    }
    
    int semester = subjects[index].semester;
    if (students[numStudents-1]->semester < semester) {
        printf("\nYou can't opt for this subject in this semester!\n");
        return;
    }
    
    if (subjects[index].capacity == 0) {
        printf("\nThe subject is already full! Try another subject.\n");
        return;
    }
    
    subjects[index].capacity--;
    int studentIndex = numStudents-1;
    int count = 0;
    while (count < 2 && students[studentIndex]->elective[count] != -1) {
        count++;
    }
    
    if (count < 2) {
        students[studentIndex]->elective[count] = index;
        printf("\nSubject %s opted for successfully!\n", subjects[index].name);
    } else {
        printf("\nYou have already opted for two electives!\n");
    }
    return;
}

void searchStudent() {
    int rollNo;
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNo);
    
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNo == rollNo) {
            found = 1;
            Student* s = students[i];
            printf("\nStudent Details:\n");
            printf("Name: %s\n", s->name);
            printf("Roll No: %d\n", s->rollNo);
            printf("Age: %d\n", s->age);
            printf("Address: %s\n", s->address);
            printf("Email: %s\n", s->email);
            printf("Mobile No: %s\n", s->mobile);
            printf("Program: %s\n", s->program);
            printf("Semester: %d\n", s->semester);
            printf("Compulsory courses: %s (%d) %s (%d)\n", subjects[s->semester * 2 - 2].name, s->compulsory[0], subjects[s->semester * 2 - 1].name, s->compulsory[1]);
            printf("Elective courses: ");
            for (int j = 0; j < 2; j++) {
                if (s->elective[j] != -1) {
                    printf("%s ", subjects[s->elective[j]].name);
                } else {
                    printf("N/A ");
                }
            }
            printf("\n");
            break;
        }
    }
    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNo);
    }
    return;
}

int main() {
    viewSubjects();
    printf("\n\n");
    
    while (1) {
        printf("Enter option:\n1. Register Student\n2. Opt for Elective Subject\n3. Search Student\n4. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                registerStudent();
                break;
            case 2:
                printf("\nEnter subject index: ");
                int index;
                scanf("%d", &index);
                optSubject(index-1);
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
        }
        printf("\n\n");
    }
    
    return 0;
}
