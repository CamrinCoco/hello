#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,const char* type, const char* name,
double latitude,double longitude, int elevationFeet,const char* city, const char* countryAbbrv) {
    //creates an unestablished airport structure
    Airport * airport = (Airport *)malloc(sizeof(Airport) * 1);

    airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
    strcpy(airport->gpsId, gpsId);

    airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy(airport->type, type);

    airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(airport->name, name);

    airport->latitude = latitude;

    airport->longitude = longitude;

    airport->elevationFeet = elevationFeet;

    airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
    strcpy(airport->city, city);

    airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
    strcpy(airport->countryAbbrv, countryAbbrv);

    return airport;
}

void initAirport(Airport* airport, const char* gpsId, const char* type, const char* name,
double latitude, double longitude, int elevationFeet, const char* city, const char* countryAbbrv) {

    //establishes an aiport structure, from an already created airport structure
    airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
    strcpy(airport->gpsId, gpsId);

    airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy(airport->type, type);

    airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(airport->name, name);

    airport->latitude = latitude;

    airport->longitude = longitude;

    airport->elevationFeet = elevationFeet;

    airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
    strcpy(airport->city, city);

    airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
    strcpy(airport->countryAbbrv, countryAbbrv);

    return;
}

// char* airportToString(const Airport* a) {
//     if (a == NULL) {
//         char *result = (char *)malloc(sizeof(char) * 7);
//         strcpy(result, "(null)");
//         return result;
//     }
//     char buffer[100];
//     // compute the number of characters needed
//     //int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) + 10 + 10 + 10 + strlen(a->city) + strlen(a->countryAbbrv);

//     int n = snprintf(buffer, 100, "%s %s %s %lf %lf %d %s %s", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);
//     // create a result string
//     char *str = (char *)malloc(sizeof(char) * n);

//     // format the aiport into the temporary string
//     sprintf(str, "%s %s %s %.2lf %.2lf %d %s %s", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);

//     return str;
// }

double getAirDistance(const Airport* origin, const Airport* destination) {

    //calculates airport distance from two different locations using the airport structures
    double degrees = 180.0 / M_PI;
    double distance = acos(sin(origin->latitude * degrees) * sin(destination->latitude * degrees) + cos(origin->latitude * degrees) * cos(destination->latitude * degrees) * cos((destination->longitude * degrees) - (origin->longitude * degrees))) * 6371.0;

    return distance;
}

double getEstimatedTravelTime(const Airport* stops, int size, double aveKmsPerHour, double aveLayoverTimeHrs) {

    //calculates estimated distance over the total trip
    double distance = 0;
    for(int i = size; i > 0; i--){
        distance += getAirDistance(stops - i, stops - i + 1);
    }
    //gets the travel time over the whole trip distance
    double travelTime = distance / aveKmsPerHour + (aveLayoverTimeHrs * (size - 1));

    return travelTime;
}

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);

  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");

  int i, j;
  Airport temp;
  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByGPSId(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Type: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByType(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Name: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByName(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByNameDesc(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByCountryCity(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByLatitude(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");

  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if (cmpByLongitude(&airports[j], &airports[i]) > 0){
        temp = airports[i];
        airports[i] = airports[j];
        airports[j] = temp;
      }
    }
  }
  printAirports(airports, n);

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");



  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  //if none found, print: "No New York airport found!\n"

  printf("\nLarge airport: \n");
  printf("==============================\n");
  //if none found, print: "No large airport found!\n"


  return;
}

char* airportToString(const Airport* a) {
  char temp[1000];
  //this formatting is required but the code may need to be adapted
  // to your definiion of your Airport structure.
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}

void printAirports(Airport *airports, int n) {

  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }

  return;
}


int cmpByGPSId(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;

  if(t1 ->gpsId > t2 ->gpsId){
    return 1;
  }
  else if(t1 ->gpsId == t2 ->gpsId){
    return 0;
  }
  else{
    return -1;
  }
}

int cmpByType(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;
  return strcmp(t1->type, t2->type);
}

int cmpByName(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;
  return strcmp(t1->name, t2->name);
}

int cmpByNameDesc(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;
  return strcmp(t1->name, t2->name);
}

int cmpByCountryCity(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;
  if (strcmp(t1->countryAbbrv, t2->countryAbbrv) == 0) {
    return strcmp(t1->city, t2->city);
  } else {
    return strcmp(t1->countryAbbrv, t2->countryAbbrv);
  }
}

int cmpByLatitude(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;

  if(t1 ->latitude > t2 ->latitude){
    return 1;
  }
  else if(t1 ->latitude == t2 ->latitude){
    return 0;
  }
  else{
    return -1;
  }
}

int cmpByLongitude(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;

  if(t1 ->longitude > t2 ->longitude){
    return 1;
  }
  else if(t1 ->longitude == t2 ->longitude){
    return 0;
  }
  else{
    return -1;
  }
}

int cmpByLincolnDistance(const void* a, const void* b){

  const Airport *t1 = (const Airport *)a;
  const Airport *t2 = (const Airport *)b;

  if(t1 ->distance > t2 ->distance){
    return 1;
  }
  else if(t1 ->distance == t2 ->distance){
    return 0;
  }
  else{
    return -1;
  }
}

