#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int checkAdventurerCard(int, struct gameState*);

int main(int argc, char* argv[]){
	int i, j, player_num;
	int k[10] = {adventurer, embargo, minion, gardens, mine, remodel,
			smithy, village, cutpurse, sea_hag};
	struct gameState Game;

	printf("\t~Random test on Adventurer card~\n");


	for(i = 0; i < 2400; i++) {
	    	player_num = floor(Random() * 4);
		initializeGame(player_num, k, 1, &Game);
	
		Game.deckCount[player_num] = floor(Random() * MAX_DECK);
		Game.handCount[player_num] = floor(Random() * MAX_HAND);
		Game.discardCount[player_num] = floor(Random() * MAX_DECK);
	
		checkAdventurerCard(player_num, &Game);
	}

	printf("\t~Random testing complete~\n");
	
	return 0;
}

int checkAdventurerCard(int p_num, struct gameState* post){
	struct gameState pre;
	int i, num_treasure_pre = 0, num_treasure_post = 0; 
	int drawnCard;
	memcpy(&pre, post, sizeof(struct gameState));
	
	//get number of treasure cards before call to adventurer in cardEffect
	for(i = 0; i < pre.handCount[p_num]; i++){
		drawnCard = pre.hand[p_num][i];
	    	if(drawnCard == copper || drawnCard == silver || drawnCard == gold){
			num_treasure_pre++;		
		}
	}

	//call function to execute functionality for Adventurer card
	//	effects only a single player's deck + hand + discard.
	//	player's hand incremented by 2 and player's hand contains 2+ treasure cards	
	handleAdventurer(post, p_num, 0);

	//get number of treasure cards after call to adventurer in cardEffect
	for(i = 0; i < post->handCount[p_num]; i++){
		drawnCard = post->hand[p_num][i];
	    	if(drawnCard == copper || drawnCard == silver || drawnCard == gold){
			num_treasure_post++;		
		}
	}

	//3 cards added + 1 discarded
	assert(num_treasure_post-num_treasure_pre==2);
	//handCount after should be greater than 
	//	handCount before handleAdventurer call
	assert(pre.handCount[p_num] < post->handCount[p_num]);
	//deckCount after should be less than 
	//	deckCount before handleAdventurer call
	assert(pre.deckCount[p_num] > post->deckCount[p_num]);

	return 0;
}
