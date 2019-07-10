#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>
#include <map>
#include "Track.h"
#include "BettingKiosk.h"

/*
	\TODO 
*/

const std::string VERSION = "v0.2.0-dev";

const float START_CREDITS = 0.4;
const size_t HORSE_NUM = 4;

Track track;
BettingKiosk kiosk = BettingKiosk(HORSE_NUM, START_CREDITS);

int main() {
	srand(time(NULL));
	
	while(true){
		kiosk.placeBets(&track.suiteToText);

		while(!track.takeTurn())
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

		if(!kiosk.evaluateBets(track.getWinner()))
			break;	
		
		track.reset();
	}
	
	return 0;
}

