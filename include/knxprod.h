#pragma once


#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
                                             
#define MAIN_OpenKnxId 0xA0
#define MAIN_ApplicationNumber 2
#define MAIN_ApplicationVersion 53
#define MAIN_ParameterSize 18665
#define MAIN_MaxKoNumber 1509
#define MAIN_OrderNumber "OpenKnxPresenceBig"
#define BASE_ModuleVersion 18
#define UCT_ModuleVersion 2
#define PM_ModuleVersion 53
#define BTN_ModuleVersion 5
#define LOG_ModuleVersion 52
// Parameter with single occurrence


#define BASE_StartupDelayBase                     0      // 2 Bits, Bit 7-6
#define     BASE_StartupDelayBaseMask 0xC0
#define     BASE_StartupDelayBaseShift 6
#define BASE_StartupDelayTime                     0      // 14 Bits, Bit 13-0
#define     BASE_StartupDelayTimeMask 0x3FFF
#define     BASE_StartupDelayTimeShift 0
#define BASE_HeartbeatDelayBase                   2      // 2 Bits, Bit 7-6
#define     BASE_HeartbeatDelayBaseMask 0xC0
#define     BASE_HeartbeatDelayBaseShift 6
#define BASE_HeartbeatDelayTime                   2      // 14 Bits, Bit 13-0
#define     BASE_HeartbeatDelayTimeMask 0x3FFF
#define     BASE_HeartbeatDelayTimeShift 0
#define BASE_Timezone                             4      // 5 Bits, Bit 7-3
#define     BASE_TimezoneMask 0xF8
#define     BASE_TimezoneShift 3
#define BASE_TimezoneSign                         4      // 1 Bit, Bit 7
#define     BASE_TimezoneSignMask 0x80
#define     BASE_TimezoneSignShift 7
#define BASE_TimezoneValue                        4      // 4 Bits, Bit 6-3
#define     BASE_TimezoneValueMask 0x78
#define     BASE_TimezoneValueShift 3
#define BASE_CombinedTimeDate                     4      // 1 Bit, Bit 2
#define     BASE_CombinedTimeDateMask 0x04
#define     BASE_CombinedTimeDateShift 2
#define BASE_SummertimeAll                        4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeAllMask 0x03
#define     BASE_SummertimeAllShift 0
#define BASE_SummertimeDE                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeDEMask 0x03
#define     BASE_SummertimeDEShift 0
#define BASE_SummertimeWorld                      4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeWorldMask 0x03
#define     BASE_SummertimeWorldShift 0
#define BASE_SummertimeKO                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeKOMask 0x03
#define     BASE_SummertimeKOShift 0
#define BASE_Latitude                             5      // float
#define BASE_Longitude                            9      // float
#define BASE_Diagnose                            14      // 1 Bit, Bit 7
#define     BASE_DiagnoseMask 0x80
#define     BASE_DiagnoseShift 7
#define BASE_Watchdog                            14      // 1 Bit, Bit 6
#define     BASE_WatchdogMask 0x40
#define     BASE_WatchdogShift 6
#define BASE_ReadTimeDate                        14      // 1 Bit, Bit 5
#define     BASE_ReadTimeDateMask 0x20
#define     BASE_ReadTimeDateShift 5
#define BASE_HeartbeatExtended                   14      // 1 Bit, Bit 4
#define     BASE_HeartbeatExtendedMask 0x10
#define     BASE_HeartbeatExtendedShift 4
#define BASE_ManualSave                          14      // 3 Bits, Bit 2-0
#define     BASE_ManualSaveMask 0x07
#define     BASE_ManualSaveShift 0
#define BASE_PeriodicSave                        15      // 8 Bits, Bit 7-0
#define BASE_Dummy                               45      // uint8_t

