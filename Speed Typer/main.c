#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>     // To calculate time difference and get current local time
#include<Windows.h>  // For Beep() and Sleep() functions

void mainmenu();
void about();
void NewGame();
void ViewScores();
void help();

void select_text();

void challenge_mode(char [],int);
void tutor_mode(char [],int);
void survival_mode(char [],int);
int count(char []);

int string_length(char *);
void removeDuplicates(char *);
void removeAll(char *, const char, int );
void append(char*, char );

void SaveProgress(char [],int,int);

char username[35];

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
    system("COLOR 09");
    puts("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************");
    puts("\t\t\t\t\t\t   WELCOME TO SPEED TYPER");
    puts("\t\t\t\t\t\t****************************\n");
    puts("\t\t\t\t\t\t1. New Game");
    puts("\t\t\t\t\t\t2. View Scores");
    puts("\t\t\t\t\t\t3. Help");
    puts("\t\t\t\t\t\t4. About developers");
    puts("\t\t\t\t\t\t5. Exit\n\n");
    printf("\t\t\t\t\t\tPlease enter Your Choice: ");
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
        exit(0);

    default:
        printf("\n\t\t\t\t\t\Invalid Option! Please select 1, 2, 3, 4 or 5.");
        Sleep(2000);
        goto ChooseOpt;
    }
}

void NewGame()
{
    system("cls");
    system("COLOR 09");
    puts("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************");
    puts("\t\t\t\t\t\t\t    User");
    puts("\t\t\t\t\t\t****************************\n");
    printf("\t\t\t\t\t\tEnter your first name: ");
    scanf("%s", &username);
    puts("\n\n\t\t\t\t\t\t*****************************\n\n");
    printf("\t\t\t\t\t\tHi %s, welcome to Speed Typer\n", username);
    select_text();
}

void help()
{
    system("COLOR 06");
    FILE *ptr;
    char c, choice;
    system("cls");
    ptr = fopen("help.txt", "r");
    c = fgetc(ptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(ptr);
    }
    fclose(ptr);
    printf("\n\n\n Press enter key to return to main menu");
    fflush(stdin);
    choice=getchar();
    if (choice=='\n') mainmenu();
}

void about()
{
    system("COLOR 06");
    FILE *fptr;
    char c,choice;
    system("cls");
    fptr = fopen("about.txt", "r");
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\n Press enter key to return to main menu");
    fflush(stdin);
    choice=getchar();
    if (choice=='\n') mainmenu();
}

//Text and Mode Selection Menu

void select_text()
{
    printf("\n\t\t\t\t\t\tLoading:");
    int i=0;
    for (i = 0; i < 15; i++)
    {
        printf("-");
        Sleep(60);
    }
selecttext:
    system("color 09");
    system("cls");
    int choice;
    char file_name[7]="cx.txt";
    puts("\n\n\n\n\n\n\n\t\t\t\t\t\t");
    puts("\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t       Texts Available\n\n");
    puts("\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t1. Lowercase Letters \n\t\t\t\t\t\t2. Mixed Alphabets \n\t\t\t\t\t\t3. Punctuations \n\t\t\t\t\t\t4. Numbers\n");
    printf("\n\t\t\t\t\t\tOr Press 5 to return to main menu\n");
    printf("\n\t\t\t\t\t\tSelect Your Choice: ");
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
    case 5:
        mainmenu();
        break;
    default:
        printf("Invalid Option");
        goto selecttext;
    }
selectmode:
    system("cls");
    puts("\n\n\n\n\n\n\n\t\t\t\t\t\t");
    puts("\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t     Please Select a Mode:\n\n");
    puts("\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t1. Tutor Mode \n\t\t\t\t\t\t2. Challenge Mode \n\t\t\t\t\t\t3. Survival Mode\n");
    printf("\n\t\t\t\t\t\tOr Press 4 to return to main menu or 5 to go back\n");
    printf("\n\t\t\t\t\t\tSelect Your Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        tutor_mode(file_name,choice);
        break;
    case 2:
        challenge_mode(file_name,choice);
        break;
    case 3:
        survival_mode(file_name,choice);
        break;
    case 4:
        mainmenu();
        break;
    case 5:
        goto selecttext;
    default:
        printf("Invalid Option");
        Sleep(1);
        goto selectmode;
    }
}

//definitions for modes

