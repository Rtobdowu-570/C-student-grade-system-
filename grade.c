#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

typedef struct 
    {
        int id;
        char name[50];
        int age;
        float grades[5];
        float average;
    }Student;

    void addStudent(Student students[], int *count);
    void displayStudent(Student students[], int count);
    void searchStudent(Student students[], int count);

    float calculateAverage(float grades[5], int count);
    char getGrades(float avg);

/**
 * Main function to run the program
 * 
 * This program is a simple student database program which allows the user to add, search, and display all data
 * 
 * @return int 0 on successful execution
 */
    int main() {

        Student students[MAX_STUDENTS];
        int count = 0;
        int choice;

        printf("--- WELCOME --- \n");

        do
        {
            printf("\nSelect a choice: \n");
            printf("\n1. Add  Student \n");
            printf("2. Search for a Student \n");
            printf("3. Display All Data \n");
            printf("4. Exit the program \n");
            printf("\nEnter Your choice:");
            scanf("%d", &choice);

            switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;

        case 2:
            searchStudent(students, count);
            break;

        case 3:
            displayStudent(students, count);
            break;

        case 4:
            printf("\nYou exited the program");
            break;
        
        default:
            printf("\ninvalid choice");
            break;
        }

        } while (choice != 4);
        

        return 0;
    }


/**
 * Calculate the average of the grades provided
 * 
 * @param grades An array of 5 grades
 * @param count The number of grades to consider
 * @return The average of the grades
 */
    float calculateAverage(float grades[5], int count){
        if (count <= 0) return 0.0f;
        float sum = 0.0f;
        for(int i = 0; i < count; i++) {
            sum += grades[i];
        }
        return sum / (float)count;
    }

/**
 * Return the letter grade corresponding to the average provided
 * 
 * @param avg The average to get the letter grade for
 * @return The letter grade corresponding to the average
 */
    char getGrades(float avg){
        if (avg >= 90.0f) {
            return 'A';
        } else if (avg >= 80.0f) {
            return 'B';
        } else if (avg >= 70.0f) {
            return 'C';
        } else if (avg >= 60.0f) {
            return 'D';
        } else {
            return 'F';
        }
    }


/**
 * Adds a new student to the database
 * 
 * This function takes in a student array and the current count of students.
 * It checks if the student list is full and if so, prints a message and exits.
 * Then it prompts the user to enter the student's id, name, age, and 5 grades.
 * It calculates the average of the grades and adds the student to the database.
 */
    void addStudent(Student students[], int *count) {
        if (*count >= MAX_STUDENTS) {
            printf("Student list is Full\n");
        }

        Student data;

        printf("\nEnter Student Id: ");
        scanf("%d", &data.id);

        while(getchar() != '\n'); 

        printf("\nEnter Student Name: ");
        fgets(data.name, sizeof(data.name), stdin);
        data.name[strlen(data.name) - 1] = '\0'; 


        printf("\nEnter Student Age: ");
        scanf("%d", &data.age);

        printf("\nEnter 5 grade: \n");
        for(int i = 0; i < 5; i++) {
            printf(" Grade %d: ", i + 1);
            scanf("%f", &data.grades[i]);
        }

        data.average = calculateAverage(data.grades, 5);
        students[*count] = data;
        (*count)++;
    }

/**
 * Searches for a student in the database based on the id provided
 * 
 * @param students The array of students to search through
 * @param count The number of students in the database
 */
    void searchStudent(Student students[], int count) {
        int id = 0;
        printf("\nEnter Student id to search: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if(students[i].id == id) {
                printf("\nStudent Id: %d", students[i].id);
                printf("\nStudent Name: %s", students[i].name);
                printf("\nStudent Age: %d", students[i].age);
                printf("\nStudent Average Grade: %.2f \n", students[i].average);
                return;
            }  else {
                 printf("Student not found");
            }
        }
    }

/**
 * Displays all the students in the database
 * 
 * This function takes in a student array and the current count of students.
 * It checks if there are any students to display and if so, prints a header and then
 * loops through the array, printing out the student's id, name, age, and average grade.
 */
    void displayStudent(Student students[], int count) {
        if (count == 0) {
            printf("\nNo students found to display.\n");
        } else {
            printf("\n -- Student List ---");
            for (int i = 0; i < count; i++) {
                printf("\n Student Id: %d", students[i].id);
                printf("\n Student Name: %s", students[i].name);
                printf("\n Student Age: %d", students[i].age);
                printf("\n Student Average Grade: %.2f", students[i].average);
                printf("\n------------------- \n");
            }
        }
    }

    


