#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// HUGE thanks to evandeadlysins from the dark souls discord
// for providing the formulas to calculate the next level cost

int calculate_des_ds1_ds3_er_bb(int s, int e) {
	int res = 0;
	int diff;

	// (souls to get from lvl 1 to lvl e) - (souls to get from lvl 1 to lvl s)

	for (size_t i = 2; i < e + 1; i++) {
		if (i <= 11)
			diff = round(0.08 * pow(i, 2) + 16.2 * i + 640.7);
		else
			diff = round(0.02 * pow(i, 3) + 3.06 * pow(i, 2) + 105.6 * i - 895);
		res += diff;
	}

	for (size_t j = 2; j < s + 1; j++) {
		if (j <= 11)
			diff = round(0.08 * pow(j, 2) + 16.2 * j + 640.7);
		else
			diff = round(0.02 * pow(j, 3) + 3.06 * pow(j, 2) + 105.6 * j - 895);
		res -= diff;
	}

	return res;
}

// this is a recursive funciton here,
// but ds2 just stores all the values in memory lmao
double ds2_next_level_cost(int x) {
	double res;
	if (x == 2)
		return 500;
	else if (x >= 3 && x <= 13)
		return ds2_next_level_cost(x - 1) * 1.0550;
	else if (x >= 14 && x <= 17)
		return ds2_next_level_cost(x - 1) * 1.0520;
	else if (x >= 18 && x <= 25)
		return ds2_next_level_cost(x - 1) * 1.0500;
	else if (x >= 26 && x <= 41)
		return ds2_next_level_cost(x - 1) * 1.0420;
	else if (x >= 42 && x <= 56)
		return ds2_next_level_cost(x - 1) * 1.0340;
	else if (x >= 57 && x <= 71)
		return ds2_next_level_cost(x - 1) * 1.0250;
	else if (x >= 72 && x <= 91)
		return ds2_next_level_cost(x - 1) * 1.0220;
	else if (x >= 92 && x <= 116)
		return ds2_next_level_cost(x - 1) * 1.0170;
	else if (x >= 117 && x <= 171)
		return ds2_next_level_cost(x - 1) * 1.0150;
	else if (x >= 172 && x <= 181)
		return ds2_next_level_cost(x - 1) * 1.0120;
	else if (x >= 182 && x <= 201)
		return ds2_next_level_cost(x - 1) * 1.0080;
	else if (x >= 202 && x <= 251)
		return ds2_next_level_cost(x - 1) * 1.0350;
	else
		return ds2_next_level_cost(x - 1) * 1.0025;
}

int calculate_ds2(int s, int e) {
	int res = 0;

	// souls from lvl 1 to e - souls from lvl 1 to s

	for (size_t i = 2; i < e + 1; i++) {
		res += round(ds2_next_level_cost(i));
	}

	for (size_t j = 2; j < s + 1; j++) {
		res -= round(ds2_next_level_cost(j));
	}

	return res;
}

int main(int argc, char* argv[]) {
	if (argc < 4) {
		printf("usage: soulcalc <des/ds1/ds2/ds3/er/bb> <start level> <end level>\n");
		return 1;
	}

	char* game = argv[1];
	int start_lvl = atoi(argv[2]);
	int end_lvl = atoi(argv[3]);

	if (end_lvl < start_lvl || end_lvl == start_lvl) {
		printf("end level is smaller than or equal to start level, try again\n");
		return 1;
	}

	if (start_lvl < 1) {
		printf("start level less than 1, try again\n");
		return 1;
	}

	int res;
	if (strcmp(game, "des") == 0 || strcmp(game, "ds1") == 0 || strcmp(game, "ds3") == 0 || strcmp(game, "er") == 0 || strcmp(game, "bb") == 0) {
		if (end_lvl > 713) {
			printf("end level too high for this game! 713 is the max for %s\n", game);
			return 1;
		}
		res = calculate_des_ds1_ds3_er_bb(start_lvl, end_lvl);
	} else if (strcmp(game, "ds2") == 0) {
		if (end_lvl > 838) {
			printf("end level too high for this game! 838 is the max for dark souls 2\n");
			return 1;
		}
		res = calculate_ds2(start_lvl, end_lvl);
	} else {
		printf("invalid game\n");
		return 1;
	}

	printf("to get from level %d to level %d in %s, you'll need %d souls/runes/echoes\n", start_lvl, end_lvl, game, res);
}
