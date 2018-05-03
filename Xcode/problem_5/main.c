#include <stdio.h>
#include <stdlib.h>

int counter(int bottles[3][3]);


int main()
{
    int bottles[3][3];
    int i, j;
    int sum = 0;
    char binName[3] = {'B', 'G', 'C'};
    int allCombinations[6][3] =  { {0, 2, 1}, {0, 1, 2}, {2,0,1}, {2,1,0}, {1, 0, 2}, {1, 2, 0} } ;
    int totaltimes = 0;
    int sumMove = 0;
    int minimumMove;
    int minMoveIndex = 0;
    
    while(scanf("%d %d %d %d %d %d %d %d %d",
                &bottles[0][0], &bottles[0][1], &bottles[0][2],
                &bottles[1][0], &bottles[1][1], &bottles[1][2],
                &bottles[2][0], &bottles[2][1], &bottles[2][2]) != EOF)
    {
        totaltimes = counter(bottles);
        minimumMove = totaltimes;
        
        
        for (i = 0; i < 6; i++)
        {
            sumMove = totaltimes - (bottles[0][allCombinations[i][0]] + bottles[1][allCombinations[i][1]] + bottles[2][allCombinations[i][2]]);
            
            if (sumMove < minimumMove)
            {
                minimumMove = sumMove;
                minMoveIndex = i;
                
            }
        }
        
        printf("%c%c%c %d\n",
               binName[allCombinations[minMoveIndex][0]],
               binName[allCombinations[minMoveIndex][1]],
               binName[allCombinations[minMoveIndex][2]],  minimumMove);
    }
    return 0;
}

int counter(int bottles[3][3])
{
    int i, j;
    int sum = 0;
    
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            sum += bottles[i][j];
        }
    }
    
    return sum;
}
