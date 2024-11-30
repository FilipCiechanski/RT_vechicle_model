

    

        /*
        * Model.cpp
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




    
#include "Model.h"

#include <cmath>

#include "rtwtypes.h"

#include "Model_private.h"

#include <cstring>

extern "C" {

#include "rt_nonfinite.h"
}


    

    

    

    

    

    

    

    

    

    

    
        /* Block signals (default storage) */
                                            B_Model_T Model_B;


            
        /* Continuous states */
                            X_Model_T Model_X;


    
            /* Block states (default storage) */
                                            DW_Model_T Model_DW;


            
    




            
        
        
        
        
        
        

        

        
        


                /* Real-time model */
                        
                                RT_MODEL_Model_T Model_M_{};


                            RT_MODEL_Model_T *const Model_M{ &Model_M_ };




    

    

    

    

        
                         
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[], uint32_T maxIndex)
{
    real_T frac;
    real_T yL_0d0;
    uint32_T iLeft;
    /* Column-major Lookup 1-D
   Search method: 'binary'
   Use previous index: 'off'
   Interpolation method: 'Linear point-slope'
   Extrapolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u0 <= bp0[0U]) {
        iLeft = 0U;
        frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
    } else if (u0 < bp0[maxIndex]) {
        uint32_T bpIdx;
        uint32_T iRght;
        /* Binary Search */
        bpIdx = maxIndex >> 1U;
        iLeft = 0U;
        iRght = maxIndex;
        while (iRght - iLeft > 1U) {
            if (u0 < bp0[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
    } else {
        iLeft = maxIndex - 1U;
        frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
    }
    /* Column-major Interpolation 1-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    yL_0d0 = table[iLeft];
    return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}
        
                 
real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
    real_T fractions[2];
    real_T frac;
    real_T yL_0d0;
    real_T yL_0d1;
    uint32_T bpIndices[2];
    uint32_T bpIdx;
    uint32_T iLeft;
    uint32_T iRght;
    /* Column-major Lookup 2-D
   Search method: 'binary'
   Use previous index: 'off'
   Interpolation method: 'Linear point-slope'
   Extrapolation method: 'Linear'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u0 <= bp0[0U]) {
        iLeft = 0U;
        frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
    } else if (u0 < bp0[maxIndex[0U]]) {
        /* Binary Search */
        bpIdx = maxIndex[0U] >> 1U;
        iLeft = 0U;
        iRght = maxIndex[0U];
        while (iRght - iLeft > 1U) {
            if (u0 < bp0[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
    } else {
        iLeft = maxIndex[0U] - 1U;
        frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U] - 1U]);
    }
    fractions[0U] = frac;
    bpIndices[0U] = iLeft;
    /* Prelookup - Index and Fraction
   Index Search method: 'binary'
   Extrapolation method: 'Linear'
   Use previous index: 'off'
   Use last breakpoint for index at or above upper limit: 'off'
   Remove protection against out-of-range input in generated code: 'off'
 */
    if (u1 <= bp1[0U]) {
        iLeft = 0U;
        frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
    } else if (u1 < bp1[maxIndex[1U]]) {
        /* Binary Search */
        bpIdx = maxIndex[1U] >> 1U;
        iLeft = 0U;
        iRght = maxIndex[1U];
        while (iRght - iLeft > 1U) {
            if (u1 < bp1[bpIdx]) {
                iRght = bpIdx;
            } else {
                iLeft = bpIdx;
            }
            bpIdx = (iRght + iLeft) >> 1U;
        }
        frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
    } else {
        iLeft = maxIndex[1U] - 1U;
        frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U] - 1U]);
    }
    /* Column-major Interpolation 2-D
   Interpolation method: 'Linear point-slope'
   Use last breakpoint for index at or above upper limit: 'off'
   Overflow mode: 'portable wrapping'
 */
    bpIdx = iLeft * stride + bpIndices[0U];
    yL_0d0 = table[bpIdx];
    yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    bpIdx += stride;
    yL_0d1 = table[bpIdx];
    return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) * frac + yL_0d0;
}
        
    








    /* 
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */

        static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
    {
        

            /* Solver Matrices */
            static const real_T rt_ODE3_A[3]{
                1.0/2.0, 3.0/4.0, 1.0
            };
            static const real_T rt_ODE3_B[3][3]{
                { 1.0/2.0,     0.0,     0.0 },
                {     0.0, 3.0/4.0,     0.0 },
                { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
            };

            time_T    t    { rtsiGetT(si) };
            time_T    tnew { rtsiGetSolverStopTime(si) };
            time_T    h    { rtsiGetStepSize(si) };
            real_T    *x   { rtsiGetContStates(si) };
            ODE3_IntgData  *id {  static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };
            real_T    *y   { id->y };
            real_T    *f0  { id->f[0] };
            real_T    *f1  { id->f[1] };
            real_T    *f2  { id->f[2] };
            real_T    hB[3];
            int_T     i;
            int_T     nXc  { 12 };


            rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
            

            /* Save the state values at time t in y, we'll use x as ynew. */
            (void) std::memcpy(y, x,
static_cast<uint_T>(nXc)*sizeof(real_T));

            /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
            /* f0 = f(t,y) */
            rtsiSetdX(si, f0);

                        Model_derivatives();

            /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
            hB[0] = h * rt_ODE3_B[0][0];
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0]);
            }
            rtsiSetT(si, t + h*rt_ODE3_A[0]);
            rtsiSetdX(si, f1);
            
            


            Model_step();


                        Model_derivatives();

            

            /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
            for (i = 0; i <= 1; i++) {
                hB[i] = h * rt_ODE3_B[1][i];
            }
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
            }
            rtsiSetT(si, t + h*rt_ODE3_A[1]);
            rtsiSetdX(si, f2);
            
            


            Model_step();


                        Model_derivatives();

            

            /* tnew = t + hA(3);
            ynew = y + f*hB(:,3); */
            for (i = 0; i <= 2; i++) {
                hB[i] = h * rt_ODE3_B[2][i];
            }
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
            }
            rtsiSetT(si, tnew);





            rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
            

    }
    

    
    

                
        
        
        

    

                        




        /* Model step function */
        
                    
        void Model_step(void) 
        {
            



        

                
        
            
real_T Gain1_c_tmp;
real_T rtb_BrakeTorque;
real_T rtb_Gain2;
real_T rtb_IC4_idx_1;
real_T rtb_IC4_idx_2;
real_T rtb_IC4_idx_3;
real_T rtb_IC5_idx_3;
real_T rtb_MotorTorqueNm;
real_T rtb_SteeringangleIN;
real_T rtb_Subtract_p;
real_T rtb_uDLookupTable;
real_T rtb_uDLookupTable1_e;

            

        

        




                
            

            if (rtmIsMajorTimeStep(Model_M)) {
        
            /* set solver stop time */
        if (!(Model_M->Timing.clockTick0+1)) {
            rtsiSetSolverStopTime(&Model_M->solverInfo, ((Model_M->Timing.clockTickH0 + 1) * Model_M->Timing.stepSize0 * 4294967296.0));
        } else {
            rtsiSetSolverStopTime(&Model_M->solverInfo, ((Model_M->Timing.clockTick0  + 1) * Model_M->Timing.stepSize0 + Model_M->Timing.clockTickH0 * Model_M->Timing.stepSize0 * 4294967296.0));
        }


    

        } /* end MajorTimeStep */
        /* Update absolute time of base rate at minor time step */
        if (rtmIsMinorTimeStep(Model_M)) {
            Model_M->Timing.t[0] = rtsiGetT(&Model_M->solverInfo);
        }
        





        




                                                    
                
                                    /* {S!d622}Integrator: '<S5>/Integrator3' */
Model_B.V_xms = Model_X.Integrator3_CSTATE;
/* {S!d624}InitialCondition: '<S5>/IC' incorporates:
 *  InitialCondition: '<S19>/IC4'
 *  InitialCondition: '<S19>/IC5'
 *  InitialCondition: '<S34>/IC'
 *  InitialCondition: '<S35>/IC'
 *  InitialCondition: '<S36>/IC'
 *  InitialCondition: '<S37>/IC'
 *  InitialCondition: '<S5>/IC1'
 *  InitialCondition: '<S5>/IC2'
 *  InitialCondition: '<S6>/IC'
 *  InitialCondition: '<S6>/IC1'
 *  InitialCondition: '<S6>/IC2'
 */
Gain1_c_tmp = Model_M->Timing.t[0];
if ((Model_DW.IC_FirstOutputTime == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime = Gain1_c_tmp;
    rtb_uDLookupTable = Model_P.IC_Value;
} else {
    rtb_uDLookupTable = Model_B.V_xms;
}
/* {S!d626}Gain: '<S1>/Gain2' incorporates:
 *  Gain: '<S1>/Gain1'
 *  Gain: '<S1>/Gain4'
 *  Math: '<S1>/Square'
 */
rtb_Gain2 = rtb_uDLookupTable * rtb_uDLookupTable * Model_P.A * Model_P.air_density * Model_P.Gain2_Gain;
if (rtmIsMajorTimeStep(Model_M)) {
    /* {S!d628}Gain: '<S8>/Gain1' incorporates:
 *  Constant: '<S2>/Constant2'
 */
    rtb_BrakeTorque = Model_P.Gain1_Gain_l * Model_P.Constant2_Value;
    /* {S!d630}Abs: '<S2>/Abs' */
    rtb_MotorTorqueNm = std::abs(rtb_BrakeTorque);
    /* {S!d632}Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
 *  Lookup_n-D: '<S3>/1-D Lookup Table'
 */
    rtb_SteeringangleIN = look1_binlxpw(rtb_MotorTorqueNm, Model_P.uDLookupTable_bp01Data, Model_P.uDLookupTable_tableData, 21U);
    /* {S!d634}Lookup_n-D: '<S2>/1-D Lookup Table1' incorporates:
 *  Lookup_n-D: '<S3>/1-D Lookup Table'
 */
    rtb_MotorTorqueNm = look1_binlxpw(rtb_MotorTorqueNm, Model_P.uDLookupTable1_bp01Data, Model_P.uDLookupTable1_tableData, 21U);
    /* {S!d640}Switch: '<S2>/Switch' */
    if (rtb_BrakeTorque > Model_P.Switch_Threshold) {
        /* {S!d636}Switch: '<S2>/Switch' */
        Model_B.SteeringangleFL = rtb_MotorTorqueNm;
    } else {
        /* {S!d638}Switch: '<S2>/Switch' incorporates:
 *  Gain: '<S2>/Gain'
 */
        Model_B.SteeringangleFL = Model_P.Gain_Gain * rtb_SteeringangleIN;
    }
    /* {E!d640}End of Switch: '<S2>/Switch' */

    /* {S!d646}Switch: '<S2>/Switch1' */
    if (rtb_BrakeTorque > Model_P.Switch1_Threshold) {
        /* {S!d642}Switch: '<S2>/Switch1' */
        Model_B.SteeringangleFR = rtb_SteeringangleIN;
    } else {
        /* {S!d644}Switch: '<S2>/Switch1' incorporates:
 *  Gain: '<S2>/Gain1'
 */
        Model_B.SteeringangleFR = Model_P.Gain1_Gain * rtb_MotorTorqueNm;
    }
    /* {E!d646}End of Switch: '<S2>/Switch1' */

    /* {S!d648}Saturate: '<S2>/Saturation' incorporates:
 *  Constant: '<S2>/Constant'
 */
    if (Model_P.Constant_Value > Model_P.Saturation_UpperSat_n) {
        rtb_uDLookupTable1_e = Model_P.Saturation_UpperSat_n;
    } else if (Model_P.Constant_Value < Model_P.Saturation_LowerSat_j) {
        rtb_uDLookupTable1_e = Model_P.Saturation_LowerSat_j;
    } else {
        rtb_uDLookupTable1_e = Model_P.Constant_Value;
    }
    /* {S!d650}Gain: '<S3>/Gain' incorporates:
 *  Lookup_n-D: '<S3>/1-D Lookup Table'
 *  Saturate: '<S2>/Saturation'
 */
    Model_B.MotorTorque = Model_P.Gain_Gain_b * look1_binlxpw(rtb_uDLookupTable1_e, Model_P.uDLookupTable_bp01Data_c, Model_P.uDLookupTable_tableData_d, 1U);
    /* {S!d652}Gain: '<S3>/Gain1' incorporates:
 *  Constant: '<S2>/Constant1'
 *  Lookup_n-D: '<S3>/1-D Lookup Table1'
 */
    Model_B.BrakeTorque = Model_P.Gain1_Gain_lp * look1_binlxpw(Model_P.Constant1_Value, Model_P.uDLookupTable1_bp01Data_d, Model_P.uDLookupTable1_tableData_d, 10U);
    /* {S!d654}Trigonometry: '<S12>/Cos' */
    Model_B.Cos = std::cos(Model_B.SteeringangleFL);
}
/* {S!d656}Integrator: '<S5>/Integrator4' */
rtb_uDLookupTable1_e = Model_X.Integrator4_CSTATE;
/* {S!d658}InitialCondition: '<S5>/IC2' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC2_FirstOutputTime == (rtMinusInf)) || (Model_DW.IC2_FirstOutputTime == Gain1_c_tmp)) {
    Model_DW.IC2_FirstOutputTime = Gain1_c_tmp;
    rtb_uDLookupTable1_e = Model_P.IC2_Value;
}
/* {S!d660}Product: '<S24>/Product1' incorporates:
 *  Constant: '<S24>/Constant1'
 *  Product: '<S25>/Product1'
 */
rtb_IC4_idx_3 = rtb_uDLookupTable1_e * Model_P.half_track;
/* {S!d662}Sum: '<S24>/Subtract' incorporates:
 *  Constant: '<S24>/Constant'
 *  Integrator: '<S5>/Integrator6'
 *  Product: '<S24>/Product'
 *  Sum: '<S25>/Subtract'
 */
rtb_MotorTorqueNm = Model_P.lf * rtb_uDLookupTable1_e + Model_X.Integrator6_CSTATE;
/* {S!d664}Sum: '<S24>/Subtract1' incorporates:
 *  Product: '<S24>/Product1'
 *  Sum: '<S26>/Subtract1'
 */
rtb_IC4_idx_2 = rtb_uDLookupTable - rtb_IC4_idx_3;
/* {S!d666}Sum: '<S24>/Subtract2' incorporates:
 *  Product: '<S24>/Divide'
 *  Sum: '<S24>/Subtract'
 *  Sum: '<S24>/Subtract1'
 */
rtb_SteeringangleIN = rtb_MotorTorqueNm / rtb_IC4_idx_2 - Model_B.SteeringangleFL;
/* {S!d668}Saturate: '<S19>/Saturation4' */
if (rtb_SteeringangleIN > Model_P.Saturation4_UpperSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_UpperSat;
} else if (rtb_SteeringangleIN < Model_P.Saturation4_LowerSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_LowerSat;
}
/* {S!d670}Gain: '<S20>/Gain' incorporates:
 *  Saturate: '<S19>/Saturation4'
 */
rtb_BrakeTorque = Model_P.Gain_Gain_h * rtb_SteeringangleIN;
/* {S!d672}Sum: '<S25>/Subtract1' incorporates:
 *  Sum: '<S27>/Subtract1'
 */
rtb_IC4_idx_3 += rtb_uDLookupTable;
/* {S!d674}Sum: '<S25>/Subtract2' incorporates:
 *  Product: '<S25>/Divide'
 *  Sum: '<S25>/Subtract1'
 */
rtb_SteeringangleIN = rtb_MotorTorqueNm / rtb_IC4_idx_3 - Model_B.SteeringangleFR;
/* {S!d676}Saturate: '<S19>/Saturation4' */
if (rtb_SteeringangleIN > Model_P.Saturation4_UpperSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_UpperSat;
} else if (rtb_SteeringangleIN < Model_P.Saturation4_LowerSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_LowerSat;
}
/* {S!d678}Gain: '<S20>/Gain' incorporates:
 *  Saturate: '<S19>/Saturation4'
 */
rtb_IC4_idx_1 = Model_P.Gain_Gain_h * rtb_SteeringangleIN;
/* {S!d680}Sum: '<S26>/Subtract' incorporates:
 *  Constant: '<S26>/Constant'
 *  Integrator: '<S5>/Integrator6'
 *  Product: '<S26>/Product'
 *  Sum: '<S27>/Subtract'
 */
rtb_MotorTorqueNm = Model_X.Integrator6_CSTATE - Model_P.lr * rtb_uDLookupTable1_e;
/* {S!d682}Product: '<S26>/Divide' incorporates:
 *  Sum: '<S26>/Subtract'
 */
rtb_SteeringangleIN = rtb_MotorTorqueNm / rtb_IC4_idx_2;
/* {S!d684}Saturate: '<S19>/Saturation4' */
if (rtb_SteeringangleIN > Model_P.Saturation4_UpperSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_UpperSat;
} else if (rtb_SteeringangleIN < Model_P.Saturation4_LowerSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_LowerSat;
}
/* {S!d686}Gain: '<S20>/Gain' incorporates:
 *  Saturate: '<S19>/Saturation4'
 */
rtb_IC4_idx_2 = Model_P.Gain_Gain_h * rtb_SteeringangleIN;
/* {S!d688}Product: '<S27>/Divide' */
rtb_SteeringangleIN = rtb_MotorTorqueNm / rtb_IC4_idx_3;
/* {S!d690}Saturate: '<S19>/Saturation4' */
if (rtb_SteeringangleIN > Model_P.Saturation4_UpperSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_UpperSat;
} else if (rtb_SteeringangleIN < Model_P.Saturation4_LowerSat) {
    rtb_SteeringangleIN = Model_P.Saturation4_LowerSat;
}
/* {S!d692}Gain: '<S20>/Gain' incorporates:
 *  Saturate: '<S19>/Saturation4'
 */
rtb_IC4_idx_3 = Model_P.Gain_Gain_h * rtb_SteeringangleIN;
/* {S!d694}InitialCondition: '<S19>/IC4' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC4_FirstOutputTime == (rtMinusInf)) || (Model_DW.IC4_FirstOutputTime == Gain1_c_tmp)) {
    Model_DW.IC4_FirstOutputTime = Gain1_c_tmp;
    rtb_BrakeTorque = Model_P.IC4_Value;
    rtb_IC4_idx_1 = Model_P.IC4_Value;
    rtb_IC4_idx_2 = Model_P.IC4_Value;
    rtb_IC4_idx_3 = Model_P.IC4_Value;
}
/* {S!d696}Lookup_n-D: '<S15>/2-D Lookup Table' incorporates:
 *  Constant: '<S4>/Constant1'
 */
rtb_BrakeTorque = look2_binlxpw(Model_P.Constant1_Value_f, rtb_BrakeTorque, Model_P.Fz, Model_P.SA, Model_P.Fy, Model_P.uDLookupTable_maxIndex, 41U);
if (rtmIsMajorTimeStep(Model_M)) {
    /* {S!d698}Trigonometry: '<S12>/Cos1' */
    Model_B.Cos1 = std::cos(Model_B.SteeringangleFR);
    /* {S!d700}Trigonometry: '<S12>/Sin' incorporates:
 *  Gain: '<S12>/Gain2'
 */
    Model_B.Sin = std::sin(Model_P.Gain2_Gain_b * Model_B.SteeringangleFL);
}
/* {S!d702}Lookup_n-D: '<S16>/2-D Lookup Table' incorporates:
 *  Constant: '<S4>/Constant2'
 */
rtb_SteeringangleIN = look2_binlxpw(Model_P.Constant2_Value_i, rtb_IC4_idx_1, Model_P.Fz, Model_P.SA, Model_P.Fy, Model_P.uDLookupTable_maxIndex_a, 41U);
/* {S!d704}Saturate: '<S34>/Saturation' */
if (Model_X.Integrator2_CSTATE > Model_P.Saturation_UpperSat_p) {
    rtb_MotorTorqueNm = Model_P.Saturation_UpperSat_p;
} else if (Model_X.Integrator2_CSTATE < Model_P.Saturation_LowerSat_c) {
    rtb_MotorTorqueNm = Model_P.Saturation_LowerSat_c;
} else {
    rtb_MotorTorqueNm = Model_X.Integrator2_CSTATE;
}
/* {E!d704}End of Saturate: '<S34>/Saturation' */

/* {S!d706}InitialCondition: '<S34>/IC' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC_FirstOutputTime_d == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime_d == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime_d = Gain1_c_tmp;
    rtb_MotorTorqueNm = Model_P.IC_Value_j;
}
/* {S!d708}Sum: '<S31>/Subtract' incorporates:
 *  Constant: '<S31>/Constant'
 *  Constant: '<S31>/Constant4'
 *  Product: '<S31>/Divide'
 */
rtb_uDLookupTable1_e = Model_P.tire_radius * rtb_MotorTorqueNm / rtb_uDLookupTable - Model_P.Constant_Value_m;
/* {S!d710}Saturate: '<S35>/Saturation' */
if (Model_X.Integrator2_CSTATE_o > Model_P.Saturation_UpperSat_j) {
    rtb_MotorTorqueNm = Model_P.Saturation_UpperSat_j;
} else if (Model_X.Integrator2_CSTATE_o < Model_P.Saturation_LowerSat_l) {
    rtb_MotorTorqueNm = Model_P.Saturation_LowerSat_l;
} else {
    rtb_MotorTorqueNm = Model_X.Integrator2_CSTATE_o;
}
/* {E!d710}End of Saturate: '<S35>/Saturation' */

/* {S!d712}InitialCondition: '<S35>/IC' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC_FirstOutputTime_h == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime_h == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime_h = Gain1_c_tmp;
    rtb_MotorTorqueNm = Model_P.IC_Value_g;
}
/* {S!d714}Sum: '<S30>/Subtract' incorporates:
 *  Constant: '<S30>/Constant'
 *  Constant: '<S30>/Constant4'
 *  Product: '<S30>/Divide'
 */
rtb_Subtract_p = Model_P.tire_radius * rtb_MotorTorqueNm / rtb_uDLookupTable - Model_P.Constant_Value_i;
/* {S!d716}Saturate: '<S37>/Saturation' */
if (Model_X.Integrator1_CSTATE > Model_P.Saturation_UpperSat_m) {
    rtb_MotorTorqueNm = Model_P.Saturation_UpperSat_m;
} else if (Model_X.Integrator1_CSTATE < Model_P.Saturation_LowerSat_f) {
    rtb_MotorTorqueNm = Model_P.Saturation_LowerSat_f;
} else {
    rtb_MotorTorqueNm = Model_X.Integrator1_CSTATE;
}
/* {E!d716}End of Saturate: '<S37>/Saturation' */

/* {S!d718}InitialCondition: '<S37>/IC' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC_FirstOutputTime_a == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime_a == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime_a = Gain1_c_tmp;
    rtb_MotorTorqueNm = Model_P.IC_Value_h;
}
/* {S!d720}Sum: '<S32>/Subtract' incorporates:
 *  Constant: '<S32>/Constant'
 *  Constant: '<S32>/Constant4'
 *  Product: '<S32>/Divide'
 */
rtb_IC4_idx_1 = Model_P.tire_radius * rtb_MotorTorqueNm / rtb_uDLookupTable - Model_P.Constant_Value_o;
/* {S!d722}Saturate: '<S36>/Saturation' */
if (Model_X.Integrator1_CSTATE_o > Model_P.Saturation_UpperSat_h) {
    rtb_MotorTorqueNm = Model_P.Saturation_UpperSat_h;
} else if (Model_X.Integrator1_CSTATE_o < Model_P.Saturation_LowerSat_a) {
    rtb_MotorTorqueNm = Model_P.Saturation_LowerSat_a;
} else {
    rtb_MotorTorqueNm = Model_X.Integrator1_CSTATE_o;
}
/* {E!d722}End of Saturate: '<S36>/Saturation' */

/* {S!d724}InitialCondition: '<S36>/IC' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC_FirstOutputTime_g == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime_g == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime_g = Gain1_c_tmp;
    rtb_MotorTorqueNm = Model_P.IC_Value_hg;
}
/* {S!d742}Switch: '<S19>/Switch' incorporates:
 *  Saturate: '<S19>/Saturation1'
 */
if (rtb_uDLookupTable > Model_P.Switch_Threshold_j) {
    /* {S!d726}Saturate: '<S19>/Saturation' */
    if (rtb_uDLookupTable1_e > Model_P.Saturation_UpperSat) {
        rtb_uDLookupTable1_e = Model_P.Saturation_UpperSat;
    } else if (rtb_uDLookupTable1_e < Model_P.Saturation_LowerSat) {
        rtb_uDLookupTable1_e = Model_P.Saturation_LowerSat;
    }
    if (rtb_Subtract_p > Model_P.Saturation_UpperSat) {
        rtb_Subtract_p = Model_P.Saturation_UpperSat;
    } else if (rtb_Subtract_p < Model_P.Saturation_LowerSat) {
        rtb_Subtract_p = Model_P.Saturation_LowerSat;
    }
    if (rtb_IC4_idx_1 > Model_P.Saturation_UpperSat) {
        rtb_IC4_idx_1 = Model_P.Saturation_UpperSat;
    } else if (rtb_IC4_idx_1 < Model_P.Saturation_LowerSat) {
        rtb_IC4_idx_1 = Model_P.Saturation_LowerSat;
    }
    /* {S!d728}Sum: '<S33>/Subtract' incorporates:
 *  Constant: '<S33>/Constant'
 *  Constant: '<S33>/Constant4'
 *  Product: '<S33>/Divide'
 */
    rtb_IC5_idx_3 = Model_P.tire_radius * rtb_MotorTorqueNm / rtb_uDLookupTable - Model_P.Constant_Value_j;
    /* {S!d730}Saturate: '<S19>/Saturation' */
    if (rtb_IC5_idx_3 > Model_P.Saturation_UpperSat) {
        rtb_IC5_idx_3 = Model_P.Saturation_UpperSat;
    } else if (rtb_IC5_idx_3 < Model_P.Saturation_LowerSat) {
        rtb_IC5_idx_3 = Model_P.Saturation_LowerSat;
    }
} else {
    if (rtb_uDLookupTable1_e > Model_P.Saturation1_UpperSat) {
        /* {S!d732}Saturate: '<S19>/Saturation1' */
        rtb_uDLookupTable1_e = Model_P.Saturation1_UpperSat;
    } else if (rtb_uDLookupTable1_e < Model_P.Saturation1_LowerSat) {
        /* {S!d734}Saturate: '<S19>/Saturation1' */
        rtb_uDLookupTable1_e = Model_P.Saturation1_LowerSat;
    }
    /* {S!d736}Saturate: '<S19>/Saturation1' */
    if (rtb_Subtract_p > Model_P.Saturation1_UpperSat) {
        rtb_Subtract_p = Model_P.Saturation1_UpperSat;
    } else if (rtb_Subtract_p < Model_P.Saturation1_LowerSat) {
        rtb_Subtract_p = Model_P.Saturation1_LowerSat;
    }
    if (rtb_IC4_idx_1 > Model_P.Saturation1_UpperSat) {
        rtb_IC4_idx_1 = Model_P.Saturation1_UpperSat;
    } else if (rtb_IC4_idx_1 < Model_P.Saturation1_LowerSat) {
        rtb_IC4_idx_1 = Model_P.Saturation1_LowerSat;
    }
    /* {S!d738}Sum: '<S33>/Subtract' incorporates:
 *  Constant: '<S33>/Constant'
 *  Constant: '<S33>/Constant4'
 *  Product: '<S33>/Divide'
 */
    rtb_IC5_idx_3 = Model_P.tire_radius * rtb_MotorTorqueNm / rtb_uDLookupTable - Model_P.Constant_Value_j;
    /* {S!d740}Saturate: '<S19>/Saturation1' */
    if (rtb_IC5_idx_3 > Model_P.Saturation1_UpperSat) {
        rtb_IC5_idx_3 = Model_P.Saturation1_UpperSat;
    } else if (rtb_IC5_idx_3 < Model_P.Saturation1_LowerSat) {
        rtb_IC5_idx_3 = Model_P.Saturation1_LowerSat;
    }
}
/* {E!d742}End of Switch: '<S19>/Switch' */

/* {S!d744}InitialCondition: '<S19>/IC5' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC5_FirstOutputTime == (rtMinusInf)) || (Model_DW.IC5_FirstOutputTime == Gain1_c_tmp)) {
    Model_DW.IC5_FirstOutputTime = Gain1_c_tmp;
    rtb_uDLookupTable1_e = Model_P.IC5_Value;
    rtb_Subtract_p = Model_P.IC5_Value;
    rtb_IC4_idx_1 = Model_P.IC5_Value;
    rtb_IC5_idx_3 = Model_P.IC5_Value;
}
/* {S!d746}Lookup_n-D: '<S15>/2-D Lookup Table1' incorporates:
 *  Constant: '<S4>/Constant1'
 */
rtb_MotorTorqueNm = look2_binlxpw(Model_P.Constant1_Value_f, rtb_uDLookupTable1_e, Model_P.Fz, Model_P.SR, Model_P.Fx, Model_P.uDLookupTable1_maxIndex, 41U);
if (rtmIsMajorTimeStep(Model_M)) {
    /* {S!d748}Trigonometry: '<S12>/Sin1' incorporates:
 *  Gain: '<S12>/Gain3'
 */
    Model_B.Sin1 = std::sin(Model_P.Gain3_Gain * Model_B.SteeringangleFR);
}
/* {S!d750}Lookup_n-D: '<S16>/2-D Lookup Table1' incorporates:
 *  Constant: '<S4>/Constant2'
 */
rtb_uDLookupTable1_e = look2_binlxpw(Model_P.Constant2_Value_i, rtb_Subtract_p, Model_P.Fz, Model_P.SR, Model_P.Fx, Model_P.uDLookupTable1_maxIndex_l, 41U);
/* {S!d752}Lookup_n-D: '<S17>/2-D Lookup Table' incorporates:
 *  Constant: '<S4>/Constant3'
 */
rtb_Subtract_p = look2_binlxpw(Model_P.Constant3_Value, rtb_IC4_idx_2, Model_P.Fz, Model_P.SA, Model_P.Fy, Model_P.uDLookupTable_maxIndex_k, 41U);
/* {S!d754}Lookup_n-D: '<S18>/2-D Lookup Table' incorporates:
 *  Constant: '<S4>/Constant4'
 */
rtb_uDLookupTable = look2_binlxpw(Model_P.Constant4_Value, rtb_IC4_idx_3, Model_P.Fz, Model_P.SA, Model_P.Fy, Model_P.uDLookupTable_maxIndex_b, 41U);
/* {S!d760}InitialCondition: '<S6>/IC1' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC1_FirstOutputTime == (rtMinusInf)) || (Model_DW.IC1_FirstOutputTime == Gain1_c_tmp)) {
    Model_DW.IC1_FirstOutputTime = Gain1_c_tmp;
    /* {S!d756}InitialCondition: '<S6>/IC1' */
    Model_B.IC1 = Model_P.IC1_Value;
} else {
    /* {S!d758}InitialCondition: '<S6>/IC1' incorporates:
 *  Gain: '<S12>/Gain'
 *  Product: '<S12>/Product'
 *  Product: '<S12>/Product1'
 *  Product: '<S12>/Product2'
 *  Product: '<S12>/Product3'
 *  Sum: '<S12>/Add1'
 */
    Model_B.IC1 = (((((Model_B.Cos * rtb_BrakeTorque + Model_B.Cos1 * rtb_SteeringangleIN) - Model_B.Sin * rtb_MotorTorqueNm) - Model_B.Sin1 * rtb_uDLookupTable1_e) + rtb_Subtract_p) + rtb_uDLookupTable) * (1.0 / Model_P.mass);
}
/* {S!d762}Sum: '<S5>/Add1' incorporates:
 *  Gain: '<S5>/Gain4'
 *  Integrator: '<S5>/Integrator'
 *  Integrator: '<S5>/Integrator1'
 *  Product: '<S5>/Product8'
 */
Model_B.YACCms2 = Model_P.Gain4_Gain * Model_X.Integrator_CSTATE * Model_X.Integrator1_CSTATE_i + Model_B.IC1;
/* {S!d768}InitialCondition: '<S5>/IC1' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC1_FirstOutputTime_d == (rtMinusInf)) || (Model_DW.IC1_FirstOutputTime_d == Gain1_c_tmp)) {
    Model_DW.IC1_FirstOutputTime_d = Gain1_c_tmp;
    /* {S!d764}InitialCondition: '<S5>/IC1' */
    Model_B.V_yms = Model_P.IC1_Value_k;
} else {
    /* {S!d766}InitialCondition: '<S5>/IC1' incorporates:
 *  Integrator: '<S5>/Integrator2'
 */
    Model_B.V_yms = Model_X.Integrator2_CSTATE_i;
}
if (rtmIsMajorTimeStep(Model_M)) {
    /* {S!d770}Trigonometry: '<S13>/Cos' */
    Model_B.Cos_p = std::cos(Model_B.SteeringangleFL);
    /* {S!d772}Trigonometry: '<S13>/Cos1' */
    Model_B.Cos1_a = std::cos(Model_B.SteeringangleFR);
    /* {S!d774}Trigonometry: '<S13>/Sin' incorporates:
 *  Gain: '<S13>/Gain1'
 */
    Model_B.Sin_i = std::sin(Model_P.Gain1_Gain_f * Model_B.SteeringangleFL);
    /* {S!d776}Trigonometry: '<S13>/Sin1' incorporates:
 *  Gain: '<S13>/Gain2'
 */
    Model_B.Sin1_j = std::sin(Model_P.Gain2_Gain_l * Model_B.SteeringangleFR);
}
/* {S!d778}Lookup_n-D: '<S17>/2-D Lookup Table1' incorporates:
 *  Constant: '<S4>/Constant3'
 */
