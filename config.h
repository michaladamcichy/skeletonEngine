#pragma once
class Config
{
private:
	std::string windowTitle = "My little window ;-D";
	int screenWidth = 1024;
	int screenHeight = 756;
	std::string worldFileName = "world.dat";
	double cameraLength = 1024;
public:
	Config(std::string cfgFilePath);
	void printCurrentCfgInfo();
	const char* getWindowTitle();
	int getScreenWidth();
	int getScreenHeight();
	const char* getWorldFileName();
	double getCameraLength();
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
		std::string tmpS;
		double tmpD;
		printf("\nLoading configuration from %s.", cfgFilePath.c_str());
		std::getline(input, windowTitle);
		input >> screenWidth;
		std::getline(input, tmpS);
		input >> screenHeight;
		std::getline(input, tmpS);
		input >> worldFileName;
		std::getline(input, tmpS);
		input >> tmpD;
		cameraLength = tmpD * screenWidth;
		std::getline(input, tmpS);
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
	printf("\nCamera's length: %lf", cameraLength);
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
double Config::getCameraLength()
{
	return cameraLength;
}
Config::~Config()
{
}