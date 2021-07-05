/*ROCK, PAPER, SCISSOR*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void source(); //Taking input and assigning score
void instruction(); //Instruction of game
int greater(char char1, char char2); //Logic building
void result(int u_s, int c_s); //Result delcare
char usr_name[10]; //Global declaration

int main()
{
    printf("-----------------------------\n");
    printf("\tWelcome to \n* ROCK, PAPER & SCISSOR GAME *\n");
    printf("-----------------------------\n");
    instruction();
    printf("Enter your name: ");
    scanf("%s", &usr_name);
    source();

    return 0;
}

void source() 
{
    int usr_score = 0, comp_score = 0, input, i = 0;
    char usr_char, comp_char;
    char dict[] = {'r', 'p', 's'};

    while (i < 3)
    {
        srand(time(NULL)); //To generate the random value
        printf("\n%s selects: ", usr_name);
        scanf("%d", &input);
        usr_char = dict[input - 1]; 
        printf("You choses %c\n\n", usr_char);

        input = rand() % 3;
        printf("Computer selects: %d\n", input + 1);
        comp_char = dict[input];
        printf("Computer choses %c\n\n", comp_char);

        if (greater(usr_char, comp_char) == 1)
        {
            usr_score += 1;
            printf("You nailed it!\n\n\n");
        }
        else if (greater(usr_char, comp_char) == -1)
        {
            comp_score += 1;
            usr_score += 1;
            printf("Its a Draw.\n\n\n");
        }
        else
        {
            comp_score += 1;
            printf("Awwww! Computer made it.\n\n\n");
        }

        i++;
    }
    result(usr_score, comp_score);
}

void instruction() //To only give an instructions of the Game
{
    printf("******************************\n");
    printf("To Select ROCK, input 1\n");
    printf("To Select PAPER, input 2\n");
    printf("To Select SCISSOR, input 3\n");
    printf("******************************\n");
}

int greater(char char1, char char2)
{
    if (char1 == char2)
    {
        return -1;
    }

    if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char1 == 's') && (char2 == 'r'))
    {
        return 0;
    }

    if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char1 == 'r') && (char2 == 'p'))
    {
        return 0;
    }

    if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char1 == 'p') && (char2 == 's'))
    {
        return 0;
    }
}

void result(int u_s, int c_s)
{
    printf("Your score: %d \nComputers score: %d\n\n", u_s, c_s);
    if (u_s > c_s)
        {
            printf("%s is the Winner\n", usr_name);
            printf("\t*****WINNER WINNER CHICKEN DINNER*****");
        }
    else if (u_s < c_s)
    {
        printf("Computer is the Winner\n");
        printf("\tBetter luck next time :-)\n");
    }
    else if (u_s == c_s)
    {
        printf("\tMATCH DRAW\n");
    }
}