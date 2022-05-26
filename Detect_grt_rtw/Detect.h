/*
 * Detect.h
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

#ifndef RTW_HEADER_Detect_h_
#define RTW_HEADER_Detect_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Detect_COMMON_INCLUDES_
# define Detect_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Detect_COMMON_INCLUDES_ */

#include "Detect_types.h"

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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
} DW_Detect_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T U;                            /* '<Root>/U' */
} ExtU_Detect_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Y;                         /* '<Root>/Y' */
} ExtY_Detect_T;

/* Parameters (default storage) */
struct P_Detect_T_ {
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S1>/Delay Input1'
                                      */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Detect_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Detect_T Detect_P;

/* Block states (default storage) */
extern DW_Detect_T Detect_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Detect_T Detect_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Detect_T Detect_Y;

/* Model entry point functions */
extern void Detect_initialize(void);
extern void Detect_step(void);
extern void Detect_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Detect_T *const Detect_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('PortMapTest/Detect Rise Positive')    - opens subsystem PortMapTest/Detect Rise Positive
 * hilite_system('PortMapTest/Detect Rise Positive/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PortMapTest'
 * '<S1>'   : 'PortMapTest/Detect Rise Positive'
 * '<S2>'   : 'PortMapTest/Detect Rise Positive/Positive'
 */
#endif                                 /* RTW_HEADER_Detect_h_ */
