#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

#include <Windows.h>
#include <tchar.h>
#include <CommCtrl.h>
#include <shlobj_core.h>
#include "resource.h"

using namespace std;
namespace fs = std::filesystem;

fs::path get_user_profile_path()
{
	char* p = getenv("UserProfile");
	fs::path result = p;
	return result;
};

class pch
{
};