rtb_IC4_idx_1 = look2_binlxpw(Model_P.Constant3_Value, rtb_IC4_idx_1, Model_P.Fz, Model_P.SR, Model_P.Fx, Model_P.uDLookupTable1_maxIndex_h, 41U);
/* {S!d780}Lookup_n-D: '<S18>/2-D Lookup Table1' incorporates:
 *  Constant: '<S4>/Constant4'
 */
rtb_IC4_idx_2 = look2_binlxpw(Model_P.Constant4_Value, rtb_IC5_idx_3, Model_P.Fz, Model_P.SR, Model_P.Fx, Model_P.uDLookupTable1_maxIndex_h2, 41U);
/* {S!d786}InitialCondition: '<S6>/IC' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC_FirstOutputTime_f == (rtMinusInf)) || (Model_DW.IC_FirstOutputTime_f == Gain1_c_tmp)) {
    Model_DW.IC_FirstOutputTime_f = Gain1_c_tmp;
    /* {S!d782}InitialCondition: '<S6>/IC' */
    Model_B.IC = Model_P.IC_Value_n;
} else {
    /* {S!d784}InitialCondition: '<S6>/IC' incorporates:
 *  Gain: '<S13>/Gain'
 *  Gain: '<S1>/Gain5'
 *  Product: '<S13>/Product'
 *  Product: '<S13>/Product1'
 *  Product: '<S13>/Product2'
 *  Product: '<S13>/Product3'
 *  Sum: '<S13>/Add1'
 */
    Model_B.IC = ((((((Model_B.Cos_p * rtb_MotorTorqueNm + Model_B.Cos1_a * rtb_uDLookupTable1_e) + rtb_IC4_idx_1) + rtb_IC4_idx_2) + Model_B.Sin_i * rtb_BrakeTorque) + Model_B.Sin1_j * rtb_SteeringangleIN) - Model_P.Cd * rtb_Gain2) * (1.0 / Model_P.mass);
}
if (rtmIsMajorTimeStep(Model_M)) {
    /* {S!d788}Trigonometry: '<S14>/Cos' */
    Model_B.Cos_b = std::cos(Model_B.SteeringangleFL);
    /* {S!d790}Trigonometry: '<S14>/Cos1' */
    Model_B.Cos1_b = std::cos(Model_B.SteeringangleFR);
    /* {S!d792}Trigonometry: '<S14>/Sin' incorporates:
 *  Gain: '<S14>/Gain1'
 */
    Model_B.Sin_ib = std::sin(Model_P.Gain1_Gain_b * Model_B.SteeringangleFL);
    /* {S!d794}Trigonometry: '<S14>/Sin1' incorporates:
 *  Gain: '<S14>/Gain4'
 */
    Model_B.Sin1_h = std::sin(Model_P.Gain4_Gain_g * Model_B.SteeringangleFR);
}
/* {S!d800}InitialCondition: '<S6>/IC2' incorporates:
 *  InitialCondition: '<S5>/IC'
 */
