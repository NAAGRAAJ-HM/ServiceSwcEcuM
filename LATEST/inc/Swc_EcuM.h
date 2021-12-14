#pragma once

class class_Swc_EcuM{
   public:
      void StartPreOs             (void);
      void StartPostOs            (void);
      void OffPreOs               (void);
      void OffPostOs              (void);
      void EnableWakeupSources    (void);
      void GenerateRamHash        (void);
      void CheckRamHash           (void);
      void ErrorHook              (void);
};

extern class_Swc_EcuM Swc_EcuM;