void tutor_mode(char file_name[7],int choice)
{
    while(1)
    {
        system("color 0F");
        int i = 0, begin, end, diff, j, wrong = 0, totalcharacters, k=0;
        int wpm;
        char ch=0, sel;
        char *mistakes = strdup("");
        FILE *fptr;
        system("cls");
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        totalcharacters = count(file_name);
        char b[200];
        fptr = fopen(file_name,"r");
        printf("\n\n\tYour Input: ");


        do
        {

            ch = getc(fptr);

            do
            {

                b[i] = getch();
                if (i == 0)
                    begin = time(NULL);
                if (b[i] == 27)
                    mainmenu();
                if (b[i] == 13)
                    goto aa;
                if (ch == b[i])
                    putch(b[i]);
                else if (ch != b[i])
                {
                    wrong++;
                    Beep(880,50);
                    append(mistakes,b[i]);
                }

            }
            while(ch != b[i]);
            i++;
        }
        while(i < totalcharacters);
aa:
        i++;
        fclose(fptr);
        end = time(NULL);
        diff = end - begin;
        wpm = (i/5)*60/diff;
        float accuracy = ((i-wrong)/(float)i) * 100.0;
        removeDuplicates(mistakes);
        system("cls");
        puts("\n\n\n\n\n\n\n\n\t\t\t\t\t*********************************************");
        printf("\n\t\t\t\t\t\tTime taken           : %d seconds", diff);
        printf("\n\t\t\t\t\t\tWords Per Minute(WPM): %d", wpm);
        printf("\n\t\t\t\t\t\tAccuracy             : %.2f %c", accuracy, '%');
        printf("\n\t\t\t\t\t\tNumber of mistakes   : %d", wrong);
        printf("\n\t\t\t\t\t\tYour weak keys       : ");
        for (i=0; i<string_length(mistakes); i++) printf("%c ", mistakes[i]);
        puts("\n\n\t\t\t\t\t*********************************************");
        printf("\n\t\t\t\t\t\tPress Y to store record\n\t\t\t\t\t\tPress N to return to the main menu\n\t\t\t\t\t\tPress any key to replay");
        printf("\n\n\t\t\t\t\t\tSelect Your Choice: ");
        fflush(stdin);
        sel=getchar();
        if (sel=='Y')
        {
            SaveProgress(file_name,wpm,choice);
            break;
        }
        else if (sel=='N')
        {
            mainmenu();
            break;
        }
    }

}

