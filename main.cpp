#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
    bool isEnd = false;
    string line, person, currentPerson;
    int gift, recievers, money, numberOfPeople;
    istringstream ss;
    map<string, int> persons;
    vector<string> personsVector;

    while (getline(cin, line))
    {
        if (isEnd)
        {
            cout<< endl;
        }
        ss.str(line);
        ss >> numberOfPeople;
        ss.clear();
        getline(cin, line);
        ss.str(line);
        for (int i = 0; i < numberOfPeople; i++)
        {
            ss >> person;
            ss.clear();
            persons.insert(pair<string, int>(person, 0));
            personsVector.push_back(person);
        }
        for (int i = 0; i < numberOfPeople; i++)
        {
            getline(cin, line);
            ss.str(line);
            ss >> currentPerson >> gift >> recievers;
            if (recievers != 0)
            {
                money = gift / recievers;
                auto it = persons.find(currentPerson);
                it->second += -1 * recievers * money;

                for (int j = 0; j < recievers; j++)
                {
                    ss >> person;
                    auto it = persons.find(person);
                    it->second += money;
                }
            }
            ss.clear();
        }
        for (auto vec_it = personsVector.begin(); vec_it < personsVector.end(); vec_it++)
        {
            auto map_it = persons.find(*vec_it);
            cout << map_it->first << " " << map_it->second << endl;
        }
        personsVector.clear();
        persons.clear();
        isEnd = true;
    }
    return EXIT_SUCCESS;
}