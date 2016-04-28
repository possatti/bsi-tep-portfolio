// UVA 00573 - The Snail

#include <cstdio>
#include <cstdlib>

int main() {
	int h, u, d, f;
	scanf("%d %d %d %d\n", &h, &u, &d, &f);
	// fprintf(stderr, " ==> %d %d %d %d\n", h, u, d, f);
	// fprintf(stderr, "debug: h=%d, u=%d, d=%d, f=%d\n", h, u, d, f);

	while (h != 0) {
		float initial_height, distance_climbed, height_after_climbing, height_after_sliding = 0;
		int day;
		bool finish = true;
		for (day = 1; finish; ++day)
		{
			initial_height = height_after_sliding;
			float fatigue = u * (float (f) / 100) * (day - 1);
			distance_climbed = u - fatigue;
			height_after_climbing = initial_height + distance_climbed;
			height_after_sliding = height_after_climbing - d;
			if (height_after_climbing > h || height_after_sliding < 0)
				finish = false;
			// fprintf(stderr, "debug: day %d\n", day);
			// fprintf(stderr, "debug: initial_height: %f\n", initial_height);
			// fprintf(stderr, "debug: fatigue: %f\n", fatigue);
			// fprintf(stderr, "debug: distance_climbed: %f\n", distance_climbed);
			// fprintf(stderr, "debug: height_after_climbing: %f\n", height_after_climbing);
			// fprintf(stderr, "debug: height_after_sliding: %f\n", height_after_sliding);
			// if (!finish) fprintf(stderr, "debug: finish\n");
		}
		if (height_after_climbing > h) {
			printf("success on day %d\n", day - 1);
		} else {
			printf("failure on day %d\n", day - 1);
		}

		scanf("%d %d %d %d\n", &h, &u, &d, &f);
		// printf(" ==> %d %d %d %d\n", h, u, d, f);
		// fprintf(stderr, "debug: h=%d, u=%d, d=%d, f=%d\n", h, u, d, f);
	}

	return 0;
}
