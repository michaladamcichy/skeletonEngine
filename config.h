#pragma once
class Config
{
private:
	std::string windowTitle = "My little window ;-D";
	int screenWidth = 1024;
	int screenHeight = 756;
	std::string worldFileName = "world.dat";
	double cameraLengthMultiplier = 1;
public:
	Config(std::string cfgFilePath);
	void printCurrentCfgInfo();
	const char* getWindowTitle();
	int getScreenWidth();
	int getScreenHeight();
	const char* getWorldFileName();
	double getCameraLengthMultiplier();
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
		std::string tmp;
		printf("\nLoading configuration from %s.", cfgFilePath.c_str());
		std::getline(input, windowTitle);
		input >> screenWidth;
		std::getline(input, tmp);
		input >> screenHeight;
		std::getline(input, tmp);
		input >> worldFileName;
		std::getline(input, tmp);
		input >> cameraLengthMultiplier;
		std::getline(input, tmp);
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
	printf("\nWorld file name: %s", worldFileName.c_str());
	printf("\nCamera's length: %lf", cameraLengthMultiplier);
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
const char* Config::getWorldFileName()
{
	return worldFileName.c_str();
}
double Config::getCameraLengthMultiplier()
{
	return cameraLengthMultiplier;
}
Config::~Config()
{
}