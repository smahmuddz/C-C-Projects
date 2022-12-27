# Infix to Postfix Calculator Using C

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
```

These lines include the necessary header files for the program. The **`stdio.h`**header file provides functions for input and output, such as **`printf`**and **`scanf`**. The **`string.h`**header file provides functions for manipulating strings, such as **`strlen`**. The **`ctype.h`**header file provides functions for classifying and manipulating characters, such as **`isalpha.`**

```c
#define MAX_EXPR_SIZE 100
```

This line defines a constant called **`MAX_EXPR_SIZE`**with a value of 100. This constant is used to specify the maximum size of the infix and postfix expressions.

```c
char stack[MAX_EXPR_SIZE];
int top = -1;
```

These lines define the **`stack`**array and the **`top`**variable. The **`stack`**array is used to store operators as they are encountered in the infix expression. The **`top`**variable is used to keep track of the top element in the stack. It is initialized to -1 to indicate that the stack is empty.

```c
void push(char c) {
    stack[++top] = c;
}
```

This function adds a character to the top of the stack. It takes a single argument, **`c`**, which is the character to be added to the stack. The **`top`**variable is incremented before the character is added to the stack, so the new character becomes the top element.

```c
char pop() {
    return stack[top--];
}
```

This function removes and returns the top element from the stack. The **`top`** variable is decremented after the element is returned, so the element below it becomes the top element.

```c
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}
```

This function returns the precedence of an operator. Operators with higher precedence are popped from the stack before operators with lower precedence. The **`^`** operator has the highest precedence, followed by **`*`** and **`/`**, and then **`+`** and **`-`**. All other operators have precedence of -1.

```c
void infix_to_postfix(char* infix, char* postfix) {
    int i, j;
    int infix_len = strlen(infix);

    for (i = 0, j = 0; i < infix_len; i++) {
        if (isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the '('
        } else {
    while (precedence(stack[top]) >= precedence(infix[i])) {
        postfix[j++] = pop();
    }
    push(infix[i]);
}
```

If the current character in the infix string is an operator, it is compared to the operator at the top of the stack. If the operator at the top of the stack has higher precedence, it is popped from the stack and added to the postfix string. If the operator at the top of the stack has lower precedence, the new operator is pushed onto the stack.

```c
while (top != -1) {
    postfix[j++] = pop();
}

postfix[j] = '\0';  // Null terminate the postfix string
```

When the end of the infix string is reached, all remaining operators on the stack are popped and added to the postfix string. The postfix string is then null terminated to indicate the end of the string.

```c
int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
```

The **`main`** function reads an infix expression from the user and calls the **`infix_to_postfix`**
function to convert it to a postfix expression. The postfix expression is then printed to the console. The **`main`**function returns 0 to indicate that the program completed successfully.