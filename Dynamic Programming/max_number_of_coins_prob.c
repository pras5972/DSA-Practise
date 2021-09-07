#include <stdio.h>
#include <stdlib.h>

int max_coins(int coins[], int n, int w)
{
    int max[n][w+1];

    for(int i=0;i<n;i++)
        max[i][0]=1;
    
    for(int j=0;j<=w;j++)
    {
        if(j%coins[0] == 0)
            max[0][j] = 1;
        else    
            max[0][j]=0;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(j<coins[i])
                max[i][j] = max[i-1][j];
            else    
                max[i][j] = max[i-1][j] + max[i][j-coins[i]];
        }
        
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0; j<=w; j++)
    //     {
    //         printf("%d ", max[i][j]);
    //     }
    //     printf("\n");
    // }
    return max[n-1][w];
}
int main()
{
    int n;
    printf("Enter number of coins: ");
    scanf("%d",&n);

    int coins[n];
    printf("Enter coins values: ");
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    
    int w;
    printf("Enter the value:");
    scanf("%d",&w);
    
    printf("Max ways : %d",max_coins(coins,n,w));

}