#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int checkSeahagCard(int, struct gameState);

int main(int argc, char* argv[]){
	int i, j, player_num;
	int k[10] = {adventurer, embargo, minion, gardens, mine, remodel,
			smithy, village, cutpurse, sea_hag};
	struct gameState Game;

	printf("Testing adventurer card\n");


	for(i = 0; i < 2400; i++) {
	    	player_num = floor(Random() * 4);
		initializeGame(player_num, k, 1, Game);
		for(j = 0; j < player_num; j++){	
			Game.deckCount[j] = floor(Random() * MAX_DECK);
			Game.handCount[j] = floor(Random() * MAX_HAND);
			Game.discardCount[j] = floor(Random() * MAX_DECK);
		}
		checkSeahagCard(player_num, &Game);
	}
	
	return 0;
}

int checkSeahagCard(int p_num, struct gameState* post){
	int result;

	struct gameState pre;

	memcpy(pre, post, sizeof(struct gameState));
	
	//call function to execute functionality for Sea Hag card
	result = handleSeahag(post, p_num, 0);

	//effects all players' deck & deckCount except 1 player


}