// Zeitbasis
#define ParamBASE_StartupDelayBase                    ((knx.paramByte(BASE_StartupDelayBase) & BASE_StartupDelayBaseMask) >> BASE_StartupDelayBaseShift)
// Zeit
#define ParamBASE_StartupDelayTime                    (knx.paramWord(BASE_StartupDelayTime) & BASE_StartupDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_StartupDelayTimeMS                  (paramDelay(knx.paramWord(BASE_StartupDelayTime)))
// Zeitbasis
#define ParamBASE_HeartbeatDelayBase                  ((knx.paramByte(BASE_HeartbeatDelayBase) & BASE_HeartbeatDelayBaseMask) >> BASE_HeartbeatDelayBaseShift)
// Zeit
#define ParamBASE_HeartbeatDelayTime                  (knx.paramWord(BASE_HeartbeatDelayTime) & BASE_HeartbeatDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_HeartbeatDelayTimeMS                (paramDelay(knx.paramWord(BASE_HeartbeatDelayTime)))
// Zeitzone
#define ParamBASE_Timezone                            ((knx.paramByte(BASE_Timezone) & BASE_TimezoneMask) >> BASE_TimezoneShift)
// Zeitzone-Vorzeichen
#define ParamBASE_TimezoneSign                        ((bool)(knx.paramByte(BASE_TimezoneSign) & BASE_TimezoneSignMask))
// Zeitzone-Wert
#define ParamBASE_TimezoneValue                       ((knx.paramByte(BASE_TimezoneValue) & BASE_TimezoneValueMask) >> BASE_TimezoneValueShift)
// Empfangen über
#define ParamBASE_CombinedTimeDate                    ((bool)(knx.paramByte(BASE_CombinedTimeDate) & BASE_CombinedTimeDateMask))
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeAll                       (knx.paramByte(BASE_SummertimeAll) & BASE_SummertimeAllMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeDE                        (knx.paramByte(BASE_SummertimeDE) & BASE_SummertimeDEMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeWorld                     (knx.paramByte(BASE_SummertimeWorld) & BASE_SummertimeWorldMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeKO                        (knx.paramByte(BASE_SummertimeKO) & BASE_SummertimeKOMask)
// Breitengrad
#define ParamBASE_Latitude                            (knx.paramFloat(BASE_Latitude, Float_Enc_IEEE754Single))
// Längengrad
#define ParamBASE_Longitude                           (knx.paramFloat(BASE_Longitude, Float_Enc_IEEE754Single))
// Diagnoseobjekt anzeigen
#define ParamBASE_Diagnose                            ((bool)(knx.paramByte(BASE_Diagnose) & BASE_DiagnoseMask))
// Watchdog aktivieren
#define ParamBASE_Watchdog                            ((bool)(knx.paramByte(BASE_Watchdog) & BASE_WatchdogMask))
// Bei Neustart vom Bus lesen
#define ParamBASE_ReadTimeDate                        ((bool)(knx.paramByte(BASE_ReadTimeDate) & BASE_ReadTimeDateMask))
// Erweitertes "In Betrieb"
#define ParamBASE_HeartbeatExtended                   ((bool)(knx.paramByte(BASE_HeartbeatExtended) & BASE_HeartbeatExtendedMask))
// Manuelles speichern
#define ParamBASE_ManualSave                          (knx.paramByte(BASE_ManualSave) & BASE_ManualSaveMask)
// Zyklisches speichern
#define ParamBASE_PeriodicSave                        (knx.paramByte(BASE_PeriodicSave))
// 
#define ParamBASE_Dummy                               (knx.paramByte(BASE_Dummy))

#define BASE_KoHeartbeat 1
#define BASE_KoTime 2
#define BASE_KoDate 3
#define BASE_KoDiagnose 7
#define BASE_KoIsSummertime 10
#define BASE_KoManualSave 11

// In Betrieb
#define KoBASE_Heartbeat                           (knx.getGroupObject(BASE_KoHeartbeat))
// Uhrzeit/Datum
#define KoBASE_Time                                (knx.getGroupObject(BASE_KoTime))
// Datum
#define KoBASE_Date                                (knx.getGroupObject(BASE_KoDate))
// Diagnose
#define KoBASE_Diagnose                            (knx.getGroupObject(BASE_KoDiagnose))
// Sommerzeit aktiv
#define KoBASE_IsSummertime                        (knx.getGroupObject(BASE_KoIsSummertime))
// Speichern
#define KoBASE_ManualSave                          (knx.getGroupObject(BASE_KoManualSave))



#define PM_VisibleChannels                     46      // uint8_t
#define PM_LEDPresence                         47      // 2 Bits, Bit 7-6
#define     PM_LEDPresenceMask 0xC0
#define     PM_LEDPresenceShift 6
#define PM_LEDMove                             47      // 2 Bits, Bit 5-4
#define     PM_LEDMoveMask 0x30
#define     PM_LEDMoveShift 4
#define PM_PirSensitivity                      47      // 4 Bits, Bit 3-0
#define     PM_PirSensitivityMask 0x0F
#define     PM_PirSensitivityShift 0
#define PM_HfPresence                          48      // 3 Bits, Bit 7-5
#define     PM_HfPresenceMask 0xE0
#define     PM_HfPresenceShift 5
#define PM_HfScenario                          48      // 3 Bits, Bit 4-2
#define     PM_HfScenarioMask 0x1C
#define     PM_HfScenarioShift 2
#define PM_HlkSettings                         48      // 1 Bit, Bit 4
#define     PM_HlkSettingsMask 0x10
#define     PM_HlkSettingsShift 4
#define PM_HWLux                               48      // 2 Bits, Bit 1-0
#define     PM_HWLuxMask 0x03
#define     PM_HWLuxShift 0
#define PM_HfSensitivity                       49      // 4 Bits, Bit 7-4
#define     PM_HfSensitivityMask 0xF0
#define     PM_HfSensitivityShift 4
#define PM_SendRAW                             49      // 1 Bit, Bit 3
#define     PM_SendRAWMask 0x08
#define     PM_SendRAWShift 3
#define PM_ReadLed                             49      // 1 Bit, Bit 2
#define     PM_ReadLedMask 0x04
#define     PM_ReadLedShift 2
#define PM_PirPresence                         49      // 2 Bits, Bit 1-0
#define     PM_PirPresenceMask 0x03
#define     PM_PirPresenceShift 0
#define PM_HfDelayTime                         50      // uint16_t
#define PM_HfRangeGateMin                      52      // 4 Bits, Bit 7-4
#define     PM_HfRangeGateMinMask 0xF0
#define     PM_HfRangeGateMinShift 4
#define PM_HfRangeGateMax                      52      // 4 Bits, Bit 3-0
#define     PM_HfRangeGateMaxMask 0x0F
#define     PM_HfRangeGateMaxShift 0
#define PM_LuxOffsetPM                         53      // int8_t
#define PM_LuxSendDeltaAbsRel                  54      // 1 Bit, Bit 7
#define     PM_LuxSendDeltaAbsRelMask 0x80
#define     PM_LuxSendDeltaAbsRelShift 7
#define PM_LuxSendDelta                        54      // 15 Bits, Bit 14-0
#define     PM_LuxSendDeltaMask 0x7FFF
#define     PM_LuxSendDeltaShift 0
#define PM_LuxSendCycleDelayBase               56      // 2 Bits, Bit 7-6
#define     PM_LuxSendCycleDelayBaseMask 0xC0
#define     PM_LuxSendCycleDelayBaseShift 6
#define PM_LuxSendCycleDelayTime               56      // 14 Bits, Bit 13-0
#define     PM_LuxSendCycleDelayTimeMask 0x3FFF
#define     PM_LuxSendCycleDelayTimeShift 0
#define PM_Trigger00                           58      // uint16_t
#define PM_Trigger01                           60      // uint16_t
#define PM_Trigger02                           62      // uint16_t
#define PM_Trigger03                           64      // uint16_t
#define PM_Trigger04                           66      // uint16_t
#define PM_Trigger05                           68      // uint16_t
#define PM_Trigger06                           70      // uint16_t
#define PM_Trigger07                           72      // uint16_t
#define PM_Trigger08                           74      // uint16_t
#define PM_Trigger09                           76      // uint16_t
#define PM_Trigger10                           78      // uint16_t
#define PM_Trigger11                           80      // uint16_t
#define PM_Trigger12                           82      // uint16_t
#define PM_Trigger13                           84      // uint16_t
#define PM_Trigger14                           86      // uint16_t
#define PM_Trigger15                           88      // uint16_t
#define PM_Hold00                              90      // uint16_t
#define PM_Hold01                              92      // uint16_t
#define PM_Hold02                              94      // uint16_t
#define PM_Hold03                              96      // uint16_t
#define PM_Hold04                              98      // uint16_t
#define PM_Hold05                              100      // uint16_t
#define PM_Hold06                              102      // uint16_t
#define PM_Hold07                              104      // uint16_t
#define PM_Hold08                              106      // uint16_t
#define PM_Hold09                              108      // uint16_t
#define PM_Hold10                              110      // uint16_t
#define PM_Hold11                              112      // uint16_t
#define PM_Hold12                              114      // uint16_t
#define PM_Hold13                              116      // uint16_t
#define PM_Hold14                              118      // uint16_t
#define PM_Hold15                              120      // uint16_t

// Verfügbare Kanäle
#define ParamPM_VisibleChannels                     (knx.paramByte(PM_VisibleChannels))
// LED Präsenz
#define ParamPM_LEDPresence                         ((knx.paramByte(PM_LEDPresence) & PM_LEDPresenceMask) >> PM_LEDPresenceShift)
// LED Bewegung
#define ParamPM_LEDMove                             ((knx.paramByte(PM_LEDMove) & PM_LEDMoveMask) >> PM_LEDMoveShift)
// PIR-Empfindlichkeit
#define ParamPM_PirSensitivity                      (knx.paramByte(PM_PirSensitivity) & PM_PirSensitivityMask)
// HF-Sensor
#define ParamPM_HfPresence                          ((knx.paramByte(PM_HfPresence) & PM_HfPresenceMask) >> PM_HfPresenceShift)
// Detektions-Szenario
#define ParamPM_HfScenario                          ((knx.paramByte(PM_HfScenario) & PM_HfScenarioMask) >> PM_HfScenarioShift)
// HF-Einstellungen
#define ParamPM_HlkSettings                         ((bool)(knx.paramByte(PM_HlkSettings) & PM_HlkSettingsMask))
// Helligkeits-Sensor
#define ParamPM_HWLux                               (knx.paramByte(PM_HWLux) & PM_HWLuxMask)
// HF-Empfindlichkeit
#define ParamPM_HfSensitivity                       ((knx.paramByte(PM_HfSensitivity) & PM_HfSensitivityMask) >> PM_HfSensitivityShift)
// Präsenz-Rohdaten auf den Bus senden?
#define ParamPM_SendRAW                             ((bool)(knx.paramByte(PM_SendRAW) & PM_SendRAWMask))
// Wert nach einem Neustart lesen?
#define ParamPM_ReadLed                             ((bool)(knx.paramByte(PM_ReadLed) & PM_ReadLedMask))
// PIR-Sensor
#define ParamPM_PirPresence                         (knx.paramByte(PM_PirPresence) & PM_PirPresenceMask)
// Haltedauer
#define ParamPM_HfDelayTime                         (knx.paramWord(PM_HfDelayTime))
// Minimale Entfernung
#define ParamPM_HfRangeGateMin                      ((knx.paramByte(PM_HfRangeGateMin) & PM_HfRangeGateMinMask) >> PM_HfRangeGateMinShift)
// Maximale Entfernung
#define ParamPM_HfRangeGateMax                      (knx.paramByte(PM_HfRangeGateMax) & PM_HfRangeGateMaxMask)
// Korrektur Luxwert
#define ParamPM_LuxOffsetPM                         ((int8_t)knx.paramByte(PM_LuxOffsetPM))
// Helligkeitsänderung wird angegeben in
#define ParamPM_LuxSendDeltaAbsRel                  ((bool)(knx.paramByte(PM_LuxSendDeltaAbsRel) & PM_LuxSendDeltaAbsRelMask))
// Senden der Helligkeit bei Änderung um
#define ParamPM_LuxSendDelta                        (knx.paramWord(PM_LuxSendDelta) & PM_LuxSendDeltaMask)
// Zeitbasis
#define ParamPM_LuxSendCycleDelayBase               ((knx.paramByte(PM_LuxSendCycleDelayBase) & PM_LuxSendCycleDelayBaseMask) >> PM_LuxSendCycleDelayBaseShift)
// Zeit
#define ParamPM_LuxSendCycleDelayTime               (knx.paramWord(PM_LuxSendCycleDelayTime) & PM_LuxSendCycleDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamPM_LuxSendCycleDelayTimeMS             (paramDelay(knx.paramWord(PM_LuxSendCycleDelayTime)))
// Trigger
#define ParamPM_Trigger00                           (knx.paramWord(PM_Trigger00))
// Trigger
#define ParamPM_Trigger01                           (knx.paramWord(PM_Trigger01))
// Trigger
#define ParamPM_Trigger02                           (knx.paramWord(PM_Trigger02))
// Trigger
#define ParamPM_Trigger03                           (knx.paramWord(PM_Trigger03))
// Trigger
#define ParamPM_Trigger04                           (knx.paramWord(PM_Trigger04))
// Trigger
#define ParamPM_Trigger05                           (knx.paramWord(PM_Trigger05))
// Trigger
#define ParamPM_Trigger06                           (knx.paramWord(PM_Trigger06))
// Trigger
#define ParamPM_Trigger07                           (knx.paramWord(PM_Trigger07))
// Trigger
#define ParamPM_Trigger08                           (knx.paramWord(PM_Trigger08))
// Trigger
#define ParamPM_Trigger09                           (knx.paramWord(PM_Trigger09))
// Trigger
#define ParamPM_Trigger10                           (knx.paramWord(PM_Trigger10))
// Trigger
#define ParamPM_Trigger11                           (knx.paramWord(PM_Trigger11))
// Trigger
#define ParamPM_Trigger12                           (knx.paramWord(PM_Trigger12))
// Trigger
#define ParamPM_Trigger13                           (knx.paramWord(PM_Trigger13))
// Trigger
#define ParamPM_Trigger14                           (knx.paramWord(PM_Trigger14))
// Trigger
#define ParamPM_Trigger15                           (knx.paramWord(PM_Trigger15))
// Halten
#define ParamPM_Hold00                              (knx.paramWord(PM_Hold00))
// Halten
#define ParamPM_Hold01                              (knx.paramWord(PM_Hold01))
// Halten
#define ParamPM_Hold02                              (knx.paramWord(PM_Hold02))
// Halten
#define ParamPM_Hold03                              (knx.paramWord(PM_Hold03))
// Halten
#define ParamPM_Hold04                              (knx.paramWord(PM_Hold04))
// Halten
#define ParamPM_Hold05                              (knx.paramWord(PM_Hold05))
// Halten
#define ParamPM_Hold06                              (knx.paramWord(PM_Hold06))
// Halten
#define ParamPM_Hold07                              (knx.paramWord(PM_Hold07))
// Halten
#define ParamPM_Hold08                              (knx.paramWord(PM_Hold08))
// Halten
#define ParamPM_Hold09                              (knx.paramWord(PM_Hold09))
// Halten
#define ParamPM_Hold10                              (knx.paramWord(PM_Hold10))
// Halten
#define ParamPM_Hold11                              (knx.paramWord(PM_Hold11))
// Halten
#define ParamPM_Hold12                              (knx.paramWord(PM_Hold12))
// Halten
#define ParamPM_Hold13                              (knx.paramWord(PM_Hold13))
// Halten
#define ParamPM_Hold14                              (knx.paramWord(PM_Hold14))
// Halten
#define ParamPM_Hold15                              (knx.paramWord(PM_Hold15))

#define PM_KoLuxOut 20
#define PM_KoPresenceOut 21
#define PM_KoMoveOut 22
#define PM_KoMoveSpeedOut 23
#define PM_KoLEDPresence 24
#define PM_KoLEDMove 25
#define PM_KoScenario 26
#define PM_KoHfSensitivity 27
#define PM_KoHfReset 28
#define PM_KoPirSensitivity 29

// Ausgang Helligkeitssensor
#define KoPM_LuxOut                              (knx.getGroupObject(PM_KoLuxOut))
// Ausgang Präsenz
#define KoPM_PresenceOut                         (knx.getGroupObject(PM_KoPresenceOut))
// Ausgang Bewegung (0=keine, 1=radial, 2=nähern, 3=entf.)
#define KoPM_MoveOut                             (knx.getGroupObject(PM_KoMoveOut))
// Ausgang Entfernung
#define KoPM_MoveSpeedOut                        (knx.getGroupObject(PM_KoMoveSpeedOut))
// Eingang LED Präsenz
#define KoPM_LEDPresence                         (knx.getGroupObject(PM_KoLEDPresence))
// Eingang LED Bewegung
#define KoPM_LEDMove                             (knx.getGroupObject(PM_KoLEDMove))
// Eingang Szenario
#define KoPM_Scenario                            (knx.getGroupObject(PM_KoScenario))
// Hf-Empfindlichkeit
#define KoPM_HfSensitivity                       (knx.getGroupObject(PM_KoHfSensitivity))
// Reset HF-Sensor
#define KoPM_HfReset                             (knx.getGroupObject(PM_KoHfReset))
// PIR-Empfindlichkeit
#define KoPM_PirSensitivity                      (knx.getGroupObject(PM_KoPirSensitivity))

#define PM_ChannelCount 40

// Parameter per channel
#define PM_ParamBlockOffset 122
#define PM_ParamBlockSize 138
#define PM_ParamCalcIndex(index) (index + PM_ParamBlockOffset + _channelIndex * PM_ParamBlockSize)

#define PM_pPresenceInputs                      0      // 3 Bits, Bit 7-5
#define     PM_pPresenceInputsMask 0xE0
#define     PM_pPresenceInputsShift 5
#define PM_pPresenceType                        0      // 1 Bit, Bit 4
#define     PM_pPresenceTypeMask 0x10
#define     PM_pPresenceTypeShift 4
#define PM_pMoveType                            0      // 1 Bit, Bit 3
#define     PM_pMoveTypeMask 0x08
#define     PM_pMoveTypeShift 3
#define PM_pPhaseBool                           0      // 1 Bit, Bit 2
#define     PM_pPhaseBoolMask 0x04
#define     PM_pPhaseBoolShift 2
#define PM_pPhaseCount                          0      // 2 Bits, Bit 1-0
#define     PM_pPhaseCountMask 0x03
#define     PM_pPhaseCountShift 0
#define PM_pOutput1Type                         1      // 3 Bits, Bit 7-5
#define     PM_pOutput1TypeMask 0xE0
#define     PM_pOutput1TypeShift 5
#define PM_pOutput2Type                         1      // 3 Bits, Bit 4-2
#define     PM_pOutput2TypeMask 0x1C
#define     PM_pOutput2TypeShift 2
#define PM_pChannelActive                       1      // 2 Bits, Bit 1-0
#define     PM_pChannelActiveMask 0x03
#define     PM_pChannelActiveShift 0
#define PM_pBrightnessIndependent               2      // 1 Bit, Bit 7
#define     PM_pBrightnessIndependentMask 0x80
#define     PM_pBrightnessIndependentShift 7
#define PM_pBrightnessIntern                    2      // 1 Bit, Bit 6
#define     PM_pBrightnessInternMask 0x40
#define     PM_pBrightnessInternShift 6
#define PM_pLockType                            2      // 2 Bits, Bit 4-3
#define     PM_pLockTypeMask 0x18
#define     PM_pLockTypeShift 3
#define PM_pLockActive                          2      // 1 Bit, Bit 2
#define     PM_pLockActiveMask 0x04
#define     PM_pLockActiveShift 2
#define PM_pLockOn                              2      // 2 Bits, Bit 1-0
#define     PM_pLockOnMask 0x03
#define     PM_pLockOnShift 0
#define PM_pLockOff                             3      // 2 Bits, Bit 7-6
#define     PM_pLockOffMask 0xC0
#define     PM_pLockOffShift 6
#define PM_pLockFallback                        3      // 1 Bit, Bit 5
#define     PM_pLockFallbackMask 0x20
#define     PM_pLockFallbackShift 5
#define PM_pPhaseChange                         3      // 1 Bit, Bit 4
#define     PM_pPhaseChangeMask 0x10
#define     PM_pPhaseChangeShift 4
#define PM_pPresenceUsage                       3      // 2 Bits, Bit 3-2
#define     PM_pPresenceUsageMask 0x0C
#define     PM_pPresenceUsageShift 2
#define PM_pPresenceUsagePIR                    3      // 2 Bits, Bit 3-2
#define     PM_pPresenceUsagePIRMask 0x0C
#define     PM_pPresenceUsagePIRShift 2
#define PM_pAutoOffIsLeave                      3      // 1 Bit, Bit 1
#define     PM_pAutoOffIsLeaveMask 0x02
#define     PM_pAutoOffIsLeaveShift 1
#define PM_pManualModeKeyCount                  3      // 1 Bit, Bit 0
#define     PM_pManualModeKeyCountMask 0x01
#define     PM_pManualModeKeyCountShift 0
#define PM_pBrightnessRead                      4      // 1 Bit, Bit 7
#define     PM_pBrightnessReadMask 0x80
#define     PM_pBrightnessReadShift 7
#define PM_pStartReadLux                        4      // 1 Bit, Bit 6
#define     PM_pStartReadLuxMask 0x40
#define     PM_pStartReadLuxShift 6
#define PM_pStartReadPresence1                  4      // 1 Bit, Bit 5
#define     PM_pStartReadPresence1Mask 0x20
#define     PM_pStartReadPresence1Shift 5
#define PM_pStartReadPresence2                  4      // 1 Bit, Bit 4
#define     PM_pStartReadPresence2Mask 0x10
#define     PM_pStartReadPresence2Shift 4
#define PM_pStartReadAktorState                 4      // 1 Bit, Bit 3
#define     PM_pStartReadAktorStateMask 0x08
#define     PM_pStartReadAktorStateShift 3
#define PM_pStartReadLock                       4      // 1 Bit, Bit 2
#define     PM_pStartReadLockMask 0x04
#define     PM_pStartReadLockShift 2
#define PM_pStartReadDayPhase                   4      // 1 Bit, Bit 1
#define     PM_pStartReadDayPhaseMask 0x02
#define     PM_pStartReadDayPhaseShift 1
#define PM_pStartReadScene                      4      // 1 Bit, Bit 0
#define     PM_pStartReadSceneMask 0x01
#define     PM_pStartReadSceneShift 0
#define PM_pLeaveRoomModeAll                    5      // 3 Bits, Bit 7-5
#define     PM_pLeaveRoomModeAllMask 0xE0
#define     PM_pLeaveRoomModeAllShift 5
#define PM_pLeaveRoomModeMove                   5      // 3 Bits, Bit 7-5
#define     PM_pLeaveRoomModeMoveMask 0xE0
#define     PM_pLeaveRoomModeMoveShift 5
#define PM_pLeaveRoomModeReset                  5      // 3 Bits, Bit 7-5
#define     PM_pLeaveRoomModeResetMask 0xE0
#define     PM_pLeaveRoomModeResetShift 5
#define PM_pExternalSupportsReset               5      // 2 Bits, Bit 4-3
#define     PM_pExternalSupportsResetMask 0x18
#define     PM_pExternalSupportsResetShift 3
#define PM_pPresenceKeepAlive                   5      // 1 Bit, Bit 2
#define     PM_pPresenceKeepAliveMask 0x04
#define     PM_pPresenceKeepAliveShift 2
#define PM_pMoveKeepAlive                       5      // 1 Bit, Bit 1
#define     PM_pMoveKeepAliveMask 0x02
#define     PM_pMoveKeepAliveShift 1
#define PM_pChannelDelayBase                    6      // 2 Bits, Bit 7-6
#define     PM_pChannelDelayBaseMask 0xC0
#define     PM_pChannelDelayBaseShift 6
#define PM_pChannelDelayTime                    6      // 14 Bits, Bit 13-0
#define     PM_pChannelDelayTimeMask 0x3FFF
#define     PM_pChannelDelayTimeShift 0
#define PM_pLockFallbackBase                    8      // 2 Bits, Bit 7-6
#define     PM_pLockFallbackBaseMask 0xC0
#define     PM_pLockFallbackBaseShift 6
#define PM_pLockFallbackTime                    8      // 14 Bits, Bit 13-0
#define     PM_pLockFallbackTimeMask 0x3FFF
#define     PM_pLockFallbackTimeShift 0
#define PM_pDowntimeOffBase                    10      // 2 Bits, Bit 7-6
#define     PM_pDowntimeOffBaseMask 0xC0
#define     PM_pDowntimeOffBaseShift 6
#define PM_pDowntimeOffTime                    10      // 14 Bits, Bit 13-0
#define     PM_pDowntimeOffTimeMask 0x3FFF
#define     PM_pDowntimeOffTimeShift 0
#define PM_pAdaptiveDelayBase                  12      // 2 Bits, Bit 7-6
#define     PM_pAdaptiveDelayBaseMask 0xC0
#define     PM_pAdaptiveDelayBaseShift 6
#define PM_pAdaptiveDelayTime                  12      // 14 Bits, Bit 13-0
#define     PM_pAdaptiveDelayTimeMask 0x3FFF
#define     PM_pAdaptiveDelayTimeShift 0
#define PM_pPhase1Scene                        14      // 8 Bits, Bit 7-0
#define PM_pPhase2Scene                        15      // 8 Bits, Bit 7-0
#define PM_pPhase3Scene                        16      // 8 Bits, Bit 7-0
#define PM_pPhase4Scene                        17      // 8 Bits, Bit 7-0
#define PM_pScene0                             18      // 8 Bits, Bit 7-0
#define PM_pScene1                             19      // 8 Bits, Bit 7-0
#define PM_pScene2                             20      // 8 Bits, Bit 7-0
#define PM_pScene3                             21      // 8 Bits, Bit 7-0
#define PM_pScene4                             22      // 8 Bits, Bit 7-0
#define PM_pScene5                             23      // 8 Bits, Bit 7-0
#define PM_pScene6                             24      // 8 Bits, Bit 7-0
#define PM_pScene7                             25      // 8 Bits, Bit 7-0
#define PM_pScene8                             26      // 8 Bits, Bit 7-0
#define PM_pScene9                             27      // 8 Bits, Bit 7-0
#define PM_pSceneAction0                       28      // 8 Bits, Bit 7-0
#define PM_pSceneAction1                       29      // 8 Bits, Bit 7-0
#define PM_pSceneAction2                       30      // 8 Bits, Bit 7-0
#define PM_pSceneAction3                       31      // 8 Bits, Bit 7-0
#define PM_pSceneAction4                       32      // 8 Bits, Bit 7-0
#define PM_pSceneAction5                       33      // 8 Bits, Bit 7-0
#define PM_pSceneAction6                       34      // 8 Bits, Bit 7-0
#define PM_pSceneAction7                       35      // 8 Bits, Bit 7-0
#define PM_pSceneAction8                       36      // 8 Bits, Bit 7-0
#define PM_pSceneAction9                       37      // 8 Bits, Bit 7-0
#define PM_pIntLux                             38      // 1 Bit, Bit 7
#define     PM_pIntLuxMask 0x80
#define     PM_pIntLuxShift 7
#define PM_pNumLux                             38      // 15 Bits, Bit 14-0
#define     PM_pNumLuxMask 0x7FFF
#define     PM_pNumLuxShift 0
#define PM_pIntPresence1                       40      // 1 Bit, Bit 7
#define     PM_pIntPresence1Mask 0x80
#define     PM_pIntPresence1Shift 7
#define PM_pNumPresence1                       40      // 15 Bits, Bit 14-0
#define     PM_pNumPresence1Mask 0x7FFF
#define     PM_pNumPresence1Shift 0
#define PM_pIntPresence2                       42      // 1 Bit, Bit 7
#define     PM_pIntPresence2Mask 0x80
#define     PM_pIntPresence2Shift 7
#define PM_pNumPresence2                       42      // 15 Bits, Bit 14-0
#define     PM_pNumPresence2Mask 0x7FFF
#define     PM_pNumPresence2Shift 0
#define PM_pIntSetAuto                         44      // 1 Bit, Bit 7
#define     PM_pIntSetAutoMask 0x80
#define     PM_pIntSetAutoShift 7
#define PM_pNumSetAuto                         44      // 15 Bits, Bit 14-0
#define     PM_pNumSetAutoMask 0x7FFF
#define     PM_pNumSetAutoShift 0
#define PM_pIntSetManual                       46      // 1 Bit, Bit 7
#define     PM_pIntSetManualMask 0x80
#define     PM_pIntSetManualShift 7
#define PM_pNumSetManual                       46      // 15 Bits, Bit 14-0
#define     PM_pNumSetManualMask 0x7FFF
#define     PM_pNumSetManualShift 0
#define PM_pIntActorState                      48      // 1 Bit, Bit 7
#define     PM_pIntActorStateMask 0x80
#define     PM_pIntActorStateShift 7
#define PM_pNumActorState                      48      // 15 Bits, Bit 14-0
#define     PM_pNumActorStateMask 0x7FFF
#define     PM_pNumActorStateShift 0
#define PM_pIntLock                            50      // 1 Bit, Bit 7
#define     PM_pIntLockMask 0x80
#define     PM_pIntLockShift 7
#define PM_pNumLock                            50      // 15 Bits, Bit 14-0
#define     PM_pNumLockMask 0x7FFF
#define     PM_pNumLockShift 0
#define PM_pIntReset                           52      // 1 Bit, Bit 7
#define     PM_pIntResetMask 0x80
#define     PM_pIntResetShift 7
#define PM_pNumReset                           52      // 15 Bits, Bit 14-0
#define     PM_pNumResetMask 0x7FFF
#define     PM_pNumResetShift 0
#define PM_pIntDayPhase                        54      // 1 Bit, Bit 7
#define     PM_pIntDayPhaseMask 0x80
#define     PM_pIntDayPhaseShift 7
#define PM_pNumDayPhase                        54      // 15 Bits, Bit 14-0
#define     PM_pNumDayPhaseMask 0x7FFF
#define     PM_pNumDayPhaseShift 0
#define PM_pIntScene                           56      // 1 Bit, Bit 7
#define     PM_pIntSceneMask 0x80
#define     PM_pIntSceneShift 7
#define PM_pNumScene                           56      // 15 Bits, Bit 14-0
#define     PM_pNumSceneMask 0x7FFF
#define     PM_pNumSceneShift 0
#define PM_pABrightnessAuto                    58      // 2 Bits, Bit 7-6
#define     PM_pABrightnessAutoMask 0xC0
#define     PM_pABrightnessAutoShift 6
#define PM_pAPresenceShort                     58      // 1 Bit, Bit 5
#define     PM_pAPresenceShortMask 0x20
#define     PM_pAPresenceShortShift 5
#define PM_pALockHardwareLEDs                  58      // 1 Bit, Bit 4
#define     PM_pALockHardwareLEDsMask 0x10
#define     PM_pALockHardwareLEDsShift 4
#define PM_pAOutput1Filter                     58      // 2 Bits, Bit 3-2
#define     PM_pAOutput1FilterMask 0x0C
#define     PM_pAOutput1FilterShift 2
#define PM_pAOutput2Filter                     58      // 2 Bits, Bit 1-0
#define     PM_pAOutput2FilterMask 0x03
#define     PM_pAOutput2FilterShift 0
#define PM_pAManualWithPresence                59      // 1 Bit, Bit 7
#define     PM_pAManualWithPresenceMask 0x80
#define     PM_pAManualWithPresenceShift 7
#define PM_pAPresenceShortNoSwitch             59      // 1 Bit, Bit 6
#define     PM_pAPresenceShortNoSwitchMask 0x40
#define     PM_pAPresenceShortNoSwitchShift 6
#define PM_pAPresenceShortCalculation          59      // 1 Bit, Bit 5
#define     PM_pAPresenceShortCalculationMask 0x20
#define     PM_pAPresenceShortCalculationShift 5
#define PM_pADayPhaseFunction                  59      // 2 Bits, Bit 4-3
#define     PM_pADayPhaseFunctionMask 0x18
#define     PM_pADayPhaseFunctionShift 3
#define PM_pAPresenceDelayBase                 60      // 2 Bits, Bit 7-6
#define     PM_pAPresenceDelayBaseMask 0xC0
#define     PM_pAPresenceDelayBaseShift 6
#define PM_pAPresenceDelayTime                 60      // 14 Bits, Bit 13-0
#define     PM_pAPresenceDelayTimeMask 0x3FFF
#define     PM_pAPresenceDelayTimeShift 0
#define PM_pAPresenceShortDurationBase         62      // 2 Bits, Bit 7-6
#define     PM_pAPresenceShortDurationBaseMask 0xC0
#define     PM_pAPresenceShortDurationBaseShift 6
#define PM_pAPresenceShortDurationTime         62      // 14 Bits, Bit 13-0
#define     PM_pAPresenceShortDurationTimeMask 0x3FFF
#define     PM_pAPresenceShortDurationTimeShift 0
#define PM_pAPresenceShortDelayBase            64      // 2 Bits, Bit 7-6
#define     PM_pAPresenceShortDelayBaseMask 0xC0
#define     PM_pAPresenceShortDelayBaseShift 6
#define PM_pAPresenceShortDelayTime            64      // 14 Bits, Bit 13-0
#define     PM_pAPresenceShortDelayTimeMask 0x3FFF
#define     PM_pAPresenceShortDelayTimeShift 0
#define PM_pABrightnessOffDelayBase            66      // 2 Bits, Bit 7-6
#define     PM_pABrightnessOffDelayBaseMask 0xC0
#define     PM_pABrightnessOffDelayBaseShift 6
#define PM_pABrightnessOffDelayTime            66      // 14 Bits, Bit 13-0
#define     PM_pABrightnessOffDelayTimeMask 0x3FFF
#define     PM_pABrightnessOffDelayTimeShift 0
#define PM_pAManualFallbackDelayBase           68      // 2 Bits, Bit 7-6
#define     PM_pAManualFallbackDelayBaseMask 0xC0
#define     PM_pAManualFallbackDelayBaseShift 6
#define PM_pAManualFallbackDelayTime           68      // 14 Bits, Bit 13-0
#define     PM_pAManualFallbackDelayTimeMask 0x3FFF
#define     PM_pAManualFallbackDelayTimeShift 0
#define PM_pABrightnessOn                      70      // uint16_t
#define PM_pABrightnessDelta                   72      // uint16_t
#define PM_pAOutput1On                         74      // 8 Bits, Bit 7-0
#define PM_pAOutput1OnValue                    74      // uint8_t
#define PM_pAOutput1OnScene                    74      // 8 Bits, Bit 7-0
#define PM_pAOutput1OnDim                      74      // uint8_t
#define PM_pAOutput1Off                        75      // 8 Bits, Bit 7-0
#define PM_pAOutput1OffValue                   75      // uint8_t
#define PM_pAOutput1OffScene                   75      // 8 Bits, Bit 7-0
#define PM_pAOutput1OffDim                     75      // uint8_t
#define PM_pAOutput2On                         76      // 8 Bits, Bit 7-0
#define PM_pAOutput2OnValue                    76      // uint8_t
#define PM_pAOutput2OnScene                    76      // 8 Bits, Bit 7-0
#define PM_pAOutput2OnDim                      76      // uint8_t
#define PM_pAOutput2Off                        77      // 8 Bits, Bit 7-0
#define PM_pAOutput2OffValue                   77      // uint8_t
#define PM_pAOutput2OffScene                   77      // 8 Bits, Bit 7-0
#define PM_pAOutput2OffDim                     77      // uint8_t
#define PM_pBBrightnessAuto                    78      // 2 Bits, Bit 7-6
#define     PM_pBBrightnessAutoMask 0xC0
#define     PM_pBBrightnessAutoShift 6
#define PM_pBPresenceShort                     78      // 1 Bit, Bit 5
#define     PM_pBPresenceShortMask 0x20
#define     PM_pBPresenceShortShift 5
#define PM_pBLockHardwareLEDs                  78      // 1 Bit, Bit 4
#define     PM_pBLockHardwareLEDsMask 0x10
#define     PM_pBLockHardwareLEDsShift 4
#define PM_pBOutput1Filter                     78      // 2 Bits, Bit 3-2
#define     PM_pBOutput1FilterMask 0x0C
#define     PM_pBOutput1FilterShift 2
#define PM_pBOutput2Filter                     78      // 2 Bits, Bit 1-0
#define     PM_pBOutput2FilterMask 0x03
#define     PM_pBOutput2FilterShift 0
#define PM_pBManualWithPresence                79      // 1 Bit, Bit 7
#define     PM_pBManualWithPresenceMask 0x80
#define     PM_pBManualWithPresenceShift 7
#define PM_pBPresenceShortNoSwitch             79      // 1 Bit, Bit 6
#define     PM_pBPresenceShortNoSwitchMask 0x40
#define     PM_pBPresenceShortNoSwitchShift 6
#define PM_pBPresenceShortCalculation          79      // 1 Bit, Bit 5
#define     PM_pBPresenceShortCalculationMask 0x20
#define     PM_pBPresenceShortCalculationShift 5
#define PM_pBDayPhaseFunction                  79      // 2 Bits, Bit 4-3
#define     PM_pBDayPhaseFunctionMask 0x18
#define     PM_pBDayPhaseFunctionShift 3
#define PM_pBPresenceDelayBase                 80      // 2 Bits, Bit 7-6
#define     PM_pBPresenceDelayBaseMask 0xC0
#define     PM_pBPresenceDelayBaseShift 6
#define PM_pBPresenceDelayTime                 80      // 14 Bits, Bit 13-0
#define     PM_pBPresenceDelayTimeMask 0x3FFF
#define     PM_pBPresenceDelayTimeShift 0
#define PM_pBPresenceShortDurationBase         82      // 2 Bits, Bit 7-6
#define     PM_pBPresenceShortDurationBaseMask 0xC0
#define     PM_pBPresenceShortDurationBaseShift 6
#define PM_pBPresenceShortDurationTime         82      // 14 Bits, Bit 13-0
#define     PM_pBPresenceShortDurationTimeMask 0x3FFF
#define     PM_pBPresenceShortDurationTimeShift 0
#define PM_pBPresenceShortDelayBase            84      // 2 Bits, Bit 7-6
#define     PM_pBPresenceShortDelayBaseMask 0xC0
#define     PM_pBPresenceShortDelayBaseShift 6
#define PM_pBPresenceShortDelayTime            84      // 14 Bits, Bit 13-0
#define     PM_pBPresenceShortDelayTimeMask 0x3FFF
#define     PM_pBPresenceShortDelayTimeShift 0
#define PM_pBBrightnessOffDelayBase            86      // 2 Bits, Bit 7-6
#define     PM_pBBrightnessOffDelayBaseMask 0xC0
#define     PM_pBBrightnessOffDelayBaseShift 6
#define PM_pBBrightnessOffDelayTime            86      // 14 Bits, Bit 13-0
#define     PM_pBBrightnessOffDelayTimeMask 0x3FFF
#define     PM_pBBrightnessOffDelayTimeShift 0
#define PM_pBManualFallbackDelayBase           88      // 2 Bits, Bit 7-6
#define     PM_pBManualFallbackDelayBaseMask 0xC0
#define     PM_pBManualFallbackDelayBaseShift 6
#define PM_pBManualFallbackDelayTime           88      // 14 Bits, Bit 13-0
#define     PM_pBManualFallbackDelayTimeMask 0x3FFF
#define     PM_pBManualFallbackDelayTimeShift 0
#define PM_pBBrightnessOn                      90      // uint16_t
#define PM_pBBrightnessDelta                   92      // uint16_t
#define PM_pBOutput1On                         94      // 8 Bits, Bit 7-0
#define PM_pBOutput1OnValue                    94      // uint8_t
#define PM_pBOutput1OnScene                    94      // 8 Bits, Bit 7-0
#define PM_pBOutput1OnDim                      94      // uint8_t
#define PM_pBOutput1Off                        95      // 8 Bits, Bit 7-0
#define PM_pBOutput1OffValue                   95      // uint8_t
#define PM_pBOutput1OffScene                   95      // 8 Bits, Bit 7-0
#define PM_pBOutput1OffDim                     95      // uint8_t
#define PM_pBOutput2On                         96      // 8 Bits, Bit 7-0
#define PM_pBOutput2OnValue                    96      // uint8_t
#define PM_pBOutput2OnScene                    96      // 8 Bits, Bit 7-0
#define PM_pBOutput2OnDim                      96      // uint8_t
#define PM_pBOutput2Off                        97      // 8 Bits, Bit 7-0
#define PM_pBOutput2OffValue                   97      // uint8_t
#define PM_pBOutput2OffScene                   97      // 8 Bits, Bit 7-0
#define PM_pBOutput2OffDim                     97      // uint8_t
#define PM_pCBrightnessAuto                    98      // 2 Bits, Bit 7-6
#define     PM_pCBrightnessAutoMask 0xC0
#define     PM_pCBrightnessAutoShift 6
#define PM_pCPresenceShort                     98      // 1 Bit, Bit 5
#define     PM_pCPresenceShortMask 0x20
#define     PM_pCPresenceShortShift 5
#define PM_pCLockHardwareLEDs                  98      // 1 Bit, Bit 4
#define     PM_pCLockHardwareLEDsMask 0x10
#define     PM_pCLockHardwareLEDsShift 4
#define PM_pCOutput1Filter                     98      // 2 Bits, Bit 3-2
#define     PM_pCOutput1FilterMask 0x0C
#define     PM_pCOutput1FilterShift 2
#define PM_pCOutput2Filter                     98      // 2 Bits, Bit 1-0
#define     PM_pCOutput2FilterMask 0x03
#define     PM_pCOutput2FilterShift 0
#define PM_pCManualWithPresence                99      // 1 Bit, Bit 7
#define     PM_pCManualWithPresenceMask 0x80
#define     PM_pCManualWithPresenceShift 7
#define PM_pCPresenceShortNoSwitch             99      // 1 Bit, Bit 6
#define     PM_pCPresenceShortNoSwitchMask 0x40
#define     PM_pCPresenceShortNoSwitchShift 6
#define PM_pCPresenceShortCalculation          99      // 1 Bit, Bit 5
#define     PM_pCPresenceShortCalculationMask 0x20
#define     PM_pCPresenceShortCalculationShift 5
#define PM_pCDayPhaseFunction                  99      // 2 Bits, Bit 4-3
#define     PM_pCDayPhaseFunctionMask 0x18
#define     PM_pCDayPhaseFunctionShift 3
#define PM_pCPresenceDelayBase                 100      // 2 Bits, Bit 7-6
#define     PM_pCPresenceDelayBaseMask 0xC0
#define     PM_pCPresenceDelayBaseShift 6
#define PM_pCPresenceDelayTime                 100      // 14 Bits, Bit 13-0
#define     PM_pCPresenceDelayTimeMask 0x3FFF
#define     PM_pCPresenceDelayTimeShift 0
#define PM_pCPresenceShortDurationBase         102      // 2 Bits, Bit 7-6
#define     PM_pCPresenceShortDurationBaseMask 0xC0
#define     PM_pCPresenceShortDurationBaseShift 6
#define PM_pCPresenceShortDurationTime         102      // 14 Bits, Bit 13-0
#define     PM_pCPresenceShortDurationTimeMask 0x3FFF
#define     PM_pCPresenceShortDurationTimeShift 0
#define PM_pCPresenceShortDelayBase            104      // 2 Bits, Bit 7-6
#define     PM_pCPresenceShortDelayBaseMask 0xC0
#define     PM_pCPresenceShortDelayBaseShift 6
#define PM_pCPresenceShortDelayTime            104      // 14 Bits, Bit 13-0
#define     PM_pCPresenceShortDelayTimeMask 0x3FFF
#define     PM_pCPresenceShortDelayTimeShift 0
#define PM_pCBrightnessOffDelayBase            106      // 2 Bits, Bit 7-6
#define     PM_pCBrightnessOffDelayBaseMask 0xC0
#define     PM_pCBrightnessOffDelayBaseShift 6
#define PM_pCBrightnessOffDelayTime            106      // 14 Bits, Bit 13-0
#define     PM_pCBrightnessOffDelayTimeMask 0x3FFF
#define     PM_pCBrightnessOffDelayTimeShift 0
#define PM_pCManualFallbackDelayBase           108      // 2 Bits, Bit 7-6
#define     PM_pCManualFallbackDelayBaseMask 0xC0
#define     PM_pCManualFallbackDelayBaseShift 6
#define PM_pCManualFallbackDelayTime           108      // 14 Bits, Bit 13-0
#define     PM_pCManualFallbackDelayTimeMask 0x3FFF
#define     PM_pCManualFallbackDelayTimeShift 0
#define PM_pCBrightnessOn                      110      // uint16_t
#define PM_pCBrightnessDelta                   112      // uint16_t
#define PM_pCOutput1On                         114      // 8 Bits, Bit 7-0
#define PM_pCOutput1OnValue                    114      // uint8_t
#define PM_pCOutput1OnScene                    114      // 8 Bits, Bit 7-0
#define PM_pCOutput1OnDim                      114      // uint8_t
#define PM_pCOutput1Off                        115      // 8 Bits, Bit 7-0
#define PM_pCOutput1OffValue                   115      // uint8_t
#define PM_pCOutput1OffScene                   115      // 8 Bits, Bit 7-0
#define PM_pCOutput1OffDim                     115      // uint8_t
#define PM_pCOutput2On                         116      // 8 Bits, Bit 7-0
#define PM_pCOutput2OnValue                    116      // uint8_t
#define PM_pCOutput2OnScene                    116      // 8 Bits, Bit 7-0
#define PM_pCOutput2OnDim                      116      // uint8_t
#define PM_pCOutput2Off                        117      // 8 Bits, Bit 7-0
#define PM_pCOutput2OffValue                   117      // uint8_t
#define PM_pCOutput2OffScene                   117      // 8 Bits, Bit 7-0
#define PM_pCOutput2OffDim                     117      // uint8_t
#define PM_pDBrightnessAuto                    118      // 2 Bits, Bit 7-6
#define     PM_pDBrightnessAutoMask 0xC0
#define     PM_pDBrightnessAutoShift 6
#define PM_pDPresenceShort                     118      // 1 Bit, Bit 5
#define     PM_pDPresenceShortMask 0x20
#define     PM_pDPresenceShortShift 5
#define PM_pDLockHardwareLEDs                  118      // 1 Bit, Bit 4
#define     PM_pDLockHardwareLEDsMask 0x10
#define     PM_pDLockHardwareLEDsShift 4
#define PM_pDOutput1Filter                     118      // 2 Bits, Bit 3-2
#define     PM_pDOutput1FilterMask 0x0C
#define     PM_pDOutput1FilterShift 2
#define PM_pDOutput2Filter                     118      // 2 Bits, Bit 1-0
#define     PM_pDOutput2FilterMask 0x03
#define     PM_pDOutput2FilterShift 0
#define PM_pDManualWithPresence                119      // 1 Bit, Bit 7
#define     PM_pDManualWithPresenceMask 0x80
#define     PM_pDManualWithPresenceShift 7
#define PM_pDPresenceShortNoSwitch             119      // 1 Bit, Bit 6
#define     PM_pDPresenceShortNoSwitchMask 0x40
#define     PM_pDPresenceShortNoSwitchShift 6
#define PM_pDPresenceShortCalculation          119      // 1 Bit, Bit 5
#define     PM_pDPresenceShortCalculationMask 0x20
#define     PM_pDPresenceShortCalculationShift 5
#define PM_pDDayPhaseFunction                  119      // 2 Bits, Bit 4-3
#define     PM_pDDayPhaseFunctionMask 0x18
#define     PM_pDDayPhaseFunctionShift 3
#define PM_pDPresenceDelayBase                 120      // 2 Bits, Bit 7-6
#define     PM_pDPresenceDelayBaseMask 0xC0
#define     PM_pDPresenceDelayBaseShift 6
#define PM_pDPresenceDelayTime                 120      // 14 Bits, Bit 13-0
#define     PM_pDPresenceDelayTimeMask 0x3FFF
#define     PM_pDPresenceDelayTimeShift 0
#define PM_pDPresenceShortDurationBase         122      // 2 Bits, Bit 7-6
#define     PM_pDPresenceShortDurationBaseMask 0xC0
#define     PM_pDPresenceShortDurationBaseShift 6
#define PM_pDPresenceShortDurationTime         122      // 14 Bits, Bit 13-0
#define     PM_pDPresenceShortDurationTimeMask 0x3FFF
#define     PM_pDPresenceShortDurationTimeShift 0
#define PM_pDPresenceShortDelayBase            124      // 2 Bits, Bit 7-6
#define     PM_pDPresenceShortDelayBaseMask 0xC0
#define     PM_pDPresenceShortDelayBaseShift 6
#define PM_pDPresenceShortDelayTime            124      // 14 Bits, Bit 13-0
#define     PM_pDPresenceShortDelayTimeMask 0x3FFF
#define     PM_pDPresenceShortDelayTimeShift 0
#define PM_pDBrightnessOffDelayBase            126      // 2 Bits, Bit 7-6
#define     PM_pDBrightnessOffDelayBaseMask 0xC0
#define     PM_pDBrightnessOffDelayBaseShift 6
#define PM_pDBrightnessOffDelayTime            126      // 14 Bits, Bit 13-0
#define     PM_pDBrightnessOffDelayTimeMask 0x3FFF
#define     PM_pDBrightnessOffDelayTimeShift 0
#define PM_pDManualFallbackDelayBase           128      // 2 Bits, Bit 7-6
#define     PM_pDManualFallbackDelayBaseMask 0xC0
#define     PM_pDManualFallbackDelayBaseShift 6
#define PM_pDManualFallbackDelayTime           128      // 14 Bits, Bit 13-0
#define     PM_pDManualFallbackDelayTimeMask 0x3FFF
#define     PM_pDManualFallbackDelayTimeShift 0
#define PM_pDBrightnessOn                      130      // uint16_t
#define PM_pDBrightnessDelta                   132      // uint16_t
#define PM_pDOutput1On                         134      // 8 Bits, Bit 7-0
#define PM_pDOutput1OnValue                    134      // uint8_t
#define PM_pDOutput1OnScene                    134      // 8 Bits, Bit 7-0
#define PM_pDOutput1OnDim                      134      // uint8_t
#define PM_pDOutput1Off                        135      // 8 Bits, Bit 7-0
#define PM_pDOutput1OffValue                   135      // uint8_t
#define PM_pDOutput1OffScene                   135      // 8 Bits, Bit 7-0
#define PM_pDOutput1OffDim                     135      // uint8_t
#define PM_pDOutput2On                         136      // 8 Bits, Bit 7-0
#define PM_pDOutput2OnValue                    136      // uint8_t
#define PM_pDOutput2OnScene                    136      // 8 Bits, Bit 7-0
#define PM_pDOutput2OnDim                      136      // uint8_t
#define PM_pDOutput2Off                        137      // 8 Bits, Bit 7-0
#define PM_pDOutput2OffValue                   137      // uint8_t
#define PM_pDOutput2OffScene                   137      // 8 Bits, Bit 7-0
#define PM_pDOutput2OffDim                     137      // uint8_t

// Eingänge für externen Melder
#define ParamPM_pPresenceInputs                     ((knx.paramByte(PM_ParamCalcIndex(PM_pPresenceInputs)) & PM_pPresenceInputsMask) >> PM_pPresenceInputsShift)
// Eingang Präsenz
#define ParamPM_pPresenceType                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pPresenceType)) & PM_pPresenceTypeMask))
// Eingang Bewegung
#define ParamPM_pMoveType                           ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pMoveType)) & PM_pMoveTypeMask))
// Tagesphasen über Tag-/Nacht-Objekt verfügbar machen?
#define ParamPM_pPhaseBool                          ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pPhaseBool)) & PM_pPhaseBoolMask))
// Anzahl Tagesphasen
#define ParamPM_pPhaseCount                         (knx.paramByte(PM_ParamCalcIndex(PM_pPhaseCount)) & PM_pPhaseCountMask)
// Ausgang 1 ist vom Typ
#define ParamPM_pOutput1Type                        ((knx.paramByte(PM_ParamCalcIndex(PM_pOutput1Type)) & PM_pOutput1TypeMask) >> PM_pOutput1TypeShift)
// Ausgang 2 ist vom Typ
#define ParamPM_pOutput2Type                        ((knx.paramByte(PM_ParamCalcIndex(PM_pOutput2Type)) & PM_pOutput2TypeMask) >> PM_pOutput2TypeShift)
// Kanalaktivität
#define ParamPM_pChannelActive                      (knx.paramByte(PM_ParamCalcIndex(PM_pChannelActive)) & PM_pChannelActiveMask)
// Kanal ist Helligkeitsabhängig
#define ParamPM_pBrightnessIndependent              ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBrightnessIndependent)) & PM_pBrightnessIndependentMask))
// Eingebauten Helligkeitssensor verwenden?
#define ParamPM_pBrightnessIntern                   ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBrightnessIntern)) & PM_pBrightnessInternMask))
// Sperrobjekt
#define ParamPM_pLockType                           ((knx.paramByte(PM_ParamCalcIndex(PM_pLockType)) & PM_pLockTypeMask) >> PM_pLockTypeShift)
// Sperraktivität
#define ParamPM_pLockActive                         ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pLockActive)) & PM_pLockActiveMask))
// Beim EINschalten wird
#define ParamPM_pLockOn                             (knx.paramByte(PM_ParamCalcIndex(PM_pLockOn)) & PM_pLockOnMask)
// Beim AUSschalten wird
#define ParamPM_pLockOff                            ((knx.paramByte(PM_ParamCalcIndex(PM_pLockOff)) & PM_pLockOffMask) >> PM_pLockOffShift)
// Mit Rückfallzeit?
#define ParamPM_pLockFallback                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pLockFallback)) & PM_pLockFallbackMask))
// Neue Tagesphase übernehmen
#define ParamPM_pPhaseChange                        ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pPhaseChange)) & PM_pPhaseChangeMask))
// Eingebauten Präsenzsensor verwenden?
#define ParamPM_pPresenceUsage                      ((knx.paramByte(PM_ParamCalcIndex(PM_pPresenceUsage)) & PM_pPresenceUsageMask) >> PM_pPresenceUsageShift)
// Eingebauten Präsenzsensor verwenden?
#define ParamPM_pPresenceUsagePIR                   ((knx.paramByte(PM_ParamCalcIndex(PM_pPresenceUsagePIR)) & PM_pPresenceUsagePIRMask) >> PM_pPresenceUsagePIRShift)
// 'Automatik übersteuern'=AUS heißt 'Raum verlassen'
#define ParamPM_pAutoOffIsLeave                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pAutoOffIsLeave)) & PM_pAutoOffIsLeaveMask))
// Tastenmodus für 'Manuell übersteuern'
#define ParamPM_pManualModeKeyCount                 ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pManualModeKeyCount)) & PM_pManualModeKeyCountMask))
// Nach Totzeit Lesetelegramm senden?
#define ParamPM_pBrightnessRead                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBrightnessRead)) & PM_pBrightnessReadMask))
// Helligkeit nach Neustart vom Bus lesen?
#define ParamPM_pStartReadLux                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadLux)) & PM_pStartReadLuxMask))
// Präsenz A nach Neustart vom Bus lesen?
#define ParamPM_pStartReadPresence1                 ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadPresence1)) & PM_pStartReadPresence1Mask))
// Präsenz B nach Neustart vom Bus lesen?
#define ParamPM_pStartReadPresence2                 ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadPresence2)) & PM_pStartReadPresence2Mask))
// Aktorstatus nach Neustart vom Bus lesen?
#define ParamPM_pStartReadAktorState                ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadAktorState)) & PM_pStartReadAktorStateMask))
// Sperre nach Neustart vom Bus lesen?
#define ParamPM_pStartReadLock                      ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadLock)) & PM_pStartReadLockMask))
// Tagesphase nach Neustart vom Bus lesen?
#define ParamPM_pStartReadDayPhase                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadDayPhase)) & PM_pStartReadDayPhaseMask))
// Steuerszene nach Neustart vom Bus lesen?
#define ParamPM_pStartReadScene                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pStartReadScene)) & PM_pStartReadSceneMask))
// Modus für Raum verlassen
#define ParamPM_pLeaveRoomModeAll                   ((knx.paramByte(PM_ParamCalcIndex(PM_pLeaveRoomModeAll)) & PM_pLeaveRoomModeAllMask) >> PM_pLeaveRoomModeAllShift)
// Modus für Raum verlassen
#define ParamPM_pLeaveRoomModeMove                  ((knx.paramByte(PM_ParamCalcIndex(PM_pLeaveRoomModeMove)) & PM_pLeaveRoomModeMoveMask) >> PM_pLeaveRoomModeMoveShift)
// Modus für Raum verlassen
#define ParamPM_pLeaveRoomModeReset                 ((knx.paramByte(PM_ParamCalcIndex(PM_pLeaveRoomModeReset)) & PM_pLeaveRoomModeResetMask) >> PM_pLeaveRoomModeResetShift)
// Externer PM kann über Bus zurückgesetzt werden?
#define ParamPM_pExternalSupportsReset              ((knx.paramByte(PM_ParamCalcIndex(PM_pExternalSupportsReset)) & PM_pExternalSupportsResetMask) >> PM_pExternalSupportsResetShift)
//     Eingang kann nicht einschalten,    aber bestehende Präsenz verlängern
#define ParamPM_pPresenceKeepAlive                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pPresenceKeepAlive)) & PM_pPresenceKeepAliveMask))
//     Eingang kann nicht einschalten,    aber bestehende Präsenz verlängern
#define ParamPM_pMoveKeepAlive                      ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pMoveKeepAlive)) & PM_pMoveKeepAliveMask))
// Startverzögerung für diesen Kanal
#define ParamPM_pChannelDelayBase                   ((knx.paramByte(PM_ParamCalcIndex(PM_pChannelDelayBase)) & PM_pChannelDelayBaseMask) >> PM_pChannelDelayBaseShift)
// Startverzögerung für diesen Kanal
#define ParamPM_pChannelDelayTime                   (knx.paramWord(PM_ParamCalcIndex(PM_pChannelDelayTime)) & PM_pChannelDelayTimeMask)
// Startverzögerung für diesen Kanal (in Millisekunden)
#define ParamPM_pChannelDelayTimeMS                 (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pChannelDelayTime))))
// Rückfall nach
#define ParamPM_pLockFallbackBase                   ((knx.paramByte(PM_ParamCalcIndex(PM_pLockFallbackBase)) & PM_pLockFallbackBaseMask) >> PM_pLockFallbackBaseShift)
// Rückfall nach
#define ParamPM_pLockFallbackTime                   (knx.paramWord(PM_ParamCalcIndex(PM_pLockFallbackTime)) & PM_pLockFallbackTimeMask)
// Rückfall nach (in Millisekunden)
#define ParamPM_pLockFallbackTimeMS                 (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pLockFallbackTime))))
// Totzeit nach Raum verlassen
#define ParamPM_pDowntimeOffBase                    ((knx.paramByte(PM_ParamCalcIndex(PM_pDowntimeOffBase)) & PM_pDowntimeOffBaseMask) >> PM_pDowntimeOffBaseShift)
// Totzeit nach Raum verlassen
#define ParamPM_pDowntimeOffTime                    (knx.paramWord(PM_ParamCalcIndex(PM_pDowntimeOffTime)) & PM_pDowntimeOffTimeMask)
// Totzeit nach Raum verlassen (in Millisekunden)
#define ParamPM_pDowntimeOffTimeMS                  (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDowntimeOffTime))))
// Totzeit bis zur Helligkeitsanpassung
#define ParamPM_pAdaptiveDelayBase                  ((knx.paramByte(PM_ParamCalcIndex(PM_pAdaptiveDelayBase)) & PM_pAdaptiveDelayBaseMask) >> PM_pAdaptiveDelayBaseShift)
// Totzeit bis zur Helligkeitsanpassung
#define ParamPM_pAdaptiveDelayTime                  (knx.paramWord(PM_ParamCalcIndex(PM_pAdaptiveDelayTime)) & PM_pAdaptiveDelayTimeMask)
// Totzeit bis zur Helligkeitsanpassung (in Millisekunden)
#define ParamPM_pAdaptiveDelayTimeMS                (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pAdaptiveDelayTime))))
// Szene Phase 1
#define ParamPM_pPhase1Scene                        (knx.paramByte(PM_ParamCalcIndex(PM_pPhase1Scene)))
// Szene Phase 2
#define ParamPM_pPhase2Scene                        (knx.paramByte(PM_ParamCalcIndex(PM_pPhase2Scene)))
// Szene Phase 3
#define ParamPM_pPhase3Scene                        (knx.paramByte(PM_ParamCalcIndex(PM_pPhase3Scene)))
// Szene Phase 4
#define ParamPM_pPhase4Scene                        (knx.paramByte(PM_ParamCalcIndex(PM_pPhase4Scene)))
// Szene0
#define ParamPM_pScene0                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene0)))
// Szene1
#define ParamPM_pScene1                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene1)))
// Szene2
#define ParamPM_pScene2                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene2)))
// Szene3
#define ParamPM_pScene3                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene3)))
// Szene4
#define ParamPM_pScene4                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene4)))
// Szene5
#define ParamPM_pScene5                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene5)))
// Szene6
#define ParamPM_pScene6                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene6)))
// Szene7
#define ParamPM_pScene7                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene7)))
// Szene8
#define ParamPM_pScene8                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene8)))
// Szene9
#define ParamPM_pScene9                             (knx.paramByte(PM_ParamCalcIndex(PM_pScene9)))
// SzeneAction0
#define ParamPM_pSceneAction0                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction0)))
// SzeneAction1
#define ParamPM_pSceneAction1                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction1)))
// SzeneAction2
#define ParamPM_pSceneAction2                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction2)))
// SzeneAction3
#define ParamPM_pSceneAction3                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction3)))
// SzeneAction4
#define ParamPM_pSceneAction4                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction4)))
// SzeneAction5
#define ParamPM_pSceneAction5                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction5)))
// SzeneAction6
#define ParamPM_pSceneAction6                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction6)))
// SzeneAction7
#define ParamPM_pSceneAction7                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction7)))
// SzeneAction8
#define ParamPM_pSceneAction8                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction8)))
// SzeneAction9
#define ParamPM_pSceneAction9                       (knx.paramByte(PM_ParamCalcIndex(PM_pSceneAction9)))
// Neues oder internes KO
#define ParamPM_pIntLux                             ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntLux)) & PM_pIntLuxMask))
// Nummer vom internen KO
#define ParamPM_pNumLux                             (knx.paramWord(PM_ParamCalcIndex(PM_pNumLux)) & PM_pNumLuxMask)
// Neues oder internes KO
#define ParamPM_pIntPresence1                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntPresence1)) & PM_pIntPresence1Mask))
// Nummer vom internen KO
#define ParamPM_pNumPresence1                       (knx.paramWord(PM_ParamCalcIndex(PM_pNumPresence1)) & PM_pNumPresence1Mask)
// Neues oder internes KO
#define ParamPM_pIntPresence2                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntPresence2)) & PM_pIntPresence2Mask))
// Nummer vom internen KO
#define ParamPM_pNumPresence2                       (knx.paramWord(PM_ParamCalcIndex(PM_pNumPresence2)) & PM_pNumPresence2Mask)
// Neues oder internes KO
#define ParamPM_pIntSetAuto                         ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntSetAuto)) & PM_pIntSetAutoMask))
// Nummer vom internen KO
#define ParamPM_pNumSetAuto                         (knx.paramWord(PM_ParamCalcIndex(PM_pNumSetAuto)) & PM_pNumSetAutoMask)
// Neues oder internes KO
#define ParamPM_pIntSetManual                       ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntSetManual)) & PM_pIntSetManualMask))
// Nummer vom internen KO
#define ParamPM_pNumSetManual                       (knx.paramWord(PM_ParamCalcIndex(PM_pNumSetManual)) & PM_pNumSetManualMask)
// Neues oder internes KO
#define ParamPM_pIntActorState                      ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntActorState)) & PM_pIntActorStateMask))
// Nummer vom internen KO
#define ParamPM_pNumActorState                      (knx.paramWord(PM_ParamCalcIndex(PM_pNumActorState)) & PM_pNumActorStateMask)
// Neues oder internes KO
#define ParamPM_pIntLock                            ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntLock)) & PM_pIntLockMask))
// Nummer vom internen KO
#define ParamPM_pNumLock                            (knx.paramWord(PM_ParamCalcIndex(PM_pNumLock)) & PM_pNumLockMask)
// Neues oder internes KO
#define ParamPM_pIntReset                           ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntReset)) & PM_pIntResetMask))
// Nummer vom internen KO
#define ParamPM_pNumReset                           (knx.paramWord(PM_ParamCalcIndex(PM_pNumReset)) & PM_pNumResetMask)
// Neues oder internes KO
#define ParamPM_pIntDayPhase                        ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntDayPhase)) & PM_pIntDayPhaseMask))
// Nummer vom internen KO
#define ParamPM_pNumDayPhase                        (knx.paramWord(PM_ParamCalcIndex(PM_pNumDayPhase)) & PM_pNumDayPhaseMask)
// Neues oder internes KO
#define ParamPM_pIntScene                           ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pIntScene)) & PM_pIntSceneMask))
// Nummer vom internen KO
#define ParamPM_pNumScene                           (knx.paramWord(PM_ParamCalcIndex(PM_pNumScene)) & PM_pNumSceneMask)
// Ausschalten über Helligkeit
#define ParamPM_pABrightnessAuto                    ((knx.paramByte(PM_ParamCalcIndex(PM_pABrightnessAuto)) & PM_pABrightnessAutoMask) >> PM_pABrightnessAutoShift)
// Kurze Anwesenheit erkennen?
#define ParamPM_pAPresenceShort                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceShort)) & PM_pAPresenceShortMask))
// Diese Tagesphase sperrt Hardware-LEDs
#define ParamPM_pALockHardwareLEDs                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pALockHardwareLEDs)) & PM_pALockHardwareLEDsMask))
// Ausgang 1 sendet
#define ParamPM_pAOutput1Filter                     ((knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1Filter)) & PM_pAOutput1FilterMask) >> PM_pAOutput1FilterShift)
// Ausgang 2 sendet
#define ParamPM_pAOutput2Filter                     (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2Filter)) & PM_pAOutput2FilterMask)
// Manueller Modus ist präsenzabhängig?
#define ParamPM_pAManualWithPresence                ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pAManualWithPresence)) & PM_pAManualWithPresenceMask))
// Erst nach der Kurzzeitpräsenz schalten(z.B. Durchgangsraum)
#define ParamPM_pAPresenceShortNoSwitch             ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceShortNoSwitch)) & PM_pAPresenceShortNoSwitchMask))
// Kurzzeitpräsenz wird ermittelt anhand vom
#define ParamPM_pAPresenceShortCalculation          ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceShortCalculation)) & PM_pAPresenceShortCalculationMask))
// Funktion der Tagesphase
#define ParamPM_pADayPhaseFunction                  ((knx.paramByte(PM_ParamCalcIndex(PM_pADayPhaseFunction)) & PM_pADayPhaseFunctionMask) >> PM_pADayPhaseFunctionShift)
// Nachlaufzeit
#define ParamPM_pAPresenceDelayBase                 ((knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceDelayBase)) & PM_pAPresenceDelayBaseMask) >> PM_pAPresenceDelayBaseShift)
// Nachlaufzeit
#define ParamPM_pAPresenceDelayTime                 (knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceDelayTime)) & PM_pAPresenceDelayTimeMask)
// Nachlaufzeit (in Millisekunden)
#define ParamPM_pAPresenceDelayTimeMS               (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceDelayTime))))
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pAPresenceShortDurationBase         ((knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceShortDurationBase)) & PM_pAPresenceShortDurationBaseMask) >> PM_pAPresenceShortDurationBaseShift)
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pAPresenceShortDurationTime         (knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceShortDurationTime)) & PM_pAPresenceShortDurationTimeMask)
// Dauer-der-kurzen-Anwesenheit (in Millisekunden)
#define ParamPM_pAPresenceShortDurationTimeMS       (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceShortDurationTime))))
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pAPresenceShortDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pAPresenceShortDelayBase)) & PM_pAPresenceShortDelayBaseMask) >> PM_pAPresenceShortDelayBaseShift)
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pAPresenceShortDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceShortDelayTime)) & PM_pAPresenceShortDelayTimeMask)
// Nachlaufzeit-bei-kurzer-Anwesenheit (in Millisekunden)
#define ParamPM_pAPresenceShortDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pAPresenceShortDelayTime))))
// Ausschalten-verzoegern-um
#define ParamPM_pABrightnessOffDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pABrightnessOffDelayBase)) & PM_pABrightnessOffDelayBaseMask) >> PM_pABrightnessOffDelayBaseShift)
// Ausschalten-verzoegern-um
#define ParamPM_pABrightnessOffDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pABrightnessOffDelayTime)) & PM_pABrightnessOffDelayTimeMask)
// Ausschalten-verzoegern-um (in Millisekunden)
#define ParamPM_pABrightnessOffDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pABrightnessOffDelayTime))))
// Manuellen-Modus-beenden-nach
#define ParamPM_pAManualFallbackDelayBase           ((knx.paramByte(PM_ParamCalcIndex(PM_pAManualFallbackDelayBase)) & PM_pAManualFallbackDelayBaseMask) >> PM_pAManualFallbackDelayBaseShift)
// Manuellen-Modus-beenden-nach
#define ParamPM_pAManualFallbackDelayTime           (knx.paramWord(PM_ParamCalcIndex(PM_pAManualFallbackDelayTime)) & PM_pAManualFallbackDelayTimeMask)
// Manuellen-Modus-beenden-nach (in Millisekunden)
#define ParamPM_pAManualFallbackDelayTimeMS         (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pAManualFallbackDelayTime))))
// Einschalten: Unterhalb welcher Helligkeit
#define ParamPM_pABrightnessOn                      (knx.paramWord(PM_ParamCalcIndex(PM_pABrightnessOn)))
// Ausschalten: Wie viel heller darf es werden
#define ParamPM_pABrightnessDelta                   (knx.paramWord(PM_ParamCalcIndex(PM_pABrightnessDelta)))
// Wert für EIN
#define ParamPM_pAOutput1On                         (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1On)))
// Wert für EIN
#define ParamPM_pAOutput1OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OnValue)))
// Wert für EIN
#define ParamPM_pAOutput1OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OnScene)))
// Wert für EIN
#define ParamPM_pAOutput1OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OnDim)))
// Wert für AUS
#define ParamPM_pAOutput1Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1Off)))
// Wert für AUS
#define ParamPM_pAOutput1OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OffValue)))
// Wert für AUS
#define ParamPM_pAOutput1OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OffScene)))
// Wert für AUS
#define ParamPM_pAOutput1OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput1OffDim)))
// Wert für EIN
#define ParamPM_pAOutput2On                         (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2On)))
// Wert für EIN
#define ParamPM_pAOutput2OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OnValue)))
// Wert für EIN
#define ParamPM_pAOutput2OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OnScene)))
// Wert für EIN
#define ParamPM_pAOutput2OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OnDim)))
// Wert für AUS
#define ParamPM_pAOutput2Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2Off)))
// Wert für AUS
#define ParamPM_pAOutput2OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OffValue)))
// Wert für AUS
#define ParamPM_pAOutput2OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OffScene)))
// Wert für AUS
#define ParamPM_pAOutput2OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pAOutput2OffDim)))
// Ausschalten über Helligkeit
#define ParamPM_pBBrightnessAuto                    ((knx.paramByte(PM_ParamCalcIndex(PM_pBBrightnessAuto)) & PM_pBBrightnessAutoMask) >> PM_pBBrightnessAutoShift)
// Kurze Anwesenheit erkennen?
#define ParamPM_pBPresenceShort                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceShort)) & PM_pBPresenceShortMask))
// Diese Tagesphase sperrt Hardware-LEDs
#define ParamPM_pBLockHardwareLEDs                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBLockHardwareLEDs)) & PM_pBLockHardwareLEDsMask))
// Ausgang 1 sendet
#define ParamPM_pBOutput1Filter                     ((knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1Filter)) & PM_pBOutput1FilterMask) >> PM_pBOutput1FilterShift)
// Ausgang 2 sendet
#define ParamPM_pBOutput2Filter                     (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2Filter)) & PM_pBOutput2FilterMask)
// Manueller Modus ist präsenzabhängig?
#define ParamPM_pBManualWithPresence                ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBManualWithPresence)) & PM_pBManualWithPresenceMask))
// Erst nach der Kurzzeitpräsenz schalten(z.B. Durchgangsraum)
#define ParamPM_pBPresenceShortNoSwitch             ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceShortNoSwitch)) & PM_pBPresenceShortNoSwitchMask))
// Kurzzeitpräsenz wird ermittelt anhand vom
#define ParamPM_pBPresenceShortCalculation          ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceShortCalculation)) & PM_pBPresenceShortCalculationMask))
// Funktion der Tagesphase
#define ParamPM_pBDayPhaseFunction                  ((knx.paramByte(PM_ParamCalcIndex(PM_pBDayPhaseFunction)) & PM_pBDayPhaseFunctionMask) >> PM_pBDayPhaseFunctionShift)
// Nachlaufzeit
#define ParamPM_pBPresenceDelayBase                 ((knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceDelayBase)) & PM_pBPresenceDelayBaseMask) >> PM_pBPresenceDelayBaseShift)
// Nachlaufzeit
#define ParamPM_pBPresenceDelayTime                 (knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceDelayTime)) & PM_pBPresenceDelayTimeMask)
// Nachlaufzeit (in Millisekunden)
#define ParamPM_pBPresenceDelayTimeMS               (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceDelayTime))))
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pBPresenceShortDurationBase         ((knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceShortDurationBase)) & PM_pBPresenceShortDurationBaseMask) >> PM_pBPresenceShortDurationBaseShift)
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pBPresenceShortDurationTime         (knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceShortDurationTime)) & PM_pBPresenceShortDurationTimeMask)
// Dauer-der-kurzen-Anwesenheit (in Millisekunden)
#define ParamPM_pBPresenceShortDurationTimeMS       (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceShortDurationTime))))
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pBPresenceShortDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pBPresenceShortDelayBase)) & PM_pBPresenceShortDelayBaseMask) >> PM_pBPresenceShortDelayBaseShift)
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pBPresenceShortDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceShortDelayTime)) & PM_pBPresenceShortDelayTimeMask)
// Nachlaufzeit-bei-kurzer-Anwesenheit (in Millisekunden)
#define ParamPM_pBPresenceShortDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pBPresenceShortDelayTime))))
// Ausschalten-verzoegern-um
#define ParamPM_pBBrightnessOffDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pBBrightnessOffDelayBase)) & PM_pBBrightnessOffDelayBaseMask) >> PM_pBBrightnessOffDelayBaseShift)
// Ausschalten-verzoegern-um
#define ParamPM_pBBrightnessOffDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pBBrightnessOffDelayTime)) & PM_pBBrightnessOffDelayTimeMask)
// Ausschalten-verzoegern-um (in Millisekunden)
#define ParamPM_pBBrightnessOffDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pBBrightnessOffDelayTime))))
// Manuellen-Modus-beenden-nach
#define ParamPM_pBManualFallbackDelayBase           ((knx.paramByte(PM_ParamCalcIndex(PM_pBManualFallbackDelayBase)) & PM_pBManualFallbackDelayBaseMask) >> PM_pBManualFallbackDelayBaseShift)
// Manuellen-Modus-beenden-nach
#define ParamPM_pBManualFallbackDelayTime           (knx.paramWord(PM_ParamCalcIndex(PM_pBManualFallbackDelayTime)) & PM_pBManualFallbackDelayTimeMask)
// Manuellen-Modus-beenden-nach (in Millisekunden)
#define ParamPM_pBManualFallbackDelayTimeMS         (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pBManualFallbackDelayTime))))
// Einschalten: Unterhalb welcher Helligkeit
#define ParamPM_pBBrightnessOn                      (knx.paramWord(PM_ParamCalcIndex(PM_pBBrightnessOn)))
// Ausschalten: Wie viel heller darf es werden
#define ParamPM_pBBrightnessDelta                   (knx.paramWord(PM_ParamCalcIndex(PM_pBBrightnessDelta)))
// Wert für EIN
#define ParamPM_pBOutput1On                         (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1On)))
// Wert für EIN
#define ParamPM_pBOutput1OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OnValue)))
// Wert für EIN
#define ParamPM_pBOutput1OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OnScene)))
// Wert für EIN
#define ParamPM_pBOutput1OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OnDim)))
// Wert für AUS
#define ParamPM_pBOutput1Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1Off)))
// Wert für AUS
#define ParamPM_pBOutput1OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OffValue)))
// Wert für AUS
#define ParamPM_pBOutput1OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OffScene)))
// Wert für AUS
#define ParamPM_pBOutput1OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput1OffDim)))
// Wert für EIN
#define ParamPM_pBOutput2On                         (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2On)))
// Wert für EIN
#define ParamPM_pBOutput2OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OnValue)))
// Wert für EIN
#define ParamPM_pBOutput2OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OnScene)))
// Wert für EIN
#define ParamPM_pBOutput2OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OnDim)))
// Wert für AUS
#define ParamPM_pBOutput2Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2Off)))
// Wert für AUS
#define ParamPM_pBOutput2OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OffValue)))
// Wert für AUS
#define ParamPM_pBOutput2OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OffScene)))
// Wert für AUS
#define ParamPM_pBOutput2OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pBOutput2OffDim)))
// Ausschalten über Helligkeit
#define ParamPM_pCBrightnessAuto                    ((knx.paramByte(PM_ParamCalcIndex(PM_pCBrightnessAuto)) & PM_pCBrightnessAutoMask) >> PM_pCBrightnessAutoShift)
// Kurze Anwesenheit erkennen?
#define ParamPM_pCPresenceShort                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceShort)) & PM_pCPresenceShortMask))
// Diese Tagesphase sperrt Hardware-LEDs
#define ParamPM_pCLockHardwareLEDs                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pCLockHardwareLEDs)) & PM_pCLockHardwareLEDsMask))
// Ausgang 1 sendet
#define ParamPM_pCOutput1Filter                     ((knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1Filter)) & PM_pCOutput1FilterMask) >> PM_pCOutput1FilterShift)
// Ausgang 2 sendet
#define ParamPM_pCOutput2Filter                     (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2Filter)) & PM_pCOutput2FilterMask)
// Manueller Modus ist präsenzabhängig?
#define ParamPM_pCManualWithPresence                ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pCManualWithPresence)) & PM_pCManualWithPresenceMask))
// Erst nach der Kurzzeitpräsenz schalten(z.B. Durchgangsraum)
#define ParamPM_pCPresenceShortNoSwitch             ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceShortNoSwitch)) & PM_pCPresenceShortNoSwitchMask))
// Kurzzeitpräsenz wird ermittelt anhand vom
#define ParamPM_pCPresenceShortCalculation          ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceShortCalculation)) & PM_pCPresenceShortCalculationMask))
// Funktion der Tagesphase
#define ParamPM_pCDayPhaseFunction                  ((knx.paramByte(PM_ParamCalcIndex(PM_pCDayPhaseFunction)) & PM_pCDayPhaseFunctionMask) >> PM_pCDayPhaseFunctionShift)
// Nachlaufzeit
#define ParamPM_pCPresenceDelayBase                 ((knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceDelayBase)) & PM_pCPresenceDelayBaseMask) >> PM_pCPresenceDelayBaseShift)
// Nachlaufzeit
#define ParamPM_pCPresenceDelayTime                 (knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceDelayTime)) & PM_pCPresenceDelayTimeMask)
// Nachlaufzeit (in Millisekunden)
#define ParamPM_pCPresenceDelayTimeMS               (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceDelayTime))))
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pCPresenceShortDurationBase         ((knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceShortDurationBase)) & PM_pCPresenceShortDurationBaseMask) >> PM_pCPresenceShortDurationBaseShift)
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pCPresenceShortDurationTime         (knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceShortDurationTime)) & PM_pCPresenceShortDurationTimeMask)
// Dauer-der-kurzen-Anwesenheit (in Millisekunden)
#define ParamPM_pCPresenceShortDurationTimeMS       (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceShortDurationTime))))
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pCPresenceShortDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pCPresenceShortDelayBase)) & PM_pCPresenceShortDelayBaseMask) >> PM_pCPresenceShortDelayBaseShift)
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pCPresenceShortDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceShortDelayTime)) & PM_pCPresenceShortDelayTimeMask)
// Nachlaufzeit-bei-kurzer-Anwesenheit (in Millisekunden)
#define ParamPM_pCPresenceShortDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pCPresenceShortDelayTime))))
// Ausschalten-verzoegern-um
#define ParamPM_pCBrightnessOffDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pCBrightnessOffDelayBase)) & PM_pCBrightnessOffDelayBaseMask) >> PM_pCBrightnessOffDelayBaseShift)
// Ausschalten-verzoegern-um
#define ParamPM_pCBrightnessOffDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pCBrightnessOffDelayTime)) & PM_pCBrightnessOffDelayTimeMask)
// Ausschalten-verzoegern-um (in Millisekunden)
#define ParamPM_pCBrightnessOffDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pCBrightnessOffDelayTime))))
// Manuellen-Modus-beenden-nach
#define ParamPM_pCManualFallbackDelayBase           ((knx.paramByte(PM_ParamCalcIndex(PM_pCManualFallbackDelayBase)) & PM_pCManualFallbackDelayBaseMask) >> PM_pCManualFallbackDelayBaseShift)
// Manuellen-Modus-beenden-nach
#define ParamPM_pCManualFallbackDelayTime           (knx.paramWord(PM_ParamCalcIndex(PM_pCManualFallbackDelayTime)) & PM_pCManualFallbackDelayTimeMask)
// Manuellen-Modus-beenden-nach (in Millisekunden)
#define ParamPM_pCManualFallbackDelayTimeMS         (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pCManualFallbackDelayTime))))
// Einschalten: Unterhalb welcher Helligkeit
#define ParamPM_pCBrightnessOn                      (knx.paramWord(PM_ParamCalcIndex(PM_pCBrightnessOn)))
// Ausschalten: Wie viel heller darf es werden
#define ParamPM_pCBrightnessDelta                   (knx.paramWord(PM_ParamCalcIndex(PM_pCBrightnessDelta)))
// Wert für EIN
#define ParamPM_pCOutput1On                         (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1On)))
// Wert für EIN
#define ParamPM_pCOutput1OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OnValue)))
// Wert für EIN
#define ParamPM_pCOutput1OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OnScene)))
// Wert für EIN
#define ParamPM_pCOutput1OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OnDim)))
// Wert für AUS
#define ParamPM_pCOutput1Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1Off)))
// Wert für AUS
#define ParamPM_pCOutput1OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OffValue)))
// Wert für AUS
#define ParamPM_pCOutput1OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OffScene)))
// Wert für AUS
#define ParamPM_pCOutput1OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput1OffDim)))
// Wert für EIN
#define ParamPM_pCOutput2On                         (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2On)))
// Wert für EIN
#define ParamPM_pCOutput2OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OnValue)))
// Wert für EIN
#define ParamPM_pCOutput2OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OnScene)))
// Wert für EIN
#define ParamPM_pCOutput2OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OnDim)))
// Wert für AUS
#define ParamPM_pCOutput2Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2Off)))
// Wert für AUS
#define ParamPM_pCOutput2OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OffValue)))
// Wert für AUS
#define ParamPM_pCOutput2OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OffScene)))
// Wert für AUS
#define ParamPM_pCOutput2OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pCOutput2OffDim)))
// Ausschalten über Helligkeit
#define ParamPM_pDBrightnessAuto                    ((knx.paramByte(PM_ParamCalcIndex(PM_pDBrightnessAuto)) & PM_pDBrightnessAutoMask) >> PM_pDBrightnessAutoShift)
// Kurze Anwesenheit erkennen?
#define ParamPM_pDPresenceShort                     ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceShort)) & PM_pDPresenceShortMask))
// Diese Tagesphase sperrt Hardware-LEDs
#define ParamPM_pDLockHardwareLEDs                  ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pDLockHardwareLEDs)) & PM_pDLockHardwareLEDsMask))
// Ausgang 1 sendet
#define ParamPM_pDOutput1Filter                     ((knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1Filter)) & PM_pDOutput1FilterMask) >> PM_pDOutput1FilterShift)
// Ausgang 2 sendet
#define ParamPM_pDOutput2Filter                     (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2Filter)) & PM_pDOutput2FilterMask)
// Manueller Modus ist präsenzabhängig?
#define ParamPM_pDManualWithPresence                ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pDManualWithPresence)) & PM_pDManualWithPresenceMask))
// Erst nach der Kurzzeitpräsenz schalten(z.B. Durchgangsraum)
#define ParamPM_pDPresenceShortNoSwitch             ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceShortNoSwitch)) & PM_pDPresenceShortNoSwitchMask))
// Kurzzeitpräsenz wird ermittelt anhand vom
#define ParamPM_pDPresenceShortCalculation          ((bool)(knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceShortCalculation)) & PM_pDPresenceShortCalculationMask))
// Funktion der Tagesphase
#define ParamPM_pDDayPhaseFunction                  ((knx.paramByte(PM_ParamCalcIndex(PM_pDDayPhaseFunction)) & PM_pDDayPhaseFunctionMask) >> PM_pDDayPhaseFunctionShift)
// Nachlaufzeit
#define ParamPM_pDPresenceDelayBase                 ((knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceDelayBase)) & PM_pDPresenceDelayBaseMask) >> PM_pDPresenceDelayBaseShift)
// Nachlaufzeit
#define ParamPM_pDPresenceDelayTime                 (knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceDelayTime)) & PM_pDPresenceDelayTimeMask)
// Nachlaufzeit (in Millisekunden)
#define ParamPM_pDPresenceDelayTimeMS               (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceDelayTime))))
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pDPresenceShortDurationBase         ((knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceShortDurationBase)) & PM_pDPresenceShortDurationBaseMask) >> PM_pDPresenceShortDurationBaseShift)
// Dauer-der-kurzen-Anwesenheit
#define ParamPM_pDPresenceShortDurationTime         (knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceShortDurationTime)) & PM_pDPresenceShortDurationTimeMask)
// Dauer-der-kurzen-Anwesenheit (in Millisekunden)
#define ParamPM_pDPresenceShortDurationTimeMS       (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceShortDurationTime))))
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pDPresenceShortDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pDPresenceShortDelayBase)) & PM_pDPresenceShortDelayBaseMask) >> PM_pDPresenceShortDelayBaseShift)
// Nachlaufzeit-bei-kurzer-Anwesenheit
#define ParamPM_pDPresenceShortDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceShortDelayTime)) & PM_pDPresenceShortDelayTimeMask)
// Nachlaufzeit-bei-kurzer-Anwesenheit (in Millisekunden)
#define ParamPM_pDPresenceShortDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDPresenceShortDelayTime))))
// Ausschalten-verzoegern-um
#define ParamPM_pDBrightnessOffDelayBase            ((knx.paramByte(PM_ParamCalcIndex(PM_pDBrightnessOffDelayBase)) & PM_pDBrightnessOffDelayBaseMask) >> PM_pDBrightnessOffDelayBaseShift)
// Ausschalten-verzoegern-um
#define ParamPM_pDBrightnessOffDelayTime            (knx.paramWord(PM_ParamCalcIndex(PM_pDBrightnessOffDelayTime)) & PM_pDBrightnessOffDelayTimeMask)
// Ausschalten-verzoegern-um (in Millisekunden)
#define ParamPM_pDBrightnessOffDelayTimeMS          (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDBrightnessOffDelayTime))))
// Manuellen-Modus-beenden-nach
#define ParamPM_pDManualFallbackDelayBase           ((knx.paramByte(PM_ParamCalcIndex(PM_pDManualFallbackDelayBase)) & PM_pDManualFallbackDelayBaseMask) >> PM_pDManualFallbackDelayBaseShift)
// Manuellen-Modus-beenden-nach
#define ParamPM_pDManualFallbackDelayTime           (knx.paramWord(PM_ParamCalcIndex(PM_pDManualFallbackDelayTime)) & PM_pDManualFallbackDelayTimeMask)
// Manuellen-Modus-beenden-nach (in Millisekunden)
#define ParamPM_pDManualFallbackDelayTimeMS         (paramDelay(knx.paramWord(PM_ParamCalcIndex(PM_pDManualFallbackDelayTime))))
// Einschalten: Unterhalb welcher Helligkeit
#define ParamPM_pDBrightnessOn                      (knx.paramWord(PM_ParamCalcIndex(PM_pDBrightnessOn)))
// Ausschalten: Wie viel heller darf es werden
#define ParamPM_pDBrightnessDelta                   (knx.paramWord(PM_ParamCalcIndex(PM_pDBrightnessDelta)))
// Wert für EIN
#define ParamPM_pDOutput1On                         (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1On)))
// Wert für EIN
#define ParamPM_pDOutput1OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OnValue)))
// Wert für EIN
#define ParamPM_pDOutput1OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OnScene)))
// Wert für EIN
#define ParamPM_pDOutput1OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OnDim)))
// Wert für AUS
#define ParamPM_pDOutput1Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1Off)))
// Wert für AUS
#define ParamPM_pDOutput1OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OffValue)))
// Wert für AUS
#define ParamPM_pDOutput1OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OffScene)))
// Wert für AUS
#define ParamPM_pDOutput1OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput1OffDim)))
// Wert für EIN
#define ParamPM_pDOutput2On                         (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2On)))
// Wert für EIN
#define ParamPM_pDOutput2OnValue                    (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OnValue)))
// Wert für EIN
#define ParamPM_pDOutput2OnScene                    (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OnScene)))
// Wert für EIN
#define ParamPM_pDOutput2OnDim                      (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OnDim)))
// Wert für AUS
#define ParamPM_pDOutput2Off                        (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2Off)))
// Wert für AUS
#define ParamPM_pDOutput2OffValue                   (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OffValue)))
// Wert für AUS
#define ParamPM_pDOutput2OffScene                   (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OffScene)))
// Wert für AUS
#define ParamPM_pDOutput2OffDim                     (knx.paramByte(PM_ParamCalcIndex(PM_pDOutput2OffDim)))

