#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 300

int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply_op(int a, int b, char op, int *div_zero) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            *div_zero = 1;
            return 0;
        }
        return a / b;
    }
    return 0;
}

int main(void) {
    int values[MAX_STACK];
    int val_top = -1;

    char ops[MAX_STACK];
    int ops_top = -1;

    int div_zero = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if (ch == ' ' || ch == '\t') {
            continue;
        }

        if (isdigit(ch)) {
            int val = ch - '0';
            while ((ch = getchar()) != EOF && isdigit(ch)) {
                val = val * 10 + (ch - '0');
            }
            values[++val_top] = val;

            if (ch == EOF || ch == '\n' || ch == '\r') {
                break;
            }
            if (ch == ' ' || ch == '\t') {
                continue;
            }
        }

        if (ch == '(') {
            ops[++ops_top] = '(';
        } 
        else if (ch == ')') {
            int found_open = 0;
            while (ops_top >= 0) {
                if (ops[ops_top] == '(') {
                    found_open = 1;
                    ops_top--;
                    break;
                }
                if (val_top < 1) {
                    puts("ERROR: UNBALANCED");
                    return 0;
                }
                int b = values[val_top--];
                int a = values[val_top--];
                char op = ops[ops_top--];
                int res = apply_op(a, b, op, &div_zero);
                if (div_zero) {
                    puts("ERROR: DIV BY ZERO");
                    return 0;
                }
                values[++val_top] = res;
            }
            if (!found_open) {
                puts("ERROR: UNBALANCED");
                return 0;
            }
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (ops_top >= 0 && ops[ops_top] != '(' && get_precedence(ops[ops_top]) >= get_precedence((char)ch)) {
                if (val_top < 1) {
                    puts("ERROR: UNBALANCED");
                    return 0;
                }
                int b = values[val_top--];
                int a = values[val_top--];
                char op = ops[ops_top--];
                int res = apply_op(a, b, op, &div_zero);
                if (div_zero) {
                    puts("ERROR: DIV BY ZERO");
                    return 0;
                }
                values[++val_top] = res;
            }
            ops[++ops_top] = (char)ch;
        }
    }

    while (ops_top >= 0) {
        if (ops[ops_top] == '(') {
            puts("ERROR: UNBALANCED");
            return 0;
        }
        if (val_top < 1) {
            puts("ERROR: UNBALANCED");
            return 0;
        }
        int b = values[val_top--];
        int a = values[val_top--];
        char op = ops[ops_top--];
        int res = apply_op(a, b, op, &div_zero);
        if (div_zero) {
            puts("ERROR: DIV BY ZERO");
            return 0;
        }
        values[++val_top] = res;
    }

    if (val_top != 0) {
        puts("ERROR: UNBALANCED");
        return 0;
    }

    printf("%d\n", values[0]);
    return 0;
}