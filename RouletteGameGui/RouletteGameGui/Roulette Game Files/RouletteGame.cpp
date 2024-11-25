#include <iostream>
#include <windows.h>
#include <random>
#include <thread>
#include "RouletteGame.h"

//Constructor
RouletteGame::RouletteGame(long long int Balance): m_Balance{ Balance } {};

//SpinningScreen
long long int RouletteGame::GetCurrentBalance() { return m_Balance; }

long long int RouletteGame::GetBetAmount() {
	return  m_BetAmountBlackOdds +
		m_BetAmountRedEven +
		m_BetAmountOneToEighteen +
		m_BetAmountNineteenToThirtySix +
		m_BetAmountFirstTwelve +
		m_BetAmountSecondTwelve +
		m_BetAmountThirdTwelve +
		m_BetAmountFirstColumn +
		m_BetAmountSecondColumn +
		m_BetAmountThirdColumn +
		m_BetAmountNumberZero +
		m_BetAmountNumberOne +
		m_BetAmountNumberTwo +
		m_BetAmountNumberThree +
		m_BetAmountNumberFour +
		m_BetAmountNumberFive +
		m_BetAmountNumberSix +
		m_BetAmountNumberSeven +
		m_BetAmountNumberEight +
		m_BetAmountNumberNine +
		m_BetAmountNumberTen +
		m_BetAmountNumberEleven +
		m_BetAmountNumberTwelve +
		m_BetAmountNumberThirteen +
		m_BetAmountNumberFourteen +
		m_BetAmountNumberFifteen +
		m_BetAmountNumberSixteen +
		m_BetAmountNumberSeventeen +
		m_BetAmountNumberEighteen +
		m_BetAmountNumberNineteen +
		m_BetAmountNumberTwenty +
		m_BetAmountNumberTwentyOne +
		m_BetAmountNumberTwentyTwo +
		m_BetAmountNumberTwentyThree +
		m_BetAmountNumberTwentyFour +
		m_BetAmountNumberTwentyFive +
		m_BetAmountNumberTwentySix +
		m_BetAmountNumberTwentySeven +
		m_BetAmountNumberTwentyEight +
		m_BetAmountNumberTwentyNine +
		m_BetAmountNumberThirty +
		m_BetAmountNumberThirtyOne +
		m_BetAmountNumberThirtyTwo +
		m_BetAmountNumberThirtyThree +
		m_BetAmountNumberThirtyFour +
		m_BetAmountNumberThirtyFive +
		m_BetAmountNumberThirtySix +
		m_BetAmountStreetOne +
		m_BetAmountStreetTwo +
		m_BetAmountStreetThree +
		m_BetAmountStreetFour +
		m_BetAmountStreetFive +
		m_BetAmountStreetSix +
		m_BetAmountStreetSeven +
		m_BetAmountStreetEight +
		m_BetAmountStreetNine +
		m_BetAmountStreetTen +
		m_BetAmountStreetEleven +
		m_BetAmountStreetTwelve +
		m_BetAmountDoubleStreetZeroOneTwoThree +
		m_BetAmountStreetZeroOneTwo +
		m_BetAmountStreetZeroTwoThree +
		m_BetAmountDoubleStreetOneTwo +
		m_BetAmountDoubleStreetTwoThree +
		m_BetAmountDoubleStreetThreeFour +
		m_BetAmountDoubleStreetFourFive +
		m_BetAmountDoubleStreetFiveSix +
		m_BetAmountDoubleStreetSixSeven +
		m_BetAmountDoubleStreetSevenEight +
		m_BetAmountDoubleStreetEightNine +
		m_BetAmountDoubleStreetNineTen +
		m_BetAmountDoubleStreetTenEleven +
		m_BetAmountDoubleStreetElevenTwelve +
		m_BetAmountSquareOne +
		m_BetAmountSquareTwo +
		m_BetAmountSquareThree +
		m_BetAmountSquareFour +
		m_BetAmountSquareFive +
		m_BetAmountSquareSix +
		m_BetAmountSquareSeven +
		m_BetAmountSquareEight +
		m_BetAmountSquareNine +
		m_BetAmountSquareTen +
		m_BetAmountSquareEleven +
		m_BetAmountSquareTwelve +
		m_BetAmountSquareThirteen +
		m_BetAmountSquareFourteen +
		m_BetAmountSquareFifteen +
		m_BetAmountSquareSixteen +
		m_BetAmountSquareSeventeen +
		m_BetAmountSquareEighteen +
		m_BetAmountSquareNineteen +
		m_BetAmountSquareTwenty +
		m_BetAmountSquareTwentyOne +
		m_BetAmountSquareTwentyTwo +
		m_BetAmountVerticalSplitOne +
		m_BetAmountVerticalSplitTwo +
		m_BetAmountVerticalSplitThree +
		m_BetAmountVerticalSplitFour +
		m_BetAmountVerticalSplitFive +
		m_BetAmountVerticalSplitSix +
		m_BetAmountVerticalSplitSeven +
		m_BetAmountVerticalSplitEight +
		m_BetAmountVerticalSplitNine +
		m_BetAmountVerticalSplitTen +
		m_BetAmountVerticalSplitEleven +
		m_BetAmountVerticalSplitTwelve +
		m_BetAmountVerticalSplitThirteen +
		m_BetAmountVerticalSplitFourteen +
		m_BetAmountVerticalSplitFifteen +
		m_BetAmountVerticalSplitSixteen +
		m_BetAmountVerticalSplitSeventeen +
		m_BetAmountVerticalSplitEighteen +
		m_BetAmountVerticalSplitNineteen +
		m_BetAmountVerticalSplitTwenty +
		m_BetAmountVerticalSplitTwentyone +
		m_BetAmountVerticalSplitTwentytwo +
		m_BetAmountVerticalSplitTwentythree +
		m_BetAmountVerticalSplitTwentyfour +
		m_BetAmountHorizontalSplitOne +
		m_BetAmountHorizontalSplitTwo +
		m_BetAmountHorizontalSplitThree +
		m_BetAmountHorizontalSplitFour +
		m_BetAmountHorizontalSplitFive +
		m_BetAmountHorizontalSplitSix +
		m_BetAmountHorizontalSplitSeven +
		m_BetAmountHorizontalSplitEight +
		m_BetAmountHorizontalSplitNine +
		m_BetAmountHorizontalSplitTen +
		m_BetAmountHorizontalSplitEleven +
		m_BetAmountHorizontalSplitTwelve +
		m_BetAmountHorizontalSplitThirteen +
		m_BetAmountHorizontalSplitFourteen +
		m_BetAmountHorizontalSplitFifteen +
		m_BetAmountHorizontalSplitSixteen +
		m_BetAmountHorizontalSplitSeventeen +
		m_BetAmountHorizontalSplitEighteen +
		m_BetAmountHorizontalSplitNineteen +
		m_BetAmountHorizontalSplitTwenty +
		m_BetAmountHorizontalSplitTwentyOne +
		m_BetAmountHorizontalSplitTwentyTwo +
		m_BetAmountHorizontalSplitTwentyThree +
		m_BetAmountHorizontalSplitTwentyFour +
		m_BetAmountHorizontalSplitTwentyFive +
		m_BetAmountHorizontalSplitTwentySix +
		m_BetAmountHorizontalSplitTwentySeven +
		m_BetAmountHorizontalSplitTwentyEight +
		m_BetAmountHorizontalSplitTwentyNine +
		m_BetAmountHorizontalSplitThirty +
		m_BetAmountHorizontalSplitThirtyOne +
		m_BetAmountHorizontalSplitThirtyTwo +
		m_BetAmountHorizontalSplitThirtyThree;
}

