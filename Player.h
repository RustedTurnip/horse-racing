#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "BettingKiosk.h"
#include "Track.h"

class Player(){

	private:
		std::string name;
		float credits;
		float bets[Track::horseNum] = {};
		
		BettingKiosk::Ticket* ticket = nullptr;	//May become vector if Track hosts multiple races

	public:
		Player();
		~player();
		
		float getCredits() { return credits; };
};

#endif //!PLAYER_H

