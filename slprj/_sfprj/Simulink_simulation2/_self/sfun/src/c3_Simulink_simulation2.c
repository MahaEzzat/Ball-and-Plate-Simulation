/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Simulink_simulation2_sfun.h"
#include "c3_Simulink_simulation2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Simulink_simulation2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[17] = { "kx1", "ky1", "kx2", "ky2",
  "nargin", "nargout", "Case", "t", "x1", "y1", "r", "x0", "y0", "x", "y", "ex",
  "ey" };

/* Function Declarations */
static void initialize_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void initialize_params_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void enable_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void disable_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void set_sim_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void sf_gateway_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void c3_chartstep_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void initSimStructsc3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_ey, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static real_T c3_linspace(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_d2);
static void c3_eml_scalar_eg(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance);
static real_T c3_rdivide(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_x, real_T c3_y);
static real_T c3_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a);
static void c3_eml_error(SFc3_Simulink_simulation2InstanceStruct *chartInstance);
static void c3_b_eml_error(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance);
static real_T c3_b_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a);
static real_T c3_c_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a);
static real_T c3_d_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a);
static real_T c3_cosd(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x);
static boolean_T c3_isfinite(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, real_T c3_x);
static real_T c3_sind(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x);
static real_T c3_norm(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Simulink_simulation2, const
  char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_cosd(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T *c3_x);
static void c3_b_sind(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T *c3_x);
static void init_dsm_address_info(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Simulink_simulation2 = 0U;
}

static void initialize_params_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T *c3_ex;
  real_T *c3_ey;
  real_T *c3_x;
  real_T *c3_g_y;
  c3_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(5, 1), false);
  c3_hoistedGlobal = *c3_ex;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_ey;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_x;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_g_y;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_Simulink_simulation2;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_ex;
  real_T *c3_ey;
  real_T *c3_x;
  real_T *c3_y;
  c3_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *c3_ex = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "ex");
  *c3_ey = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "ey");
  *c3_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "x");
  *c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "y");
  chartInstance->c3_is_active_c3_Simulink_simulation2 = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_active_c3_Simulink_simulation2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Simulink_simulation2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  real_T *c3_Case;
  real_T *c3_t;
  real_T *c3_x1;
  real_T *c3_x;
  real_T *c3_y1;
  real_T *c3_r;
  real_T *c3_x0;
  real_T *c3_y0;
  real_T *c3_y;
  real_T *c3_ex;
  real_T *c3_ey;
  c3_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_y0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_x0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_y1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_Case = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_Case, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_t, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_x1, 2U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Simulink_simulation2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Simulink_simulation2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c3_x, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_y1, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_r, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_x0, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_y0, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_y, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_ex, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_ey, 10U);
}