void challenge_mode(char file_name[7],int choice)
{
    while(1)
    {
        system("color 0F");

        int i = 0, totalcharacters,wrong = 0, j, begin, end, diff, wpm;
        char ch=0,c, sel;
        FILE *ptr;
        system("cls");
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        totalcharacters = count(file_name);
        char b[150];
        printf("\n\n");
        ptr = fopen(file_name, "r");
        if (ptr == NULL)
        {
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        do
        {

            ch = getc(ptr);

            do
            {
aa:
                b[i] = getch();
                if (i == 0)
                    begin = time(NULL);
                if (b[i] == 27)
                    mainmenu();

                putch(b[i]);
                if (ch != b[i] && b[i] != 8)
                {
                    do
                    {
                        c = getch();
                    }
                    while (c != 8);
                    printf("\b \b");
                    wrong++;
                }

            }
            while(ch != b[i]);
            i++;
        }
        while(i < totalcharacters);
        end = time(NULL);
        diff = end - begin;
        wpm = (totalcharacters/5)*60/diff;
        float accuracy = ((totalcharacters-wrong)/(float)totalcharacters) * 100.0;
        system("cls");
        puts("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************");
        printf("\n\n\t\t\t\t\t\tWords Per Minute(WPM): %d", wpm);
        printf("\n\t\t\t\t\t\tAccuracy             : %.2f\n\n\n", accuracy);
        puts("\n\n\t\t\t\t\t\t****************************");
        printf("\n\t\t\t\t       Press Y to store record or N to return to the main menu:");
        fflush(stdin);
        sel=getchar();
        if (sel=='Y')
        {
            SaveProgress(file_name,wpm,choice);
            break;
        }
        else if (sel=='N')
        {
            mainmenu();
        }
    }
}

void survival_mode(char file_name[7],int choice)
{
    while(1)
    {
        system("color 0F");

        int i = 0, begin, end, diff, j, totalcharacters;
        int wpm;
        char ch=0, sel;
        system("cls");
        FILE *ptr;
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        totalcharacters = count(file_name);
        char b[200];
        printf("\n\n\tYour Input: ");
        ptr = fopen(file_name, "r");
        if (ptr == NULL)
        {
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        do
        {

            ch = getc(ptr);

            do
            {
                if (ch ==EOF) goto a3;
                b[i] = getch();
                if (i == 0)
                    begin = time(NULL);
                if (ch == b[i])
                    putch(b[i]);
                else if (ch != b[i])
                {
                    printf("\n\nOops! You entered %c instead of %c", b[i], ch);
                    Sleep(1500);
                    goto b2;
                }
            }
            while(ch != b[i]);
            i++;
        }
        while(i < totalcharacters);
a3:
        fclose(ptr);
        end = time(NULL);
        diff = end - begin;
        wpm = (i/5.0)*60/diff;

        system("cls");

        puts("\n\n\n\n\n\n\n\n\t\t\t\t\t\t*******************************");
        printf("\n\t\t\t\t\t\tCongratulations! You passed\n\t\t\t\t\t\t\tthe Challenge ");
        puts("\n\n\t\t\t\t\t\t*******************************");
        printf("\n\t\t\t\t\t\tTime taken           : %d seconds", diff);
        printf("\n\t\t\t\t\t\tWords Per Minute(WPM): %d", wpm);

        puts("\n\n\t\t\t\t\t\t****************************");
        printf("\n\t\t\t\t\t\tPress Y to store record\n\t\t\t\t\t\tPress N to return to the main menu\n\t\t\t\t\t\tPress any key to replay");
        printf("\n\n\t\t\t\t\t\tSelect Your Choice: ");
        fflush(stdin);
        sel=getchar();
        if (sel=='Y')
        {
            SaveProgress(file_name,wpm,choice);
            break;
        }
        else if (sel=='N')
        {
            mainmenu();
        }
        else continue;

b2:
        fclose(ptr);
        printf("\n\t\t\t\t\t\tPress N to return to the main menu\n\t\t\t\t\t\tPress any key to replay:");
        printf("\n\n\t\t\t\t\t\tSelect Your Choice: ");
        fflush(stdin);
        sel=getchar();
        if (sel=='N')
        {
            mainmenu();
        }
    }
}

// counts and returns the number of characters in the file
int count(char filename[])
{
    FILE *ptr;
    char c;
    int totalcharacters = -1;
    ptr = fopen(filename,"r");
    if (ptr == NULL)
    {
        fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
        printf("\n\n\n Press enter key to return to main menu");
        fflush(stdin);
        c=getchar();
        if (c=='\n') mainmenu();
    }
    do
    {
        c = fgetc(ptr);
        printf("%c", c);
        totalcharacters++;
    }
    while(c != EOF);
    fclose(ptr);
    return totalcharacters;
}

//definitions to show weak keys
int string_length(char* string)
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

void append(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void removeDuplicates(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        removeAll(str, str[i], i + 1);
        i++;
    }
}

void removeAll(char* str, const char toRemove, int index)
{
    int i;
    while(str[index] != '\0')
    {
        if(str[index] == toRemove)
        {
            /* Shift all characters from current position to one place left */
            i = index;
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        }
        else
        {
            index++;
        }
    }
}

//Store Records
void SaveProgress(char file_name[7],int wpm,int choice)
{
    FILE *progress=NULL,*tocount=NULL;
    char mode[100]="",text[100]="";
    char ch=NULL;
    int lines=1,n;
    tocount=fopen("SAVE.txt","r");
    while (ch!=EOF)
    {
        if (ch=='\n')
            lines++;
        ch=fgetc(tocount);
    }
    fclose(tocount);
    time_t Time;
    time(&Time);
    switch(file_name[1])
    {
    case '1':
        strcat(text,"Lowercase Letters");
        break;
    case '2':
        strcat(text,"Mixedcase Alphabets");
        break;
    case '3':
        strcat(text,"Punctuation");
        break;
    case '4':
        strcat(text,"Numbers");
        break;
    default:
        break;
    }
    //1. Tutor Mode \n2. Challenge Mode \n3. Death Mode
    switch(choice)
    {
    case 1:
        strcat (mode,"Tutor mode");
        break;
    case 2:
        strcat (mode,"Challenge mode");
        break;
    case 3:
        strcat(mode,"Survival mode");
        break;
    default:
        break;
    }
    n=(lines-1)/2;
    progress=fopen("SAVE.txt","a");
    fprintf(progress,"\t%-7d%-10s\t%-15s\t%-20s\t%-15d%-35s\n",(lines-n),username,mode,text,wpm,ctime(&Time));
    fclose(progress);
    ViewScores();
}

void ViewScores()
{
    system("COLOR 09");
    system("cls");
    printf("\t\t\t\t\t\tS C O R E S");
    printf("\n\n\tS.N\tName\t\tMode\t\tText\t\t\tScore(WPM)\t\tDate/Time");
    printf("\n   __________________________________________________________________________________________________________________\n");
    FILE *progress;
    char c=NULL, choice;
    progress=fopen("SAVE.txt","r");
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(progress);
    }
    fclose(progress);
    printf("\n\n\n Press enter key to return to main menu");
    fflush(stdin);
    choice=getchar();
    if (choice=='\n') mainmenu();
}

