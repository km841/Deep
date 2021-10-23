#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <filesystem>
#include <vector>
#include <map>

using namespace std;
namespace fs = std::filesystem;


class FileManager
{
public:
    FileManager() : _localPath(fs::current_path()) { InnerList();  };
    ~FileManager() {};
    void ChangeDir(const char* p);
    void RemoveFile(const char* p);
    void AlignExt();
    void InnerList();
    void PrintAlignList();
 
    const vector<fs::path>& GetFileList();
    const fs::path& GetPath();
    const map<string, vector<fs::path>>& GetAlignList();


public:
    fs::path _localPath;
    vector<fs::path> _pv;
    map<string, vector<fs::path>> _spvm;
};
