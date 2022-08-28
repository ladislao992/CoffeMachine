#pragma once
class ICoffeeMachine
{
	virtual bool MakeEspresso() = 0;
	virtual bool MakeAmericano() = 0;
	virtual bool MakeLatte() = 0;
};