static void c3_chartstep_c3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_Case;
  real_T c3_t;
  real_T c3_x1;
  real_T c3_y1;
  real_T c3_r;
  real_T c3_x0;
  real_T c3_y0;
  uint32_T c3_debug_family_var_map[17];
  real_T c3_kx1;
  real_T c3_ky1;
  real_T c3_kx2;
  real_T c3_ky2;
  real_T c3_nargin = 7.0;
  real_T c3_nargout = 4.0;
  real_T c3_x;
  real_T c3_y;
  real_T c3_ex;
  real_T c3_ey;
  real_T c3_A;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_b_A;
  real_T c3_B;
  real_T c3_g_x;
  real_T c3_c_y;
  real_T c3_h_x;
  real_T c3_d_y;
  real_T c3_i_x;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_c_A;
  real_T c3_b_B;
  real_T c3_l_x;
  real_T c3_g_y;
  real_T c3_m_x;
  real_T c3_h_y;
  real_T c3_n_x;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_d_A;
  real_T c3_c_B;
  real_T c3_q_x;
  real_T c3_k_y;
  real_T c3_r_x;
  real_T c3_l_y;
  real_T c3_s_x;
  real_T c3_m_y;
  real_T c3_n_y;
  real_T c3_e_A;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_o_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_f_A;
  real_T c3_d_B;
  real_T c3_y_x;
  real_T c3_p_y;
  real_T c3_ab_x;
  real_T c3_q_y;
  real_T c3_bb_x;
  real_T c3_r_y;
  real_T c3_s_y;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_g_A;
  real_T c3_e_B;
  real_T c3_eb_x;
  real_T c3_t_y;
  real_T c3_fb_x;
  real_T c3_u_y;
  real_T c3_gb_x;
  real_T c3_v_y;
  real_T c3_w_y;
  real_T c3_hb_x;
  real_T c3_ib_x;
  real_T c3_h_A;
  real_T c3_f_B;
  real_T c3_jb_x;
  real_T c3_x_y;
  real_T c3_kb_x;
  real_T c3_y_y;
  real_T c3_lb_x;
  real_T c3_ab_y;
  real_T c3_bb_y;
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_i_A;
  real_T c3_mb_x;
  real_T c3_nb_x;
  real_T c3_ob_x;
  real_T c3_cb_y;
  real_T c3_pb_x;
  real_T c3_qb_x;
  real_T c3_j_A;
  real_T c3_g_B;
  real_T c3_rb_x;
  real_T c3_db_y;
  real_T c3_sb_x;
  real_T c3_eb_y;
  real_T c3_tb_x;
  real_T c3_fb_y;
  real_T c3_gb_y;
  real_T c3_ub_x;
  real_T c3_vb_x;
  real_T c3_k_A;
  real_T c3_h_B;
  real_T c3_wb_x;
  real_T c3_hb_y;
  real_T c3_xb_x;
  real_T c3_ib_y;
  real_T c3_yb_x;
  real_T c3_jb_y;
  real_T c3_kb_y;
  real_T c3_ac_x;
  real_T c3_bc_x;
  real_T c3_l_A;
  real_T c3_i_B;
  real_T c3_cc_x;
  real_T c3_lb_y;
  real_T c3_dc_x;
  real_T c3_mb_y;
  real_T c3_ec_x;
  real_T c3_nb_y;
  real_T c3_ob_y;
  real_T c3_m_A;
  real_T c3_fc_x;
  real_T c3_gc_x;
  real_T c3_hc_x;
  real_T c3_pb_y;
  real_T c3_ic_x;
  real_T c3_jc_x;
  real_T c3_n_A;
  real_T c3_j_B;
  real_T c3_kc_x;
  real_T c3_qb_y;
  real_T c3_lc_x;
  real_T c3_rb_y;
  real_T c3_mc_x;
  real_T c3_sb_y;
  real_T c3_tb_y;
  real_T c3_nc_x;
  real_T c3_oc_x;
  real_T c3_o_A;
  real_T c3_k_B;
  real_T c3_pc_x;
  real_T c3_ub_y;
  real_T c3_qc_x;
  real_T c3_vb_y;
  real_T c3_rc_x;
  real_T c3_wb_y;
  real_T c3_xb_y;
  real_T c3_sc_x;
  real_T c3_tc_x;
  real_T c3_p_A;
  real_T c3_l_B;
  real_T c3_uc_x;
  real_T c3_yb_y;
  real_T c3_vc_x;
  real_T c3_ac_y;
  real_T c3_wc_x;
  real_T c3_bc_y;
  real_T c3_cc_y;
  real_T c3_q_A;
  real_T c3_xc_x;
  real_T c3_yc_x;
  real_T c3_ad_x;
  real_T c3_dc_y;
  real_T c3_bd_x;
  real_T c3_cd_x;
  real_T c3_r_A;
  real_T c3_m_B;
  real_T c3_dd_x;
  real_T c3_ec_y;
  real_T c3_ed_x;
  real_T c3_fc_y;
  real_T c3_fd_x;
  real_T c3_gc_y;
  real_T c3_hc_y;
  real_T c3_gd_x;
  real_T c3_hd_x;
  real_T c3_s_A;
  real_T c3_n_B;
  real_T c3_id_x;
  real_T c3_ic_y;
  real_T c3_jd_x;
  real_T c3_jc_y;
  real_T c3_kd_x;
  real_T c3_kc_y;
  real_T c3_lc_y;
  real_T c3_ld_x;
  real_T c3_md_x;
  real_T c3_t_A;
  real_T c3_o_B;
  real_T c3_nd_x;
  real_T c3_mc_y;
  real_T c3_od_x;
  real_T c3_nc_y;
  real_T c3_pd_x;
  real_T c3_oc_y;
  real_T c3_pc_y;
  real_T c3_u_A;
  real_T c3_qd_x;
  real_T c3_rd_x;
  real_T c3_sd_x;
  real_T c3_qc_y;
  real_T c3_td_x;
  real_T c3_ud_x;
  real_T c3_vd_x;
  real_T c3_wd_x;
  real_T c3_xd_x;
  real_T c3_rc_y;
  real_T c3_v_A;
  real_T c3_p_B;
  real_T c3_yd_x;
  real_T c3_sc_y;
  real_T c3_ae_x;
  real_T c3_tc_y;
  real_T c3_be_x;
  real_T c3_uc_y;
  real_T c3_vc_y;
  real_T c3_ce_x;
  real_T c3_de_x;
  real_T c3_ee_x;
  real_T c3_wc_y;
  real_T c3_fe_x;
  real_T c3_xc_y;
  real_T c3_ge_x;
  real_T c3_yc_y;
  real_T c3_he_x;
  real_T c3_ad_y;
  real_T c3_z;
  real_T c3_ie_x;
  real_T c3_je_x;
  real_T c3_ke_x;
  real_T c3_le_x;
  real_T c3_me_x;
  real_T c3_bd_y;
  real_T c3_ne_x;
  real_T c3_oe_x;
  real_T c3_pe_x;
  real_T c3_cd_y;
  real_T c3_w_A;
  real_T c3_q_B;
  real_T c3_qe_x;
  real_T c3_dd_y;
  real_T c3_re_x;
  real_T c3_ed_y;
  real_T c3_se_x;
  real_T c3_fd_y;
  real_T c3_gd_y;
  real_T c3_te_x;
  real_T c3_ue_x;
  real_T c3_ve_x;
  real_T c3_hd_y;
  real_T c3_we_x;
  real_T c3_id_y;
  real_T c3_xe_x;
  real_T c3_jd_y;
  real_T c3_ye_x;
  real_T c3_kd_y;
  real_T c3_b_z;
  real_T c3_af_x;
  real_T c3_bf_x;
  real_T c3_cf_x;
  real_T c3_df_x;
  real_T c3_ef_x;
  real_T c3_ld_y;
  real_T c3_ff_x;
  real_T c3_gf_x;
  real_T c3_hf_x;
  real_T c3_md_y;
  real_T c3_if_x;
  real_T c3_jf_x;
  real_T c3_kf_x;
  real_T c3_nd_y;
  real_T c3_lf_x;
  real_T c3_mf_x;
  real_T c3_nf_x;
  real_T c3_od_y;
  real_T c3_x_A;
  real_T c3_r_B;
  real_T c3_of_x;
  real_T c3_pd_y;
  real_T c3_pf_x;
  real_T c3_qd_y;
  real_T c3_qf_x;
  real_T c3_rd_y;
  real_T c3_sd_y;
  real_T *c3_b_ey;
  real_T *c3_b_ex;
  real_T *c3_td_y;
  real_T *c3_rf_x;
  real_T *c3_b_y0;
  real_T *c3_b_x0;
  real_T *c3_b_r;
  real_T *c3_b_y1;
  real_T *c3_b_x1;
  real_T *c3_b_t;
  real_T *c3_b_Case;
  c3_b_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_td_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_y0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_x0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_y1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_rf_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_Case = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_Case;
  c3_b_hoistedGlobal = *c3_b_t;
  c3_c_hoistedGlobal = *c3_b_x1;
  c3_d_hoistedGlobal = *c3_b_y1;
  c3_e_hoistedGlobal = *c3_b_r;
  c3_f_hoistedGlobal = *c3_b_x0;
  c3_g_hoistedGlobal = *c3_b_y0;
  c3_Case = c3_hoistedGlobal;
  c3_t = c3_b_hoistedGlobal;
  c3_x1 = c3_c_hoistedGlobal;
  c3_y1 = c3_d_hoistedGlobal;
  c3_r = c3_e_hoistedGlobal;
  c3_x0 = c3_f_hoistedGlobal;
  c3_y0 = c3_g_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_kx1, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ky1, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_kx2, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ky2, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Case, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_t, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_x1, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_y1, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_r, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_x0, 11U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_y0, 12U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ex, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ey, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  c3_t = c3_linspace(chartInstance, c3_t);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_A = 8.1243429E+7 * c3_x1;
  c3_b_x = c3_A;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  c3_b_y = c3_d_x / 8.125E+7;
  c3_e_x = -325000.0 * c3_t;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarExp(c3_f_x);
  c3_b_A = 4.5737168756571E+13 * c3_x1 * c3_f_x;
  c3_B = (1.71640625E+19 * c3_x1 - 5.28125E+13 * c3_mpower(chartInstance, 2.0 *
           c3_x1)) + 8.125E+7;
  c3_g_x = c3_b_A;
  c3_c_y = c3_B;
  c3_h_x = c3_g_x;
  c3_d_y = c3_c_y;
  c3_i_x = c3_h_x;
  c3_e_y = c3_d_y;
  c3_f_y = c3_i_x / c3_e_y;
  c3_j_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance, 2.0 * c3_x1));
  c3_k_x = c3_j_x;
  c3_k_x = muDoubleScalarExp(c3_k_x);
  c3_c_A = c3_k_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_x1) -
                      8.1243429E+7 * c3_c_mpower(chartInstance, 2.0 * c3_x1)) +
                     1.056164577E+14 * c3_d_mpower(chartInstance, c3_x1));
  c3_b_B = 500.0 * c3_x1 * ((2.1125E+11 * c3_x1 - 650000.0 * c3_mpower
    (chartInstance, 2.0 * c3_x1)) + 1.0);
  c3_l_x = c3_c_A;
  c3_g_y = c3_b_B;
  c3_m_x = c3_l_x;
  c3_h_y = c3_g_y;
  c3_n_x = c3_m_x;
  c3_i_y = c3_h_y;
  c3_j_y = c3_n_x / c3_i_y;
  c3_o_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance, 2.0 * c3_x1));
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarExp(c3_p_x);
  c3_d_A = c3_t * c3_p_x * (((8.1243429E+7 * c3_c_mpower(chartInstance, 2.0 *
    c3_x1) - 9.1474987460574E+13 * c3_b_mpower(chartInstance, c3_x1) * c3_mpower
                              (chartInstance, 2.0 * c3_x1)) + 2.8146E+8 *
    c3_b_mpower(chartInstance, c3_x1)) + 1.056164577E+14 * c3_d_mpower
    (chartInstance, c3_x1));
  c3_c_B = 500.0 * c3_x1 * c3_mpower(chartInstance, 2.0 * c3_x1) * ((2.1125E+11 *
    c3_x1 - 650000.0 * c3_mpower(chartInstance, 2.0 * c3_x1)) + 1.0);
  c3_q_x = c3_d_A;
  c3_k_y = c3_c_B;
  c3_r_x = c3_q_x;
  c3_l_y = c3_k_y;
  c3_s_x = c3_r_x;
  c3_m_y = c3_l_y;
  c3_n_y = c3_s_x / c3_m_y;
  c3_kx1 = ((c3_b_y + c3_f_y) - c3_j_y) - c3_n_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_e_A = 8.1243429E+7 * c3_y1;
  c3_t_x = c3_e_A;
  c3_u_x = c3_t_x;
  c3_v_x = c3_u_x;
  c3_o_y = c3_v_x / 8.125E+7;
  c3_w_x = -325000.0 * c3_t;
  c3_x_x = c3_w_x;
  c3_x_x = muDoubleScalarExp(c3_x_x);
  c3_f_A = 4.5737168756571E+13 * c3_y1 * c3_x_x;
  c3_d_B = (1.71640625E+19 * c3_y1 - 5.28125E+13 * c3_mpower(chartInstance, 2.0 *
             c3_y1)) + 8.125E+7;
  c3_y_x = c3_f_A;
  c3_p_y = c3_d_B;
  c3_ab_x = c3_y_x;
  c3_q_y = c3_p_y;
  c3_bb_x = c3_ab_x;
  c3_r_y = c3_q_y;
  c3_s_y = c3_bb_x / c3_r_y;
  c3_cb_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance, 2.0 *
    c3_y1));
  c3_db_x = c3_cb_x;
  c3_db_x = muDoubleScalarExp(c3_db_x);
  c3_g_A = c3_db_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_y1) -
                       8.1243429E+7 * c3_c_mpower(chartInstance, 2.0 * c3_y1)) +
                      1.056164577E+14 * c3_d_mpower(chartInstance, c3_y1));
  c3_e_B = 500.0 * c3_y1 * ((2.1125E+11 * c3_y1 - 650000.0 * c3_mpower
    (chartInstance, 2.0 * c3_y1)) + 1.0);
  c3_eb_x = c3_g_A;
  c3_t_y = c3_e_B;
  c3_fb_x = c3_eb_x;
  c3_u_y = c3_t_y;
  c3_gb_x = c3_fb_x;
  c3_v_y = c3_u_y;
  c3_w_y = c3_gb_x / c3_v_y;
  c3_hb_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance, 2.0 *
    c3_y1));
  c3_ib_x = c3_hb_x;
  c3_ib_x = muDoubleScalarExp(c3_ib_x);
  c3_h_A = c3_t * c3_ib_x * (((8.1243429E+7 * c3_c_mpower(chartInstance, 2.0 *
    c3_y1) - 9.1474987460574E+13 * c3_b_mpower(chartInstance, c3_y1) * c3_mpower
                               (chartInstance, 2.0 * c3_y1)) + 2.8146E+8 *
    c3_b_mpower(chartInstance, c3_y1)) + 1.056164577E+14 * c3_d_mpower
    (chartInstance, c3_y1));
  c3_f_B = 500.0 * c3_y1 * c3_mpower(chartInstance, 2.0 * c3_y1) * ((2.1125E+11 *
    c3_y1 - 650000.0 * c3_mpower(chartInstance, 2.0 * c3_y1)) + 1.0);
  c3_jb_x = c3_h_A;
  c3_x_y = c3_f_B;
  c3_kb_x = c3_jb_x;
  c3_y_y = c3_x_y;
  c3_lb_x = c3_kb_x;
  c3_ab_y = c3_y_y;
  c3_bb_y = c3_lb_x / c3_ab_y;
  c3_ky1 = ((c3_o_y + c3_s_y) - c3_w_y) - c3_bb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_kx2 = c3_kx1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_ky2 = c3_ky1;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  switch ((int32_T)_SFD_INTEGER_CHECK("Case", c3_Case)) {
   case 1:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_ex = c3_x1 - c3_kx2;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_ey = c3_y1 - c3_ky2;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
    if (CV_EML_IF(0, 1, 0, c3_t > 60.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
      c3_d0 = c3_t - 15.0;
      c3_b_cosd(chartInstance, &c3_d0);
      c3_x1 = c3_r * c3_d0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
      c3_d1 = c3_t - 15.0;
      c3_b_sind(chartInstance, &c3_d1);
      c3_y1 = c3_r * c3_d1;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
      c3_i_A = 8.1243429E+7 * c3_x1;
      c3_mb_x = c3_i_A;
      c3_nb_x = c3_mb_x;
      c3_ob_x = c3_nb_x;
      c3_cb_y = c3_ob_x / 8.125E+7;
      c3_pb_x = -325000.0 * c3_t;
      c3_qb_x = c3_pb_x;
      c3_qb_x = muDoubleScalarExp(c3_qb_x);
      c3_j_A = 4.5737168756571E+13 * c3_x1 * c3_qb_x;
      c3_g_B = (1.71640625E+19 * c3_x1 - 5.28125E+13 * c3_mpower(chartInstance,
                 c3_norm(chartInstance, 2.0 * c3_x1))) + 8.125E+7;
      c3_rb_x = c3_j_A;
      c3_db_y = c3_g_B;
      c3_sb_x = c3_rb_x;
      c3_eb_y = c3_db_y;
      c3_tb_x = c3_sb_x;
      c3_fb_y = c3_eb_y;
      c3_gb_y = c3_tb_x / c3_fb_y;
      c3_ub_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)));
      c3_vb_x = c3_ub_x;
      c3_vb_x = muDoubleScalarExp(c3_vb_x);
      c3_k_A = c3_vb_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_x1) -
                           8.1243429E+7 * c3_c_mpower(chartInstance, c3_norm
        (chartInstance, 2.0 * c3_x1))) + 1.056164577E+14 * c3_d_mpower
                          (chartInstance, c3_x1));
      c3_h_B = 500.0 * c3_x1 * ((2.1125E+11 * c3_x1 - 650000.0 * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1))) + 1.0);
      c3_wb_x = c3_k_A;
      c3_hb_y = c3_h_B;
      c3_xb_x = c3_wb_x;
      c3_ib_y = c3_hb_y;
      c3_yb_x = c3_xb_x;
      c3_jb_y = c3_ib_y;
      c3_kb_y = c3_yb_x / c3_jb_y;
      c3_ac_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)));
      c3_bc_x = c3_ac_x;
      c3_bc_x = muDoubleScalarExp(c3_bc_x);
      c3_l_A = c3_t * c3_bc_x * (((8.1243429E+7 * c3_c_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)) - 9.1474987460574E+13 * c3_b_mpower
                                   (chartInstance, c3_x1) * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1))) + 2.8146E+8 *
        c3_b_mpower(chartInstance, c3_x1)) + 1.056164577E+14 * c3_d_mpower
        (chartInstance, c3_x1));
      c3_i_B = 500.0 * c3_x1 * c3_mpower(chartInstance, c3_norm(chartInstance,
        2.0 * c3_x1)) * ((2.1125E+11 * c3_x1 - 650000.0 * c3_mpower
                          (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1)))
                         + 1.0);
      c3_cc_x = c3_l_A;
      c3_lb_y = c3_i_B;
      c3_dc_x = c3_cc_x;
      c3_mb_y = c3_lb_y;
      c3_ec_x = c3_dc_x;
      c3_nb_y = c3_mb_y;
      c3_ob_y = c3_ec_x / c3_nb_y;
      c3_kx1 = ((c3_cb_y + c3_gb_y) - c3_kb_y) - c3_ob_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
      c3_m_A = 8.1243429E+7 * c3_y1;
      c3_fc_x = c3_m_A;
      c3_gc_x = c3_fc_x;
      c3_hc_x = c3_gc_x;
      c3_pb_y = c3_hc_x / 8.125E+7;
      c3_ic_x = -325000.0 * c3_t;
      c3_jc_x = c3_ic_x;
      c3_jc_x = muDoubleScalarExp(c3_jc_x);
      c3_n_A = 4.5737168756571E+13 * c3_y1 * c3_jc_x;
      c3_j_B = (1.71640625E+19 * c3_y1 - 5.28125E+13 * c3_mpower(chartInstance,
                 c3_norm(chartInstance, 2.0 * c3_y1))) + 8.125E+7;
      c3_kc_x = c3_n_A;
      c3_qb_y = c3_j_B;
      c3_lc_x = c3_kc_x;
      c3_rb_y = c3_qb_y;
      c3_mc_x = c3_lc_x;
      c3_sb_y = c3_rb_y;
      c3_tb_y = c3_mc_x / c3_sb_y;
      c3_nc_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_y1)));
      c3_oc_x = c3_nc_x;
      c3_oc_x = muDoubleScalarExp(c3_oc_x);
      c3_o_A = c3_oc_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_y1) -
                           8.1243429E+7 * c3_c_mpower(chartInstance, c3_norm
        (chartInstance, 2.0 * c3_y1))) + 1.056164577E+14 * c3_d_mpower
                          (chartInstance, c3_y1));
      c3_k_B = 500.0 * c3_y1 * ((2.1125E+11 * c3_y1 - 650000.0 * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_y1))) + 1.0);
      c3_pc_x = c3_o_A;
      c3_ub_y = c3_k_B;
      c3_qc_x = c3_pc_x;
      c3_vb_y = c3_ub_y;
      c3_rc_x = c3_qc_x;
      c3_wb_y = c3_vb_y;
      c3_xb_y = c3_rc_x / c3_wb_y;
      c3_sc_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_y1)));
      c3_tc_x = c3_sc_x;
      c3_tc_x = muDoubleScalarExp(c3_tc_x);
      c3_p_A = c3_t * c3_tc_x * (((8.1243429E+7 * c3_c_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_y1)) - 9.1474987460574E+13 * c3_b_mpower
                                   (chartInstance, c3_y1) * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_y1))) + 2.8146E+8 *
        c3_b_mpower(chartInstance, c3_y1)) + 1.056164577E+14 * c3_d_mpower
        (chartInstance, c3_y1));
      c3_l_B = 500.0 * c3_y1 * c3_mpower(chartInstance, c3_norm(chartInstance,
        2.0 * c3_y1)) * ((2.1125E+11 * c3_y1 - 650000.0 * c3_mpower
                          (chartInstance, c3_norm(chartInstance, 2.0 * c3_y1)))
                         + 1.0);
      c3_uc_x = c3_p_A;
      c3_yb_y = c3_l_B;
      c3_vc_x = c3_uc_x;
      c3_ac_y = c3_yb_y;
      c3_wc_x = c3_vc_x;
      c3_bc_y = c3_ac_y;
      c3_cc_y = c3_wc_x / c3_bc_y;
      c3_ky1 = ((c3_pb_y + c3_tb_y) - c3_xb_y) - c3_cc_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
      c3_kx2 = c3_kx1;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
      c3_ky2 = c3_ky1;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
      c3_x1 = c3_r * 0.70710678118654757;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
      c3_y1 = c3_r * 0.70710678118654746;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
      c3_q_A = 8.1243429E+7 * c3_x1;
      c3_xc_x = c3_q_A;
      c3_yc_x = c3_xc_x;
      c3_ad_x = c3_yc_x;
      c3_dc_y = c3_ad_x / 8.125E+7;
      c3_bd_x = -325000.0 * c3_t;
      c3_cd_x = c3_bd_x;
      c3_cd_x = muDoubleScalarExp(c3_cd_x);
      c3_r_A = 4.5737168756571E+13 * c3_x1 * c3_cd_x;
      c3_m_B = (1.71640625E+19 * c3_x1 - 5.28125E+13 * c3_mpower(chartInstance,
                 c3_norm(chartInstance, 2.0 * c3_x1))) + 8.125E+7;
      c3_dd_x = c3_r_A;
      c3_ec_y = c3_m_B;
      c3_ed_x = c3_dd_x;
      c3_fc_y = c3_ec_y;
      c3_fd_x = c3_ed_x;
      c3_gc_y = c3_fc_y;
      c3_hc_y = c3_fd_x / c3_gc_y;
      c3_gd_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)));
      c3_hd_x = c3_gd_x;
      c3_hd_x = muDoubleScalarExp(c3_hd_x);
      c3_s_A = c3_hd_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_x1) -
                           8.1243429E+7 * c3_c_mpower(chartInstance, c3_norm
        (chartInstance, 2.0 * c3_x1))) + 1.056164577E+14 * c3_d_mpower
                          (chartInstance, c3_x1));
      c3_n_B = 500.0 * c3_x1 * ((2.1125E+11 * c3_x1 - 650000.0 * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1))) + 1.0);
      c3_id_x = c3_s_A;
      c3_ic_y = c3_n_B;
      c3_jd_x = c3_id_x;
      c3_jc_y = c3_ic_y;
      c3_kd_x = c3_jd_x;
      c3_kc_y = c3_jc_y;
      c3_lc_y = c3_kd_x / c3_kc_y;
      c3_ld_x = c3_rdivide(chartInstance, -c3_t, c3_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)));
      c3_md_x = c3_ld_x;
      c3_md_x = muDoubleScalarExp(c3_md_x);
      c3_t_A = c3_t * c3_md_x * (((8.1243429E+7 * c3_c_mpower(chartInstance,
        c3_norm(chartInstance, 2.0 * c3_x1)) - 9.1474987460574E+13 * c3_b_mpower
                                   (chartInstance, c3_x1) * c3_mpower
        (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1))) + 2.8146E+8 *
        c3_b_mpower(chartInstance, c3_x1)) + 1.056164577E+14 * c3_d_mpower
        (chartInstance, c3_x1));
      c3_o_B = 500.0 * c3_x1 * c3_mpower(chartInstance, c3_norm(chartInstance,
        2.0 * c3_x1)) * ((2.1125E+11 * c3_x1 - 650000.0 * c3_mpower
                          (chartInstance, c3_norm(chartInstance, 2.0 * c3_x1)))
                         + 1.0);
      c3_nd_x = c3_t_A;
      c3_mc_y = c3_o_B;
      c3_od_x = c3_nd_x;
      c3_nc_y = c3_mc_y;
      c3_pd_x = c3_od_x;
      c3_oc_y = c3_nc_y;
      c3_pc_y = c3_pd_x / c3_oc_y;
      c3_kx1 = ((c3_dc_y + c3_hc_y) - c3_lc_y) - c3_pc_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
      c3_kx2 = c3_kx1;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
      c3_u_A = 8.1243429E+7 * c3_y1;
      c3_qd_x = c3_u_A;
      c3_rd_x = c3_qd_x;
      c3_sd_x = c3_rd_x;
      c3_qc_y = c3_sd_x / 8.125E+7;
      c3_td_x = -325000.0 * c3_t;
      c3_ud_x = c3_td_x;
      c3_ud_x = muDoubleScalarExp(c3_ud_x);
      c3_vd_x = 2.0 * c3_y1;
      c3_wd_x = c3_vd_x;
      c3_xd_x = c3_wd_x;
      c3_rc_y = muDoubleScalarAbs(c3_xd_x);
      c3_v_A = 4.5737168756571E+13 * c3_y1 * c3_ud_x;
      c3_p_B = (1.71640625E+19 * c3_y1 - 5.28125E+13 * c3_mpower(chartInstance,
                 c3_rc_y)) + 8.125E+7;
      c3_yd_x = c3_v_A;
      c3_sc_y = c3_p_B;
      c3_ae_x = c3_yd_x;
      c3_tc_y = c3_sc_y;
      c3_be_x = c3_ae_x;
      c3_uc_y = c3_tc_y;
      c3_vc_y = c3_be_x / c3_uc_y;
      c3_ce_x = 2.0 * c3_y1;
      c3_de_x = c3_ce_x;
      c3_ee_x = c3_de_x;
      c3_wc_y = muDoubleScalarAbs(c3_ee_x);
      c3_fe_x = -c3_t;
      c3_xc_y = c3_mpower(chartInstance, c3_wc_y);
      c3_ge_x = c3_fe_x;
      c3_yc_y = c3_xc_y;
      c3_he_x = c3_ge_x;
      c3_ad_y = c3_yc_y;
      c3_z = c3_he_x / c3_ad_y;
      c3_ie_x = c3_z;
      c3_je_x = c3_ie_x;
      c3_je_x = muDoubleScalarExp(c3_je_x);
      c3_ke_x = 2.0 * c3_y1;
      c3_le_x = c3_ke_x;
      c3_me_x = c3_le_x;
      c3_bd_y = muDoubleScalarAbs(c3_me_x);
      c3_ne_x = 2.0 * c3_y1;
      c3_oe_x = c3_ne_x;
      c3_pe_x = c3_oe_x;
      c3_cd_y = muDoubleScalarAbs(c3_pe_x);
      c3_w_A = c3_je_x * ((2.8146E+8 * c3_b_mpower(chartInstance, c3_y1) -
                           8.1243429E+7 * c3_c_mpower(chartInstance, c3_bd_y)) +
                          1.056164577E+14 * c3_d_mpower(chartInstance, c3_y1));
      c3_q_B = 500.0 * c3_y1 * ((2.1125E+11 * c3_y1 - 650000.0 * c3_mpower
        (chartInstance, c3_cd_y)) + 1.0);
      c3_qe_x = c3_w_A;
      c3_dd_y = c3_q_B;
      c3_re_x = c3_qe_x;
      c3_ed_y = c3_dd_y;
      c3_se_x = c3_re_x;
      c3_fd_y = c3_ed_y;
      c3_gd_y = c3_se_x / c3_fd_y;
      c3_te_x = 2.0 * c3_y1;
      c3_ue_x = c3_te_x;
      c3_ve_x = c3_ue_x;
      c3_hd_y = muDoubleScalarAbs(c3_ve_x);
      c3_we_x = -c3_t;
      c3_id_y = c3_mpower(chartInstance, c3_hd_y);
      c3_xe_x = c3_we_x;
      c3_jd_y = c3_id_y;
      c3_ye_x = c3_xe_x;
      c3_kd_y = c3_jd_y;
      c3_b_z = c3_ye_x / c3_kd_y;
      c3_af_x = c3_b_z;
      c3_bf_x = c3_af_x;
      c3_bf_x = muDoubleScalarExp(c3_bf_x);
      c3_cf_x = 2.0 * c3_y1;
      c3_df_x = c3_cf_x;
      c3_ef_x = c3_df_x;
      c3_ld_y = muDoubleScalarAbs(c3_ef_x);
      c3_ff_x = 2.0 * c3_y1;
      c3_gf_x = c3_ff_x;
      c3_hf_x = c3_gf_x;
      c3_md_y = muDoubleScalarAbs(c3_hf_x);
      c3_if_x = 2.0 * c3_y1;
      c3_jf_x = c3_if_x;
      c3_kf_x = c3_jf_x;
      c3_nd_y = muDoubleScalarAbs(c3_kf_x);
      c3_lf_x = 2.0 * c3_y1;
      c3_mf_x = c3_lf_x;
      c3_nf_x = c3_mf_x;
      c3_od_y = muDoubleScalarAbs(c3_nf_x);
      c3_x_A = c3_t * c3_bf_x * (((8.1243429E+7 * c3_c_mpower(chartInstance,
        c3_ld_y) - 9.1474987460574E+13 * c3_b_mpower(chartInstance, c3_y1) *
        c3_mpower(chartInstance, c3_md_y)) + 2.8146E+8 * c3_b_mpower
        (chartInstance, c3_y1)) + 1.056164577E+14 * c3_d_mpower(chartInstance,
        c3_y1));
      c3_r_B = 500.0 * c3_y1 * c3_mpower(chartInstance, c3_nd_y) * ((2.1125E+11 *
        c3_y1 - 650000.0 * c3_mpower(chartInstance, c3_od_y)) + 1.0);
      c3_of_x = c3_x_A;
      c3_pd_y = c3_r_B;
      c3_pf_x = c3_of_x;
      c3_qd_y = c3_pd_y;
      c3_qf_x = c3_pf_x;
      c3_rd_y = c3_qd_y;
      c3_sd_y = c3_qf_x / c3_rd_y;
      c3_ky1 = ((c3_qc_y + c3_vc_y) - c3_gd_y) - c3_sd_y;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
      c3_ky2 = c3_ky1;
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  c3_x = c3_kx2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_y = c3_ky2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  c3_ex = c3_x1 - c3_kx2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  c3_ey = c3_y1 - c3_ky2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_rf_x = c3_x;
  *c3_td_y = c3_y;
  *c3_b_ex = c3_ex;
  *c3_b_ey = c3_ey;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Simulink_simulation2
  (SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Simulink_simulation2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_ey, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ey), &c3_thisId);
  sf_mex_destroy(&c3_ey);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_ey;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Simulink_simulation2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)chartInstanceVoid;
  c3_ey = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ey), &c3_thisId);
  sf_mex_destroy(&c3_ey);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Simulink_simulation2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 55, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  const mxArray *c3_rhs48 = NULL;
  const mxArray *c3_lhs48 = NULL;
  const mxArray *c3_rhs49 = NULL;
  const mxArray *c3_lhs49 = NULL;
  const mxArray *c3_rhs50 = NULL;
  const mxArray *c3_lhs50 = NULL;
  const mxArray *c3_rhs51 = NULL;
  const mxArray *c3_lhs51 = NULL;
  const mxArray *c3_rhs52 = NULL;
  const mxArray *c3_lhs52 = NULL;
  const mxArray *c3_rhs53 = NULL;
  const mxArray *c3_lhs53 = NULL;
  const mxArray *c3_rhs54 = NULL;
  const mxArray *c3_lhs54 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("linspace"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("exp"), "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837580U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_exp"), "name",
                  "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1301335664U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mpower"), "name", "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717478U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("ismatrix"), "name", "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1331308458U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("power"), "name", "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sqrt"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825938U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cosd"), "name", "name", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837572U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837578U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isfinite"), "name", "name", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isinf"), "name", "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825976U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837578U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rem"), "name", "name", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c3_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c3_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c3_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sind"), "name", "name", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c3_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343837578U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c3_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("norm"), "name", "name", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717468U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c3_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c3_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs54), "lhs", "lhs",
                  54);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
  sf_mex_destroy(&c3_rhs48);
  sf_mex_destroy(&c3_lhs48);
  sf_mex_destroy(&c3_rhs49);
  sf_mex_destroy(&c3_lhs49);
  sf_mex_destroy(&c3_rhs50);
  sf_mex_destroy(&c3_lhs50);
  sf_mex_destroy(&c3_rhs51);
  sf_mex_destroy(&c3_lhs51);
  sf_mex_destroy(&c3_rhs52);
  sf_mex_destroy(&c3_lhs52);
  sf_mex_destroy(&c3_rhs53);
  sf_mex_destroy(&c3_lhs53);
  sf_mex_destroy(&c3_rhs54);
  sf_mex_destroy(&c3_lhs54);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static real_T c3_linspace(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_d2)
{
  c3_eml_scalar_eg(chartInstance);
  return c3_d2;
}

