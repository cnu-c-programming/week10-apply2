#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node 
{
    char name[16];
    int score;
    struct Node *next;
};
struct Node *head = NULL;

int main() {
    char cmd[16];
    char name[16];
    int score;
    char target[16];
    while (1)
    {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0)
        {
            scanf("%s %d", name, &score);
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            strcpy(newNode->name, name);
            newNode->score = score;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = newNode;
            }
            else {
                struct Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        else if (strcmp(cmd, "delete") == 0)
        {
            scanf("%s", target);
            struct Node *curr = head;
            struct Node *prev = NULL;

            while (curr != NULL)
            {
                if (strcmp(curr->name, target) == 0)
                {
                    if (prev == NULL) { head = curr->next;}
                    else {prev->next = curr->next;}
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        else if (strcmp(cmd, "print") == 0)
        {
            struct Node *curr = head;
            while (curr != NULL)
            {
                printf("%s %d\n", curr->name, curr->score);
                curr = curr->next;
            }
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            break;
        }
        
    }
}
