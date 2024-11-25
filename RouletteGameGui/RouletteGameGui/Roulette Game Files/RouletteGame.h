#pragma once
#include <iostream>
#include <windows.h>


struct SpinNumbers {
	int previousSpinNumber;
	int previousPreviousSpinNumber;
	int previousPreviousPreviousSpinNumber;
	int previousPreviousPreviousPreviousSpinNumber;
};

class RouletteGame {
private:

	//Show Numbers
	int  m_IncrementShowCheck{ 0 };
	bool m_ShowPreviousOne{ false };
	bool m_ShowPreviousTwo{ false };
	bool m_ShowPreviousThree{ false };
	bool m_ShowPreviousFour{ false };

	//Spin Numbers
	int m_PreviousPreviousPreviousPreviousSpinNumber{0};
	int m_PreviousPreviousPreviousSpinNumber{0};
	int m_PreviousPreviousSpinNumber{0};
	int m_PreviousSpinNumber{0};
	int m_SpinNumber{0};

	//User playing Balance
	long long int m_Balance							{150};

	//Red Black || Odd Even BetAmounts
	long long int m_BetAmountBlackOdds				{0};
	long long int m_BetAmountRedEven				{0};

	//1 to 18 || 19 to 36 Bet Amount
	long long int m_BetAmountOneToEighteen			{0};
	long long int m_BetAmountNineteenToThirtySix	{0};

	//First 12 || Second 12 || Third 12 Bet Amount
	long long int m_BetAmountFirstTwelve			{0};
	long long int m_BetAmountSecondTwelve			{0};
	long long int m_BetAmountThirdTwelve			{0};

	//these should be name rows
	long long int m_BetAmountFirstColumn			{0};
	long long int m_BetAmountSecondColumn			{0};
	long long int m_BetAmountThirdColumn			{0};

	//Single Number BetAmount
	long long int m_BetAmountNumberZero				{0};
	long long int m_BetAmountNumberOne				{0};
	long long int m_BetAmountNumberTwo				{0};
	long long int m_BetAmountNumberThree			{0};
	long long int m_BetAmountNumberFour				{0};
	long long int m_BetAmountNumberFive				{0};
	long long int m_BetAmountNumberSix				{0};
	long long int m_BetAmountNumberSeven			{0};
	long long int m_BetAmountNumberEight			{0};
	long long int m_BetAmountNumberNine				{0};
	long long int m_BetAmountNumberTen				{0};
	long long int m_BetAmountNumberEleven			{0};
	long long int m_BetAmountNumberTwelve			{0};
	long long int m_BetAmountNumberThirteen			{0};
	long long int m_BetAmountNumberFourteen			{0};
	long long int m_BetAmountNumberFifteen			{0};
	long long int m_BetAmountNumberSixteen			{0};
	long long int m_BetAmountNumberSeventeen		{0};
	long long int m_BetAmountNumberEighteen			{0};
	long long int m_BetAmountNumberNineteen			{0};
	long long int m_BetAmountNumberTwenty			{0};
	long long int m_BetAmountNumberTwentyOne		{0};
	long long int m_BetAmountNumberTwentyTwo		{0};
	long long int m_BetAmountNumberTwentyThree		{0};
	long long int m_BetAmountNumberTwentyFour		{0};
	long long int m_BetAmountNumberTwentyFive		{0};
	long long int m_BetAmountNumberTwentySix		{0};
	long long int m_BetAmountNumberTwentySeven		{0};
	long long int m_BetAmountNumberTwentyEight		{0};
	long long int m_BetAmountNumberTwentyNine		{0};
	long long int m_BetAmountNumberThirty			{0};
	long long int m_BetAmountNumberThirtyOne		{0};
	long long int m_BetAmountNumberThirtyTwo		{0};
	long long int m_BetAmountNumberThirtyThree		{0};
	long long int m_BetAmountNumberThirtyFour		{0};
	long long int m_BetAmountNumberThirtyFive		{0};
	long long int m_BetAmountNumberThirtySix		{0};

