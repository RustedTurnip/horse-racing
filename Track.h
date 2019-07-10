#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "BettingKiosk.h"

class Track{

	public:
		enum suite{
			hearts, diamonds, clubs, spades, horseNum
		};


	private:
		int track[horseNum] = {};	//Default values of 0
		size_t positions = 15;
		size_t winner = horseNum;

		BettingKiosk kiosk;

	public:
		/* Constructor -- Destructor */
		Track();
		~Track();
		
		void printTrack();

		/* Operational functions */
		bool takeTurn();
		suite randomSuite();
		static std::string suiteToText(suite val);
		suite getWinner();
		void reset();

		/* Override */
		//std::ostream& operator<<(std::ostream&, const Track&);	//To String sort of
		

};

#endif //!TRACK_H

