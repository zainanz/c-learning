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

treeNode *addTreeNode(treeNode *head, int value)
{

    if (!head)
    {
        printf("last got here");
        treeNode *node = createTreeNode(value);
        head = node;
        printf("%p", head);
    }
    else
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

    // treeNode *testNode = NULL;
    // printf("%p", testNode);
    // addTreeNode(testNode, 10);
    // printf("Testing addTreeNode with null head: --> Expected: 10 | GOT: %i", testNode->value);
    return 0;
}