if ((Model_DW.IC2_FirstOutputTime_j == (rtMinusInf)) || (Model_DW.IC2_FirstOutputTime_j == Gain1_c_tmp)) {
    Model_DW.IC2_FirstOutputTime_j = Gain1_c_tmp;
    /* {S!d796}InitialCondition: '<S6>/IC2' */
    Model_B.IC2 = Model_P.IC2_Value_b;
} else {
    /* {S!d798}InitialCondition: '<S6>/IC2' incorporates:
 *  Gain: '<S14>/Gain'
 *  Gain: '<S14>/Gain10'
 *  Gain: '<S14>/Gain11'
 *  Gain: '<S14>/Gain12'
 *  Gain: '<S14>/Gain13'
 *  Gain: '<S14>/Gain14'
 *  Gain: '<S14>/Gain15'
 *  Gain: '<S14>/Gain2'
 *  Gain: '<S14>/Gain5'
 *  Gain: '<S14>/Gain6'
 *  Gain: '<S14>/Gain7'
 *  Gain: '<S14>/Gain8'
 *  Gain: '<S14>/Gain9'
 *  Product: '<S14>/Product'
 *  Product: '<S14>/Product1'
 *  Product: '<S14>/Product2'
 *  Product: '<S14>/Product3'
 *  Product: '<S14>/Product4'
 *  Product: '<S14>/Product5'
 *  Product: '<S14>/Product6'
 *  Product: '<S14>/Product7'
 *  Sum: '<S14>/Add3'
 */
    Model_B.IC2 = (((((((((((Model_B.Cos_b * rtb_MotorTorqueNm * Model_P.half_track + Model_B.Cos1_b * rtb_uDLookupTable1_e * -Model_P.half_track) + Model_P.half_track * rtb_IC4_idx_1) + -Model_P.half_track * rtb_IC4_idx_2) + Model_B.Sin_ib * rtb_BrakeTorque * Model_P.half_track) + Model_B.Sin1_h * rtb_SteeringangleIN * -Model_P.half_track) + -Model_P.lr * rtb_Subtract_p) + -Model_P.lr * rtb_uDLookupTable) + Model_B.Cos_b * rtb_BrakeTorque * Model_P.lf) + Model_B.Cos1_b * rtb_SteeringangleIN * Model_P.lf) + Model_B.Sin_ib * rtb_MotorTorqueNm * -Model_P.lf) + Model_B.Sin1_h * rtb_uDLookupTable1_e * -Model_P.lf) * (1.0 / Model_P.Iz_wehicle);
}
/* {S!d802}Gain: '<S34>/Gain1' incorporates:
 *  Constant: '<S34>/Constant4'
 *  Product: '<S34>/Product'
 *  Sum: '<S34>/Add1'
 */
