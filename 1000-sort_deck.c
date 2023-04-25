#include "deck.h"
#include <stdlib.h>  // for qsort

/**
 * compare_cards - helper function to compare two cards
 * @a: first card to compare
 * @b: second card to compare
 *
 * Return: negative number if a < b, zero if a == b, positive number if a > b
 */
static int compare_cards(const void *a, const void *b)
{
    const card_t *ca = ((const deck_node_t *)a)->card;
    const card_t *cb = ((const deck_node_t *)b)->card;

    int value_a, value_b;
    switch (ca->value[0])
    {
        case 'A': value_a = 1; break;
        case 'J': value_a = 11; break;
        case 'Q': value_a = 12; break;
        case 'K': value_a = 13; break;
        default: value_a = atoi(ca->value); break;
    }
    switch (cb->value[0])
    {
        case 'A': value_b = 1; break;
        case 'J': value_b = 11; break;
        case 'Q': value_b = 12; break;
        case 'K': value_b = 13; break;
        default: value_b = atoi(cb->value); break;
    }

    int kind_a = ca->kind;
    int kind_b = cb->kind;

    if (value_a != value_b)
        return value_a - value_b;
    else
        return kind_a - kind_b;
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
    if (!deck || !*deck)
        return;

    qsort(*deck, 52, sizeof(deck_node_t), compare_cards);

    // fix the next and prev pointers of the nodes
    for (int i = 0; i < 52; i++)
    {
        (*deck)[i].prev = (i == 0 ? NULL : &((*deck)[i-1]));
        (*deck)[i].next = (i == 51 ? NULL : &((*deck)[i+1]));
    }
}
