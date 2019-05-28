#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer,
    council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall,
    minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag,
    treasure_map};

int main(){
	int i, j, result;

	printf("Testing getCost():\n");
	
	for(i = 0; i < 100; i++){
		for(j = 0; j < 27; j++){
			result = getCost(cards[j]);
			if(cards[j] == curse || cards[j] == copper){
				assert(result == 0);
			}
			else{
				assert(result > 0);
			}
		}
	}

	printf("Testing passed\n");

	return 0;
}