// deprecated
#define PM_KoOffset 50

// Communication objects per channel (multiple occurrence)
#define PM_KoBlockOffset 50
#define PM_KoBlockSize 20

#define PM_KoCalcNumber(index) (index + PM_KoBlockOffset + _channelIndex * PM_KoBlockSize)
#define PM_KoCalcIndex(number) ((number >= PM_KoCalcNumber(0) && number < PM_KoCalcNumber(PM_KoBlockSize)) ? (number - PM_KoBlockOffset) % PM_KoBlockSize : -1)
#define PM_KoCalcChannel(number) ((number >= PM_KoBlockOffset && number < PM_KoBlockOffset + PM_ChannelCount * PM_KoBlockSize) ? (number - PM_KoBlockOffset) / PM_KoBlockSize : -1)

#define PM_KoKOpLux 0
#define PM_KoKOpPresence1 1
#define PM_KoKOpPresence2 2
#define PM_KoKOpSetAuto 3
#define PM_KoKOpSetManual 4
#define PM_KoKOpAktorState 5
#define PM_KoKOpLock 6
#define PM_KoKOpReset 7
#define PM_KoKOpDayPhase 8
#define PM_KoKOpLuxOn 9
#define PM_KoKOpLuxOff 10
#define PM_KoKOpPresenceDelay 11
#define PM_KoKOpScene 12
#define PM_KoKOpOutput 13
#define PM_KoKOpOutput2 14
#define PM_KoKOpIsManual 15
#define PM_KoKOpChangeDimRel 16
#define PM_KoKOpChangeDimAbs 17
#define PM_KoKOpChangeSwitch 18
#define PM_KoKOpResetExternalPM 19

