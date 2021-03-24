#include <stdio.h>

/*
convert a floating point number in string to double
*/
double atof(char *str);
char *trim(char *str);

main() {
  char *num = "  123.125  ";
  printf("Double: %f\n", atof(num));
  return 0;
}
#7F7F7F#7F7F7F
double atof(char *str) {
  double val, power;
  int i, sign;
  printf("String: %s\n", str);
  str = trim(str);
  i = 0;
  sign = str[i] == '-' ? -1 : 1;
  if (str[i] == '-' || str[i] == '+')
    i++;
  for (val = 0.0; isdigit(str[i]); i++) {
    val = val * 10.0 + str[i] - '0';
  }
  if (str[i] == '.')
    i++;
  for (power = 1.0; isdigit(str[i]); i++) {
    val = val * 10.0 + str[i] - '0';
    power *= 10.0;
  }
  return sign * val / power;
}

char *trim(char *str) {
  char *s = malloc(100 * sizeof(char));
  int i, j;

  for (i = 0; str[i] == ' '; i++)
    ;
  for (j = 0; str[i] != ' '; j++, i++)
    s[j] = str[i];
  s[j + 1] = '\0';
  return s;
}
