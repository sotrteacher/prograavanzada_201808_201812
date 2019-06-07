#include <ctime>
/**
 *time_t now = time(0);
 *tm *ltm = localtime(&now);
 */

int get_year(tm* ltm){
  return 1900+ltm->tm_year;
}

int get_month(tm* ltm){
  return 1+ltm->tm_mon;
}

int get_day(tm* ltm){
  return ltm->tm_mday;
}

int get_hour(tm* ltm){
  return 1+ltm->tm_hour;
}

int get_min(tm* ltm){
  return 1+ltm->tm_min;
}

int get_sec(tm* ltm){
  return 1+ltm->tm_sec;
}


