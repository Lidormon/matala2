#include <stdio.h>

#define N 5
#define W 20


int dp[N+1][W+1];


int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int weights[], int values[], int selected_bool[]) {
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int i = N, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        }
        i--;
    }
    
    
    return dp[N][W];
}

int main() {
    int i = 0;
    int weights[N];
    int values[N];
    char items[N];
    int selected_bool[N]={0};
    while(i<N){
       
        items[i] = getchar();
        
        scanf("%d",&values[i]);
       
        scanf("%d",&weights[i]);
        getchar(); // Skipping enter press deleting from buffer;
    i++;}

    int max_profit = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n",max_profit);
    printf("Selected items:");
    for (i = 0; i < N; i++) {
        if (selected_bool[i]) {
            printf(" %c", items[i]);
            
        }
    }
    return 0;
}
