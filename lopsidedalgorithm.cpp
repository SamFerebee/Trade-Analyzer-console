#include "lopsidedalgorithm.h"

void LopsidedAlgorithm::getAndSetLopsidedValue(PersonClass& person)
{
	lopsidedValue = static_cast<int>(person.returnLopsided());
}
void LopsidedAlgorithm::getAndSettempvec(PersonClass& person)
{
	tempvec =  person.returnValueOfIndividualPlayers();
}
void LopsidedAlgorithm::getAndSettempvec2(PersonClass& person)
{
	tempvec2 = person.returnValueOfIndividualPlayers();
}
void LopsidedAlgorithm::getAndSetHighest(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec[i] > highest1)
			highest1 = tempvec[i];
	}
}
void LopsidedAlgorithm::getAndSetHighest2(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec2[i] > highest2)
			highest2 = tempvec2[i];
	}
}
void LopsidedAlgorithm::getAndSetLowest(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec[i] < lowest1)
			lowest1 = tempvec[i];
	}
}
void LopsidedAlgorithm::getAndSetLowest2(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec2[i] < lowest2)
			lowest2 = tempvec2[i];
	}
}
void LopsidedAlgorithm::getAndSetSecondHighest(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec[i] > secondHighest1 && tempvec[i] < highest1)
			secondHighest1 = tempvec[i];
	}
}
void LopsidedAlgorithm::getAndSetSecondHighest2(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec2[i] > secondHighest2 && tempvec2[i] < highest2)
			secondHighest2 = tempvec2[i];
	}
}

void LopsidedAlgorithm::getAndSetThirdHighest1(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec[i] > thirdHighest1 && tempvec[i] < secondHighest1)
			thirdHighest1 = tempvec[i];
	}
}
void LopsidedAlgorithm::getAndSetThirdHighest2(PersonClass& person)
{
	for (int i = 0; i < static_cast<int>(person.returnNumOfPlayersTraded()); ++i)
	{
		if (tempvec2[i] > thirdHighest2 && tempvec2[i] < secondHighest2)
			thirdHighest2 = tempvec2[i];
	}
}

