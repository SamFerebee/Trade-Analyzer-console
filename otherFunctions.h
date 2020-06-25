#pragma once
#include "PersonClass.h"

void printListOfPlayerValues(PersonClass &person, float  &lopsidedOffset);
std::vector<playerData> createPlayerBankFromFile();
std::istream& operator>> (std::istream& input, playerData& data);
PersonClass createPersonClass(std::vector<playerData>& allPlayers);
void checkAndReplaceValue(std::vector<playerData>& allPlayers);