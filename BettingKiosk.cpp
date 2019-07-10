#include "BettingKiosk.h"

/*
	Constructor -- Destructor
*/
BettingKiosk::BettingKiosk(size_t horseNum, float credits)
: credits(credits){
	
	bets = new float[horseNum];
}

BettingKiosk::~BettingKiosk(){

	delete[] bets;
}


/*
	Operational functions
*/
void BettingKiosk::placeBets(std::string(*funct)(Track::suite)){

	std::cout << "Credits: " << credits << std::endl;	
	
	for(int i = 0; i < 4; i++){	//TODO: Change from i < 4 to i < horseNum or something

		float temp;
		std::cout << "How many credits would you like to bet on " << (*funct)(static_cast<Track::suite>(i)) << "?" << std::endl;
		std::cout << ">";
		std::cin >> temp;

		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			i--;
		}
		else if(temp > credits){
			std::cout << std::endl << "You do not have enough remaining credits to place this bet." << std::endl;
			i--;
		}
		else if(temp < 0.0f){
			std::cout << std::endl << "Please enter a valid number of credits." << std::endl;
			i--;
		}
		else{
			credits -= temp;
			bets[i] += temp;
		}
	}
}

bool BettingKiosk::evaluateBets(int winner){
	
	credits += bets[winner] * 4.f;	//TODO change bets[winner] - remove winner var

	for(int i = 0; i < sizeof(bets)/sizeof(int); i++){
		bets[0] = 0.0f;
	}
	
	char con = 'y';
	std::cout << "Credits: " << credits << std::endl;
	//std::system("clear");
	std::cout << "Continue betting? (y/n)" << std::endl << ">";
	std::cin >> con;
	
	if(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		return false;
	}
	else if(con != 'y')
		return false;

	return true;
}

