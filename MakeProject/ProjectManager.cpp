#include "pch.h"
#include "ProjectManager.h"

bool ProjectManager::Init()
{
	for (fs::path fileName : fs::directory_iterator(this->defaultAddr))
	{
		projectList.emplace_back(fileName.wstring());
	}

	if (projectList.empty()) {
		flag = false;
		return false;
	}
	
	projectFrame.emplace_back(L"1. ���� ����");
	projectFrame.emplace_back(L"2. ���̾ƿ� ����");
	projectFrame.emplace_back(L"3. ��ġ ����");
	projectFrame.emplace_back(L"4. �ۺ�(�����) ����");
	projectFrame.emplace_back(L"5. ���� ����");
	projectFrame.emplace_back(L"6. ��Ÿ ����");
	projectFrame.emplace_back(L"7. ���� ����");
	projectFrame.emplace_back(L"8. ����");

	return true;

	//std::wofstream wofs("this_file.txt", std::ios::app | std::ios::out);
	//for (const auto& fileName : projectList)
	//{
	//	wofs << fileName << endl;
	//}

	//wofs.close();


}
