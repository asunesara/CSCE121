#ifndef WEATHERFUNCTIONS_H
#define WEATHERFUNCTIONS_H
#include <string>
// add function declarations/prototypes


double** add_cities_from_file(double** table, size_t& cities, size_t& days, std::string fileName);

void destroy_table(double** table, int cities);

double get_average_rainfall_between_days_given_city(double** table, int cities, int days,int start, int end, int index);

double get_average_rainfall_between_days_all_cities(double** table, int cities, int days,int start, int end);

double get_max_rainfall_all_cities_given_day(double** table, int cities, int days,int index);

double get_max_rainfall_given_city(double** table, int cities, int days,int index);



#endif