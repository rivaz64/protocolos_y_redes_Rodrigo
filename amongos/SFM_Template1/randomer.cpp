#include "randomer.h"
#include<math.h>
float randomer::box_muller(float x, float y)
{
	if (ya) {
		ya = false;
		return n2;
	}
	else {
		float w = x * x + y * y;
		do {
			n1 = x * w;
			n2 = y * w;
			w = sqrt((-2.0 * log(w)) / w);
		} while (w < 1);
		return n1;
	}

}