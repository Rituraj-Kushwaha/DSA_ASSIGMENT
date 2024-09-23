#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
//Display
void displayStudents(char students[][MAX_NAME_LENGTH], int size) {
    printf("Current list of students:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }
}
//Create
void createList(char students[][MAX_NAME_LENGTH], int *size) {
    printf("Enter student names (enter 'done' to finish):\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        scanf("%49s", students[i]);
        if (strcmp(students[i], "done") == 0) {
            *size = i;
            break;
        }
    }
}
//Insertion
void insertStudent(char students[][MAX_NAME_LENGTH], int *size) {
    printf("Enter the name of the student to insert: ");
    char name[MAX_NAME_LENGTH];
    scanf("%49s", name);
    printf("Enter the index at which to insert the student: ");
    int index;
    scanf("%d", &index);
    if (index < 1 || index > *size + 1) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    for (int i = *size; i >= index - 1; i--) {
        strcpy(students[i + 1], students[i]);
    }
    strcpy(students[index - 1], name);
    (*size)++;
}
//Deletion
void deleteStudent(char students[][MAX_NAME_LENGTH], int *size) {
    printf("Do you want to delete by name (1) or by index (2)? ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the name of the student to delete: ");
        char name[MAX_NAME_LENGTH];
        scanf("%49s", name);
        for (int i = 0; i < *size; i++) {
            if (strcmp(students[i], name) == 0) {
                for (int j = i; j < *size - 1; j++) {
                    strcpy(students[j], students[j + 1]);
                }
                (*size)--;
                printf("Student deleted successfully.\n");
                return;
            }
        }
        printf("Student not found.\n");
    } else if (choice == 2) {
        printf("Enter the index of the student to delete: ");
        int index;
        scanf("%d", &index);
        if (index < 1 || index > *size) {
            printf("Invalid index. Please try again.\n");
            return;
        }
        for (int i = index - 1; i < *size - 1; i++) {
            strcpy(students[i], students[i + 1]);
        }
        (*size)--;
        printf("Student deleted successfully.\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}
//Searching
void searchStudent(char students[][MAX_NAME_LENGTH], int size) {
    printf("Enter the name of the student to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%49s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i], name) == 0) {
            printf("Student found at index %d.\n", i + 1);
            return;
        }
    }
    printf("Student not found.\n");
}
int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int size = 0;
    int choice;
//Menu for operation
    while (1) {
        printf("Student Management System\n");
        printf("1. Create list\n");
        printf("2. Insert student\n");
        printf("3. Delete student\n");
        printf("4. Display students\n");
        printf("5. Search for student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList(students, &size);
                displayStudents(students, size);
                break;
            case 2:
                if (size == MAX_STUDENTS) {
                    printf("List is full. Cannot insert more students.\n");
                } else {
                    insertStudent(students, &size);
                    displayStudents(students, size);
                }
                break;
            case 3:
                if (size == 0) {
                    printf("List is empty. Cannot delete students.\n");
                } else {
                    deleteStudent (students, &size);
                    displayStudents(students, size);
                }
                break;
            case 4:
                if (size == 0) {
                    printf("List is empty.\n");
                } else {
                    displayStudents(students, size);
                }
                break;
            case 5:
                if (size == 0) {
                    printf("List is empty. Cannot search for students.\n");
                } else {
                    searchStudent(students, size);
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}