#pragma once
class ICoffeeMachineRecipe
{
	virtual void SetEspressoRecipe() = 0;
	virtual void SetAmericanoRecipe() = 0;
	virtual void SetLatteRecipe() = 0;
public:
	//virtual ~ICoffeeMachineRecipe();
	//virtual void SetNewRecipe(std::string mane, int water, int sugar, int milk, int coffee, int t, int time) = 0;
};