bool RouletteGame::GetShowPreviousOne()		{
	if (m_IncrementShowCheck == 1) {
		m_ShowPreviousOne = true;
	}
	return m_ShowPreviousOne;
}

bool RouletteGame::GetShowPreviousTwo()		{ 
	if (m_IncrementShowCheck == 2) {
		m_ShowPreviousTwo = true;
	}
	return m_ShowPreviousTwo;
}

bool RouletteGame::GetShowPreviousThree()   { 
	if (m_IncrementShowCheck == 3) {
		m_ShowPreviousThree = true;
	}
	return m_ShowPreviousThree;
}

bool RouletteGame::GetShowPreviousFour()    { 
	if (m_IncrementShowCheck == 4) {
		m_ShowPreviousFour = true;
	}
	return m_ShowPreviousFour;
}

SpinNumbers RouletteGame::GetPreviousSpinNumbers() {
	SpinNumbers numbers;
	numbers.previousSpinNumber = m_PreviousSpinNumber;
	numbers.previousPreviousSpinNumber = m_PreviousPreviousSpinNumber;
	numbers.previousPreviousPreviousSpinNumber = m_PreviousPreviousPreviousSpinNumber;
	numbers.previousPreviousPreviousPreviousSpinNumber = m_PreviousPreviousPreviousPreviousSpinNumber;
	return numbers;
}

std::string RouletteGame::GetNumberColor(int& Number) {
	for (int i = 0; i < sizeof(m_BLACKODDS) / sizeof(m_BLACKODDS[0]); ++i) {
		if (Number == m_BLACKODDS[i]) {
			return "Black";
		}
	}

	for (int i = 0; i < sizeof(m_REDEVEN) / sizeof(m_REDEVEN[0]); ++i) {
		if (Number == m_REDEVEN[i]) {
			return "Red";
		}
	}

	if (Number == 0) {
		return "Green";
	}
}


//HelperFunction for the below
void RouletteGame::AddToBet(long long int& betVariable, const int& BetAmountPlus) {
	if (m_Balance >= BetAmountPlus) {
		betVariable += BetAmountPlus;
		m_Balance -= BetAmountPlus;
	}
	else {
		std::cout << "Insufficent funds" << std::endl;
	}
}


// Add Red and Black Bets
void RouletteGame::AddToBetBlack(const int& BetAmountPlus) {
	AddToBet(m_BetAmountBlackOdds, BetAmountPlus);
}
void RouletteGame::AddToBetRed(const int& BetAmountPlus) {
	AddToBet(m_BetAmountRedEven, BetAmountPlus);
}

//Adding 1-18 || 19-36 bets
void RouletteGame::AddToBetOneToEighteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountOneToEighteen, BetAmountPlus);
}
void RouletteGame::AddToBetNineteenToThirtySix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNineteenToThirtySix, BetAmountPlus);
}


//Adding Twelves
void RouletteGame::AddToBetFirstTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountFirstTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetSecondTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSecondTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetThirdTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountThirdTwelve, BetAmountPlus);
}

//Adding Column Bets
void RouletteGame::AddToBetFirstColumn(const int& BetAmountPlus) {
	AddToBet(m_BetAmountFirstColumn, BetAmountPlus);
}
void RouletteGame::AddToBetSecondColumn(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSecondColumn, BetAmountPlus);
}
void RouletteGame::AddToBetThirdColumn(const int& BetAmountPlus) {
	AddToBet(m_BetAmountThirdColumn, BetAmountPlus);
}


//Adding Number Bets
void RouletteGame::AddToBetNumberZero(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberZero, BetAmountPlus);
}
void RouletteGame::AddToBetNumberOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberOne, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwo, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThree, BetAmountPlus);
}
void RouletteGame::AddToBetNumberFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberFour, BetAmountPlus);
}
void RouletteGame::AddToBetNumberFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberFive, BetAmountPlus);
}
void RouletteGame::AddToBetNumberSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberSix, BetAmountPlus);
}
void RouletteGame::AddToBetNumberSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberSeven, BetAmountPlus);
}
void RouletteGame::AddToBetNumberEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberEight, BetAmountPlus);
}
void RouletteGame::AddToBetNumberNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberNine, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberEleven, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberFourteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberFourteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberFifteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberFifteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberSixteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberSixteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberSeventeen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberSeventeen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberEighteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberEighteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberNineteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberNineteen, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwenty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwenty, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyOne, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyTwo, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyThree, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyFour, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyFive, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentySix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentySix, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentySeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentySeven, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyEight, BetAmountPlus);
}
void RouletteGame::AddToBetNumberTwentyNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberTwentyNine, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirty, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtyOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtyOne, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtyTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtyTwo, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtyThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtyThree, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtyFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtyFour, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtyFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtyFive, BetAmountPlus);
}
void RouletteGame::AddToBetNumberThirtySix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountNumberThirtySix, BetAmountPlus);
}


//Adding Single Street Bets
void RouletteGame::AddToBetStreetOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetOne, BetAmountPlus);
}
void RouletteGame::AddToBetStreetTwo(const int& BetAmountPlus){
	AddToBet(m_BetAmountStreetTwo, BetAmountPlus);
}
void RouletteGame::AddToBetStreetThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetThree, BetAmountPlus);
}
void RouletteGame::AddToBetStreetFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetFour, BetAmountPlus);
}
void RouletteGame::AddToBetStreetFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetFive, BetAmountPlus);
}
void RouletteGame::AddToBetStreetSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetSix, BetAmountPlus);
}
void RouletteGame::AddToBetStreetSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetSeven, BetAmountPlus);
}
void RouletteGame::AddToBetStreetEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetEight, BetAmountPlus);
}
void RouletteGame::AddToBetStreetNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetNine, BetAmountPlus);
}
void RouletteGame::AddToBetStreetTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetTen, BetAmountPlus);
}
void RouletteGame::AddToBetStreetEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetEleven, BetAmountPlus);
}
void RouletteGame::AddToBetStreetTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetTwelve, BetAmountPlus);
}

void RouletteGame::AddToBetStreetZeroOneTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountStreetZeroOneTwo, BetAmountPlus);
}
void RouletteGame::AddToBetStreetZeroTwoThree(const int& BetAmountPlus){
	AddToBet(m_BetAmountStreetZeroTwoThree, BetAmountPlus);
}