// Helligkeit extern
#define KoPM_KOpLux                              (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpLux)))
// Präsenz
#define KoPM_KOpPresence1                        (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpPresence1)))
// Bewegung
#define KoPM_KOpPresence2                        (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpPresence2)))
// Automatik übersteuern
#define KoPM_KOpSetAuto                          (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpSetAuto)))
// Manuell übersteuern
#define KoPM_KOpSetManual                        (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpSetManual)))
// Aktorstatus
#define KoPM_KOpAktorState                       (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpAktorState)))
// Zwangsführung
#define KoPM_KOpLock                             (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpLock)))
// Reset
#define KoPM_KOpReset                            (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpReset)))
// Tagesphase
#define KoPM_KOpDayPhase                         (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpDayPhase)))
// Einschalt-Helligkeitsschwelle
#define KoPM_KOpLuxOn                            (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpLuxOn)))
// Ausschalt-Helligkeitsschwelle
#define KoPM_KOpLuxOff                           (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpLuxOff)))
// Nachlaufzeit
#define KoPM_KOpPresenceDelay                    (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpPresenceDelay)))
// PM über Szene steuern
#define KoPM_KOpScene                            (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpScene)))
// Wert 1
#define KoPM_KOpOutput                           (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpOutput)))
// Wert 2
#define KoPM_KOpOutput2                          (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpOutput2)))
// Status Manuell(1)/Automatik(0)
#define KoPM_KOpIsManual                         (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpIsManual)))
// Änderung relativ dimmen
#define KoPM_KOpChangeDimRel                     (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpChangeDimRel)))
// Änderung absolut dimmen
#define KoPM_KOpChangeDimAbs                     (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpChangeDimAbs)))
// Änderung schalten
#define KoPM_KOpChangeSwitch                     (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpChangeSwitch)))
// Externen PM zurücksetzen
#define KoPM_KOpResetExternalPM                  (knx.getGroupObject(PM_KoCalcNumber(PM_KoKOpResetExternalPM)))

#define BTN_ReactionTimeMultiClick              5642      // 8 Bits, Bit 7-0
#define BTN_ReactionTimeLong                    5643      // 8 Bits, Bit 7-0
#define BTN_ReactionTimeExtraLong               5644      // 8 Bits, Bit 7-0
#define BTN_VisibleChannels                     5645      // uint8_t

// Mehrfach-Klick
#define ParamBTN_ReactionTimeMultiClick              (knx.paramByte(BTN_ReactionTimeMultiClick))
// Langer Tastendruck
#define ParamBTN_ReactionTimeLong                    (knx.paramByte(BTN_ReactionTimeLong))
// Extra langer Tastendruck
#define ParamBTN_ReactionTimeExtraLong               (knx.paramByte(BTN_ReactionTimeExtraLong))
// Verfügbare Kanäle
#define ParamBTN_VisibleChannels                     (knx.paramByte(BTN_VisibleChannels))

#define BTN_ChannelCount 30

// Parameter per channel
#define BTN_ParamBlockOffset 5646
#define BTN_ParamBlockSize 53
#define BTN_ParamCalcIndex(index) (index + BTN_ParamBlockOffset + _channelIndex * BTN_ParamBlockSize)

#define BTN_bMode                                0      // 7 Bits, Bit 7-1
#define     BTN_bModeMask 0xFE
#define     BTN_bModeShift 1
#define BTN_bLock                                1      // 2 Bits, Bit 7-6
#define     BTN_bLockMask 0xC0
#define     BTN_bLockShift 6
#define BTN_bMultiClickCount                     1      // 1 Bit, Bit 7
#define     BTN_bMultiClickCountMask 0x80
#define     BTN_bMultiClickCountShift 7
#define BTN_bDynamicStatus                       1      // 1 Bit, Bit 2
#define     BTN_bDynamicStatusMask 0x04
#define     BTN_bDynamicStatusShift 2
#define BTN_bInA                                 2      // 16 Bits, Bit 15-0
#define BTN_bInB                                 4      // 16 Bits, Bit 15-0
#define BTN_bReactionTimeMultiClick              6      // 8 Bits, Bit 7-0
#define BTN_bReactionTimeLong                    7      // 8 Bits, Bit 7-0
#define BTN_bReactionTimeExtraLong               8      // 8 Bits, Bit 7-0
#define BTN_bOutShort_DPT                        9      // 8 Bits, Bit 7-0
#define BTN_bOutLong_DPT                        10      // 8 Bits, Bit 7-0
#define BTN_bOutExtraLong_DPT                   11      // 8 Bits, Bit 7-0
#define BTN_bOutMulti_DPT                       12      // 8 Bits, Bit 7-0
#define BTN_bOutMulti_Click1_Active             13      // 1 Bit, Bit 7
#define     BTN_bOutMulti_Click1_ActiveMask 0x80
#define     BTN_bOutMulti_Click1_ActiveShift 7
#define BTN_bOutMulti_Click2_Active             13      // 1 Bit, Bit 6
#define     BTN_bOutMulti_Click2_ActiveMask 0x40
#define     BTN_bOutMulti_Click2_ActiveShift 6
#define BTN_bOutMulti_Click3_Active             13      // 1 Bit, Bit 5
#define     BTN_bOutMulti_Click3_ActiveMask 0x20
#define     BTN_bOutMulti_Click3_ActiveShift 5
#define BTN_bOutShort_T1_Active_Press           14      // 1 Bit, Bit 7
#define     BTN_bOutShort_T1_Active_PressMask 0x80
#define     BTN_bOutShort_T1_Active_PressShift 7
#define BTN_bOutShort_T1_Active_Release         14      // 1 Bit, Bit 6
#define     BTN_bOutShort_T1_Active_ReleaseMask 0x40
#define     BTN_bOutShort_T1_Active_ReleaseShift 6
#define BTN_bOutShort_T2_Active_Press           14      // 1 Bit, Bit 5
#define     BTN_bOutShort_T2_Active_PressMask 0x20
#define     BTN_bOutShort_T2_Active_PressShift 5
#define BTN_bOutShort_T2_Active_Release         14      // 1 Bit, Bit 4
#define     BTN_bOutShort_T2_Active_ReleaseMask 0x10
#define     BTN_bOutShort_T2_Active_ReleaseShift 4
#define BTN_bOutLong_T1_Active_Press            15      // 1 Bit, Bit 7
#define     BTN_bOutLong_T1_Active_PressMask 0x80
#define     BTN_bOutLong_T1_Active_PressShift 7
#define BTN_bOutLong_T1_Active_Release          15      // 1 Bit, Bit 6
#define     BTN_bOutLong_T1_Active_ReleaseMask 0x40
#define     BTN_bOutLong_T1_Active_ReleaseShift 6
#define BTN_bOutLong_T2_Active_Press            15      // 1 Bit, Bit 5
#define     BTN_bOutLong_T2_Active_PressMask 0x20
#define     BTN_bOutLong_T2_Active_PressShift 5
#define BTN_bOutLong_T2_Active_Release          15      // 1 Bit, Bit 4
#define     BTN_bOutLong_T2_Active_ReleaseMask 0x10
#define     BTN_bOutLong_T2_Active_ReleaseShift 4
#define BTN_bOutExtraLong_T1_Active_Press       16      // 1 Bit, Bit 7
#define     BTN_bOutExtraLong_T1_Active_PressMask 0x80
#define     BTN_bOutExtraLong_T1_Active_PressShift 7
#define BTN_bOutExtraLong_T1_Active_Release     16      // 1 Bit, Bit 6
#define     BTN_bOutExtraLong_T1_Active_ReleaseMask 0x40
#define     BTN_bOutExtraLong_T1_Active_ReleaseShift 6
#define BTN_bOutExtraLong_T2_Active_Press       16      // 1 Bit, Bit 5
#define     BTN_bOutExtraLong_T2_Active_PressMask 0x20
#define     BTN_bOutExtraLong_T2_Active_PressShift 5
#define BTN_bOutExtraLong_T2_Active_Release     16      // 1 Bit, Bit 4
#define     BTN_bOutExtraLong_T2_Active_ReleaseMask 0x10
#define     BTN_bOutExtraLong_T2_Active_ReleaseShift 4
#define BTN_bOutShort_T1_Dpt1_Press             17      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T1_Dpt1_Release           19      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt1_Press             21      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt1_Release           23      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt1_Press              25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt1_Release            27      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt1_Press              29      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt1_Release            31      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt1_Press         33      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt1_Release       35      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt1_Press         37      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt1_Release       39      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click1_Dpt1               41      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click2_Dpt1               43      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click3_Dpt1               45      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T1_Dpt2_Press             17      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T1_Dpt2_Release           19      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt2_Press             21      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt2_Release           23      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt2_Press              25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt2_Release            27      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt2_Press              29      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt2_Release            31      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt2_Press         33      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt2_Release       35      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt2_Press         37      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt2_Release       39      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click1_Dpt2               41      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click2_Dpt2               43      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click3_Dpt2               45      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T1_Dpt5_Press             17      // uint16_t
#define BTN_bOutShort_T1_Dpt5_Release           19      // uint16_t
#define BTN_bOutShort_T2_Dpt5_Press             21      // uint16_t
#define BTN_bOutShort_T2_Dpt5_Release           23      // uint16_t
#define BTN_bOutLong_T1_Dpt5_Press              25      // uint16_t
#define BTN_bOutLong_T1_Dpt5_Release            27      // uint16_t
#define BTN_bOutLong_T2_Dpt5_Press              29      // uint16_t
#define BTN_bOutLong_T2_Dpt5_Release            31      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt5_Press         33      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt5_Release       35      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt5_Press         37      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt5_Release       39      // uint16_t
#define BTN_bOutMulti_Click1_Dpt5               41      // uint16_t
#define BTN_bOutMulti_Click2_Dpt5               43      // uint16_t
#define BTN_bOutMulti_Click3_Dpt5               45      // uint16_t
#define BTN_bOutShort_T1_Dpt5001_Press          17      // uint16_t
#define BTN_bOutShort_T1_Dpt5001_Release        19      // uint16_t
#define BTN_bOutShort_T2_Dpt5001_Press          21      // uint16_t
#define BTN_bOutShort_T2_Dpt5001_Release        23      // uint16_t
#define BTN_bOutLong_T1_Dpt5001_Press           25      // uint16_t
#define BTN_bOutLong_T1_Dpt5001_Release         27      // uint16_t
#define BTN_bOutLong_T2_Dpt5001_Press           29      // uint16_t
#define BTN_bOutLong_T2_Dpt5001_Release         31      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt5001_Press      33      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt5001_Release    35      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt5001_Press      37      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt5001_Release    39      // uint16_t
#define BTN_bOutMulti_Click1_Dpt5001            41      // uint16_t
#define BTN_bOutMulti_Click2_Dpt5001            43      // uint16_t
#define BTN_bOutMulti_Click3_Dpt5001            45      // uint16_t
#define BTN_bOutShort_T1_Dpt7_Press             17      // uint16_t
#define BTN_bOutShort_T1_Dpt7_Release           19      // uint16_t
#define BTN_bOutShort_T2_Dpt7_Press             21      // uint16_t
#define BTN_bOutShort_T2_Dpt7_Release           23      // uint16_t
#define BTN_bOutLong_T1_Dpt7_Press              25      // uint16_t
#define BTN_bOutLong_T1_Dpt7_Release            27      // uint16_t
#define BTN_bOutLong_T2_Dpt7_Press              29      // uint16_t
#define BTN_bOutLong_T2_Dpt7_Release            31      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt7_Press         33      // uint16_t
#define BTN_bOutExtraLong_T1_Dpt7_Release       35      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt7_Press         37      // uint16_t
#define BTN_bOutExtraLong_T2_Dpt7_Release       39      // uint16_t
#define BTN_bOutMulti_Click1_Dpt7               41      // uint16_t
#define BTN_bOutMulti_Click2_Dpt7               43      // uint16_t
#define BTN_bOutMulti_Click3_Dpt7               45      // uint16_t
#define BTN_bOutShort_T1_Dpt18_Press            17      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T1_Dpt18_Release          19      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt18_Press            21      // 16 Bits, Bit 15-0
#define BTN_bOutShort_T2_Dpt18_Release          23      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt18_Press             25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt18_Release           27      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt18_Press             29      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt18_Release           31      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt18_Press        33      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T1_Dpt18_Release      35      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt18_Press        37      // 16 Bits, Bit 15-0
#define BTN_bOutExtraLong_T2_Dpt18_Release      39      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click1_Dpt18              41      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click2_Dpt18              43      // 16 Bits, Bit 15-0
#define BTN_bOutMulti_Click3_Dpt18              45      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3007_Press           25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3007_PressSingle     25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3007_Release         27      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt3007_Press           29      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt3007_Release         31      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3008_Press           25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3008_PressSingle     25      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T1_Dpt3008_Release         27      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt3008_Press           29      // 16 Bits, Bit 15-0
#define BTN_bOutLong_T2_Dpt3008_Release         31      // 16 Bits, Bit 15-0
#define BTN_bOut2Short_T1                       47      // 2 Bits, Bit 7-6
#define     BTN_bOut2Short_T1Mask 0xC0
#define     BTN_bOut2Short_T1Shift 6
#define BTN_bOut2Short_T2                       47      // 2 Bits, Bit 5-4
#define     BTN_bOut2Short_T2Mask 0x30
#define     BTN_bOut2Short_T2Shift 4
#define BTN_bOut2Long_T1                        47      // 2 Bits, Bit 3-2
#define     BTN_bOut2Long_T1Mask 0x0C
#define     BTN_bOut2Long_T1Shift 2
#define BTN_bOut2Long_T2                        47      // 2 Bits, Bit 1-0
#define     BTN_bOut2Long_T2Mask 0x03
#define     BTN_bOut2Long_T2Shift 0
#define BTN_bOut2ExtraLong_T1                   48      // 2 Bits, Bit 7-6
#define     BTN_bOut2ExtraLong_T1Mask 0xC0
#define     BTN_bOut2ExtraLong_T1Shift 6
#define BTN_bOut2ExtraLong_T2                   48      // 2 Bits, Bit 5-4
#define     BTN_bOut2ExtraLong_T2Mask 0x30
#define     BTN_bOut2ExtraLong_T2Shift 4
#define BTN_bStatusFallbackTime                 49      // uint16_t
#define BTN_bStatusThresholdHigh                51      // uint8_t
#define BTN_bStatusThresholdLow                 52      // uint8_t

// Modus
#define ParamBTN_bMode                               ((knx.paramByte(BTN_ParamCalcIndex(BTN_bMode)) & BTN_bModeMask) >> BTN_bModeShift)
// Sperre
#define ParamBTN_bLock                               ((knx.paramByte(BTN_ParamCalcIndex(BTN_bLock)) & BTN_bLockMask) >> BTN_bLockShift)
// Ausgabe der Klickanzahl
#define ParamBTN_bMultiClickCount                    ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bMultiClickCount)) & BTN_bMultiClickCountMask))
// Dynamische Richtung
#define ParamBTN_bDynamicStatus                      ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bDynamicStatus)) & BTN_bDynamicStatusMask))
//    1. Taster
#define ParamBTN_bInA                                (knx.paramWord(BTN_ParamCalcIndex(BTN_bInA)))
//    2. Taster
#define ParamBTN_bInB                                (knx.paramWord(BTN_ParamCalcIndex(BTN_bInB)))
// Mehrfach-Klick
#define ParamBTN_bReactionTimeMultiClick             (knx.paramByte(BTN_ParamCalcIndex(BTN_bReactionTimeMultiClick)))
// Langer Tastendruck
#define ParamBTN_bReactionTimeLong                   (knx.paramByte(BTN_ParamCalcIndex(BTN_bReactionTimeLong)))
// Extra langer Tastendruck
#define ParamBTN_bReactionTimeExtraLong              (knx.paramByte(BTN_ParamCalcIndex(BTN_bReactionTimeExtraLong)))
// Datentyp
#define ParamBTN_bOutShort_DPT                       (knx.paramByte(BTN_ParamCalcIndex(BTN_bOutShort_DPT)))
// Datentyp
#define ParamBTN_bOutLong_DPT                        (knx.paramByte(BTN_ParamCalcIndex(BTN_bOutLong_DPT)))
// Datentyp
#define ParamBTN_bOutExtraLong_DPT                   (knx.paramByte(BTN_ParamCalcIndex(BTN_bOutExtraLong_DPT)))
// Datentyp
#define ParamBTN_bOutMulti_DPT                       (knx.paramByte(BTN_ParamCalcIndex(BTN_bOutMulti_DPT)))
// 1. Klick
#define ParamBTN_bOutMulti_Click1_Active             ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Active)) & BTN_bOutMulti_Click1_ActiveMask))
// 2. Klick
#define ParamBTN_bOutMulti_Click2_Active             ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Active)) & BTN_bOutMulti_Click2_ActiveMask))
// 3. Klick
#define ParamBTN_bOutMulti_Click3_Active             ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Active)) & BTN_bOutMulti_Click3_ActiveMask))
// Wert beim Drücken
#define ParamBTN_bOutShort_T1_Active_Press           ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutShort_T1_Active_Press)) & BTN_bOutShort_T1_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutShort_T1_Active_Release         ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutShort_T1_Active_Release)) & BTN_bOutShort_T1_Active_ReleaseMask))
// Wert beim Drücken
#define ParamBTN_bOutShort_T2_Active_Press           ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutShort_T2_Active_Press)) & BTN_bOutShort_T2_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutShort_T2_Active_Release         ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutShort_T2_Active_Release)) & BTN_bOutShort_T2_Active_ReleaseMask))
// Wert beim Drücken
#define ParamBTN_bOutLong_T1_Active_Press            ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutLong_T1_Active_Press)) & BTN_bOutLong_T1_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutLong_T1_Active_Release          ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutLong_T1_Active_Release)) & BTN_bOutLong_T1_Active_ReleaseMask))
// Wert beim Drücken
#define ParamBTN_bOutLong_T2_Active_Press            ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutLong_T2_Active_Press)) & BTN_bOutLong_T2_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutLong_T2_Active_Release          ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutLong_T2_Active_Release)) & BTN_bOutLong_T2_Active_ReleaseMask))
// Wert beim Drücken
#define ParamBTN_bOutExtraLong_T1_Active_Press       ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Active_Press)) & BTN_bOutExtraLong_T1_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutExtraLong_T1_Active_Release     ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Active_Release)) & BTN_bOutExtraLong_T1_Active_ReleaseMask))
// Wert beim Drücken
#define ParamBTN_bOutExtraLong_T2_Active_Press       ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Active_Press)) & BTN_bOutExtraLong_T2_Active_PressMask))
// Wert beim Loslassen
#define ParamBTN_bOutExtraLong_T2_Active_Release     ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Active_Release)) & BTN_bOutExtraLong_T2_Active_ReleaseMask))
// 
#define ParamBTN_bOutShort_T1_Dpt1_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt1_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt1_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt1_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt1_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt1_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt1_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt1_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt1_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt1_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt1_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt1_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt1_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt1_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt1_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt1_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt1_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt1_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt1_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt1_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt1_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt1_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt1_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt1_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt1               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt1)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt1               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt1)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt1               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt1)))
// 
#define ParamBTN_bOutShort_T1_Dpt2_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt2_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt2_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt2_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt2_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt2_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt2_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt2_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt2_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt2_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt2_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt2_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt2_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt2_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt2_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt2_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt2_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt2_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt2_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt2_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt2_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt2_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt2_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt2_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt2               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt2)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt2               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt2)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt2               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt2)))
// 
#define ParamBTN_bOutShort_T1_Dpt5_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt5_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt5_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt5_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt5_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt5_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt5_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt5_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt5_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt5_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt5_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt5_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt5_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt5_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt5_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt5_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt5_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt5_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt5_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt5_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt5_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt5_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt5_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt5_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt5               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt5)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt5               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt5)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt5               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt5)))
// 
#define ParamBTN_bOutShort_T1_Dpt5001_Press          (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt5001_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt5001_Release        (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt5001_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt5001_Press          (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt5001_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt5001_Release        (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt5001_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt5001_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt5001_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt5001_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt5001_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt5001_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt5001_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt5001_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt5001_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt5001_Press      (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt5001_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt5001_Release    (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt5001_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt5001_Press      (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt5001_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt5001_Release    (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt5001_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt5001            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt5001)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt5001            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt5001)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt5001            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt5001)))
// 
#define ParamBTN_bOutShort_T1_Dpt7_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt7_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt7_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt7_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt7_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt7_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt7_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt7_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt7_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt7_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt7_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt7_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt7_Press              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt7_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt7_Release            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt7_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt7_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt7_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt7_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt7_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt7_Press         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt7_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt7_Release       (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt7_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt7               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt7)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt7               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt7)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt7               (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt7)))
// 
#define ParamBTN_bOutShort_T1_Dpt18_Press            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt18_Press)))
// 
#define ParamBTN_bOutShort_T1_Dpt18_Release          (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T1_Dpt18_Release)))
// 
#define ParamBTN_bOutShort_T2_Dpt18_Press            (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt18_Press)))
// 
#define ParamBTN_bOutShort_T2_Dpt18_Release          (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutShort_T2_Dpt18_Release)))
// 
#define ParamBTN_bOutLong_T1_Dpt18_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt18_Press)))
// 
#define ParamBTN_bOutLong_T1_Dpt18_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt18_Release)))
// 
#define ParamBTN_bOutLong_T2_Dpt18_Press             (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt18_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt18_Release           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt18_Release)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt18_Press        (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt18_Press)))
// 
#define ParamBTN_bOutExtraLong_T1_Dpt18_Release      (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T1_Dpt18_Release)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt18_Press        (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt18_Press)))
// 
#define ParamBTN_bOutExtraLong_T2_Dpt18_Release      (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutExtraLong_T2_Dpt18_Release)))
// 
#define ParamBTN_bOutMulti_Click1_Dpt18              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click1_Dpt18)))
// 
#define ParamBTN_bOutMulti_Click2_Dpt18              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click2_Dpt18)))
// 
#define ParamBTN_bOutMulti_Click3_Dpt18              (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutMulti_Click3_Dpt18)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T1_Dpt3007_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3007_Press)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T1_Dpt3007_PressSingle     (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3007_PressSingle)))
// 
#define ParamBTN_bOutLong_T1_Dpt3007_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3007_Release)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T2_Dpt3007_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt3007_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt3007_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt3007_Release)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T1_Dpt3008_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3008_Press)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T1_Dpt3008_PressSingle     (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3008_PressSingle)))
// 
#define ParamBTN_bOutLong_T1_Dpt3008_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T1_Dpt3008_Release)))
// Wert beim Drücken
#define ParamBTN_bOutLong_T2_Dpt3008_Press           (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt3008_Press)))
// 
#define ParamBTN_bOutLong_T2_Dpt3008_Release         (knx.paramWord(BTN_ParamCalcIndex(BTN_bOutLong_T2_Dpt3008_Release)))
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2Short_T1                       ((knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2Short_T1)) & BTN_bOut2Short_T1Mask) >> BTN_bOut2Short_T1Shift)
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2Short_T2                       ((knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2Short_T2)) & BTN_bOut2Short_T2Mask) >> BTN_bOut2Short_T2Shift)
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2Long_T1                        ((knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2Long_T1)) & BTN_bOut2Long_T1Mask) >> BTN_bOut2Long_T1Shift)
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2Long_T2                        (knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2Long_T2)) & BTN_bOut2Long_T2Mask)
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2ExtraLong_T1                   ((knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2ExtraLong_T1)) & BTN_bOut2ExtraLong_T1Mask) >> BTN_bOut2ExtraLong_T1Shift)
// Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_bOut2ExtraLong_T2                   ((knx.paramByte(BTN_ParamCalcIndex(BTN_bOut2ExtraLong_T2)) & BTN_bOut2ExtraLong_T2Mask) >> BTN_bOut2ExtraLong_T2Shift)
// Verzögerung
#define ParamBTN_bStatusFallbackTime                 (knx.paramWord(BTN_ParamCalcIndex(BTN_bStatusFallbackTime)))
// Oberer Schwellwert
#define ParamBTN_bStatusThresholdHigh                (knx.paramByte(BTN_ParamCalcIndex(BTN_bStatusThresholdHigh)))
// Unterer Schwellwert
#define ParamBTN_bStatusThresholdLow                 (knx.paramByte(BTN_ParamCalcIndex(BTN_bStatusThresholdLow)))

