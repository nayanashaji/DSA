#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

struct Node* createNode(char *word, char *meaning) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char *word, char *meaning) {
    if (root == NULL)
        return createNode(word, meaning);
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word '%s' already exists.\n", word);
    return root;
}

struct Node* search(struct Node* root, char *word) {
    if (root == NULL || strcmp(root->word, word) == 0)
        return root;
    if (strcmp(word, root->word) < 0)
        return search(root->left, word);
    else
        return search(root->right, word);
}

void updateMeaning(struct Node* root, char *word, char *newMeaning) {
    struct Node* found = search(root, word);
    if (found) {
        strcpy(found->meaning, newMeaning);
        printf("Meaning of '%s' updated successfully.\n", word);
    } else {
        printf("Word '%s' not found in dictionary.\n", word);
    }
}

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, char *word) {
    if (root == NULL)
        return NULL;
    if (strcmp(word, root->word) < 0)
        root->left = deleteNode(root->left, word);
    else if (strcmp(word, root->word) > 0)
        root->right = deleteNode(root->right, word);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s : %s\n", root->word, root->meaning);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100], newMeaning[100];

    while (1) {
        printf("\n--- DICTIONARY USING BST ---\n");
        printf("1. Insert a word\n");
        printf("2. Search a word\n");
        printf("3. Update meaning\n");
        printf("4. Delete a word\n");
        printf("5. Display dictionary (Inorder)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%[^\n]", word);
                getchar();
                printf("Enter meaning: ");
                scanf("%[^\n]", meaning);
                getchar();
                root = insert(root, word, meaning);
                break;

            case 2:
                printf("Enter word to search: ");
                scanf("%[^\n]", word);
                getchar();
                {
                    struct Node* found = search(root, word);
                    if (found)
                        printf("Meaning: %s\n", found->meaning);
                    else
                        printf("Word not found.\n");
                }
                break;

            case 3:
                printf("Enter word to update: ");
                scanf("%[^\n]", word);
                getchar();
                printf("Enter new meaning: ");
                scanf("%[^\n]", newMeaning);
                getchar();
                updateMeaning(root, word, newMeaning);
                break;

            case 4:
                printf("Enter word to delete: ");
                scanf("%[^\n]", word);
                getchar();
                root = deleteNode(root, word);
                break;

            case 5:
                if (root == NULL)
                    printf("Dictionary is empty.\n");
                else {
                    printf("\nDictionary (sorted):\n");
                    inorderTraversal(root);
                }
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}