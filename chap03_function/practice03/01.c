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
void init_data (void);
void read_cards (void);
int check_flush (void);
int check_straight (void);
int check_four_cards (void);
int check_three_cards (void);
int count_pairs (void);
void analyze_hand (void);
int check_cards (const int num_in[], const int num_in_size, const int count);
void sort (int arr[], const int size);


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
init_data (void)
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
  int cards[NUM_RANKS][NUM_SUITS] = { 0, };
  int cards_read = 0;

  init_data ();

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
	default:
	  printf
	    ("Error: Unknown card rank '%c'. (Available rank: 0, a, 2~9, t, j, q, k)\n",
	     rank_ch);
	  continue;
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
	default:
	  printf
	    ("Error: Unknown card suit '%c'. (Available suit: c, d, h, s)\n",
	     suit_ch);
	  continue;
	}

      if (cards[rank][suit] >= 1)
	{
	  printf ("Error: '%c - %c' is already yours..\n", rank_ch, suit_ch);
	  continue;
	}

      ++num_in_rank[rank];
      ++num_in_suit[suit];
      ++cards[rank][suit];
      ++cards_read;
    }
}

/** Return 1 if flush; otherwise return 0 */
int
check_flush (void)
{
  return (check_cards (num_in_suit, NUM_SUITS, 5) ? 1 : 0);
}

/** Return 1 if staight; otherwise return 0 */
int
check_straight (void)
{
  int count = 1;
  int i;

  for (i = 0; i + 1 < NUM_CARDS; ++i)
    {
      while (i + 1 < NUM_CARDS && num_in_rank[i] == num_in_rank[i + 1])
	++i;

      if (i + 1 >= NUM_CARDS)
	break;

      if (num_in_rank[i + 1] == num_in_rank[i] + 1)
	++count;
      else
	{
	  if (count >= 5)
	    break;
	  else
	    count = 1;
	}
    }

  return ((count >= 5) ? 1 : 0);
}

int
check_four_cards (void)
{
  return (check_cards (num_in_rank, NUM_RANKS, 4) ? 1 : 0);
}

int
check_three_cards (void)
{
  return (check_cards (num_in_rank, NUM_RANKS, 3) ? 1 : 0);
}

/** Return 1 if one pair, 2 if two pair; otherwise return 0 */
int
count_pairs (void)
{
  switch (check_cards (num_in_rank, NUM_RANKS, 2))
    {
    case 2:
      return 2;
    case 1:
      return 1;
    default:
      return 0;
    }
}

/** Print the highest score cards, using above functions */
void
analyze_hand (void)
{
  if (check_flush ())
    printf ("Flush\n");
  else if (check_straight ())
    printf ("Straight\n");
  else if (check_four_cards ())
    printf ("Four cards\n");
  else if (check_three_cards ())
    printf ("Three cards\n");
  else if (count_pairs () == 2)
    printf ("Two pair\n");
  else if (count_pairs () == 1)
    printf ("One pair\n");
  else
    printf ("None\n");
}

int
check_cards (const int num_in[], const int num_in_size, const int count)
{
  int c = 0;
  int i;

  for (i = 0; i < num_in_size; ++i)
    {
      if (num_in[i] == count)
	++c;
    }

  return c;
}

void
sort (int arr[], const int size)
{
  int i, j, t;
  for (i = size - 1; i >= 0; --i)
    {
      for (j = 0; j <= i; ++j)
	{
	  if (arr[j] > arr[i])
	    {
	      t = arr[i];
	      arr[i] = arr[j];
	      arr[j] = t;
	    }
	}
    }
}
