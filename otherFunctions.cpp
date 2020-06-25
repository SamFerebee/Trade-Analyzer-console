#include "otherFunctions.h"


void printListOfPlayerValues(PersonClass &person, float &lopsidedOffset)
{
	std::vector<playerData> vecOfTotalPlayers{ person.returnTotalVecOfPlayers() };
	std::string name{};
	std::vector<std::string> tempVec{ person.returnVecPlayersTraded() };
	for (int i{ 0 }; i < person.returnNumOfPlayersTraded(); ++i)
	{
		float x{ 0 };
		auto found{ std::find_if(
			vecOfTotalPlayers.begin(), vecOfTotalPlayers.end(),
			[i, vecOfTotalPlayers, tempVec](playerData& vecOfTotalPlayers) { return vecOfTotalPlayers.playerName == tempVec[i]; }) };
			if (found != vecOfTotalPlayers.end())
			{
				x += ((*found).playerValue);
				name = ((*found).playerName);
				std::cout << name << " had a value of " << x * lopsidedOffset << '\n';
			} }
}

PersonClass createPersonClass(std::vector<playerData>& allPlayers)
{
	PersonClass Person;
	std::string firstName{};
	std::getline(std::cin, firstName);
	Person.setName(firstName);
	Person.getAmtTraded();
	Person.getPlayerNames();
	Person.checkForAndAddPlayer(allPlayers);
	Person.getPlayersValue();
	
	return Person;
}

void checkAndReplaceValue(std::vector<playerData>& allPlayers)
{
	std::vector<playerData> &vecOfTotalPlayers{ allPlayers };
	float x{ 0 };
	std::string tempString;
	std::cout << "What player would you like to search for? ";
	std::getline(std::cin, tempString);
	for (int i{ 0 }; i < allPlayers.size(); ++i)
	{
		auto found = std::find_if(
			vecOfTotalPlayers.begin(), vecOfTotalPlayers.end(),
			[i, vecOfTotalPlayers, tempString](playerData& vecOfTotalPlayers) { return vecOfTotalPlayers.playerName == tempString; });
		if (found != vecOfTotalPlayers.end())
		{
			std::cout << ((*found).playerName) << " current value is: " << ((*found).playerValue) << '\n';
			while (x < 1 || x > 150)
			{
				std::cout << "Enter a new value for " << ((*found).playerName) << ": ";
				std::cin >> x;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "You must enter a number between 1-150 \n";
				}
				if (x < 1 || x > 150)
					std::cout << "You must enter a number between 1-150 \n";
			}
			((*found).playerValue) = x;
			std::cout << (*found).playerName << " value is now set to " << x << '\n';
			return;
		}
		if (found == vecOfTotalPlayers.end())
		{
			std::cout << "The player bank does not have a value for " << tempString << ". Would you like to add one? ";
			std::string answer{};
			std::getline(std::cin, answer);
			while (answer != "yes" && answer != "no")
			{
				std::cout << "You must enter yes or no, case sensitive: ";
				std::getline(std::cin, answer);
			}
			if (answer == "yes")
			{
				bool status{ true };
				int size = vecOfTotalPlayers.size();
				vecOfTotalPlayers.push_back(playerData());
				std::string getName{ tempString };
				int getValue{};
				std::string teamName{};
				std::string position{};
				bool internalLoop{ true };
				while (internalLoop) //loop to ensure value input is between 1 and 120 only
				{
					std::cout << "Enter a value for " << tempString << ": ";
					std::cin >> getValue;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
					}
					else
						std::cin.ignore(32767, '\n');
					if (getValue > 0 && getValue < 120)
						internalLoop = false;
				}
				bool positionLoop{ true };
				while (positionLoop)
				{
					std::cout << "Enter his position (QB, RB, WR, or TE, case sensitive): ";
					std::getline(std::cin, position);
					if (position == "QB" || position == "RB" || position == "WR" || position == "TE")
						positionLoop = false;
				}
				bool teamLoop{ true };
				std::cout << "Enter his team's abbreviation (ex. NYG or PHI): ";
				while (teamLoop)
				{
					std::getline(std::cin, teamName);
					if (teamName == "NYG" || teamName == "DAL" || teamName == "PHI" || teamName == "WSH" || teamName == "ARI" || teamName == "ATL" || teamName == "BAL" || teamName == "BUF" || teamName == "CAR" || teamName == "CHI" || teamName == "CIN" || teamName == "CLE" || teamName == "DEN" || teamName == "DET" || teamName == "GB" || teamName == "HOU" || teamName == "IND" || teamName == "JAX" || teamName == "KC" || teamName == "MIA" || teamName == "MIN" || teamName == "NE" || teamName == "NO" || teamName == "NYJ" || teamName == "OAK" || teamName == "PIT" || teamName == "LAC" || teamName == "SEA" || teamName == "LAR" || teamName == "SF" || teamName == "TB" || teamName == "TEN")
						teamLoop = false;
					else
					{
						std::cout << teamName << " is not a valid team abbreviation. Please enter a valid team abbreviation: ";
					}
				}
				vecOfTotalPlayers[size].playerName = getName;
				vecOfTotalPlayers[size].playerValue = getValue;
				vecOfTotalPlayers[size].playerPosition = position;
				vecOfTotalPlayers[size].playersTeam = teamName;
				status = false;
				std::cout << "Returning to main menu \n";
				return;
			}
			else
			{
				std::cout << "Returning to main menu \n";
				return;
			}
		}
	}
}