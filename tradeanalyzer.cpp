#include <Windows.h>
#include <algorithm>
#include "PersonClass.h"
#include "otherFunctions.h"
#include "lopsidedalgorithm.h"
#include <fstream>

//complete lopsided algorithm
//add all other relevant player values
//pass things by reference and const where appropriate
//clean up code: rename functions, variables, add comments


void otherStuff(PersonClass &person, PersonClass &otherPerson)
{
	person.evaluateLopsided(otherPerson);

	//joke lines for dramatic effect
	std::cout << "Getting grapes ready"; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << ". "; Sleep(200);
	Sleep(350);
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::array<std::string, 2> jokeLines1{ "Analyzing trade", "Evaluating trade" };
	std::array<std::string, 3> jokeLines2{ "Hacking Schefter's email", "Checking RotoWorld trade values", "Analyzing Twitter Trends" };
	std::uniform_int_distribution<> selectJokeLines{ 0, 1 };
	auto getJokeLine{ selectJokeLines(mt) };
	std::uniform_int_distribution<> selectJokeLines2{ 0, 2 };
	auto getJokeLine2{ selectJokeLines2(mt) };
	std::cout << jokeLines1[getJokeLine]; Sleep(500); std::cout << "."; Sleep(300); std::cout << "."; Sleep(300); std::cout << "."; Sleep(500); std::cout << '\n';
	std::cout << jokeLines2[getJokeLine2]; Sleep(500); std::cout << "."; Sleep(300); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; Sleep(200); std::cout << "."; std::cout << '\n';
	
	//determine if trade is lopsided and if so, apply algorithm
	float lopsidedOffset{ 1 };
	float lopsidedOffset2{ 1 };
	if (person.returnLopsided() != 0)
	{
		std::cout << "*****" << " Meebz' Trade Analyzer has detected that this trade involves an uneven number of players on each side.\n" << "Applying algorithm"; Sleep(250);
		std::cout << "."; Sleep(500); std::cout << "."; Sleep(300); std::cout << "."; Sleep(200); std::cout << '\n';
		//applyLopsidedAlgorithm(person, otherPerson, lopsidedOffset, lopsidedOffset2); //sending lopsidedOffsets to lopsidedFunction as references to use as out parameters
		LopsidedAlgorithm algo{};
		algo.getAndSetLopsidedValue(person);
		algo.getAndSettempvec(person);
		algo.getAndSettempvec2(otherPerson);
		algo.getAndSetHighest(person);
		algo.getAndSetHighest2(otherPerson);
		algo.getAndSetSecondHighest(person);
		algo.getAndSetSecondHighest2(otherPerson);
		algo.getAndSetLowest(person);
		algo.getAndSetLowest2(otherPerson);
		algo.applyLopsidedAlgorithm(person, otherPerson, lopsidedOffset, lopsidedOffset2);
	}

	person.calculateTradeValueDifference(otherPerson);
	person.evaluateTrade(otherPerson); 
	Sleep(250);

	//print out results, separated into 2 if statements based on whether person or otherPerson pervailed in the trade, prevailer always printed first
	if (person.returnTradeValueDifference(otherPerson) <= 0)
	{
		std::cout << "**RESULT**\n" << person.returnName() << ' ' << person.returnOutcome() << ' ' << otherPerson.returnName() << '\n';
		std::cout << person.returnName() << " traded away a total value of ";
		std::cout << person.returnValueOfPlayers() << " and " << otherPerson.returnName() << " traded away a total value of " << otherPerson.returnValueOfPlayers() << '\n';
		Sleep(500);
	}
	else if (person.returnTradeValueDifference(otherPerson) > 0)
	{
		std::cout << "**RESULT**\n" << otherPerson.returnName() << ' ' << person.returnOutcome() << ' ' << person.returnName() << '\n';
		std::cout << otherPerson.returnName() << " traded away a total value of ";
		std::cout << otherPerson.returnValueOfPlayers() << " and " << person.returnName() << " traded away a total value of " << person.returnValueOfPlayers() << '\n';
		Sleep(500);
	}
	std::cout << '\n';

	std::cout << person.returnName() << "'s players had the following values: \n";
	printListOfPlayerValues(person, lopsidedOffset);
	std::cout << '\n';
	std::cout << otherPerson.returnName() << "'s players had the following values: \n";
	printListOfPlayerValues(otherPerson, lopsidedOffset2);
}

int main()
{
	//if a custom playerbank has been created, use that, otherwise use generic playerbank
	std::fstream fileStream;
	fileStream.open("playerbank.txt");
	std::vector<playerData> allPlayers{};
	if (fileStream)
		allPlayers = createPlayerBankFromFile();
	else
		allPlayers = populateList();

	std::cout << "Welcome to Meebz' Trade Analyzer. ";
	//loop for application 
	while (true)
	{
		std::cout << "Enter one of the following commands: view bank, change player value, analyze trade, or exit. If you'd like to save changes you've made to the player bank for future use, use exit: ";
		std::string startAnswer{};
		std::getline(std::cin, startAnswer);
		//loop to validate input
		while (startAnswer != "view bank" && startAnswer != "change player value" && startAnswer != "analyze trade" && startAnswer != "exit")
		{
			std::cout << "You must enter view bank, change player value, analyze trade, or exit. Case sensitive: ";
			std::getline(std::cin, startAnswer);
		}
		if (startAnswer == "view bank")
		{
			for (int i = 0; i < allPlayers.size(); ++i)
			{
				std::cout << allPlayers[i].playerName << " (" << allPlayers[i].playerPosition << ", " << allPlayers[i].playersTeam << ") "<<  "has a value of " << allPlayers[i].playerValue << '\n';
			}
			std::cout << '\n';
		}
		if (startAnswer == "change player value")
		{
			checkAndReplaceValue(allPlayers);
		}
		if (startAnswer == "analyze trade")
		{
			//create 2 PersonClass objects and get the required information to evaluate the trade
			std::cout << "Enter the first trade partner's name: ";
			PersonClass person{ createPersonClass(allPlayers) };
			std::cout << "Enter " << person.returnName() << "'s trade partner: ";
			PersonClass otherPerson{ createPersonClass(allPlayers) };
			//////trade happens out of otherStuff
			otherStuff(person, otherPerson);
			std::cout << '\n';
		}
		if (startAnswer == "exit")
		{
			std::cout << "Exiting Trade Analzyer...\n";
			std::ofstream myfile;
			myfile.open("playerbank.txt");
			for (int k = 0; k < allPlayers.size(); ++k)
			{
				myfile << allPlayers[k].playerName << ' ' << allPlayers[k].playerPosition << ' ' << allPlayers[k].playersTeam << ' ' << allPlayers[k].playerValue << '\n';
			}
			myfile.close();
			return 0;
		}
	}
	return 0;
}