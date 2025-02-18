#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *members;
    int length;
} Set;

bool is_empty(Set *set);
bool sub_set(Set *setA, Set *setB);
void delete_set(Set *set);
void insert(Set *set, int member);
void print_set(Set *set);
Set *init();
Set *make_copy(Set *set);
Set *set_union(Set *setA, Set *setB);
Set *set_intersection(Set *setA, Set *setB);
Set *set_difference(Set *setA, Set *setB);

// Just to avoid for looping when im certain there are no copies.
void custom_insert(Set *set, int value);

int main()
{
    Set *setA = init();

    if (is_empty(setA))
        printf("It's an empty set\n");
    else
        printf("Set is not empty\n");
    printf("Set A: ");
    insert(setA, 1);
    insert(setA, 2);
    insert(setA, 3);
    insert(setA, 4);
    insert(setA, 4);
    print_set(setA);

    printf("Set B: ");
    Set *setB = init();
    insert(setB, 2);
    insert(setB, 5);
    insert(setB, 7);
    insert(setB, 6);
    insert(setB, 1);
    print_set(setB);

    printf("Union Set: ");
    Set *union_set = set_union(setA, setB);
    print_set(union_set);

    printf("Intersection Set: ");
    Set *intersect = set_intersection(setA, setB);
    print_set(intersect);

    printf("Difference Set: A - B:\n-> ");
    Set *difference = set_difference(setA, setB);
    print_set(difference);

    printf("Difference Set: B - A:\n-> ");
    difference = set_difference(setB, setA);
    print_set(difference);
    return 0;
}

// Methods:

bool is_empty(Set *set)
{
    return set->length == 0;
}

Set *init()
{
    Set *new_set = malloc(sizeof(Set));
    new_set->length = 0;
    new_set->members = malloc(sizeof(int));
    return new_set;
}

void delete_set(Set *set)
{
    free(set->members);
    free(set);
}

void insert(Set *set, int member)
{
    bool in_set = false;
    for (int i = 0; i < set->length; i++)
    {
        if (set->members[i] == member)
            in_set = true;
    }
    if (!in_set)
    {
        set->members = realloc(set->members, sizeof(int) * set->length + 1);
        set->members[set->length] = member;
        set->length++;
    }
};

void print_set(Set *set)
{
    for (int i = 0; i < set->length; i++)
    {
        printf("%i ", set->members[i]);
    }
    printf("\n");
}

Set *set_union(Set *setA, Set *setB)
{
    Set *union_set = init();
    for (int i = 0; i < setA->length; i++)
    {
        insert(union_set, setA->members[i]);
    }
    for (int i = 0; i < setB->length; i++)
    {
        insert(union_set, setB->members[i]);
    }
    return union_set;
}

Set *set_intersection(Set *setA, Set *setB)
{
    Set *new_set = init();
    Set *test_set = make_copy(setA);
    for (int i = 0; i < setB->length; i++)
    {
        int pre_length = test_set->length;
        insert(test_set, setB->members[i]);
        if (pre_length == test_set->length)
        {
            insert(new_set, setB->members[i]);
        }
    }
    delete_set(test_set);
    return new_set;
}

Set *set_difference(Set *setA, Set *setB)
{
    Set *new_set = init();

    Set *copyB = make_copy(setB);

    for (int i = 0; i < setA->length; i++)
    {
        int pre_length = copyB->length;
        insert(copyB, setA->members[i]);
        if (pre_length != copyB->length)
        {
            // if its not equal means that it is a unique item;
            custom_insert(new_set, setA->members[i]);
        }
    }
    delete_set(copyB);
    return new_set;
}

void custom_insert(Set *set, int value)
{
    set->members = realloc(set->members, sizeof(int) * set->length + 1);
    set->members[set->length] = value;
    set->length++;
}

Set *make_copy(Set *set)
{
    Set *copy_set = malloc(sizeof(Set));
    copy_set->length = set->length;
    copy_set->members = malloc(set->length * sizeof(int));

    for (int i = 0; i < set->length; ++i)
    {
        copy_set->members[i] = set->members[i];
    }

    return copy_set;
}

bool sub_set(Set *setA, Set *setB)
{
    if (setA->length > setB->length)
    {
        return false;
    }
    for (int i = 0; i < setA->length; i++)
    {
        bool balanced = false;
        for (int j = 0; i < setB->length; j++)
            if (setA->members[i] == setB->members[j])
                balanced = true;
        if (!balanced)
            return false;
    }
}