static void c3_eml_scalar_eg(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_rdivide(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_x, real_T c3_y)
{
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_c_y;
  (void)chartInstance;
  c3_b_x = c3_x;
  c3_b_y = c3_y;
  c3_c_x = c3_b_x;
  c3_c_y = c3_b_y;
  return c3_c_x / c3_c_y;
}

static real_T c3_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a)
{
  real_T c3_c;
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_x;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  if (c3_ak < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  c3_x = c3_d_a;
  c3_c = c3_x;
  if (c3_c < 0.0) {
    c3_b_eml_error(chartInstance);
  }

  return muDoubleScalarSqrt(c3_c);
}

static void c3_eml_error(SFc3_Simulink_simulation2InstanceStruct *chartInstance)
{
  int32_T c3_i0;
  static char_T c3_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  for (c3_i0 = 0; c3_i0 < 31; c3_i0++) {
    c3_u[c3_i0] = c3_cv0[c3_i0];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_y));
}

static void c3_b_eml_error(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance)
{
  int32_T c3_i1;
  static char_T c3_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  int32_T c3_i2;
  static char_T c3_cv2[4] = { 's', 'q', 'r', 't' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  for (c3_i1 = 0; c3_i1 < 30; c3_i1++) {
    c3_u[c3_i1] = c3_cv1[c3_i1];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_b_u[c3_i2] = c3_cv2[c3_i2];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c3_y, 14, c3_b_y));
}