//////////////////////////lopSidedOffsets are out parameters
void LopsidedAlgorithm::applyLopsidedAlgorithm(PersonClass& person, PersonClass& otherPerson, float& lopsidedOffset, float& lopsidedOffset2)
{
	int highestDifference{ std::abs(highest2 - highest1) };
	switch (lopsidedValue)
	{
	case (1):
		/////////// 2 for 1 trade
		if (otherPerson.returnNumOfPlayersTraded() == 1)
		{
			if (highest1 > highest2)
			{
				return;
			}
			if (highest2 - highest1 > 0 && highest2 - highest1 < 6)
			{
				person.setPlayersValue(.95);
				lopsidedOffset = .95;
				return;
			}
			else if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{
				person.setPlayersValue(.9);
				lopsidedOffset = .9;
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				person.setPlayersValue(.8);
				lopsidedOffset = .8;
				return;
			}
			else if (highest2 - highest1 > 20 && highest2 - highest1 < 28)
			{
				person.setPlayersValue(.65);
				lopsidedOffset = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				person.setPlayersValue(.55);
				lopsidedOffset = .55;
				return;
			}
			else
				break;
		}
		////////////////// 3 for 2
		else if (otherPerson.returnNumOfPlayersTraded() == 2)
		{
			////////////////////////////////if highest1 > highest2/////////////////////////
			if (highest1 > highest2)
			{
				if (highest1 - highest2 < 4)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				else if (highest1 - highest2 < 12)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.92);
						lopsidedOffset = .92;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.84);
						lopsidedOffset = .84;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
				}
				else if (highest1 - highest2 < 24)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
				}
				else if (highest1 - highest2 < 38)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 41)
					{
						person.setPlayersValue(.97);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 40)
					{
						person.setPlayersValue(.93);
						lopsidedOffset = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest1 is less than highest2////////////////
			if (highest2 - highest1 < 6)
			{////////////////////first if secondhighest is 10 greater than secondhighest2/////////////				
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			////////////////////////if highest2 is between 5 and 13 greather than highest1/////////////////
			if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{/////////////////////if secondhighest1 is 16 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 16))
				{
					if (secondHighest1 - secondHighest2 < 20)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 15)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			
			//////////////////////if highest2 is 22 greater
			else if (highest2 - highest1 > 22)
			{
				/////////////////////if secondhighest1 is 25 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 25))
				{
					if (secondHighest1 - secondHighest2 < 35)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 45)
					{
						otherPerson.setPlayersValue(.8);
						lopsidedOffset2 = .8;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 55)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 25)
				{
					person.setPlayersValue(.92);
					lopsidedOffset = .92;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.7);
					lopsidedOffset = .7;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.63);
					lopsidedOffset = .63;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
					return;
				}
				else
				{
					person.setPlayersValue(.5);
					lopsidedOffset = .5;
				}
				return;
			}
		}
		////////////////////////////////// 4 for 3 (fuck)
		else if (otherPerson.returnNumOfPlayersTraded() == 3)
		{
			////////////////////////////////if highest1 > highest2/////////////////////////
			if (highest1 > highest2)
			{
				if (highest1 - highest2 < 4)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				else if (highest1 - highest2 < 12)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.92);
						lopsidedOffset = .92;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.84);
						lopsidedOffset = .84;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
				}
				else if (highest1 - highest2 < 24)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
				}
				else if (highest1 - highest2 < 38)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 41)
					{
						person.setPlayersValue(.97);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 40)
					{
						person.setPlayersValue(.93);
						lopsidedOffset = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest1 is less than highest2////////////////
			if (highest2 - highest1 < 6)
			{////////////////////first if secondhighest is 10 greater than secondhighest2/////////////				
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			////////////////////////if highest2 is between 5 and 13 greather than highest1/////////////////
			if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{/////////////////////if secondhighest1 is 16 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 16))
				{
					if (secondHighest1 - secondHighest2 < 20)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 15)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			//////////////////////if highest2 is 22 greater
			else if (highest2 - highest1 > 22)
			{
				/////////////////////if secondhighest1 is 25 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 25))
				{
					if (secondHighest1 - secondHighest2 < 35)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 45)
					{
						otherPerson.setPlayersValue(.8);
						lopsidedOffset2 = .8;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 55)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 25)
				{
					person.setPlayersValue(.92);
					lopsidedOffset = .92;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.7);
					lopsidedOffset = .7;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.63);
					lopsidedOffset = .63;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
					return;
				}
				else
				{
					person.setPlayersValue(.5);
					lopsidedOffset = .5;
				}
				return;
			}
		}
		///////////////////////////////lopside 2
	case (2):
		if (otherPerson.returnNumOfPlayersTraded() == 1)
		{
			if (highest1 > highest2)
			{
				return;
			}
			if (highest2 - highest1 > 0 && highest2 - highest1 < 6)
			{
				person.setPlayersValue(.95);
				lopsidedOffset = .95;
				return;
			}
			else if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{
				person.setPlayersValue(.9);
				lopsidedOffset = .9;
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				person.setPlayersValue(.8);
				lopsidedOffset = .8;
				return;
			}
			else if (highest2 - highest1 > 20 && highest2 - highest1 < 28)
			{
				person.setPlayersValue(.65);
				lopsidedOffset = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				person.setPlayersValue(.55);
				lopsidedOffset = .55;
				return;
			}
			else
				break;
		}
		////////////////// 3 for 2
		else if (otherPerson.returnNumOfPlayersTraded() == 2)
		{
			////////////////////////////////if highest1 > highest2/////////////////////////
			if (highest1 > highest2)
			{
				if (highest1 - highest2 < 4)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				else if (highest1 - highest2 < 12)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 24)
					{
						person.setPlayersValue(.92);
						lopsidedOffset = .92;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 23 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.84);
						lopsidedOffset = .84;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.7);
						lopsidedOffset = .7;
						return;
					}
				}
				else if (highest1 - highest2 < 24)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 34)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 33)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
				}
				else if (highest1 - highest2 < 38)
				{
					if (secondHighest1 >= secondHighest2)
					{
						return;
					}
					if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 12)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 11 && secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(1);
						lopsidedOffset = 1;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 27 && secondHighest2 - secondHighest1 < 41)
					{
						person.setPlayersValue(.97);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 > 40)
					{
						person.setPlayersValue(.93);
						lopsidedOffset = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest1 is less than highest2////////////////
			if (highest2 - highest1 < 6)
			{////////////////////first if secondhighest is 10 greater than secondhighest2/////////////				
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			////////////////////////if highest2 is between 5 and 13 greather than highest1/////////////////
			if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{/////////////////////if secondhighest1 is 16 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 16))
				{
					if (secondHighest1 - secondHighest2 < 20)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 15)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				if (secondHighest1 > (secondHighest2 + 10))
				{
					if (secondHighest1 - secondHighest2 < 16)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 25)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 36)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					person.setPlayersValue(.96);
					lopsidedOffset = .96;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.80);
					lopsidedOffset = .80;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.73);
					lopsidedOffset = .73;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.65);
					lopsidedOffset = .65;
					return;
				}
				else
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
				}
				return;
			}
			//////////////////////if highest2 is 22 greater
			else if (highest2 - highest1 > 22)
			{
				/////////////////////if secondhighest1 is 25 greather than secondhighest2
				if (secondHighest1 > (secondHighest2 + 25))
				{
					if (secondHighest1 - secondHighest2 < 35)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 45)
					{
						otherPerson.setPlayersValue(.8);
						lopsidedOffset2 = .8;
						return;
					}
					else if (secondHighest1 - secondHighest2 < 55)
					{
						otherPerson.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 25)
				{
					person.setPlayersValue(.92);
					lopsidedOffset = .92;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					person.setPlayersValue(.7);
					lopsidedOffset = .7;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 10 && secondHighest2 - secondHighest1 < 23)
				{
					person.setPlayersValue(.63);
					lopsidedOffset = .63;
					return;
				}
				else if (secondHighest2 - secondHighest1 > 22 && secondHighest2 - secondHighest1 < 33)
				{
					person.setPlayersValue(.55);
					lopsidedOffset = .55;
					return;
				}
				else
				{
					person.setPlayersValue(.5);
					lopsidedOffset = .5;
				}
				return;
			}
		}
		/////////////////////////lopside 3
	case (3):
		if (otherPerson.returnNumOfPlayersTraded() == 1)
		{
			if (highest1 > highest2)
			{
				return;
			}
			if (highest2 - highest1 > 0 && highest2 - highest1 < 6)
			{
				person.setPlayersValue(.95);
				lopsidedOffset = .95;
				return;
			}
			else if (highest2 - highest1 > 5 && highest2 - highest1 < 13)
			{
				person.setPlayersValue(.9);
				lopsidedOffset = .9;
				return;
			}
			else if (highest2 - highest1 > 12 && highest2 - highest1 < 21)
			{
				person.setPlayersValue(.8);
				lopsidedOffset = .8;
				return;
			}
			else if (highest2 - highest1 > 20 && highest2 - highest1 < 28)
			{
				person.setPlayersValue(.65);
				lopsidedOffset = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				person.setPlayersValue(.55);
				lopsidedOffset = .55;
				return;
			}
			else
				break;
		}
		////////////////////////lopside -1
	case (-1):
		if (person.returnNumOfPlayersTraded() == 1)
		{
			if (highest2 > highest1)
			{
				return;
			}
			if (highest1 - highest2 > 0 && highest1 - highest2 < 6)
			{
				otherPerson.setPlayersValue(.95);
				lopsidedOffset2 = .95;
				return;
			}
			else if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{
				otherPerson.setPlayersValue(.9);
				lopsidedOffset2 = .9;
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				otherPerson.setPlayersValue(.8);
				lopsidedOffset2 = .8;
				return;
			}
			else if (highest1 - highest2 > 20 && highest1 - highest2 < 28)
			{
				otherPerson.setPlayersValue(.65);
				lopsidedOffset2 = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				otherPerson.setPlayersValue(.55);
				lopsidedOffset2 = .55;
				return;
			}
			else
				break;
		}
		////////////////// 3 for 2
		else if (person.returnNumOfPlayersTraded() == 2)
		{
			////////////////////////////////if highest2 > highest1/////////////////////////
			if (highest2 > highest1)
			{
				if (highest2 - highest1 < 4)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				else if (highest2 - highest1 < 12)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.92);
						lopsidedOffset2 = .92;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.84);
						lopsidedOffset2 = .84;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
				}
				else if (highest2 - highest1 < 24)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
				}
				else if (highest2 - highest1 < 38)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 41)
					{
						otherPerson.setPlayersValue(.97);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 40)
					{
						otherPerson.setPlayersValue(.93);
						lopsidedOffset2 = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest2 is less than highest1////////////////
			if (highest1 - highest2 < 6)
			{////////////////////first if secondhighest2 is 10 greater than secondhighest1/////////////				
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			////////////////////////if highest2 is between 5 and 13 greather than highest1/////////////////
			if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{/////////////////////if secondhighest1 is 16 greather than secondhighest2
				if (secondHighest2 > (secondHighest1 + 16))
				{
					if (secondHighest2 - secondHighest1 < 20)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest1 - secondHighest2 < 15)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			//////////////////////if highest1 is 22 greater
			else if (highest1 - highest2 > 22)
			{
				/////////////////////if secondhighest2 is 25 greather than secondhighes12
				if (secondHighest2 > (secondHighest1 + 25))
				{
					if (secondHighest2 - secondHighest1 < 35)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 45)
					{
						person.setPlayersValue(.8);
						lopsidedOffset = .8;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 55)
					{
						person.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 25)
				{
					otherPerson.setPlayersValue(.92);
					lopsidedOffset2 = .92;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.7);
					lopsidedOffset2 = .7;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.63);
					lopsidedOffset2 = .63;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.5);
					lopsidedOffset2 = .5;
				}
				return;
			}
		}
		else if (person.returnNumOfPlayersTraded() == 3)
		{
			////////////////////////////////if highest1 > highest2/////////////////////////
			if (highest2 > highest1)
			{
				if (highest2 - highest1 < 4)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				else if (highest2 - highest1 < 12)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.92);
						lopsidedOffset2 = .92;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.84);
						lopsidedOffset2 = .84;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
				}
				else if (highest2 - highest1 < 24)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
				}
				else if (highest2 - highest1 < 38)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 41)
					{
						otherPerson.setPlayersValue(.97);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 40)
					{
						otherPerson.setPlayersValue(.93);
						lopsidedOffset2 = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest2 is less than highest1////////////////
			if (highest1 - highest2 < 6)
			{////////////////////first if secondhighest2 is 10 greater than secondhighest1/////////////				
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			////////////////////////if highest1 is between 5 and 13 greather than highest2/////////////////
			if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{/////////////////////if secondhighest2 is 16 greather than secondhighest1
				if (secondHighest2 > (secondHighest1 + 16))
				{
					if (secondHighest2 - secondHighest1 < 20)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 15)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			//////////////////////if highest1 is 22 greater
			else if (highest1 - highest2 > 22)
			{
				/////////////////////if secondhighest2 is 25 greather than secondhighest1
				if (secondHighest2 > (secondHighest1 + 25))
				{
					if (secondHighest2 - secondHighest1 < 35)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 45)
					{
						person.setPlayersValue(.8);
						lopsidedOffset = .8;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 55)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 25)
				{
					otherPerson.setPlayersValue(.92);
					lopsidedOffset2 = .92;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.7);
					lopsidedOffset2 = .7;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.63);
					lopsidedOffset2 = .63;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.5);
					lopsidedOffset2 = .5;
				}
				return;
			}
		}
		//////////////////////lopside -2
	case (-2):
		if (person.returnNumOfPlayersTraded() == 1)
		{
			if (highest2 > highest1)
			{
				return;
			}
			if (highest1 - highest2 > 0 && highest1 - highest2 < 6)
			{
				otherPerson.setPlayersValue(.95);
				lopsidedOffset2 = .95;
				return;
			}
			else if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{
				otherPerson.setPlayersValue(.9);
				lopsidedOffset2 = .9;
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				otherPerson.setPlayersValue(.8);
				lopsidedOffset2 = .8;
				return;
			}
			else if (highest1 - highest2 > 20 && highest1 - highest2 < 28)
			{
				otherPerson.setPlayersValue(.65);
				lopsidedOffset2 = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				otherPerson.setPlayersValue(.55);
				lopsidedOffset2 = .55;
				return;
			}
			else
				break;
		}
		////////////////// 3 for 2
		else if (person.returnNumOfPlayersTraded() == 2)
		{
			////////////////////////////////if highest2 > highest1/////////////////////////
			if (highest2 > highest1)
			{
				if (highest2 - highest1 < 4)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.85);
						lopsidedOffset2 = .85;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				else if (highest2 - highest1 < 12)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 24)
					{
						otherPerson.setPlayersValue(.92);
						lopsidedOffset2 = .92;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 23 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.84);
						lopsidedOffset2 = .84;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.7);
						lopsidedOffset2 = .7;
						return;
					}
				}
				else if (highest2 - highest1 < 24)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 34)
					{
						otherPerson.setPlayersValue(.95);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 33)
					{
						otherPerson.setPlayersValue(.9);
						lopsidedOffset2 = .9;
						return;
					}
				}
				else if (highest2 - highest1 < 38)
				{
					if (secondHighest2 >= secondHighest1)
					{
						return;
					}
					if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 12)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 11 && secondHighest1 - secondHighest2 < 28)
					{
						otherPerson.setPlayersValue(1);
						lopsidedOffset2 = 1;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 27 && secondHighest1 - secondHighest2 < 41)
					{
						otherPerson.setPlayersValue(.97);
						lopsidedOffset2 = .95;
						return;
					}
					else if (secondHighest1 - secondHighest2 > 40)
					{
						otherPerson.setPlayersValue(.93);
						lopsidedOffset2 = .93;
						return;
					}
				}
			}
			/////////////////////////////ok now if highest2 is less than highest1////////////////
			if (highest1 - highest2 < 6)
			{////////////////////first if secondhighest2 is 10 greater than secondhighest1/////////////				
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			////////////////////////if highest2 is between 5 and 13 greather than highest1/////////////////
			if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{/////////////////////if secondhighest1 is 16 greather than secondhighest2
				if (secondHighest2 > (secondHighest1 + 16))
				{
					if (secondHighest2 - secondHighest1 < 20)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 28)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				///////////////////out of being 16 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest1 - secondHighest2 < 15)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				if (secondHighest2 > (secondHighest1 + 10))
				{
					if (secondHighest2 - secondHighest1 < 16)
					{
						person.setPlayersValue(.95);
						lopsidedOffset = .95;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 25)
					{
						person.setPlayersValue(.85);
						lopsidedOffset = .85;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 36)
					{
						person.setPlayersValue(.74);
						lopsidedOffset = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset = .6;
						return;
					}
				}
				//////////////out of secondhighest being 10 greater than secondhighest1
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 11)
				{
					otherPerson.setPlayersValue(.96);
					lopsidedOffset2 = .96;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.80);
					lopsidedOffset2 = .80;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.73);
					lopsidedOffset2 = .73;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.65);
					lopsidedOffset2 = .65;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
				}
				return;
			}
			//////////////////////if highest1 is 22 greater
			else if (highest1 - highest2 > 22)
			{
				/////////////////////if secondhighest2 is 25 greather than secondhighes12
				if (secondHighest2 > (secondHighest1 + 25))
				{
					if (secondHighest2 - secondHighest1 < 35)
					{
						person.setPlayersValue(.9);
						lopsidedOffset = .9;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 45)
					{
						person.setPlayersValue(.8);
						lopsidedOffset = .8;
						return;
					}
					else if (secondHighest2 - secondHighest1 < 55)
					{
						person.setPlayersValue(.74);
						lopsidedOffset2 = .74;
						return;
					}
					else
					{
						person.setPlayersValue(.6);
						lopsidedOffset2 = .6;
						return;
					}
				}
				///////////////////out of being 25 great
				else if (secondHighest2 - secondHighest1 > 0 && secondHighest2 - secondHighest1 < 25)
				{
					otherPerson.setPlayersValue(.92);
					lopsidedOffset2 = .92;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 0 && secondHighest1 - secondHighest2 < 11)
				{
					otherPerson.setPlayersValue(.7);
					lopsidedOffset2 = .7;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 10 && secondHighest1 - secondHighest2 < 23)
				{
					otherPerson.setPlayersValue(.63);
					lopsidedOffset2 = .63;
					return;
				}
				else if (secondHighest1 - secondHighest2 > 22 && secondHighest1 - secondHighest2 < 33)
				{
					otherPerson.setPlayersValue(.55);
					lopsidedOffset2 = .55;
					return;
				}
				else
				{
					otherPerson.setPlayersValue(.5);
					lopsidedOffset2 = .5;
				}
				return;
			}
		}
		/////////////////////lopside -3
	case (-3):
		if (person.returnNumOfPlayersTraded() == 1)
		{
			if (highest2 > highest1)
			{
				return;
			}
			if (highest1 - highest2 > 0 && highest1 - highest2 < 6)
			{
				otherPerson.setPlayersValue(.95);
				lopsidedOffset2 = .95;
				return;
			}
			else if (highest1 - highest2 > 5 && highest1 - highest2 < 13)
			{
				otherPerson.setPlayersValue(.9);
				lopsidedOffset2 = .9;
				return;
			}
			else if (highest1 - highest2 > 12 && highest1 - highest2 < 21)
			{
				otherPerson.setPlayersValue(.8);
				lopsidedOffset2 = .8;
				return;
			}
			else if (highest1 - highest2 > 20 && highest1 - highest2 < 28)
			{
				otherPerson.setPlayersValue(.65);
				lopsidedOffset2 = .65;
				return;
			}
			else if (highest2 - highest1 > 27)
			{
				otherPerson.setPlayersValue(.55);
				lopsidedOffset2 = .55;
				return;
			}
			else
				break;
		}
		
	}
}