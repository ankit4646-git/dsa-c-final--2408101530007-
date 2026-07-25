#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page {
    char url[51];
    struct Page *prev;
    struct Page *next;
} Page;

Page *current = NULL;

void visit(char *url) {
    // Free all pages ahead in history when visiting a new page
    if (current != NULL) {
        Page *walker = current->next;
        while (walker != NULL) {
            Page *temp = walker->next;
            free(walker);
            walker = temp;
        }
        current->next = NULL;
    }

    // Allocate new page
    Page *p = (Page *)malloc(sizeof(Page));
    strcpy(p->url, url);
    p->prev = current;
    p->next = NULL;

    if (current != NULL) {
        current->next = p;
    }
    current = p;
}

void back() {
    if (current == NULL || current->prev == NULL) {
        printf("NO BACK\n");
    } else {
        current = current->prev;
        printf("%s\n", current->url);
    }
}

void forward() {
    if (current == NULL || current->next == NULL) {
        printf("NO FORWARD\n");
    } else {
        current = current->next;
        printf("%s\n", current->url);
    }
}

void print_current() {
    if (current == NULL) {
        printf("NONE\n");
    } else {
        printf("%s\n", current->url);
    }
}

void free_all() {
    // Move to the very first node
    while (current != NULL && current->prev != NULL) {
        current = current->prev;
    }
    // Free all nodes
    while (current != NULL) {
        Page *temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    char cmd[20];
    char url[51];

    for (int i = 0; i < q; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "VISIT") == 0) {
            scanf("%s", url);
            visit(url);
        } else if (strcmp(cmd, "BACK") == 0) {
            back();
        } else if (strcmp(cmd, "FORWARD") == 0) {
            forward();
        } else if (strcmp(cmd, "CURRENT") == 0) {
            print_current();
        }
    }

    free_all();
    return 0;
}