	//Single Street Bet Amount
	long long int m_BetAmountStreetOne		{0};
	long long int m_BetAmountStreetTwo		{0};
	long long int m_BetAmountStreetThree	{0};
	long long int m_BetAmountStreetFour		{0};
	long long int m_BetAmountStreetFive		{0};
	long long int m_BetAmountStreetSix		{0};
	long long int m_BetAmountStreetSeven	{0};
	long long int m_BetAmountStreetEight	{0};
	long long int m_BetAmountStreetNine		{0};
	long long int m_BetAmountStreetTen		{0};
	long long int m_BetAmountStreetEleven	{0};
	long long int m_BetAmountStreetTwelve	{0};

	
	long long int m_BetAmountStreetZeroOneTwo		{0};
	long long int m_BetAmountStreetZeroTwoThree		{0};


	//Double Street European Version Bet Amount
	long long int m_BetAmountDoubleStreetZeroOneTwoThree			{0};
	long long int m_BetAmountDoubleStreetOneTwo						{0};
	long long int m_BetAmountDoubleStreetTwoThree					{0};
	long long int m_BetAmountDoubleStreetThreeFour					{0};
	long long int m_BetAmountDoubleStreetFourFive					{0};
	long long int m_BetAmountDoubleStreetFiveSix					{0};
	long long int m_BetAmountDoubleStreetSixSeven					{0};
	long long int m_BetAmountDoubleStreetSevenEight					{0};
	long long int m_BetAmountDoubleStreetEightNine					{0};
	long long int m_BetAmountDoubleStreetNineTen					{0};
	long long int m_BetAmountDoubleStreetTenEleven					{0};
	long long int m_BetAmountDoubleStreetElevenTwelve				{0};

	//Square Bet Amount
	long long int m_BetAmountSquareOne			{0};
	long long int m_BetAmountSquareTwo			{0}; 
	long long int m_BetAmountSquareThree		{0}; 
	long long int m_BetAmountSquareFour			{0}; 
	long long int m_BetAmountSquareFive			{0}; 
	long long int m_BetAmountSquareSix			{0}; 
	long long int m_BetAmountSquareSeven		{0}; 
	long long int m_BetAmountSquareEight		{0}; 
	long long int m_BetAmountSquareNine			{0}; 
	long long int m_BetAmountSquareTen			{0}; 
	long long int m_BetAmountSquareEleven		{0}; 
	long long int m_BetAmountSquareTwelve		{0}; 
	long long int m_BetAmountSquareThirteen		{0}; 
	long long int m_BetAmountSquareFourteen		{0}; 
	long long int m_BetAmountSquareFifteen		{0}; 
	long long int m_BetAmountSquareSixteen		{0};
	long long int m_BetAmountSquareSeventeen	{0}; 
	long long int m_BetAmountSquareEighteen		{0}; 
	long long int m_BetAmountSquareNineteen		{0}; 
	long long int m_BetAmountSquareTwenty		{0}; 
	long long int m_BetAmountSquareTwentyOne	{0}; 
	long long int m_BetAmountSquareTwentyTwo	{0}; 

	//SplitVertical BetAmount
	long long int m_BetAmountVerticalSplitOne			{0};
	long long int m_BetAmountVerticalSplitTwo			{0};
	long long int m_BetAmountVerticalSplitThree			{0};
	long long int m_BetAmountVerticalSplitFour			{0};
	long long int m_BetAmountVerticalSplitFive			{0};
	long long int m_BetAmountVerticalSplitSix			{0};
	long long int m_BetAmountVerticalSplitSeven			{0}; 
	long long int m_BetAmountVerticalSplitEight			{0};
	long long int m_BetAmountVerticalSplitNine			{0};
	long long int m_BetAmountVerticalSplitTen			{0};
	long long int m_BetAmountVerticalSplitEleven		{0};
	long long int m_BetAmountVerticalSplitTwelve		{0};
	long long int m_BetAmountVerticalSplitThirteen		{0};
	long long int m_BetAmountVerticalSplitFourteen		{0};
	long long int m_BetAmountVerticalSplitFifteen		{0};
	long long int m_BetAmountVerticalSplitSixteen		{0};
	long long int m_BetAmountVerticalSplitSeventeen		{0};
	long long int m_BetAmountVerticalSplitEighteen		{0};
	long long int m_BetAmountVerticalSplitNineteen		{0};
	long long int m_BetAmountVerticalSplitTwenty		{0};
	long long int m_BetAmountVerticalSplitTwentyone		{0};
	long long int m_BetAmountVerticalSplitTwentytwo		{0};
	long long int m_BetAmountVerticalSplitTwentythree	{0}; 
	long long int m_BetAmountVerticalSplitTwentyfour	{0};

