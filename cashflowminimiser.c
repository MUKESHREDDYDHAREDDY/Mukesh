#include <stdio.h> 

 

#define MAX_PERSONS 10  // Assuming a maximum of 10 persons, you can change this as needed 

 

int N, edges; 

 

int getMin(int arr[]) { 

    int minInd = 0; 

    for (int i = 1; i < N; i++) 

        if (arr[i] < arr[minInd]) 

            minInd = i; 

    return minInd; 

} 

 

int getMax(int arr[]) { 

    int maxInd = 0; 

    for (int i = 1; i < N; i++) 

        if (arr[i] > arr[maxInd]) 

            maxInd = i; 

    return maxInd; 

} 

 

int minOf2(int x, int y) { 

    return (x < y) ? x : y; 

} 

 

void minCashFlowRec(int amount[]) { 

    int mxCredit = getMax(amount), mxDebit = getMin(amount); 

    if (amount[mxCredit] == 0 && amount[mxDebit] == 0) 

        return; 

 

    int min = minOf2(-amount[mxDebit], amount[mxCredit]); 

    amount[mxCredit] -= min; 

    amount[mxDebit] += min; 

 

    printf("Person %d ---- ( %d ) ----> Person %d\n", mxDebit, min, mxCredit); 

 

    minCashFlowRec(amount); 

} 

 

void minCashFlow(int graph[][MAX_PERSONS]) { 

    int amount[MAX_PERSONS] = {0}; 

 

    for (int p = 0; p < N; p++) 

        for (int i = 0; i < N; i++) 

            amount[p] += (graph[i][p] - graph[p][i]); 

 

    minCashFlowRec(amount); 

} 

 

int main() { 

    printf("ENTER NUMBER OF PERSONS\n"); 

    scanf("%d", &N); 

 

    printf("ENTER NUMBER OF CASHFLOW EDGES\n"); 

     

    int graph[MAX_PERSONS][MAX_PERSONS] = {0};  // Initializing the graph matrix 

 

    for (int i = 0; i < edges; i++) { 

        int row, column, random; 

        printf("Enter edge details (row column random): "); 

        scanf("%d %d %d", &row, &column, &random); 

        graph[row][column] = random; 

        printf("%d ---(%d)--->%d\n", row, graph[row][column], column); 

    } 

 

    printf("\n"); 

    printf("MINIMIZED DATA\n"); 

    minCashFlow(graph); 

 

    return 0; 

} 
