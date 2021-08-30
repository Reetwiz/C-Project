#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

void mainmenu();
void about();
void NewGame();
void ViewScores();
void help();

void select_text();
void challenge_mode(char []);
void tutor_mode(char []);
void death_mode(char []);

int main()
{
    mainmenu();
    return 0;
}

void mainmenu()
{
ChooseOpt:
    system("cls");
    int choice;
    puts("\t\t\t\t****************************");
    puts("\t\t\t\t   WELCOME TO SPEED TYPER");
    puts("\t\t\t\t****************************\n");
    puts("\t\t\t\t\t1. New Game");
    puts("\t\t\t\t\t2. View Scores");
    puts("\t\t\t\t\t3. Help");
    puts("\t\t\t\t\t4. About developers");
    puts("\t\t\t\t\t5. Exit\n\n");
    printf("\t\t\t\t\tPlease enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        NewGame();
        break;

    case 2:
        system("cls");
        ViewScores();
        break;

    case 3:
        system("cls");
        help();
        break;

    case 4:
        system("cls");
        about();
        break;

    case 5:
        exit(1);

    default:
        printf("\n\t\tERROR!! Please select 1, 2, 3, 4 or 5.");
        Sleep(2000);
        goto ChooseOpt;
    }
    //printf("\n\t\tPress any key to continue: ");
    // getch();
}

void NewGame()
{
    char username[20];
    system("cls");
    printf("\t\t\tEnter your first name: ");
    scanf("%s", &username);
    printf("\t\t\tHi %s, welcome to Speed Typer\n", username);
    select_text();
}

void ViewScores()
{
    printf("\t\t\t\t\t\tS C O R E S");
    printf("\n\n\tS.N.\tName\t\tMode\t\tText\t\tDate/Time\t\t\tScore(WPM)");
    printf("\n   __________________________________________________________________________________________________________________");
}

void help()
{
    FILE *ptr;
    char c;
    system("cls");
    ptr = fopen("help.txt", "r");
    c = fgetc(ptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(ptr);
    }
    fclose(ptr);
}

void about()
{
    FILE *fptr;
    char c;
    system("cls");
    fptr = fopen("about.txt", "r");
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}


void select_text()
{
    printf("\n\t\tLoading:");
    int i=0;
    for (i = 0; i < 10; i++)
    {
        printf("-");
        Sleep(100);
    }
selecttext:
    //system("color ");
    system("cls");
    int choice;
    char file_name[7]="cx.txt";
    printf("Texts Available:\n\n");
    printf("1. Lowercase Letters \n2. Mixed Alphabets \n3. Punctuations \n4. Numbers\n");
    printf("Or Press 5 to return to main menu\n");
    printf("Select Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        file_name[1]='1';
        break;
    case 2:
        file_name[1]='2';
        break;
    case 3:
        file_name[1]='3';
        break;
    case 4:
        file_name[1]='4';
        break;
    default:
        printf("Invalid Option");
        goto selecttext;
    }
    system("cls");
selectmode:
    printf("Please Select a Mode:\n");
    printf("1. Tutor Mode \n2. Challenge Mode \n3. Death Mode\n\n\n\n ");
    printf("Or Press 4 to return to main menu\n\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        tutor_mode(file_name);
        break;
    case 2:
        challenge_mode(file_name);
        break;
    case 3:
        death_mode(file_name);
        break;
    case 4:
        mainmenu();
        break;
    default:
        printf("Invalid Option");
        sleep(1);
        goto selectmode;
    }
}

void challenge_mode(char file_name[7])
{
    int i = 0, totalcharacters = 1,wrong = 0, j, begin, end, diff, wpm;
    char ch,c;
    FILE *fptr, *ptr;
     system("cls");
    fptr = fopen(file_name, "r");
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
    }
    while(ch != EOF);
    fclose(fptr);
    char b[150];
    printf("\n\n");
    ptr = fopen(file_name, "r");
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
                }
                while (c != 8);
                printf("\b");
                wrong++;
            }

        }
        while(ch != b[i]);
        i++;
    }
    while(i < 74);
    end = time(NULL);
    diff = end - begin;
    wpm = (totalcharacters/5)*60/diff;
    float accuracy = ((totalcharacters-wrong)/(float)totalcharacters) * 100.0;
    system("cls");
    printf("\n\nYour wpm is: %d", wpm);
    printf("\n The accuracy is: %f", accuracy);
    return;
     printf("Press enter to return to the main menu or escape key to exit");
    char cho;
    gets(ch);
    if (ch=="\n")
        mainmenu();
}

void tutor_mode(char file_name[6])
{
    int i = 0, begin, end, diff, j, wrong = 0, totalcharacters = 1;
    int wpm;
    char ch;
    FILE *fptr, *ptr;
     system("cls");
    fptr = fopen(file_name, "r");
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
    }
    while(ch != EOF);
    char b[200];
    fclose(fptr);
    printf("\n\n");
    ptr = fopen(file_name, "r");
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
        }
        while(ch != b[i]);
        i++;
    }
    while(i < 74);
aa:
    fclose(ptr);
    end = time(NULL);
    diff = end - begin;
    wpm = (totalcharacters/5)*60/diff;
    float accuracy = ((totalcharacters-wrong)/(float)totalcharacters) * 100.0;
    system("cls");
    printf("\n\nYour wpm is: %d", wpm);
    printf("\n The accuracy is: %.2f %c", accuracy, '%');
     printf("Press enter to return to the main menu or escape key to exit");
     printf("Do you want to store your record?");
     char choice;
     scanf("%c", choice);

}

void death_mode(char file_name[6])
{
    int i = 0, begin, end, diff, j, wrong = 0, totalcharacters = 1;
    int wpm;
    char ch;
     system("cls");
    FILE *fptr, *ptr;
    fptr = fopen(file_name, "r");
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
    }
    while(ch != EOF);

    char b[200];
    fclose(fptr);
    printf("\n\n");
    ptr = fopen(file_name, "r");
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
        }
        while(ch != b[i]);
        i++;
    }
    while(i < 74);
aa:
    fclose(ptr);
    end = time(NULL);
    diff = end - begin;
    wpm = (i/5)*60/diff;
    float accuracy = ((i-wrong)/(float)i) * 100.0;
    system("cls");
    printf("\n\nYour wpm is: %d", wpm);
    printf("\n The accuracy is: %.2f %c", accuracy, '%');
    printf("Press enter to return to the main menu or escape key to exit");

}





