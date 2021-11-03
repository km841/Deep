#include "Trace.h"

void Trace::put(string tag, string info)
{
	_traceVector.emplace_back(tag, info);
}

void Trace::print(string tag)
{
	cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < _traceVector.size(); i++)
	{
		if (_traceVector[i].first == tag)
			cout << tag << ":" << _traceVector[i].second << endl;
	}
}

void Trace::print()
{
	cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < _traceVector.size(); i++)
	{
		cout << _traceVector[i].first << ":" << _traceVector[i].second << endl;
	}

}
