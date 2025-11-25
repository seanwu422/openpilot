#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3250407866236505369);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3600342458303032533);
void car_H_mod_fun(double *state, double *out_7154834726939235095);
void car_f_fun(double *state, double dt, double *out_24810897533838510);
void car_F_fun(double *state, double dt, double *out_7797320406800095423);
void car_h_25(double *state, double *unused, double *out_1337923375513180554);
void car_H_25(double *state, double *unused, double *out_8306752056234715744);
void car_h_24(double *state, double *unused, double *out_4060769754890208330);
void car_H_24(double *state, double *unused, double *out_73928478147420282);
void car_h_30(double *state, double *unused, double *out_1286963261403153967);
void car_H_30(double *state, double *unused, double *out_7621659058967587245);
void car_h_26(double *state, double *unused, double *out_8363471348040400509);
void car_H_26(double *state, double *unused, double *out_4565248737360659520);
void car_h_27(double *state, double *unused, double *out_6311421797798153788);
void car_H_27(double *state, double *unused, double *out_8650321702941539460);
void car_h_29(double *state, double *unused, double *out_8497872747657375478);
void car_H_29(double *state, double *unused, double *out_7111427714653195061);
void car_h_28(double *state, double *unused, double *out_5143677996722012051);
void car_H_28(double *state, double *unused, double *out_6252917341986825981);
void car_h_31(double *state, double *unused, double *out_5199606851941682206);
void car_H_31(double *state, double *unused, double *out_3939040635127308044);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}