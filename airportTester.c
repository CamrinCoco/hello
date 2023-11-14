//TODO: Implement Test Cases when program works

#include <stdlib.h>
#include <stdio.h>

#include "airport.h"

int main(int argc, char **argv) {
    Airport * oneAirport = createAirport("HSND", "small_airport", "Shendi Airport", 16.70, 33.43, 1181, "Shendi", "SD-04");
    printf("%s", airportToString(oneAirport));

    return 0;
}
