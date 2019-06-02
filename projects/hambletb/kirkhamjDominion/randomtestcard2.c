#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int checkSmithyCard(int, struct gameState*);

int main(int argc, char* argv[]){
	int i, j, player_num;
	int k[10] = {adventurer, embargo, minion, gardens, mine, remodel,
			smithy, village, cutpurse, sea_hag};
	struct gameState Game;

	printf("\t~Random test on Smithy card~\n");

	SelectStream(2);
	PutSeed(3);

	for(i = 0; i < 2400; i++) {
	    	printf("Test %d\n", i);

	    	player_num = (rand() % MAX_PLAYERS)+1;

		initializeGame(player_num, k, 1, &Game);
		Game.deckCount[player_num] = floor(Random() * MAX_DECK);
		Game.handCount[player_num] = floor(Random() * MAX_HAND);
		Game.discardCount[player_num] = floor(Random() * MAX_DECK);	
	
		checkSmithyCard(player_num, &Game);
		
		printf("\n");
	}
	
	printf("\t~Random testing complete~\n");
	
	return 0;
}

int checkSmithyCard(int p_num, struct gameState* post){
	struct gameState pre;
	int pre_handCount = 0, post_handCount = 0;
	int pre_discardC = 0, post_discardC = 0;
	int cardDrawn = 0;

	memcpy(&pre, post, sizeof(struct gameState));
	
	//call function to execute functionality for Smithy card
	a2Smithy(&p_num, &post, &cardDrawn);

	//ensure correct functionality of handleSmity

	//assert(pre.deckCount[p_num] > post->deckCount[p_num]);
	if(!(pre.deckCount[p_num] > post->deckCount[p_num])){
		printf("Error: incorrect number of cards removed from deck\n");
		printf("\tNumber removed: %d, Expected: 3\n)", pre.deckCount[p_num]-post->deckCount[p_num]);
	}
	else { printf("Deck count Test Passed\n"); }


	//Smithy card adds 3 cards to hand from deck and discards 1 card from hand
	pre_handCount = pre.handCount[p_num];
	post_handCount = post->handCount[p_num];

	//handCount should increase by 2 (3 random cards from deck added, 
	//	smithy card discarded)
	//assert(post_handCount - pre_handCount == 2);
	if(post_handCount - pre_handCount != 2){
		printf("Error: incorrect number of cards added to hand\n");
		printf("\tNumber added: %d, Expected: 2\n", post_handCount-pre_handCount);
	}
	else { printf("Hand count test Passed\n"); }

	pre_discardC = pre.discardCount[p_num];
	post_discardC = post->discardCount[p_num];

	//discardCount should increase by 1 for the discarded Smithy card
	if(pre_discardC >= post_discardC){
	    printf("Error: incorrect number of cards added to discard\n");
	    printf("\tNumber added: %d\n\tExpected: 1\n", post_discardC-pre_discardC);
	}
	else { printf("Discard count test Passed\n"); }

	return 0;
}