static real_T c3_b_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  return c3_d_a * c3_d_a;
}

static real_T c3_c_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_ar;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  if (c3_ak < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  c3_ar = c3_d_a;
  return muDoubleScalarPower(c3_ar, 2.5);
}

static real_T c3_d_mpower(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
  real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_ar;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  c3_ar = c3_d_a;
  return muDoubleScalarPower(c3_ar, 3.0);
}

static real_T c3_cosd(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_cosd(chartInstance, &c3_b_x);
  return c3_b_x;
}

static boolean_T c3_isfinite(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  boolean_T c3_b_b;
  boolean_T c3_b0;
  real_T c3_c_x;
  boolean_T c3_c_b;
  boolean_T c3_b1;
  (void)chartInstance;
  c3_b_x = c3_x;
  c3_b_b = muDoubleScalarIsInf(c3_b_x);
  c3_b0 = !c3_b_b;
  c3_c_x = c3_x;
  c3_c_b = muDoubleScalarIsNaN(c3_c_x);
  c3_b1 = !c3_c_b;
  return c3_b0 && c3_b1;
}

static real_T c3_sind(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sind(chartInstance, &c3_b_x);
  return c3_b_x;
}

static real_T c3_norm(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T c3_x)
{
  real_T c3_b_x;
  real_T c3_c_x;
  (void)chartInstance;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  return muDoubleScalarAbs(c3_c_x);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Simulink_simulation2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i3, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Simulink_simulation2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Simulink_simulation2, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Simulink_simulation2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Simulink_simulation2);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_cosd(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T *c3_x)
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_xk;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_absx;
  real_T c3_h_x;
  real_T c3_i_x;
  int8_T c3_n;
  int8_T c3_b_n;
  c3_b_x = *c3_x;
  if (!c3_isfinite(chartInstance, c3_b_x)) {
    *c3_x = rtNaN;
  } else {
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_e_x = c3_d_x;
    c3_eml_scalar_eg(chartInstance);
    c3_xk = c3_e_x;
    c3_d_x = muDoubleScalarRem(c3_xk, 360.0);
    c3_f_x = c3_d_x;
    c3_g_x = c3_f_x;
    c3_absx = muDoubleScalarAbs(c3_g_x);
    if (c3_absx > 180.0) {
      if (c3_d_x > 0.0) {
        c3_d_x -= 360.0;
      } else {
        c3_d_x += 360.0;
      }

      c3_h_x = c3_d_x;
      c3_i_x = c3_h_x;
      c3_absx = muDoubleScalarAbs(c3_i_x);
    }

    if (c3_absx <= 45.0) {
      c3_d_x *= 0.017453292519943295;
      c3_n = 0;
    } else if (c3_absx <= 135.0) {
      if (c3_d_x > 0.0) {
        c3_d_x = 0.017453292519943295 * (c3_d_x - 90.0);
        c3_n = 1;
      } else {
        c3_d_x = 0.017453292519943295 * (c3_d_x + 90.0);
        c3_n = -1;
      }
    } else if (c3_d_x > 0.0) {
      c3_d_x = 0.017453292519943295 * (c3_d_x - 180.0);
      c3_n = 2;
    } else {
      c3_d_x = 0.017453292519943295 * (c3_d_x + 180.0);
      c3_n = -2;
    }

    c3_b_n = c3_n;
    c3_b_x = c3_d_x;
    if ((real_T)c3_b_n == 0.0) {
      *c3_x = muDoubleScalarCos(c3_b_x);
    } else if ((real_T)c3_b_n == 1.0) {
      *c3_x = -muDoubleScalarSin(c3_b_x);
    } else if ((real_T)c3_b_n == -1.0) {
      *c3_x = muDoubleScalarSin(c3_b_x);
    } else {
      *c3_x = -muDoubleScalarCos(c3_b_x);
    }
  }
}