	//SplitHorizontal BetAmount
	long long int m_BetAmountHorizontalSplitOne			{0};
	long long int m_BetAmountHorizontalSplitTwo			{0};
	long long int m_BetAmountHorizontalSplitThree		{0}; 
	long long int m_BetAmountHorizontalSplitFour		{0}; 
	long long int m_BetAmountHorizontalSplitFive		{0}; 
	long long int m_BetAmountHorizontalSplitSix			{0};
	long long int m_BetAmountHorizontalSplitSeven		{0}; 
	long long int m_BetAmountHorizontalSplitEight		{0}; 
	long long int m_BetAmountHorizontalSplitNine		{0}; 
	long long int m_BetAmountHorizontalSplitTen			{0}; 
	long long int m_BetAmountHorizontalSplitEleven		{0}; 
	long long int m_BetAmountHorizontalSplitTwelve		{0}; 
	long long int m_BetAmountHorizontalSplitThirteen	{0}; 
	long long int m_BetAmountHorizontalSplitFourteen	{0}; 
	long long int m_BetAmountHorizontalSplitFifteen		{0}; 
	long long int m_BetAmountHorizontalSplitSixteen		{0};
	long long int m_BetAmountHorizontalSplitSeventeen	{0}; 
	long long int m_BetAmountHorizontalSplitEighteen	{0};
	long long int m_BetAmountHorizontalSplitNineteen	{0}; 
	long long int m_BetAmountHorizontalSplitTwenty		{0}; 
	long long int m_BetAmountHorizontalSplitTwentyOne	{0}; 
	long long int m_BetAmountHorizontalSplitTwentyTwo	{0};
	long long int m_BetAmountHorizontalSplitTwentyThree {0};
	long long int m_BetAmountHorizontalSplitTwentyFour	{0}; 
	long long int m_BetAmountHorizontalSplitTwentyFive	{0}; 
	long long int m_BetAmountHorizontalSplitTwentySix	{0}; 
	long long int m_BetAmountHorizontalSplitTwentySeven {0}; 
	long long int m_BetAmountHorizontalSplitTwentyEight {0}; 
	long long int m_BetAmountHorizontalSplitTwentyNine	{0}; 
	long long int m_BetAmountHorizontalSplitThirty		{0}; 
	long long int m_BetAmountHorizontalSplitThirtyOne	{0};
	long long int m_BetAmountHorizontalSplitThirtyTwo	{0};
	long long int m_BetAmountHorizontalSplitThirtyThree {0}; 

	//Single Value Bets Arrays
	const int m_NumberZero[1]			= {0};
	const int m_NumberOne[1]			= {1};
	const int m_NumberTwo[1]			= {2};
	const int m_NumberThree[1]			= {3};
	const int m_NumberFour[1]			= {4};
	const int m_NumberFive[1]			= {5};
	const int m_NumberSix[1]			= {6};
	const int m_NumberSeven[1]			= {7};
	const int m_NumberEight[1]			= {8};
	const int m_NumberNine[1]			= {9};
	const int m_NumberTen[1]			= {10};
	const int m_NumberEleven[1]			= {11};
	const int m_NumberTwelve[1]			= {12};
	const int m_NumberThirteen[1]		= {13};
	const int m_NumberFourteen[1]		= {14};
	const int m_NumberFifteen[1]		= {15};
	const int m_NumberSixteen[1]		= {16};
	const int m_NumberSeventeen[1]		= {17};
	const int m_NumberEighteen[1]		= {18};
	const int m_NumberNineteen[1]		= {19};
	const int m_NumberTwenty[1]			= {20};
	const int m_NumberTwentyOne[1]		= {21};
	const int m_NumberTwentyTwo[1]		= {22};
	const int m_NumberTwentyThree[1]	= {23};
	const int m_NumberTwentyFour[1]		= {24};
	const int m_NumberTwentyFive[1]		= {25};
	const int m_NumberTwentySix[1]		= {26};
	const int m_NumberTwentySeven[1]	= {27};
	const int m_NumberTwentyEight[1]	= {28};
	const int m_NumberTwentyNine[1]		= {29};
	const int m_NumberThirty[1]			= {30};
	const int m_NumberThirtyOne[1]		= {31};
	const int m_NumberThirtyTwo[1]		= {32};
	const int m_NumberThirtyThree[1]	= {33};
	const int m_NumberThirtyFour[1]		= {34};
	const int m_NumberThirtyFive[1]		= {35};
	const int m_NumberThirtySix[1]		= {36};