// deprecated
#define BTN_KoOffset 1150

// Communication objects per channel (multiple occurrence)
#define BTN_KoBlockOffset 1150
#define BTN_KoBlockSize 12

#define BTN_KoCalcNumber(index) (index + BTN_KoBlockOffset + _channelIndex * BTN_KoBlockSize)
#define BTN_KoCalcIndex(number) ((number >= BTN_KoCalcNumber(0) && number < BTN_KoCalcNumber(BTN_KoBlockSize)) ? (number - BTN_KoBlockOffset) % BTN_KoBlockSize : -1)
#define BTN_KoCalcChannel(number) ((number >= BTN_KoBlockOffset && number < BTN_KoBlockOffset + BTN_ChannelCount * BTN_KoBlockSize) ? (number - BTN_KoBlockOffset) / BTN_KoBlockSize : -1)

#define BTN_KoLock 0
#define BTN_KoIn1 1
#define BTN_KoIn2 2
#define BTN_KoOut1Status 3
#define BTN_KoOut2Status 4
#define BTN_KoOut3Status 5
#define BTN_KoOut1 6
#define BTN_KoOut2 7
#define BTN_KoOut3 8
#define BTN_KoOut4 9
#define BTN_KoOut5 10
#define BTN_KoOut6 11

// 
#define KoBTN_Lock                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoLock)))
// 
#define KoBTN_In1                                 (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoIn1)))
// 
#define KoBTN_In2                                 (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoIn2)))
// 
#define KoBTN_Out1Status                          (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut1Status)))
// 
#define KoBTN_Out2Status                          (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut2Status)))
// 
#define KoBTN_Out3Status                          (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut3Status)))
// 
#define KoBTN_Out1                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut1)))
// 
#define KoBTN_Out2                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut2)))
// 
#define KoBTN_Out3                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut3)))
// 
#define KoBTN_Out4                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut4)))
// 
#define KoBTN_Out5                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut5)))
// 
#define KoBTN_Out6                                (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoOut6)))

#define LOG_BuzzerInstalled                     7236      // 1 Bit, Bit 7
#define     LOG_BuzzerInstalledMask 0x80
#define     LOG_BuzzerInstalledShift 7
#define LOG_LedInstalled                        7236      // 1 Bit, Bit 6
#define     LOG_LedInstalledMask 0x40
#define     LOG_LedInstalledShift 6
#define LOG_VacationKo                          7236      // 1 Bit, Bit 5
#define     LOG_VacationKoMask 0x20
#define     LOG_VacationKoShift 5
#define LOG_HolidayKo                           7236      // 1 Bit, Bit 4
#define     LOG_HolidayKoMask 0x10
#define     LOG_HolidayKoShift 4
#define LOG_VacationRead                        7236      // 1 Bit, Bit 3
#define     LOG_VacationReadMask 0x08
#define     LOG_VacationReadShift 3
#define LOG_HolidaySend                         7236      // 1 Bit, Bit 2
#define     LOG_HolidaySendMask 0x04
#define     LOG_HolidaySendShift 2
#define LOG_Neujahr                             7237      // 1 Bit, Bit 7
#define     LOG_NeujahrMask 0x80
#define     LOG_NeujahrShift 7
#define LOG_DreiKoenige                         7237      // 1 Bit, Bit 6
#define     LOG_DreiKoenigeMask 0x40
#define     LOG_DreiKoenigeShift 6
#define LOG_Weiberfastnacht                     7237      // 1 Bit, Bit 5
#define     LOG_WeiberfastnachtMask 0x20
#define     LOG_WeiberfastnachtShift 5
#define LOG_Rosenmontag                         7237      // 1 Bit, Bit 4
#define     LOG_RosenmontagMask 0x10
#define     LOG_RosenmontagShift 4
#define LOG_Fastnachtsdienstag                  7237      // 1 Bit, Bit 3
#define     LOG_FastnachtsdienstagMask 0x08
#define     LOG_FastnachtsdienstagShift 3
#define LOG_Aschermittwoch                      7237      // 1 Bit, Bit 2
#define     LOG_AschermittwochMask 0x04
#define     LOG_AschermittwochShift 2
#define LOG_Frauentag                           7237      // 1 Bit, Bit 1
#define     LOG_FrauentagMask 0x02
#define     LOG_FrauentagShift 1
#define LOG_Gruendonnerstag                     7237      // 1 Bit, Bit 0
#define     LOG_GruendonnerstagMask 0x01
#define     LOG_GruendonnerstagShift 0
#define LOG_Karfreitag                          7238      // 1 Bit, Bit 7
#define     LOG_KarfreitagMask 0x80
#define     LOG_KarfreitagShift 7
#define LOG_Ostersonntag                        7238      // 1 Bit, Bit 6
#define     LOG_OstersonntagMask 0x40
#define     LOG_OstersonntagShift 6
#define LOG_Ostermontag                         7238      // 1 Bit, Bit 5
#define     LOG_OstermontagMask 0x20
#define     LOG_OstermontagShift 5
#define LOG_TagDerArbeit                        7238      // 1 Bit, Bit 4
#define     LOG_TagDerArbeitMask 0x10
#define     LOG_TagDerArbeitShift 4
#define LOG_Himmelfahrt                         7238      // 1 Bit, Bit 3
#define     LOG_HimmelfahrtMask 0x08
#define     LOG_HimmelfahrtShift 3
#define LOG_Pfingstsonntag                      7238      // 1 Bit, Bit 2
#define     LOG_PfingstsonntagMask 0x04
#define     LOG_PfingstsonntagShift 2
#define LOG_Pfingstmontag                       7238      // 1 Bit, Bit 1
#define     LOG_PfingstmontagMask 0x02
#define     LOG_PfingstmontagShift 1
#define LOG_Fronleichnam                        7238      // 1 Bit, Bit 0
#define     LOG_FronleichnamMask 0x01
#define     LOG_FronleichnamShift 0
#define LOG_Friedensfest                        7239      // 1 Bit, Bit 7
#define     LOG_FriedensfestMask 0x80
#define     LOG_FriedensfestShift 7
#define LOG_MariaHimmelfahrt                    7239      // 1 Bit, Bit 6
#define     LOG_MariaHimmelfahrtMask 0x40
#define     LOG_MariaHimmelfahrtShift 6
#define LOG_DeutscheEinheit                     7239      // 1 Bit, Bit 5
#define     LOG_DeutscheEinheitMask 0x20
#define     LOG_DeutscheEinheitShift 5
#define LOG_Reformationstag                     7239      // 1 Bit, Bit 4
#define     LOG_ReformationstagMask 0x10
#define     LOG_ReformationstagShift 4
#define LOG_Allerheiligen                       7239      // 1 Bit, Bit 3
#define     LOG_AllerheiligenMask 0x08
#define     LOG_AllerheiligenShift 3
#define LOG_BussBettag                          7239      // 1 Bit, Bit 2
#define     LOG_BussBettagMask 0x04
#define     LOG_BussBettagShift 2
#define LOG_Advent1                             7239      // 1 Bit, Bit 1
#define     LOG_Advent1Mask 0x02
#define     LOG_Advent1Shift 1
#define LOG_Advent2                             7239      // 1 Bit, Bit 0
#define     LOG_Advent2Mask 0x01
#define     LOG_Advent2Shift 0
#define LOG_Advent3                             7240      // 1 Bit, Bit 7
#define     LOG_Advent3Mask 0x80
#define     LOG_Advent3Shift 7
#define LOG_Advent4                             7240      // 1 Bit, Bit 6
#define     LOG_Advent4Mask 0x40
#define     LOG_Advent4Shift 6
#define LOG_Heiligabend                         7240      // 1 Bit, Bit 5
#define     LOG_HeiligabendMask 0x20
#define     LOG_HeiligabendShift 5
#define LOG_Weihnachtstag1                      7240      // 1 Bit, Bit 4
#define     LOG_Weihnachtstag1Mask 0x10
#define     LOG_Weihnachtstag1Shift 4
#define LOG_Weihnachtstag2                      7240      // 1 Bit, Bit 3
#define     LOG_Weihnachtstag2Mask 0x08
#define     LOG_Weihnachtstag2Shift 3
#define LOG_Silvester                           7240      // 1 Bit, Bit 2
#define     LOG_SilvesterMask 0x04
#define     LOG_SilvesterShift 2
#define LOG_Nationalfeiertag                    7240      // 1 Bit, Bit 1
#define     LOG_NationalfeiertagMask 0x02
#define     LOG_NationalfeiertagShift 1
#define LOG_MariaEmpfaengnis                    7240      // 1 Bit, Bit 0
#define     LOG_MariaEmpfaengnisMask 0x01
#define     LOG_MariaEmpfaengnisShift 0
#define LOG_NationalfeiertagSchweiz             7241      // 1 Bit, Bit 7
#define     LOG_NationalfeiertagSchweizMask 0x80
#define     LOG_NationalfeiertagSchweizShift 7
#define LOG_Totensonntag                        7241      // 1 Bit, Bit 6
#define     LOG_TotensonntagMask 0x40
#define     LOG_TotensonntagShift 6
#define LOG_BuzzerSilent                        7242      // uint16_t
#define LOG_BuzzerNormal                        7244      // uint16_t
#define LOG_BuzzerLoud                          7246      // uint16_t
#define LOG_VisibleChannels                     7248      // uint8_t
#define LOG_LedMapping                          7249      // 3 Bits, Bit 7-5
#define     LOG_LedMappingMask 0xE0
#define     LOG_LedMappingShift 5
#define LOG_UserFormula1                        7250      // char*, 99 Byte
#define LOG_UserFormula1Active                  7349      // 1 Bit, Bit 7
#define     LOG_UserFormula1ActiveMask 0x80
#define     LOG_UserFormula1ActiveShift 7
#define LOG_UserFormula2                        7350      // char*, 99 Byte
#define LOG_UserFormula2Active                  7449      // 1 Bit, Bit 7
#define     LOG_UserFormula2ActiveMask 0x80
#define     LOG_UserFormula2ActiveShift 7
#define LOG_UserFormula3                        7450      // char*, 99 Byte
#define LOG_UserFormula3Active                  7549      // 1 Bit, Bit 7
#define     LOG_UserFormula3ActiveMask 0x80
#define     LOG_UserFormula3ActiveShift 7
#define LOG_UserFormula4                        7550      // char*, 99 Byte
#define LOG_UserFormula4Active                  7649      // 1 Bit, Bit 7
#define     LOG_UserFormula4ActiveMask 0x80
#define     LOG_UserFormula4ActiveShift 7
#define LOG_UserFormula5                        7650      // char*, 99 Byte
#define LOG_UserFormula5Active                  7749      // 1 Bit, Bit 7
#define     LOG_UserFormula5ActiveMask 0x80
#define     LOG_UserFormula5ActiveShift 7
#define LOG_UserFormula6                        7750      // char*, 99 Byte
#define LOG_UserFormula6Active                  7849      // 1 Bit, Bit 7
#define     LOG_UserFormula6ActiveMask 0x80
#define     LOG_UserFormula6ActiveShift 7
#define LOG_UserFormula7                        7850      // char*, 99 Byte
#define LOG_UserFormula7Active                  7949      // 1 Bit, Bit 7
#define     LOG_UserFormula7ActiveMask 0x80
#define     LOG_UserFormula7ActiveShift 7
#define LOG_UserFormula8                        7950      // char*, 99 Byte
#define LOG_UserFormula8Active                  8049      // 1 Bit, Bit 7
#define     LOG_UserFormula8ActiveMask 0x80
#define     LOG_UserFormula8ActiveShift 7
#define LOG_UserFormula9                        8050      // char*, 99 Byte
#define LOG_UserFormula9Active                  8149      // 1 Bit, Bit 7
#define     LOG_UserFormula9ActiveMask 0x80
#define     LOG_UserFormula9ActiveShift 7
#define LOG_UserFormula10                       8150      // char*, 99 Byte
#define LOG_UserFormula10Active                 8249      // 1 Bit, Bit 7
#define     LOG_UserFormula10ActiveMask 0x80
#define     LOG_UserFormula10ActiveShift 7
#define LOG_UserFormula11                       8250      // char*, 99 Byte
#define LOG_UserFormula11Active                 8349      // 1 Bit, Bit 7
#define     LOG_UserFormula11ActiveMask 0x80
#define     LOG_UserFormula11ActiveShift 7
#define LOG_UserFormula12                       8350      // char*, 99 Byte
#define LOG_UserFormula12Active                 8449      // 1 Bit, Bit 7
#define     LOG_UserFormula12ActiveMask 0x80
#define     LOG_UserFormula12ActiveShift 7
#define LOG_UserFormula13                       8450      // char*, 99 Byte
#define LOG_UserFormula13Active                 8549      // 1 Bit, Bit 7
#define     LOG_UserFormula13ActiveMask 0x80
#define     LOG_UserFormula13ActiveShift 7
#define LOG_UserFormula14                       8550      // char*, 99 Byte
#define LOG_UserFormula14Active                 8649      // 1 Bit, Bit 7
#define     LOG_UserFormula14ActiveMask 0x80
#define     LOG_UserFormula14ActiveShift 7
#define LOG_UserFormula15                       8650      // char*, 99 Byte
#define LOG_UserFormula15Active                 8749      // 1 Bit, Bit 7
#define     LOG_UserFormula15ActiveMask 0x80
#define     LOG_UserFormula15ActiveShift 7
#define LOG_UserFormula16                       8750      // char*, 99 Byte
#define LOG_UserFormula16Active                 8849      // 1 Bit, Bit 7
#define     LOG_UserFormula16ActiveMask 0x80
#define     LOG_UserFormula16ActiveShift 7
#define LOG_UserFormula17                       8850      // char*, 99 Byte
#define LOG_UserFormula17Active                 8949      // 1 Bit, Bit 7
#define     LOG_UserFormula17ActiveMask 0x80
#define     LOG_UserFormula17ActiveShift 7
#define LOG_UserFormula18                       8950      // char*, 99 Byte
#define LOG_UserFormula18Active                 9049      // 1 Bit, Bit 7
#define     LOG_UserFormula18ActiveMask 0x80
#define     LOG_UserFormula18ActiveShift 7
#define LOG_UserFormula19                       9050      // char*, 99 Byte
#define LOG_UserFormula19Active                 9149      // 1 Bit, Bit 7
#define     LOG_UserFormula19ActiveMask 0x80
#define     LOG_UserFormula19ActiveShift 7
#define LOG_UserFormula20                       9150      // char*, 99 Byte
#define LOG_UserFormula20Active                 9249      // 1 Bit, Bit 7
#define     LOG_UserFormula20ActiveMask 0x80
#define     LOG_UserFormula20ActiveShift 7
#define LOG_UserFormula21                       9250      // char*, 99 Byte
#define LOG_UserFormula21Active                 9349      // 1 Bit, Bit 7
#define     LOG_UserFormula21ActiveMask 0x80
#define     LOG_UserFormula21ActiveShift 7
#define LOG_UserFormula22                       9350      // char*, 99 Byte
#define LOG_UserFormula22Active                 9449      // 1 Bit, Bit 7
#define     LOG_UserFormula22ActiveMask 0x80
#define     LOG_UserFormula22ActiveShift 7
#define LOG_UserFormula23                       9450      // char*, 99 Byte
#define LOG_UserFormula23Active                 9549      // 1 Bit, Bit 7
#define     LOG_UserFormula23ActiveMask 0x80
#define     LOG_UserFormula23ActiveShift 7
#define LOG_UserFormula24                       9550      // char*, 99 Byte
#define LOG_UserFormula24Active                 9649      // 1 Bit, Bit 7
#define     LOG_UserFormula24ActiveMask 0x80
#define     LOG_UserFormula24ActiveShift 7
#define LOG_UserFormula25                       9650      // char*, 99 Byte
#define LOG_UserFormula25Active                 9749      // 1 Bit, Bit 7
#define     LOG_UserFormula25ActiveMask 0x80
#define     LOG_UserFormula25ActiveShift 7
#define LOG_UserFormula26                       9750      // char*, 99 Byte
#define LOG_UserFormula26Active                 9849      // 1 Bit, Bit 7
#define     LOG_UserFormula26ActiveMask 0x80
#define     LOG_UserFormula26ActiveShift 7
#define LOG_UserFormula27                       9850      // char*, 99 Byte
#define LOG_UserFormula27Active                 9949      // 1 Bit, Bit 7
#define     LOG_UserFormula27ActiveMask 0x80
#define     LOG_UserFormula27ActiveShift 7
#define LOG_UserFormula28                       9950      // char*, 99 Byte
#define LOG_UserFormula28Active                 10049      // 1 Bit, Bit 7
#define     LOG_UserFormula28ActiveMask 0x80
#define     LOG_UserFormula28ActiveShift 7
#define LOG_UserFormula29                       10050      // char*, 99 Byte
#define LOG_UserFormula29Active                 10149      // 1 Bit, Bit 7
#define     LOG_UserFormula29ActiveMask 0x80
#define     LOG_UserFormula29ActiveShift 7
#define LOG_UserFormula30                       10150      // char*, 99 Byte
#define LOG_UserFormula30Active                 10249      // 1 Bit, Bit 7
#define     LOG_UserFormula30ActiveMask 0x80
#define     LOG_UserFormula30ActiveShift 7

// Akustischer Signalgeber vorhanden (Buzzer)?
#define ParamLOG_BuzzerInstalled                     ((bool)(knx.paramByte(LOG_BuzzerInstalled) & LOG_BuzzerInstalledMask))
// Optischer Signalgeber vorhanden (RGB-LED)?
#define ParamLOG_LedInstalled                        ((bool)(knx.paramByte(LOG_LedInstalled) & LOG_LedInstalledMask))
// Urlaubsbehandlung aktivieren?
#define ParamLOG_VacationKo                          ((bool)(knx.paramByte(LOG_VacationKo) & LOG_VacationKoMask))
// Feiertage auf dem Bus verfügbar machen?
#define ParamLOG_HolidayKo                           ((bool)(knx.paramByte(LOG_HolidayKo) & LOG_HolidayKoMask))
// Nach Neustart Urlaubsinfo lesen?
#define ParamLOG_VacationRead                        ((bool)(knx.paramByte(LOG_VacationRead) & LOG_VacationReadMask))
// Nach Neuberechnung Feiertagsinfo senden?
#define ParamLOG_HolidaySend                         ((bool)(knx.paramByte(LOG_HolidaySend) & LOG_HolidaySendMask))
// 1. Neujahr
#define ParamLOG_Neujahr                             ((bool)(knx.paramByte(LOG_Neujahr) & LOG_NeujahrMask))
// 2. Heilige Drei Könige
#define ParamLOG_DreiKoenige                         ((bool)(knx.paramByte(LOG_DreiKoenige) & LOG_DreiKoenigeMask))
// 3. Weiberfastnacht
#define ParamLOG_Weiberfastnacht                     ((bool)(knx.paramByte(LOG_Weiberfastnacht) & LOG_WeiberfastnachtMask))
// 4. Rosenmontag
#define ParamLOG_Rosenmontag                         ((bool)(knx.paramByte(LOG_Rosenmontag) & LOG_RosenmontagMask))
// 5. Fastnachtsdienstag
#define ParamLOG_Fastnachtsdienstag                  ((bool)(knx.paramByte(LOG_Fastnachtsdienstag) & LOG_FastnachtsdienstagMask))
// 6. Aschermittwoch
#define ParamLOG_Aschermittwoch                      ((bool)(knx.paramByte(LOG_Aschermittwoch) & LOG_AschermittwochMask))
// 7. Frauentag
#define ParamLOG_Frauentag                           ((bool)(knx.paramByte(LOG_Frauentag) & LOG_FrauentagMask))
// 8. Gründonnerstag
#define ParamLOG_Gruendonnerstag                     ((bool)(knx.paramByte(LOG_Gruendonnerstag) & LOG_GruendonnerstagMask))
// 9. Karfreitag
#define ParamLOG_Karfreitag                          ((bool)(knx.paramByte(LOG_Karfreitag) & LOG_KarfreitagMask))
// 10. Ostersonntag
#define ParamLOG_Ostersonntag                        ((bool)(knx.paramByte(LOG_Ostersonntag) & LOG_OstersonntagMask))
// 11. Ostermontag
#define ParamLOG_Ostermontag                         ((bool)(knx.paramByte(LOG_Ostermontag) & LOG_OstermontagMask))
// 12. Tag der Arbeit
#define ParamLOG_TagDerArbeit                        ((bool)(knx.paramByte(LOG_TagDerArbeit) & LOG_TagDerArbeitMask))
// 13. Christi Himmelfahrt
#define ParamLOG_Himmelfahrt                         ((bool)(knx.paramByte(LOG_Himmelfahrt) & LOG_HimmelfahrtMask))
// 14. Pfingstsonntag
#define ParamLOG_Pfingstsonntag                      ((bool)(knx.paramByte(LOG_Pfingstsonntag) & LOG_PfingstsonntagMask))
// 15. Pfingstmontag
#define ParamLOG_Pfingstmontag                       ((bool)(knx.paramByte(LOG_Pfingstmontag) & LOG_PfingstmontagMask))
// 16. Fronleichnam
#define ParamLOG_Fronleichnam                        ((bool)(knx.paramByte(LOG_Fronleichnam) & LOG_FronleichnamMask))
// 17. Hohes Friedensfest
#define ParamLOG_Friedensfest                        ((bool)(knx.paramByte(LOG_Friedensfest) & LOG_FriedensfestMask))
// 18. Mariä Himmelfahrt
#define ParamLOG_MariaHimmelfahrt                    ((bool)(knx.paramByte(LOG_MariaHimmelfahrt) & LOG_MariaHimmelfahrtMask))
// 19. Tag der Deutschen Einheit
#define ParamLOG_DeutscheEinheit                     ((bool)(knx.paramByte(LOG_DeutscheEinheit) & LOG_DeutscheEinheitMask))
// 20. Reformationstag
#define ParamLOG_Reformationstag                     ((bool)(knx.paramByte(LOG_Reformationstag) & LOG_ReformationstagMask))
// 21. Allerheiligen
#define ParamLOG_Allerheiligen                       ((bool)(knx.paramByte(LOG_Allerheiligen) & LOG_AllerheiligenMask))
// 22. Buß- und Bettag
#define ParamLOG_BussBettag                          ((bool)(knx.paramByte(LOG_BussBettag) & LOG_BussBettagMask))
// 23. Erster Advent
#define ParamLOG_Advent1                             ((bool)(knx.paramByte(LOG_Advent1) & LOG_Advent1Mask))
// 24. Zweiter Advent
#define ParamLOG_Advent2                             ((bool)(knx.paramByte(LOG_Advent2) & LOG_Advent2Mask))
// 25. Dritter Advent
#define ParamLOG_Advent3                             ((bool)(knx.paramByte(LOG_Advent3) & LOG_Advent3Mask))
// 26. Vierter Advent
#define ParamLOG_Advent4                             ((bool)(knx.paramByte(LOG_Advent4) & LOG_Advent4Mask))
// 27. Heiligabend
#define ParamLOG_Heiligabend                         ((bool)(knx.paramByte(LOG_Heiligabend) & LOG_HeiligabendMask))
// 28. Erster Weihnachtstag
#define ParamLOG_Weihnachtstag1                      ((bool)(knx.paramByte(LOG_Weihnachtstag1) & LOG_Weihnachtstag1Mask))
// 29. Zweiter Weihnachtstag
#define ParamLOG_Weihnachtstag2                      ((bool)(knx.paramByte(LOG_Weihnachtstag2) & LOG_Weihnachtstag2Mask))
// 30. Silvester
#define ParamLOG_Silvester                           ((bool)(knx.paramByte(LOG_Silvester) & LOG_SilvesterMask))
// 31. Nationalfeiertag (AT)
#define ParamLOG_Nationalfeiertag                    ((bool)(knx.paramByte(LOG_Nationalfeiertag) & LOG_NationalfeiertagMask))
// 32. Maria Empfängnis (AT)
#define ParamLOG_MariaEmpfaengnis                    ((bool)(knx.paramByte(LOG_MariaEmpfaengnis) & LOG_MariaEmpfaengnisMask))
// 33. Nationalfeiertag (CH)
#define ParamLOG_NationalfeiertagSchweiz             ((bool)(knx.paramByte(LOG_NationalfeiertagSchweiz) & LOG_NationalfeiertagSchweizMask))
// 34. Totensonntag
#define ParamLOG_Totensonntag                        ((bool)(knx.paramByte(LOG_Totensonntag) & LOG_TotensonntagMask))
// Frequenz für Buzzer (leise)
#define ParamLOG_BuzzerSilent                        (knx.paramWord(LOG_BuzzerSilent))
// Frequenz für Buzzer (normal)
#define ParamLOG_BuzzerNormal                        (knx.paramWord(LOG_BuzzerNormal))
// Frequenz für Buzzer (laut)
#define ParamLOG_BuzzerLoud                          (knx.paramWord(LOG_BuzzerLoud))
// Verfügbare Kanäle
#define ParamLOG_VisibleChannels                     (knx.paramByte(LOG_VisibleChannels))
// Lötpad A / B / C entspricht
#define ParamLOG_LedMapping                          ((knx.paramByte(LOG_LedMapping) & LOG_LedMappingMask) >> LOG_LedMappingShift)
// Formeldefinition
#define ParamLOG_UserFormula1                        (knx.paramData(LOG_UserFormula1))
// Benutzerformel 1 aktiv
#define ParamLOG_UserFormula1Active                  ((bool)(knx.paramByte(LOG_UserFormula1Active) & LOG_UserFormula1ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula2                        (knx.paramData(LOG_UserFormula2))
// Benutzerformel 2 aktiv
#define ParamLOG_UserFormula2Active                  ((bool)(knx.paramByte(LOG_UserFormula2Active) & LOG_UserFormula2ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula3                        (knx.paramData(LOG_UserFormula3))
// Benutzerformel 3 aktiv
#define ParamLOG_UserFormula3Active                  ((bool)(knx.paramByte(LOG_UserFormula3Active) & LOG_UserFormula3ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula4                        (knx.paramData(LOG_UserFormula4))
// Benutzerformel 4 aktiv
#define ParamLOG_UserFormula4Active                  ((bool)(knx.paramByte(LOG_UserFormula4Active) & LOG_UserFormula4ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula5                        (knx.paramData(LOG_UserFormula5))
// Benutzerformel 5 aktiv
#define ParamLOG_UserFormula5Active                  ((bool)(knx.paramByte(LOG_UserFormula5Active) & LOG_UserFormula5ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula6                        (knx.paramData(LOG_UserFormula6))
// Benutzerformel 6 aktiv
#define ParamLOG_UserFormula6Active                  ((bool)(knx.paramByte(LOG_UserFormula6Active) & LOG_UserFormula6ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula7                        (knx.paramData(LOG_UserFormula7))
// Benutzerformel 7 aktiv
#define ParamLOG_UserFormula7Active                  ((bool)(knx.paramByte(LOG_UserFormula7Active) & LOG_UserFormula7ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula8                        (knx.paramData(LOG_UserFormula8))
// Benutzerformel 8 aktiv
#define ParamLOG_UserFormula8Active                  ((bool)(knx.paramByte(LOG_UserFormula8Active) & LOG_UserFormula8ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula9                        (knx.paramData(LOG_UserFormula9))
// Benutzerformel 9 aktiv
#define ParamLOG_UserFormula9Active                  ((bool)(knx.paramByte(LOG_UserFormula9Active) & LOG_UserFormula9ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula10                       (knx.paramData(LOG_UserFormula10))
// Benutzerformel 10 aktiv
#define ParamLOG_UserFormula10Active                 ((bool)(knx.paramByte(LOG_UserFormula10Active) & LOG_UserFormula10ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula11                       (knx.paramData(LOG_UserFormula11))
// Benutzerformel 11 aktiv
#define ParamLOG_UserFormula11Active                 ((bool)(knx.paramByte(LOG_UserFormula11Active) & LOG_UserFormula11ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula12                       (knx.paramData(LOG_UserFormula12))
// Benutzerformel 12 aktiv
#define ParamLOG_UserFormula12Active                 ((bool)(knx.paramByte(LOG_UserFormula12Active) & LOG_UserFormula12ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula13                       (knx.paramData(LOG_UserFormula13))
// Benutzerformel 13 aktiv
#define ParamLOG_UserFormula13Active                 ((bool)(knx.paramByte(LOG_UserFormula13Active) & LOG_UserFormula13ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula14                       (knx.paramData(LOG_UserFormula14))
// Benutzerformel 14 aktiv
#define ParamLOG_UserFormula14Active                 ((bool)(knx.paramByte(LOG_UserFormula14Active) & LOG_UserFormula14ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula15                       (knx.paramData(LOG_UserFormula15))
// Benutzerformel 15 aktiv
#define ParamLOG_UserFormula15Active                 ((bool)(knx.paramByte(LOG_UserFormula15Active) & LOG_UserFormula15ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula16                       (knx.paramData(LOG_UserFormula16))
// Benutzerformel 16 aktiv
#define ParamLOG_UserFormula16Active                 ((bool)(knx.paramByte(LOG_UserFormula16Active) & LOG_UserFormula16ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula17                       (knx.paramData(LOG_UserFormula17))
// Benutzerformel 17 aktiv
#define ParamLOG_UserFormula17Active                 ((bool)(knx.paramByte(LOG_UserFormula17Active) & LOG_UserFormula17ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula18                       (knx.paramData(LOG_UserFormula18))
// Benutzerformel 18 aktiv
#define ParamLOG_UserFormula18Active                 ((bool)(knx.paramByte(LOG_UserFormula18Active) & LOG_UserFormula18ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula19                       (knx.paramData(LOG_UserFormula19))
// Benutzerformel 19 aktiv
#define ParamLOG_UserFormula19Active                 ((bool)(knx.paramByte(LOG_UserFormula19Active) & LOG_UserFormula19ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula20                       (knx.paramData(LOG_UserFormula20))
// Benutzerformel 20 aktiv
#define ParamLOG_UserFormula20Active                 ((bool)(knx.paramByte(LOG_UserFormula20Active) & LOG_UserFormula20ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula21                       (knx.paramData(LOG_UserFormula21))
// Benutzerformel 21 aktiv
#define ParamLOG_UserFormula21Active                 ((bool)(knx.paramByte(LOG_UserFormula21Active) & LOG_UserFormula21ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula22                       (knx.paramData(LOG_UserFormula22))
// Benutzerformel 22 aktiv
#define ParamLOG_UserFormula22Active                 ((bool)(knx.paramByte(LOG_UserFormula22Active) & LOG_UserFormula22ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula23                       (knx.paramData(LOG_UserFormula23))
// Benutzerformel 23 aktiv
#define ParamLOG_UserFormula23Active                 ((bool)(knx.paramByte(LOG_UserFormula23Active) & LOG_UserFormula23ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula24                       (knx.paramData(LOG_UserFormula24))
// Benutzerformel 24 aktiv
#define ParamLOG_UserFormula24Active                 ((bool)(knx.paramByte(LOG_UserFormula24Active) & LOG_UserFormula24ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula25                       (knx.paramData(LOG_UserFormula25))
// Benutzerformel 25 aktiv
#define ParamLOG_UserFormula25Active                 ((bool)(knx.paramByte(LOG_UserFormula25Active) & LOG_UserFormula25ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula26                       (knx.paramData(LOG_UserFormula26))
// Benutzerformel 26 aktiv
#define ParamLOG_UserFormula26Active                 ((bool)(knx.paramByte(LOG_UserFormula26Active) & LOG_UserFormula26ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula27                       (knx.paramData(LOG_UserFormula27))
// Benutzerformel 27 aktiv
#define ParamLOG_UserFormula27Active                 ((bool)(knx.paramByte(LOG_UserFormula27Active) & LOG_UserFormula27ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula28                       (knx.paramData(LOG_UserFormula28))
// Benutzerformel 28 aktiv
#define ParamLOG_UserFormula28Active                 ((bool)(knx.paramByte(LOG_UserFormula28Active) & LOG_UserFormula28ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula29                       (knx.paramData(LOG_UserFormula29))
// Benutzerformel 29 aktiv
#define ParamLOG_UserFormula29Active                 ((bool)(knx.paramByte(LOG_UserFormula29Active) & LOG_UserFormula29ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula30                       (knx.paramData(LOG_UserFormula30))
// Benutzerformel 30 aktiv
#define ParamLOG_UserFormula30Active                 ((bool)(knx.paramByte(LOG_UserFormula30Active) & LOG_UserFormula30ActiveMask))

