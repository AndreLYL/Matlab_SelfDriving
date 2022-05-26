/*
 * PortMapTest.h
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

#ifndef RTW_HEADER_PortMapTest_h_
#define RTW_HEADER_PortMapTest_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PortMapTest_COMMON_INCLUDES_
# define PortMapTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* PortMapTest_COMMON_INCLUDES_ */

#include "PortMapTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Step;                         /* '<Root>/Step' */
  uint8_T y;                           /* '<S12>/bit_concat' */
  uint8_T y_d;                         /* '<S11>/bit_concat' */
  uint8_T y_e;                         /* '<S10>/bit_concat' */
  uint8_T y_c;                         /* '<S9>/bit_concat' */
  uint8_T y_k;                         /* '<S8>/bit_concat' */
  uint8_T y_cz;                        /* '<S7>/bit_concat' */
  uint8_T y_j;                         /* '<S6>/bit_concat' */
  boolean_T Compare;                   /* '<S20>/Compare' */
  boolean_T Uk1;                       /* '<S2>/Delay Input1' */
  boolean_T FixPtRelationalOperator;   /* '<S2>/FixPt Relational Operator' */
} B_PortMapTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
} DW_PortMapTest_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Speed;                        /* '<Root>/Speed' */
  real_T Position_In;                  /* '<Root>/Position_In' */
  real_T TimeGap;                      /* '<Root>/TimeGap' */
} ExtU_PortMapTest_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Position_Out;                 /* '<Root>/Position_Out' */
} ExtY_PortMapTest_T;

/* Parameters (default storage) */
struct P_PortMapTest_T_ {
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S2>/Delay Input1'
                                      */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  boolean_T Constant_Value_j;          /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  boolean_T Constant2_Value;           /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
  boolean_T Constant3_Value;           /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  boolean_T Constant4_Value;           /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  boolean_T Constant5_Value;           /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<Root>/Constant5'
                                        */
  boolean_T Constant7_Value;           /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<Root>/Constant7'
                                        */
  boolean_T Constant6_Value;           /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<Root>/Constant6'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PortMapTest_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PortMapTest_T PortMapTest_P;

/* Block signals (default storage) */
extern B_PortMapTest_T PortMapTest_B;

/* Block states (default storage) */
extern DW_PortMapTest_T PortMapTest_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PortMapTest_T PortMapTest_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PortMapTest_T PortMapTest_Y;

/* Model entry point functions */
extern void PortMapTest_initialize(void);
extern void PortMapTest_step(void);
extern void PortMapTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PortMapTest_T *const PortMapTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S1>/booleanConv' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv1' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv2' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv3' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv4' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv5' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv6' : Eliminate redundant data type conversion
 * Block '<S1>/booleanConv7' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PortMapTest'
 * '<S1>'   : 'PortMapTest/ActvReasonConcatSub'
 * '<S2>'   : 'PortMapTest/Detect Rise Positive'
 * '<S3>'   : 'PortMapTest/Subsystem'
 * '<S4>'   : 'PortMapTest/Subsystem1'
 * '<S5>'   : 'PortMapTest/ActvReasonConcatSub/Bit Concat'
 * '<S6>'   : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc2'
 * '<S7>'   : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc3'
 * '<S8>'   : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc4'
 * '<S9>'   : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc5'
 * '<S10>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc6'
 * '<S11>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc7'
 * '<S12>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc8'
 * '<S13>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc2/bit_concat'
 * '<S14>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc3/bit_concat'
 * '<S15>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc4/bit_concat'
 * '<S16>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc5/bit_concat'
 * '<S17>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc6/bit_concat'
 * '<S18>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc7/bit_concat'
 * '<S19>'  : 'PortMapTest/ActvReasonConcatSub/Bit Concat/bc8/bit_concat'
 * '<S20>'  : 'PortMapTest/Detect Rise Positive/Positive'
 */
#endif                                 /* RTW_HEADER_PortMapTest_h_ */
