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
	
	projectFrame.emplace_back(L"1. 제작 도면");
	projectFrame.emplace_back(L"2. 레이아웃 도면");
	projectFrame.emplace_back(L"3. 배치 도면");
	projectFrame.emplace_back(L"4. 송부(참고용) 도면");
	projectFrame.emplace_back(L"5. 전기 도면");
	projectFrame.emplace_back(L"6. 기타 도면");
	projectFrame.emplace_back(L"7. 승인 도면");
	projectFrame.emplace_back(L"8. 파일");

	return true;

	//std::wofstream wofs("this_file.txt", std::ios::app | std::ios::out);
	//for (const auto& fileName : projectList)
	//{
	//	wofs << fileName << endl;
	//}

	//wofs.close();


}