	//Black Red && Even Odd arrays
	const int m_BLACKODDS[18]				= {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35};		 // Also Odd numbers
	const int m_REDEVEN[18]					= {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};	 // Also Even numbers

	//1 - 18 || 19 - 36 arrays
	const int m_OneToEighteen[18]			= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};		     // 1 to 1 payout
	const int m_NineteenToThirtySix[18]		= {19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; // 1 to 1 payout

	//1st12 || 2nd12 || 3rd12 arrays
	const int m_FirstTwelve[12]				= {1,2,3,4,5,6,7,8,9,10,11,12};								 // 2 to 1 payout
	const int m_SecondTwelve[12]			= {13,14,15,16,17,18,19,20,21,22,23,24};					 // 2 to 1 payout
	const int m_ThirdTwelve[12]				= {25,26,27,28,29,30,31,32,33,34,35,36};					 // 2 to 1 payout

	//FirstColumn || SecondColumn || ThirdColumn arrays
	const int m_FirstColumn[12]				= {1,4,7,10,13,16,19,22,25,28,31,34};						 // 2 to 1 payout
	const int m_SecondColumn[12]			= {2,5,8,11,14,17,20,23,26,29,32,35};						 // 2 to 1 payout
	const int m_ThirdColumn[12]				= {3,6,9,12,15,18,21,24,27,30,33,36};						 // 2 to 1 payout

	//Single StreetBets arrays
	const int m_StreetOne[3]				= {1,2,3};			//11 to 1 payout
	const int m_StreetTwo[3]				= {4,5,6};			//11 to 1 payout
	const int m_StreetThree[3]				= {7,8,9};			//11 to 1 payout

	const int m_StreetFour[3]				= {10,11,12};		//11 to 1 payout
	const int m_StreetFive[3]				= {13,14,15};		//11 to 1 payout
	const int m_StreetSix[3]				= {16,17,18};		//11 to 1 payout

	const int m_StreetSeven[3]				= {19,20,21};		//11 to 1 payout
	const int m_StreetEight[3]				= {22,23,24};		//11 to 1 payout
	const int m_StreetNine[3]				= {25,26,27};		//11 to 1 payout

	const int m_StreetTen[3]				= {28,29,30};		//11 to 1 payout
	const int m_StreetEleven[3]				= {31,32,33};		//11 to 1 payout
	const int m_StreetTwelve[3]				= {34,35,36};		//11 to 1 payout


	//European Version so these are considered StreetBet arrays
	const int m_StreetZeroOneTwo[4]			= {0,1,2};				// 11 to 1 payout
	const int m_StreetZeroTwoThree[4]		= {0,2,3};				// 11 to 1 payout

	//Double Street Bets arrays
	const int m_DoubleStreetZeroOneTwoThree[4]	= {0,1,2,3};			// 5 to 1 payout
	const int m_DoubleStreetOneTwo[6]			= {1,2,3,4,5,6};		// 5 to 1 payout
	const int m_DoubleStreetTwoThree[6]			= {4,5,6,7,8,9};		// 5 to 1 payout
	const int m_DoubleStreetThreeFour[6]		= {7,8,9,10,11,12};		// 5 to 1 payout
	const int m_DoubleStreetFourFive[6]			= {10,11,12,13,14,15};	// 5 to 1 payout
	const int m_DoubleStreetFiveSix[6]			= {13,14,15,16,17,18};	// 5 to 1 payout
	const int m_DoubleStreetSixSeven[6]			= {16,17,18,19,20,21};	// 5 to 1 payout
	const int m_DoubleStreetSevenEight[6]		= {19,20,21,22,23,24};	// 5 to 1 payout
	const int m_DoubleStreetEightNine[6]		= {22,23,24,25,26,27};	// 5 to 1 payout
	const int m_DoubleStreetNineTen[6]			= {25,26,27,28,29,30};	// 5 to 1 payout
	const int m_DoubleStreetTenEleven[6]		= {28,29,30,31,32,33};	// 5 to 1 payout
	const int m_DoubleStreetElevenTwelve[6]		= {31,32,33,34,35,36};	// 5 to 1 payout

	//Square Bets arrays
	const int m_SquareOne[4]			= {1,2,4,5};		// 8 to 1 payout
	const int m_SquareTwo[4]			= {2,3,5,6};		// 8 to 1 payout
	const int m_SquareThree[4]			= {4,5,7,8};		// 8 to 1 payout
	const int m_SquareFour[4]			= {5,6,8,9};		// 8 to 1 payout
	const int m_SquareFive[4]			= {7,8,10,11};		// 8 to 1 payout
	const int m_SquareSix[4]			= {8,9,11,12};		// 8 to 1 payout
	const int m_SquareSeven[4]			= {10,11,13,14};	// 8 to 1 payout
	const int m_SquareEight[4]			= {11,12,14,15};	// 8 to 1 payout
	const int m_SquareNine[4]			= {13,14,16,17};	// 8 to 1 payout
	const int m_SquareTen[4]			= {14,15,17,18};	// 8 to 1 payout
	const int m_SquareEleven[4]			= {16,17,19,20};	// 8 to 1 payout
	const int m_SquareTwelve[4]			= {17,18,20,21};	// 8 to 1 payout
	const int m_SquareThirteen[4]		= {19,20,22,23};	// 8 to 1 payout
	const int m_SquareFourteen[4]		= {20,21,23,24};	// 8 to 1 payout
	const int m_SquareFifteen[4]		= {22,23,25,26};	// 8 to 1 payout
	const int m_SquareSixteen[4]		= {23,24,26,27};	// 8 to 1 payout
	const int m_SquareSeventeen[4]		= {25,26,28,29};	// 8 to 1 payout
	const int m_SquareEighteen[4]		= {26,27,29,30};	// 8 to 1 payout
	const int m_SquareNineteen[4]		= {28,29,31,32};	// 8 to 1 payout
	const int m_SquareTwenty[4]			= {29,30,32,33};	// 8 to 1 payout
	const int m_SquareTwentyOne[4]		= {31,32,34,35};	// 8 to 1 payout
	const int m_SquareTwentyTwo[4]		= {32,33,35,36};	// 8 to 1 payout
	
	//Split Vertical Bets arrays
	const int m_VerticalSplitOne[2]			= {1,2};	// 17 to 1 payout
	const int m_VerticalSplitTwo[2]			= {2,3};	// 17 to 1 payout
	const int m_VerticalSplitThree[2]		= {4,5};	// 17 to 1 payout
	const int m_VerticalSplitFour[2]		= {5,6};	// 17 to 1 payout
	const int m_VerticalSplitFive[2]		= {7,8};	// 17 to 1 payout
	const int m_VerticalSplitSix[2]			= {8,9};	// 17 to 1 payout
	const int m_VerticalSplitSeven[2]		= {10,11};	// 17 to 1 payout
	const int m_VerticalSplitEight[2]		= {11,12};	// 17 to 1 payout
	const int m_VerticalSplitNine[2]		= {13,14};	// 17 to 1 payout
	const int m_VerticalSplitTen[2]			= {14,15};	// 17 to 1 payout
	const int m_VerticalSplitEleven[2]		= {16,17};	// 17 to 1 payout
	const int m_VerticalSplitTwelve[2]		= {17,18};	// 17 to 1 payout
	const int m_VerticalSplitThirteen[2]	= {19,20};	// 17 to 1 payout
	const int m_VerticalSplitFourteen[2]	= {20,21};	// 17 to 1 payout
	const int m_VerticalSplitFifteen[2]		= {22,23};	// 17 to 1 payout
	const int m_VerticalSplitSixteen[2]		= {23,24};	// 17 to 1 payout
	const int m_VerticalSplitSeventeen[2]	= {25,26};	// 17 to 1 payout
	const int m_VerticalSplitEighteen[2]	= {26,27};	// 17 to 1 payout
	const int m_VerticalSplitNineteen[2]	= {28,29};	// 17 to 1 payout
	const int m_VerticalSplitTwenty[2]		= {29,30};	// 17 to 1 payout
	const int m_VerticalSplitTwentyone[2]	= {31,32};	// 17 to 1 payout
	const int m_VerticalSplitTwentytwo[2]	= {32,33};	// 17 to 1 payout
	const int m_VerticalSplitTwentythree[2] = {34,35};	// 17 to 1 payout
	const int m_VerticalSplitTwentyfour[2]	= {35,36};	// 17 to 1 payout
	
	//Split Horizontal Bets arrays
	const int m_HorizontalSplitOne[2]			= { 1,4 };		// 17 to 1 payout
	const int m_HorizontalSplitTwo[2]			= { 2,5 };		// 17 to 1 payout
	const int m_HorizontalSplitThree[2]			= { 3,6 };		// 17 to 1 payout
	const int m_HorizontalSplitFour[2]			= { 4,7 };		// 17 to 1 payout
	const int m_HorizontalSplitFive[2]			= { 5,8 };		// 17 to 1 payout
	const int m_HorizontalSplitSix[2]			= { 6,9 };		// 17 to 1 payout
	const int m_HorizontalSplitSeven[2]			= { 7,10 };		// 17 to 1 payout
	const int m_HorizontalSplitEight[2]			= { 8,11 };		// 17 to 1 payout
	const int m_HorizontalSplitNine[2]			= { 9,12 };		// 17 to 1 payout
	const int m_HorizontalSplitTen[2]			= { 10,13 };	// 17 to 1 payout
	const int m_HorizontalSplitEleven[2]		= { 11,14 };	// 17 to 1 payout
	const int m_HorizontalSplitTwelve[2]		= { 12,15 };	// 17 to 1 payout
	const int m_HorizontalSplitThirteen[2]		= { 13,16 };	// 17 to 1 payout
	const int m_HorizontalSplitFourteen[2]		= { 14,17 };	// 17 to 1 payout
	const int m_HorizontalSplitFifteen[2]		= { 15,18 };	// 17 to 1 payout
	const int m_HorizontalSplitSixteen[2]		= { 16,19 };	// 17 to 1 payout
	const int m_HorizontalSplitSeventeen[2]		= { 17,20 };	// 17 to 1 payout
	const int m_HorizontalSplitEighteen[2]		= { 18,21 };	// 17 to 1 payout
	const int m_HorizontalSplitNineteen[2]		= { 19,22 };	// 17 to 1 payout
	const int m_HorizontalSplitTwenty[2]		= { 20,23 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyOne[2]		= { 21,24 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyTwo[2]		= { 22,25 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyThree[2]	= { 23,26 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyFour[2]	= { 24,27 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyFive[2]	= { 25,28 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentySix[2]		= { 26,29 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentySeven[2]	= { 27,30 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyEight[2]	= { 28,31 };	// 17 to 1 payout
	const int m_HorizontalSplitTwentyNine[2]	= { 29,32 };	// 17 to 1 payout
	const int m_HorizontalSplitThirty[2]		= { 30,33 };	// 17 to 1 payout
	const int m_HorizontalSplitThirtyOne[2]		= { 31,34 };	// 17 to 1 payout
	const int m_HorizontalSplitThirtyTwo[2]		= { 32,35 };	// 17 to 1 payout
	const int m_HorizontalSplitThirtyThree[2]	= { 33,36 };	// 17 to 1 payout
	

public:
	//Constructor
	RouletteGame(long long int Balance);

	void GenerateRandomNumber();
	
	//Spin
	void StartRound();

	//Global Function for all of the below
	void AddToBet(long long int& betVariable, const int& BetAmountPlus);

	//Calculations for Winnings
	void checkAndProcessBet(long long int betAmount, const int* betNumbers, const int forloopvalue, const int multiplier, const std::string betname);

	//Red and Black
	void AddToBetBlack(const int& BetAmountPlus);
	void AddToBetRed(const int& BetAmountPlus);

	//OneToEighteen and NineteenToThirySix
	void AddToBetOneToEighteen(const int& BetAmountPlus);
	void AddToBetNineteenToThirtySix(const int& BetAmountPlus);

	//1st12 || 2nd12 || 3rd12
	void AddToBetFirstTwelve(const int& BetAmountPlus);
	void AddToBetSecondTwelve(const int& BetAmountPlus);
	void AddToBetThirdTwelve(const int& BetAmountPlus);

	//FirstColumn || SecondColumn || ThirdColumn
	void AddToBetFirstColumn(const int& BetAmountPlus);
	void AddToBetSecondColumn(const int& BetAmountPlus);
	void AddToBetThirdColumn(const int& BetAmountPlus);

	//Number Bets
	void AddToBetNumberZero(const int& BetAmountPlus);
	void AddToBetNumberOne(const int& BetAmountPlus);
	void AddToBetNumberTwo(const int& BetAmountPlus);
	void AddToBetNumberThree(const int& BetAmountPlus);
	void AddToBetNumberFour(const int& BetAmountPlus);
	void AddToBetNumberFive(const int& BetAmountPlus);
	void AddToBetNumberSix(const int& BetAmountPlus);
	void AddToBetNumberSeven(const int& BetAmountPlus);
	void AddToBetNumberEight(const int& BetAmountPlus);
	void AddToBetNumberNine(const int& BetAmountPlus);
	void AddToBetNumberTen(const int& BetAmountPlus);
	void AddToBetNumberEleven(const int& BetAmountPlus);
	void AddToBetNumberTwelve(const int& BetAmountPlus);
	void AddToBetNumberThirteen(const int& BetAmountPlus);
	void AddToBetNumberFourteen(const int& BetAmountPlus);
	void AddToBetNumberFifteen(const int& BetAmountPlus);
	void AddToBetNumberSixteen(const int& BetAmountPlus);
	void AddToBetNumberSeventeen(const int& BetAmountPlus);
	void AddToBetNumberEighteen(const int& BetAmountPlus);
	void AddToBetNumberNineteen(const int& BetAmountPlus);
	void AddToBetNumberTwenty(const int& BetAmountPlus);
	void AddToBetNumberTwentyOne(const int& BetAmountPlus);
	void AddToBetNumberTwentyTwo(const int& BetAmountPlus);
	void AddToBetNumberTwentyThree(const int& BetAmountPlus);
	void AddToBetNumberTwentyFour(const int& BetAmountPlus);
	void AddToBetNumberTwentyFive(const int& BetAmountPlus);
	void AddToBetNumberTwentySix(const int& BetAmountPlus);
	void AddToBetNumberTwentySeven(const int& BetAmountPlus);
	void AddToBetNumberTwentyEight(const int& BetAmountPlus);
	void AddToBetNumberTwentyNine(const int& BetAmountPlus);
	void AddToBetNumberThirty(const int& BetAmountPlus);
	void AddToBetNumberThirtyOne(const int& BetAmountPlus);
	void AddToBetNumberThirtyTwo(const int& BetAmountPlus);
	void AddToBetNumberThirtyThree(const int& BetAmountPlus);
	void AddToBetNumberThirtyFour(const int& BetAmountPlus);
	void AddToBetNumberThirtyFive(const int& BetAmountPlus);
	void AddToBetNumberThirtySix(const int& BetAmountPlus);

	//Single Street Bets
	void AddToBetStreetOne(const int& BetAmountPlus);
	void AddToBetStreetTwo(const int& BetAmountPlus);
	void AddToBetStreetThree(const int& BetAmountPlus);
	void AddToBetStreetFour(const int& BetAmountPlus);
	void AddToBetStreetFive(const int& BetAmountPlus);
	void AddToBetStreetSix(const int& BetAmountPlus);
	void AddToBetStreetSeven(const int& BetAmountPlus);
	void AddToBetStreetEight(const int& BetAmountPlus);
	void AddToBetStreetNine(const int& BetAmountPlus);
	void AddToBetStreetTen(const int& BetAmountPlus);
	void AddToBetStreetEleven(const int& BetAmountPlus);
	void AddToBetStreetTwelve(const int& BetAmountPlus);

	void AddToBetStreetZeroOneTwo(const int& BetAmountPlus);
	void AddToBetStreetZeroTwoThree(const int& BetAmountPlus);
	


	//Double Street Bets 
	void AddToBetDoubleStreetZeroOneTwoThree(const int& BetAmountPlus);
	void AddToBetDoubleStreetOneTwo(const int& BetAmountPlus);
	void AddToBetDoubleStreetTwoThree(const int& BetAmountPlus);
	void AddToBetDoubleStreetThreeFour(const int& BetAmountPlus);
	void AddToBetDoubleStreetFourFive(const int& BetAmountPlus);
	void AddToBetDoubleStreetFiveSix(const int& BetAmountPlus);
	void AddToBetDoubleStreetSixSeven(const int& BetAmountPlus);
	void AddToBetDoubleStreetSevenEight(const int& BetAmountPlus);
	void AddToBetDoubleStreetEightNine(const int& BetAmountPlus);
	void AddToBetDoubleStreetNineTen(const int& BetAmountPlus);
	void AddToBetDoubleStreetTenEleven(const int& BetAmountPlus);
	void AddToBetDoubleStreetElevenTwelve(const int& BetAmountPlus);

	//Sqaure Bets
	void AddToBetSquareOne(const int& BetAmountPlus);
	void AddToBetSquareTwo(const int& BetAmountPlus);
	void AddToBetSquareThree(const int& BetAmountPlus);
	void AddToBetSquareFour(const int& BetAmountPlus);
	void AddToBetSquareFive(const int& BetAmountPlus);
	void AddToBetSquareSix(const int& BetAmountPlus);
	void AddToBetSquareSeven(const int& BetAmountPlus);
	void AddToBetSquareEight(const int& BetAmountPlus);
	void AddToBetSquareNine(const int& BetAmountPlus);
	void AddToBetSquareTen(const int& BetAmountPlus);
	void AddToBetSquareEleven(const int& BetAmountPlus);
	void AddToBetSquareTwelve(const int& BetAmountPlus);
	void AddToBetSquareThirteen(const int& BetAmountPlus);
	void AddToBetSquareFourteen(const int& BetAmountPlus);
	void AddToBetSquareFifteen(const int& BetAmountPlus);
	void AddToBetSquareSixteen(const int& BetAmountPlus);
	void AddToBetSquareSeventeen(const int& BetAmountPlus);
	void AddToBetSquareEighteen(const int& BetAmountPlus);
	void AddToBetSquareNineteen(const int& BetAmountPlus);
	void AddToBetSquareTwenty(const int& BetAmountPlus);
	void AddToBetSquareTwentyOne(const int& BetAmountPlus);
	void AddToBetSquareTwentyTwo(const int& BetAmountPlus);


	//Split Vertical Bets
	void AddToBetVerticalSplitOne(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwo(const int& BetAmountPlus);
	void AddToBetVerticalSplitThree(const int& BetAmountPlus);
	void AddToBetVerticalSplitFour(const int& BetAmountPlus);
	void AddToBetVerticalSplitFive(const int& BetAmountPlus);
	void AddToBetVerticalSplitSix(const int& BetAmountPlus);
	void AddToBetVerticalSplitSeven(const int& BetAmountPlus);
	void AddToBetVerticalSplitEight(const int& BetAmountPlus);
	void AddToBetVerticalSplitNine(const int& BetAmountPlus);
	void AddToBetVerticalSplitTen(const int& BetAmountPlus);
	void AddToBetVerticalSplitEleven(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwelve(const int& BetAmountPlus);
	void AddToBetVerticalSplitThirteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitFourteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitFifteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitSixteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitSeventeen(const int& BetAmountPlus);
	void AddToBetVerticalSplitEighteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitNineteen(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwenty(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwentyone(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwentytwo(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwentythree(const int& BetAmountPlus);
	void AddToBetVerticalSplitTwentyfour(const int& BetAmountPlus);


	//Split Horizontal Bets
	void AddToBetHorizontalSplitOne(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwo(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThree(const int& BetAmountPlus);
	void AddToBetHorizontalSplitFour(const int& BetAmountPlus);
	void AddToBetHorizontalSplitFive(const int& BetAmountPlus);
	void AddToBetHorizontalSplitSix(const int& BetAmountPlus);
	void AddToBetHorizontalSplitSeven(const int& BetAmountPlus);
	void AddToBetHorizontalSplitEight(const int& BetAmountPlus);
	void AddToBetHorizontalSplitNine(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitEleven(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwelve(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThirteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitFourteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitFifteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitSixteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitSeventeen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitEighteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitNineteen(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwenty(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyOne(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyTwo(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyThree(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyFour(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyFive(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentySix(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentySeven(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyEight(const int& BetAmountPlus);
	void AddToBetHorizontalSplitTwentyNine(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThirty(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThirtyOne(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThirtyTwo(const int& BetAmountPlus);
	void AddToBetHorizontalSplitThirtyThree(const int& BetAmountPlus);

	//Grabbing Information
	long long int GetBetAmount();
	long long int GetCurrentBalance();
	std::string GetNumberColor(int& Number);

	//Chat log
	bool GetShowPreviousOne();
	bool GetShowPreviousTwo();
	bool GetShowPreviousThree();
	bool GetShowPreviousFour();

	//Clearing Bets 
	void ClearAllBets(); //Helper Member Function for Clearing All Table Bets
	void ResetAllBetsAfterRound(); //Reset all bet values after the round

	//Grab Pervious Number
	SpinNumbers GetPreviousSpinNumbers();
};