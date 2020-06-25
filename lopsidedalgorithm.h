#pragma once
#include "PersonClass.h"

class LopsidedAlgorithm
{
private:
	int highest1{ 0 };
	int highest2{ 0 };
	int secondHighest1{ 0 };
	int secondHighest2{ 0 };
	int thirdHighest1{ 0 };
	int thirdHighest2{ 0 };
	int lowest1{ 10000 };
	int lowest2{ 10000 };
	int lopsidedValue{};
	std::vector<int> tempvec{};
	std::vector<int> tempvec2{};

public:
	void applyLopsidedAlgorithm(PersonClass& person, PersonClass& otherPerson, float& lopsidedOffset, float& lopsidedOffset2);
	void getAndSetLopsidedValue(PersonClass& person);
	void getAndSetHighest(PersonClass& person);
	void getAndSetHighest2(PersonClass& person);
	void getAndSetThirdHighest1(PersonClass& person);
	void getAndSetThirdHighest2(PersonClass& person);
	void getAndSetLowest(PersonClass& person);
	void getAndSetLowest2(PersonClass& person);
	void getAndSetSecondHighest(PersonClass& person);
	void getAndSetSecondHighest2(PersonClass& person);
	void getAndSettempvec(PersonClass& person);
	void getAndSettempvec2(PersonClass& Person);
};
