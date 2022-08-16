#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char box[10] = {'o','1','2','3','4','5','6','7','8','9'};
int win[3]={0,0,0};
int round=1;
int checkwin();
void grid();


int main()
{
int choice;
while(1){
system("cls");
printf("\n\n\n\t1.Play With Player.\n\n\t2.Play With Computer.\n\n\tEnter A choice: ");
scanf("%d",&choice);
if (choice==1)
{
    playwithPlayer();
    break;
}
else if (choice==2)
{
    playwithcomp();
    break;
}
else
    printf("\n\tInvalid Input, Try Again!");
    sleep(2);
}
return 0;

}
void playwithcomp(){

while(round<=3){

    int player = 1, i, choice;
    char mark;
    int chs[10]={0,1,2,3,4,5,6,7,8,9,10};

    do
    {
        grid();

        if(player % 2==1)
            player=1;
        else player=2;
        if(player==1)
        {printf("\tPlayer 1, enter a number:  ");}
        else
        {
            printf("\tComputer Is Placing it's Move");
        }
        if(player==1)
        {scanf("%d", &choice);
        chs[choice]=0;
        }
        else
        {
         while(1)
         {
        choice = rand()%10;
        if(chs[choice]!=0)
        {
            break;
        }

         }

        }
         if (player == 1)
            mark ='X' ;
            else
            {
            sleep(2);
            mark='O';
            }



        if (choice == 1 && box[1] == '1')
            box[1] = mark;

        else if (choice == 2 && box[2] == '2')
            box[2] = mark;

        else if (choice == 3 && box[3] == '3')
            box[3] = mark;

        else if (choice == 4 && box[4] == '4')
            box[4] = mark;

        else if (choice == 5 && box[5] == '5')
            box[5] = mark;

        else if (choice == 6 && box[6] == '6')
            box[6] = mark;

        else if (choice == 7 && box[7] == '7')
            box[7] = mark;

        else if (choice == 8 && box[8] == '8')
            box[8] = mark;

        else if (choice == 9 && box[9] == '9')
            box[9] = mark;

        else
        {
            printf("\tInvalid move ");
            player--;
            getch();
        }
        i = checkwin();
        player++;
}
while (i ==  - 1);
    grid();

    if (i == 1)
    {
       printf("\tPlayer %d won the round. \n",--player);
       win[player]+=1;
       box[1]='1',box[2]='2',box[3]='3',box[4]='4',box[5]='5',box[6]='6',box[7]='7',box[8]='8',box[9]='9';
    }


    else
        {
        win[1]++;
        win[2]++;
        printf("\tDraw");
        box[1]='1',box[2]='2',box[3]='3',box[4]='4',box[5]='5',box[6]='6',box[7]='7',box[8]='8',box[9]='9';
        }
    round++;
    getch();
}

printf("\n\tPlayer 1: %d pts \n\tPlayer 2: %d pts \n",win[1],win[2]);

if(win[1]>win[2]){printf("\n\tPlayer 1 Wins.\n\n\n\n");}

else if (win[1]<win[2]){printf("\nPlayer 2 Wins.\n\n\n\n\n");}

else {printf("\nIt's A Draw");}

}
void playwithPlayer(){

while(round<=3){

    int player = 1, i, choice;
    char mark;

    do
    {
        grid();

        if(player % 2==1)
            player=1;
        else player=2;
        printf("\tPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);
         if (player == 1)
            mark ='X' ;
            else
            mark='O';



        if (choice == 1 && box[1] == '1')
            box[1] = mark;

        else if (choice == 2 && box[2] == '2')
            box[2] = mark;

        else if (choice == 3 && box[3] == '3')
            box[3] = mark;

        else if (choice == 4 && box[4] == '4')
            box[4] = mark;

        else if (choice == 5 && box[5] == '5')
            box[5] = mark;

        else if (choice == 6 && box[6] == '6')
            box[6] = mark;

        else if (choice == 7 && box[7] == '7')
            box[7] = mark;

        else if (choice == 8 && box[8] == '8')
            box[8] = mark;

        else if (choice == 9 && box[9] == '9')
            box[9] = mark;

        else
        {
            printf("\tInvalid move ");
            player--;
            getch();
        }
        i = checkwin();
        player++;
}
while (i ==  - 1);
    grid();

    if (i == 1)
    {
       printf("\tPlayer %d won the round. \n",--player);
       win[player]+=1;
       box[1]='1',box[2]='2',box[3]='3',box[4]='4',box[5]='5',box[6]='6',box[7]='7',box[8]='8',box[9]='9';
    }


    else
        {
        win[1]++;
        win[2]++;
        printf("\tDraw");
        box[1]='1',box[2]='2',box[3]='3',box[4]='4',box[5]='5',box[6]='6',box[7]='7',box[8]='8',box[9]='9';
        }
    round++;
    getch();
}

printf("\n\tPlayer 1: %d pts \n\tPlayer 2: %d pts \n",win[1],win[2]);

if(win[1]>win[2]){printf("\n\tPlayer 1 Wins.\n\n\n\n");}

else if (win[1]<win[2]){printf("\nPlayer 2 Wins.\n\n\n\n\n");}

else {printf("\nIt's A Draw");}

}


int checkwin()
{

     if (box[1] == box[2] && box[2] == box[3])
       return 1;

     else if (box[4] == box[5] && box[5] == box[6])
       return 1;

     else if (box[7] == box[8] && box[8] == box[9])
       return 1;

     else if (box[1] == box[4] && box[4] == box[7])
       return 1;

     else if (box[2] == box[5] && box[5] == box[8])
        return 1;

     else if (box[3] == box[6] && box[6] == box[9])
        return 1;

     else if (box[1] == box[5] && box[5] == box[9])
        return 1;

     else if (box[3] == box[5] && box[5] == box[7])
       return 1;

     else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
       return 0;

     else
       return  - 1;
}



void grid()
{
    system("cls");
    printf("\n\n\t\tTic Tac Toe\n\n");
    printf("\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");
    printf("\t       Round: %d\n\n",round);
    printf("\t       |     |     \n");
    printf("\t    %c  |  %c  |  %c \n", box[1], box[2], box[3]);
    printf("\t  _____|_____|_____\n");
    printf("\t       |     |     \n");
    printf("\t    %c  |  %c  |  %c \n", box[4], box[5], box[6]);
    printf("\t  _____|_____|_____\n");
    printf("\t       |     |     \n");
    printf("\t    %c  |  %c  |  %c \n", box[7], box[8], box[9]);
    printf("\t       |     |     \n\n");
}

