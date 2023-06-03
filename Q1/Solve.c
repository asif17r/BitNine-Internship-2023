#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Dynamic Programming approach for Fibonacci Sequence
//0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 ...
#define Limit 100000
int fiboArr[Limit];
int fibo(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(fiboArr[n] != 0) return fiboArr[n];
    fiboArr[n] = fibo(n-1) + fibo(n-2);
    return fiboArr[n];
}

typedef enum TypeTag {ADD, SUB, MUL} TypeTag;
typedef struct Node{
    TypeTag type;
    int val;
} Node;

//add function for two numbers
Node* add(int a, int b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = ADD;
    newNode->val = a + b;
    return newNode;
}
//add function for two nodes
Node* addN(Node* a, Node* b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = ADD;
    newNode->val = (b == NULL) ? fibo(a->val) : a->val + b->val;
    return newNode;
}

//sub function for two numbers
Node *sub(int a, int b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = SUB;
    newNode->val = a - b;
    return newNode;
}
//sub function for two nodes
Node *subN(Node* a, Node* b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = SUB;
    newNode->val = (b == NULL) ? fibo(a->val) : a->val - b->val;
    return newNode;
}

//mul function for two numbers
Node *mul(int a, int b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = MUL;
    newNode->val = a * b;
    return newNode;
}
//mul function for two nodes
Node *mulN(Node* a, Node* b){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = MUL;
    newNode->val = (b == NULL) ? fibo(a->val) : a->val * b->val;
    return newNode;
}

//function pointer for two numbers
typedef Node* (*OperationType)(int, int);
OperationType makeFunc(TypeTag type){
    switch(type){
        case ADD:
            return add;
        case SUB:
            return sub;
        case MUL:
            return mul;
    }
}

//function pointer for two nodes
typedef Node* (*OperationTypeN)(Node*, Node*);
OperationTypeN makeFuncN(TypeTag type){
    switch(type){
        case ADD:
            return addN;
        case SUB:
            return subN;
        case MUL:
            return mulN;
    }
}

//print function
void calc(Node* node){
    switch(node->type){
        case ADD:
            printf("add : %d\n", node->val);
            break;
        case SUB:
            printf("sub : %d\n", node->val);
            break;
        case MUL:
            printf("mul : %d\n", node->val);
            break;
    }
}

int main()
{
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFuncN(SUB))(mul, add);
    Node *fibo = (*makeFuncN(SUB))(sub, NULL);
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
}