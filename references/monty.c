#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void pall() {
    for (int i = top; i >= 0; --i) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    FILE *file = fopen("bytecodes/00.m", "r");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char instruction[50];
    int value;

    while (fscanf(file, "%s", instruction) != EOF) {
        if (strcmp(instruction, "push") == 0) {
            fscanf(file, "%d", &value);
            push(value);
        } else if (strcmp(instruction, "pall") == 0) {
            pall();
        } // Add more instructions as needed
    }

    fclose(file);

    return 0;
}
