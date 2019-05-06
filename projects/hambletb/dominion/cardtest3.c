#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){
    	int i, j, result, handCount;
	int numPlayer = 4;
	struct gameState Game;
  	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int currentPlayer;

  	printf("Testing Adventurer Card:,\n");

	for(i = 0; i < 1000; i++){
	    	memset(&Game, -5, sizeof(struct gameState));
		result = initializeGame(numPlayer, k, 1, &Game);
		currentPlayer = whoseTurn(&Game);
		handCount = Game.handCount[currentPlayer];
		handleAdventurer(&Game, currentPlayer, currentPlayer+1);
		assert(Game.handCount[currentPlayer] > handCount);
	}

	 printf("Testing Passed.\n");
	
	 return 0;
}