#define LOG_KoVacation 4
#define LOG_KoHoliday1 5
#define LOG_KoHoliday2 6
#define LOG_KoLedLock 8
#define LOG_KoBuzzerLock 9

// Urlaub
#define KoLOG_Vacation                            (knx.getGroupObject(LOG_KoVacation))
// Welcher Feiertag ist heute?
#define KoLOG_Holiday1                            (knx.getGroupObject(LOG_KoHoliday1))
// Welcher Feiertag ist morgen?
#define KoLOG_Holiday2                            (knx.getGroupObject(LOG_KoHoliday2))
// LED sperren
#define KoLOG_LedLock                             (knx.getGroupObject(LOG_KoLedLock))
// Buzzer sperren
#define KoLOG_BuzzerLock                          (knx.getGroupObject(LOG_KoBuzzerLock))

#define LOG_ChannelCount 99

// Parameter per channel
#define LOG_ParamBlockOffset 10250
#define LOG_ParamBlockSize 85
#define LOG_ParamCalcIndex(index) (index + LOG_ParamBlockOffset + _channelIndex * LOG_ParamBlockSize)

#define LOG_fChannelDelayBase                    0      // 2 Bits, Bit 7-6
#define     LOG_fChannelDelayBaseMask 0xC0
#define     LOG_fChannelDelayBaseShift 6
#define LOG_fChannelDelayTime                    0      // 14 Bits, Bit 13-0
#define     LOG_fChannelDelayTimeMask 0x3FFF
#define     LOG_fChannelDelayTimeShift 0
#define LOG_fLogic                               2      // 8 Bits, Bit 7-0
#define LOG_fCalculate                           3      // 2 Bits, Bit 1-0
#define     LOG_fCalculateMask 0x03
#define     LOG_fCalculateShift 0
#define LOG_fDisable                             3      // 1 Bit, Bit 2
#define     LOG_fDisableMask 0x04
#define     LOG_fDisableShift 2
#define LOG_fAlarm                               3      // 1 Bit, Bit 3
#define     LOG_fAlarmMask 0x08
#define     LOG_fAlarmShift 3
#define LOG_fTGate                               3      // 1 Bit, Bit 4
#define     LOG_fTGateMask 0x10
#define     LOG_fTGateShift 4
#define LOG_fOInternalOn                         3      // 1 Bit, Bit 5
#define     LOG_fOInternalOnMask 0x20
#define     LOG_fOInternalOnShift 5
#define LOG_fOInternalOff                        3      // 1 Bit, Bit 6
#define     LOG_fOInternalOffMask 0x40
#define     LOG_fOInternalOffShift 6
#define LOG_fTrigger                             4      // 8 Bits, Bit 7-0
#define LOG_fTriggerE1                           4      // 1 Bit, Bit 0
#define     LOG_fTriggerE1Mask 0x01
#define     LOG_fTriggerE1Shift 0
#define LOG_fTriggerE2                           4      // 1 Bit, Bit 1
#define     LOG_fTriggerE2Mask 0x02
#define     LOG_fTriggerE2Shift 1
#define LOG_fTriggerI1                           4      // 1 Bit, Bit 2
#define     LOG_fTriggerI1Mask 0x04
#define     LOG_fTriggerI1Shift 2
#define LOG_fTriggerI2                           4      // 1 Bit, Bit 3
#define     LOG_fTriggerI2Mask 0x08
#define     LOG_fTriggerI2Shift 3
#define LOG_fTriggerTime                         4      // 8 Bits, Bit 7-0
#define LOG_fTriggerGateClose                    5      // 2 Bits, Bit 7-6
#define     LOG_fTriggerGateCloseMask 0xC0
#define     LOG_fTriggerGateCloseShift 6
#define LOG_fTriggerGateOpen                     5      // 2 Bits, Bit 5-4
#define     LOG_fTriggerGateOpenMask 0x30
#define     LOG_fTriggerGateOpenShift 4
#define LOG_fE1ConvertInt                        6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertIntMask 0xF0
#define     LOG_fE1ConvertIntShift 4
#define LOG_fE1Convert                           6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertMask 0xF0
#define     LOG_fE1ConvertShift 4
#define LOG_fE1ConvertFloat                      6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertFloatMask 0xF0
#define     LOG_fE1ConvertFloatShift 4
#define LOG_fE1ConvertSpecial                    6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertSpecialMask 0xF0
#define     LOG_fE1ConvertSpecialShift 4
#define LOG_fE1ConvertBool                       6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertBoolMask 0xF0
#define     LOG_fE1ConvertBoolShift 4
#define LOG_fE1                                  6      // 2 Bits, Bit 1-0
#define     LOG_fE1Mask 0x03
#define     LOG_fE1Shift 0
#define LOG_fE1Dpt                               7      // 8 Bits, Bit 7-0
#define LOG_fE1RepeatBase                        8      // 2 Bits, Bit 7-6
#define     LOG_fE1RepeatBaseMask 0xC0
#define     LOG_fE1RepeatBaseShift 6
#define LOG_fE1RepeatTime                        8      // 14 Bits, Bit 13-0
#define     LOG_fE1RepeatTimeMask 0x3FFF
#define     LOG_fE1RepeatTimeShift 0
#define LOG_fE1OtherKO                          10      // uint16_t
#define LOG_fE1OtherKORel                       10      // int16_t
#define LOG_fE1Default                          12      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultMask 0x03
#define     LOG_fE1DefaultShift 0
#define LOG_fE1DefaultExt                       12      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultExtMask 0x03
#define     LOG_fE1DefaultExtShift 0
#define LOG_fE1DefaultEEPROM                    12      // 1 Bit, Bit 2
#define     LOG_fE1DefaultEEPROMMask 0x04
#define     LOG_fE1DefaultEEPROMShift 2
#define LOG_fE1DefaultRepeat                    12      // 1 Bit, Bit 3
#define     LOG_fE1DefaultRepeatMask 0x08
#define     LOG_fE1DefaultRepeatShift 3
#define LOG_fE1UseOtherKO                       12      // 2 Bits, Bit 5-4
#define     LOG_fE1UseOtherKOMask 0x30
#define     LOG_fE1UseOtherKOShift 4
#define LOG_fE1LowDelta                         13      // int32_t
#define LOG_fE1HighDelta                        17      // int32_t
#define LOG_fE1LowDeltaFloat                    13      // float
#define LOG_fE1HighDeltaFloat                   17      // float
#define LOG_fE1LowDeltaDouble                   13      // float
#define LOG_fE1HighDeltaDouble                  17      // float
#define LOG_fE1Low0Valid                        20      // 1 Bit, Bit 7
#define     LOG_fE1Low0ValidMask 0x80
#define     LOG_fE1Low0ValidShift 7
#define LOG_fE1Low1Valid                        20      // 1 Bit, Bit 6
#define     LOG_fE1Low1ValidMask 0x40
#define     LOG_fE1Low1ValidShift 6
#define LOG_fE1Low2Valid                        20      // 1 Bit, Bit 5
#define     LOG_fE1Low2ValidMask 0x20
#define     LOG_fE1Low2ValidShift 5
#define LOG_fE1Low3Valid                        20      // 1 Bit, Bit 4
#define     LOG_fE1Low3ValidMask 0x10
#define     LOG_fE1Low3ValidShift 4
#define LOG_fE1Low4Valid                        20      // 1 Bit, Bit 3
#define     LOG_fE1Low4ValidMask 0x08
#define     LOG_fE1Low4ValidShift 3
#define LOG_fE1Low5Valid                        20      // 1 Bit, Bit 2
#define     LOG_fE1Low5ValidMask 0x04
#define     LOG_fE1Low5ValidShift 2
#define LOG_fE1Low6Valid                        20      // 1 Bit, Bit 1
#define     LOG_fE1Low6ValidMask 0x02
#define     LOG_fE1Low6ValidShift 1
#define LOG_fE1Low0Dpt2                         13      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt2                         14      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt2                         15      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt2                         16      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt2Fix                       13      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt5                          13      // uint8_t
#define LOG_fE1HighDpt5                         17      // uint8_t
#define LOG_fE1Low0Dpt5In                       13      // uint8_t
#define LOG_fE1Low1Dpt5In                       14      // uint8_t
#define LOG_fE1Low2Dpt5In                       15      // uint8_t
#define LOG_fE1Low3Dpt5In                       16      // uint8_t
#define LOG_fE1Low4Dpt5In                       17      // uint8_t
#define LOG_fE1Low5Dpt5In                       18      // uint8_t
#define LOG_fE1Low6Dpt5In                       19      // uint8_t
#define LOG_fE1LowDpt5Fix                       13      // uint8_t
#define LOG_fE1LowDpt5001                       13      // uint8_t
#define LOG_fE1HighDpt5001                      17      // uint8_t
#define LOG_fE1Low0Dpt5xIn                      13      // uint8_t
#define LOG_fE1Low1Dpt5xIn                      14      // uint8_t
#define LOG_fE1Low2Dpt5xIn                      15      // uint8_t
#define LOG_fE1Low3Dpt5xIn                      16      // uint8_t
#define LOG_fE1Low4Dpt5xIn                      17      // uint8_t
#define LOG_fE1Low5Dpt5xIn                      18      // uint8_t
#define LOG_fE1Low6Dpt5xIn                      19      // uint8_t
#define LOG_fE1LowDpt5xFix                      13      // uint8_t
#define LOG_fE1LowDpt6                          13      // int8_t
#define LOG_fE1HighDpt6                         17      // int8_t
#define LOG_fE1Low0Dpt6In                       13      // int8_t
#define LOG_fE1Low1Dpt6In                       14      // int8_t
#define LOG_fE1Low2Dpt6In                       15      // int8_t
#define LOG_fE1Low3Dpt6In                       16      // int8_t
#define LOG_fE1Low4Dpt6In                       17      // int8_t
#define LOG_fE1Low5Dpt6In                       18      // int8_t
#define LOG_fE1Low6Dpt6In                       19      // int8_t
#define LOG_fE1LowDpt6Fix                       13      // int8_t
#define LOG_fE1LowDpt7                          13      // uint16_t
#define LOG_fE1HighDpt7                         17      // uint16_t
#define LOG_fE1Low0Dpt7In                       13      // uint16_t
#define LOG_fE1Low1Dpt7In                       15      // uint16_t
#define LOG_fE1Low2Dpt7In                       17      // uint16_t
#define LOG_fE1LowDpt7Fix                       13      // uint16_t
#define LOG_fE1LowDpt8                          13      // int16_t
#define LOG_fE1HighDpt8                         17      // int16_t
#define LOG_fE1Low0Dpt8In                       13      // int16_t
#define LOG_fE1Low1Dpt8In                       15      // int16_t
#define LOG_fE1Low2Dpt8In                       17      // int16_t
#define LOG_fE1LowDpt8Fix                       13      // int16_t
#define LOG_fE1LowDpt9                          13      // float
#define LOG_fE1HighDpt9                         17      // float
#define LOG_fE1LowDpt9Fix                       13      // float
#define LOG_fE1LowDpt12                         13      // uint32_t
#define LOG_fE1HighDpt12                        17      // uint32_t
#define LOG_fE1LowDpt12Fix                      13      // uint32_t
#define LOG_fE1LowDpt13                         13      // int32_t
#define LOG_fE1HighDpt13                        17      // int32_t
#define LOG_fE1LowDpt13Fix                      13      // int32_t
#define LOG_fE1LowDpt14                         13      // float
#define LOG_fE1HighDpt14                        17      // float
#define LOG_fE1LowDpt14Fix                      13      // float
#define LOG_fE1Low0Dpt17                        13      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt17                        14      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt17                        15      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt17                        16      // 8 Bits, Bit 7-0
#define LOG_fE1Low4Dpt17                        17      // 8 Bits, Bit 7-0
#define LOG_fE1Low5Dpt17                        18      // 8 Bits, Bit 7-0
#define LOG_fE1Low6Dpt17                        19      // 8 Bits, Bit 7-0
#define LOG_fE1Low7Dpt17                        20      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt17Fix                      13      // 8 Bits, Bit 7-0
#define LOG_fE1LowDptRGB                        13      // int32_t
#define LOG_fE1HighDptRGB                       17      // int32_t
#define LOG_fE1LowDptRGBFix                     13      // int32_t
#define LOG_fE2ConvertInt                       21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertIntMask 0xF0
#define     LOG_fE2ConvertIntShift 4
#define LOG_fE2Convert                          21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertMask 0xF0
#define     LOG_fE2ConvertShift 4
#define LOG_fE2ConvertFloat                     21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertFloatMask 0xF0
#define     LOG_fE2ConvertFloatShift 4
#define LOG_fE2ConvertSpecial                   21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertSpecialMask 0xF0
#define     LOG_fE2ConvertSpecialShift 4
#define LOG_fE2ConvertBool                      21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertBoolMask 0xF0
#define     LOG_fE2ConvertBoolShift 4
#define LOG_fE2                                 21      // 2 Bits, Bit 1-0
#define     LOG_fE2Mask 0x03
#define     LOG_fE2Shift 0
#define LOG_fE2Dpt                              22      // 8 Bits, Bit 7-0
#define LOG_fE2RepeatBase                       23      // 2 Bits, Bit 7-6
#define     LOG_fE2RepeatBaseMask 0xC0
#define     LOG_fE2RepeatBaseShift 6
#define LOG_fE2RepeatTime                       23      // 14 Bits, Bit 13-0
#define     LOG_fE2RepeatTimeMask 0x3FFF
#define     LOG_fE2RepeatTimeShift 0
#define LOG_fE2OtherKO                          25      // uint16_t
#define LOG_fE2OtherKORel                       25      // int16_t
#define LOG_fE2Default                          27      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultMask 0x03
#define     LOG_fE2DefaultShift 0
#define LOG_fE2DefaultExt                       27      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultExtMask 0x03
#define     LOG_fE2DefaultExtShift 0
#define LOG_fE2DefaultEEPROM                    27      // 1 Bit, Bit 2
#define     LOG_fE2DefaultEEPROMMask 0x04
#define     LOG_fE2DefaultEEPROMShift 2
#define LOG_fE2DefaultRepeat                    27      // 1 Bit, Bit 3
#define     LOG_fE2DefaultRepeatMask 0x08
#define     LOG_fE2DefaultRepeatShift 3
#define LOG_fE2UseOtherKO                       27      // 2 Bits, Bit 5-4
#define     LOG_fE2UseOtherKOMask 0x30
#define     LOG_fE2UseOtherKOShift 4
#define LOG_fE2LowDelta                         28      // int32_t
#define LOG_fE2HighDelta                        32      // int32_t
#define LOG_fE2LowDeltaFloat                    28      // float
#define LOG_fE2HighDeltaFloat                   32      // float
#define LOG_fE2LowDeltaDouble                   28      // float
#define LOG_fE2HighDeltaDouble                  32      // float
#define LOG_fE2Low0Valid                        35      // 1 Bit, Bit 7
#define     LOG_fE2Low0ValidMask 0x80
#define     LOG_fE2Low0ValidShift 7
#define LOG_fE2Low1Valid                        35      // 1 Bit, Bit 6
#define     LOG_fE2Low1ValidMask 0x40
#define     LOG_fE2Low1ValidShift 6
#define LOG_fE2Low2Valid                        35      // 1 Bit, Bit 5
#define     LOG_fE2Low2ValidMask 0x20
#define     LOG_fE2Low2ValidShift 5
#define LOG_fE2Low3Valid                        35      // 1 Bit, Bit 4
#define     LOG_fE2Low3ValidMask 0x10
#define     LOG_fE2Low3ValidShift 4
#define LOG_fE2Low4Valid                        35      // 1 Bit, Bit 3
#define     LOG_fE2Low4ValidMask 0x08
#define     LOG_fE2Low4ValidShift 3
#define LOG_fE2Low5Valid                        35      // 1 Bit, Bit 2
#define     LOG_fE2Low5ValidMask 0x04
#define     LOG_fE2Low5ValidShift 2
#define LOG_fE2Low6Valid                        35      // 1 Bit, Bit 1
#define     LOG_fE2Low6ValidMask 0x02
#define     LOG_fE2Low6ValidShift 1
#define LOG_fE2Low0Dpt2                         28      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt2                         29      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt2                         30      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt2                         31      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt2Fix                       28      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt5                          28      // uint8_t
#define LOG_fE2HighDpt5                         32      // uint8_t
#define LOG_fE2Low0Dpt5In                       28      // uint8_t
#define LOG_fE2Low1Dpt5In                       29      // uint8_t
#define LOG_fE2Low2Dpt5In                       30      // uint8_t
#define LOG_fE2Low3Dpt5In                       31      // uint8_t
#define LOG_fE2Low4Dpt5In                       32      // uint8_t
#define LOG_fE2Low5Dpt5In                       33      // uint8_t
#define LOG_fE2Low6Dpt5In                       34      // uint8_t
#define LOG_fE2LowDpt5Fix                       28      // uint8_t
#define LOG_fE2LowDpt5001                       28      // uint8_t
#define LOG_fE2HighDpt5001                      32      // uint8_t
#define LOG_fE2Low0Dpt5xIn                      28      // uint8_t
#define LOG_fE2Low1Dpt5xIn                      29      // uint8_t
#define LOG_fE2Low2Dpt5xIn                      30      // uint8_t
#define LOG_fE2Low3Dpt5xIn                      31      // uint8_t
#define LOG_fE2Low4Dpt5xIn                      32      // uint8_t
#define LOG_fE2Low5Dpt5xIn                      33      // uint8_t
#define LOG_fE2Low6Dpt5xIn                      34      // uint8_t
#define LOG_fE2LowDpt5xFix                      28      // uint8_t
#define LOG_fE2LowDpt6                          28      // int8_t
#define LOG_fE2HighDpt6                         32      // int8_t
#define LOG_fE2Low0Dpt6In                       28      // int8_t
#define LOG_fE2Low1Dpt6In                       29      // int8_t
#define LOG_fE2Low2Dpt6In                       30      // int8_t
#define LOG_fE2Low3Dpt6In                       31      // int8_t
#define LOG_fE2Low4Dpt6In                       32      // int8_t
#define LOG_fE2Low5Dpt6In                       33      // int8_t
#define LOG_fE2Low6Dpt6In                       34      // int8_t
#define LOG_fE2LowDpt6Fix                       28      // int8_t
#define LOG_fE2LowDpt7                          28      // uint16_t
#define LOG_fE2HighDpt7                         32      // uint16_t
#define LOG_fE2Low0Dpt7In                       28      // uint16_t
#define LOG_fE2Low1Dpt7In                       30      // uint16_t
#define LOG_fE2Low2Dpt7In                       32      // uint16_t
#define LOG_fE2LowDpt7Fix                       28      // uint16_t
#define LOG_fE2LowDpt8                          28      // int16_t
#define LOG_fE2HighDpt8                         32      // int16_t
#define LOG_fE2Low0Dpt8In                       28      // int16_t
#define LOG_fE2Low1Dpt8In                       30      // int16_t
#define LOG_fE2Low2Dpt8In                       32      // int16_t
#define LOG_fE2LowDpt8Fix                       28      // int16_t
#define LOG_fE2LowDpt9                          28      // float
#define LOG_fE2HighDpt9                         32      // float
#define LOG_fE2LowDpt9Fix                       28      // float
#define LOG_fE2LowDpt12                         28      // uint32_t
#define LOG_fE2HighDpt12                        32      // uint32_t
#define LOG_fE2LowDpt12Fix                      28      // uint32_t
#define LOG_fE2LowDpt13                         28      // int32_t
#define LOG_fE2HighDpt13                        32      // int32_t
#define LOG_fE2LowDpt13Fix                      28      // int32_t
#define LOG_fE2LowDpt14                         28      // float
#define LOG_fE2HighDpt14                        32      // float
#define LOG_fE2LowDpt14Fix                      28      // float
#define LOG_fE2Low0Dpt17                        28      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt17                        29      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt17                        30      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt17                        31      // 8 Bits, Bit 7-0
#define LOG_fE2Low4Dpt17                        32      // 8 Bits, Bit 7-0
#define LOG_fE2Low5Dpt17                        33      // 8 Bits, Bit 7-0
#define LOG_fE2Low6Dpt17                        34      // 8 Bits, Bit 7-0
#define LOG_fE2Low7Dpt17                        35      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt17Fix                      28      // 8 Bits, Bit 7-0
#define LOG_fE2LowDptRGB                        28      // int32_t
#define LOG_fE2HighDptRGB                       32      // int32_t
#define LOG_fE2LowDptRGBFix                     28      // int32_t
#define LOG_fTd1DuskDawn                         6      // 4 Bits, Bit 7-4
#define     LOG_fTd1DuskDawnMask 0xF0
#define     LOG_fTd1DuskDawnShift 4
#define LOG_fTd2DuskDawn                         6      // 4 Bits, Bit 3-0
#define     LOG_fTd2DuskDawnMask 0x0F
#define     LOG_fTd2DuskDawnShift 0
#define LOG_fTd3DuskDawn                         7      // 4 Bits, Bit 7-4
#define     LOG_fTd3DuskDawnMask 0xF0
#define     LOG_fTd3DuskDawnShift 4
#define LOG_fTd4DuskDawn                         7      // 4 Bits, Bit 3-0
#define     LOG_fTd4DuskDawnMask 0x0F
#define     LOG_fTd4DuskDawnShift 0
#define LOG_fTd5DuskDawn                         8      // 4 Bits, Bit 7-4
#define     LOG_fTd5DuskDawnMask 0xF0
#define     LOG_fTd5DuskDawnShift 4
#define LOG_fTd6DuskDawn                         8      // 4 Bits, Bit 3-0
#define     LOG_fTd6DuskDawnMask 0x0F
#define     LOG_fTd6DuskDawnShift 0
#define LOG_fTd7DuskDawn                         9      // 4 Bits, Bit 7-4
#define     LOG_fTd7DuskDawnMask 0xF0
#define     LOG_fTd7DuskDawnShift 4
#define LOG_fTd8DuskDawn                         9      // 4 Bits, Bit 3-0
#define     LOG_fTd8DuskDawnMask 0x0F
#define     LOG_fTd8DuskDawnShift 0
#define LOG_fTYearDay                           10      // 2 Bits, Bit 7-6
#define     LOG_fTYearDayMask 0xC0
#define     LOG_fTYearDayShift 6
#define LOG_fTHoliday                           10      // 2 Bits, Bit 5-4
#define     LOG_fTHolidayMask 0x30
#define     LOG_fTHolidayShift 4
#define LOG_fTRestoreState                      10      // 2 Bits, Bit 3-2
#define     LOG_fTRestoreStateMask 0x0C
#define     LOG_fTRestoreStateShift 2
#define LOG_fTVacation                          10      // 2 Bits, Bit 1-0
#define     LOG_fTVacationMask 0x03
#define     LOG_fTVacationShift 0
#define LOG_fTd1ValueNum                        11      // uint8_t
#define LOG_fTd2ValueNum                        12      // uint8_t
#define LOG_fTd3ValueNum                        13      // uint8_t
#define LOG_fTd4ValueNum                        14      // uint8_t
#define LOG_fTd5ValueNum                        15      // uint8_t
#define LOG_fTd6ValueNum                        16      // uint8_t
#define LOG_fTd7ValueNum                        17      // uint8_t
#define LOG_fTd8ValueNum                        18      // uint8_t
#define LOG_fTd1Value                           20      // 1 Bit, Bit 7
#define     LOG_fTd1ValueMask 0x80
#define     LOG_fTd1ValueShift 7
#define LOG_fTd1Degree                          20      // 6 Bits, Bit 6-1
#define     LOG_fTd1DegreeMask 0x7E
#define     LOG_fTd1DegreeShift 1
#define LOG_fTd1HourAbs                         20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourAbsMask 0x3E
#define     LOG_fTd1HourAbsShift 1
#define LOG_fTd1HourRel                         20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelMask 0x3E
#define     LOG_fTd1HourRelShift 1
#define LOG_fTd1HourRelShort                    20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelShortMask 0x3E
#define     LOG_fTd1HourRelShortShift 1
#define LOG_fTd1MinuteAbs                       20      // 6 Bits, Bit 0--5
#define LOG_fTd1MinuteRel                       20      // 6 Bits, Bit 0--5
#define LOG_fTd1Weekday                         21      // 3 Bits, Bit 2-0
#define     LOG_fTd1WeekdayMask 0x07
#define     LOG_fTd1WeekdayShift 0
#define LOG_fTd2Value                           22      // 1 Bit, Bit 7
#define     LOG_fTd2ValueMask 0x80
#define     LOG_fTd2ValueShift 7
#define LOG_fTd2Degree                          22      // 6 Bits, Bit 6-1
#define     LOG_fTd2DegreeMask 0x7E
#define     LOG_fTd2DegreeShift 1
#define LOG_fTd2HourAbs                         22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourAbsMask 0x3E
#define     LOG_fTd2HourAbsShift 1
#define LOG_fTd2HourRel                         22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelMask 0x3E
#define     LOG_fTd2HourRelShift 1
#define LOG_fTd2HourRelShort                    22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelShortMask 0x3E
#define     LOG_fTd2HourRelShortShift 1
#define LOG_fTd2MinuteAbs                       22      // 6 Bits, Bit 0--5
#define LOG_fTd2MinuteRel                       22      // 6 Bits, Bit 0--5
#define LOG_fTd2Weekday                         23      // 3 Bits, Bit 2-0
#define     LOG_fTd2WeekdayMask 0x07
#define     LOG_fTd2WeekdayShift 0
#define LOG_fTd3Value                           24      // 1 Bit, Bit 7
#define     LOG_fTd3ValueMask 0x80
#define     LOG_fTd3ValueShift 7
#define LOG_fTd3Degree                          24      // 6 Bits, Bit 6-1
#define     LOG_fTd3DegreeMask 0x7E
#define     LOG_fTd3DegreeShift 1
#define LOG_fTd3HourAbs                         24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourAbsMask 0x3E
#define     LOG_fTd3HourAbsShift 1
#define LOG_fTd3HourRel                         24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelMask 0x3E
#define     LOG_fTd3HourRelShift 1
#define LOG_fTd3HourRelShort                    24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelShortMask 0x3E
#define     LOG_fTd3HourRelShortShift 1
#define LOG_fTd3MinuteAbs                       24      // 6 Bits, Bit 0--5
#define LOG_fTd3MinuteRel                       24      // 6 Bits, Bit 0--5
#define LOG_fTd3Weekday                         25      // 3 Bits, Bit 2-0
#define     LOG_fTd3WeekdayMask 0x07
#define     LOG_fTd3WeekdayShift 0
#define LOG_fTd4Value                           26      // 1 Bit, Bit 7
#define     LOG_fTd4ValueMask 0x80
#define     LOG_fTd4ValueShift 7
#define LOG_fTd4Degree                          26      // 6 Bits, Bit 6-1
#define     LOG_fTd4DegreeMask 0x7E
#define     LOG_fTd4DegreeShift 1
#define LOG_fTd4HourAbs                         26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourAbsMask 0x3E
#define     LOG_fTd4HourAbsShift 1
#define LOG_fTd4HourRel                         26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelMask 0x3E
#define     LOG_fTd4HourRelShift 1
#define LOG_fTd4HourRelShort                    26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelShortMask 0x3E
#define     LOG_fTd4HourRelShortShift 1
#define LOG_fTd4MinuteAbs                       26      // 6 Bits, Bit 0--5
#define LOG_fTd4MinuteRel                       26      // 6 Bits, Bit 0--5
#define LOG_fTd4Weekday                         27      // 3 Bits, Bit 2-0
#define     LOG_fTd4WeekdayMask 0x07
#define     LOG_fTd4WeekdayShift 0
#define LOG_fTd5Value                           28      // 1 Bit, Bit 7
#define     LOG_fTd5ValueMask 0x80
#define     LOG_fTd5ValueShift 7
#define LOG_fTd5Degree                          28      // 6 Bits, Bit 6-1
#define     LOG_fTd5DegreeMask 0x7E
#define     LOG_fTd5DegreeShift 1
#define LOG_fTd5HourAbs                         28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourAbsMask 0x3E
#define     LOG_fTd5HourAbsShift 1
#define LOG_fTd5HourRel                         28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelMask 0x3E
#define     LOG_fTd5HourRelShift 1
#define LOG_fTd5HourRelShort                    28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelShortMask 0x3E
#define     LOG_fTd5HourRelShortShift 1
#define LOG_fTd5MinuteAbs                       28      // 6 Bits, Bit 0--5
#define LOG_fTd5MinuteRel                       28      // 6 Bits, Bit 0--5
#define LOG_fTd5Weekday                         29      // 3 Bits, Bit 2-0
#define     LOG_fTd5WeekdayMask 0x07
#define     LOG_fTd5WeekdayShift 0
#define LOG_fTd6Value                           30      // 1 Bit, Bit 7
#define     LOG_fTd6ValueMask 0x80
#define     LOG_fTd6ValueShift 7
#define LOG_fTd6Degree                          30      // 6 Bits, Bit 6-1
#define     LOG_fTd6DegreeMask 0x7E
#define     LOG_fTd6DegreeShift 1
#define LOG_fTd6HourAbs                         30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourAbsMask 0x3E
#define     LOG_fTd6HourAbsShift 1
#define LOG_fTd6HourRel                         30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelMask 0x3E
#define     LOG_fTd6HourRelShift 1
#define LOG_fTd6HourRelShort                    30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelShortMask 0x3E
#define     LOG_fTd6HourRelShortShift 1
#define LOG_fTd6MinuteAbs                       30      // 6 Bits, Bit 0--5
#define LOG_fTd6MinuteRel                       30      // 6 Bits, Bit 0--5
#define LOG_fTd6Weekday                         31      // 3 Bits, Bit 2-0
#define     LOG_fTd6WeekdayMask 0x07
#define     LOG_fTd6WeekdayShift 0
#define LOG_fTd7Value                           32      // 1 Bit, Bit 7
#define     LOG_fTd7ValueMask 0x80
#define     LOG_fTd7ValueShift 7
#define LOG_fTd7Degree                          32      // 6 Bits, Bit 6-1
#define     LOG_fTd7DegreeMask 0x7E
#define     LOG_fTd7DegreeShift 1
#define LOG_fTd7HourAbs                         32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourAbsMask 0x3E
#define     LOG_fTd7HourAbsShift 1
#define LOG_fTd7HourRel                         32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelMask 0x3E
#define     LOG_fTd7HourRelShift 1
#define LOG_fTd7HourRelShort                    32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelShortMask 0x3E
#define     LOG_fTd7HourRelShortShift 1
#define LOG_fTd7MinuteAbs                       32      // 6 Bits, Bit 0--5
#define LOG_fTd7MinuteRel                       32      // 6 Bits, Bit 0--5
#define LOG_fTd7Weekday                         33      // 3 Bits, Bit 2-0
#define     LOG_fTd7WeekdayMask 0x07
#define     LOG_fTd7WeekdayShift 0
#define LOG_fTd8Value                           34      // 1 Bit, Bit 7
#define     LOG_fTd8ValueMask 0x80
#define     LOG_fTd8ValueShift 7
#define LOG_fTd8Degree                          34      // 6 Bits, Bit 6-1
#define     LOG_fTd8DegreeMask 0x7E
#define     LOG_fTd8DegreeShift 1
#define LOG_fTd8HourAbs                         34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourAbsMask 0x3E
#define     LOG_fTd8HourAbsShift 1
#define LOG_fTd8HourRel                         34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelMask 0x3E
#define     LOG_fTd8HourRelShift 1
#define LOG_fTd8HourRelShort                    34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelShortMask 0x3E
#define     LOG_fTd8HourRelShortShift 1
#define LOG_fTd8MinuteAbs                       34      // 6 Bits, Bit 0--5
#define LOG_fTd8MinuteRel                       34      // 6 Bits, Bit 0--5
#define LOG_fTd8Weekday                         35      // 3 Bits, Bit 2-0
#define     LOG_fTd8WeekdayMask 0x07
#define     LOG_fTd8WeekdayShift 0
#define LOG_fTy1Weekday1                        28      // 1 Bit, Bit 7
#define     LOG_fTy1Weekday1Mask 0x80
#define     LOG_fTy1Weekday1Shift 7
#define LOG_fTy1Weekday2                        28      // 1 Bit, Bit 6
#define     LOG_fTy1Weekday2Mask 0x40
#define     LOG_fTy1Weekday2Shift 6
#define LOG_fTy1Weekday3                        28      // 1 Bit, Bit 5
#define     LOG_fTy1Weekday3Mask 0x20
#define     LOG_fTy1Weekday3Shift 5
#define LOG_fTy1Weekday4                        28      // 1 Bit, Bit 4
#define     LOG_fTy1Weekday4Mask 0x10
#define     LOG_fTy1Weekday4Shift 4
#define LOG_fTy1Weekday5                        28      // 1 Bit, Bit 3
#define     LOG_fTy1Weekday5Mask 0x08
#define     LOG_fTy1Weekday5Shift 3
#define LOG_fTy1Weekday6                        28      // 1 Bit, Bit 2
#define     LOG_fTy1Weekday6Mask 0x04
#define     LOG_fTy1Weekday6Shift 2
#define LOG_fTy1Weekday7                        28      // 1 Bit, Bit 1
#define     LOG_fTy1Weekday7Mask 0x02
#define     LOG_fTy1Weekday7Shift 1
#define LOG_fTy1Day                             28      // 7 Bits, Bit 7-1
#define     LOG_fTy1DayMask 0xFE
#define     LOG_fTy1DayShift 1
#define LOG_fTy1IsWeekday                       28      // 1 Bit, Bit 0
#define     LOG_fTy1IsWeekdayMask 0x01
#define     LOG_fTy1IsWeekdayShift 0
#define LOG_fTy1Month                           29      // 4 Bits, Bit 7-4
#define     LOG_fTy1MonthMask 0xF0
#define     LOG_fTy1MonthShift 4
#define LOG_fTy2Weekday1                        30      // 1 Bit, Bit 7
#define     LOG_fTy2Weekday1Mask 0x80
#define     LOG_fTy2Weekday1Shift 7
#define LOG_fTy2Weekday2                        30      // 1 Bit, Bit 6
#define     LOG_fTy2Weekday2Mask 0x40
#define     LOG_fTy2Weekday2Shift 6
#define LOG_fTy2Weekday3                        30      // 1 Bit, Bit 5
#define     LOG_fTy2Weekday3Mask 0x20
#define     LOG_fTy2Weekday3Shift 5
#define LOG_fTy2Weekday4                        30      // 1 Bit, Bit 4
#define     LOG_fTy2Weekday4Mask 0x10
#define     LOG_fTy2Weekday4Shift 4
#define LOG_fTy2Weekday5                        30      // 1 Bit, Bit 3
#define     LOG_fTy2Weekday5Mask 0x08
#define     LOG_fTy2Weekday5Shift 3
#define LOG_fTy2Weekday6                        30      // 1 Bit, Bit 2
#define     LOG_fTy2Weekday6Mask 0x04
#define     LOG_fTy2Weekday6Shift 2
#define LOG_fTy2Weekday7                        30      // 1 Bit, Bit 1
#define     LOG_fTy2Weekday7Mask 0x02
#define     LOG_fTy2Weekday7Shift 1
#define LOG_fTy2Day                             30      // 7 Bits, Bit 7-1
#define     LOG_fTy2DayMask 0xFE
#define     LOG_fTy2DayShift 1
#define LOG_fTy2IsWeekday                       30      // 1 Bit, Bit 0
#define     LOG_fTy2IsWeekdayMask 0x01
#define     LOG_fTy2IsWeekdayShift 0
#define LOG_fTy2Month                           31      // 4 Bits, Bit 7-4
#define     LOG_fTy2MonthMask 0xF0
#define     LOG_fTy2MonthShift 4
#define LOG_fTy3Weekday1                        32      // 1 Bit, Bit 7
#define     LOG_fTy3Weekday1Mask 0x80
#define     LOG_fTy3Weekday1Shift 7
#define LOG_fTy3Weekday2                        32      // 1 Bit, Bit 6
#define     LOG_fTy3Weekday2Mask 0x40
#define     LOG_fTy3Weekday2Shift 6
#define LOG_fTy3Weekday3                        32      // 1 Bit, Bit 5
#define     LOG_fTy3Weekday3Mask 0x20
#define     LOG_fTy3Weekday3Shift 5
#define LOG_fTy3Weekday4                        32      // 1 Bit, Bit 4
#define     LOG_fTy3Weekday4Mask 0x10
#define     LOG_fTy3Weekday4Shift 4
#define LOG_fTy3Weekday5                        32      // 1 Bit, Bit 3
#define     LOG_fTy3Weekday5Mask 0x08
#define     LOG_fTy3Weekday5Shift 3
#define LOG_fTy3Weekday6                        32      // 1 Bit, Bit 2
#define     LOG_fTy3Weekday6Mask 0x04
#define     LOG_fTy3Weekday6Shift 2
#define LOG_fTy3Weekday7                        32      // 1 Bit, Bit 1
#define     LOG_fTy3Weekday7Mask 0x02
#define     LOG_fTy3Weekday7Shift 1
#define LOG_fTy3Day                             32      // 7 Bits, Bit 7-1
#define     LOG_fTy3DayMask 0xFE
#define     LOG_fTy3DayShift 1
#define LOG_fTy3IsWeekday                       32      // 1 Bit, Bit 0
#define     LOG_fTy3IsWeekdayMask 0x01
#define     LOG_fTy3IsWeekdayShift 0
#define LOG_fTy3Month                           33      // 4 Bits, Bit 7-4
#define     LOG_fTy3MonthMask 0xF0
#define     LOG_fTy3MonthShift 4
#define LOG_fTy4Weekday1                        34      // 1 Bit, Bit 7
#define     LOG_fTy4Weekday1Mask 0x80
#define     LOG_fTy4Weekday1Shift 7
#define LOG_fTy4Weekday2                        34      // 1 Bit, Bit 6
#define     LOG_fTy4Weekday2Mask 0x40
#define     LOG_fTy4Weekday2Shift 6
#define LOG_fTy4Weekday3                        34      // 1 Bit, Bit 5
#define     LOG_fTy4Weekday3Mask 0x20
#define     LOG_fTy4Weekday3Shift 5
#define LOG_fTy4Weekday4                        34      // 1 Bit, Bit 4
#define     LOG_fTy4Weekday4Mask 0x10
#define     LOG_fTy4Weekday4Shift 4
#define LOG_fTy4Weekday5                        34      // 1 Bit, Bit 3
#define     LOG_fTy4Weekday5Mask 0x08
#define     LOG_fTy4Weekday5Shift 3
#define LOG_fTy4Weekday6                        34      // 1 Bit, Bit 2
#define     LOG_fTy4Weekday6Mask 0x04
#define     LOG_fTy4Weekday6Shift 2
#define LOG_fTy4Weekday7                        34      // 1 Bit, Bit 1
#define     LOG_fTy4Weekday7Mask 0x02
#define     LOG_fTy4Weekday7Shift 1
#define LOG_fTy4Day                             34      // 7 Bits, Bit 7-1
#define     LOG_fTy4DayMask 0xFE
#define     LOG_fTy4DayShift 1
#define LOG_fTy4IsWeekday                       34      // 1 Bit, Bit 0
#define     LOG_fTy4IsWeekdayMask 0x01
#define     LOG_fTy4IsWeekdayShift 0
#define LOG_fTy4Month                           35      // 4 Bits, Bit 7-4
#define     LOG_fTy4MonthMask 0xF0
#define     LOG_fTy4MonthShift 4
#define LOG_fI1                                 36      // 2 Bits, Bit 7-6
#define     LOG_fI1Mask 0xC0
#define     LOG_fI1Shift 6
#define LOG_fI2                                 36      // 2 Bits, Bit 5-4
#define     LOG_fI2Mask 0x30
#define     LOG_fI2Shift 4
#define LOG_fI1Kind                             36      // 2 Bits, Bit 3-2
#define     LOG_fI1KindMask 0x0C
#define     LOG_fI1KindShift 2
#define LOG_fI2Kind                             36      // 2 Bits, Bit 1-0
#define     LOG_fI2KindMask 0x03
#define     LOG_fI2KindShift 0
#define LOG_fI1Function                         37      // uint8_t
#define LOG_fI2Function                         38      // uint8_t
#define LOG_fI1FunctionRel                      37      // int8_t
#define LOG_fI2FunctionRel                      38      // int8_t
#define LOG_fI1AsTrigger                        39      // 1 Bit, Bit 7
#define     LOG_fI1AsTriggerMask 0x80
#define     LOG_fI1AsTriggerShift 7
#define LOG_fI2AsTrigger                        39      // 1 Bit, Bit 6
#define     LOG_fI2AsTriggerMask 0x40
#define     LOG_fI2AsTriggerShift 6
#define LOG_fOStairtimeBase                     40      // 2 Bits, Bit 7-6
#define     LOG_fOStairtimeBaseMask 0xC0
#define     LOG_fOStairtimeBaseShift 6
#define LOG_fOStairtimeTime                     40      // 14 Bits, Bit 13-0
#define     LOG_fOStairtimeTimeMask 0x3FFF
#define     LOG_fOStairtimeTimeShift 0
#define LOG_fOBlinkBase                         42      // 2 Bits, Bit 7-6
#define     LOG_fOBlinkBaseMask 0xC0
#define     LOG_fOBlinkBaseShift 6
#define LOG_fOBlinkTime                         42      // 14 Bits, Bit 13-0
#define     LOG_fOBlinkTimeMask 0x3FFF
#define     LOG_fOBlinkTimeShift 0
#define LOG_fODelayOnBase                       44      // 2 Bits, Bit 7-6
#define     LOG_fODelayOnBaseMask 0xC0
#define     LOG_fODelayOnBaseShift 6
#define LOG_fODelayOnTime                       44      // 14 Bits, Bit 13-0
#define     LOG_fODelayOnTimeMask 0x3FFF
#define     LOG_fODelayOnTimeShift 0
#define LOG_fODelayOffBase                      46      // 2 Bits, Bit 7-6
#define     LOG_fODelayOffBaseMask 0xC0
#define     LOG_fODelayOffBaseShift 6
#define LOG_fODelayOffTime                      46      // 14 Bits, Bit 13-0
#define     LOG_fODelayOffTimeMask 0x3FFF
#define     LOG_fODelayOffTimeShift 0
#define LOG_fORepeatOnBase                      48      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOnBaseMask 0xC0
#define     LOG_fORepeatOnBaseShift 6
#define LOG_fORepeatOnTime                      48      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOnTimeMask 0x3FFF
#define     LOG_fORepeatOnTimeShift 0
#define LOG_fORepeatOffBase                     50      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOffBaseMask 0xC0
#define     LOG_fORepeatOffBaseShift 6
#define LOG_fORepeatOffTime                     50      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOffTimeMask 0x3FFF
#define     LOG_fORepeatOffTimeShift 0
#define LOG_fODelay                             52      // 1 Bit, Bit 7
#define     LOG_fODelayMask 0x80
#define     LOG_fODelayShift 7
#define LOG_fODelayOnRepeat                     52      // 2 Bits, Bit 6-5
#define     LOG_fODelayOnRepeatMask 0x60
#define     LOG_fODelayOnRepeatShift 5
#define LOG_fODelayOnReset                      52      // 1 Bit, Bit 4
#define     LOG_fODelayOnResetMask 0x10
#define     LOG_fODelayOnResetShift 4
#define LOG_fODelayOffRepeat                    52      // 2 Bits, Bit 3-2
#define     LOG_fODelayOffRepeatMask 0x0C
#define     LOG_fODelayOffRepeatShift 2
#define LOG_fODelayOffReset                     52      // 1 Bit, Bit 1
#define     LOG_fODelayOffResetMask 0x02
#define     LOG_fODelayOffResetShift 1
#define LOG_fOStair                             52      // 1 Bit, Bit 0
#define     LOG_fOStairMask 0x01
#define     LOG_fOStairShift 0
#define LOG_fORetrigger                         53      // 1 Bit, Bit 7
#define     LOG_fORetriggerMask 0x80
#define     LOG_fORetriggerShift 7
#define LOG_fOStairOff                          53      // 1 Bit, Bit 6
#define     LOG_fOStairOffMask 0x40
#define     LOG_fOStairOffShift 6
#define LOG_fORepeat                            53      // 1 Bit, Bit 5
#define     LOG_fORepeatMask 0x20
#define     LOG_fORepeatShift 5
#define LOG_fOOutputFilter                      53      // 2 Bits, Bit 4-3
#define     LOG_fOOutputFilterMask 0x18
#define     LOG_fOOutputFilterShift 3
#define LOG_fOSendOnChange                      53      // 1 Bit, Bit 3
#define     LOG_fOSendOnChangeMask 0x08
#define     LOG_fOSendOnChangeShift 3
#define LOG_fODpt                               54      // 8 Bits, Bit 7-0
#define LOG_fOOn                                55      // 8 Bits, Bit 7-0
#define LOG_fOOnBuzzer                          55      // 8 Bits, Bit 7-0
#define LOG_fOOnLed                             55      // 8 Bits, Bit 7-0
#define LOG_fOOnAll                             55      // 8 Bits, Bit 7-0
#define LOG_fOOnTone                            56      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt1                            56      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt2                            56      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt5                            56      // uint8_t
#define LOG_fOOnDpt5001                         56      // uint8_t
#define LOG_fOOnDpt6                            56      // int8_t
#define LOG_fOOnDpt7                            56      // uint16_t
#define LOG_fOOnDpt8                            56      // int16_t
#define LOG_fOOnDpt9                            56      // float
#define LOG_fOOnDpt12                           56      // uint32_t
#define LOG_fOOnDpt13                           56      // int32_t
#define LOG_fOOnDpt14                           56      // float
#define LOG_fOOnDpt16                           56      // char*, 14 Byte
#define LOG_fOOnDpt17                           56      // 8 Bits, Bit 7-0
#define LOG_fOOnRGB                             56      // 24 Bits, Bit 31-8
#define     LOG_fOOnRGBMask 0xFFFFFF00
#define     LOG_fOOnRGBShift 8
#define LOG_fOOnPAArea                          56      // 4 Bits, Bit 7-4
#define     LOG_fOOnPAAreaMask 0xF0
#define     LOG_fOOnPAAreaShift 4
#define LOG_fOOnPALine                          56      // 4 Bits, Bit 3-0
#define     LOG_fOOnPALineMask 0x0F
#define     LOG_fOOnPALineShift 0
#define LOG_fOOnPADevice                        57      // uint8_t
#define LOG_fOOnFunction                        56      // 8 Bits, Bit 7-0
#define LOG_fOOnKOKind                          61      // 2 Bits, Bit 7-6
#define     LOG_fOOnKOKindMask 0xC0
#define     LOG_fOOnKOKindShift 6
#define LOG_fOOnKONumber                        56      // uint16_t
#define LOG_fOOnKONumberRel                     56      // int16_t
#define LOG_fOOnKODpt                           58      // 8 Bits, Bit 7-0
#define LOG_fOOnKOSend                          61      // 2 Bits, Bit 5-4
#define     LOG_fOOnKOSendMask 0x30
#define     LOG_fOOnKOSendShift 4
#define LOG_fOOnKOSendNumber                    62      // uint16_t
#define LOG_fOOnKOSendNumberRel                 62      // int16_t
#define LOG_fOOff                               70      // 8 Bits, Bit 7-0
#define LOG_fOOffBuzzer                         70      // 8 Bits, Bit 7-0
#define LOG_fOOffLed                            70      // 8 Bits, Bit 7-0
#define LOG_fOOffAll                            70      // 8 Bits, Bit 7-0
#define LOG_fOOffTone                           71      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt1                           71      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt2                           71      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt5                           71      // uint8_t
#define LOG_fOOffDpt5001                        71      // uint8_t
#define LOG_fOOffDpt6                           71      // int8_t
#define LOG_fOOffDpt7                           71      // uint16_t
#define LOG_fOOffDpt8                           71      // int16_t
#define LOG_fOOffDpt9                           71      // float
#define LOG_fOOffDpt12                          71      // uint32_t
#define LOG_fOOffDpt13                          71      // int32_t
#define LOG_fOOffDpt14                          71      // float
#define LOG_fOOffDpt16                          71      // char*, 14 Byte
#define LOG_fOOffDpt17                          71      // 8 Bits, Bit 7-0
#define LOG_fOOffRGB                            71      // 24 Bits, Bit 31-8
#define     LOG_fOOffRGBMask 0xFFFFFF00
#define     LOG_fOOffRGBShift 8
#define LOG_fOOffPAArea                         71      // 4 Bits, Bit 7-4
#define     LOG_fOOffPAAreaMask 0xF0
#define     LOG_fOOffPAAreaShift 4
#define LOG_fOOffPALine                         71      // 4 Bits, Bit 3-0
#define     LOG_fOOffPALineMask 0x0F
#define     LOG_fOOffPALineShift 0
#define LOG_fOOffPADevice                       72      // uint8_t
#define LOG_fOOffFunction                       71      // 8 Bits, Bit 7-0
#define LOG_fOOffKOKind                         76      // 2 Bits, Bit 7-6
#define     LOG_fOOffKOKindMask 0xC0
#define     LOG_fOOffKOKindShift 6
#define LOG_fOOffKONumber                       71      // uint16_t
#define LOG_fOOffKONumberRel                    71      // int16_t
#define LOG_fOOffKODpt                          73      // 8 Bits, Bit 7-0
#define LOG_fOOffKOSend                         76      // 2 Bits, Bit 5-4
#define     LOG_fOOffKOSendMask 0x30
#define     LOG_fOOffKOSendShift 4
#define LOG_fOOffKOSendNumber                   77      // uint16_t
#define LOG_fOOffKOSendNumberRel                77      // int16_t

