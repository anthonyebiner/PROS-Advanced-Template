#include "declareStuff.hpp"

/*
This is the initialization file for your program. You will want to put anything that you want to be done before the
driver control and autonomous peroids. This is also a good place to define all of you motors, sensors, controllers,
and variables
*/

Motor FrontRightM(1, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees); //(port, reversed, gearset, encoderUnits)
Motor FrontLeftM(2,  false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor BackRightM(3,  true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor BackLeftM(4,  false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor IntakeM(5,  true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor LiftM(6,  false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor Flywheel1M(9,  false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor Flywheel2M(10,  true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

Controller MasterC; //The name of your controller

ControllerButton intakeInButton(ControllerDigital::L1); //Define buttons here
ControllerButton intakeOutButton(ControllerDigital::L2);

ChassisControllerIntegrated drive = ChassisControllerFactory::create( //create a chassis that contains your drive motors
  {FrontLeftM, BackLeftM}, {FrontRightM, BackRightM}, //{Left motors}, {Right motors}
  AbstractMotor::gearset::green, //gearset
  {4.15_in, 14.5_in} //{wheel diameter, distance between wheels}
);

AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(LiftM); //creates a controller for the lift

MotorGroup flywheel({Flywheel1M,Flywheel2M}); //groups the two flywheel motors together so we can control them at the same time

AsyncMotionProfileController driveController = AsyncControllerFactory::motionProfile(0.75, 1.0, 5.0, drive); //creates a 2D motion profile controller


void initialize() {

}

void disabled() {

}

void competition_initialize() {

}
