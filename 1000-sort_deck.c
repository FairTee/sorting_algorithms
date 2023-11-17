#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards for qsort
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero
 * if card1 is found to be less than, equal to, or greater than card2
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	if (c1->kind != c2->kind)
		return (c1->kind - c2->kind);

	return (strcmp(c1->value, c2->value));
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, count = 0;
	deck_node_t *current = *deck;
	card_t *cards[52];

	while (current)
	{
		cards[count] = (card_t *)current->card;
		current = current->next;
		count++;
	}

	qsort(cards, count, sizeof(card_t *), compare_cards);

	current = *deck;
	for (i = 0; i < count; i++)
	{
		current->card = cards[i];
		current = current->next;
	}
}
