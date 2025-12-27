average_Mz_FL = mean(out.Mz_FL.signals.values);
average_Mz_FR = mean(out.Mz_FR.signals.values);
average_Mz_RL = mean(out.Mz_RL.signals.values);
average_Mz_RR = mean(out.Mz_RR.signals.values);

average_Fx_FL = mean(out.Fx_FL.signals.values);
average_Fx_FR = mean(out.Fx_FR.signals.values);
average_Fx_RL = mean(out.Fx_RL.signals.values);
average_Fx_RR = mean(out.Fx_RR.signals.values);

average_Fy_FL = mean(out.Fy_FL.signals.values);
average_Fy_FR = mean(out.Fy_FR.signals.values);
average_Fy_RL = mean(out.Fy_RL.signals.values);
average_Fy_RR = mean(out.Fy_RR.signals.values);

average_Fz_FL = mean(out.Fz_FL.signals.values);
average_Fz_FR = mean(out.Fz_FR.signals.values);
average_Fz_RL = mean(out.Fz_RL.signals.values);
average_Fz_RR = mean(out.Fz_RR.signals.values);

Forces = table([average_Fx_FL; average_Fy_FL; average_Fz_FL;average_Mz_FL], [average_Fx_FR; average_Fy_FR;average_Fz_FR;average_Mz_FR], ...
    [average_Fx_RL; average_Fy_RL;average_Fz_RL;average_Mz_RL],[average_Fx_RR; average_Fy_RR;average_Fz_RR;average_Mz_RR]);