static void c3_b_sind(SFc3_Simulink_simulation2InstanceStruct *chartInstance,
                      real_T *c3_x)
{
  real_T c3_b_x;
  real_T c3_d3;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_xk;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_absx;
  real_T c3_h_x;
  real_T c3_i_x;
  int8_T c3_n;
  int8_T c3_b_n;
  c3_b_x = *c3_x;
  if (!c3_isfinite(chartInstance, c3_b_x)) {
    c3_d3 = rtNaN;
  } else {
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_e_x = c3_d_x;
    c3_eml_scalar_eg(chartInstance);
    c3_xk = c3_e_x;
    c3_d_x = muDoubleScalarRem(c3_xk, 360.0);
    c3_f_x = c3_d_x;
    c3_g_x = c3_f_x;
    c3_absx = muDoubleScalarAbs(c3_g_x);
    if (c3_absx > 180.0) {
      if (c3_d_x > 0.0) {
        c3_d_x -= 360.0;
      } else {
        c3_d_x += 360.0;
      }

      c3_h_x = c3_d_x;
      c3_i_x = c3_h_x;
      c3_absx = muDoubleScalarAbs(c3_i_x);
    }

    if (c3_absx <= 45.0) {
      c3_d_x *= 0.017453292519943295;
      c3_n = 0;
    } else if (c3_absx <= 135.0) {
      if (c3_d_x > 0.0) {
        c3_d_x = 0.017453292519943295 * (c3_d_x - 90.0);
        c3_n = 1;
      } else {
        c3_d_x = 0.017453292519943295 * (c3_d_x + 90.0);
        c3_n = -1;
      }
    } else if (c3_d_x > 0.0) {
      c3_d_x = 0.017453292519943295 * (c3_d_x - 180.0);
      c3_n = 2;
    } else {
      c3_d_x = 0.017453292519943295 * (c3_d_x + 180.0);
      c3_n = -2;
    }

    c3_b_n = c3_n;
    c3_b_x = c3_d_x;
    if ((real_T)c3_b_n == 0.0) {
      c3_d3 = muDoubleScalarSin(c3_b_x);
    } else if ((real_T)c3_b_n == 1.0) {
      c3_d3 = muDoubleScalarCos(c3_b_x);
    } else if ((real_T)c3_b_n == -1.0) {
      c3_d3 = -muDoubleScalarCos(c3_b_x);
    } else {
      c3_d3 = -muDoubleScalarSin(c3_b_x);
    }
  }

  *c3_x = c3_d3;
}

