#include "deck.h"
#include <stdio.h>

void sort_by_suit(deck_node_t **deck);
void sort_by_value(deck_node_t **deck);
void exch(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2);
int cmp_vals(const card_t *card1, const card_t *card2);
/**
 * sort_deck - sorts a 52 card deck
 * @deck: deck to sort
 *
 * Return: Always 0 (ok)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_by_suit(deck);
	sort_by_value(deck);
}

/**
 * sort_by_suit - sorts a 52 card deck by suit
 * @deck: deck to sort
 */
void sort_by_suit(deck_node_t **deck)
{
	deck_node_t *f, *t;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && f->card->kind < f->prev->card->kind;
		     f = f->prev)
		{
			t = f->prev;
			exch(deck, t, f);
			f = f->next;
		}
	}
}

/**
 * sort_by_value - sorts a 52 card deck staticly by value
 * @deck: deck to sort
 */
void sort_by_value(deck_node_t **deck)
{
	deck_node_t *f, *t;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && cmp_vals(f->card, f->prev->card) &&
		       f->card->kind == f->prev->card->kind;
		     f = f->prev)
		{
			t = f->prev;
			exch(deck, t, f);
			f = f->next;
		}
	}
}
/**
 * exch - swaps 2 consecutive cards of a doubly linked list
 * Used in the insertion algorithm
 * @deck: Head node for the deck
 * @card1: The first card to swap
 * @card2: The second card to swap
 */
void exch(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev, *next;

	prev = card1->prev;
	next = card2->next;

	if (prev != NULL)
		prev->next = card2;
	else
		*deck = card2;
	card1->prev = card2;
	card1->next = next;
	card2->prev = prev;
	card2->next = card1;
	if (next)
		next->prev = card1;
}

/**
 * cmp_vals - compares 2 card values
 * @card1: The first card to compare
 * @card2: The second card to compare
 *
 * Return: 1 if less than, 0 if greater or equal to
 */
int cmp_vals(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
			       "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int id1 = 0, id2 = 0, x;

	if ((char1 >= 48 && char1 <= 57) && (char2 >= 49 &&
					     char2 <= 57))
	{
		if (card1->value[1] == '0')
			char1 = 58;
		if (card2->value[1] == '0')
			char2 = 58;
		return (char1 < char2);
	}
	else
	{
		for (x = 0; x < 14; x++)
		{
			if (card1->value[0] == ord[x][0] &&
			    card1->value[1] == ord[x][1])
				id1 = x;
			if (card2->value[0] == ord[x][0] &&
			    card2->value[1] == ord[x][1])
				id2 = x;
		}
		return (id1 < id2);
	}
}