//Adding Double Street Bets
void RouletteGame::AddToBetDoubleStreetZeroOneTwoThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetZeroOneTwoThree, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetOneTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetOneTwo, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetTwoThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetTwoThree, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetThreeFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetThreeFour, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetFourFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetFourFive, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetFiveSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetFiveSix, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetSixSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetSixSeven, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetSevenEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetSevenEight, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetEightNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetEightNine, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetNineTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetNineTen, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetTenEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetTenEleven, BetAmountPlus);
}
void RouletteGame::AddToBetDoubleStreetElevenTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountDoubleStreetElevenTwelve, BetAmountPlus);
}

// Sqaure Bets
void RouletteGame::AddToBetSquareOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareOne, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTwo(const int& BetAmountPlus){
	AddToBet(m_BetAmountSquareTwo, BetAmountPlus);
}
void RouletteGame::AddToBetSquareThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareThree, BetAmountPlus);
}
void RouletteGame::AddToBetSquareFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareFour, BetAmountPlus);
}
void RouletteGame::AddToBetSquareFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareFive, BetAmountPlus);
}
void RouletteGame::AddToBetSquareSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareSix, BetAmountPlus);
}
void RouletteGame::AddToBetSquareSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareSeven, BetAmountPlus);
}
void RouletteGame::AddToBetSquareEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareEight, BetAmountPlus);
}
void RouletteGame::AddToBetSquareNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareNine, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareTen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareEleven, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetSquareThirteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareThirteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareFourteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareFourteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareFifteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareFifteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareSixteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareSixteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareSeventeen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareSeventeen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareEighteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareEighteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareNineteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareNineteen, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTwenty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareTwenty, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTwentyOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareTwentyOne, BetAmountPlus);
}
void RouletteGame::AddToBetSquareTwentyTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountSquareTwentyTwo, BetAmountPlus);
}