static void init_dsm_address_info(SFc3_Simulink_simulation2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Simulink_simulation2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(85511746U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1509287963U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1934073900U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1681983785U);
}

mxArray *sf_c3_Simulink_simulation2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ydb18dnad5g4mEylmrjXCE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Simulink_simulation2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Simulink_simulation2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_Simulink_simulation2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[14],T\"ex\",},{M[1],M[15],T\"ey\",},{M[1],M[5],T\"x\",},{M[1],M[13],T\"y\",},{M[8],M[0],T\"is_active_c3_Simulink_simulation2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Simulink_simulation2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Simulink_simulation2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulink_simulation2MachineNumber_,
           3,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Simulink_simulation2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Simulink_simulation2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Simulink_simulation2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Case");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x1");
          _SFD_SET_DATA_PROPS(3,2,0,1,"x");
          _SFD_SET_DATA_PROPS(4,1,1,0,"y1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"r");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x0");
          _SFD_SET_DATA_PROPS(7,1,1,0,"y0");
          _SFD_SET_DATA_PROPS(8,2,0,1,"y");
          _SFD_SET_DATA_PROPS(9,2,0,1,"ex");
          _SFD_SET_DATA_PROPS(10,2,0,1,"ey");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3584);
        _SFD_CV_INIT_EML_IF(0,1,0,1149,1156,2329,3501);

        {
          static int caseStart[] = { -1, 1074, 1125 };

          static int caseExprEnd[] = { 8, 1080, 1131 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,1057,1069,3529,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_Case;
          real_T *c3_t;
          real_T *c3_x1;
          real_T *c3_x;
          real_T *c3_y1;
          real_T *c3_r;
          real_T *c3_x0;
          real_T *c3_y0;
          real_T *c3_y;
          real_T *c3_ex;
          real_T *c3_ey;
          c3_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_y0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_x0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_y1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_Case = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Case);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_x1);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_y1);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_r);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_x0);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_y0);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_ex);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_ey);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Simulink_simulation2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "fVorDloix9pTfyUY7pxPiE";
}

