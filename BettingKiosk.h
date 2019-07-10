#ifndef BETTING_KIOSK_H
#define BETTING_KIOSK_H

#include "Track.h"

class BettingKiosk{
	
	public:
		struct Ticket{
			float horses[Track::horseNum] = {};
		}

	private:
		float credits;
		float* bets;
		int winner;

	public:
		/* Constructor -- Destructor */
		BettingKiosk(size_t=4, float=0.4f);
		~BettingKiosk();

		void placeBets(std::string(*)(Track::suite));	//Weird syntax is in aid of passing a function
		bool evaluateBets(int);

		//Getters
		float getCredits();
};

#endif //!BETTING_KIOSK_H
