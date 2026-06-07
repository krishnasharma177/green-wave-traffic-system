#include <stdio.h>
#include <math.h>

/*
   Function:
   Finds the fastest speed that allows a vehicle
   to reach the next traffic signal during green light.
*/

double calculateIdealSpeed(double distance, double cycleTime, double offset)
{
    const double minSpeed = 5.0;   // Minimum allowed speed (m/s)
    const double maxSpeed = 13.0;  // Maximum allowed speed (m/s)

    // Check speeds from maximum to minimum
    for(double speed = maxSpeed; speed >= minSpeed; speed -= 0.1)
    {
        // Calculate travel time
        double travelTime = distance / speed;

        /*
           Find arrival position in signal cycle
           fmod helps handle repeating cycles
        */
        double modTime =
        fmod(travelTime - offset + cycleTime, cycleTime);

        /*
           Assumption:
           First half cycle = GREEN
           Second half cycle = RED
        */

        if(modTime < (cycleTime / 2.0))
        {
            return speed;
        }
    }

    // No valid speed found
    return -1;
}

int main()
{
    double distance;
    double cycleTime;
    double offset;
    double idealSpeed;

    printf("===== Smart Traffic Speed Optimizer =====\n");

    printf("Enter distance between lights (meters): ");
    scanf("%lf", &distance);

    printf("Enter traffic light cycle time (seconds): ");
    scanf("%lf", &cycleTime);

    printf("Enter offset time (seconds): ");
    scanf("%lf", &offset);

    // Call function
    idealSpeed =
    calculateIdealSpeed(distance, cycleTime, offset);

    if(idealSpeed != -1)
    {
        printf("\nIdeal Speed: %.2lf m/s\n", idealSpeed);

        printf("Approx Speed: %.2lf km/h\n",
               idealSpeed * 3.6);
    }
    else
    {
        printf("\nNo suitable speed found.\n");
    }

    printf("\nProgram Finished Successfully.\n");

    return 0;
}
