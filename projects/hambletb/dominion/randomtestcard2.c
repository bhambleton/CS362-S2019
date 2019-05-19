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


	for(i = 0; i < 2400; i++) {
	    	printf("Test %d\n", i);

	    	player_num = (rand() % MAX_PLAYERS)+1;

		initializeGame(player_num, k, 1, &Game);
		Game.deckCount[player_num] = floor(Random() * MAX_DECK);
		Game.handCount[player_num] = floor(Random() * MAX_HAND);
		
		checkSmithyCard(player_num, &Game);
		printf("\n");
	}
	
	printf("\t~Random testing complete~\n");
	
	return 0;
}

int checkSmithyCard(int p_num, struct gameState* post){
	struct gameState pre;
	int pre_handCount = 0, post_handCount = 0;
	memcpy(&pre, post, sizeof(struct gameState));
	
	//call function to execute functionality for Smithy card
	handleSmithy(post, p_num, 0);

	//ensure correct functionality of handleSmity

	//assert(pre.deckCount[p_num] > post->deckCount[p_num]);
	if(!(pre.deckCount[p_num] > post->deckCount[p_num])){
		printf("Error: incorrect number of cards removed from deck\n");
		printf("\tNumber removed: %d, Expected: 3\n)", pre.deckCount[p_num]-post->deckCount[p_num]);
	}


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


	return 0;
}
