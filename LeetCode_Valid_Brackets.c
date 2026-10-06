#include <stdio.h>
#include <string.h>

int isValid(char s[]) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {


        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }


        else {
            if (top == -1)
                return 0;

            char open = stack[top--];

            if ((s[i] == ')' && open != '(') ||
                (s[i] == '}' && open != '{') ||
                (s[i] == ']' && open != '[')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[100];

    printf("Enter the string: ");
    scanf("%99s", s);

    printf("%s\n", isValid(s) ? "true" : "false");

    return 0;
}
