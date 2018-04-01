#pragma once
class Config
{
private:
	std::string windowTitle = "My little window ;-D";
	int screenWidth = 1024;
	int screenHeight = 756;
public:
	Config(std::string cfgFilePath);
	void printCurrentCfgInfo();
	const char* getWindowTitle();
	int getScreenWidth();
	int getScreenHeight();
	~Config();
};

Config::Config(std::string cfgFilePath = "cfg.cfg")
{
	std::ifstream input;
	input.open(cfgFilePath);
	if (!input.good())
	{
		printf("\nUnable to open configuration file: %s", cfgFilePath.c_str());
	}
	else
	{
		printf("\nLoading configuration from %s.", cfgFilePath.c_str());
		std::getline(input, windowTitle);
		input >> screenWidth;
		input.get();
		input >> screenHeight;
		input.get();
	}
	input.close();
	printCurrentCfgInfo();
}
void Config::printCurrentCfgInfo()
{
	printf("\nCurrent configuration info:");
	printf("\nWindow title: %s", windowTitle.c_str());
	printf("\nScreen width: %d", screenWidth);
	printf("\nScreen height: %d", screenHeight);
}
const char* Config::getWindowTitle()
{
	return windowTitle.c_str();
}
int Config::getScreenWidth()
{
	return screenWidth;
}
int Config::getScreenHeight()
{
	return screenHeight;
}
Config::~Config()
{
}