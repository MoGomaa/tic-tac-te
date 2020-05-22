#include <stdio.h>
#include <stdlib.h>

void show_Grid(void);
char check_idx(char);
char check_end(void);

char Grid[9] = {'1', '2', '3',
                '4', '5', '6',
                '7', '8', '9'};

int main()
{
    char flag, i;

    char idx;
    char player    = 0;
    char symbol[2] = {'x', 'o'};


    for(i=0 ; i<9 ; ++i)
    {
        show_Grid();

        do
        {
            printf("\nPlayer : %d\n", player+1);
            printf("Select place '%c' : ", symbol[player]);
            flag = scanf("%d", &idx);
            if(flag == 0)
            {
                // Handle char input to %d
                fflush(stdin);
                continue;
            }
        }while(!check_idx(idx));
        Grid[idx-1] = symbol[player];

        if(check_end())
        {
            show_Grid();
            printf("Player %d Wins\n", player+1);
            break;
        }

        player = !player;
    }

    printf("\nGame Over\n");
    return 0;
}

void show_Grid(void)
{
    char r, c;

    for(r=0 ; r<3 ; ++r)
    {
        for(c=0 ; c<3 ; ++c)
        {
            char idx = 3*r + c;
            printf("| %c |", Grid[idx]);
        }
        printf("\n");
    }
}

char check_idx(char idx)
{
    if(idx>=1 && idx<=9)
        if(Grid[idx-1] != 'x'  &&  Grid[idx-1] != 'o')
            return 1;

    printf("Incorrect Place - Try Again\n");
    return 0;
}

char check_end(void)
{
    if(Grid[0]==Grid[1] && Grid[0]==Grid[1])
        return 1;
    if(Grid[3]==Grid[4] && Grid[3]==Grid[5])
        return 1;
    if(Grid[6]==Grid[7] && Grid[6]==Grid[8])
        return 1;

    if(Grid[0]==Grid[3] && Grid[0]==Grid[6])
        return 1;
    if(Grid[1]==Grid[4] && Grid[1]==Grid[7])
        return 1;
    if(Grid[3]==Grid[5] && Grid[3]==Grid[8])
        return 1;

    if(Grid[0]==Grid[4] && Grid[0]==Grid[8])
        return 1;
    if(Grid[2]==Grid[4] && Grid[2]==Grid[6])
        return 1;

    return 0;
}
