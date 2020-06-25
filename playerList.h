#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>

struct playerData
{
	std::string playerName;
	int playerValue;
	std::string playerPosition;
	std::string playersTeam;
	friend std::istream& operator>> (std::istream& input, playerData& data);
};

std::vector<playerData> populateList();
std::vector<playerData> createPlayerBankFromFile();

