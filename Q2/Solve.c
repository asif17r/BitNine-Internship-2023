#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Itrative approach
int getValueItr(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    int a = 0, b = 1, c = 2;
    for(int i = 3; i <= n; i++){
        int newNum = b + a;
        a = b;
        b = c;
        c = newNum;   
    }
    return c;
}


//Dynamic Programming approach
#define Limit 100000
int DP[Limit];
int getValueDp(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(DP[n] != 0) return DP[n];
    return DP[n] = getValueDp(n-2) + getValueDp(n-3);
}

//matrix exponentiation approach
void printMatrix(int a[3][3]){
    printf("The matrix is\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
}

//function for matrix multiplication
void mul(int a[3][3], int b[3][3]){
    int temp[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    memcpy(a, temp, sizeof(temp));
}

//function for binary exponentiation with matrix
void power(int a[3][3], int b){
    int ans[3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //identity matrix
    while(b){
        if(b & 1) mul(ans, a);
        mul(a, a);
        b /= 2;
    }
    memcpy(a, ans, sizeof(ans));
}

int getValueMatrixExpo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    int base[3][3] = {{2,1,0},{0,0,0},{0,0,0}};
    int trans[3][3] = {{0,1,0},{1,0,1},{1,0,0}};
    n -= 2;
    power(trans, n);
    mul(base, trans);
    return base[0][0];
}

int main(){
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    printf("The %dth number using DP %d\n", n,getValueDp(n));
    printf("The %dth using Itrative Approach %d\n",n, getValueItr(n));
    printf("The %dth using Matrix Exponentiation %d\n",n, getValueMatrixExpo(n));
}
