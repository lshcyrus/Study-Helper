/* This is a very simple program combining some essential study needs.
   Designed and implemented by LEE Shing Hei Cyrus. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define true 1
#define false 0
#define A 4
#define B 3
#define C 2
#define D 1
#define F 0

/* For input validation */
void int_validate() 
{
    int ch = getchar();
    while (ch != '\n' && ch != EOF){
        ch = getchar();
    }
}

typedef struct{
    char code[9];
    int asmnum, month, day;
}Assignment;

Assignment create_reminder(char code[9], int asmnum, int month, int day){
    Assignment reminder;
    strcpy(reminder.code, code);
    reminder.asmnum = asmnum;
    reminder.month = month;
    reminder.day = day;
    return reminder;
}

int getMonth(){
    int i, n, sum = 0;
    time_t current_time;
    time(&current_time);
    for (i = 4; i <= 6; i++){
        sum += (char)ctime(&current_time)[i];
    }
    if (sum == 'J' + 'a' + 'n'){
        return 1;
    }
    else if (sum == 'F' + 'e' + 'b'){
        return 2;
    }
    else if (sum == 'M' + 'a' + 'r'){
        return 3;
    }
    else if (sum == 'A' + 'p' + 'r'){
        return 4;
    }
    else if (sum == 'M' + 'a' + 'y'){
        return 5;
    }
    else if (sum == 'J' + 'u' + 'n'){
        return 6;
    }
    else if (sum == 'J' + 'u' + 'l'){
        return 7;
    }
    else if (sum == 'A' + 'u' + 'g'){
        return 8;
    }
    else if (sum == 'S' + 'e' + 'p'){
        return 9;
    }
    else if (sum == 'O' + 'c' + 't'){
        return 10;
    }
    else if (sum == 'N' + 'o' + 'v'){
        return 11;
    }
    else if (sum == 'D' + 'e' + 'c'){
        return 12;
    }
}

int getDay(){
    int i, n = 8;
    char day[2];
    time_t current_time;
    time(&current_time);
    for (i = 0; i <= 1; i++){
        day[i] = ctime(&current_time)[n];
        n++;
    }
    return atoi(day);
}
void displayTime(){
    time_t current_time;
    time(&current_time);
    printf("Current Time:\t%s", ctime(&current_time));
}


void dlcount(Assignment assignment){
    int i, sum = 0;
    int current_month, current_day;
    int day_diff;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    current_month = getMonth();
    current_day = getDay();
    if (current_month == assignment.month){
        day_diff = assignment.day - current_day;
    }
    else if (assignment.month > current_month){
        for (i = current_month-1; i < assignment.month-1; i++){ // addition of no. of days of two months
            sum += days[i];
        }
        day_diff = (sum - current_day) + assignment.day;
    }
    if (day_diff >= 0)
        printf("Approximately %d days before %s Assignment %d deadline.\n", day_diff, assignment.code, assignment.asmnum);
    else
        printf("This Assignment has passed its deadline.\n");
}

void welcome(){
    printf("====================================================================================\n");
    printf("This is a simple program specialized for CUHK Study.\n");
    printf("Designed and implemented by LEE Shing Hei Cyrus :)\n");
    printf("Please report bugs to me if any are found.\nPlease inform me before sharing to others that I don't know!\n");
}

void displayMethod(){
    printf("====================================================================================\n");
    printf("The calculator follows the calculation stated in the student handbook of CUHK.\n");
    printf("For instance:\n");
    printf("GPA would be calculated by [Attained Grade]x[Course Unit] for one course.\n");
    printf("====================================================================================\n");
}

