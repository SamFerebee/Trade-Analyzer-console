#pragma once
#include "playerlist.h"
#include <array>
#include <cstdlib>
#include <ctime>
#include <random>

class PersonClass
{
private:
	std::string m_name{};
	float m_numOfPlayerTraded{};
	std::vector<std::string> m_vecPlayersTraded{};
	float m_valueOfPlayers{};
	std::string m_outcome{};
	float m_lopsided{};
	float m_tradeValueDifference{};
	std::vector<playerData> m_totalVecOfAllPlayers{};
	std::vector<int> valueOfIndividuals{};
public:
	void getName();
	void getPlayerNames();
	void getAmtTraded();
	void getPlayersValue();
	void evaluateTrade(PersonClass& comparison);
	void evaluateLopsided(PersonClass& comparion);
	std::string returnName();
	std::string returnOutcome();
	float returnValueOfPlayers();
	float returnNumOfPlayersTraded();
	std::vector<std::string> returnVecPlayersTraded();
	float returnLopsided();
	void setPlayersValue(float x);
	void setName(std::string& x);
	int returnTradeValueDifference(PersonClass& comparison);
	void calculateTradeValueDifference(PersonClass& comparison);
	void checkForAndAddPlayer(std::vector<playerData>& vector);
	std::vector<playerData> returnTotalVecOfPlayers();
	std::vector<int> returnValueOfIndividualPlayers();
};




