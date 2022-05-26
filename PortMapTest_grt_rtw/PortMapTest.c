/*
 * PortMapTest.c
 *
 * Code generation for model "PortMapTest".
 *
 * Model version              : 1.20
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 27 01:32:40 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "PortMapTest.h"
#include "PortMapTest_private.h"

/* Block signals (default storage) */
B_PortMapTest_T PortMapTest_B;

/* Block states (default storage) */
DW_PortMapTest_T PortMapTest_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PortMapTest_T PortMapTest_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PortMapTest_T PortMapTest_Y;

/* Real-time model */
RT_MODEL_PortMapTest_T PortMapTest_M_;
RT_MODEL_PortMapTest_T *const PortMapTest_M = &PortMapTest_M_;

/* Model step function */
void PortMapTest_step(void)
{
  real_T currentTime;
  uint8_T y;
  uint8_T b_y;

  /* Outport: '<Root>/Position_Out' */
  PortMapTest_Y.Position_Out = 0.0;

  /* Outputs for Atomic SubSystem: '<S1>/Bit Concat' */
  /* Outputs for Atomic SubSystem: '<S5>/bc2' */
  /* MATLAB Function: '<S6>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant_Value_j;
  b_y = PortMapTest_P.Constant1_Value;
  PortMapTest_B.y_j = (uint8_T)(y << 1 | b_y);

  /* End of Outputs for SubSystem: '<S5>/bc2' */

  /* Outputs for Atomic SubSystem: '<S5>/bc3' */
  /* MATLAB Function: '<S7>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant2_Value;
  PortMapTest_B.y_cz = (uint8_T)(((PortMapTest_B.y_j & 7) << 1 & 7) | y);

  /* End of Outputs for SubSystem: '<S5>/bc3' */

  /* Outputs for Atomic SubSystem: '<S5>/bc4' */
  /* MATLAB Function: '<S8>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant3_Value;
  PortMapTest_B.y_k = (uint8_T)(((PortMapTest_B.y_cz & 15) << 1 & 15) | y);

  /* End of Outputs for SubSystem: '<S5>/bc4' */

  /* Outputs for Atomic SubSystem: '<S5>/bc5' */
  /* MATLAB Function: '<S9>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant4_Value;
  PortMapTest_B.y_c = (uint8_T)(((PortMapTest_B.y_k & 31) << 1 & 31) | y);

  /* End of Outputs for SubSystem: '<S5>/bc5' */

  /* Outputs for Atomic SubSystem: '<S5>/bc6' */
  /* MATLAB Function: '<S10>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant5_Value;
  PortMapTest_B.y_e = (uint8_T)(((PortMapTest_B.y_c & 63) << 1 & 63) | y);

  /* End of Outputs for SubSystem: '<S5>/bc6' */

  /* Outputs for Atomic SubSystem: '<S5>/bc7' */
  /* MATLAB Function: '<S11>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant7_Value;
  PortMapTest_B.y_d = (uint8_T)(((PortMapTest_B.y_e & 127) << 1 & 127) | y);

  /* End of Outputs for SubSystem: '<S5>/bc7' */

  /* Outputs for Atomic SubSystem: '<S5>/bc8' */
  /* MATLAB Function: '<S12>/bit_concat' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  /* :  y = bitconcat(cast_to_fi(u1), cast_to_fi(u2)); */
  y = PortMapTest_P.Constant6_Value;
  PortMapTest_B.y = (uint8_T)((uint8_T)(PortMapTest_B.y_d << 1) | y);

  /* End of Outputs for SubSystem: '<S5>/bc8' */
  /* End of Outputs for SubSystem: '<S1>/Bit Concat' */

  /* Step: '<Root>/Step' */
  currentTime = PortMapTest_M->Timing.t[0];
  if (currentTime < PortMapTest_P.Step_Time) {
    PortMapTest_B.Step = PortMapTest_P.Step_Y0;
  } else {
    PortMapTest_B.Step = PortMapTest_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  PortMapTest_B.Compare = (PortMapTest_B.Step > PortMapTest_P.Constant_Value);

  /* UnitDelay: '<S2>/Delay Input1' */
  PortMapTest_B.Uk1 = PortMapTest_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S2>/FixPt Relational Operator' */
  PortMapTest_B.FixPtRelationalOperator = ((int32_T)PortMapTest_B.Compare >
    (int32_T)PortMapTest_B.Uk1);

  /* Matfile logging */
  rt_UpdateTXYLogVars(PortMapTest_M->rtwLogInfo, (PortMapTest_M->Timing.t));

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  PortMapTest_DW.DelayInput1_DSTATE = PortMapTest_B.Compare;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(PortMapTest_M)!=-1) &&
        !((rtmGetTFinal(PortMapTest_M)-PortMapTest_M->Timing.t[0]) >
          PortMapTest_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(PortMapTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PortMapTest_M->Timing.clockTick0)) {
    ++PortMapTest_M->Timing.clockTickH0;
  }

  PortMapTest_M->Timing.t[0] = PortMapTest_M->Timing.clockTick0 *
    PortMapTest_M->Timing.stepSize0 + PortMapTest_M->Timing.clockTickH0 *
    PortMapTest_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    PortMapTest_M->Timing.clockTick1++;
    if (!PortMapTest_M->Timing.clockTick1) {
      PortMapTest_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void PortMapTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PortMapTest_M, 0,
                sizeof(RT_MODEL_PortMapTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PortMapTest_M->solverInfo,
                          &PortMapTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&PortMapTest_M->solverInfo, &rtmGetTPtr(PortMapTest_M));
    rtsiSetStepSizePtr(&PortMapTest_M->solverInfo,
                       &PortMapTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PortMapTest_M->solverInfo, (&rtmGetErrorStatus
      (PortMapTest_M)));
    rtsiSetRTModelPtr(&PortMapTest_M->solverInfo, PortMapTest_M);
  }

  rtsiSetSimTimeStep(&PortMapTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&PortMapTest_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PortMapTest_M, &PortMapTest_M->Timing.tArray[0]);
  rtmSetTFinal(PortMapTest_M, 10.0);
  PortMapTest_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PortMapTest_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PortMapTest_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PortMapTest_M->rtwLogInfo, (NULL));
    rtliSetLogT(PortMapTest_M->rtwLogInfo, "tout");
    rtliSetLogX(PortMapTest_M->rtwLogInfo, "");
    rtliSetLogXFinal(PortMapTest_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PortMapTest_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PortMapTest_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(PortMapTest_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PortMapTest_M->rtwLogInfo, 1);
    rtliSetLogY(PortMapTest_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PortMapTest_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PortMapTest_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &PortMapTest_B), 0,
                sizeof(B_PortMapTest_T));

  /* states (dwork) */
  (void) memset((void *)&PortMapTest_DW, 0,
                sizeof(DW_PortMapTest_T));

  /* external inputs */
  (void)memset(&PortMapTest_U, 0, sizeof(ExtU_PortMapTest_T));

  /* external outputs */
  PortMapTest_Y.Position_Out = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(PortMapTest_M->rtwLogInfo, 0.0, rtmGetTFinal
    (PortMapTest_M), PortMapTest_M->Timing.stepSize0, (&rtmGetErrorStatus
    (PortMapTest_M)));

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  PortMapTest_DW.DelayInput1_DSTATE = PortMapTest_P.DetectRisePositive_vinit;
}

/* Model terminate function */
void PortMapTest_terminate(void)
{
  /* (no terminate code required) */
}
