#ifndef __GLOBAL__
#define __GLOBAL__

#include "main.h"
#include "lib/piston.h"
#include "lib/chassis.h"
#include "lib/auton_obj.h"


namespace glb
{
    // ports ===============================
    #define P_BL 9
    #define P_FL 8
    #define P_BR 3
    #define P_FR 2
    #define P_FLY_L 11
    #define P_FLY_R 12
    #define P_INTAKE_L 10
    #define P_INTAKE_R 1
    #define P_INTAKE_P 'A'
    #define P_ANGLE_P 'B'
    #define P_EXPANSION_P 'C'
    #define P_DISC_SENSOR_P 15

    #define P_IMU 7
    // objects =============================
    pros::Controller con(pros::E_CONTROLLER_MASTER);
    pros::Imu imu(P_IMU);
    pros::Motor flywheelL(P_FLY_L, pros::E_MOTOR_GEARSET_06, true);
    pros::Motor flywheelR(P_FLY_R, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor intakeL(P_INTAKE_L, pros::E_MOTOR_GEARSET_06, true);
    pros::Motor intakeR(P_INTAKE_R, pros::E_MOTOR_GEARSET_06, false);
    pros::Distance disc_sensor(P_DISC_SENSOR_P);

    Piston intakeP(P_INTAKE_P);
    Piston angleP(P_ANGLE_P);
    Piston expansionP(P_EXPANSION_P);
    Chassis chas({P_BL, -P_FL}, {P_BR, -P_FR}, pros::E_MOTOR_GEARSET_18, false);
    Auton *auton;
}

#endif