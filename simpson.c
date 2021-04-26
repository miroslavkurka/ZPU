#include <math.h>
#include <stdio.h>

double f(double x) {
  double tmp = 0; // vypocet samotnej funkcie
  return tmp;
}

double Integral(int a, int b) // od a po b
{
  /* Simpson
   * 1. dostan cele cislo na interval aproximacie
   * 2. vypocitaj step delta
   * 3. kazde cele liche krat 2 kazde sude krat 4
   * 4. spocitaj cele pole
   * */
  int n_round = a / b;
  double delta = (b - a) / n_round;
  double result = 0;

  for (int i = 0; i < n_round; ++i) {
    if (i % 2 == 0) {
      result += 2 * f(i + delta);
    } else {
      result += 4 * f(i + delta);
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  //      double dolna_hranica = atoi(argv[1]);
  //     double horna_hranica = atoi(argv[2]);
}
