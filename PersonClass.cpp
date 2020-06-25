#include "PersonClass.h"


//vector is out parameter to modify vector that is in main
void PersonClass::checkForAndAddPlayer(std::vector<playerData>& vector)
{
	std::vector<playerData> vecOfTotalPlayers{ vector };
	std::string name{};
	std::vector<std::string> tempVec{ returnVecPlayersTraded() };
	for (int i{ 0 }; i < returnNumOfPlayersTraded(); ++i)
	{
		float x{ 0 };
		auto found{ std::find_if(
			vecOfTotalPlayers.begin(), vecOfTotalPlayers.end(),
			[i, vecOfTotalPlayers, tempVec](playerData& vecOfTotalPlayers) { return vecOfTotalPlayers.playerName == tempVec[i]; }) };
			if (found == vecOfTotalPlayers.end())//if player user entered is not in the playerBank
			{
				bool status{ true };
				while (status) //loop to ensure input is yes or no only
				{
					std::cout << tempVec[i] << " does not have a value in the database, would you like to add one? ";
					std::string answer{};
					std::getline(std::cin, answer);
					if (answer == "yes" || answer == "Yes")
					{
						int size = vecOfTotalPlayers.size();
						vecOfTotalPlayers.push_back(playerData());
						std::string getName{tempVec[i]};
						int getValue{};
						std::string teamName{};
						std::string position{};
						bool internalLoop{ true };
						while (internalLoop) //loop to ensure value input is between 1 and 120 only
						{
							std::cout << "Enter a value for " << tempVec[i] << ':';
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
					}
					else if (answer == "no" || answer == "No")
					{
						std::cout << "Okay, back to analyzing trade. \n";
						std::cin.ignore(32767, '\n');
						status = false;
					}
					else
						status = true;
				}
			} }
	m_totalVecOfAllPlayers = vecOfTotalPlayers;
	vector = vecOfTotalPlayers;
	}

void PersonClass::setPlayersValue(float x)
{
	m_valueOfPlayers = (m_valueOfPlayers * x);
}

void PersonClass::getName()
{

	std::cout << "Enter trade partner's name: ";
	std::string name{};
	std::getline(std::cin, name);
	m_name = name;
}

void PersonClass::getPlayerNames()
{
	std::vector<std::string> playersTraded{};
	std::string number{ "first" };
	std::string input{};
	for (int i{ 1 }; i <= m_numOfPlayerTraded; ++i)
	{
		switch (i)
		{
		case (2):
			number = "second";
			break;
		case (3):
			number = "third";
			break;
		case (4):
			number = "fourth";
			break;
		case(5):
			number = "fifth";
			break;
		default:
			break;
		}
		if (m_numOfPlayerTraded == 1)
		{
			std::cout << "Enter the player " << m_name << " traded: ";
			std::getline(std::cin, input);
			playersTraded.push_back(input);
		}
		else
		{
			std::cout << "Enter the " << number << " player " << m_name << " traded: ";
			std::getline(std::cin, input);
			playersTraded.push_back(input);
		}
	}
	m_vecPlayersTraded = playersTraded;
}

void PersonClass::getAmtTraded()
{
	std::cout << "How many players did " << m_name << " trade?: ";
	int x{};
	std::cin >> x;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	while (x < 1 || x > 3)
	{
		std::cout << "Meebz' Trade Analyzer can currently only analyze up to 3 players traded per team.\n" << "How many players did " << m_name << " trade?: ";
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}
	std::cin.ignore(32767, '\n');
	m_numOfPlayerTraded = x;
}

void PersonClass::getPlayersValue()
{
	std::vector<playerData> vecOfTotalPlayers{ m_totalVecOfAllPlayers };
	float x{ 0 };
	std::vector<std::string> tempVec{ m_vecPlayersTraded };
	for (int i{ 0 }; i < m_numOfPlayerTraded; ++i)
	{
		auto found = std::find_if(
			vecOfTotalPlayers.begin(), vecOfTotalPlayers.end(),
			[i, vecOfTotalPlayers, tempVec](playerData& vecOfTotalPlayers) { return vecOfTotalPlayers.playerName == tempVec[i]; });
		if (found != vecOfTotalPlayers.end())
		x += ((*found).playerValue);

	}
	m_valueOfPlayers = x;
}

void PersonClass::evaluateTrade(PersonClass& comparison)
{
	//make m_tradeValueDifference a percentage of the greater team value
	float tradeValueDifferencePercent{};
	if (m_valueOfPlayers > comparison.m_valueOfPlayers)
		tradeValueDifferencePercent = m_tradeValueDifference / m_valueOfPlayers;
	else if (m_valueOfPlayers < comparison.m_valueOfPlayers)
		tradeValueDifferencePercent = comparison.m_tradeValueDifference / comparison.m_valueOfPlayers;

	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::string outcome{};
	if (m_tradeValueDifference == 0)
	{
		std::array <std::string, 2> evenTradeOutcomes{ "made an even trade with", "made a fair trade with" };
		std::uniform_int_distribution<> d_EvenTradeOutcomes{ 0, 1 };
		auto x{ d_EvenTradeOutcomes(mt) };
		outcome = evenTradeOutcomes[x];
		m_outcome = outcome;
		return;
	}
	if (tradeValueDifferencePercent > .24)
	{
		std::array<std::string, 7> gotGrapedOutcomes{ "absolutely GRAPED", "BADLY ripped off", "trade raped", "stole in broad daylight from", "completely embarassed", "received a generous donation from", "fully meeked" };
		std::uniform_int_distribution<> d_GrapedOutcomes{ 0, 6 };
		auto x{ d_GrapedOutcomes(mt) };
		outcome = gotGrapedOutcomes[x];
		m_outcome = outcome;
		return;
	}
	if (tradeValueDifferencePercent < .25 && tradeValueDifferencePercent > .14)
	{
		std::array<std::string, 3>goodWinOutcomes{ "strongly outnegotiated", "meeked", "ripped off" };
		std::uniform_int_distribution d_goodWinOutcomes{ 0, 2 };
		auto x{ d_goodWinOutcomes(mt) };
		m_outcome = goodWinOutcomes[x];
	}
	if (tradeValueDifferencePercent < .15 && tradeValueDifferencePercent > .06)
	{
		std::array<std::string, 3> normalTradeOutcomes{ "got the better of", "took advantage of", "won this trade with" };
		std::uniform_int_distribution<> d_NormalTradeOutcomes{ 0, 2 };
		auto x{ d_NormalTradeOutcomes(mt) };
		outcome = normalTradeOutcomes[x];
		m_outcome = outcome;
		return;
	}
	if (tradeValueDifferencePercent < .07 && tradeValueDifferencePercent > 0)
	{
		std::array<std::string, 3> closeTradeOutcomes{ "gets the edge, but he made a close deal with", "wins marginally in this trade with", "got a little more value than" };
		std::uniform_int_distribution<> d_CloseTradeOutcomes{ 0, 2 };
		auto x{ d_CloseTradeOutcomes(mt) };
		outcome = closeTradeOutcomes[x];
		m_outcome = outcome;
		return;
	}
}

void PersonClass::evaluateLopsided(PersonClass &comparison)
{
	float difference{};
	difference = m_numOfPlayerTraded - comparison.m_numOfPlayerTraded;
	m_lopsided = difference;
}

void PersonClass::setName(std::string& x)
{
	(this->m_name) = x;
}

void PersonClass::calculateTradeValueDifference(PersonClass& comparison)
{
	float x{ m_valueOfPlayers - comparison.m_valueOfPlayers };
	(this->m_tradeValueDifference) = x;
}

//////// return functions
std::string PersonClass::returnName()
{
	return this->m_name;
}

std::string PersonClass::returnOutcome()
{
	return this->m_outcome;
}

float PersonClass::returnValueOfPlayers()
{
	return this->m_valueOfPlayers;
}

float PersonClass::returnNumOfPlayersTraded()
{
	return this->m_numOfPlayerTraded;
}

std::vector<std::string> PersonClass::returnVecPlayersTraded()
{
	return this->m_vecPlayersTraded;
}

float PersonClass::returnLopsided()
{
	return this->m_lopsided;
}


int PersonClass::returnTradeValueDifference(PersonClass &comparison)
{
	return this->m_tradeValueDifference;
}

std::vector<playerData> PersonClass::returnTotalVecOfPlayers()
{
	return m_totalVecOfAllPlayers;
}

std::vector<int> PersonClass::returnValueOfIndividualPlayers()
{
	std::vector<playerData> vecOfTotalPlayers{ returnTotalVecOfPlayers() };
	std::vector<std::string> tempVec{ returnVecPlayersTraded() };
	std::vector<int> valuesVec{};
	for (int i{ 0 }; i < returnNumOfPlayersTraded(); ++i)
	{
		int x{ 0 };
		auto found{ std::find_if(
			vecOfTotalPlayers.begin(), vecOfTotalPlayers.end(),
			[i, vecOfTotalPlayers, tempVec](playerData& vecOfTotalPlayers) { return vecOfTotalPlayers.playerName == tempVec[i]; }) };
		if (found != vecOfTotalPlayers.end())
		{
			x += ((*found).playerValue);
			valuesVec.push_back(x);
		}
	}
	return valuesVec;
}