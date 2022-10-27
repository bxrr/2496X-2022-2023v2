#include "main.h"
#include "global.h"
#include "driver.h"
#include "auton.h"
#include "pid.h"
#include "lib/auton_obj.h"

using namespace glb;
using namespace pros;


void initialize() 
{
	lcd::initialize();
	con.clear();
	static Auton temp = auton_selector(autons);
	auton = &temp;

	// tasks
	Task fw_ctrl(pid::spin_flywheel);
}

void autonomous()
{
	(*auton).run();
}

void opcontrol() 
{
	int time = 0;

	while(true)
	{
		arcade_drive();
		flywheel_control();

		if(con.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			autonomous();
		if(con.get_digital(E_CONTROLLER_DIGITAL_LEFT))
			calibrate_robot();
		
		delay(10);
		time += 10;
	}
}