Model_B.Gain1 = ((0.0 - Model_P.tire_radius * rtb_MotorTorqueNm) - Model_B.BrakeTorque) * (1.0 / Model_P.Iz_wheel);
/* {S!d804}Gain: '<S35>/Gain1' incorporates:
 *  Constant: '<S35>/Constant4'
 *  Product: '<S35>/Product'
 *  Sum: '<S35>/Add1'
 */
Model_B.Gain1_b = ((0.0 - Model_P.tire_radius * rtb_uDLookupTable1_e) - Model_B.BrakeTorque) * (1.0 / Model_P.Iz_wheel);
/* {S!d806}Sum: '<S36>/Add2' incorporates:
 *  Sum: '<S37>/Add2'
 */
Gain1_c_tmp = Model_B.MotorTorque - Model_B.BrakeTorque;
/* {S!d808}Gain: '<S36>/Gain1' incorporates:
 *  Constant: '<S36>/Constant4'
 *  Product: '<S36>/Product'
 *  Sum: '<S36>/Add2'
 */
Model_B.Gain1_c = (Gain1_c_tmp - Model_P.tire_radius * rtb_IC4_idx_1) * (1.0 / Model_P.Iz_wheel);
/* {S!d810}Gain: '<S37>/Gain1' incorporates:
 *  Constant: '<S37>/Constant4'
 *  Product: '<S37>/Product'
 *  Sum: '<S37>/Add2'
 */