//Split Vertical Bets
void RouletteGame::AddToBetVerticalSplitOne(const int& BetAmountPlus){
	AddToBet(m_BetAmountVerticalSplitOne, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwo(const int& BetAmountPlus){
	AddToBet(m_BetAmountVerticalSplitTwo, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitThree, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitFour, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitFive, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitSix, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitSeven, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitEight, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitNine, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitEleven, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitThirteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitThirteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitFourteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitFourteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitFifteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitFifteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitSixteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitSixteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitSeventeen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitSeventeen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitEighteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitEighteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitNineteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitNineteen, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwenty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwenty, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwentyone(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwentyone, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwentytwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwentytwo, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwentythree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwentythree, BetAmountPlus);
}
void RouletteGame::AddToBetVerticalSplitTwentyfour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountVerticalSplitTwentyfour, BetAmountPlus);
}

//Split Horizontal Bets
void RouletteGame::AddToBetHorizontalSplitOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitOne, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwo, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThree, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitFour, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitFive, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitSix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitSix, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitSeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitSeven, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitEight, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitNine, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitEleven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitEleven, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwelve(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwelve, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThirteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThirteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitFourteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitFourteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitFifteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitFifteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitSixteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitSixteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitSeventeen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitSeventeen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitEighteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitEighteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitNineteen(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitNineteen, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwenty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwenty, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyOne, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyTwo, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyThree, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyFour(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyFour, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyFive(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyFive, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentySix(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentySix, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentySeven(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentySeven, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyEight(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyEight, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitTwentyNine(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitTwentyNine, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThirty(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThirty, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThirtyOne(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThirtyOne, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThirtyTwo(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThirtyTwo, BetAmountPlus);
}
void RouletteGame::AddToBetHorizontalSplitThirtyThree(const int& BetAmountPlus) {
	AddToBet(m_BetAmountHorizontalSplitThirtyThree, BetAmountPlus);
}

// Round End Clear Bets
void RouletteGame::ResetAllBetsAfterRound() {
	//Reset Current Bet Amount
	m_BetAmountBlackOdds = 0;
	m_BetAmountRedEven = 0;

	m_BetAmountOneToEighteen = 0;
	m_BetAmountNineteenToThirtySix = 0;

	m_BetAmountFirstTwelve = 0;
	m_BetAmountSecondTwelve = 0;
	m_BetAmountThirdTwelve = 0;

	m_BetAmountFirstColumn = 0;
	m_BetAmountSecondColumn = 0;
	m_BetAmountThirdColumn = 0;

	m_BetAmountNumberZero = 0;
	m_BetAmountNumberOne = 0;
	m_BetAmountNumberTwo = 0;
	m_BetAmountNumberThree = 0;
	m_BetAmountNumberFour = 0;
	m_BetAmountNumberFive = 0;
	m_BetAmountNumberSix = 0;
	m_BetAmountNumberSeven = 0;
	m_BetAmountNumberEight = 0;
	m_BetAmountNumberNine = 0;
	m_BetAmountNumberTen = 0;
	m_BetAmountNumberEleven = 0;
	m_BetAmountNumberTwelve = 0;
	m_BetAmountNumberThirteen = 0;
	m_BetAmountNumberFourteen = 0;
	m_BetAmountNumberFifteen = 0;
	m_BetAmountNumberSixteen = 0;
	m_BetAmountNumberSeventeen = 0;
	m_BetAmountNumberEighteen = 0;
	m_BetAmountNumberNineteen = 0;
	m_BetAmountNumberTwenty = 0;
	m_BetAmountNumberTwentyOne = 0;
	m_BetAmountNumberTwentyTwo = 0;
	m_BetAmountNumberTwentyThree = 0;
	m_BetAmountNumberTwentyFour = 0;
	m_BetAmountNumberTwentyFive = 0;
	m_BetAmountNumberTwentySix = 0;
	m_BetAmountNumberTwentySeven = 0;
	m_BetAmountNumberTwentyEight = 0;
	m_BetAmountNumberTwentyNine = 0;
	m_BetAmountNumberThirty = 0;
	m_BetAmountNumberThirtyOne = 0;
	m_BetAmountNumberThirtyTwo = 0;
	m_BetAmountNumberThirtyThree = 0;
	m_BetAmountNumberThirtyFour = 0;
	m_BetAmountNumberThirtyFive = 0;
	m_BetAmountNumberThirtySix = 0;


	m_BetAmountStreetOne = 0;
	m_BetAmountStreetTwo = 0;
	m_BetAmountStreetThree = 0;
	m_BetAmountStreetFour = 0;
	m_BetAmountStreetFive = 0;
	m_BetAmountStreetSix = 0;
	m_BetAmountStreetSeven = 0;
	m_BetAmountStreetEight = 0;
	m_BetAmountStreetNine = 0;
	m_BetAmountStreetTen = 0;
	m_BetAmountStreetEleven = 0;
	m_BetAmountStreetTwelve = 0;

	m_BetAmountStreetZeroOneTwo = 0;
	m_BetAmountStreetZeroTwoThree = 0;

	m_BetAmountDoubleStreetZeroOneTwoThree = 0;
	m_BetAmountDoubleStreetOneTwo = 0;
	m_BetAmountDoubleStreetTwoThree = 0;
	m_BetAmountDoubleStreetThreeFour = 0;
	m_BetAmountDoubleStreetFourFive = 0;
	m_BetAmountDoubleStreetFiveSix = 0;
	m_BetAmountDoubleStreetSixSeven = 0;
	m_BetAmountDoubleStreetSevenEight = 0;
	m_BetAmountDoubleStreetEightNine = 0;
	m_BetAmountDoubleStreetNineTen = 0;
	m_BetAmountDoubleStreetTenEleven = 0;
	m_BetAmountDoubleStreetElevenTwelve = 0;

	//Square Bets
	m_BetAmountSquareOne = 0;
	m_BetAmountSquareTwo = 0;
	m_BetAmountSquareThree = 0;
	m_BetAmountSquareFour = 0;
	m_BetAmountSquareFive = 0;
	m_BetAmountSquareSix = 0;
	m_BetAmountSquareSeven = 0;
	m_BetAmountSquareEight = 0;
	m_BetAmountSquareNine = 0;
	m_BetAmountSquareTen = 0;
	m_BetAmountSquareEleven = 0;
	m_BetAmountSquareTwelve = 0;
	m_BetAmountSquareThirteen = 0;
	m_BetAmountSquareFourteen = 0;
	m_BetAmountSquareFifteen = 0;
	m_BetAmountSquareSixteen = 0;
	m_BetAmountSquareSeventeen = 0;
	m_BetAmountSquareEighteen = 0;
	m_BetAmountSquareNineteen = 0;
	m_BetAmountSquareTwenty = 0;
	m_BetAmountSquareTwentyOne = 0;
	m_BetAmountSquareTwentyTwo = 0;

	//Split Vertical Bets
	m_BetAmountVerticalSplitOne = 0;
	m_BetAmountVerticalSplitTwo = 0;
	m_BetAmountVerticalSplitThree = 0;
	m_BetAmountVerticalSplitFour = 0;
	m_BetAmountVerticalSplitFive = 0;
	m_BetAmountVerticalSplitSix = 0;
	m_BetAmountVerticalSplitSeven = 0;
	m_BetAmountVerticalSplitEight = 0;
	m_BetAmountVerticalSplitNine = 0;
	m_BetAmountVerticalSplitTen = 0;
	m_BetAmountVerticalSplitEleven = 0;
	m_BetAmountVerticalSplitTwelve = 0;
	m_BetAmountVerticalSplitThirteen = 0;
	m_BetAmountVerticalSplitFourteen = 0;
	m_BetAmountVerticalSplitFifteen = 0;
	m_BetAmountVerticalSplitSixteen = 0;
	m_BetAmountVerticalSplitSeventeen = 0;
	m_BetAmountVerticalSplitEighteen = 0;
	m_BetAmountVerticalSplitNineteen = 0;
	m_BetAmountVerticalSplitTwenty = 0;
	m_BetAmountVerticalSplitTwentyone = 0;
	m_BetAmountVerticalSplitTwentytwo = 0;
	m_BetAmountVerticalSplitTwentythree = 0;
	m_BetAmountVerticalSplitTwentyfour = 0;

	//Split Horizontal Bets
	m_BetAmountHorizontalSplitOne = 0;
	m_BetAmountHorizontalSplitTwo = 0;
	m_BetAmountHorizontalSplitThree = 0;
	m_BetAmountHorizontalSplitFour = 0;
	m_BetAmountHorizontalSplitFive = 0;
	m_BetAmountHorizontalSplitSix = 0;
	m_BetAmountHorizontalSplitSeven = 0;
	m_BetAmountHorizontalSplitEight = 0;
	m_BetAmountHorizontalSplitNine = 0;
	m_BetAmountHorizontalSplitTen = 0;
	m_BetAmountHorizontalSplitEleven = 0;
	m_BetAmountHorizontalSplitTwelve = 0;
	m_BetAmountHorizontalSplitThirteen = 0;
	m_BetAmountHorizontalSplitFourteen = 0;
	m_BetAmountHorizontalSplitFifteen = 0;
	m_BetAmountHorizontalSplitSixteen = 0;
	m_BetAmountHorizontalSplitSeventeen = 0;
	m_BetAmountHorizontalSplitEighteen = 0;
	m_BetAmountHorizontalSplitNineteen = 0;
	m_BetAmountHorizontalSplitTwenty = 0;
	m_BetAmountHorizontalSplitTwentyOne = 0;
	m_BetAmountHorizontalSplitTwentyTwo = 0;
	m_BetAmountHorizontalSplitTwentyThree = 0;
	m_BetAmountHorizontalSplitTwentyFour = 0;
	m_BetAmountHorizontalSplitTwentyFive = 0;
	m_BetAmountHorizontalSplitTwentySix = 0;
	m_BetAmountHorizontalSplitTwentySeven = 0;
	m_BetAmountHorizontalSplitTwentyEight = 0;
	m_BetAmountHorizontalSplitTwentyNine = 0;
	m_BetAmountHorizontalSplitThirty = 0;
	m_BetAmountHorizontalSplitThirtyOne = 0;
	m_BetAmountHorizontalSplitThirtyTwo = 0;
	m_BetAmountHorizontalSplitThirtyThree = 0;

}

// Clearing All board Bets if user decides to change bets
void RouletteGame::ClearAllBets() {
	//Put money back into balance first
	m_Balance += m_BetAmountBlackOdds +
		m_BetAmountRedEven +
		m_BetAmountOneToEighteen +
		m_BetAmountNineteenToThirtySix +
		m_BetAmountFirstTwelve +
		m_BetAmountSecondTwelve +
		m_BetAmountThirdTwelve +
		m_BetAmountFirstColumn +
		m_BetAmountSecondColumn +
		m_BetAmountThirdColumn +
		m_BetAmountNumberZero +
		m_BetAmountNumberOne +
		m_BetAmountNumberTwo +
		m_BetAmountNumberThree +
		m_BetAmountNumberFour +
		m_BetAmountNumberFive +
		m_BetAmountNumberSix +
		m_BetAmountNumberSeven +
		m_BetAmountNumberEight +
		m_BetAmountNumberNine +
		m_BetAmountNumberTen +
		m_BetAmountNumberEleven +
		m_BetAmountNumberTwelve +
		m_BetAmountNumberThirteen +
		m_BetAmountNumberFourteen +
		m_BetAmountNumberFifteen +
		m_BetAmountNumberSixteen +
		m_BetAmountNumberSeventeen +
		m_BetAmountNumberEighteen +
		m_BetAmountNumberNineteen +
		m_BetAmountNumberTwenty +
		m_BetAmountNumberTwentyOne +
		m_BetAmountNumberTwentyTwo +
		m_BetAmountNumberTwentyThree +
		m_BetAmountNumberTwentyFour +
		m_BetAmountNumberTwentyFive +
		m_BetAmountNumberTwentySix +
		m_BetAmountNumberTwentySeven +
		m_BetAmountNumberTwentyEight +
		m_BetAmountNumberTwentyNine +
		m_BetAmountNumberThirty +
		m_BetAmountNumberThirtyOne +
		m_BetAmountNumberThirtyTwo +
		m_BetAmountNumberThirtyThree +
		m_BetAmountNumberThirtyFour +
		m_BetAmountNumberThirtyFive +
		m_BetAmountNumberThirtySix +
		m_BetAmountStreetOne +
		m_BetAmountStreetTwo +
		m_BetAmountStreetThree +
		m_BetAmountStreetFour +
		m_BetAmountStreetFive +
		m_BetAmountStreetSix +
		m_BetAmountStreetSeven +
		m_BetAmountStreetEight +
		m_BetAmountStreetNine +
		m_BetAmountStreetTen +
		m_BetAmountStreetEleven +
		m_BetAmountStreetTwelve +
		m_BetAmountDoubleStreetZeroOneTwoThree +
		m_BetAmountStreetZeroOneTwo +
		m_BetAmountStreetZeroTwoThree +
		m_BetAmountDoubleStreetOneTwo +
		m_BetAmountDoubleStreetTwoThree +
		m_BetAmountDoubleStreetThreeFour +
		m_BetAmountDoubleStreetFourFive +
		m_BetAmountDoubleStreetFiveSix +
		m_BetAmountDoubleStreetSixSeven +
		m_BetAmountDoubleStreetSevenEight +
		m_BetAmountDoubleStreetEightNine +
		m_BetAmountDoubleStreetNineTen +
		m_BetAmountDoubleStreetTenEleven +
		m_BetAmountDoubleStreetElevenTwelve +
		m_BetAmountSquareOne +
		m_BetAmountSquareTwo +
		m_BetAmountSquareThree +
		m_BetAmountSquareFour +
		m_BetAmountSquareFive +
		m_BetAmountSquareSix +
		m_BetAmountSquareSeven +
		m_BetAmountSquareEight +
		m_BetAmountSquareNine +
		m_BetAmountSquareTen +
		m_BetAmountSquareEleven +
		m_BetAmountSquareTwelve +
		m_BetAmountSquareThirteen +
		m_BetAmountSquareFourteen +
		m_BetAmountSquareFifteen +
		m_BetAmountSquareSixteen +
		m_BetAmountSquareSeventeen +
		m_BetAmountSquareEighteen +
		m_BetAmountSquareNineteen +
		m_BetAmountSquareTwenty +
		m_BetAmountSquareTwentyOne +
		m_BetAmountSquareTwentyTwo +
		m_BetAmountVerticalSplitOne +
		m_BetAmountVerticalSplitTwo +
		m_BetAmountVerticalSplitThree +
		m_BetAmountVerticalSplitFour +
		m_BetAmountVerticalSplitFive +
		m_BetAmountVerticalSplitSix +
		m_BetAmountVerticalSplitSeven +
		m_BetAmountVerticalSplitEight +
		m_BetAmountVerticalSplitNine +
		m_BetAmountVerticalSplitTen +
		m_BetAmountVerticalSplitEleven +
		m_BetAmountVerticalSplitTwelve +
		m_BetAmountVerticalSplitThirteen +
		m_BetAmountVerticalSplitFourteen +
		m_BetAmountVerticalSplitFifteen +
		m_BetAmountVerticalSplitSixteen +
		m_BetAmountVerticalSplitSeventeen +
		m_BetAmountVerticalSplitEighteen +
		m_BetAmountVerticalSplitNineteen +
		m_BetAmountVerticalSplitTwenty +
		m_BetAmountVerticalSplitTwentyone +
		m_BetAmountVerticalSplitTwentytwo +
		m_BetAmountVerticalSplitTwentythree +
		m_BetAmountVerticalSplitTwentyfour +
		m_BetAmountHorizontalSplitOne +
		m_BetAmountHorizontalSplitTwo +
		m_BetAmountHorizontalSplitThree +
		m_BetAmountHorizontalSplitFour +
		m_BetAmountHorizontalSplitFive +
		m_BetAmountHorizontalSplitSix +
		m_BetAmountHorizontalSplitSeven +
		m_BetAmountHorizontalSplitEight +
		m_BetAmountHorizontalSplitNine +
		m_BetAmountHorizontalSplitTen +
		m_BetAmountHorizontalSplitEleven +
		m_BetAmountHorizontalSplitTwelve +
		m_BetAmountHorizontalSplitThirteen +
		m_BetAmountHorizontalSplitFourteen +
		m_BetAmountHorizontalSplitFifteen +
		m_BetAmountHorizontalSplitSixteen +
		m_BetAmountHorizontalSplitSeventeen +
		m_BetAmountHorizontalSplitEighteen +
		m_BetAmountHorizontalSplitNineteen +
		m_BetAmountHorizontalSplitTwenty +
		m_BetAmountHorizontalSplitTwentyOne +
		m_BetAmountHorizontalSplitTwentyTwo +
		m_BetAmountHorizontalSplitTwentyThree +
		m_BetAmountHorizontalSplitTwentyFour +
		m_BetAmountHorizontalSplitTwentyFive +
		m_BetAmountHorizontalSplitTwentySix +
		m_BetAmountHorizontalSplitTwentySeven +
		m_BetAmountHorizontalSplitTwentyEight +
		m_BetAmountHorizontalSplitTwentyNine +
		m_BetAmountHorizontalSplitThirty +
		m_BetAmountHorizontalSplitThirtyOne +
		m_BetAmountHorizontalSplitThirtyTwo +
		m_BetAmountHorizontalSplitThirtyThree;

	//Then reset the bets
	ResetAllBetsAfterRound();

	std::cout << "Bets have been cleared" << std::endl;
}

// Spinning the Roulette Wheel
void RouletteGame::GenerateRandomNumber() {
	system("CLS");
	std::cout << "Spinning" << std::endl;
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> RouletteBall{ 0, 36 };
	srand(time(0));
	m_SpinNumber = RouletteBall(mt);
	system("CLS");
}

void RouletteGame::checkAndProcessBet(long long int betAmount, const int* betNumbers, const int forloopvalue, int multiplier, const std::string betname) {
	if (betAmount > 0) {
		bool betWon = false;
		for (int i = 0; i < forloopvalue; ++i) {
			if (m_SpinNumber == betNumbers[i]) {
				betWon = true;
				break;
			}
		}

		//Money is already deducted so if u win it increase otherwise if u lose then NULL
		m_Balance += (betWon ? betAmount + (betAmount * multiplier) : NULL);
	}
	else {
		return;
	}
}

void RouletteGame::StartRound() {

	//Black Red || Odd Even Bet Checks
	checkAndProcessBet(m_BetAmountBlackOdds, m_BLACKODDS,	18, 1, "Black");
	checkAndProcessBet(m_BetAmountRedEven, m_REDEVEN, 18, 1, "Red");

	//1 to 18 || 19 to 36 Bet Checks
	checkAndProcessBet(m_BetAmountOneToEighteen, m_OneToEighteen,18, 1, "1 to 18");
	checkAndProcessBet(m_BetAmountNineteenToThirtySix, m_NineteenToThirtySix,18, 1, "19 to 36");

	//Twelves Number Bet Checks
	checkAndProcessBet(m_BetAmountFirstTwelve, m_FirstTwelve, 12, 2, "1st 12");
	checkAndProcessBet(m_BetAmountSecondTwelve, m_SecondTwelve, 12, 2, "2nd 12");
	checkAndProcessBet(m_BetAmountThirdTwelve, m_ThirdTwelve, 12, 2, "2rd 12");

	//Rows Number Bet Checks
	checkAndProcessBet(m_BetAmountFirstColumn, m_FirstColumn, 12, 2, "1st Column");
	checkAndProcessBet(m_BetAmountSecondColumn, m_SecondColumn, 12, 2, "2nd Column");
	checkAndProcessBet(m_BetAmountThirdColumn, m_ThirdColumn, 12, 2, "3rd Column");

	//Single Number Bet Checks
	checkAndProcessBet(m_BetAmountNumberZero, m_NumberZero, 1, 35, "Number 0");
	checkAndProcessBet(m_BetAmountNumberOne, m_NumberOne, 1, 35, "Number 1");
	checkAndProcessBet(m_BetAmountNumberTwo, m_NumberTwo, 1, 35, "Number 2");
	checkAndProcessBet(m_BetAmountNumberThree, m_NumberThree, 1, 35, "Number 3");
	checkAndProcessBet(m_BetAmountNumberFour, m_NumberFour, 1, 35, "Number 4");
	checkAndProcessBet(m_BetAmountNumberFive, m_NumberFive, 1, 35, "Number 5");
	checkAndProcessBet(m_BetAmountNumberSix, m_NumberSix, 1, 35, "Number 6");
	checkAndProcessBet(m_BetAmountNumberSeven, m_NumberSeven, 1, 35, "Number 7");
	checkAndProcessBet(m_BetAmountNumberEight, m_NumberEight, 1, 35, "Number 8");
	checkAndProcessBet(m_BetAmountNumberNine, m_NumberNine, 1, 35, "Number 9");
	checkAndProcessBet(m_BetAmountNumberTen, m_NumberTen, 1, 35, "Number 10");
	checkAndProcessBet(m_BetAmountNumberEleven, m_NumberEleven, 1, 35, "Number 11");
	checkAndProcessBet(m_BetAmountNumberTwelve, m_NumberTwelve, 1, 35, "Number 12");
	checkAndProcessBet(m_BetAmountNumberThirteen, m_NumberThirteen, 1, 35, "Number 13");
	checkAndProcessBet(m_BetAmountNumberFourteen, m_NumberFourteen, 1, 35, "Number 14");
	checkAndProcessBet(m_BetAmountNumberFifteen, m_NumberFifteen, 1, 35, "Number 15");
	checkAndProcessBet(m_BetAmountNumberSixteen, m_NumberSixteen, 1, 35, "Number 16");
	checkAndProcessBet(m_BetAmountNumberSeventeen, m_NumberSeventeen, 1, 35, "Number 17");
	checkAndProcessBet(m_BetAmountNumberEighteen, m_NumberEighteen, 1, 35, "Number 18");
	checkAndProcessBet(m_BetAmountNumberNineteen, m_NumberNineteen, 1, 35, "Number 19");
	checkAndProcessBet(m_BetAmountNumberTwenty, m_NumberTwenty, 1, 35, "Number 20");
	checkAndProcessBet(m_BetAmountNumberTwentyOne, m_NumberTwentyOne, 1, 35, "Number 21");
	checkAndProcessBet(m_BetAmountNumberTwentyTwo, m_NumberTwentyTwo, 1, 35, "Number 22");
	checkAndProcessBet(m_BetAmountNumberTwentyThree, m_NumberTwentyThree, 1, 35, "Number 23");
	checkAndProcessBet(m_BetAmountNumberTwentyFour, m_NumberTwentyFour, 1, 35, "Number 24");
	checkAndProcessBet(m_BetAmountNumberTwentyFive, m_NumberTwentyFive, 1, 35, "Number 25");
	checkAndProcessBet(m_BetAmountNumberTwentySix, m_NumberTwentySix, 1, 35, "Number 26");
	checkAndProcessBet(m_BetAmountNumberTwentySeven, m_NumberTwentySeven, 1, 35, "Number 27");
	checkAndProcessBet(m_BetAmountNumberTwentyEight, m_NumberTwentyEight, 1, 35, "Number 28");
	checkAndProcessBet(m_BetAmountNumberTwentyNine, m_NumberTwentyNine, 1, 35, "Number 29");
	checkAndProcessBet(m_BetAmountNumberThirty, m_NumberThirty, 1, 35, "Number 30");
	checkAndProcessBet(m_BetAmountNumberThirtyOne, m_NumberThirtyOne, 1, 35, "Number 31");
	checkAndProcessBet(m_BetAmountNumberThirtyTwo, m_NumberThirtyTwo, 1, 35, "Number 32");
	checkAndProcessBet(m_BetAmountNumberThirtyThree, m_NumberThirtyThree, 1, 35, "Number 33");
	checkAndProcessBet(m_BetAmountNumberThirtyFour, m_NumberThirtyFour, 1, 35, "Number 34");
	checkAndProcessBet(m_BetAmountNumberThirtyFive, m_NumberThirtyFive, 1, 35, "Number 35");
	checkAndProcessBet(m_BetAmountNumberThirtySix, m_NumberThirtySix, 1, 35, "Number 36");

	//SingleStreet BetChecks
	checkAndProcessBet(m_BetAmountStreetOne, m_StreetOne, 3, 11, "Street One");
	checkAndProcessBet(m_BetAmountStreetTwo, m_StreetTwo, 3, 11, "Street Two");
	checkAndProcessBet(m_BetAmountStreetThree, m_StreetThree, 3, 11, "Street Three");
	checkAndProcessBet(m_BetAmountStreetFour, m_StreetFour, 3, 11, "Street Four");
	checkAndProcessBet(m_BetAmountStreetFive, m_StreetFive, 3, 11, "Street Five");
	checkAndProcessBet(m_BetAmountStreetSix, m_StreetSix, 3, 11, "Street Six");
	checkAndProcessBet(m_BetAmountStreetSeven, m_StreetSeven, 3, 11, "Street Seven");
	checkAndProcessBet(m_BetAmountStreetEight, m_StreetEight, 3, 11, "Street Eight");
	checkAndProcessBet(m_BetAmountStreetNine, m_StreetNine, 3, 11, "Street Nine");
	checkAndProcessBet(m_BetAmountStreetTen, m_StreetTen, 3, 11, "Street Ten");
	checkAndProcessBet(m_BetAmountStreetEleven, m_StreetEleven, 3, 11, "Street Eleven");
	checkAndProcessBet(m_BetAmountStreetTwelve, m_StreetTwelve, 3, 11, "Street Twelve");

	//European Single Street BetChecks
	checkAndProcessBet(m_BetAmountStreetZeroOneTwo, m_StreetZeroOneTwo, 3, 11, "StreetZeroOneTwo");
	checkAndProcessBet(m_BetAmountStreetZeroTwoThree, m_StreetZeroTwoThree, 3, 11, "StreetZeroTwoThree");

	//DoubleStreet BetChecks European
	checkAndProcessBet(m_BetAmountDoubleStreetZeroOneTwoThree, m_DoubleStreetZeroOneTwoThree, 4, 5, "DoubleStreetZeroOneTwoThree");
	checkAndProcessBet(m_BetAmountDoubleStreetOneTwo,	m_DoubleStreetOneTwo, 6, 5, "DoubleStreetOneTwo");
	checkAndProcessBet(m_BetAmountDoubleStreetTwoThree, m_DoubleStreetTwoThree, 6, 5, "DoubleStreetTwoThree");
	checkAndProcessBet(m_BetAmountDoubleStreetThreeFour, m_DoubleStreetThreeFour, 6, 5, "DoubleStreetThreeFour");
	checkAndProcessBet(m_BetAmountDoubleStreetFourFive, m_DoubleStreetFourFive, 6, 5, "DoubleStreetFourFive");
	checkAndProcessBet(m_BetAmountDoubleStreetFiveSix, m_DoubleStreetFiveSix, 6, 5, "DoubleStreetFiveSix");
	checkAndProcessBet(m_BetAmountDoubleStreetSixSeven, m_DoubleStreetSixSeven, 6, 5, "DoubleStreetSixSeven");
	checkAndProcessBet(m_BetAmountDoubleStreetSevenEight, m_DoubleStreetSevenEight, 6, 5, "DoubleStreetSevenEight");
	checkAndProcessBet(m_BetAmountDoubleStreetEightNine, m_DoubleStreetEightNine, 6, 5, "DoubleStreetEightNine");
	checkAndProcessBet(m_BetAmountDoubleStreetNineTen, m_DoubleStreetNineTen, 6, 5, "DoubleStreetNineTen");
	checkAndProcessBet(m_BetAmountDoubleStreetTenEleven, m_DoubleStreetTenEleven, 6, 5, "DoubleStreetTenEleven");
	checkAndProcessBet(m_BetAmountDoubleStreetElevenTwelve, m_DoubleStreetElevenTwelve, 6, 5, "DoubleStreetElevenTwelve");

	//Sqaure BetsChecks
	checkAndProcessBet(m_BetAmountSquareOne, m_SquareOne, 4, 8, "SquareOne");
	checkAndProcessBet(m_BetAmountSquareTwo, m_SquareTwo, 4, 8, "SquareTwo");
	checkAndProcessBet(m_BetAmountSquareThree, m_SquareThree, 4, 8, "SquareThree");
	checkAndProcessBet(m_BetAmountSquareFour, m_SquareFour, 4, 8, "SquareFour");
	checkAndProcessBet(m_BetAmountSquareFive, m_SquareFive, 4, 8, "SquareFive");
	checkAndProcessBet(m_BetAmountSquareSix, m_SquareSix, 4, 8, "SquareSix");
	checkAndProcessBet(m_BetAmountSquareSeven, m_SquareSeven, 4, 8, "SquareSeven");
	checkAndProcessBet(m_BetAmountSquareEight, m_SquareEight, 4, 8, "SquareEight");
	checkAndProcessBet(m_BetAmountSquareNine, m_SquareNine, 4, 8, "SquareNine");
	checkAndProcessBet(m_BetAmountSquareTen, m_SquareTen, 4, 8, "SquareTen");
	checkAndProcessBet(m_BetAmountSquareEleven, m_SquareEleven, 4, 8, "SquareEleven");
	checkAndProcessBet(m_BetAmountSquareTwelve, m_SquareTwelve, 4, 8, "SquareTwelve");
	checkAndProcessBet(m_BetAmountSquareThirteen, m_SquareThirteen, 4, 8, "SquareThirteen");
	checkAndProcessBet(m_BetAmountSquareFourteen, m_SquareFourteen, 4, 8, "SquareFourteen");
	checkAndProcessBet(m_BetAmountSquareFifteen, m_SquareFifteen, 4, 8, "SquareFifteen");
	checkAndProcessBet(m_BetAmountSquareSixteen, m_SquareSixteen, 4, 8, "SquareSixteen");
	checkAndProcessBet(m_BetAmountSquareSeventeen, m_SquareSeventeen, 4, 8, "SquareSeventeen");
	checkAndProcessBet(m_BetAmountSquareEighteen, m_SquareEighteen, 4, 8, "SquareEighteen");
	checkAndProcessBet(m_BetAmountSquareNineteen, m_SquareNineteen, 4, 8, "SquareNineteen");
	checkAndProcessBet(m_BetAmountSquareTwenty, m_SquareTwenty, 4, 8, "SquareTwenty");
	checkAndProcessBet(m_BetAmountSquareTwentyOne, m_SquareTwentyOne, 4, 8, "SquareTwentyOne");
	checkAndProcessBet(m_BetAmountSquareTwentyTwo, m_SquareTwentyTwo, 4, 8, "SquareTwentyTwo");

	//Vertical Split Bet Checks
	checkAndProcessBet(m_BetAmountVerticalSplitOne, m_VerticalSplitOne, 2, 17, "VerticalSplitOne");
	checkAndProcessBet(m_BetAmountVerticalSplitTwo, m_VerticalSplitTwo, 2, 17, "VerticalSplitTwo");
	checkAndProcessBet(m_BetAmountVerticalSplitThree, m_VerticalSplitThree, 2, 17, "VerticalSplitThree");
	checkAndProcessBet(m_BetAmountVerticalSplitFour, m_VerticalSplitFour, 2, 17, "VerticalSplitFour");
	checkAndProcessBet(m_BetAmountVerticalSplitFive, m_VerticalSplitFive, 2, 17, "VerticalSplitFive");
	checkAndProcessBet(m_BetAmountVerticalSplitSix, m_VerticalSplitSix, 2, 17, "VerticalSplitSix");
	checkAndProcessBet(m_BetAmountVerticalSplitSeven, m_VerticalSplitSeven, 2, 17, "VerticalSplitSeven");
	checkAndProcessBet(m_BetAmountVerticalSplitEight, m_VerticalSplitEight, 2, 17, "VerticalSplitEight");
	checkAndProcessBet(m_BetAmountVerticalSplitNine, m_VerticalSplitNine, 2, 17, "VerticalSplitNine");
	checkAndProcessBet(m_BetAmountVerticalSplitTen, m_VerticalSplitTen, 2, 17, "VerticalSplitTen");
	checkAndProcessBet(m_BetAmountVerticalSplitEleven, m_VerticalSplitEleven, 2, 17, "VerticalSplitEleven");
	checkAndProcessBet(m_BetAmountVerticalSplitTwelve, m_VerticalSplitTwelve, 2, 17, "VerticalSplitTwelve");
	checkAndProcessBet(m_BetAmountVerticalSplitThirteen, m_VerticalSplitThirteen, 2, 17, "VerticalSplitThirteen");
	checkAndProcessBet(m_BetAmountVerticalSplitFourteen, m_VerticalSplitFourteen, 2, 17, "VerticalSplitFourteen");
	checkAndProcessBet(m_BetAmountVerticalSplitFifteen, m_VerticalSplitFifteen, 2, 17, "VerticalSplitFifteen");
	checkAndProcessBet(m_BetAmountVerticalSplitSixteen, m_VerticalSplitSixteen, 2, 17, "VerticalSplitSixteen");
	checkAndProcessBet(m_BetAmountVerticalSplitSeventeen, m_VerticalSplitSeventeen, 2, 17, "VerticalSplitSeventeen");
	checkAndProcessBet(m_BetAmountVerticalSplitEighteen, m_VerticalSplitEighteen, 2, 17, "VerticalSplitEighteen");
	checkAndProcessBet(m_BetAmountVerticalSplitNineteen, m_VerticalSplitNineteen, 2, 17, "VerticalSplitNineteen");
	checkAndProcessBet(m_BetAmountVerticalSplitTwenty, m_VerticalSplitTwenty, 2, 17, "VerticalSplitTwenty");
	checkAndProcessBet(m_BetAmountVerticalSplitTwentyone, m_VerticalSplitTwentyone, 2, 17, "VerticalSplitTwentyone");
	checkAndProcessBet(m_BetAmountVerticalSplitTwentytwo, m_VerticalSplitTwentytwo, 2, 17, "VerticalSplitTwentytwo");
	checkAndProcessBet(m_BetAmountVerticalSplitTwentythree, m_VerticalSplitTwentythree, 2, 17, "VerticalSplitTwentythree");
	checkAndProcessBet(m_BetAmountVerticalSplitTwentyfour, m_VerticalSplitTwentyfour, 2, 17, "VerticalSplitTwentyfour");

	//Horizontal Split Bet Checks
	checkAndProcessBet(m_BetAmountHorizontalSplitOne, m_HorizontalSplitOne, 2, 17, "HorizontalSplitOne");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwo, m_HorizontalSplitTwo, 2, 17, "HorizontalSplitTwo");
	checkAndProcessBet(m_BetAmountHorizontalSplitThree, m_HorizontalSplitThree, 2, 17, "HorizontalSplitThree");
	checkAndProcessBet(m_BetAmountHorizontalSplitFour, m_HorizontalSplitFour, 2, 17, "HorizontalSplitFour");
	checkAndProcessBet(m_BetAmountHorizontalSplitFive, m_HorizontalSplitFive, 2, 17, "HorizontalSplitFive");
	checkAndProcessBet(m_BetAmountHorizontalSplitSix, m_HorizontalSplitSix, 2, 17, "HorizontalSplitSix");
	checkAndProcessBet(m_BetAmountHorizontalSplitSeven, m_HorizontalSplitSeven, 2, 17, "HorizontalSplitSeven");
	checkAndProcessBet(m_BetAmountHorizontalSplitEight, m_HorizontalSplitEight, 2, 17, "HorizontalSplitEight");
	checkAndProcessBet(m_BetAmountHorizontalSplitNine, m_HorizontalSplitNine, 2, 17, "HorizontalSplitNine");
	checkAndProcessBet(m_BetAmountHorizontalSplitTen, m_HorizontalSplitTen, 2, 17, "HorizontalSplitTen");
	checkAndProcessBet(m_BetAmountHorizontalSplitEleven, m_HorizontalSplitEleven, 2, 17, "HorizontalSplitEleven");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwelve, m_HorizontalSplitTwelve, 2, 17, "HorizontalSplitTwelve");
	checkAndProcessBet(m_BetAmountHorizontalSplitThirteen, m_HorizontalSplitThirteen, 2, 17, "HorizontalSplitThirteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitFourteen, m_HorizontalSplitFourteen, 2, 17, "HorizontalSplitFourteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitFifteen, m_HorizontalSplitFifteen, 2, 17, "HorizontalSplitFifteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitSixteen, m_HorizontalSplitSixteen, 2, 17, "HorizontalSplitSixteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitSeventeen, m_HorizontalSplitSeventeen, 2, 17, "HorizontalSplitSeventeen");
	checkAndProcessBet(m_BetAmountHorizontalSplitEighteen, m_HorizontalSplitEighteen, 2, 17, "HorizontalSplitEighteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitNineteen, m_HorizontalSplitNineteen, 2, 17, "HorizontalSplitNineteen");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwenty, m_HorizontalSplitTwenty, 2, 17, "HorizontalSplitTwenty");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyOne, m_HorizontalSplitTwentyOne, 2, 17, "HorizontalSplitTwentyOne");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyTwo, m_HorizontalSplitTwentyTwo, 2, 17, "HorizontalSplitTwentyTwo");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyThree, m_HorizontalSplitTwentyThree, 2, 17, "HorizontalSplitTwentyThree");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyFour, m_HorizontalSplitTwentyFour, 2, 17, "HorizontalSplitTwentyFour");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyFive, m_HorizontalSplitTwentyFive, 2, 17, "HorizontalSplitTwentyFive");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentySix, m_HorizontalSplitTwentySix, 2, 17, "HorizontalSplitTwentySix");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentySeven, m_HorizontalSplitTwentySeven, 2, 17, "HorizontalSplitTwentySeven");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyEight, m_HorizontalSplitTwentyEight, 2, 17, "HorizontalSplitTwentyEight");
	checkAndProcessBet(m_BetAmountHorizontalSplitTwentyNine, m_HorizontalSplitTwentyNine, 2, 17, "HorizontalSplitTwentyNine");
	checkAndProcessBet(m_BetAmountHorizontalSplitThirty, m_HorizontalSplitThirty, 2, 17, "HorizontalSplitThirty");
	checkAndProcessBet(m_BetAmountHorizontalSplitThirtyOne, m_HorizontalSplitThirtyOne, 2, 17, "HorizontalSplitThirtyOne");
	checkAndProcessBet(m_BetAmountHorizontalSplitThirtyTwo, m_HorizontalSplitThirtyTwo, 2, 17, "HorizontalSplitThirtyTwo");
	checkAndProcessBet(m_BetAmountHorizontalSplitThirtyThree, m_HorizontalSplitThirtyThree, 2, 17, "HorizontalSplitThirtyThree");


	//Display What it landed on ( could prob just do if else instead of two forloops...)
	for (int i = 0; i < sizeof(m_BLACKODDS) / sizeof(m_BLACKODDS[0]); ++i) {
		if (m_SpinNumber == m_BLACKODDS[i]) {
			std::cout << m_SpinNumber << " Black" << std::endl;
		}
	}

	for (int i = 0; i < sizeof(m_REDEVEN) / sizeof(m_REDEVEN[0]); ++i) {
		if (m_SpinNumber == m_REDEVEN[i]) {
			std::cout << m_SpinNumber << " Red" << std::endl;
		}
	}

	if (m_SpinNumber == 0) {
		std::cout << m_SpinNumber << " Green" << std::endl;
	}

	//Reset all bets to 0 to play again
	ResetAllBetsAfterRound();

	//Update Pervious Spin Number for chat logs
	m_PreviousPreviousPreviousPreviousSpinNumber			= m_PreviousPreviousPreviousSpinNumber;
	m_PreviousPreviousPreviousSpinNumber					= m_PreviousPreviousSpinNumber;
	m_PreviousPreviousSpinNumber							= m_PreviousSpinNumber;
	m_PreviousSpinNumber									= m_SpinNumber;
	++m_IncrementShowCheck;


	//Clear output console
	//Sleep(1000);
	system("CLS");

	//Check Balance to end the game -- Maybe add hard mode where u can shut off pc LOL
	//int temp_balance = GetCurrentBalance(); // idk why but i had to do this for it to work
	//if (temp_balance <= 0) {
	//	std::cout << "Out of Money you lost!" << std::endl;
	//	Sleep(3000);
	//	exit(0);
	//}
}

