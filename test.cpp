#include <iostream>
using namespace std;

class Student
{
	int* scores;
	int score, weekCount;

public:

	Student() : score(0), weekCount(0) {
		scores = new int[6];
	}

	Student(const Student& other) : score(other.score), weekCount(other.weekCount) {
		scores = new int[6];
		for (int i = 0; i < weekCount; i++) {
			scores[i] = other.scores[i];
		}
	}

	int operator+(const Student& other) { return score + other.score; }
	int operator-(const Student& other) { return score - other.score; }

	Student& operator=(const Student& other) {
		score = other.score;
		weekCount = other.weekCount;
		scores = new int[6];
		for (int i = 0; i < weekCount; i++) {
			scores[i] = other.scores[i];
		}
	}

	virtual ~Student() { delete[] scores; }

	void increaseScore(int score) { score++; }
	void nextWeek() { 
		scores[weekCount++] = score;
		score = 0;
	}

	int weeksScore(int week) const { return scores[week]; }

};
int main() {
	Student helpMe;
	//사용하는코드
	return 0;
}
