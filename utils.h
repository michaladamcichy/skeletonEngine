bool isFileEmpty(std::string path)
{
    std::ifstream in;
    in.open(path.c_str(), std::ios::ate | std::ios::binary);
	if (in.good())
	{
		return !in.tellg();
	}
	else
	{
		printf("\nCannot open file %s", path.c_str());
		return true;
	}
}
int linesCount(std::string path)
{
	if (isFileEmpty(path))
	{
		return 0;
	}
	else
	{
		std::ifstream in;
		std::string row;
		int rowsCount = 0;
		in.open(path.c_str());
		while (!in.eof())
		{
			std::getline(in, row);
			rowsCount++;
		}
		return rowsCount;
	}
}
std::string lastWordFromPath(std::string path)
{
	if (path.size() == 0)
	{
		return "";
	}
	else
	{
		std::string last;
		int index = path.size() - 1;

		while (path[index] != '/' && index >= 0)
		{
			index--;
		}
		if (index + 1 < path.size())
		{
			index++;
		}
		last = path.substr(index, path.size() - index);
		return last;
	}
}