#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int checkSeahagCard(int, struct gameState*);

int main(int argc, char* argv[]){
	int i, j, player_num;
	int k[10] = {adventurer, embargo, minion, gardens, mine, remodel,
			smithy, village, cutpurse, sea_hag};
	struct gameState Game;

	printf("\t~Testing Sea Hag card~\n");

	SelectStream(2);
	PutSeed(3);

	for(i = 0; i < 2400; i++) {
	    	printf("Test %d\n", i);
	    	player_num = (rand() % MAX_PLAYERS)+1;
		initializeGame(player_num, k, 1, &Game);

		for(j = 0; j < player_num; j++){	
			Game.deckCount[j] = floor(Random() * MAX_DECK);
			Game.handCount[j] = floor(Random() * MAX_HAND);
			Game.discardCount[j] = floor(Random() * MAX_DECK);
		}

		checkSeahagCard(player_num, &Game);
		printf("\n");
	}

	printf("\t~Random testing complete~\n");

	return 0;
}

int checkSeahagCard(int p_num, struct gameState* post){
	int i;
	struct gameState pre;

	memcpy(&pre, post, sizeof(struct gameState));
	
	//call function to execute functionality for Sea Hag card
	handleSeaHag(post, p_num);

	//effects all players' deck & deckCount except player that played the card
	for(i = 0; i < post->numPlayers; i++){
		if(i != p_num){
			if(post->deck[i][post->deckCount[i]--] != curse){
				printf("Error: top card of player %d is not a curse\n", i);
			}
			if(pre.deckCount[i] >= post->deckCount[i]){
				printf("Error: incorrect number of cards removed from player %d's deck\n", i);
				printf("\tDeck Count before: %d\n\tDeck Count after: %d\n", pre.deckCount[i],
					post->deckCount[i]);
			}
		}
	}

	//check handCount for p_num to make sure sea_hag card removed from hand
	if(pre.handCount[p_num] >= post->handCount[p_num]){
		printf("Error: incorrect number of cards removed from player %d's hand\n", p_num);
		printf("Hand count before: %d\n\tHand count after: %d\n", pre.handCount[p_num],
			post->handCount[p_num]);
	}

	return 0;
}
