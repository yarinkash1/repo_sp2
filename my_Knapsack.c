#include <stdio.h>
#define WEIGHT 20
#define TOTAL_ITEMS 5


//declare functions
int max(int a, int b);
int knapSack(int weights[], int values[], int selected_bool[]);

int main() {
    //declare variables
    int maxValue;
    int current_value;
    int current_weight;
    char items[TOTAL_ITEMS];
    int value [TOTAL_ITEMS];
    int weight[TOTAL_ITEMS];
    int selected_bool[TOTAL_ITEMS]={0,0,0,0,0};
    int i=0;
    //user's inputs:
    for(i=0;i<TOTAL_ITEMS;i++)
    {
        scanf(" %c",&items[i]);
        scanf("%d",&value[i]);
        scanf("%d", &weight[i]);
    }
    //call the function to get the maximum profit from the knapsack problem.
    //inside the function we also find which items chosen to make the best profit.
    //each  selected item will get a 1(true) in the boolean selected_bool.
    maxValue=knapSack(weight,value,selected_bool);

    //print result of maximum value:

    printf("Maximum profit: %d\n",maxValue);

    //print result of selected items:

    printf("Selected items: ");
    for(i=0;i<TOTAL_ITEMS;i++)
    {
        if(selected_bool[i]==1)
        {
            printf("%c ",items[i]);
        }

    }

    return 0;
}

//helper function
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int knapSack(int weights[], int values[],int selected_bool[] ) {

    int numStrings=5;
    //matrix that the first element indicates the number of the items,second the weight
    int dp[numStrings + 1][WEIGHT + 1];

    //init the matrix
    int i = 0;
    int j = 0;
    for (i = 0; i <= numStrings; i++) {
        for (j = 0; j <= WEIGHT; j++) {

            //if we dont have anymore items to see or the bag weight is full than we cant do more profit
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
                // checks if the weight of the current item is less than or equal to the remaining capacity
            else if (weights[i-1]<=j)
            {
                //check if we should add it or not
                //comparing value without adding the item and if we added it
                //if we decide to add we take off the weight of the item from the bag if not we continue like previous step
                dp[i][j] = max(values[i-1] + dp[i-1][j-(int)weights[i-1]], dp[i-1][j]);
            }
            else
            {
                //if the capacity was too much we skip that item
                dp[i][j]=dp[i-1][j];
            }

        }


    }

    int t=0;
    int w= WEIGHT;
    for (t=0; t<numStrings; t++) {
        selected_bool[t]=0;
    }

    //if the following item gave us a bigger profit from previous it means we selected that item
    while(t>0 && w>0) {
        if (dp[t][w] != dp[t-1][w]) {
            selected_bool[t-1]=1;
            w -= weights[t-1];
        }
        t--;
    }

    //get maximum profit
    int max_value = dp[numStrings][WEIGHT];

    return max_value;
}
