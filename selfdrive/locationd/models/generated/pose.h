#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5586622557656464519);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6540307311358214990);
void pose_H_mod_fun(double *state, double *out_4655181558033116450);
void pose_f_fun(double *state, double dt, double *out_3836637758354497072);
void pose_F_fun(double *state, double dt, double *out_6303441859094454629);
void pose_h_4(double *state, double *unused, double *out_5581430167932054779);
void pose_H_4(double *state, double *unused, double *out_497336827005964285);
void pose_h_10(double *state, double *unused, double *out_5698097009222269922);
void pose_H_10(double *state, double *unused, double *out_346835565707097471);
void pose_h_13(double *state, double *unused, double *out_7289809049648311279);
void pose_H_13(double *state, double *unused, double *out_3709610652338297086);
void pose_h_14(double *state, double *unused, double *out_982976403773081971);
void pose_H_14(double *state, double *unused, double *out_62220300361080686);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}