#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void challenge_mode(void)
{
    int i = 0, begin, end, diff, totalcharacters = 1, j, wrong = 0;
    int wpm;
    char ch,c;
    FILE *fptr, *ptr;
    fptr = fopen("new.txt", "r");
    if (fptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }
    do
    {
        totalcharacters++;
        printf("%c", ch);
        ch = fgetc(fptr);
    }while(ch != EOF);
    fclose(fptr);
    char b[150];
    printf("\n\n");
    ptr = fopen("new.txt", "r");
    if (ptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }
    do
    {
        if (i == 0)
            begin = time(NULL);
        ch = getc(ptr);

        do
        {
        b[i] = getch();
        putch(b[i]);
        if (ch != b[i] && b[i] != 8)
        {
            do
            {
                c = getch();
            }while (c != 8);
            printf("\b");
            wrong++;
        }

        }while(ch != b[i]);
        i++;
    }while(i < 74);
    end = time(NULL);
    diff = end - begin;
    wpm = (totalcharacters/5)*60/diff;
    printf("\n\nYour wpm is: %d", wpm);
    float accuracy = ((totalcharacters-wrong)/(float)totalcharacters) * 100.0;
    printf("\n The accuracy is: %f", accuracy);
    return;
}

void tutor_mode(void)
{
int i = 0, begin, end, diff, j, wrong = 0, totalcharacters = 1;
    int wpm;
    char ch;
    FILE *fptr, *ptr;
    fptr = fopen("new.txt", "r");
    if (fptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }
    do
    {
        totalcharacters++;
        printf("%c", ch);
        ch = fgetc(fptr);
    }while(ch != EOF);
    char b[200];
    fclose(fptr);
    printf("\n\n");
    ptr = fopen("new.txt", "r");
    if (ptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }

    do
    {
        if (i == 0)
            begin = time(NULL);
        ch = getc(ptr);

        do
        {
        b[i] = getch();
        if (b[i] == 13)
            goto aa;
        if (ch == b[i])
            putch(b[i]);
        else if (ch != b[i])
            wrong++;
        }while(ch != b[i]);
        i++;
    }while(i < 74);
    aa:
    fclose(ptr);
    end = time(NULL);
    diff = end - begin;
    wpm = (totalcharacters/5)*60/diff;
    printf("\n\nYour wpm is: %d", wpm);
    float accuracy = ((totalcharacters-wrong)/(float)totalcharacters) * 100.0;
    printf("\n The accuracy is: %.2f %c", accuracy, '%');
    return;
}

void death_mode(void)
{
    int i = 0, begin, end, diff, j, wrong = 0, totalcharacters = 1;
    int wpm;
    char ch;
    FILE *fptr, *ptr;
    fptr = fopen("new.txt", "r");
    if (fptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }
    do
    {
        totalcharacters++;
        printf("%c", ch);
        ch = fgetc(fptr);
    }while(ch != EOF);

    char b[200];
    fclose(fptr);
    printf("\n\n");
    ptr = fopen("new.txt", "r");
    if (ptr == NULL)
    {
        fprintf(stderr,"The program cannot be run.");
        exit(1);
    }
    do
    {
        if (i == 0)
            begin = time(NULL);
        ch = getc(ptr);

        do
        {
        b[i] = getch();
        if (ch == b[i])
            putch(b[i]);
        else if (ch != b[i])
        {
            wrong++;
            goto aa;
        }
        }while(ch != b[i]);
        i++;
    }while(i < 74);
    aa:
    fclose(ptr);
    end = time(NULL);
    diff = end - begin;
    wpm = (i/5)*60/diff;
    printf("\n\nYour wpm is: %d", wpm);
    float accuracy = ((i-wrong)/(float)i) * 100.0;
    printf("\n The accuracy is: %.2f %c", accuracy, '%');
    return;
}
int main()
{
    challenge_mode();
    return 0;
}
