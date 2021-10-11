#include <iostream>
#include "enet/enet.h"
#include "corefunc.h"
#include "json.hpp"
#include "userfunc.h"
#include "utilsfunc.h"
#include <direct.h>
#define GetCurrentDir _getcwd


using namespace std;
using json = nlohmann::json;
vector<GrowtopiaBot> bots;
#pragma region unneed
inline bool exists_test(const string& name) {
	ifstream f(name.c_str());
	return f.good();
}

json getjson()
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return errno;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
	string botDataPath = cCurrentPath + string("\\bot.json");

	if (!exists_test(botDataPath)) {
		cout << "Cannot find bot data on that path!. Stuck?, please read README.md" << endl;
		return 0;
	}
	cout << "Loading bot data on path (" << botDataPath << ")" << endl;

	ifstream i(botDataPath);
	json j;
	i >> j;
	return j;
}


#pragma endregion

vector<string> split(const string& s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

int main(int argc, char** argv)
{
    init(); 
    /*SERVER_HOST = "209.59.191.76";
    SERVER_PORT = 17093;*/
	SERVER_HOST = "127.0.0.1";
	SERVER_PORT = 17191;
	std::string line;
	std::string readline;
	std::ifstream myfile("acc.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			readline += line;
		}
		myfile.close();
	}

	vector<string> out = split(readline, '.');
	GrowtopiaBot bot = {
		out.at(0), out.at(1)
	};
	bot.gameVersion = "3.60";
	bot.worldName = "GROOPHY";
	bot.ownerUsername = "Groophy";
	/*json j = getjson();
	GrowtopiaBot bot = {
		j["username"], j["password"]
	};
	cout << "Bot loaded!. Using username " << j["username"].get<string>() << ", With Pass " + j["password"].get<string>()  << ", With version " + j["gameVersion"].get<string>() << endl;
	bot.gameVersion = j["gameVersion"].get<string>();
	bot.worldName = j["targetWorld"].get<string>();
	bot.ownerUsername = j["ownerUsername"].get<string>();*/
	bot.userInit();
	bots.push_back(bot);
	while (true)
	{
		bot.eventLoop();
		bot.userLoop();
	}
	system("pause");

}