static void sf_opaque_initialize_c3_Simulink_simulation2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Simulink_simulation2
    ((SFc3_Simulink_simulation2InstanceStruct*) chartInstanceVar);
  initialize_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_Simulink_simulation2(void *chartInstanceVar)
{
  enable_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_Simulink_simulation2(void *chartInstanceVar)
{
  disable_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_Simulink_simulation2(void *chartInstanceVar)
{
  sf_gateway_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Simulink_simulation2
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Simulink_simulation2
    ((SFc3_Simulink_simulation2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Simulink_simulation2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_Simulink_simulation2(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_Simulink_simulation2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Simulink_simulation2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_Simulink_simulation2(S);
}

static void sf_opaque_set_sim_state_c3_Simulink_simulation2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_Simulink_simulation2(S, st);
}

static void sf_opaque_terminate_c3_Simulink_simulation2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Simulink_simulation2InstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulink_simulation2_optimization_info();
    }

    finalize_c3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Simulink_simulation2((SFc3_Simulink_simulation2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Simulink_simulation2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_Simulink_simulation2
      ((SFc3_Simulink_simulation2InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Simulink_simulation2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Simulink_simulation2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1516163608U));
  ssSetChecksum1(S,(2463722400U));
  ssSetChecksum2(S,(1193327345U));
  ssSetChecksum3(S,(1778450056U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Simulink_simulation2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Simulink_simulation2(SimStruct *S)
{
  SFc3_Simulink_simulation2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_Simulink_simulation2InstanceStruct *)utMalloc(sizeof
    (SFc3_Simulink_simulation2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_Simulink_simulation2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Simulink_simulation2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Simulink_simulation2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Simulink_simulation2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Simulink_simulation2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Simulink_simulation2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Simulink_simulation2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Simulink_simulation2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Simulink_simulation2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Simulink_simulation2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Simulink_simulation2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Simulink_simulation2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_Simulink_simulation2_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Simulink_simulation2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Simulink_simulation2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Simulink_simulation2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Simulink_simulation2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
