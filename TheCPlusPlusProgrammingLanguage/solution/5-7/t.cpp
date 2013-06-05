const char *month_name[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","July", "Aug", "Sep","Oct", "Nov", "Dec"};
const int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
struct month {
  const char *name;
  const int days;
};
const struct month m[] = {{"Jan",31},
                  {"Feb",28},
                  {"Mar",31},
                  {"Apr",30},
                  {"May",31},
                  {"Jun",30},
                  {"July",31},
                  {"Aug",31},
                  {"Sep",30},
                  {"Oct",31},
                  {"Nov",30},
                  {"Dec",31}};
int main() {
}
