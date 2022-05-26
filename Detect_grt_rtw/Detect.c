/*
 * Detect.c
 *
 * Code generation for model "Detect".
 *
 * Model version              : 1.19
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 27 01:17:32 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Detect.h"
#include "Detect_private.h"

/* Block states (default storage) */
DW_Detect_T Detect_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Detect_T Detect_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Detect_T Detect_Y;

/* Real-time model */
RT_MODEL_Detect_T Detect_M_;
RT_MODEL_Detect_T *const Detect_M = &Detect_M_;

/* Model step function */
void Detect_step(void)
{
  boolean_T rtb_Compare;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/U'
   */
  rtb_Compare = (Detect_U.U > Detect_P.Constant_Value);

  /* Outport: '<Root>/Y' incorporates:
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   */
  Detect_Y.Y = ((int32_T)rtb_Compare > (int32_T)Detect_DW.DelayInput1_DSTATE);

  /* Update for UnitDelay: '<S1>/Delay Input1' */
  Detect_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Detect_M->rtwLogInfo, (&Detect_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(Detect_M)!=-1) &&
        !((rtmGetTFinal(Detect_M)-Detect_M->Timing.taskTime0) >
          Detect_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Detect_M, "Simulation finished");
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
  if (!(++Detect_M->Timing.clockTick0)) {
    ++Detect_M->Timing.clockTickH0;
  }

  Detect_M->Timing.taskTime0 = Detect_M->Timing.clockTick0 *
    Detect_M->Timing.stepSize0 + Detect_M->Timing.clockTickH0 *
    Detect_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Detect_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Detect_M, 0,
                sizeof(RT_MODEL_Detect_T));
  rtmSetTFinal(Detect_M, 10.0);
  Detect_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Detect_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Detect_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Detect_M->rtwLogInfo, (NULL));
    rtliSetLogT(Detect_M->rtwLogInfo, "tout");
    rtliSetLogX(Detect_M->rtwLogInfo, "");
    rtliSetLogXFinal(Detect_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Detect_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Detect_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Detect_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Detect_M->rtwLogInfo, 1);
    rtliSetLogY(Detect_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Detect_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Detect_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Detect_DW, 0,
                sizeof(DW_Detect_T));

  /* external inputs */
  Detect_U.U = 0.0;

  /* external outputs */
  Detect_Y.Y = false;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Detect_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Detect_M), Detect_M->Timing.stepSize0, (&rtmGetErrorStatus(Detect_M)));

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1' */
  Detect_DW.DelayInput1_DSTATE = Detect_P.DetectRisePositive_vinit;
}

/* Model terminate function */
void Detect_terminate(void)
{
  /* (no terminate code required) */
}
