#pragma once
#include "playerList.h"

std::istream& operator>> (std::istream& input, playerData& data)
{
	std::string first;
	std::string last;
	std::string team;
	std::string position;
	input >> first >> last;
	input >> data.playerPosition;
	input >> data.playersTeam;
	data.playerName = first + ' ' + last;;
	input >> data.playerValue;
	return input;
}

std::vector<playerData> createPlayerBankFromFile()
{
	std::vector<playerData> playerBank{};
	playerData playerStruct;
	std::ifstream inFile;
	inFile.open("playerbank.txt");
	while (inFile >> playerStruct)
	{
		playerBank.push_back(playerStruct);
	}
	inFile.close();
	return playerBank;
}

std::vector<playerData> populateList()
{
	int i{ 0 };
	std::vector<playerData> totalPlayerVector;

	///////////////QBs
	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Lamar Jackson";
	totalPlayerVector[i].playerPosition = "QB";
	totalPlayerVector[i].playersTeam = "BAL";
	totalPlayerVector[i].playerValue = 69;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Patrick Mahomes";
	totalPlayerVector[i].playerPosition = "QB";
	totalPlayerVector[i].playersTeam = "KC";
	totalPlayerVector[i].playerValue = 67;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Russell Wilson";
	totalPlayerVector[i].playerPosition = "QB";
	totalPlayerVector[i].playersTeam = "SEA";
	totalPlayerVector[i].playerValue = 53;
	++i;

	///////////////RBs
	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Christian McCaffrey";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "CAR";
	totalPlayerVector[i].playerValue = 74;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Saquon Barkley";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "NYG";
	totalPlayerVector[i].playerValue = 63;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Derrick Henry";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "TEN";
	totalPlayerVector[i].playerValue = 60;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Ezekiel Elliot";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "DAL";
	totalPlayerVector[i].playerValue = 62;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Alvin Kamara";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "NO";
	totalPlayerVector[i].playerValue = 56;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Dalvin Cook";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "MIN";
	totalPlayerVector[i].playerValue = 63;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Joe Mixon";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "CIN";
	totalPlayerVector[i].playerValue = 47;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Nick Chubb";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "CLE";
	totalPlayerVector[i].playerValue = 49;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Aaron Jones";
	totalPlayerVector[i].playerPosition = "RB";
	totalPlayerVector[i].playersTeam = "GB";
	totalPlayerVector[i].playerValue = 45;
	++i;

	///////////////WRs

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Michael Thomas";
	totalPlayerVector[i].playerPosition = "WR";
	totalPlayerVector[i].playersTeam = "NO";
	totalPlayerVector[i].playerValue = 53;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Tyreek Hill";
	totalPlayerVector[i].playerPosition = "WR";
	totalPlayerVector[i].playersTeam = "KC";
	totalPlayerVector[i].playerValue = 53;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Davante Adams";
	totalPlayerVector[i].playerPosition = "WR";
	totalPlayerVector[i].playersTeam = "GB";
	totalPlayerVector[i].playerValue = 52;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Julio Jones";
	totalPlayerVector[i].playerPosition = "WR";
	totalPlayerVector[i].playersTeam = "ATL";
	totalPlayerVector[i].playerValue = 51;
	++i;

	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Deandre Hopkins";
	totalPlayerVector[i].playerPosition = "WR";
	totalPlayerVector[i].playersTeam = "HOU";
	totalPlayerVector[i].playerValue = 51;
	++i;

	////////TEs
	totalPlayerVector.push_back(playerData());
	totalPlayerVector[i].playerName = "Travis Kelce";
	totalPlayerVector[i].playerPosition = "TE";
	totalPlayerVector[i].playersTeam = "KC";
	totalPlayerVector[i].playerValue = 46;
	++i;

	return totalPlayerVector;
}