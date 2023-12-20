#include "sortings.h"
#include "MM.h"

int main() {

	test();

	int mc[] = {1, 1, 2, 3, 4, 1, 2, -1000000, 10};
	quick(mc, 0, 8);

	for (int j = 0; j < 9; j++) printf("%d ", mc[j]);
}
