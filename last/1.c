#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXWORDS 20

struct tnode {
    char *word;
    int count; 
    struct tnode *left;
    struct tnode *right;
}; 
struct tnode *addtree(struct tnode *, char *);
void tree2array(struct tnode *);
void bubble_sort(struct tnode *[], int);
void arrayprint(struct tnode *[]);
int getword(char *, int);

struct tnode *words[MAXWORDS];
int nword = 0;

int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword (word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    tree2array(root);
    printf("number of words = %d\n\n", nword);
    bubble_sort(words, nword);
    arrayprint(words);
    return 0;
}

void tree2array(struct tnode *p)
{
    if (p != NULL) {
        tree2array (p->left);
        if (nword < MAXWORDS)
            words[nword++] = p;
        tree2array(p->right);
    }
}

void swap(struct tnode *[], int, int);

void bubble_sort(struct tnode *w[], int n) {
    int j, t = 1;
    while (n-- && t)
        for (j = t = 0; j < n; j++) {
            if (w[j]->count >= w[j+1]->count) continue;
            swap(w, j, j+1);
            t = 1;
        }
}

void swap(struct tnode *w[], int i, int j) {
    struct tnode *temp;

    temp = w[i];
    w[i] = w[j];
    w[j] = temp;
}

void arrayprint(struct tnode *w[])
{
    int i;
    for (i = 0; i < nword; i++)
        printf("%4d %s\n", w[i]->count, w[i]->word);
}