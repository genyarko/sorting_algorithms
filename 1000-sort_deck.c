#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - Compare two cards
 * @card1: First card
 * @card2: Second card
 *
 * Return: -1 if card1 < card2, 0 if card1 == card2, 1 if card1 > card2
 */
static int compare_cards(const card_t *card1, const card_t *card2)
{
    int value1, value2;

    if (card1->kind != card2->kind)
        return (card1->kind - card2->kind);

    switch (card1->value[0])
    {
    case 'A':
        value1 = 1;
        break;
    case '1':
        value1 = 10;
        break;
    case 'J':
        value1 = 11;
        break;
    case 'Q':
        value1 = 12;
        break;
    case 'K':
        value1 = 13;
        break;
    default:
        value1 = card1->value[0] - '0';
        break;
    }

    switch (card2->value[0])
    {
    case 'A':
        value2 = 1;
        break;
    case '1':
        value2 = 10;
        break;
    case 'J':
        value2 = 11;
        break;
    case 'Q':
        value2 = 12;
        break;
    case 'K':
        value2 = 13;
        break;
    default:
        value2 = card2->value[0] - '0';
        break;
    }

    return (value1 - value2);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i, j;
    deck_node_t *node1, *node2;
    const card_t *tmp_card;

    if (!deck || !*deck || !(*deck)->next)
        return;

    for (i = 0, node1 = *deck; i < 51; i++, node1 = node1->next)
    {
        for (j = i + 1, node2 = node1->next; j < 52; j++, node2 = node2->next)
        {
            if (compare_cards(node1->card, node2->card) > 0)
            {
                tmp_card = node1->card;
                node1->card = node2->card;
                node2->card = tmp_card;
            }
        }
    }
}
