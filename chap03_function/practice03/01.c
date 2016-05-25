/** Macros*/
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


/** Includes */
#include <stdio.h>


/** Global variables */
int num_in_rank[NUM_RANKS + 1];
int num_in_suit[NUM_SUITS];


/** Declarations */
void read_cards (void);
void analyze_hand (void);


/** Definitions */
int
main (void)
{
  while (1)
    {
      read_cards ();
      analyze_hand ();
    }
}

void
init_data ()
{
  int rank, suit;
  for (rank = 0; rank < NUM_RANKS; rank++)
    num_in_rank[rank] = 0;
  for (suit = 0; suit < NUM_SUITS; suit++)
    num_in_suit[suit] = 0;
}

void
read_cards (void)
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  init_data ();
  int cards_read = 0;

  while (cards_read < NUM_CARDS)
    {
      printf ("Enter a card: ");
      scanf (" %c", &rank_ch);
      switch (rank_ch)
	{
	case 'a':
	  rank = 1;
	  break;
	case '2':
	  rank = 2;
	  break;
	case '3':
	  rank = 3;
	  break;
	case '4':
	  rank = 4;
	  break;
	case '5':
	  rank = 5;
	  break;
	case '6':
	  rank = 6;
	  break;
	case '7':
	  rank = 7;
	  break;
	case '8':
	  rank = 8;
	  break;
	case '9':
	  rank = 9;
	  break;
	case 't':
	  rank = 10;
	  break;
	case 'j':
	  rank = 11;
	  break;
	case 'q':
	  rank = 12;
	  break;
	case 'k':
	  rank = 13;
	  break;
	}

      scanf (" %c", &suit_ch);
      switch (suit_ch)
	{
	case 'c':
	  suit = 0;
	  break;
	case 'd':
	  suit = 1;
	  break;
	case 'h':
	  suit = 2;
	  break;
	case 's':
	  suit = 3;
	  break;
	}
      num_in_rank[rank]++;
      num_in_suit[suit]++;
      cards_read++;
    }
}

/** Return 1 if flush; otherwise return 0 */
int
check_flush ()
{
}

/** Return 1 if staight; otherwise return 0 */
int
check_straight ()
{
}

int
check_four_cards ()
{
}

int
check_three_cards ()
{
}

/** Return 1 if one pair, 2 if two pair; otherwise return 0 */
int
count_pairs ()
{
}

/** Print the hightest score card, using above functions */
void
analyze_hand (void)
{
}
