#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){
    	int i, result;
	int numPlayer = 4;
    	struct gameState Game;
  	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  	printf("Testing initializeGame(),\n");

	for(i = 0; i < 150; i++){
	    	memset(&Game, -5, sizeof(struct gameState));
		result = initializeGame(numPlayer, k, 1, &Game);
		assert(result == 0);
		assert(Game.numPlayers == numPlayer);
	}

    	return 0;
}
