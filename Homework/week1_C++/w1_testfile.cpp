//我把函式include進來了,直接編譯此檔就可以ㄌ
#include "homework.cpp"
int main() {
    int gcd_arr[50][3] = {
        {438, 30, 6},   {597, 117, 3}, {836, 561, 11}, {9, 162, 9},    {388, 856, 4},
        {942, 879, 3},  {144, 861, 3}, {508, 938, 2},  {49, 574, 7},   {722, 850, 2},
        {633, 837, 3},  {906, 492, 6}, {792, 592, 8},  {1000, 916, 4}, {742, 222, 2},
        {138, 225, 3},  {568, 800, 8}, {834, 126, 6},  {485, 110, 5},  {580, 572, 4},
        {672, 480, 96}, {394, 404, 2}, {864, 219, 3},  {404, 292, 4},  {212, 368, 4},
        {435, 29, 29},  {694, 342, 2}, {765, 648, 9},  {783, 675, 27}, {464, 96, 16},
        {976, 86, 2},   {142, 866, 2}, {287, 686, 7},  {215, 535, 5},  {875, 455, 35},
        {514, 840, 2},  {856, 390, 2}, {484, 112, 4},  {458, 680, 2},  {441, 330, 3},
        {768, 754, 2},  {538, 262, 2}, {14, 200, 2},   {926, 490, 2},  {196, 544, 4},
        {896, 938, 14}, {330, 621, 3}, {279, 930, 93}, {333, 696, 3},  {111, 222, 111}};

    int fib_arr[40] = {
        0,          1,         1,         2,         3,         5,          8,          13,
        21,         34,        55,        89,        144,       233,        377,        610,
        987,        1597,      2584,      4181,      6765,      10946,      17711,      28657,
        46368,      75025,     121393,    196418,    317811,    514229,     832040,     1346269,
        2178309,    3524578,   5702887,   9227465,   14930352,  24157817,   39088169,   63245986,
        };

    int b2d_arr[50][2] = {
        {1110111010, 954},  {1101000100, 836},  {1111110001, 1009}, {1100101111, 815},
        {1010100101, 677},  {1001100100, 612},  {1000011011, 539},  {1110000001, 897},
        {1110101010, 938},  {1110011001, 921},  {1011111101, 765},  {1110101111, 943},
        {1111111110, 1022}, {1100011011, 795},  {1100011101, 797},  {1000010100, 532},
        {1001011000, 600},  {1101000011, 835},  {1111011100, 988},  {1110011011, 923},
        {1110110000, 944},  {1111110011, 1011}, {1101000101, 837},  {1110101011, 939},
        {1001010111, 599},  {1100110110, 822},  {1000110010, 562},  {1100001000, 776},
        {1110010101, 917},  {1000001101, 525},  {1001000111, 583},  {1100001011, 779},
        {1101111110, 894},  {1110011110, 926},  {1000100010, 546},  {1011100101, 741},
        {1100001011, 779},  {1100110111, 823},  {1100101111, 815},  {1011110100, 756},
        {1010100111, 679},  {1110010111, 919},  {1101001010, 842},  {1101100110, 870},
        {1100111100, 828},  {1000110001, 561},  {1111111100, 1020}, {1110000011, 899},
        {1001000001, 577},  {1001110001, 625}};

    int gcd_score = 0;
    for (int i = 0; i < 50; i++)
        if (GCD(gcd_arr[i][0], gcd_arr[i][1]) == gcd_arr[i][2])
            gcd_score++;
    printf("GCD: (%d/50) test passed.\n", gcd_score);

    int fib_score = 0;
    for (int i = 0; i < 40; i++)
        if (fib(i) == fib_arr[i])
            fib_score++;
    printf("fib: (%d/40) test passed.\n", fib_score);

    int b2d_score = 0;
    for (int i = 0; i < 50; i++) {
        if (b2d(to_string(b2d_arr[i][0])) == b2d_arr[i][1])
            b2d_score++;
    }
    printf("b2d: (%d/50) test passed.\n", b2d_score);

    return 0;
}
