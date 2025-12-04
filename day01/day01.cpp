#include <iostream>
using namespace std;

int part_1(FILE *input) {
    int zero_count = 0;
    char line[32];
    int current = 50;

    while (fgets(line, sizeof line, input)) {
        char dir = line[0];
        long delta = strtol(line + 1, NULL, 10);
        if (dir == 'L') {
            delta *= -1;
        }

        current = (current + delta) % 100;

        if (current < 0)
            current += 100;

        zero_count += (current == 0);
    }

    return zero_count;
}

int part_2(FILE *input) {
    int zero_count = 0;
    char line[32];
    int current = 50;

    while (fgets(line, sizeof line, input)) {
        char dir = line[0];
        long delta = strtol(line + 1, NULL, 10);

        int sign = (dir == 'L') ? -1 : 1;

        for (int i = 0; i < abs(delta); i++) {
            current = (current + sign) % 100;
            zero_count += (current == 0);
        }

        if (current < 0)
            current += 100;
    }

    return zero_count;
}

int main(void) {
    FILE *input = fopen("input", "r");

    if (input) {
        int sol = part_2(input);
        cout << sol << '\n';
        fclose(input);
    }
}