void calculateGPA(){
    int i, n, count = 1;
    char coursecode[10], grade[3];
    double unit, totalgpa = 0.0, totalunit = 0.0;
    FILE* ptr;
    displayMethod();
    // printf("How many subjects have you taken? ");
    // scanf("%d", &num);

    ptr = fopen("insert-your-grades-and-corresponding-unit-here.txt", "r");
    while (!feof(ptr))
    {   
        int sum = 0;
        double agpa = 0.0;
        fscanf(ptr, "%s", coursecode);
        fscanf(ptr, "%s", grade);
        fscanf(ptr, "%lf", &unit);
        printf("\nSubject %d: %s\n", count, coursecode);
        if (count < 10){
            printf("Subject %d Grade\t: %s\n", count, grade);
            printf("Subject %d Unit\t: %.1f\n", count, unit);
        }
        if (count >= 10){
            printf("Subject %d Grade: %s\n", count, grade);
            printf("Subject %d Unit\t: %.1f\n", count, unit);
        }

        n = (int)strlen(grade);
        if (n == 1)
        {
            if (grade[0] == 'A')
                agpa = A * unit;
            else if (grade[0] == 'B')
                agpa = B * unit;
            else if (grade[0] == 'C')
                agpa = C * unit;
            else if (grade[0] == 'D')
                agpa = D * unit;
            else if (grade[0] == 'F')
                agpa = F * unit;
        }
        else if (n == 2)
        {
            if (grade[0] == 'A')
                agpa = A;
            else if (grade[0] == 'B')
                agpa = B;
            else if (grade[0] == 'C')
                agpa = C;
            else if (grade[0] == 'D')
                agpa = D;
            else if (grade[0] == 'F')
                agpa = F;
            if (grade[1] == '+')
                agpa += 0.3;
            if (grade[1] == '-')
                agpa -= 0.3;
            agpa *= unit;
        }
        totalgpa += agpa;
        totalunit += unit;
        count++;
    }
    printf("\nTotal GPA attained: %lf\n", totalgpa);
    printf("Total unit studied: %lf\n", totalunit);
    printf("Cumulative GPA\t: %f\n", totalgpa/totalunit);
    
    fclose(ptr);
}

void convertBD(){
    printf("====================================================================================\n");
    int i, b, d, sum = 0, choice = 0, valid = 0;
    while (!valid){
        printf("[1]: Binary to Decimal\n");
        printf("[2]: Decimal to Binary\n");
        printf("[3]: Return to main menu\n");
        printf("Please Enter: ");
        scanf("%d", &choice);
        int_validate();
        if (choice >= 1 && choice <= 3){
            valid = 1;
            switch(choice){
                case 1:
                {
                    printf("The binary number you wish to convert: ");
                    scanf("%d", &b);
                    for (i = 0; b > 0; i++)
                    {
                        sum += (b % 10) * pow(2, i);
                        b /= 10;
                    }
                    printf("The converted decimal number is %d\n", sum);
                    break;
                }
                case 2:
                {
                    printf("The decimal number you wish to convert: ");
                    scanf("%d", &d);
                        for (i = 1; d > 0; i *= 10)
                        {
                        sum += (d % 2) * i;
                        d /= 2;
                        }
                    printf("The converted binary number is %d\n", sum);
                    break;
                }
                case 3: break;
            }
        }
        else
        {
            printf("====================================================================================\n");
            printf("Please input integer 1, 2, 3 for choice.\n");
        }   
    }
}

void vproduct(){
    printf("====================================================================================\n");
    int choice, n, i = 0, j = 0;
    double product = 0.0, dproduct = 0.0, cproduct = 0.0;
    printf("[1]: Dot Product\n");
    printf("[2]: Cross Product\n");
    printf("[3]: Return to main menu.\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    int_validate();
    if (choice == 1 || choice == 2)
    {
        printf("Please enter the dimension of vector: ");
        scanf("%d", &n);

        double v[n], w[n];

        printf("Please enter the first vector's component: ");

        while (i < n){
        scanf("%lf", &v[i]); i++;
        }
        
        printf("Please enter the second vector's component: ");

        while (j < n){
        scanf("%lf", &w[j]); j++;
        }

        switch(choice){
            case 1:{
                while (n >= 0){
                    product = v[n-1] * w[n-1];
                    dproduct += product;
                    n--;
                }
                printf("The required dot product = %.2f\n", dproduct); break;
            }
            case 2:{
                if (n > 3){
                    printf("The cross productor only supports vectors within dimension of 3.\n"); break;
                }
                if (n <= 3){
                    printf("The required cross product = <%.2f, %.2f, %.2f>\n",(v[1]*w[2]-v[2]*w[1]),-1*(v[0]*w[2]-v[2]*w[0]),(v[0]*w[1]-v[1]*w[0])); break;
                }
            }
        }
    }  
}

void determinant(){
    printf("====================================================================================\n");
    int i, j, valid = 1;
    double m[3][3];
    double det = 0.0, a, b, c, d, e, f;

    printf("Please enter matrix entries:\n");
    printf("-----FORMAT-----\n");
    printf("[1] [2] [3][ENTER]\n");
    printf("[4] [5] [6][ENTER]\n");
    printf("[7] [8] [9][ENTER]\n");
    printf("----------------\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%lf", &m[i][j]);
        }
    }

        a = m[0][0]*m[1][1]*m[2][2];
        b = m[0][1]*m[1][2]*m[2][0];
        c = m[0][2]*m[1][0]*m[2][1];
        d = m[0][2]*m[1][1]*m[2][0];
        e = m[0][0]*m[1][2]*m[2][1];
        f = m[0][1]*m[1][0]*m[2][2];

        det = a + b + c - d - e - f;
        printf("The determinant of the matrix is %.2f\n", det);
        printf("The matrix is linearly ");
        if (det == 0)
            printf("dependent.\n");
        if (det != 0)
            printf("independent.\n");
}

