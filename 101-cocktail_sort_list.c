#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 *
 * Description: Doubly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to pointer to the first node of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *head = *list;
    listint_t *start = head;
    listint_t *end = NULL;
    listint_t *tmp = NULL;
    int swapped = 0;

    while (head != end)
    {
        swapped = 0;
        while (head->next != end)
        {
            if (head->n > head->next->n)
            {
                tmp = head->next;
                if (tmp->next != NULL)
                    tmp->next->prev = head;
                head->next = tmp->next;
                tmp->prev = head->prev;
                if (head->prev != NULL)
                    head->prev->next = tmp;
                tmp->next = head;
                head->prev = tmp;
                if (tmp->prev == NULL)
                    start = tmp;
                swapped = 1;
                *list = start;
                print_list(*list);
            }
            else
                head = head->next;
        }
        end = head;
        while (head->prev != end)
        {
            if (head->n < head->prev->n)
            {
                tmp = head->prev;
                if (head->next != NULL)
                    head->next->prev = tmp;
                tmp->next = head->next;
                head->prev = tmp->prev;
                if (tmp->prev != NULL)
                    tmp->prev->next = head;
                head->next = tmp;
                tmp->prev = head;
                if (head->prev == NULL)
                    start = head;
                swapped = 1;
                *list = start;
                print_list(*list);
            }
            else
                head = head->prev;
        }
        end = head;
        head = start;
        if (!swapped)
            break;
    }
}

/**
 * print_list - prints the elements of a doubly linked list
 * @list: pointer to the first node of the list
 */
void print_list(const listint_t *list)
{
    while (list != NULL)
    {
        printf("%d", list->n);
        list = list->next;
        if (list != NULL)
            printf(", ");
    }
    printf("\n");
}

/**
 * add_node_end - adds a new node at the end of a doubly linked list
 * @list: pointer to pointer to the first node of the list
 * @n: integer to be stored in the new node
 * Return: address of the new node, or NULL if it fails
 */
listint_t *add_node_end(listint_t **list, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    listint_t *last = *list;

    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*list == NULL)
    {
        new_node->prev = NULL;
        *list = new_node;
        return (new_node);
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return (new_node);
}
