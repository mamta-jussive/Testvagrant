#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Newspaper
{
    string name;
    unordered_map<string, double> prices; // prices for each day
};

void calculateCombinations(vector<Newspaper> &newspapers, vector<pair<string, double>> &currentSelection, double budget)
{

    double totalCost = 0;
    for (auto &pair : currentSelection)
    {
        totalCost += pair.second;
    }
    if (totalCost > budget)
    {
        return;
    }

    if (totalCost == budget)
    {
        cout << "{";
        for (auto &pair : currentSelection)
        {
            cout << "\"" << pair.first << "\", ";
        }
        cout << "}, ";
        return;
    }

    for (auto &newspaper : newspapers)
    {
        for (auto &pair : newspaper.prices)
        {
            currentSelection.push_back({newspaper.name + " (" + pair.first + ")", pair.second});
            calculateCombinations(newspapers, currentSelection, budget);
            currentSelection.pop_back();
        }
    }
}

int main()
{

    vector<Newspaper> newspapers = {
        {"TOI", {{"Monday", 3}, {"Tuesday", 3}, {"Wednesday", 3}, {"Thursday", 3}, {"Friday", 3}, {"Saturday", 5}, {"Sunday", 6}}},
        {"Hindu", {{"Monday", 2.5}, {"Tuesday", 2.5}, {"Wednesday", 2.5}, {"Thursday", 2.5}, {"Friday", 2.5}, {"Saturday", 4}, {"Sunday", 4}}},
        {"ET", {{"Monday", 4}, {"Tuesday", 4}, {"Wednesday", 4}, {"Thursday", 4}, {"Friday", 4}, {"Saturday", 4}, {"Sunday", 10}}},
        {"BM", {{"Monday", 1.5}, {"Tuesday", 1.5}, {"Wednesday", 1.5}, {"Thursday", 1.5}, {"Friday", 1.5}, {"Saturday", 1.5}, {"Sunday", 1.5}}},
        {"HT", {{"Monday", 2}, {"Tuesday", 2}, {"Wednesday", 2}, {"Thursday", 2}, {"Friday", 2}, {"Saturday", 4}, {"Sunday", 4}}}};

    double budget;
    cout << "Enter weekly budget: ";
    cin >> budget;

    vector<pair<string, double>> currentSelection;
    calculateCombinations(newspapers, currentSelection, budget);

    return 0;
}
