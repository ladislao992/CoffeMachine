#include "CoffeeMaker.h"
CoffeeMaker::CoffeeMaker(int water, int sugar, int milk, int coffee) :
	m_curWater(water),
	m_curSugar(sugar),
	m_curMilk(milk),
	m_curValCoffee(coffee)
{
	if (m_curWater <= m_minLevelWater || m_curValCoffee <= m_minValCoffee) {
		std::cout << "chek lvl of water and coffee";
	}
	SetEspressoRecipe();
	SetAmericanoRecipe();
	SetLatteRecipe();
}
bool CoffeeMaker::ChekIngredientLowLvl(int water, int sugar, int milk, int coffee) {
	bool res = true;
	if (m_curWater <= m_lowLevelWater) {
		std::cout << "Water low level" << std::endl;
		if (m_curWater - water <= m_minLevelWater) {
			std::cout << "Water min level, please add water" << std::endl;
			res = false;
		}
	}
		if (m_curSugar <= m_lowValSugar) {
			std::cout << "Sugar low level" << std::endl;
			if (m_curSugar - sugar <= m_minLevelWater) {
				std::cout << "Sugar min level, please add sugar, or make without." << std::endl;
				res = false;
			}
		}
		if (m_curMilk - milk <= m_minLevelmilk) {
				std::cout << "Milk min level, please add milk, or choose another drink" << std::endl;
				res = false;
			}
		if (m_curValCoffee - coffee <= m_minValCoffee) {
			std::cout << "Coffee min level, please add coffee please" << std::endl;
			res = false;
		}
	return res;
		}

bool CoffeeMaker::MakeEspresso() {
	bool res = ChekIngredientLowLvl(m_espresoo.water, m_espresoo.sugar, m_espresoo.milk, m_espresoo.coffee);
	if (res) {
		m_curWater -= m_espresoo.water;
		m_curValCoffee -= m_espresoo.coffee;
	}
	return res;
}
bool CoffeeMaker::MakeAmericano()
{
	bool res = ChekIngredientLowLvl(m_americano.water, m_americano.sugar, m_americano.milk, m_americano.coffee);
	if (res) {
		m_curWater -= m_americano.water;
		m_curValCoffee -= m_americano.coffee;
		return res;
	}
}
bool CoffeeMaker::MakeLatte()
{
	bool res = ChekIngredientLowLvl(m_latte.water, m_latte.sugar, m_latte.milk, m_latte.coffee);
	if (res) {
		m_curWater -= m_latte.water;
		m_curValCoffee -= m_latte.coffee;
		m_curMilk -= m_latte.milk;
		m_curSugar -= m_latte.sugar;
		return res;
	}
}

int Add(int add, int& cur, int max) {
	int res = 0;
	if ((cur += add) > max) {
		res = (cur - max);
		cur = max;
	}
	return res;
}
int CoffeeMaker::AddWater(int add) {
	int res = Add(add, m_curWater, m_maxLevelWater);
	return res;
}
int CoffeeMaker::AddSugar(int add) {
	int res = Add(add, m_curSugar, m_maxValSugar);
	return res;
}
int CoffeeMaker::AddMilk(int add) {
	int res = Add(add, m_curMilk, m_maxLevelmilk);
	return res;
}
int CoffeeMaker::AddCoffee(int add) {
	int res = Add(add, m_curValCoffee, m_maxValCoffee);
	return res;
}

void CoffeeMaker::SetEspressoRecipe() {

	m_espresoo.name = "Espresso";
	m_espresoo.water = 40;
	m_espresoo.coffee = 8;
	m_espresoo.t = 95;
	m_espresoo.time = 25;
}
void CoffeeMaker::SetAmericanoRecipe() {
	m_americano.name = "Americano";
	m_americano.water = 80;
	m_americano.coffee = m_espresoo.coffee;
	m_americano.t = m_espresoo.t;
	m_americano.time = 40;
}
void CoffeeMaker::SetLatteRecipe() {
	m_latte.name = "Latte";
	m_latte.water = m_americano.water;
	m_latte.coffee = m_espresoo.coffee * 2;
	m_latte.sugar = 15;
	m_latte.milk = 15;
	m_latte.t = m_espresoo.t;
	m_latte.time = 40;

}
//void CoffeeMaker::SetNewRecipe(std::string name, int water, int sugar, int milk, int coffee, int t, int time) {
//	m_mainRecipes.push_back(new recipe);
//	m_mainRecipes[0]->name = name;
//	m_mainRecipes[0]->water = water;
//	m_mainRecipes[0]->coffee = coffee;
//	m_mainRecipes[0]->t = t;
//	m_mainRecipes[0]->time = time;
//	m_mainRecipes[0]->milk = milk;
//