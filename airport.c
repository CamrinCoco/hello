/* Authors: Camrin Coco and Jackson Wiese

Purpose: To create and establish structures for for use with the airport structure.
Also to create airpot fucntions using the structure.

Date: 11/10/2023

*/




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "airport.h"

Airport * createEmptyAirport() {
    return createAirport("", "", "", 0, 0, 0, "", "");
}

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

char* airportToString(const Airport* a) {
    if (a == NULL) {
        char *result = (char *)malloc(sizeof(char) * 7);
        strcpy(result, "(null)");
        return result;
    }
    char buffer[100];
    // compute the number of characters needed
    //int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) + 10 + 10 + 10 + strlen(a->city) + strlen(a->countryAbbrv);

    int n = snprintf(buffer, 100, "%s %s %s %lf %lf %d %s %s", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);
    // create a result string
    char *str = (char *)malloc(sizeof(char) * n);

    // format the aiport into the temporary string
    sprintf(str, "%s %s %s %.2lf %.2lf %d %s %s", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);

    return str;
}

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
