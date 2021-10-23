#include "EP_CPP.h"

void FileManager::ChangeDir(const char* p)
{
    fs::path path = static_cast<fs::path>(p);

    if (!fs::exists(path))
    {
        cout << "존재하지 않는 주소네요!!" << endl;
        return;
    }

    else
    {
        fs::current_path(p);
        this->_localPath = p;
        this->InnerList();
    }
}

void FileManager::RemoveFile(const char* p)
{
    fs::path path = static_cast<fs::path>(p);
    if (!fs::exists(p))
    {
        cout << "파일이 이미 존재하지 않습니다!" << endl;
        return;
    }

    if (fs::remove(p))
        cout << "파일이 정상적으로 삭제되었습니다." << endl;

    else
        cout << "파일이 삭제되지 않았습니다!" << endl;
}

void FileManager::AlignExt()
{
    for (fs::path tp : this->_pv)
    {
        if (fs::is_directory(tp))
        {
            this->_spvm["Dir"].emplace_back(tp);
            continue;
        }
        char* fileName = new char[1024];
        wcstombs(fileName, tp.c_str(), 1024);

        char* e = strrchr(fileName, '.');
        
        const size_t size = strlen(e);

        string ext = e;
        this->_spvm[ext].emplace_back(tp);

        delete[] fileName;
    }
}

void FileManager::InnerList()
{
    if (!_pv.empty())
        _pv.clear();

    for (const auto& file : fs::directory_iterator(this->_localPath))
        _pv.emplace_back(file);
}

void FileManager::PrintAlignList()
{
    for (const auto& [ext, fv] : this->_spvm)
    {
        cout << "# 확장자명 : " << ext << endl;
        for (const auto& fileName : fv)
            cout << "\t@" << fileName << endl;

        cout << endl;
    }
}

const vector<fs::path>& FileManager::GetFileList()
{
    return this->_pv;
}

const fs::path& FileManager::GetPath()
{
    return this->_localPath;
}

const map<string, vector<fs::path>>& FileManager::GetAlignList()
{
    return this->_spvm;
}