Model_B.Gain1_n = (Gain1_c_tmp - Model_P.tire_radius * rtb_IC4_idx_2) * (1.0 / Model_P.Iz_wheel);






        



                
                    if (rtmIsMajorTimeStep(Model_M)) {
                        /* Matfile logging */
            
    rt_UpdateTXYLogVars(Model_M->rtwLogInfo, (Model_M->Timing.t));

                } /* end MajorTimeStep */





                    

        if (rtmIsMajorTimeStep(Model_M)) {


        
            /* signal main to stop simulation */
            { /* Sample time: [0.0s, 0.0s] */
            if ( (rtmGetTFinal(Model_M)!=-1) &&
            !((rtmGetTFinal(Model_M)-(((Model_M->Timing.clockTick1+Model_M->Timing.clockTickH1* 4294967296.0))  * 0.84)) > (((Model_M->Timing.clockTick1+Model_M->Timing.clockTickH1* 4294967296.0))  * 0.84) * (DBL_EPSILON))) {
                rtmSetErrorStatus(Model_M, "Simulation finished");
            }
            }

                rt_ertODEUpdateContinuousStates(&Model_M->solverInfo);

                        /* Update absolute time for base rate */
                        /* The "clockTick0" counts the number of times the code of this task has
        * been executed. The absolute time is the multiplication of "clockTick0"
        * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        * overflow during the application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick0 and the high bits
            * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
        */

        if(!(++Model_M->Timing.clockTick0)) {
 ++Model_M->Timing.clockTickH0; 
}  Model_M->Timing.t[0] = rtsiGetSolverStopTime(&Model_M->solverInfo);


                {
            /* Update absolute timer for sample time: [0.84s, 0.0s] */
                        /* The "clockTick1" counts the number of times the code of this task has
        * been executed. The resolution of this integer timer is 0.84, which is the step size
        * of the task. Size of "clockTick1" ensures timer will not overflow during the
        * application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick1 and the high bits
            * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
        */

        Model_M->Timing.clockTick1++;
 if (!Model_M->Timing.clockTick1) {
 Model_M->Timing.clockTickH1++; 
}

        }

            





        

    } /* end MajorTimeStep */


            


        
        



                


        } 
        
                                    /* Derivatives for root system: '<Root>' */
                
        void Model_derivatives(void)
        {

            

            
    
XDot_Model_T *_rtXdot;

    




                                
        
    




                                                
                                    _rtXdot = ((XDot_Model_T *) Model_M->derivs);
/* Derivatives for Integrator: '<S5>/Integrator3' */
_rtXdot->Integrator3_CSTATE = Model_B.IC;
/* Derivatives for Integrator: '<S5>/Integrator6' */
_rtXdot->Integrator6_CSTATE = Model_B.YACCms2;
/* Derivatives for Integrator: '<S5>/Integrator4' */
_rtXdot->Integrator4_CSTATE = Model_B.IC2;
/* Derivatives for Integrator: '<S34>/Integrator2' */
_rtXdot->Integrator2_CSTATE = Model_B.Gain1;
/* Derivatives for Integrator: '<S35>/Integrator2' */
_rtXdot->Integrator2_CSTATE_o = Model_B.Gain1_b;
/* Derivatives for Integrator: '<S37>/Integrator1' */
_rtXdot->Integrator1_CSTATE = Model_B.Gain1_n;
/* Derivatives for Integrator: '<S36>/Integrator1' */
_rtXdot->Integrator1_CSTATE_o = Model_B.Gain1_c;
/* Derivatives for Integrator: '<S5>/Integrator' */
_rtXdot->Integrator_CSTATE = Model_B.IC;
/* Derivatives for Integrator: '<S5>/Integrator1' */
_rtXdot->Integrator1_CSTATE_i = Model_B.IC2;
/* Derivatives for Integrator: '<S5>/Integrator2' */
_rtXdot->Integrator2_CSTATE_i = Model_B.IC1;
/* Derivatives for Integrator: '<S5>/Integrator5' */
_rtXdot->Integrator5_CSTATE = Model_B.V_xms;
/* Derivatives for Integrator: '<S5>/Integrator7' */
_rtXdot->Integrator7_CSTATE = Model_B.V_yms;





    




                
        
                }
            














    





    /* Model initialize function */
    
            void Model_initialize(void)
    {
            


    




    
        

        



            /* Registration code */
                
    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    
        





            
            
        {
            /* Setup solver object */

                rtsiSetSimTimeStepPtr(&Model_M->solverInfo, &Model_M->Timing.simTimeStep);
            rtsiSetTPtr(&Model_M->solverInfo, &rtmGetTPtr(Model_M));
                rtsiSetStepSizePtr(&Model_M->solverInfo, &Model_M->Timing.stepSize0);
                rtsiSetdXPtr(&Model_M->solverInfo, &Model_M->derivs);
                rtsiSetContStatesPtr(&Model_M->solverInfo, (real_T **) &Model_M->contStates);
                rtsiSetNumContStatesPtr(&Model_M->solverInfo, &Model_M->Sizes.numContStates);
                    rtsiSetNumPeriodicContStatesPtr(&Model_M->solverInfo, &Model_M->Sizes.numPeriodicContStates);
                    rtsiSetPeriodicContStateIndicesPtr(&Model_M->solverInfo, &Model_M->periodicContStateIndices);
                    rtsiSetPeriodicContStateRangesPtr(&Model_M->solverInfo, &Model_M->periodicContStateRanges);


            rtsiSetErrorStatusPtr(&Model_M->solverInfo, (&rtmGetErrorStatus(Model_M)));


            rtsiSetRTModelPtr(&Model_M->solverInfo, Model_M);
        }
            rtsiSetSimTimeStep(&Model_M->solverInfo, MAJOR_TIME_STEP);
                    Model_M->intgData.y = Model_M->odeY;
                    Model_M->intgData.f[0] = Model_M->odeF[0];
                    Model_M->intgData.f[1] = Model_M->odeF[1];
                    Model_M->intgData.f[2] = Model_M->odeF[2];
                
                Model_M->contStates = ((X_Model_T *) &Model_X);



                rtsiSetSolverData(&Model_M->solverInfo, static_cast<void *>(&Model_M->intgData));
                rtsiSetIsMinorTimeStepWithModeChange(&Model_M->solverInfo, false);
        rtsiSetSolverName(&Model_M->solverInfo,"ode3");





            rtmSetTPtr(Model_M, &Model_M->Timing.tArray[0]);







                            rtmSetTFinal(Model_M, 42.0);
                                Model_M->Timing.stepSize0  = 0.84;


                    






                    
        /* Setup for data logging */
        {
                static RTWLogInfo rt_DataLoggingInfo;
                rt_DataLoggingInfo.loggingInterval = (nullptr);

                        Model_M->rtwLogInfo = &rt_DataLoggingInfo;

        }


    /* Setup for data logging */
    {
                        rtliSetLogXSignalInfo(Model_M->rtwLogInfo, (nullptr));

                        rtliSetLogXSignalPtrs(Model_M->rtwLogInfo, (nullptr));


                    rtliSetLogT(Model_M->rtwLogInfo, "tout");

                    rtliSetLogX(Model_M->rtwLogInfo, "");

                    rtliSetLogXFinal(Model_M->rtwLogInfo, "");

                    rtliSetLogVarNameModifier(Model_M->rtwLogInfo, "rt_");

                    rtliSetLogFormat(Model_M->rtwLogInfo, 4);

                    rtliSetLogMaxRows(Model_M->rtwLogInfo, 0);

                    rtliSetLogDecimation(Model_M->rtwLogInfo, 1);





                        rtliSetLogY(Model_M->rtwLogInfo, "");


                        rtliSetLogYSignalInfo(Model_M->rtwLogInfo, (nullptr));

                        rtliSetLogYSignalPtrs(Model_M->rtwLogInfo, (nullptr));

    }









        




        /* block I/O */
        
        


                
                (void) std::memset((static_cast<void *>(&Model_B)), 0,
sizeof(B_Model_T));
                

                





        























        



            /* states (continuous) */
            {
                
                (void) std::memset(static_cast<void *>(&Model_X), 0,
sizeof(X_Model_T));


            }






        /* states (dwork) */
        
        



                                        (void) std::memset(static_cast<void *>(&Model_DW),  0,
 sizeof(DW_Model_T));
                    






        
    


        
        
        


        




        







        

    
            
    
        




        /* Matfile logging */
        
    rt_StartDataLoggingWithStartTime(Model_M->rtwLogInfo, 0.0, rtmGetTFinal(Model_M), Model_M->Timing.stepSize0, (&rtmGetErrorStatus(Model_M)));









            
        




                        




                
                                    
                                    /* Start for InitialCondition: '<S5>/IC' */
Model_DW.IC_FirstOutputTime = (rtMinusInf);
/* Start for InitialCondition: '<S5>/IC2' */
Model_DW.IC2_FirstOutputTime = (rtMinusInf);
/* Start for InitialCondition: '<S19>/IC4' */
Model_DW.IC4_FirstOutputTime = (rtMinusInf);
/* Start for InitialCondition: '<S34>/IC' */
Model_DW.IC_FirstOutputTime_d = (rtMinusInf);
/* Start for InitialCondition: '<S35>/IC' */
Model_DW.IC_FirstOutputTime_h = (rtMinusInf);
/* Start for InitialCondition: '<S37>/IC' */
Model_DW.IC_FirstOutputTime_a = (rtMinusInf);
/* Start for InitialCondition: '<S36>/IC' */
Model_DW.IC_FirstOutputTime_g = (rtMinusInf);
/* Start for InitialCondition: '<S19>/IC5' */
Model_DW.IC5_FirstOutputTime = (rtMinusInf);
/* Start for InitialCondition: '<S6>/IC1' */
Model_DW.IC1_FirstOutputTime = (rtMinusInf);
/* Start for InitialCondition: '<S5>/IC1' */
Model_DW.IC1_FirstOutputTime_d = (rtMinusInf);
/* Start for InitialCondition: '<S6>/IC' */
Model_DW.IC_FirstOutputTime_f = (rtMinusInf);
/* Start for InitialCondition: '<S6>/IC2' */
Model_DW.IC2_FirstOutputTime_j = (rtMinusInf);




        




                



        




                




                                                
                                    

/* InitializeConditions for Integrator: '<S5>/Integrator3' */
Model_X.Integrator3_CSTATE = Model_P.Integrator3_IC;
/* InitializeConditions for Integrator: '<S5>/Integrator6' */
Model_X.Integrator6_CSTATE = Model_P.Integrator6_IC;
/* InitializeConditions for Integrator: '<S5>/Integrator4' */
Model_X.Integrator4_CSTATE = Model_P.Integrator4_IC;
/* InitializeConditions for Integrator: '<S34>/Integrator2' */
Model_X.Integrator2_CSTATE = Model_P.Integrator2_IC;
/* InitializeConditions for Integrator: '<S35>/Integrator2' */
Model_X.Integrator2_CSTATE_o = Model_P.Integrator2_IC_i;
/* InitializeConditions for Integrator: '<S37>/Integrator1' */
Model_X.Integrator1_CSTATE = Model_P.Integrator1_IC;
/* InitializeConditions for Integrator: '<S36>/Integrator1' */
Model_X.Integrator1_CSTATE_o = Model_P.Integrator1_IC_d;
/* InitializeConditions for Integrator: '<S5>/Integrator' */
Model_X.Integrator_CSTATE = Model_P.Integrator_IC;
/* InitializeConditions for Integrator: '<S5>/Integrator1' */
Model_X.Integrator1_CSTATE_i = Model_P.Integrator1_IC_o;
/* InitializeConditions for Integrator: '<S5>/Integrator2' */
Model_X.Integrator2_CSTATE_i = Model_P.Integrator2_IC_m;
/* InitializeConditions for Integrator: '<S5>/Integrator5' */
Model_X.Integrator5_CSTATE = Model_P.Integrator5_IC;
/* InitializeConditions for Integrator: '<S5>/Integrator7' */
Model_X.Integrator7_CSTATE = Model_P.Integrator7_IC;












                    

    





        



    }        






        




        
        /* Model terminate function */
                    void Model_terminate(void)

        {
            
            /* (no terminate code required) */



                


        }
            





    




    

    

    

    
