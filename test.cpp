#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
int hangman();

void score(int);


void main()
{
    printf("Game Start!\n\n");
    hangman();

}
int hangman() {
    int select;
    int num = 25;
    string words[25] = {
       {"dog"},{"cat"},{"tiger"},{"rabbit"},
       {"duck"},{"turtle"},{"cow"},{"chicken"},
       {"lion"},{"snake"},{"horse"},{"mouse"},
       {"giraffe"},{"penguin"},{"whale"},{"deer"},
       {"sheep"},{"goat"},{"wolf"},{"fox"},{"elephant"},
       {"bear"},{"camel"},{"dolphin"} };
    srand(time(NULL)); // 무작위 값 뽑기
    select = rand() % num; // select은 랜덤하게 뽑힐 단어의 번호
                      // num은 지정된 단어의 개수
    string problem;
    string answer;
    char char_answer; // 초기화

    int len_answer;
    int count = 0;

    len_answer = words[select].size();
    problem = words[select];

    for (int i = 0; i < len_answer; i++) {
        answer.push_back('_');
        cout << '_';
    }
    cout << endl;

    while (1)
    {
        printf("\nPlease type in alphant: ");
        cin >> char_answer;
        cin.ignore();
        cin.clear();
        int right = 0;

        for (int i = 0; i < len_answer; i++) {
            if (problem[i] == char_answer)
            {
                answer[i] = problem[i];
                right = 1;
            }
        }
        if (right == 0)
        {
            printf("wrong!\n");
            count++;
            score(count);
        }
        for (int i = 0; i < len_answer; i++)
        {
            cout << answer[i];
        }
        printf("\n");
        if (answer == problem)
        {
            printf("*** You Win ***\n");
            break;
        }
        if (count == 6)
        {
            printf("You died...Try again.\n");
            cout << "The answer is " << problem << endl;
            break;
        }
    }
    return 0;
}
// 틀렸을 경우 hangman의 그림이 하나씩 추가됨
void score(int count)
{
    if (count == 0)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         —\n");
    }
    else if (count == 1)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         —\n");
    }
    else if (count == 2)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("   |      |\n");
        printf("         |\n");
        printf("         —\n");
    }
    else if (count == 3)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("   /|      |\n");
        printf("         |\n");
        printf("         —\n");
    }
    else if (count == 4)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("   <|>      |\n");
        printf("         |\n");
        printf("         —\n");
    }
    else if (count == 5)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("   <|>       |\n");
        printf("   ／      |\n");
        printf("         —\n");
    }
    else if (count == 6)
    {
        printf("   |‾‾‾‾‾‾‾|\n");
        printf("    o      |\n");
        printf("   <|>      |\n");
        printf("   ／＼   |\n");
        printf("         —\n");
    }


}
