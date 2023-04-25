#include <stdlib.h>
#include "deck.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @deck: double pointer to head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    if (*deck == node1)
        *deck = node2;
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * sort_deck - sorts a deck of cards using insertion sort
 * @deck: double pointer to head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *index;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    for (current = (*deck)->next; current != NULL; current = current->next)
    {
        for (index = current->prev; index != NULL; index = index->prev)
        {
            const card_t *current_card = current->card;
            const card_t *index_card = index->card;

            if (index_card->kind > current_card->kind ||
                (index_card->kind == current_card->kind &&
                 index_card->value > current_card->value))
            {
                swap_nodes(deck, current, index);
            }
            else
            {
                break;
            }
        }
    }
}
