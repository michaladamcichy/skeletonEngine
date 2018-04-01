bool isFileEmpty(std::string path)
{
    std::ifstream in;
    in.open(path.c_str(), std::ios::ate | std::ios::binary);
    return !in.tellg();
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