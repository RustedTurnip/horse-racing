#include "Track.h"

/*
	Constructor -- Destructor
*/
Track::Track(){
	
}


Track::~Track(){
	
}

void Track::printTrack(){
	std::system("clear");
	for(int i = 0; i < horseNum; i++){
		std::cout << suiteToText(static_cast<suite>(i)) << ":   \t";
		for(int j = 0; j < positions; j++){
			if(track[i] == j)
				std::cout << "O";
			else
				std::cout << "x";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


/*
	Operational methods
*/
bool Track::takeTurn(){
	
	track[randomSuite()]++;
	printTrack();
	
	for(int i = 0; i < horseNum; i++){
		if(track[i] == positions - 1){
			std::cout << "Horse " << i + 1 << " wins!" << std::endl;
			winner = i;
			return true;
		}
	}
	
	return false;
}


Track::suite Track::randomSuite(){
	return static_cast<suite>(rand() % horseNum);
}

std::string Track::suiteToText(Track::suite val){
	switch (val){
	case hearts: return "Hearts";
	case diamonds: return "Diamonds";
	case clubs: return "Clubs";
	case spades: return "Spades";
	}
}

Track::suite Track::getWinner(){

		return static_cast<suite>(winner);
}

void Track::reset(){
	
	for(int i = 0; i < horseNum; i++)
		track[i] = 0;
}

/*
	Overrides
*/
/*
std::ostream& Track::operator<<(std::ostream& out, const Track& track){
	return toString();
}*/
