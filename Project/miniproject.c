#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500
#define ADMIN_PASS "admin123"

/* ---------------- ENCRYPTION ---------------- */

void encrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++)
        text[i] += 3;
}

void decrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++)
        text[i] -= 3;
}

/* ---------------- STAR GRAPH ---------------- */

void printStars(float avg) {
    int stars = (int)(avg + 0.5);
    for(int i = 0; i < stars; i++)
        printf("★");
    for(int i = stars; i < 5; i++)
        printf("☆");
}

/* ---------------- REVIEW FORM ---------------- */

void studentReviewForm(char classCode[], int teacherID) {
    FILE *fp;
    int ratings[9];
    char feedback[300];

    printf("\nRate each question from 1 (Very Poor) to 5 (Excellent)\n\n");

    printf("1. Deep conceptual understanding: ");
    scanf("%d", &ratings[0]);

    printf("2. Clarity in explaining logic: ");
    scanf("%d", &ratings[1]);

    printf("3. Intellectual rigor: ");
    scanf("%d", &ratings[2]);

    printf("4. Development of critical thinking: ");
    scanf("%d", &ratings[3]);

    printf("5. Theory connected to real-world: ");
    scanf("%d", &ratings[4]);

    printf("6. Lecture clarity & structure: ");
    scanf("%d", &ratings[5]);

    printf("7. Assessment quality: ");
    scanf("%d", &ratings[6]);

    printf("8. Responsiveness to doubts: ");
    scanf("%d", &ratings[7]);

    printf("9. Overall teaching effectiveness: ");
    scanf("%d", &ratings[8]);

    getchar();

    printf("10. Suggestions / Feedback: ");
    fgets(feedback, 300, stdin);
    feedback[strcspn(feedback, "\n")] = 0;

    encrypt(feedback);

    fp = fopen("feedback.txt", "a");
    if(fp == NULL) {
        printf("Error saving feedback.\n");
        return;
    }

    fprintf(fp, "%s|%d", classCode, teacherID);
    for(int i = 0; i < 9; i++)
        fprintf(fp, "|%d", ratings[i]);
    fprintf(fp, "|%s\n", feedback);

    fclose(fp);

    printf("\n✔ Feedback submitted anonymously.\n");
}

/* ---------------- STUDENT MODE ---------------- */

void studentMode() {
    FILE *tf;
    char classCode[MAX], line[MAX];
    int found = 0;

    printf("\nEnter Class Code: ");
    scanf("%s", classCode);

    tf = fopen("teachers.txt", "r");
    if(tf == NULL) {
        printf("Teachers file not found.\n");
        return;
    }

    while(fgets(line, MAX, tf)) {
        line[strcspn(line, "\n")] = 0;

        if(strcmp(line, classCode) == 0) {
            found = 1;
            printf("\nSelect Teacher:\n");

            while(fgets(line, MAX, tf)) {
                if(strncmp(line, "END", 3) == 0)
                    break;
                printf("%s", line);
            }
            break;
        }
    }

    fclose(tf);

    if(!found) {
        printf("Invalid Class Code.\n");
        return;
    }

    int teacherID;
    printf("\nEnter Teacher ID: ");
    scanf("%d", &teacherID);

    studentReviewForm(classCode, teacherID);
}

/* ---------------- ADMIN MODE ---------------- */

void adminMode() {
    char pass[50];
    printf("Enter Admin Password: ");
    scanf("%s", pass);

    if(strcmp(pass, ADMIN_PASS) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    FILE *ff = fopen("feedback.txt", "r");
    if(ff == NULL) {
        printf("No feedback data found.\n");
        return;
    }

    char classCode[MAX];
    printf("Enter Class Code to Analyze: ");
    scanf("%s", classCode);

    char fileClass[MAX], feedback[300];
    int teacherID;
    int ratings[9];

    int total[50] = {0};
    int count[50] = {0};

    printf("\n------ FEEDBACK RECORDS ------\n");

    while(fscanf(ff, "%[^|]|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%[^\n]\n",
        fileClass,
        &teacherID,
        &ratings[0], &ratings[1], &ratings[2],
        &ratings[3], &ratings[4], &ratings[5],
        &ratings[6], &ratings[7], &ratings[8],
        feedback) == 12) {

        if(strcmp(fileClass, classCode) == 0) {

            int sum = 0;
            for(int i = 0; i < 9; i++)
                sum += ratings[i];

            float avg = (float)sum / 9;
            total[teacherID] += avg;
            count[teacherID]++;

            decrypt(feedback);

            printf("\nTeacher %d\n", teacherID);
            printf("Average Rating: %.2f\n", avg);
            printf("Feedback: %s\n", feedback);
        }
    }

    fclose(ff);

    printf("\n------ RATING GRAPH ------\n");

    for(int i = 1; i < 50; i++) {
        if(count[i] > 0) {
            float finalAvg = total[i] / count[i];
            printf("Teacher %d : ", i);
            printStars(finalAvg);
            printf(" (%.2f)\n", finalAvg);
        }
    }
}

/* ---------------- MAIN ---------------- */

int main() {
    int choice;

    while(1) {
        printf("\n========================================\n");
        printf("  ANONYMOUS TEACHER FEEDBACK SYSTEM\n");
        printf("========================================\n");
        printf("1. Student Login\n");
        printf("2. Admin Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                studentMode();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        
    }
    

    return 0;
}