// Zeit bis der Kanal nach einem Neustart aktiv wird
#define ParamLOG_fChannelDelayBase                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fChannelDelayBase)) & LOG_fChannelDelayBaseMask) >> LOG_fChannelDelayBaseShift)
// Zeit bis der Kanal nach einem Neustart aktiv wird
#define ParamLOG_fChannelDelayTime                   (knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime)) & LOG_fChannelDelayTimeMask)
// Zeit bis der Kanal nach einem Neustart aktiv wird (in Millisekunden)
#define ParamLOG_fChannelDelayTimeMS                 (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime))))
// Logik-Operation
#define ParamLOG_fLogic                              (knx.paramByte(LOG_ParamCalcIndex(LOG_fLogic)))
// Logik auswerten
#define ParamLOG_fCalculate                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fCalculate)) & LOG_fCalculateMask)
// Kanal deaktivieren (zu Testzwecken)
#define ParamLOG_fDisable                            ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fDisable)) & LOG_fDisableMask))
// Alarmausgabe (Buzzer oder LED trotz Sperre schalten)?
#define ParamLOG_fAlarm                              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fAlarm)) & LOG_fAlarmMask))
// Tor geht sofort wieder zu
#define ParamLOG_fTGate                              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTGate)) & LOG_fTGateMask))
// Wert EIN intern weiterleiten
#define ParamLOG_fOInternalOn                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOn)) & LOG_fOInternalOnMask))
// Wert AUS intern weiterleiten
#define ParamLOG_fOInternalOff                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOff)) & LOG_fOInternalOffMask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTrigger                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fTrigger)))
//           Eingang 1
#define ParamLOG_fTriggerE1                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE1)) & LOG_fTriggerE1Mask))
//           Eingang 2
#define ParamLOG_fTriggerE2                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE2)) & LOG_fTriggerE2Mask))
//           Interner Eingang 3
#define ParamLOG_fTriggerI1                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI1)) & LOG_fTriggerI1Mask))
//           Interner Eingang 4
#define ParamLOG_fTriggerI2                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI2)) & LOG_fTriggerI2Mask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTriggerTime                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerTime)))
// Beim schließen vom Tor wird
#define ParamLOG_fTriggerGateClose                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateClose)) & LOG_fTriggerGateCloseMask) >> LOG_fTriggerGateCloseShift)
// Beim öffnen vom Tor wird
#define ParamLOG_fTriggerGateOpen                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateOpen)) & LOG_fTriggerGateOpenMask) >> LOG_fTriggerGateOpenShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertInt                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertInt)) & LOG_fE1ConvertIntMask) >> LOG_fE1ConvertIntShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1Convert                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Convert)) & LOG_fE1ConvertMask) >> LOG_fE1ConvertShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertFloat                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertFloat)) & LOG_fE1ConvertFloatMask) >> LOG_fE1ConvertFloatShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertSpecial                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertSpecial)) & LOG_fE1ConvertSpecialMask) >> LOG_fE1ConvertSpecialShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertBool                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertBool)) & LOG_fE1ConvertBoolMask) >> LOG_fE1ConvertBoolShift)
// Eingang 1
#define ParamLOG_fE1                                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1)) & LOG_fE1Mask)
// DPT für Eingang
#define ParamLOG_fE1Dpt                              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Dpt)))
// Eingang wird gelesen alle
#define ParamLOG_fE1RepeatBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1RepeatBase)) & LOG_fE1RepeatBaseMask) >> LOG_fE1RepeatBaseShift)
// Eingang wird gelesen alle
#define ParamLOG_fE1RepeatTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime)) & LOG_fE1RepeatTimeMask)
// Eingang wird gelesen alle (in Millisekunden)
#define ParamLOG_fE1RepeatTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime))))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE1OtherKO                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1OtherKO)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE1OtherKORel                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1OtherKORel)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE1Default                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Default)) & LOG_fE1DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE1DefaultExt                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultExt)) & LOG_fE1DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE1DefaultEEPROM                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultEEPROM)) & LOG_fE1DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE1DefaultRepeat                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultRepeat)) & LOG_fE1DefaultRepeatMask))
// Kommunikationsobjekt für Eingang
#define ParamLOG_fE1UseOtherKO                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1UseOtherKO)) & LOG_fE1UseOtherKOMask) >> LOG_fE1UseOtherKOShift)
// Von-Wert
#define ParamLOG_fE1LowDelta                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDelta)))
// Bis-Wert
#define ParamLOG_fE1HighDelta                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDelta)))
// Von-Wert
#define ParamLOG_fE1LowDeltaFloat                    (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaFloat                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDeltaDouble                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaDouble                  (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low0Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Valid)) & LOG_fE1Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low1Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Valid)) & LOG_fE1Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low2Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Valid)) & LOG_fE1Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low3Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Valid)) & LOG_fE1Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low4Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Valid)) & LOG_fE1Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low5Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Valid)) & LOG_fE1Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low6Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Valid)) & LOG_fE1Low6ValidMask))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE1Low0Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low1Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low2Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low3Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt2)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt2Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt2Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt5                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5)))
// Bis-Wert
#define ParamLOG_fE1HighDpt5                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt5Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt5001                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5001)))
// Bis-Wert
#define ParamLOG_fE1HighDpt5001                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5001)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5xIn)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt5xFix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE1LowDpt6                          ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6)))
// Bis-Wert
#define ParamLOG_fE1HighDpt6                         ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt6)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt6In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt6Fix                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt7                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7)))
// Bis-Wert
#define ParamLOG_fE1HighDpt7                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt7)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt7In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt7Fix                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt8                          ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8)))
// Bis-Wert
#define ParamLOG_fE1HighDpt8                         ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt8)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt8In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt8Fix                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt9                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt9                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt9), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt9Fix                       (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDpt12                         (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt12)))
// Bis-Wert
#define ParamLOG_fE1HighDpt12                        (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDpt12)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt12Fix                      (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt13                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt13)))
// Bis-Wert
#define ParamLOG_fE1HighDpt13                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDpt13)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt13Fix                      ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt14                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt14                        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt14), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt14Fix                      (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang ist EIN bei Szene
#define ParamLOG_fE1Low0Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low1Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low2Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low3Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low4Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low5Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low6Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low7Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low7Dpt17)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt17Fix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE1LowDptRGB                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE1HighDptRGB                       ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDptRGB)))
// Eingang ist konstant
#define ParamLOG_fE1LowDptRGBFix                     ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDptRGBFix)))
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertInt                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertInt)) & LOG_fE2ConvertIntMask) >> LOG_fE2ConvertIntShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2Convert                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Convert)) & LOG_fE2ConvertMask) >> LOG_fE2ConvertShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertFloat                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertFloat)) & LOG_fE2ConvertFloatMask) >> LOG_fE2ConvertFloatShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertSpecial                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertSpecial)) & LOG_fE2ConvertSpecialMask) >> LOG_fE2ConvertSpecialShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertBool                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertBool)) & LOG_fE2ConvertBoolMask) >> LOG_fE2ConvertBoolShift)
// Eingang 2
#define ParamLOG_fE2                                 (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2)) & LOG_fE2Mask)
// DPT für Eingang
#define ParamLOG_fE2Dpt                              (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Dpt)))
// Eingang wird gelesen alle
#define ParamLOG_fE2RepeatBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2RepeatBase)) & LOG_fE2RepeatBaseMask) >> LOG_fE2RepeatBaseShift)
// Eingang wird gelesen alle
#define ParamLOG_fE2RepeatTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime)) & LOG_fE2RepeatTimeMask)
// Eingang wird gelesen alle (in Millisekunden)
#define ParamLOG_fE2RepeatTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime))))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE2OtherKO                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2OtherKO)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE2OtherKORel                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2OtherKORel)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE2Default                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Default)) & LOG_fE2DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE2DefaultExt                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultExt)) & LOG_fE2DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE2DefaultEEPROM                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultEEPROM)) & LOG_fE2DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE2DefaultRepeat                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultRepeat)) & LOG_fE2DefaultRepeatMask))
// Kommunikationsobjekt für Eingang
#define ParamLOG_fE2UseOtherKO                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2UseOtherKO)) & LOG_fE2UseOtherKOMask) >> LOG_fE2UseOtherKOShift)
// Von-Wert
#define ParamLOG_fE2LowDelta                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDelta)))
// Bis-Wert
#define ParamLOG_fE2HighDelta                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDelta)))
// Von-Wert
#define ParamLOG_fE2LowDeltaFloat                    (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaFloat                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDeltaDouble                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaDouble                  (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low0Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Valid)) & LOG_fE2Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low1Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Valid)) & LOG_fE2Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low2Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Valid)) & LOG_fE2Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low3Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Valid)) & LOG_fE2Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low4Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Valid)) & LOG_fE2Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low5Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Valid)) & LOG_fE2Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low6Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Valid)) & LOG_fE2Low6ValidMask))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE2Low0Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low1Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low2Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low3Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt2)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt2Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt2Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt5                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt5Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt5001                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5001)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5001                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5001)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5xIn)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt5xFix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE2LowDpt6                          ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6)))
// Bis-Wert
#define ParamLOG_fE2HighDpt6                         ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt6)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt6In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt6Fix                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt7                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7)))
// Bis-Wert
#define ParamLOG_fE2HighDpt7                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt7)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt7In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt7Fix                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt8                          ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8)))
// Bis-Wert
#define ParamLOG_fE2HighDpt8                         ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt8)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt8In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt8Fix                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt9                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt9                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt9), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt9Fix                       (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDpt12                         (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt12)))
// Bis-Wert
#define ParamLOG_fE2HighDpt12                        (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDpt12)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt12Fix                      (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt13                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt13)))
// Bis-Wert
#define ParamLOG_fE2HighDpt13                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDpt13)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt13Fix                      ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt14                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt14                        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt14), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt14Fix                      (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang ist EIN bei Szene
#define ParamLOG_fE2Low0Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low1Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low2Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low3Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low4Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low5Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low6Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low7Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low7Dpt17)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt17Fix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE2LowDptRGB                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE2HighDptRGB                       ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDptRGB)))
// Eingang ist konstant
#define ParamLOG_fE2LowDptRGBFix                     ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDptRGBFix)))
// Zeitbezug
#define ParamLOG_fTd1DuskDawn                        ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1DuskDawn)) & LOG_fTd1DuskDawnMask) >> LOG_fTd1DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd2DuskDawn                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2DuskDawn)) & LOG_fTd2DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd3DuskDawn                        ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3DuskDawn)) & LOG_fTd3DuskDawnMask) >> LOG_fTd3DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd4DuskDawn                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4DuskDawn)) & LOG_fTd4DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd5DuskDawn                        ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5DuskDawn)) & LOG_fTd5DuskDawnMask) >> LOG_fTd5DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd6DuskDawn                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6DuskDawn)) & LOG_fTd6DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd7DuskDawn                        ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7DuskDawn)) & LOG_fTd7DuskDawnMask) >> LOG_fTd7DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd8DuskDawn                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8DuskDawn)) & LOG_fTd8DuskDawnMask)
// Typ der Zeitschaltuhr
#define ParamLOG_fTYearDay                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTYearDay)) & LOG_fTYearDayMask) >> LOG_fTYearDayShift)
// Feiertagsbehandlung
#define ParamLOG_fTHoliday                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTHoliday)) & LOG_fTHolidayMask) >> LOG_fTHolidayShift)
// Bei Neustart letzte Schaltzeit nachholen
#define ParamLOG_fTRestoreState                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTRestoreState)) & LOG_fTRestoreStateMask) >> LOG_fTRestoreStateShift)
// Urlaubsbehandlung
#define ParamLOG_fTVacation                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fTVacation)) & LOG_fTVacationMask)
// Zahlenwert
#define ParamLOG_fTd1ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1ValueNum)))
// Zahlenwert
#define ParamLOG_fTd2ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2ValueNum)))
// Zahlenwert
#define ParamLOG_fTd3ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3ValueNum)))
// Zahlenwert
#define ParamLOG_fTd4ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4ValueNum)))
// Zahlenwert
#define ParamLOG_fTd5ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5ValueNum)))
// Zahlenwert
#define ParamLOG_fTd6ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6ValueNum)))
// Zahlenwert
#define ParamLOG_fTd7ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7ValueNum)))
// Zahlenwert
#define ParamLOG_fTd8ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8ValueNum)))
// Schaltwert
#define ParamLOG_fTd1Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Value)) & LOG_fTd1ValueMask))
// Grad
#define ParamLOG_fTd1Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Degree)) & LOG_fTd1DegreeMask) >> LOG_fTd1DegreeShift)
// Stunde
#define ParamLOG_fTd1HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourAbs)) & LOG_fTd1HourAbsMask) >> LOG_fTd1HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd1HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourRel)) & LOG_fTd1HourRelMask) >> LOG_fTd1HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd1HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourRelShort)) & LOG_fTd1HourRelShortMask) >> LOG_fTd1HourRelShortShift)
// Minute
#define ParamLOG_fTd1MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteAbs)))
// Minute
#define ParamLOG_fTd1MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteRel)))
// Wochentag
#define ParamLOG_fTd1Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Weekday)) & LOG_fTd1WeekdayMask)
// Schaltwert
#define ParamLOG_fTd2Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Value)) & LOG_fTd2ValueMask))
// Grad
#define ParamLOG_fTd2Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Degree)) & LOG_fTd2DegreeMask) >> LOG_fTd2DegreeShift)
// Stunde
#define ParamLOG_fTd2HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourAbs)) & LOG_fTd2HourAbsMask) >> LOG_fTd2HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd2HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourRel)) & LOG_fTd2HourRelMask) >> LOG_fTd2HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd2HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourRelShort)) & LOG_fTd2HourRelShortMask) >> LOG_fTd2HourRelShortShift)
// Minute
#define ParamLOG_fTd2MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteAbs)))
// Minute
#define ParamLOG_fTd2MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteRel)))
// Wochentag
#define ParamLOG_fTd2Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Weekday)) & LOG_fTd2WeekdayMask)
// Schaltwert
#define ParamLOG_fTd3Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Value)) & LOG_fTd3ValueMask))
// Grad
#define ParamLOG_fTd3Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Degree)) & LOG_fTd3DegreeMask) >> LOG_fTd3DegreeShift)
// Stunde
#define ParamLOG_fTd3HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourAbs)) & LOG_fTd3HourAbsMask) >> LOG_fTd3HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd3HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourRel)) & LOG_fTd3HourRelMask) >> LOG_fTd3HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd3HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourRelShort)) & LOG_fTd3HourRelShortMask) >> LOG_fTd3HourRelShortShift)
// Minute
#define ParamLOG_fTd3MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteAbs)))
// Minute
#define ParamLOG_fTd3MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteRel)))
// Wochentag
#define ParamLOG_fTd3Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Weekday)) & LOG_fTd3WeekdayMask)
// Schaltwert
#define ParamLOG_fTd4Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Value)) & LOG_fTd4ValueMask))
// Grad
#define ParamLOG_fTd4Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Degree)) & LOG_fTd4DegreeMask) >> LOG_fTd4DegreeShift)
// Stunde
#define ParamLOG_fTd4HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourAbs)) & LOG_fTd4HourAbsMask) >> LOG_fTd4HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd4HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourRel)) & LOG_fTd4HourRelMask) >> LOG_fTd4HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd4HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourRelShort)) & LOG_fTd4HourRelShortMask) >> LOG_fTd4HourRelShortShift)
// Minute
#define ParamLOG_fTd4MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteAbs)))
// Minute
#define ParamLOG_fTd4MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteRel)))
// Wochentag
#define ParamLOG_fTd4Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Weekday)) & LOG_fTd4WeekdayMask)
// Schaltwert
#define ParamLOG_fTd5Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Value)) & LOG_fTd5ValueMask))
// Grad
#define ParamLOG_fTd5Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Degree)) & LOG_fTd5DegreeMask) >> LOG_fTd5DegreeShift)
// Stunde
#define ParamLOG_fTd5HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourAbs)) & LOG_fTd5HourAbsMask) >> LOG_fTd5HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd5HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourRel)) & LOG_fTd5HourRelMask) >> LOG_fTd5HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd5HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourRelShort)) & LOG_fTd5HourRelShortMask) >> LOG_fTd5HourRelShortShift)
// Minute
#define ParamLOG_fTd5MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteAbs)))
// Minute
#define ParamLOG_fTd5MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteRel)))
// Wochentag
#define ParamLOG_fTd5Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Weekday)) & LOG_fTd5WeekdayMask)
// Schaltwert
#define ParamLOG_fTd6Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Value)) & LOG_fTd6ValueMask))
// Grad
#define ParamLOG_fTd6Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Degree)) & LOG_fTd6DegreeMask) >> LOG_fTd6DegreeShift)
// Stunde
#define ParamLOG_fTd6HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourAbs)) & LOG_fTd6HourAbsMask) >> LOG_fTd6HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd6HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourRel)) & LOG_fTd6HourRelMask) >> LOG_fTd6HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd6HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourRelShort)) & LOG_fTd6HourRelShortMask) >> LOG_fTd6HourRelShortShift)
// Minute
#define ParamLOG_fTd6MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteAbs)))
// Minute
#define ParamLOG_fTd6MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteRel)))
// Wochentag
#define ParamLOG_fTd6Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Weekday)) & LOG_fTd6WeekdayMask)
// Schaltwert
#define ParamLOG_fTd7Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Value)) & LOG_fTd7ValueMask))
// Grad
#define ParamLOG_fTd7Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Degree)) & LOG_fTd7DegreeMask) >> LOG_fTd7DegreeShift)
// Stunde
#define ParamLOG_fTd7HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourAbs)) & LOG_fTd7HourAbsMask) >> LOG_fTd7HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd7HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourRel)) & LOG_fTd7HourRelMask) >> LOG_fTd7HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd7HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourRelShort)) & LOG_fTd7HourRelShortMask) >> LOG_fTd7HourRelShortShift)
// Minute
#define ParamLOG_fTd7MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteAbs)))
// Minute
#define ParamLOG_fTd7MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteRel)))
// Wochentag
#define ParamLOG_fTd7Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Weekday)) & LOG_fTd7WeekdayMask)
// Schaltwert
#define ParamLOG_fTd8Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Value)) & LOG_fTd8ValueMask))
// Grad
#define ParamLOG_fTd8Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Degree)) & LOG_fTd8DegreeMask) >> LOG_fTd8DegreeShift)
// Stunde
#define ParamLOG_fTd8HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourAbs)) & LOG_fTd8HourAbsMask) >> LOG_fTd8HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd8HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourRel)) & LOG_fTd8HourRelMask) >> LOG_fTd8HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd8HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourRelShort)) & LOG_fTd8HourRelShortMask) >> LOG_fTd8HourRelShortShift)
// Minute
#define ParamLOG_fTd8MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteAbs)))
// Minute
#define ParamLOG_fTd8MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteRel)))
// Wochentag
#define ParamLOG_fTd8Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Weekday)) & LOG_fTd8WeekdayMask)
// Mo
#define ParamLOG_fTy1Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday1)) & LOG_fTy1Weekday1Mask))
// Di
#define ParamLOG_fTy1Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday2)) & LOG_fTy1Weekday2Mask))
// Mi
#define ParamLOG_fTy1Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday3)) & LOG_fTy1Weekday3Mask))
// Do
#define ParamLOG_fTy1Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday4)) & LOG_fTy1Weekday4Mask))
// Fr
#define ParamLOG_fTy1Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday5)) & LOG_fTy1Weekday5Mask))
// Sa
#define ParamLOG_fTy1Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday6)) & LOG_fTy1Weekday6Mask))
// So
#define ParamLOG_fTy1Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday7)) & LOG_fTy1Weekday7Mask))
// Tag
#define ParamLOG_fTy1Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Day)) & LOG_fTy1DayMask) >> LOG_fTy1DayShift)
// Wochentag
#define ParamLOG_fTy1IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1IsWeekday)) & LOG_fTy1IsWeekdayMask))
// Monat
#define ParamLOG_fTy1Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Month)) & LOG_fTy1MonthMask) >> LOG_fTy1MonthShift)
// Mo
#define ParamLOG_fTy2Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday1)) & LOG_fTy2Weekday1Mask))
// Di
#define ParamLOG_fTy2Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday2)) & LOG_fTy2Weekday2Mask))
// Mi
#define ParamLOG_fTy2Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday3)) & LOG_fTy2Weekday3Mask))
// Do
#define ParamLOG_fTy2Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday4)) & LOG_fTy2Weekday4Mask))
// Fr
#define ParamLOG_fTy2Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday5)) & LOG_fTy2Weekday5Mask))
// Sa
#define ParamLOG_fTy2Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday6)) & LOG_fTy2Weekday6Mask))
// So
#define ParamLOG_fTy2Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday7)) & LOG_fTy2Weekday7Mask))
// Tag
#define ParamLOG_fTy2Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Day)) & LOG_fTy2DayMask) >> LOG_fTy2DayShift)
// Wochentag
#define ParamLOG_fTy2IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2IsWeekday)) & LOG_fTy2IsWeekdayMask))
// Monat
#define ParamLOG_fTy2Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Month)) & LOG_fTy2MonthMask) >> LOG_fTy2MonthShift)
// Mo
#define ParamLOG_fTy3Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday1)) & LOG_fTy3Weekday1Mask))
// Di
#define ParamLOG_fTy3Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday2)) & LOG_fTy3Weekday2Mask))
// Mi
#define ParamLOG_fTy3Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday3)) & LOG_fTy3Weekday3Mask))
// Do
#define ParamLOG_fTy3Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday4)) & LOG_fTy3Weekday4Mask))
// Fr
#define ParamLOG_fTy3Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday5)) & LOG_fTy3Weekday5Mask))
// Sa
#define ParamLOG_fTy3Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday6)) & LOG_fTy3Weekday6Mask))
// So
#define ParamLOG_fTy3Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday7)) & LOG_fTy3Weekday7Mask))
// Tag
#define ParamLOG_fTy3Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Day)) & LOG_fTy3DayMask) >> LOG_fTy3DayShift)
// Wochentag
#define ParamLOG_fTy3IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3IsWeekday)) & LOG_fTy3IsWeekdayMask))
// Monat
#define ParamLOG_fTy3Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Month)) & LOG_fTy3MonthMask) >> LOG_fTy3MonthShift)
// Mo
#define ParamLOG_fTy4Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday1)) & LOG_fTy4Weekday1Mask))
// Di
#define ParamLOG_fTy4Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday2)) & LOG_fTy4Weekday2Mask))
// Mi
#define ParamLOG_fTy4Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday3)) & LOG_fTy4Weekday3Mask))
// Do
#define ParamLOG_fTy4Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday4)) & LOG_fTy4Weekday4Mask))
// Fr
#define ParamLOG_fTy4Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday5)) & LOG_fTy4Weekday5Mask))
// Sa
#define ParamLOG_fTy4Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday6)) & LOG_fTy4Weekday6Mask))
// So
#define ParamLOG_fTy4Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday7)) & LOG_fTy4Weekday7Mask))
// Tag
#define ParamLOG_fTy4Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Day)) & LOG_fTy4DayMask) >> LOG_fTy4DayShift)
// Wochentag
#define ParamLOG_fTy4IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4IsWeekday)) & LOG_fTy4IsWeekdayMask))
// Monat
#define ParamLOG_fTy4Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Month)) & LOG_fTy4MonthMask) >> LOG_fTy4MonthShift)
// Interner Eingang 3
#define ParamLOG_fI1                                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1)) & LOG_fI1Mask) >> LOG_fI1Shift)
// Interner Eingang 4
#define ParamLOG_fI2                                 ((knx.paramByte(LOG_ParamCalcIndex(LOG_fI2)) & LOG_fI2Mask) >> LOG_fI2Shift)
// Art der Verknüpfung
#define ParamLOG_fI1Kind                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1Kind)) & LOG_fI1KindMask) >> LOG_fI1KindShift)
// Art der Verknüpfung
#define ParamLOG_fI2Kind                             (knx.paramByte(LOG_ParamCalcIndex(LOG_fI2Kind)) & LOG_fI2KindMask)
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI1Function                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fI1Function)))
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI2Function                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fI2Function)))
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI1FunctionRel                      ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fI1FunctionRel)))
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI2FunctionRel                      ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fI2FunctionRel)))
// Internen Eingang als Trigger nutzen(ist immer logisch EIN)
#define ParamLOG_fI1AsTrigger                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fI1AsTrigger)) & LOG_fI1AsTriggerMask))
// Internen Eingang als Trigger nutzen(ist immer logisch EIN)
#define ParamLOG_fI2AsTrigger                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fI2AsTrigger)) & LOG_fI2AsTriggerMask))
// Zeit für Treppenlicht
#define ParamLOG_fOStairtimeBase                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairtimeBase)) & LOG_fOStairtimeBaseMask) >> LOG_fOStairtimeBaseShift)
// Zeit für Treppenlicht
#define ParamLOG_fOStairtimeTime                     (knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime)) & LOG_fOStairtimeTimeMask)
// Zeit für Treppenlicht (in Millisekunden)
#define ParamLOG_fOStairtimeTimeMS                   (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime))))
// Treppenlicht blinkt im Rhythmus
#define ParamLOG_fOBlinkBase                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOBlinkBase)) & LOG_fOBlinkBaseMask) >> LOG_fOBlinkBaseShift)
// Treppenlicht blinkt im Rhythmus
#define ParamLOG_fOBlinkTime                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime)) & LOG_fOBlinkTimeMask)
// Treppenlicht blinkt im Rhythmus (in Millisekunden)
#define ParamLOG_fOBlinkTimeMS                       (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime))))
// EINschalten wird verzögert um
#define ParamLOG_fODelayOnBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnBase)) & LOG_fODelayOnBaseMask) >> LOG_fODelayOnBaseShift)
// EINschalten wird verzögert um
#define ParamLOG_fODelayOnTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime)) & LOG_fODelayOnTimeMask)
// EINschalten wird verzögert um (in Millisekunden)
#define ParamLOG_fODelayOnTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime))))
// AUSschalten wird verzögert um
#define ParamLOG_fODelayOffBase                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffBase)) & LOG_fODelayOffBaseMask) >> LOG_fODelayOffBaseShift)
// AUSschalten wird verzögert um
#define ParamLOG_fODelayOffTime                      (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime)) & LOG_fODelayOffTimeMask)
// AUSschalten wird verzögert um (in Millisekunden)
#define ParamLOG_fODelayOffTimeMS                    (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime))))
// EIN-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOnBase                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOnBase)) & LOG_fORepeatOnBaseMask) >> LOG_fORepeatOnBaseShift)
// EIN-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOnTime                      (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime)) & LOG_fORepeatOnTimeMask)
// EIN-Telegramm wird wiederholt alle (in Millisekunden)
#define ParamLOG_fORepeatOnTimeMS                    (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime))))
// AUS-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOffBase                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOffBase)) & LOG_fORepeatOffBaseMask) >> LOG_fORepeatOffBaseShift)
// AUS-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOffTime                     (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime)) & LOG_fORepeatOffTimeMask)
// AUS-Telegramm wird wiederholt alle (in Millisekunden)
#define ParamLOG_fORepeatOffTimeMS                   (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime))))
// Ausgang schaltet zeitverzögert
#define ParamLOG_fODelay                             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelay)) & LOG_fODelayMask))
// Erneutes EIN führt zu
#define ParamLOG_fODelayOnRepeat                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnRepeat)) & LOG_fODelayOnRepeatMask) >> LOG_fODelayOnRepeatShift)
// Darauffolgendes AUS führt zu
#define ParamLOG_fODelayOnReset                      ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnReset)) & LOG_fODelayOnResetMask))
// Erneutes AUS führt zu
#define ParamLOG_fODelayOffRepeat                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffRepeat)) & LOG_fODelayOffRepeatMask) >> LOG_fODelayOffRepeatShift)
// Darauffolgendes EIN führt zu
#define ParamLOG_fODelayOffReset                     ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffReset)) & LOG_fODelayOffResetMask))
// Ausgang hat eine Treppenlichtfunktion
#define ParamLOG_fOStair                             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStair)) & LOG_fOStairMask))
// Treppenlicht kann verlängert werden
#define ParamLOG_fORetrigger                         ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORetrigger)) & LOG_fORetriggerMask))
// Treppenlicht kann ausgeschaltet werden
#define ParamLOG_fOStairOff                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairOff)) & LOG_fOStairOffMask))
// Ausgang wiederholt zyklisch
#define ParamLOG_fORepeat                            ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeat)) & LOG_fORepeatMask))
// Wiederholungsfilter
#define ParamLOG_fOOutputFilter                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOutputFilter)) & LOG_fOOutputFilterMask) >> LOG_fOOutputFilterShift)
// Sendeverhalten für Ausgang
#define ParamLOG_fOSendOnChange                      ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOSendOnChange)) & LOG_fOSendOnChangeMask))
// DPT für Ausgang
#define ParamLOG_fODpt                               (knx.paramByte(LOG_ParamCalcIndex(LOG_fODpt)))
// Wert für EIN senden?
#define ParamLOG_fOOn                                (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOn)))
// Wert für EIN senden?
#define ParamLOG_fOOnBuzzer                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnBuzzer)))
// Wert für EIN senden?
#define ParamLOG_fOOnLed                             (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnLed)))
// Wert für EIN senden?
#define ParamLOG_fOOnAll                             (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnAll)))
//     Wert für EIN senden als
#define ParamLOG_fOOnTone                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnTone)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt1                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt1)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt2                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt2)))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt5                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt5001                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5001)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt6                            ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt6)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt7                            (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt7)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt8                            ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt8)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt9                            (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt9), Float_Enc_IEEE754Single))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt12                           (knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnDpt12)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt13                           ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnDpt13)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt14                           (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt14), Float_Enc_IEEE754Single))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt16                           (knx.paramData(LOG_ParamCalcIndex(LOG_fOOnDpt16)))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt17                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt17)))
//     Wert für EIN senden als (3-Byte-RGB)
#define ParamLOG_fOOnRGB                             ((knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnRGB)) & LOG_fOOnRGBMask) >> LOG_fOOnRGBShift)
// 
#define ParamLOG_fOOnPAArea                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPAArea)) & LOG_fOOnPAAreaMask) >> LOG_fOOnPAAreaShift)
// 
#define ParamLOG_fOOnPALine                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPALine)) & LOG_fOOnPALineMask)
// 
#define ParamLOG_fOOnPADevice                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPADevice)))
//     Wert für EIN ermitteln als
#define ParamLOG_fOOnFunction                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnFunction)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKOKind                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKOKind)) & LOG_fOOnKOKindMask) >> LOG_fOOnKOKindShift)
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKONumber                        (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKONumber)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKONumberRel                     ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKONumberRel)))
//     DPT des Kommunikationsobjekts
#define ParamLOG_fOOnKODpt                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKODpt)))
//     Wert für EIN an ein zusätzliches    KO senden?
#define ParamLOG_fOOnKOSend                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKOSend)) & LOG_fOOnKOSendMask) >> LOG_fOOnKOSendShift)
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOnKOSendNumber                    (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKOSendNumber)))
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOnKOSendNumberRel                 ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKOSendNumberRel)))
// Wert für AUS senden?
#define ParamLOG_fOOff                               (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOff)))
// Wert für AUS senden?
#define ParamLOG_fOOffBuzzer                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffBuzzer)))
// Wert für AUS senden?
#define ParamLOG_fOOffLed                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffLed)))
// Wert für AUS senden?
#define ParamLOG_fOOffAll                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffAll)))
//     Wert für AUS senden als
#define ParamLOG_fOOffTone                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffTone)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt1                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt1)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt2                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt2)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5001                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5001)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt6                           ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt6)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt7                           (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt7)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt8                           ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt8)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt9                           (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt9), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt12                          (knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffDpt12)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt13                          ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffDpt13)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt14                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt14), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt16                          (knx.paramData(LOG_ParamCalcIndex(LOG_fOOffDpt16)))
//     Wert für AUS senden als 
#define ParamLOG_fOOffDpt17                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt17)))
//     Wert für AUS senden als (3-Byte-RGB)
#define ParamLOG_fOOffRGB                            ((knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffRGB)) & LOG_fOOffRGBMask) >> LOG_fOOffRGBShift)
// 
#define ParamLOG_fOOffPAArea                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPAArea)) & LOG_fOOffPAAreaMask) >> LOG_fOOffPAAreaShift)
// 
#define ParamLOG_fOOffPALine                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPALine)) & LOG_fOOffPALineMask)
// 
#define ParamLOG_fOOffPADevice                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPADevice)))
//     Wert für AUS ermitteln als
#define ParamLOG_fOOffFunction                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffFunction)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKOKind                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKOKind)) & LOG_fOOffKOKindMask) >> LOG_fOOffKOKindShift)
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKONumber                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKONumber)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKONumberRel                    ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKONumberRel)))
//     DPT des Kommunikationsobjekts
#define ParamLOG_fOOffKODpt                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKODpt)))
//     Wert für AUS an ein zusätzliches    KO senden?
#define ParamLOG_fOOffKOSend                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKOSend)) & LOG_fOOffKOSendMask) >> LOG_fOOffKOSendShift)
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOffKOSendNumber                   (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKOSendNumber)))
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOffKOSendNumberRel                ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKOSendNumberRel)))

