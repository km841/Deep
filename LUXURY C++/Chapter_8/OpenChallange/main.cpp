#include <iostream>
#include <string>
#include "pch.h"
#include "Product.h"
#include "ConversationBook.h"
#include "CompactDisc.h"
using namespace std;

class Product;

void PrintInfo()
{
    cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
}

void PrintProd()
{
    cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
}

int main()
{
    cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
    int choice = 0;
    int id = 0;
    Product** prodList = new Product*[100];

    while (choice != 3)
    {
        PrintInfo();
        cin >> choice;
        cin.ignore();   

        if (choice == 1)
        {
            PrintProd();
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                prodList[id] = new Book;
                prodList[id]->Set(id);
                id++;
            }

            else if (choice == 2)
            {
                prodList[id] = new CompactDisc;
                prodList[id]->Set(id);
                id++;
            }

            else if (choice == 3)
            {
                prodList[id] = new ConversationBook;
                prodList[id]->Set(id);
                id++;
            }

            choice = 0;
        }

        else if (choice == 2)
        {
            for (int i = 0; i < id; i++)
            {
                prodList[i]->Show();
            }
        }

        cout << endl;
    }

    for (int i = 0; i < id; i++)
    {
        delete prodList[i];
    }
    delete[] prodList;
    
}

