#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5586622557656464519) {
   out_5586622557656464519[0] = delta_x[0] + nom_x[0];
   out_5586622557656464519[1] = delta_x[1] + nom_x[1];
   out_5586622557656464519[2] = delta_x[2] + nom_x[2];
   out_5586622557656464519[3] = delta_x[3] + nom_x[3];
   out_5586622557656464519[4] = delta_x[4] + nom_x[4];
   out_5586622557656464519[5] = delta_x[5] + nom_x[5];
   out_5586622557656464519[6] = delta_x[6] + nom_x[6];
   out_5586622557656464519[7] = delta_x[7] + nom_x[7];
   out_5586622557656464519[8] = delta_x[8] + nom_x[8];
   out_5586622557656464519[9] = delta_x[9] + nom_x[9];
   out_5586622557656464519[10] = delta_x[10] + nom_x[10];
   out_5586622557656464519[11] = delta_x[11] + nom_x[11];
   out_5586622557656464519[12] = delta_x[12] + nom_x[12];
   out_5586622557656464519[13] = delta_x[13] + nom_x[13];
   out_5586622557656464519[14] = delta_x[14] + nom_x[14];
   out_5586622557656464519[15] = delta_x[15] + nom_x[15];
   out_5586622557656464519[16] = delta_x[16] + nom_x[16];
   out_5586622557656464519[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6540307311358214990) {
   out_6540307311358214990[0] = -nom_x[0] + true_x[0];
   out_6540307311358214990[1] = -nom_x[1] + true_x[1];
   out_6540307311358214990[2] = -nom_x[2] + true_x[2];
   out_6540307311358214990[3] = -nom_x[3] + true_x[3];
   out_6540307311358214990[4] = -nom_x[4] + true_x[4];
   out_6540307311358214990[5] = -nom_x[5] + true_x[5];
   out_6540307311358214990[6] = -nom_x[6] + true_x[6];
   out_6540307311358214990[7] = -nom_x[7] + true_x[7];
   out_6540307311358214990[8] = -nom_x[8] + true_x[8];
   out_6540307311358214990[9] = -nom_x[9] + true_x[9];
   out_6540307311358214990[10] = -nom_x[10] + true_x[10];
   out_6540307311358214990[11] = -nom_x[11] + true_x[11];
   out_6540307311358214990[12] = -nom_x[12] + true_x[12];
   out_6540307311358214990[13] = -nom_x[13] + true_x[13];
   out_6540307311358214990[14] = -nom_x[14] + true_x[14];
   out_6540307311358214990[15] = -nom_x[15] + true_x[15];
   out_6540307311358214990[16] = -nom_x[16] + true_x[16];
   out_6540307311358214990[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4655181558033116450) {
   out_4655181558033116450[0] = 1.0;
   out_4655181558033116450[1] = 0.0;
   out_4655181558033116450[2] = 0.0;
   out_4655181558033116450[3] = 0.0;
   out_4655181558033116450[4] = 0.0;
   out_4655181558033116450[5] = 0.0;
   out_4655181558033116450[6] = 0.0;
   out_4655181558033116450[7] = 0.0;
   out_4655181558033116450[8] = 0.0;
   out_4655181558033116450[9] = 0.0;
   out_4655181558033116450[10] = 0.0;
   out_4655181558033116450[11] = 0.0;
   out_4655181558033116450[12] = 0.0;
   out_4655181558033116450[13] = 0.0;
   out_4655181558033116450[14] = 0.0;
   out_4655181558033116450[15] = 0.0;
   out_4655181558033116450[16] = 0.0;
   out_4655181558033116450[17] = 0.0;
   out_4655181558033116450[18] = 0.0;
   out_4655181558033116450[19] = 1.0;
   out_4655181558033116450[20] = 0.0;
   out_4655181558033116450[21] = 0.0;
   out_4655181558033116450[22] = 0.0;
   out_4655181558033116450[23] = 0.0;
   out_4655181558033116450[24] = 0.0;
   out_4655181558033116450[25] = 0.0;
   out_4655181558033116450[26] = 0.0;
   out_4655181558033116450[27] = 0.0;
   out_4655181558033116450[28] = 0.0;
   out_4655181558033116450[29] = 0.0;
   out_4655181558033116450[30] = 0.0;
   out_4655181558033116450[31] = 0.0;
   out_4655181558033116450[32] = 0.0;
   out_4655181558033116450[33] = 0.0;
   out_4655181558033116450[34] = 0.0;
   out_4655181558033116450[35] = 0.0;
   out_4655181558033116450[36] = 0.0;
   out_4655181558033116450[37] = 0.0;
   out_4655181558033116450[38] = 1.0;
   out_4655181558033116450[39] = 0.0;
   out_4655181558033116450[40] = 0.0;
   out_4655181558033116450[41] = 0.0;
   out_4655181558033116450[42] = 0.0;
   out_4655181558033116450[43] = 0.0;
   out_4655181558033116450[44] = 0.0;
   out_4655181558033116450[45] = 0.0;
   out_4655181558033116450[46] = 0.0;
   out_4655181558033116450[47] = 0.0;
   out_4655181558033116450[48] = 0.0;
   out_4655181558033116450[49] = 0.0;
   out_4655181558033116450[50] = 0.0;
   out_4655181558033116450[51] = 0.0;
   out_4655181558033116450[52] = 0.0;
   out_4655181558033116450[53] = 0.0;
   out_4655181558033116450[54] = 0.0;
   out_4655181558033116450[55] = 0.0;
   out_4655181558033116450[56] = 0.0;
   out_4655181558033116450[57] = 1.0;
   out_4655181558033116450[58] = 0.0;
   out_4655181558033116450[59] = 0.0;
   out_4655181558033116450[60] = 0.0;
   out_4655181558033116450[61] = 0.0;
   out_4655181558033116450[62] = 0.0;
   out_4655181558033116450[63] = 0.0;
   out_4655181558033116450[64] = 0.0;
   out_4655181558033116450[65] = 0.0;
   out_4655181558033116450[66] = 0.0;
   out_4655181558033116450[67] = 0.0;
   out_4655181558033116450[68] = 0.0;
   out_4655181558033116450[69] = 0.0;
   out_4655181558033116450[70] = 0.0;
   out_4655181558033116450[71] = 0.0;
   out_4655181558033116450[72] = 0.0;
   out_4655181558033116450[73] = 0.0;
   out_4655181558033116450[74] = 0.0;
   out_4655181558033116450[75] = 0.0;
   out_4655181558033116450[76] = 1.0;
   out_4655181558033116450[77] = 0.0;
   out_4655181558033116450[78] = 0.0;
   out_4655181558033116450[79] = 0.0;
   out_4655181558033116450[80] = 0.0;
   out_4655181558033116450[81] = 0.0;
   out_4655181558033116450[82] = 0.0;
   out_4655181558033116450[83] = 0.0;
   out_4655181558033116450[84] = 0.0;
   out_4655181558033116450[85] = 0.0;
   out_4655181558033116450[86] = 0.0;
   out_4655181558033116450[87] = 0.0;
   out_4655181558033116450[88] = 0.0;
   out_4655181558033116450[89] = 0.0;
   out_4655181558033116450[90] = 0.0;
   out_4655181558033116450[91] = 0.0;
   out_4655181558033116450[92] = 0.0;
   out_4655181558033116450[93] = 0.0;
   out_4655181558033116450[94] = 0.0;
   out_4655181558033116450[95] = 1.0;
   out_4655181558033116450[96] = 0.0;
   out_4655181558033116450[97] = 0.0;
   out_4655181558033116450[98] = 0.0;
   out_4655181558033116450[99] = 0.0;
   out_4655181558033116450[100] = 0.0;
   out_4655181558033116450[101] = 0.0;
   out_4655181558033116450[102] = 0.0;
   out_4655181558033116450[103] = 0.0;
   out_4655181558033116450[104] = 0.0;
   out_4655181558033116450[105] = 0.0;
   out_4655181558033116450[106] = 0.0;
   out_4655181558033116450[107] = 0.0;
   out_4655181558033116450[108] = 0.0;
   out_4655181558033116450[109] = 0.0;
   out_4655181558033116450[110] = 0.0;
   out_4655181558033116450[111] = 0.0;
   out_4655181558033116450[112] = 0.0;
   out_4655181558033116450[113] = 0.0;
   out_4655181558033116450[114] = 1.0;
   out_4655181558033116450[115] = 0.0;
   out_4655181558033116450[116] = 0.0;
   out_4655181558033116450[117] = 0.0;
   out_4655181558033116450[118] = 0.0;
   out_4655181558033116450[119] = 0.0;
   out_4655181558033116450[120] = 0.0;
   out_4655181558033116450[121] = 0.0;
   out_4655181558033116450[122] = 0.0;
   out_4655181558033116450[123] = 0.0;
   out_4655181558033116450[124] = 0.0;
   out_4655181558033116450[125] = 0.0;
   out_4655181558033116450[126] = 0.0;
   out_4655181558033116450[127] = 0.0;
   out_4655181558033116450[128] = 0.0;
   out_4655181558033116450[129] = 0.0;
   out_4655181558033116450[130] = 0.0;
   out_4655181558033116450[131] = 0.0;
   out_4655181558033116450[132] = 0.0;
   out_4655181558033116450[133] = 1.0;
   out_4655181558033116450[134] = 0.0;
   out_4655181558033116450[135] = 0.0;
   out_4655181558033116450[136] = 0.0;
   out_4655181558033116450[137] = 0.0;
   out_4655181558033116450[138] = 0.0;
   out_4655181558033116450[139] = 0.0;
   out_4655181558033116450[140] = 0.0;
   out_4655181558033116450[141] = 0.0;
   out_4655181558033116450[142] = 0.0;
   out_4655181558033116450[143] = 0.0;
   out_4655181558033116450[144] = 0.0;
   out_4655181558033116450[145] = 0.0;
   out_4655181558033116450[146] = 0.0;
   out_4655181558033116450[147] = 0.0;
   out_4655181558033116450[148] = 0.0;
   out_4655181558033116450[149] = 0.0;
   out_4655181558033116450[150] = 0.0;
   out_4655181558033116450[151] = 0.0;
   out_4655181558033116450[152] = 1.0;
   out_4655181558033116450[153] = 0.0;
   out_4655181558033116450[154] = 0.0;
   out_4655181558033116450[155] = 0.0;
   out_4655181558033116450[156] = 0.0;
   out_4655181558033116450[157] = 0.0;
   out_4655181558033116450[158] = 0.0;
   out_4655181558033116450[159] = 0.0;
   out_4655181558033116450[160] = 0.0;
   out_4655181558033116450[161] = 0.0;
   out_4655181558033116450[162] = 0.0;
   out_4655181558033116450[163] = 0.0;
   out_4655181558033116450[164] = 0.0;
   out_4655181558033116450[165] = 0.0;
   out_4655181558033116450[166] = 0.0;
   out_4655181558033116450[167] = 0.0;
   out_4655181558033116450[168] = 0.0;
   out_4655181558033116450[169] = 0.0;
   out_4655181558033116450[170] = 0.0;
   out_4655181558033116450[171] = 1.0;
   out_4655181558033116450[172] = 0.0;
   out_4655181558033116450[173] = 0.0;
   out_4655181558033116450[174] = 0.0;
   out_4655181558033116450[175] = 0.0;
   out_4655181558033116450[176] = 0.0;
   out_4655181558033116450[177] = 0.0;
   out_4655181558033116450[178] = 0.0;
   out_4655181558033116450[179] = 0.0;
   out_4655181558033116450[180] = 0.0;
   out_4655181558033116450[181] = 0.0;
   out_4655181558033116450[182] = 0.0;
   out_4655181558033116450[183] = 0.0;
   out_4655181558033116450[184] = 0.0;
   out_4655181558033116450[185] = 0.0;
   out_4655181558033116450[186] = 0.0;
   out_4655181558033116450[187] = 0.0;
   out_4655181558033116450[188] = 0.0;
   out_4655181558033116450[189] = 0.0;
   out_4655181558033116450[190] = 1.0;
   out_4655181558033116450[191] = 0.0;
   out_4655181558033116450[192] = 0.0;
   out_4655181558033116450[193] = 0.0;
   out_4655181558033116450[194] = 0.0;
   out_4655181558033116450[195] = 0.0;
   out_4655181558033116450[196] = 0.0;
   out_4655181558033116450[197] = 0.0;
   out_4655181558033116450[198] = 0.0;
   out_4655181558033116450[199] = 0.0;
   out_4655181558033116450[200] = 0.0;
   out_4655181558033116450[201] = 0.0;
   out_4655181558033116450[202] = 0.0;
   out_4655181558033116450[203] = 0.0;
   out_4655181558033116450[204] = 0.0;
   out_4655181558033116450[205] = 0.0;
   out_4655181558033116450[206] = 0.0;
   out_4655181558033116450[207] = 0.0;
   out_4655181558033116450[208] = 0.0;
   out_4655181558033116450[209] = 1.0;
   out_4655181558033116450[210] = 0.0;
   out_4655181558033116450[211] = 0.0;
   out_4655181558033116450[212] = 0.0;
   out_4655181558033116450[213] = 0.0;
   out_4655181558033116450[214] = 0.0;
   out_4655181558033116450[215] = 0.0;
   out_4655181558033116450[216] = 0.0;
   out_4655181558033116450[217] = 0.0;
   out_4655181558033116450[218] = 0.0;
   out_4655181558033116450[219] = 0.0;
   out_4655181558033116450[220] = 0.0;
   out_4655181558033116450[221] = 0.0;
   out_4655181558033116450[222] = 0.0;
   out_4655181558033116450[223] = 0.0;
   out_4655181558033116450[224] = 0.0;
   out_4655181558033116450[225] = 0.0;
   out_4655181558033116450[226] = 0.0;
   out_4655181558033116450[227] = 0.0;
   out_4655181558033116450[228] = 1.0;
   out_4655181558033116450[229] = 0.0;
   out_4655181558033116450[230] = 0.0;
   out_4655181558033116450[231] = 0.0;
   out_4655181558033116450[232] = 0.0;
   out_4655181558033116450[233] = 0.0;
   out_4655181558033116450[234] = 0.0;
   out_4655181558033116450[235] = 0.0;
   out_4655181558033116450[236] = 0.0;
   out_4655181558033116450[237] = 0.0;
   out_4655181558033116450[238] = 0.0;
   out_4655181558033116450[239] = 0.0;
   out_4655181558033116450[240] = 0.0;
   out_4655181558033116450[241] = 0.0;
   out_4655181558033116450[242] = 0.0;
   out_4655181558033116450[243] = 0.0;
   out_4655181558033116450[244] = 0.0;
   out_4655181558033116450[245] = 0.0;
   out_4655181558033116450[246] = 0.0;
   out_4655181558033116450[247] = 1.0;
   out_4655181558033116450[248] = 0.0;
   out_4655181558033116450[249] = 0.0;
   out_4655181558033116450[250] = 0.0;
   out_4655181558033116450[251] = 0.0;
   out_4655181558033116450[252] = 0.0;
   out_4655181558033116450[253] = 0.0;
   out_4655181558033116450[254] = 0.0;
   out_4655181558033116450[255] = 0.0;
   out_4655181558033116450[256] = 0.0;
   out_4655181558033116450[257] = 0.0;
   out_4655181558033116450[258] = 0.0;
   out_4655181558033116450[259] = 0.0;
   out_4655181558033116450[260] = 0.0;
   out_4655181558033116450[261] = 0.0;
   out_4655181558033116450[262] = 0.0;
   out_4655181558033116450[263] = 0.0;
   out_4655181558033116450[264] = 0.0;
   out_4655181558033116450[265] = 0.0;
   out_4655181558033116450[266] = 1.0;
   out_4655181558033116450[267] = 0.0;
   out_4655181558033116450[268] = 0.0;
   out_4655181558033116450[269] = 0.0;
   out_4655181558033116450[270] = 0.0;
   out_4655181558033116450[271] = 0.0;
   out_4655181558033116450[272] = 0.0;
   out_4655181558033116450[273] = 0.0;
   out_4655181558033116450[274] = 0.0;
   out_4655181558033116450[275] = 0.0;
   out_4655181558033116450[276] = 0.0;
   out_4655181558033116450[277] = 0.0;
   out_4655181558033116450[278] = 0.0;
   out_4655181558033116450[279] = 0.0;
   out_4655181558033116450[280] = 0.0;
   out_4655181558033116450[281] = 0.0;
   out_4655181558033116450[282] = 0.0;
   out_4655181558033116450[283] = 0.0;
   out_4655181558033116450[284] = 0.0;
   out_4655181558033116450[285] = 1.0;
   out_4655181558033116450[286] = 0.0;
   out_4655181558033116450[287] = 0.0;
   out_4655181558033116450[288] = 0.0;
   out_4655181558033116450[289] = 0.0;
   out_4655181558033116450[290] = 0.0;
   out_4655181558033116450[291] = 0.0;
   out_4655181558033116450[292] = 0.0;
   out_4655181558033116450[293] = 0.0;
   out_4655181558033116450[294] = 0.0;
   out_4655181558033116450[295] = 0.0;
   out_4655181558033116450[296] = 0.0;
   out_4655181558033116450[297] = 0.0;
   out_4655181558033116450[298] = 0.0;
   out_4655181558033116450[299] = 0.0;
   out_4655181558033116450[300] = 0.0;
   out_4655181558033116450[301] = 0.0;
   out_4655181558033116450[302] = 0.0;
   out_4655181558033116450[303] = 0.0;
   out_4655181558033116450[304] = 1.0;
   out_4655181558033116450[305] = 0.0;
   out_4655181558033116450[306] = 0.0;
   out_4655181558033116450[307] = 0.0;
   out_4655181558033116450[308] = 0.0;
   out_4655181558033116450[309] = 0.0;
   out_4655181558033116450[310] = 0.0;
   out_4655181558033116450[311] = 0.0;
   out_4655181558033116450[312] = 0.0;
   out_4655181558033116450[313] = 0.0;
   out_4655181558033116450[314] = 0.0;
   out_4655181558033116450[315] = 0.0;
   out_4655181558033116450[316] = 0.0;
   out_4655181558033116450[317] = 0.0;
   out_4655181558033116450[318] = 0.0;
   out_4655181558033116450[319] = 0.0;
   out_4655181558033116450[320] = 0.0;
   out_4655181558033116450[321] = 0.0;
   out_4655181558033116450[322] = 0.0;
   out_4655181558033116450[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3836637758354497072) {
   out_3836637758354497072[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3836637758354497072[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3836637758354497072[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3836637758354497072[3] = dt*state[12] + state[3];
   out_3836637758354497072[4] = dt*state[13] + state[4];
   out_3836637758354497072[5] = dt*state[14] + state[5];
   out_3836637758354497072[6] = state[6];
   out_3836637758354497072[7] = state[7];
   out_3836637758354497072[8] = state[8];
   out_3836637758354497072[9] = state[9];
   out_3836637758354497072[10] = state[10];
   out_3836637758354497072[11] = state[11];
   out_3836637758354497072[12] = state[12];
   out_3836637758354497072[13] = state[13];
   out_3836637758354497072[14] = state[14];
   out_3836637758354497072[15] = state[15];
   out_3836637758354497072[16] = state[16];
   out_3836637758354497072[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6303441859094454629) {
   out_6303441859094454629[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6303441859094454629[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6303441859094454629[2] = 0;
   out_6303441859094454629[3] = 0;
   out_6303441859094454629[4] = 0;
   out_6303441859094454629[5] = 0;
   out_6303441859094454629[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6303441859094454629[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6303441859094454629[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6303441859094454629[9] = 0;
   out_6303441859094454629[10] = 0;
   out_6303441859094454629[11] = 0;
   out_6303441859094454629[12] = 0;
   out_6303441859094454629[13] = 0;
   out_6303441859094454629[14] = 0;
   out_6303441859094454629[15] = 0;
   out_6303441859094454629[16] = 0;
   out_6303441859094454629[17] = 0;
   out_6303441859094454629[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6303441859094454629[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6303441859094454629[20] = 0;
   out_6303441859094454629[21] = 0;
   out_6303441859094454629[22] = 0;
   out_6303441859094454629[23] = 0;
   out_6303441859094454629[24] = 0;
   out_6303441859094454629[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6303441859094454629[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6303441859094454629[27] = 0;
   out_6303441859094454629[28] = 0;
   out_6303441859094454629[29] = 0;
   out_6303441859094454629[30] = 0;
   out_6303441859094454629[31] = 0;
   out_6303441859094454629[32] = 0;
   out_6303441859094454629[33] = 0;
   out_6303441859094454629[34] = 0;
   out_6303441859094454629[35] = 0;
   out_6303441859094454629[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6303441859094454629[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6303441859094454629[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6303441859094454629[39] = 0;
   out_6303441859094454629[40] = 0;
   out_6303441859094454629[41] = 0;
   out_6303441859094454629[42] = 0;
   out_6303441859094454629[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6303441859094454629[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6303441859094454629[45] = 0;
   out_6303441859094454629[46] = 0;
   out_6303441859094454629[47] = 0;
   out_6303441859094454629[48] = 0;
   out_6303441859094454629[49] = 0;
   out_6303441859094454629[50] = 0;
   out_6303441859094454629[51] = 0;
   out_6303441859094454629[52] = 0;
   out_6303441859094454629[53] = 0;
   out_6303441859094454629[54] = 0;
   out_6303441859094454629[55] = 0;
   out_6303441859094454629[56] = 0;
   out_6303441859094454629[57] = 1;
   out_6303441859094454629[58] = 0;
   out_6303441859094454629[59] = 0;
   out_6303441859094454629[60] = 0;
   out_6303441859094454629[61] = 0;
   out_6303441859094454629[62] = 0;
   out_6303441859094454629[63] = 0;
   out_6303441859094454629[64] = 0;
   out_6303441859094454629[65] = 0;
   out_6303441859094454629[66] = dt;
   out_6303441859094454629[67] = 0;
   out_6303441859094454629[68] = 0;
   out_6303441859094454629[69] = 0;
   out_6303441859094454629[70] = 0;
   out_6303441859094454629[71] = 0;
   out_6303441859094454629[72] = 0;
   out_6303441859094454629[73] = 0;
   out_6303441859094454629[74] = 0;
   out_6303441859094454629[75] = 0;
   out_6303441859094454629[76] = 1;
   out_6303441859094454629[77] = 0;
   out_6303441859094454629[78] = 0;
   out_6303441859094454629[79] = 0;
   out_6303441859094454629[80] = 0;
   out_6303441859094454629[81] = 0;
   out_6303441859094454629[82] = 0;
   out_6303441859094454629[83] = 0;
   out_6303441859094454629[84] = 0;
   out_6303441859094454629[85] = dt;
   out_6303441859094454629[86] = 0;
   out_6303441859094454629[87] = 0;
   out_6303441859094454629[88] = 0;
   out_6303441859094454629[89] = 0;
   out_6303441859094454629[90] = 0;
   out_6303441859094454629[91] = 0;
   out_6303441859094454629[92] = 0;
   out_6303441859094454629[93] = 0;
   out_6303441859094454629[94] = 0;
   out_6303441859094454629[95] = 1;
   out_6303441859094454629[96] = 0;
   out_6303441859094454629[97] = 0;
   out_6303441859094454629[98] = 0;
   out_6303441859094454629[99] = 0;
   out_6303441859094454629[100] = 0;
   out_6303441859094454629[101] = 0;
   out_6303441859094454629[102] = 0;
   out_6303441859094454629[103] = 0;
   out_6303441859094454629[104] = dt;
   out_6303441859094454629[105] = 0;
   out_6303441859094454629[106] = 0;
   out_6303441859094454629[107] = 0;
   out_6303441859094454629[108] = 0;
   out_6303441859094454629[109] = 0;
   out_6303441859094454629[110] = 0;
   out_6303441859094454629[111] = 0;
   out_6303441859094454629[112] = 0;
   out_6303441859094454629[113] = 0;
   out_6303441859094454629[114] = 1;
   out_6303441859094454629[115] = 0;
   out_6303441859094454629[116] = 0;
   out_6303441859094454629[117] = 0;
   out_6303441859094454629[118] = 0;
   out_6303441859094454629[119] = 0;
   out_6303441859094454629[120] = 0;
   out_6303441859094454629[121] = 0;
   out_6303441859094454629[122] = 0;
   out_6303441859094454629[123] = 0;
   out_6303441859094454629[124] = 0;
   out_6303441859094454629[125] = 0;
   out_6303441859094454629[126] = 0;
   out_6303441859094454629[127] = 0;
   out_6303441859094454629[128] = 0;
   out_6303441859094454629[129] = 0;
   out_6303441859094454629[130] = 0;
   out_6303441859094454629[131] = 0;
   out_6303441859094454629[132] = 0;
   out_6303441859094454629[133] = 1;
   out_6303441859094454629[134] = 0;
   out_6303441859094454629[135] = 0;
   out_6303441859094454629[136] = 0;
   out_6303441859094454629[137] = 0;
   out_6303441859094454629[138] = 0;
   out_6303441859094454629[139] = 0;
   out_6303441859094454629[140] = 0;
   out_6303441859094454629[141] = 0;
   out_6303441859094454629[142] = 0;
   out_6303441859094454629[143] = 0;
   out_6303441859094454629[144] = 0;
   out_6303441859094454629[145] = 0;
   out_6303441859094454629[146] = 0;
   out_6303441859094454629[147] = 0;
   out_6303441859094454629[148] = 0;
   out_6303441859094454629[149] = 0;
   out_6303441859094454629[150] = 0;
   out_6303441859094454629[151] = 0;
   out_6303441859094454629[152] = 1;
   out_6303441859094454629[153] = 0;
   out_6303441859094454629[154] = 0;
   out_6303441859094454629[155] = 0;
   out_6303441859094454629[156] = 0;
   out_6303441859094454629[157] = 0;
   out_6303441859094454629[158] = 0;
   out_6303441859094454629[159] = 0;
   out_6303441859094454629[160] = 0;
   out_6303441859094454629[161] = 0;
   out_6303441859094454629[162] = 0;
   out_6303441859094454629[163] = 0;
   out_6303441859094454629[164] = 0;
   out_6303441859094454629[165] = 0;
   out_6303441859094454629[166] = 0;
   out_6303441859094454629[167] = 0;
   out_6303441859094454629[168] = 0;
   out_6303441859094454629[169] = 0;
   out_6303441859094454629[170] = 0;
   out_6303441859094454629[171] = 1;
   out_6303441859094454629[172] = 0;
   out_6303441859094454629[173] = 0;
   out_6303441859094454629[174] = 0;
   out_6303441859094454629[175] = 0;
   out_6303441859094454629[176] = 0;
   out_6303441859094454629[177] = 0;
   out_6303441859094454629[178] = 0;
   out_6303441859094454629[179] = 0;
   out_6303441859094454629[180] = 0;
   out_6303441859094454629[181] = 0;
   out_6303441859094454629[182] = 0;
   out_6303441859094454629[183] = 0;
   out_6303441859094454629[184] = 0;
   out_6303441859094454629[185] = 0;
   out_6303441859094454629[186] = 0;
   out_6303441859094454629[187] = 0;
   out_6303441859094454629[188] = 0;
   out_6303441859094454629[189] = 0;
   out_6303441859094454629[190] = 1;
   out_6303441859094454629[191] = 0;
   out_6303441859094454629[192] = 0;
   out_6303441859094454629[193] = 0;
   out_6303441859094454629[194] = 0;
   out_6303441859094454629[195] = 0;
   out_6303441859094454629[196] = 0;
   out_6303441859094454629[197] = 0;
   out_6303441859094454629[198] = 0;
   out_6303441859094454629[199] = 0;
   out_6303441859094454629[200] = 0;
   out_6303441859094454629[201] = 0;
   out_6303441859094454629[202] = 0;
   out_6303441859094454629[203] = 0;
   out_6303441859094454629[204] = 0;
   out_6303441859094454629[205] = 0;
   out_6303441859094454629[206] = 0;
   out_6303441859094454629[207] = 0;
   out_6303441859094454629[208] = 0;
   out_6303441859094454629[209] = 1;
   out_6303441859094454629[210] = 0;
   out_6303441859094454629[211] = 0;
   out_6303441859094454629[212] = 0;
   out_6303441859094454629[213] = 0;
   out_6303441859094454629[214] = 0;
   out_6303441859094454629[215] = 0;
   out_6303441859094454629[216] = 0;
   out_6303441859094454629[217] = 0;
   out_6303441859094454629[218] = 0;
   out_6303441859094454629[219] = 0;
   out_6303441859094454629[220] = 0;
   out_6303441859094454629[221] = 0;
   out_6303441859094454629[222] = 0;
   out_6303441859094454629[223] = 0;
   out_6303441859094454629[224] = 0;
   out_6303441859094454629[225] = 0;
   out_6303441859094454629[226] = 0;
   out_6303441859094454629[227] = 0;
   out_6303441859094454629[228] = 1;
   out_6303441859094454629[229] = 0;
   out_6303441859094454629[230] = 0;
   out_6303441859094454629[231] = 0;
   out_6303441859094454629[232] = 0;
   out_6303441859094454629[233] = 0;
   out_6303441859094454629[234] = 0;
   out_6303441859094454629[235] = 0;
   out_6303441859094454629[236] = 0;
   out_6303441859094454629[237] = 0;
   out_6303441859094454629[238] = 0;
   out_6303441859094454629[239] = 0;
   out_6303441859094454629[240] = 0;
   out_6303441859094454629[241] = 0;
   out_6303441859094454629[242] = 0;
   out_6303441859094454629[243] = 0;
   out_6303441859094454629[244] = 0;
   out_6303441859094454629[245] = 0;
   out_6303441859094454629[246] = 0;
   out_6303441859094454629[247] = 1;
   out_6303441859094454629[248] = 0;
   out_6303441859094454629[249] = 0;
   out_6303441859094454629[250] = 0;
   out_6303441859094454629[251] = 0;
   out_6303441859094454629[252] = 0;
   out_6303441859094454629[253] = 0;
   out_6303441859094454629[254] = 0;
   out_6303441859094454629[255] = 0;
   out_6303441859094454629[256] = 0;
   out_6303441859094454629[257] = 0;
   out_6303441859094454629[258] = 0;
   out_6303441859094454629[259] = 0;
   out_6303441859094454629[260] = 0;
   out_6303441859094454629[261] = 0;
   out_6303441859094454629[262] = 0;
   out_6303441859094454629[263] = 0;
   out_6303441859094454629[264] = 0;
   out_6303441859094454629[265] = 0;
   out_6303441859094454629[266] = 1;
   out_6303441859094454629[267] = 0;
   out_6303441859094454629[268] = 0;
   out_6303441859094454629[269] = 0;
   out_6303441859094454629[270] = 0;
   out_6303441859094454629[271] = 0;
   out_6303441859094454629[272] = 0;
   out_6303441859094454629[273] = 0;
   out_6303441859094454629[274] = 0;
   out_6303441859094454629[275] = 0;
   out_6303441859094454629[276] = 0;
   out_6303441859094454629[277] = 0;
   out_6303441859094454629[278] = 0;
   out_6303441859094454629[279] = 0;
   out_6303441859094454629[280] = 0;
   out_6303441859094454629[281] = 0;
   out_6303441859094454629[282] = 0;
   out_6303441859094454629[283] = 0;
   out_6303441859094454629[284] = 0;
   out_6303441859094454629[285] = 1;
   out_6303441859094454629[286] = 0;
   out_6303441859094454629[287] = 0;
   out_6303441859094454629[288] = 0;
   out_6303441859094454629[289] = 0;
   out_6303441859094454629[290] = 0;
   out_6303441859094454629[291] = 0;
   out_6303441859094454629[292] = 0;
   out_6303441859094454629[293] = 0;
   out_6303441859094454629[294] = 0;
   out_6303441859094454629[295] = 0;
   out_6303441859094454629[296] = 0;
   out_6303441859094454629[297] = 0;
   out_6303441859094454629[298] = 0;
   out_6303441859094454629[299] = 0;
   out_6303441859094454629[300] = 0;
   out_6303441859094454629[301] = 0;
   out_6303441859094454629[302] = 0;
   out_6303441859094454629[303] = 0;
   out_6303441859094454629[304] = 1;
   out_6303441859094454629[305] = 0;
   out_6303441859094454629[306] = 0;
   out_6303441859094454629[307] = 0;
   out_6303441859094454629[308] = 0;
   out_6303441859094454629[309] = 0;
   out_6303441859094454629[310] = 0;
   out_6303441859094454629[311] = 0;
   out_6303441859094454629[312] = 0;
   out_6303441859094454629[313] = 0;
   out_6303441859094454629[314] = 0;
   out_6303441859094454629[315] = 0;
   out_6303441859094454629[316] = 0;
   out_6303441859094454629[317] = 0;
   out_6303441859094454629[318] = 0;
   out_6303441859094454629[319] = 0;
   out_6303441859094454629[320] = 0;
   out_6303441859094454629[321] = 0;
   out_6303441859094454629[322] = 0;
   out_6303441859094454629[323] = 1;
}
void h_4(double *state, double *unused, double *out_5581430167932054779) {
   out_5581430167932054779[0] = state[6] + state[9];
   out_5581430167932054779[1] = state[7] + state[10];
   out_5581430167932054779[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_497336827005964285) {
   out_497336827005964285[0] = 0;
   out_497336827005964285[1] = 0;
   out_497336827005964285[2] = 0;
   out_497336827005964285[3] = 0;
   out_497336827005964285[4] = 0;
   out_497336827005964285[5] = 0;
   out_497336827005964285[6] = 1;
   out_497336827005964285[7] = 0;
   out_497336827005964285[8] = 0;
   out_497336827005964285[9] = 1;
   out_497336827005964285[10] = 0;
   out_497336827005964285[11] = 0;
   out_497336827005964285[12] = 0;
   out_497336827005964285[13] = 0;
   out_497336827005964285[14] = 0;
   out_497336827005964285[15] = 0;
   out_497336827005964285[16] = 0;
   out_497336827005964285[17] = 0;
   out_497336827005964285[18] = 0;
   out_497336827005964285[19] = 0;
   out_497336827005964285[20] = 0;
   out_497336827005964285[21] = 0;
   out_497336827005964285[22] = 0;
   out_497336827005964285[23] = 0;
   out_497336827005964285[24] = 0;
   out_497336827005964285[25] = 1;
   out_497336827005964285[26] = 0;
   out_497336827005964285[27] = 0;
   out_497336827005964285[28] = 1;
   out_497336827005964285[29] = 0;
   out_497336827005964285[30] = 0;
   out_497336827005964285[31] = 0;
   out_497336827005964285[32] = 0;
   out_497336827005964285[33] = 0;
   out_497336827005964285[34] = 0;
   out_497336827005964285[35] = 0;
   out_497336827005964285[36] = 0;
   out_497336827005964285[37] = 0;
   out_497336827005964285[38] = 0;
   out_497336827005964285[39] = 0;
   out_497336827005964285[40] = 0;
   out_497336827005964285[41] = 0;
   out_497336827005964285[42] = 0;
   out_497336827005964285[43] = 0;
   out_497336827005964285[44] = 1;
   out_497336827005964285[45] = 0;
   out_497336827005964285[46] = 0;
   out_497336827005964285[47] = 1;
   out_497336827005964285[48] = 0;
   out_497336827005964285[49] = 0;
   out_497336827005964285[50] = 0;
   out_497336827005964285[51] = 0;
   out_497336827005964285[52] = 0;
   out_497336827005964285[53] = 0;
}
void h_10(double *state, double *unused, double *out_5698097009222269922) {
   out_5698097009222269922[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5698097009222269922[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5698097009222269922[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_346835565707097471) {
   out_346835565707097471[0] = 0;
   out_346835565707097471[1] = 9.8100000000000005*cos(state[1]);
   out_346835565707097471[2] = 0;
   out_346835565707097471[3] = 0;
   out_346835565707097471[4] = -state[8];
   out_346835565707097471[5] = state[7];
   out_346835565707097471[6] = 0;
   out_346835565707097471[7] = state[5];
   out_346835565707097471[8] = -state[4];
   out_346835565707097471[9] = 0;
   out_346835565707097471[10] = 0;
   out_346835565707097471[11] = 0;
   out_346835565707097471[12] = 1;
   out_346835565707097471[13] = 0;
   out_346835565707097471[14] = 0;
   out_346835565707097471[15] = 1;
   out_346835565707097471[16] = 0;
   out_346835565707097471[17] = 0;
   out_346835565707097471[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_346835565707097471[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_346835565707097471[20] = 0;
   out_346835565707097471[21] = state[8];
   out_346835565707097471[22] = 0;
   out_346835565707097471[23] = -state[6];
   out_346835565707097471[24] = -state[5];
   out_346835565707097471[25] = 0;
   out_346835565707097471[26] = state[3];
   out_346835565707097471[27] = 0;
   out_346835565707097471[28] = 0;
   out_346835565707097471[29] = 0;
   out_346835565707097471[30] = 0;
   out_346835565707097471[31] = 1;
   out_346835565707097471[32] = 0;
   out_346835565707097471[33] = 0;
   out_346835565707097471[34] = 1;
   out_346835565707097471[35] = 0;
   out_346835565707097471[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_346835565707097471[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_346835565707097471[38] = 0;
   out_346835565707097471[39] = -state[7];
   out_346835565707097471[40] = state[6];
   out_346835565707097471[41] = 0;
   out_346835565707097471[42] = state[4];
   out_346835565707097471[43] = -state[3];
   out_346835565707097471[44] = 0;
   out_346835565707097471[45] = 0;
   out_346835565707097471[46] = 0;
   out_346835565707097471[47] = 0;
   out_346835565707097471[48] = 0;
   out_346835565707097471[49] = 0;
   out_346835565707097471[50] = 1;
   out_346835565707097471[51] = 0;
   out_346835565707097471[52] = 0;
   out_346835565707097471[53] = 1;
}
void h_13(double *state, double *unused, double *out_7289809049648311279) {
   out_7289809049648311279[0] = state[3];
   out_7289809049648311279[1] = state[4];
   out_7289809049648311279[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3709610652338297086) {
   out_3709610652338297086[0] = 0;
   out_3709610652338297086[1] = 0;
   out_3709610652338297086[2] = 0;
   out_3709610652338297086[3] = 1;
   out_3709610652338297086[4] = 0;
   out_3709610652338297086[5] = 0;
   out_3709610652338297086[6] = 0;
   out_3709610652338297086[7] = 0;
   out_3709610652338297086[8] = 0;
   out_3709610652338297086[9] = 0;
   out_3709610652338297086[10] = 0;
   out_3709610652338297086[11] = 0;
   out_3709610652338297086[12] = 0;
   out_3709610652338297086[13] = 0;
   out_3709610652338297086[14] = 0;
   out_3709610652338297086[15] = 0;
   out_3709610652338297086[16] = 0;
   out_3709610652338297086[17] = 0;
   out_3709610652338297086[18] = 0;
   out_3709610652338297086[19] = 0;
   out_3709610652338297086[20] = 0;
   out_3709610652338297086[21] = 0;
   out_3709610652338297086[22] = 1;
   out_3709610652338297086[23] = 0;
   out_3709610652338297086[24] = 0;
   out_3709610652338297086[25] = 0;
   out_3709610652338297086[26] = 0;
   out_3709610652338297086[27] = 0;
   out_3709610652338297086[28] = 0;
   out_3709610652338297086[29] = 0;
   out_3709610652338297086[30] = 0;
   out_3709610652338297086[31] = 0;
   out_3709610652338297086[32] = 0;
   out_3709610652338297086[33] = 0;
   out_3709610652338297086[34] = 0;
   out_3709610652338297086[35] = 0;
   out_3709610652338297086[36] = 0;
   out_3709610652338297086[37] = 0;
   out_3709610652338297086[38] = 0;
   out_3709610652338297086[39] = 0;
   out_3709610652338297086[40] = 0;
   out_3709610652338297086[41] = 1;
   out_3709610652338297086[42] = 0;
   out_3709610652338297086[43] = 0;
   out_3709610652338297086[44] = 0;
   out_3709610652338297086[45] = 0;
   out_3709610652338297086[46] = 0;
   out_3709610652338297086[47] = 0;
   out_3709610652338297086[48] = 0;
   out_3709610652338297086[49] = 0;
   out_3709610652338297086[50] = 0;
   out_3709610652338297086[51] = 0;
   out_3709610652338297086[52] = 0;
   out_3709610652338297086[53] = 0;
}
void h_14(double *state, double *unused, double *out_982976403773081971) {
   out_982976403773081971[0] = state[6];
   out_982976403773081971[1] = state[7];
   out_982976403773081971[2] = state[8];
}
void H_14(double *state, double *unused, double *out_62220300361080686) {
   out_62220300361080686[0] = 0;
   out_62220300361080686[1] = 0;
   out_62220300361080686[2] = 0;
   out_62220300361080686[3] = 0;
   out_62220300361080686[4] = 0;
   out_62220300361080686[5] = 0;
   out_62220300361080686[6] = 1;
   out_62220300361080686[7] = 0;
   out_62220300361080686[8] = 0;
   out_62220300361080686[9] = 0;
   out_62220300361080686[10] = 0;
   out_62220300361080686[11] = 0;
   out_62220300361080686[12] = 0;
   out_62220300361080686[13] = 0;
   out_62220300361080686[14] = 0;
   out_62220300361080686[15] = 0;
   out_62220300361080686[16] = 0;
   out_62220300361080686[17] = 0;
   out_62220300361080686[18] = 0;
   out_62220300361080686[19] = 0;
   out_62220300361080686[20] = 0;
   out_62220300361080686[21] = 0;
   out_62220300361080686[22] = 0;
   out_62220300361080686[23] = 0;
   out_62220300361080686[24] = 0;
   out_62220300361080686[25] = 1;
   out_62220300361080686[26] = 0;
   out_62220300361080686[27] = 0;
   out_62220300361080686[28] = 0;
   out_62220300361080686[29] = 0;
   out_62220300361080686[30] = 0;
   out_62220300361080686[31] = 0;
   out_62220300361080686[32] = 0;
   out_62220300361080686[33] = 0;
   out_62220300361080686[34] = 0;
   out_62220300361080686[35] = 0;
   out_62220300361080686[36] = 0;
   out_62220300361080686[37] = 0;
   out_62220300361080686[38] = 0;
   out_62220300361080686[39] = 0;
   out_62220300361080686[40] = 0;
   out_62220300361080686[41] = 0;
   out_62220300361080686[42] = 0;
   out_62220300361080686[43] = 0;
   out_62220300361080686[44] = 1;
   out_62220300361080686[45] = 0;
   out_62220300361080686[46] = 0;
   out_62220300361080686[47] = 0;
   out_62220300361080686[48] = 0;
   out_62220300361080686[49] = 0;
   out_62220300361080686[50] = 0;
   out_62220300361080686[51] = 0;
   out_62220300361080686[52] = 0;
   out_62220300361080686[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_5586622557656464519) {
  err_fun(nom_x, delta_x, out_5586622557656464519);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6540307311358214990) {
  inv_err_fun(nom_x, true_x, out_6540307311358214990);
}
void pose_H_mod_fun(double *state, double *out_4655181558033116450) {
  H_mod_fun(state, out_4655181558033116450);
}
void pose_f_fun(double *state, double dt, double *out_3836637758354497072) {
  f_fun(state,  dt, out_3836637758354497072);
}
void pose_F_fun(double *state, double dt, double *out_6303441859094454629) {
  F_fun(state,  dt, out_6303441859094454629);
}
void pose_h_4(double *state, double *unused, double *out_5581430167932054779) {
  h_4(state, unused, out_5581430167932054779);
}
void pose_H_4(double *state, double *unused, double *out_497336827005964285) {
  H_4(state, unused, out_497336827005964285);
}
void pose_h_10(double *state, double *unused, double *out_5698097009222269922) {
  h_10(state, unused, out_5698097009222269922);
}
void pose_H_10(double *state, double *unused, double *out_346835565707097471) {
  H_10(state, unused, out_346835565707097471);
}
void pose_h_13(double *state, double *unused, double *out_7289809049648311279) {
  h_13(state, unused, out_7289809049648311279);
}
void pose_H_13(double *state, double *unused, double *out_3709610652338297086) {
  H_13(state, unused, out_3709610652338297086);
}
void pose_h_14(double *state, double *unused, double *out_982976403773081971) {
  h_14(state, unused, out_982976403773081971);
}
void pose_H_14(double *state, double *unused, double *out_62220300361080686) {
  H_14(state, unused, out_62220300361080686);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
