#include "lib0043.h"

int main() {
	int N;
	MagicBalls(&N);
	if(Collision(1, 2))
		Choose(2, 1);
	else
		Choose(1, 2);
}
