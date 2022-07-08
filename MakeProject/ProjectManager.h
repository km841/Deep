#pragma once


class ProjectManager
{

	std::wstring defaultAddr;
	std::vector<std::wstring> projectList;
	std::vector<std::wstring> projectFrame;
	bool flag = true;


public:
	ProjectManager() : defaultAddr(L"D:\\±èÇö¸ð\\DWG\\3.1.2. ELEC BOX") {}
	bool Init();

	~ProjectManager() {}

};

