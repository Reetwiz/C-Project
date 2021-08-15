#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// #include<string.h>

void NewGame();
void ViewScores();
void help();
void about();

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        puts("\t\t\t\t****************************");
        puts("\t\t\t\t   WELCOME TO SPEED TYPER");
        puts("\t\t\t\t****************************\n");
        puts("\t\t\t\t\t1. New Game");
        puts("\t\t\t\t\t2. View Scores");
        puts("\t\t\t\t\t3. Help");
        puts("\t\t\t\t\t4. About developers");
        puts("\t\t\t\t\t5. Exit\n\n");
        printf("Please enter 1 for New Game, 2 for Viewing Scores, 3 for Help, 4 to know about developers and 5 to Exit the game: ");
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
        }
        printf("\n\t\tPress any key to continue: ");
        getch();
    }
}

void NewGame()
{
    char username[20];
    system("cls");
    printf("\t\t\t\t\tEnter your username: ");
    scanf("%s", &username);
    printf("\t\t\t\t\tHi %s, welcome to Speed Typer", username);
}

void ViewScores()
{
    printf("\t\t\t\t\t\tS C O R E S");
    printf("\n\n\tS.N.\tName\t\tMode\t\tText\t\tDate/Time\t\t\tScore(WPM)");
    printf("\n   __________________________________________________________________________________________________________________");
}

void help()
{
    system("cls");
    FILE *ptr;
    char c;
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
    system("cls");
    FILE *fptr;
    char c;
    fptr = fopen("about.txt", "r");
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}
