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
	Task fw_ctrl(pid::fw::fw_pid);
}

void autonomous()
{
	(*auton).run();
}

void opcontrol() 
{
	int time = 0;
	bool chassis_on = true;

	while(true)
	{
		pid::fw::force_recovery = false;
		pid::fw_recover(true);
		if(chassis_on)
			arcade_drive();
			// tank_drive();
		intake_control();
		angle_control();
		flywheel_control(time);
		expansion(time);
		print_info(time, chassis_on);

		if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
			chassis_on = !chassis_on;
		if(con.get_digital(E_CONTROLLER_DIGITAL_UP) && chassis_on)
			autonomous();
		
		delay(10);
		time += 10;
	}
}