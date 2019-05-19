#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int checkAdventurerCard(int, struct gameState);

int main(int argc, char* argv[]){
	int i, j, player_num;
	int k[10] = {adventurer, embargo, minion, gardens, mine, remodel,
			smithy, village, cutpurse, sea_hag};
	struct gameState Game;

	printf("Testing adventurer card\n");


	for(i = 0; i < 2400; i++) {
	    	player_num = floor(Random() * 4);
		initializeGame(player_num, k, 1, Game);
	
		Game.deckCount[player_num] = floor(Random() * MAX_DECK);
		Game.handCount[person_num] = floor(Random() * MAX_HAND);
		Game.discardCount[person_num] = floor(Random() * MAX_DECK);
		checkAdventurerCard(player_num, &Game);
	}
	
	return 0;
}

int checkAdventurerCard(int p_num, struct gameState* post){
	int result;

	struct gameState pre;

	memcpy(pre, post, sizeof(struct gameState));
	
	//call function to execute functionality for Adventurer card
	result = handleAdventurer(post, p_num, 0);

	//effects only a single player's deck + hand + discard.
	//player's hand incremented by 2 and player's hand contains 2+ treasure cards	


}
