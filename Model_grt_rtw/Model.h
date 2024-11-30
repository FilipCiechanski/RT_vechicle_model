

        /*
    * Model.h
    *
            * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "Model".
    *
    * Model version              : 1.32
    * Simulink Coder version : 9.8 (R2022b) 13-May-2022
        * C++ source code generated on : Mon Dec 18 13:25:11 2023
 * 
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
    */


    #ifndef RTW_HEADER_Model_h_
    #define RTW_HEADER_Model_h_



                        #include "rtwtypes.h"
        #include "rtw_continuous.h"
        #include "rtw_solver.h"
        #include "rt_logging.h"




#include "Model_types.h"

extern "C" {

#include "rtGetInf.h"
}

extern "C" {

#include "rt_nonfinite.h"
}

#include <cfloat>

#include <cstring>


    

    

    

    
            /* Macros for accessing real-time model data structure */
                    #ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm) ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm) ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val) ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm) ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val) ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm) ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val) ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm) ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val) ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm) ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm) ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm) ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val) ((rtm)->derivs = (val))
#endif




        #ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm) (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) ((rtm)->Timing.t)
#endif


    







    

    

    

    

                    /* Block signals (default storage) */
                    
        struct B_Model_T {
        




                    
                    


                        



                            
                            
                                   real_T V_xms; /* '<S5>/Integrator3' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T SteeringangleFL; /* '<S2>/Switch' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T SteeringangleFR; /* '<S2>/Switch1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MotorTorque; /* '<S3>/Gain' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T BrakeTorque; /* '<S3>/Gain1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos; /* '<S12>/Cos' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos1; /* '<S12>/Cos1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin; /* '<S12>/Sin' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin1; /* '<S12>/Sin1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC1; /* '<S6>/IC1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YACCms2; /* '<S5>/Add1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T V_yms; /* '<S5>/IC1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos_p; /* '<S13>/Cos' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos1_a; /* '<S13>/Cos1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin_i; /* '<S13>/Sin' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin1_j; /* '<S13>/Sin1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC; /* '<S6>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos_b; /* '<S14>/Cos' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cos1_b; /* '<S14>/Cos1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin_ib; /* '<S14>/Sin' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Sin1_h; /* '<S14>/Sin1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC2; /* '<S6>/IC2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1; /* '<S34>/Gain1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_b; /* '<S35>/Gain1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_c; /* '<S36>/Gain1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_n; /* '<S37>/Gain1' */

                        
                        
                        


                    





        };

            
                /* Block states (default storage) for system '<Root>' */
                    
        struct DW_Model_T {
        




                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime; /* '<S5>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC2_FirstOutputTime; /* '<S5>/IC2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC4_FirstOutputTime; /* '<S19>/IC4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime_d; /* '<S34>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime_h; /* '<S35>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime_a; /* '<S37>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime_g; /* '<S36>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC5_FirstOutputTime; /* '<S19>/IC5' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC1_FirstOutputTime; /* '<S6>/IC1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC1_FirstOutputTime_d; /* '<S5>/IC1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_FirstOutputTime_f; /* '<S6>/IC' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC2_FirstOutputTime_j; /* '<S6>/IC2' */

                        
                        
                        


                    





        };

            
        
                /* Continuous states (default storage) */
                struct X_Model_T {
                            
                        real_T Integrator3_CSTATE; /* '<S5>/Integrator3' */
                    
                    
                        real_T Integrator6_CSTATE; /* '<S5>/Integrator6' */
                    
                    
                        real_T Integrator4_CSTATE; /* '<S5>/Integrator4' */
                    
                    
                        real_T Integrator2_CSTATE; /* '<S34>/Integrator2' */
                    
                    
                        real_T Integrator2_CSTATE_o; /* '<S35>/Integrator2' */
                    
                    
                        real_T Integrator1_CSTATE; /* '<S37>/Integrator1' */
                    
                    
                        real_T Integrator1_CSTATE_o; /* '<S36>/Integrator1' */
                    
                    
                        real_T Integrator_CSTATE; /* '<S5>/Integrator' */
                    
                    
                        real_T Integrator1_CSTATE_i; /* '<S5>/Integrator1' */
                    
                    
                        real_T Integrator2_CSTATE_i; /* '<S5>/Integrator2' */
                    
                    
                        real_T Integrator5_CSTATE; /* '<S5>/Integrator5' */
                    
                    
                        real_T Integrator7_CSTATE; /* '<S5>/Integrator7' */
                    
    
        };
        
                                /* State derivatives (default storage) */
                        struct XDot_Model_T {
                                
                        real_T Integrator3_CSTATE; /* '<S5>/Integrator3' */
                    
                    
                        real_T Integrator6_CSTATE; /* '<S5>/Integrator6' */
                    
                    
                        real_T Integrator4_CSTATE; /* '<S5>/Integrator4' */
                    
                    
                        real_T Integrator2_CSTATE; /* '<S34>/Integrator2' */
                    
                    
                        real_T Integrator2_CSTATE_o; /* '<S35>/Integrator2' */
                    
                    
                        real_T Integrator1_CSTATE; /* '<S37>/Integrator1' */
                    
                    
                        real_T Integrator1_CSTATE_o; /* '<S36>/Integrator1' */
                    
                    
                        real_T Integrator_CSTATE; /* '<S5>/Integrator' */
                    
                    
                        real_T Integrator1_CSTATE_i; /* '<S5>/Integrator1' */
                    
                    
                        real_T Integrator2_CSTATE_i; /* '<S5>/Integrator2' */
                    
                    
                        real_T Integrator5_CSTATE; /* '<S5>/Integrator5' */
                    
                    
                        real_T Integrator7_CSTATE; /* '<S5>/Integrator7' */
                    
                };                    
                /* State disabled  */
                struct XDis_Model_T {                            
                        boolean_T Integrator3_CSTATE; /* '<S5>/Integrator3' */
                    
                    
                        boolean_T Integrator6_CSTATE; /* '<S5>/Integrator6' */
                    
                    
                        boolean_T Integrator4_CSTATE; /* '<S5>/Integrator4' */
                    
                    
                        boolean_T Integrator2_CSTATE; /* '<S34>/Integrator2' */
                    
                    
                        boolean_T Integrator2_CSTATE_o; /* '<S35>/Integrator2' */
                    
                    
                        boolean_T Integrator1_CSTATE; /* '<S37>/Integrator1' */
                    
                    
                        boolean_T Integrator1_CSTATE_o; /* '<S36>/Integrator1' */
                    
                    
                        boolean_T Integrator_CSTATE; /* '<S5>/Integrator' */
                    
                    
                        boolean_T Integrator1_CSTATE_i; /* '<S5>/Integrator1' */
                    
                    
                        boolean_T Integrator2_CSTATE_i; /* '<S5>/Integrator2' */
                    
                    
                        boolean_T Integrator5_CSTATE; /* '<S5>/Integrator5' */
                    
                    
                        boolean_T Integrator7_CSTATE; /* '<S5>/Integrator7' */
                    
            };        
                #ifndef ODE3_INTG
        #define ODE3_INTG
        /* ODE3 Integration Data */
        struct ODE3_IntgData {
        real_T *y; /* output */
        real_T *f[3]; /* derivatives */
        };
        #endif

                        /* Parameters (default storage) */
                struct P_Model_T_ {
                    




                    
                    


                        



                            
                            
                                   real_T A; /* Variable: A
  * Referenced by: '<S1>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cd; /* Variable: Cd
  * Referenced by: '<S1>/Gain5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fx[1681]; /* Variable: Fx
  * Referenced by:
*   '<S15>/2-D Lookup Table1'
*   '<S16>/2-D Lookup Table1'
*   '<S17>/2-D Lookup Table1'
*   '<S18>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fy[3321]; /* Variable: Fy
  * Referenced by:
*   '<S15>/2-D Lookup Table'
*   '<S16>/2-D Lookup Table'
*   '<S17>/2-D Lookup Table'
*   '<S18>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fz[41]; /* Variable: Fz
  * Referenced by:
*   '<S15>/2-D Lookup Table'
*   '<S15>/2-D Lookup Table1'
*   '<S16>/2-D Lookup Table'
*   '<S16>/2-D Lookup Table1'
*   '<S17>/2-D Lookup Table'
*   '<S17>/2-D Lookup Table1'
*   '<S18>/2-D Lookup Table'
*   '<S18>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Iz_wehicle; /* Variable: Iz_wehicle
  * Referenced by: '<S14>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Iz_wheel; /* Variable: Iz_wheel
  * Referenced by:
*   '<S34>/Gain1'
*   '<S35>/Gain1'
*   '<S36>/Gain1'
*   '<S37>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T SA[81]; /* Variable: SA
  * Referenced by:
*   '<S15>/2-D Lookup Table'
*   '<S16>/2-D Lookup Table'
*   '<S17>/2-D Lookup Table'
*   '<S18>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T SR[41]; /* Variable: SR
  * Referenced by:
*   '<S15>/2-D Lookup Table1'
*   '<S16>/2-D Lookup Table1'
*   '<S17>/2-D Lookup Table1'
*   '<S18>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T air_density; /* Variable: air_density
  * Referenced by: '<S1>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T half_track; /* Variable: half_track
  * Referenced by:
*   '<S14>/Gain2'
*   '<S14>/Gain5'
*   '<S14>/Gain6'
*   '<S14>/Gain7'
*   '<S14>/Gain8'
*   '<S14>/Gain9'
*   '<S24>/Constant1'
*   '<S25>/Constant1'
*   '<S26>/Constant1'
*   '<S27>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T lf; /* Variable: lf
  * Referenced by:
*   '<S14>/Gain12'
*   '<S14>/Gain13'
*   '<S14>/Gain14'
*   '<S14>/Gain15'
*   '<S24>/Constant'
*   '<S25>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T lr; /* Variable: lr
  * Referenced by:
*   '<S14>/Gain10'
*   '<S14>/Gain11'
*   '<S26>/Constant'
*   '<S27>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mass; /* Variable: mass
  * Referenced by:
*   '<S12>/Gain'
*   '<S13>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T tire_radius; /* Variable: tire_radius
  * Referenced by:
*   '<S30>/Constant4'
*   '<S31>/Constant4'
*   '<S32>/Constant4'
*   '<S33>/Constant4'
*   '<S34>/Constant4'
*   '<S35>/Constant4'
*   '<S36>/Constant4'
*   '<S37>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain; /* Expression: -1
  * Referenced by: '<S2>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain; /* Expression: -1
  * Referenced by: '<S2>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat; /* Expression: 2
  * Referenced by: '<S19>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat; /* Expression: -0.5
  * Referenced by: '<S19>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_UpperSat; /* Expression: 2
  * Referenced by: '<S19>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_LowerSat; /* Expression: 0
  * Referenced by: '<S19>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator3_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value; /* Expression: 1
  * Referenced by: '<S5>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain; /* Expression: 1/2
  * Referenced by: '<S1>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value; /* Expression: 40
  * Referenced by: '<S2>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_l; /* Expression: pi/180
  * Referenced by: '<S8>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable_tableData[22]; /* Expression: [-0.000176278
0.017065829
0.034393458
0.051818825
0.069340186
0.086971502
0.104711028
0.122574473
0.140560091
0.158685336
0.176950206
0.195370411
0.21394595
0.232697768
0.251624118
0.270745946
0.290068486
0.309609192
0.3293733
0.349386991
0.369653754
0.475541135]
  * Referenced by: '<S2>/1-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable_bp01Data[22]; /* Expression: [0
0.073230598
0.146461196
0.219691794
0.292922392
0.36615299
0.439383588
0.512614186
0.585844784
0.659075382
0.73230598
0.805536578
0.878767176
0.951997774
1.025228372
1.09845897
1.171689568
1.244920166
1.318150764
1.391381362
1.46461196
1.83076495]
  * Referenced by: '<S2>/1-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable1_tableData[22]; /* Expression: [0.000176278
0.017336355
0.034421384
0.051433108
0.068382
0.085266315
0.102098271
0.118877866
0.135613828
0.152304412
0.168961834
0.18558435
0.202182431
0.218754332
0.235310526
0.251851011
0.26838277
0.284907547
0.301432324
0.317960592
0.334499332
0.417475776]
  * Referenced by: '<S2>/1-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable1_bp01Data[22]; /* Expression: [0
0.073230598
0.146461196
0.219691794
0.292922392
0.36615299
0.439383588
0.512614186
0.585844784
0.659075382
0.73230598
0.805536578
0.878767176
0.951997774
1.025228372
1.09845897
1.171689568
1.244920166
1.318150764
1.391381362
1.46461196
1.83076495]
  * Referenced by: '<S2>/1-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Switch_Threshold; /* Expression: 0
  * Referenced by: '<S2>/Switch'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Switch1_Threshold; /* Expression: 0
  * Referenced by: '<S2>/Switch1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value; /* Expression: 20
  * Referenced by: '<S2>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat_n; /* Expression: 100
  * Referenced by: '<S2>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat_j; /* Expression: 0
  * Referenced by: '<S2>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value; /* Expression: 0
  * Referenced by: '<S2>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable_tableData_d[2]; /* Expression: [0 30]
  * Referenced by: '<S3>/1-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable_bp01Data_c[2]; /* Expression: [0 100]
  * Referenced by: '<S3>/1-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable1_tableData_d[11]; /* Expression: tanh([-5:5])
  * Referenced by: '<S3>/1-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uDLookupTable1_bp01Data_d[11]; /* Expression: [-5:5]
  * Referenced by: '<S3>/1-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain_b; /* Expression: 9.81
  * Referenced by: '<S3>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_lp; /* Expression: 0
  * Referenced by: '<S3>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value_f; /* Expression: 600
  * Referenced by: '<S4>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_i; /* Expression: 600
  * Referenced by: '<S4>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant3_Value; /* Expression: 800
  * Referenced by: '<S4>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant4_Value; /* Expression: 800
  * Referenced by: '<S4>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator6_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator4_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC2_Value; /* Expression: 1
  * Referenced by: '<S5>/IC2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat; /* Expression: 0.55
  * Referenced by: '<S19>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat; /* Expression: -0.55
  * Referenced by: '<S19>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain_h; /* Expression: 180/pi
  * Referenced by: '<S20>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC4_Value; /* Expression: 0
  * Referenced by: '<S19>/IC4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_b; /* Expression: -1
  * Referenced by: '<S12>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator2_IC; /* Expression: 0
  * Referenced by: '<S34>/Integrator2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat_p; /* Expression: 160
  * Referenced by: '<S34>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat_c; /* Expression: 0
  * Referenced by: '<S34>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value_j; /* Expression: 1
  * Referenced by: '<S34>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_m; /* Expression: 1
  * Referenced by: '<S31>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator2_IC_i; /* Expression: 0
  * Referenced by: '<S35>/Integrator2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat_j; /* Expression: 160
  * Referenced by: '<S35>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat_l; /* Expression: 0
  * Referenced by: '<S35>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value_g; /* Expression: 1
  * Referenced by: '<S35>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_i; /* Expression: 1
  * Referenced by: '<S30>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator1_IC; /* Expression: 0
  * Referenced by: '<S37>/Integrator1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat_m; /* Expression: 160
  * Referenced by: '<S37>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat_f; /* Expression: 0
  * Referenced by: '<S37>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value_h; /* Expression: 1
  * Referenced by: '<S37>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_o; /* Expression: 1
  * Referenced by: '<S32>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator1_IC_d; /* Expression: 0
  * Referenced by: '<S36>/Integrator1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_UpperSat_h; /* Expression: 160
  * Referenced by: '<S36>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation_LowerSat_a; /* Expression: 0
  * Referenced by: '<S36>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value_hg; /* Expression: 1
  * Referenced by: '<S36>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_j; /* Expression: 1
  * Referenced by: '<S33>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Switch_Threshold_j; /* Expression: 1
  * Referenced by: '<S19>/Switch'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC5_Value; /* Expression: 0
  * Referenced by: '<S19>/IC5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain3_Gain; /* Expression: -1
  * Referenced by: '<S12>/Gain3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC1_Value; /* Expression: 0.5
  * Referenced by: '<S6>/IC1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain; /* Expression: -1
  * Referenced by: '<S5>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator1_IC_o; /* Expression: 0
  * Referenced by: '<S5>/Integrator1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator2_IC_m; /* Expression: 0
  * Referenced by: '<S5>/Integrator2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC1_Value_k; /* Expression: 1
  * Referenced by: '<S5>/IC1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator5_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator7_IC; /* Expression: 0
  * Referenced by: '<S5>/Integrator7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_f; /* Expression: -1
  * Referenced by: '<S13>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_l; /* Expression: -1
  * Referenced by: '<S13>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC_Value_n; /* Expression: 0.5
  * Referenced by: '<S6>/IC'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_b; /* Expression: -1
  * Referenced by: '<S14>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain_g; /* Expression: -1
  * Referenced by: '<S14>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IC2_Value_b; /* Expression: 0.5
  * Referenced by: '<S6>/IC2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable_maxIndex[2]; /* Computed Parameter: uDLookupTable_maxIndex
  * Referenced by: '<S15>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable_maxIndex_a[2]; /* Computed Parameter: uDLookupTable_maxIndex_a
  * Referenced by: '<S16>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable1_maxIndex[2]; /* Computed Parameter: uDLookupTable1_maxIndex
  * Referenced by: '<S15>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable1_maxIndex_l[2]; /* Computed Parameter: uDLookupTable1_maxIndex_l
  * Referenced by: '<S16>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable_maxIndex_k[2]; /* Computed Parameter: uDLookupTable_maxIndex_k
  * Referenced by: '<S17>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable_maxIndex_b[2]; /* Computed Parameter: uDLookupTable_maxIndex_b
  * Referenced by: '<S18>/2-D Lookup Table'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable1_maxIndex_h[2]; /* Computed Parameter: uDLookupTable1_maxIndex_h
  * Referenced by: '<S17>/2-D Lookup Table1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T uDLookupTable1_maxIndex_h2[2]; /* Computed Parameter: uDLookupTable1_maxIndex_h2
  * Referenced by: '<S18>/2-D Lookup Table1'
   */

                        
                        
                        


                    





                };

        


            /* Real-time Model Data Structure */
            
    struct tag_RTM_Model_T {
                    const char_T *errorStatus;
                    RTWLogInfo *rtwLogInfo;
        RTWSolverInfo solverInfo;
        X_Model_T *contStates;
                    int_T *periodicContStateIndices;
                    real_T *periodicContStateRanges;
                    real_T *derivs;
                    XDis_Model_T *contStateDisabled;
        boolean_T zCCacheNeedsReset;
                    boolean_T derivCacheNeedsReset;
                    boolean_T CTOutputIncnstWithState;
                    real_T odeY[12];
                    real_T odeF[3][12];
                    ODE3_IntgData intgData;

                        /*
        * Sizes:
                * The following substructure contains sizes information
        * for many of the model attributes such as inputs, outputs,
        * dwork, sample times, etc.
         */
 
    struct  {
                    int_T numContStates;
                    int_T numPeriodicContStates;
                    int_T numSampTimes;
            


    } Sizes;

                        /*
        * Timing:
                * The following substructure contains information regarding
        * the timing information for the model.
         */
 
    struct  {
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
                #ifdef __cplusplus
                extern "C" {
                    #endif
                        extern                 P_Model_T Model_P;




                #ifdef __cplusplus
            }
            #endif

            /* Block signals (default storage) */
                #ifdef __cplusplus
                extern "C" {
                    #endif
                        extern                 struct B_Model_T Model_B;




                #ifdef __cplusplus
            }
            #endif

            /* Continuous states (default storage) */
                        extern                 X_Model_T Model_X;





                /* Block states (default storage) */
                        extern                 struct DW_Model_T Model_DW;






    
            #ifdef __cplusplus
            extern "C" {
                #endif
            /* Model entry point functions */
                                        extern void Model_initialize(void);
                


                                                            extern void Model_step(void);
                        

                                        extern void Model_terminate(void);
                            #ifdef __cplusplus
        }
        #endif



    

    
                    /* Real-time Model object */

                        #ifdef __cplusplus
                        extern "C" {
                            #endif
                                extern                         RT_MODEL_Model_T *const Model_M;




                        #ifdef __cplusplus
                    }
                    #endif



    

    

    

            
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
            * '<Root>' : 'Model'
                * '<S1>'   : 'Model/Aero'
                * '<S2>'   : 'Model/Driver Input'
                * '<S3>'   : 'Model/Input -> Torque'
                * '<S4>'   : 'Model/Load Estimation'
                * '<S5>'   : 'Model/Measured States'
                * '<S6>'   : 'Model/State Estimation'
                * '<S7>'   : 'Model/Tires '
                * '<S8>'   : 'Model/Driver Input/Degrees to Radians'
                * '<S9>'   : 'Model/Driver Input/Radians to Degrees'
                * '<S10>'  : 'Model/Driver Input/Radians to Degrees1'
                * '<S11>'  : 'Model/Measured States/Radians to Degrees'
                * '<S12>'  : 'Model/State Estimation/Lateral Acceleration'
                * '<S13>'  : 'Model/State Estimation/Longitudinal Acceleration'
                * '<S14>'  : 'Model/State Estimation/Yaw_acceleration'
                * '<S15>'  : 'Model/Tires /FL'
                * '<S16>'  : 'Model/Tires /FR'
                * '<S17>'  : 'Model/Tires /RL'
                * '<S18>'  : 'Model/Tires /RR'
                * '<S19>'  : 'Model/Tires /Subsystem5'
                * '<S20>'  : 'Model/Tires /Subsystem5/Radians to Degrees'
                * '<S21>'  : 'Model/Tires /Subsystem5/Slip Angle'
                * '<S22>'  : 'Model/Tires /Subsystem5/Slip Ratio'
                * '<S23>'  : 'Model/Tires /Subsystem5/wheel_speed'
                * '<S24>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle FL'
                * '<S25>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle FR'
                * '<S26>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle RL'
                * '<S27>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle RR'
                * '<S28>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle RL/Radians to Degrees'
                * '<S29>'  : 'Model/Tires /Subsystem5/Slip Angle/Slip Angle RR/Radians to Degrees'
                * '<S30>'  : 'Model/Tires /Subsystem5/Slip Ratio/Slip ratio FL'
                * '<S31>'  : 'Model/Tires /Subsystem5/Slip Ratio/Slip ratio FR'
                * '<S32>'  : 'Model/Tires /Subsystem5/Slip Ratio/Slip ratio RL'
                * '<S33>'  : 'Model/Tires /Subsystem5/Slip Ratio/Slip ratio RR'
                * '<S34>'  : 'Model/Tires /Subsystem5/wheel_speed/Subsystem'
                * '<S35>'  : 'Model/Tires /Subsystem5/wheel_speed/Subsystem1'
                * '<S36>'  : 'Model/Tires /Subsystem5/wheel_speed/Subsystem2'
                * '<S37>'  : 'Model/Tires /Subsystem5/wheel_speed/Subsystem3'
    */


    

    #endif /* RTW_HEADER_Model_h_ */
