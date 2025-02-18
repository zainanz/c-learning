#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *createTreeNode(int value)
{
    treeNode *node = malloc(sizeof(treeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

treeNode *findMin(treeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    return root;
}

treeNode *addTreeNode(treeNode *head, int value)
{
    if (head->value > value)
    {
        // printf("%i, %i", head->value, value);
        if (head->left == NULL)
        {
            treeNode *node = createTreeNode(value);
            head->left = node;
        }
        else
        {
            addTreeNode(head->left, value);
        }
    }
    else
    {
        if (head->right == NULL)
        {
            treeNode *node = createTreeNode(value);
            head->right = node;
        }
        else
        {
            addTreeNode(head->right, value);
        }
    }
}

treeNode *removeTreeNode(treeNode *head, int value)
{
    treeNode *cur = head;
    if (head == NULL)
        return NULL;
    if (value > head->value)
    {
        head->right = removeTreeNode(head->right, value);
    }
    else if (value < head->value)
    {
        head->left = removeTreeNode(head->left, value);
    }
    else
    {
        // Free it
        if (head->left == NULL && head->right == NULL)
        {
            free(head);
            return NULL;
        }
        else if (head->left == NULL || head->right == NULL)
        {
            treeNode *temp;
            if (head->left == NULL)
            {
                temp = head->right;
            }
            else
            {
                temp = head->left;
            }
            free(head);
            return temp;
        }
        else
        {
            treeNode *temp = findMin(head->right);
            head->value = temp->value;
            head->right = removeTreeNode(head->right, temp->value);
        }
    }
}

void inOrder(treeNode *head)
{
    if (head != NULL)
    {
        inOrder(head->left);
        printf(" %d ", head->value);
        inOrder(head->right);
    }
}

int main()
{
    treeNode *head = createTreeNode(10);
    printf("Testing createTreeNode(value) Function\n --> Expected: 10 | GOT: %i", head->value);
    addTreeNode(head, 5);
    addTreeNode(head, 10);
    addTreeNode(head, 50);
    printf("\n\nTesting addTreeNode(value)\n");
    printf("  --> expected: 5 | GOT: %i\n", head->left->value);
    printf("  --> expected: 10 | GOT: %i\n", head->right->value);
    printf("  --> expected: 50 | GOT: %i\n", head->right->right->value);
    removeTreeNode(head, 50);
    printf("Removed 50! \n Printing in Order:\n");
    inOrder(head);
    removeTreeNode(head, 5);
    printf("Removed 5! \n Printing in Order:\n");
    inOrder(head);
    removeTreeNode(head, 10);
    inOrder(head);
    return 0;
}
