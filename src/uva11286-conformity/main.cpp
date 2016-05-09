// UVa 11286 - Conformity

#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

map<int, int> courses;

int main() {
	int frosh_n;
	int course;
	scanf("%d\n", &frosh_n);
	printf("==> %d\n", frosh_n);

	while (frosh_n != 0) {
		courses.clear();

		for (int i = 0; i < frosh_n; ++i) {
			for (int i = 0; i < 5; ++i) {
				scanf("%d", &course);
				map<int, int>::iterator iter;
				iter = courses.find(course);
				if (iter == courses.end())
					courses[course] = 1;
				else
					iter->second += 1;
				printf("%d ", course);
			}
			printf("\n");
		}

		for(map<int,int>::iterator iter = courses.begin(); iter != courses.end(); ++iter) {
			int course = iter->first;
			int popularity = iter->second;
			printf("[%d => %d]\n", course, popularity);
		}

		scanf("%d\n", &frosh_n);
		printf("==> %d\n", frosh_n);
		//frosh_n = 0;
	}

	return 0;
}