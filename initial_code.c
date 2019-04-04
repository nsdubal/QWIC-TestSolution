#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define STARTLOCATION       '@'
#define ENDOFLIFE           '$'

/* The characteristics */

#define INVERSEPRIORITY     'I'
#define BOUNDARYOBSTACLE    '#'
#define NORMALOBSTACLE      'X'
#define BEERPOWER           'B'
#define TELEPORT            'T'
#define INSTATNTEAST        'E'
#define INSTANTNORTH        'N'
#define INSTANTWEST         'W'
#define INSTANTSOUTH        'S'

#define FALSE 0u
#define TRUE  1u

#define SOUTH 0xAA
#define NORTH 0x55


 typedef struct
 {
     uint8_t line;
     uint8_t column;
 }LG_Location_s;

LG_Location_s InitLocaiton;
LG_Location_s FullMap;
static uint8_t line;
static uint8_t column;

static uint8_t BeerPowerLevel;
static uint8_t InverseActive;
static uint8_t CurrentDirection = SOUTH;

void API_Handle_BoundaryObstacle(void);
void API_Handle_NoramlObstacle(void);
void API_Handle_BeerPower(void);
void API_Handle_Teleport(void);
void API_Handle_Inverse(void);

int main()
{
    int L;
    int C;
    scanf("%d%d", &L, &C); fgetc(stdin);
    for (int i = 0; i < L; i++) {
        char row[102];
        fgets(row, 102, stdin);
    }
    uint8_t map[L][C];
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    /* Find the Starting point in a map */
    for(uint8_t i = 0; i < L ; i++)
    {
        for(uint8_t j = 0; j < C ; j++)
        {
            if(map[i][j] == STARTLOCATION)
            {
                InitLocaiton.line = i;
                InitLocaiton.column = j;
            }
        }
    }
    FullMap.line = L;
    FullMap.column = C;
    line = InitLocaiton.line;
    column = InitLocaiton.column;
    while(1)
    {
        if(CurrentDirection == SOUTH)
        {
            line++;
        }
        else
        {
            line--;
        }
        switch(map[line][column])
        {
            case BOUNDARYOBSTACLE:
                printf("#");
                if(InverseActive == FALSE)
                {
                    if(CurrentDirection == SOUTH)
                    {
                        line--;
                        if((map[line][column + 1] != 'X') || (map[line][column + 1] != '#'))
                        {
                            column++; // To East
                        }
                        else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                        {
                            CurrentDirection = NORTH;
                        }
                        else
                        {
                            column--; // To West
                        }
                    }
                    else
                    {
                        line++;
                        if((map[line][column - 1] != 'X') || (map[line][column - 1] != '#'))
                        {
                            column--; // To west
                        }
                        else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                        {
                            CurrentDirection = SOUTH; // South
                        }
                        else
                        {
                            column++; // To East
                        }
                    }

                }
                    else
                    {
                        if(CurrentDirection == SOUTH)
                        {
                            line--;
                            if((map[line][column - 1] != 'X') || (map[line][column - 1] != '#'))
                            {
                                column--; // To West
                            }
                            else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                            {
                                CurrentDirection = NORTH;
                            }
                            else
                            {
                                column++; // To East
                            }
                        }
                        else
                        {
                            line++;
                            if((map[line][column + 1] != 'X') || (map[line][column + 1] != '#'))
                            {
                               column++; // To East
                            }
                            else if((map[line + 1][column] == 'X') || (map[line][column + 1] == '#'))
                            {
                                CurrentDirection = SOUTH; // South
                            }
                            else
                            {
                                column--; // To west
                            }
                        }
                    }
            break;
            case NORMALOBSTACLE:
                printf("X");
                if(BeerPowerLevel == 1)
                {
                    ;
                }
                else
                {
                    if(InverseActive == FALSE)
                    {
                        if(CurrentDirection == SOUTH)
                        {
                            line--;
                            if((map[line][column + 1] != 'X') || (map[line][column + 1] != '#'))
                            {
                                column++; // To East
                            }
                            else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                            {
                                CurrentDirection = NORTH;
                            }
                            else
                            {
                                column--; // To West
                            }
                        }
                        else
                        {
                            line++;
                            if((map[line][column - 1] != 'X') || (map[line][column - 1] != '#'))
                            {
                                column--; // To west
                            }
                            else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                            {
                                CurrentDirection = SOUTH; // South
                            }
                            else
                            {
                                column++; // To East
                            }
                        }

                    }
                    else
                    {
                        if(CurrentDirection == SOUTH)
                        {
                            line--;
                            if((map[line][column - 1] != 'X') || (map[line][column - 1] != '#'))
                            {
                                column--; // To West
                            }
                            else if((map[line - 1][column] == 'X') || (map[line][column - 1] == '#'))
                            {
                                CurrentDirection = NORTH;
                            }
                            else
                            {
                                column++; // To East
                            }
                        }
                        else
                        {
                            line++;
                            if((map[line][column + 1] != 'X') || (map[line][column + 1] != '#'))
                            {
                               column++; // To East
                            }
                            else if((map[line + 1][column] == 'X') || (map[line][column + 1] == '#'))
                            {
                                CurrentDirection = SOUTH; // South
                            }
                            else
                            {
                                column--; // To west
                            }
                        }
                    }
                }
            break;
            case BEERPOWER:
                API_Handle_BeerPower();
            break;
            case TELEPORT:
                API_Handle_Teleport();
            break;
            case INVERSEPRIORITY:
                API_Handle_Inverse();
            break;
            case INSTATNTEAST:
                column++;
            break;
            case INSTANTNORTH:
                CurrentDirection = NORTH;
            break;
            case INSTANTWEST:
                column--;
            break;
            case INSTANTSOUTH:
                CurrentDirection = SOUTH;
            break;
            default:
            /* This is to handle empty space */
            line++;
            break;
        }
        if(map[line][column] == ENDOFLIFE) // This hadles the sucide stall
        {
            break;
        }
    }

    printf("answer\n");

    return 0;
}

void API_Handle_BeerPower(void)
{
    BeerPowerLevel++;
    if(BeerPowerLevel == 2)
    {
        BeerPowerLevel = 0u;
    }
}
void API_Handle_Teleport(void)
{
 /* Not Supported */
}
void API_Handle_Inverse(void)
{
    InverseActive++;
    if(InverseActive == 2)
    {
        InverseActive = FALSE;
    }
}
