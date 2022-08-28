#pragma once
#include "ICoffeeMachine.h"
#include "ICoffeeMachineRecipe.h"
#include<vector>
#include<iostream>
class CoffeeMaker : public ICoffeeMachine, ICoffeeMachineRecipe
{

		void SetEspressoRecipe() override;
		void SetAmericanoRecipe() override;
		void SetLatteRecipe() override;

	public:

		CoffeeMaker(int water, int sugar, int milk, int coffee);
		//~CoffeeMachine() override;
		bool MakeEspresso() override;
		bool MakeAmericano() override;
		bool MakeLatte()  override;

	
		
		int AddSugar(int gr);
		

		//void SetNewRecipe(std::string mane, int water, int sugar, int milk, int coffee, int t, int time)override;
		struct recipe {
			std::string name;
			int water = 0;//ml
			int sugar = 0;//mg
			int milk = 0;//ml
			int coffee = 0;//mg
			int t = 0;// water themperature
			int time = 0;//sec.

		};
		//recipe& GetRecipe(std::string recipeName);

	private:
		//ingredients
		int m_curWater;
		int m_curSugar;
		int m_curMilk;
		int m_curValCoffee;
		//water lvl
		int m_minLevelWater = 0;
		int m_lowLevelWater = 100;
		//sugar lvl
		int m_minValSugar = 0;
		int m_lowValSugar = 100;
		int m_maxValSugar = 3000;

		//milk lvl
		int m_minLevelmilk = 0;
		//coffee lvl
		int m_minValCoffee = 0;

		recipe m_espresoo;
		recipe m_americano;
		recipe m_latte;
		std::vector<recipe*> m_mainRecipes;

};

