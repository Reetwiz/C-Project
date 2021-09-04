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
void challenge_mode(char [],int, int);
void tutor_mode(char [],int, int);
void death_mode(char [],int, int);
void SaveProgress(char [],int,int);

int string_length(char *);
void removeDuplicates(char *);
void removeAll(char *, const char, int );
void strdpl(char* );
void append(char*, char );

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
        exit(1);

    default:
        printf("\n\t\tERROR!! Please select 1, 2, 3, 4 or 5.");
        Sleep(1000);
        goto ChooseOpt;
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
        strcat(mode,"Death mode");
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

void NewGame()
{
    system("cls");
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
    //system("color ");
    system("cls");
    int length;
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
        length = 16;
        break;
    case 2:
        file_name[1]='2';
        length = 22;
        break;
    case 3:
        file_name[1]='3';
        length = 21;
        break;
    case 4:
        file_name[1]='4';
        length = 36;
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
    printf("\t\t\t\t\t\t1. Tutor Mode \n\t\t\t\t\t\t2. Challenge Mode \n\t\t\t\t\t\t3. Death Mode\n");
    printf("\n\t\t\t\t\t\tOr Press 4 to return to main menu or 5 to go back\n");
    printf("\n\t\t\t\t\t\tSelect Your Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        tutor_mode(file_name,choice, length);
        break;
    case 2:
        challenge_mode(file_name,choice, length);
        break;
    case 3:
        death_mode(file_name,choice, length);
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

void challenge_mode(char file_name[7],int choice, int length)
{
    while(1)
    {

        int i = 0,wrong = 0, j, begin, end, diff, wpm;
        char ch,c, sel;
        FILE *fptr, *ptr;
        system("cls");
        fptr = fopen(file_name, "r");
        if (fptr == NULL)
        {
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        do
        {
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
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        do
        {
            if (i == 1)
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
        while(i < length);
        end = time(NULL);
        diff = end - begin;
        wpm = (length/5)*60/diff;
        float accuracy = ((length-wrong)/(float)length) * 100.0;
        printf("\n\t\t\t\t\t\tLoading:");
    int mk=0;
    for (i = 0; mk < 15; mk++)
    {
        printf("-");
        Sleep(60);
    }
        system("cls");
        puts("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************");
        printf("\n\n\t\t\t\t\t\tWords Per Minute(WPM): %d", wpm);
        printf("\n\t\t\t\t\t\tAccuracy             : %f\n\n\n", accuracy);
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

void tutor_mode(char file_name[7],int choice, int length)
{
    while(1)
    {
        int i = 0, begin, end, diff, j, wrong = 0, k=0;
        int wpm;
        char ch, sel;
        char *mistakes = strdup("");
        FILE *fptr;
        system("cls");
        fptr = fopen(file_name, "r");
        if (fptr == NULL)
        {
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        do
        {
            printf("%c", ch);
            ch = fgetc(fptr);
        }
        while(ch != EOF);
        char b[200];
        rewind(fptr);
        printf("\n\n\tYour Input: ");


        do
        {

            ch = getc(fptr);

            do
            {

                b[i] = getch();
                if (i == 1)
                    begin = time(NULL);
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
        while(i < length);
aa:
        fclose(fptr);
        end = time(NULL);
        diff = end - begin;
        wpm = (length/5)*60/diff;
        float accuracy = ((length-wrong)/(float)length) * 100.0;
        strdpl(mistakes);
        removeDuplicates(mistakes);
        system("cls");
        puts("\n\n\n\n\n\n\n\n\t\t\t\t\t*********************************************");
        printf("\n\t\t\t\t\t\tTime taken           : %d seconds", diff);
        printf("\n\t\t\t\t\t\tWords Per Minute(WPM): %d", wpm);
        printf("\n\t\t\t\t\t\tAccuracy             : %.2f %c", accuracy, '%');
        printf("\n\t\t\t\t\t\tNumber of mistakes   : %d", wrong);
        printf("\n\t\t\t\t\t\tYour weak keys       : ");
        for (i=0;i<string_length(mistakes);i++) printf("%c ", mistakes[i]);
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

void death_mode(char file_name[7],int choice, int length)
{
    while(1)
    {

        int i = 0, begin, end, diff, j;
        int wpm;
        char ch=0, sel;
        system("cls");
        FILE *fptr, *ptr;
        fptr = fopen(file_name, "r");
        if (fptr == NULL)
        {
            fprintf(stderr,"The program cannot be run. Please check if the text files are in the same directory as the program");
            printf("\n\n\n Press enter key to return to main menu");
            fflush(stdin);
            ch=getchar();
            if (ch=='\n') mainmenu();
        }
        puts("\t\t\t\t\t\t*****************************");
        printf("\n\t\t\t\t\t\t     Enter the given text\n");
        puts("\n\t\t\t\t\t\t*****************************");
        printf("\t");
        do
        {
            printf("%c", ch);
            ch = fgetc(fptr);
        }
        while(ch != EOF);

        char b[200];
        fclose(fptr);
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
            if (i == 1)
                begin = time(NULL);
            ch = getc(ptr);

            do
            {
                if (ch ==EOF) goto a3;
                b[i] = getch();
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
        while(i < length);
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

//definitions for string functions

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

void strdpl(char* string)
{
    int i=0,j=0,k=0;
    for(i = 0; i < string_length(string); i++)
    {
        for(j = i + 1; string[j] != '\0'; j++)
        {
            if(string[j] == string[i])
            {
                for(k = j; string[k] != '\0'; k++)
                {
                    string[k] = string[k + 1];
                }
            }
        }
    }
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