// deprecated
#define LOG_KoOffset 850

// Communication objects per channel (multiple occurrence)
#define LOG_KoBlockOffset 850
#define LOG_KoBlockSize 3

#define LOG_KoCalcNumber(index) (index + LOG_KoBlockOffset + _channelIndex * LOG_KoBlockSize)
#define LOG_KoCalcIndex(number) ((number >= LOG_KoCalcNumber(0) && number < LOG_KoCalcNumber(LOG_KoBlockSize)) ? (number - LOG_KoBlockOffset) % LOG_KoBlockSize : -1)
#define LOG_KoCalcChannel(number) ((number >= LOG_KoBlockOffset && number < LOG_KoBlockOffset + LOG_ChannelCount * LOG_KoBlockSize) ? (number - LOG_KoBlockOffset) / LOG_KoBlockSize : -1)

#define LOG_KoKOfE1 0
#define LOG_KoKOfE2 1
#define LOG_KoKOfO 2

// Eingang 1
#define KoLOG_KOfE1                               (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE1)))
// Eingang 2
#define KoLOG_KOfE2                               (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE2)))
// Ausgang
#define KoLOG_KOfO                                (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfO)))



// Header generation for Module 'BASE_KommentarModule'

#define BASE_KommentarModuleCount 0
#define BASE_KommentarModuleModuleParamSize 0
#define BASE_KommentarModuleSubmodulesParamSize 0
#define BASE_KommentarModuleParamSize 0
#define BASE_KommentarModuleParamOffset 18665
#define BASE_KommentarModuleCalcIndex(index, m1) (index + BASE_KommentarModuleParamOffset + _channelIndex * BASE_KommentarModuleCount * BASE_KommentarModuleParamSize + m1 * BASE_KommentarModuleParamSize)



