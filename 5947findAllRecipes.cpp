#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector <string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		set<string> m_supplies(supplies.begin(), supplies.end());
		map<string, int> m_recipes;
		for (int i = 0; i < recipes.size(); i++) {
			m_recipes[recipes[i]] = i;
		}
		vector <string> ans;
		bool change = true;
		while (change) {
			change = false;
			vector<string> m_recipes;
			vector<vector<string>> m_ingredients;
			for (int i = 0; i < recipes.size(); i++) {
				vector<string>& ingredient = ingredients[i];
				bool tag = true;
				for (string cur : ingredient) {
					if (m_supplies.find(cur) == m_supplies.end()) {
						tag = false;
						continue;
					}
				}
				if (tag) {
					m_supplies.insert(recipes[i]);
					ans.push_back(recipes[i]);
					change = true;
				}
				else {
					m_recipes.push_back(recipes[i]);
					m_ingredients.push_back(ingredients[i]);
				}
			}
			recipes = m_recipes;
			ingredients = m_ingredients;
		}
		return ans;
	}
};
int main() {
	vector<string> recipes = { "bread" };
	vector<vector<string>> ingredients = { {"yeast", "flour"} };
	vector<string> supplies = { "yeast", "flour", "corn" };
	Solution().findAllRecipes(recipes, ingredients, supplies);
}