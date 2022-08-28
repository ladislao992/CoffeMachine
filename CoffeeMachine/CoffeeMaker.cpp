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
bool CoffeeMaker::MakeEspresso()
{
	m_curWater -= m_espresoo.water;
	m_curValCoffee -= m_espresoo.coffee;
	return true;
}
bool CoffeeMaker::MakeAmericano()
{
	m_curWater -= m_americano.water;
	m_curValCoffee -= m_americano.coffee;
	return true;
}
bool CoffeeMaker::MakeLatte()
{
	m_curWater -= m_latte.water;
	m_curValCoffee -= m_latte.coffee;
	m_curMilk -= m_latte.milk;
	m_curSugar -= m_latte.sugar;
	return true;
}
void CoffeeMaker::SetEspressoRecipe() {

	m_espresoo.name = "Espresso";
	m_espresoo.water = 40;
	m_espresoo.coffee = 8;
	m_espresoo.t = 95;
	m_espresoo.time = 25;
}

//int CoffeeMaker::AddIngredient(int ) {
//	int res = 0;
//	if ((m_curSugar += gr) > m_maxValSugar) {
//		res = (m_curSugar - m_maxValSugar);
//		m_curSugar = m_maxValSugar;
//	}
//	return res;
//}
int CoffeeMaker::AddSugar(int gr) {
	int res = 0;
	if ((m_curSugar += gr) > m_maxValSugar) {
		res = (m_curSugar - m_maxValSugar);
		m_curSugar = m_maxValSugar;
	}
	return res;
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
//}