void displayAsm(int amount){
    printf("====================================================================================\n");
    printf("Reminder    :\tYou have %d assignments due.\n", amount);
}

void checkAsm(){
    Assignment assignment;
    int month, day, count = 0;
    int asmnum;
    char code[9];
    FILE *ptr;
    
    ptr = fopen("reminder.txt", "r");

    while (!feof(ptr)){
        printf("====================================================================================\n");
        fscanf(ptr, "%s", code);
        printf("Subject code: %s", code);
        fscanf(ptr,"%d", &asmnum);
        printf("\nAssignment number: %d\n", asmnum);
        fscanf(ptr,"%d%d", &day, &month);
        printf("Due Date for %s Assignment %d: %d/%d\n", code, asmnum, day, month); 
        assignment = create_reminder(code, asmnum, month, day);
        dlcount(assignment);
        count ++;
    }
    displayAsm(count);
    fclose(ptr);
}

// void addAsm(){
//     printf("====================================================================================\n");
//     FILE *gpacal = open("insert-your-grades-and-corresponding-unit-here.txt", "a");
//     FILE *asmrdr = open("reminder.txt", "a");
//     char scode[9], grade[3];
//     double unit = 0;
//     int choice = 0;
//     printf("[1]: Input data for GPA Calculator\n[2]: Input data for Assignment Reminder\nPlease enter your choice: ");
//     scanf("%d", &choice);
//     switch(choice){
//         case 1:{
//             printf("Please enter your subject code: ");
//             fgets(scode, 9, stdin);
//             //fprintf(gpacal, "\n%s ", scode);
//             printf("Please input your grade for the subject: ");
//             fgets(grade, 3, stdin);
//             //fprintf(gpacal,"%s ", grade);
//             printf("Please input corresponding unit for the subject: ");
//             scanf("%lf", unit);
//             //fprintf(gpacal, "%f", unit);
//         }
//     }
//     fcloseall;
// }   

int main(void){
    
    int valid = 1;
    int choice = 0;
    welcome();
    checkAsm();

    while(valid)
    {
        printf("====================================================================================\n");
        displayTime();
        printf("====================================================================================\n");
        printf("[1]: GPA Calculator\n");
        printf("[2]: Decimal-Binary/Binary-Decimal Converter\n");
        printf("[3]: Vector Producter\n");
        printf("[4]: 3x3 Matrix Determinant Calculator\n");
        printf("[5]: Check Assignment Reminder\n");
        printf("[6]: Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int_validate();
        

        if(choice >= 1 && choice <= 6)
        {
            switch(choice)
            {
                case 1: calculateGPA();break;
                case 2: convertBD();break;
                case 3: vproduct();break;
                case 4: determinant();break;
                case 5: checkAsm();break;
                case 6:
                {
                valid = 0;
                printf("====================================================================================\n");
                printf("Thank you for using my program. Hope you could boom 4!!!");
                }
            }
        }
        else
        {
            printf("Please enter integer 1-6 for option choice.\n");
        }
    }
    return 0;
}