#include "src/circle_queue.hpp"
#include <iostream>
using namespace std;
#define NUM 1e5
#define LEN 100

int main()
{
	CircleQueue<int> circle(LEN);
	for (int i = 0; i < NUM; i++)
	{
		circle.push_back(i);
	}
	for (auto &iter : circle) {
		cout << iter << endl;
	}
	return 0;
}
