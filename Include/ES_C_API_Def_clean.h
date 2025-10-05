enum ES_LengthUnit
{
    ES_LU_Meter = 0, 
    ES_LU_Millimeter = 1, 
    ES_LU_Micron = 2, 
    ES_LU_Foot = 3, 
    ES_LU_Yard = 4, 
    ES_LU_Inch = 5
};


enum ES_AngleUnit
{
    ES_AU_Radian = 0, 
    ES_AU_Degree = 1, 
    ES_AU_Gon = 2
};


enum ES_TemperatureUnit
{
    ES_TU_Celsius = 0, 
    ES_TU_Fahrenheit = 1
};


enum ES_PressureUnit
{
   ES_PU_Mbar = 0, 
   ES_PU_HPascal = 1, 
   ES_PU_KPascal = 2, 
   ES_PU_MmHg = 3, 
   ES_PU_Psi = 4, 
   ES_PU_InH2O = 5, 
   ES_PU_InHg = 6, 
};


enum ES_HumidityUnit
{
    ES_HU_RH = 0, 
};


enum ES_CoordinateSystemType
{
    ES_CS_RHR = 0, 
    ES_CS_LHRX = 1, 
    ES_CS_LHRY = 2, 
    ES_CS_LHRZ = 3, 
    ES_CS_CCW = 4, 
    ES_CS_CCC = 5, 
    ES_CS_SCW = 6, 
    ES_CS_SCC = 7
};
enum ES_DataType
{
    ES_DT_Command = 0,
    ES_DT_Error = 1,
    ES_DT_SingleMeasResult = 2,
    ES_DT_MultiMeasResult = 3,
    ES_DT_StationaryProbeMeasResult = 4,
    ES_DT_ContinuousProbeMeasResult = 5,           
    ES_DT_NivelResult = 6,
    ES_DT_ReflectorPosResult = 7,
    ES_DT_SystemStatusChange = 8,
    ES_DT_SingleMeasResult2 = 9,
    ES_DT_MultiMeasResult2 = 10,
    ES_DT_ProbePosResult = 11,                     
};


enum ES_Command
{
    ES_C_ExitApplication = 0,                      
    ES_C_GetSystemStatus = 1,                      
    ES_C_GetTrackerStatus = 2,                     
    ES_C_SetTemperatureRange = 3,                  
    ES_C_GetTemperatureRange = 4,                  
    ES_C_SetUnits = 5,
    ES_C_GetUnits = 6,
    ES_C_Initialize = 7,
    ES_C_ReleaseMotors = 8,                        
    ES_C_ActivateCameraView = 9,
    ES_C_Park = 10,
    ES_C_SwitchLaser = 11,                         
    ES_C_SetStationOrientationParams = 12,
    ES_C_GetStationOrientationParams = 13,
    ES_C_SetTransformationParams = 14,
    ES_C_GetTransformationParams = 15,
    ES_C_SetBoxRegionParams = 16,                  
    ES_C_GetBoxRegionParams = 17,                  
    ES_C_SetSphereRegionParams = 18,               
    ES_C_GetSphereRegionParams = 19,               
    ES_C_SetEnvironmentParams = 20,
    ES_C_GetEnvironmentParams = 21,
    ES_C_SetRefractionParams = 22,
    ES_C_GetRefractionParams = 23,
    ES_C_SetMeasurementMode = 24,
    ES_C_GetMeasurementMode = 25,
    ES_C_SetCoordinateSystemType = 26,
    ES_C_GetCoordinateSystemType = 27,
    ES_C_SetStationaryModeParams = 28,
    ES_C_GetStationaryModeParams = 29,
    ES_C_SetContinuousTimeModeParams = 30,
    ES_C_GetContinuousTimeModeParams = 31,
    ES_C_SetContinuousDistanceModeParams = 32,
    ES_C_GetContinuousDistanceModeParams = 33,
    ES_C_SetSphereCenterModeParams = 34,           
    ES_C_GetSphereCenterModeParams = 35,           
    ES_C_SetCircleCenterModeParams = 36,           
    ES_C_GetCircleCenterModeParams = 37,           
    ES_C_SetGridModeParams = 38,                   
    ES_C_GetGridModeParams = 39,                   
    ES_C_SetReflector = 40,
    ES_C_GetReflector = 41,
    ES_C_GetReflectors = 42,
    ES_C_SetSearchParams = 43,
    ES_C_GetSearchParams = 44,
    ES_C_SetAdmParams = 45,                        
    ES_C_GetAdmParams = 46,                        
    ES_C_SetSystemSettings = 47,
    ES_C_GetSystemSettings = 48,
    ES_C_StartMeasurement = 49,
    ES_C_StartNivelMeasurement = 51,
    ES_C_StopMeasurement = 52,
    ES_C_ChangeFace = 53,
    ES_C_GoBirdBath = 54,
    ES_C_GoPosition = 55,
    ES_C_GoPositionHVD = 56,
    ES_C_PositionRelativeHV = 57,
    ES_C_PointLaser = 58,
    ES_C_PointLaserHVD = 59,
    ES_C_MoveHV = 60,
    ES_C_GoNivelPosition = 61,
    ES_C_GoLastMeasuredPoint = 62,
    ES_C_FindReflector = 63,                       
    ES_C_Unknown = 64,
    
    
    ES_C_LookForTarget = 65,                       
    ES_C_GetDirection = 66,                        
    ES_C_CallOrientToGravity = 67,                 
    ES_C_ClearTransformationNominalPointList = 68, 
    ES_C_ClearTransformationActualPointList = 69,  
    ES_C_AddTransformationNominalPoint = 70,       
    ES_C_AddTransformationActualPoint = 71,        
    ES_C_SetTransformationInputParams = 72,        
    ES_C_GetTransformationInputParams = 73,        
    ES_C_CallTransformation = 74,                  
    ES_C_GetTransformedPoints = 75,                
    ES_C_ClearDrivePointList = 76,                 
    ES_C_AddDrivePoint = 77,                       
    ES_C_CallIntermediateCompensation = 78,        
    ES_C_SetCompensation = 79,                     
    ES_C_SetStatisticMode = 80,                    
    ES_C_GetStatisticMode = 81,                    
    ES_C_GetStillImage = 82,                       
    ES_C_SetCameraParams = 83,                     
    ES_C_GetCameraParams = 84,                     
    
    
    ES_C_GetCompensation = 85,                     
    ES_C_GetCompensations = 86,                    
    ES_C_CheckBirdBath = 87,                       
    ES_C_GetTrackerDiagnostics = 88,                              
    ES_C_GetADMInfo = 89,                           
    ES_C_GetTPInfo = 90,
    ES_C_GetNivelInfo = 91,
    ES_C_SetLaserOnTimer = 92,                     
    ES_C_GetLaserOnTimer = 93,                     
    ES_C_ConvertDisplayCoordinates = 94,           
    ES_C_GoBirdBath2 = 95,                         
    ES_C_SetTriggerSource = 96,                    
    ES_C_GetTriggerSource = 97,                    
    ES_C_GetFace = 98,                             

    
    ES_C_GetCameras = 99,                          
    ES_C_GetCamera = 100,                          
    ES_C_SetMeasurementCameraMode = 101,           
    ES_C_GetMeasurementCameraMode = 102,           
    ES_C_GetProbes = 103,
    ES_C_GetProbe = 104,
    ES_C_GetTipAdapters = 105,
    ES_C_GetTipAdapter = 106,
    ES_C_GetTCamToTrackerCompensations = 107,      
    ES_C_GetTCamToTrackerCompensation = 108,       
    ES_C_SetTCamToTrackerCompensation = 109,       
    ES_C_GetProbeCompensations = 110,
    ES_C_GetProbeCompensation = 111,
    ES_C_SetProbeCompensation = 112,               
    ES_C_GetTipToProbeCompensations = 113,         
    ES_C_GetTipToProbeCompensation = 114,
    ES_C_SetExternTriggerParams = 115,             
    ES_C_GetExternTriggerParams = 116,             
    ES_C_GetErrorEllipsoid = 117,                  
    ES_C_GetMeasurementCameraInfo = 118,           
    ES_C_GetMeasurementProbeInfo = 119,
    ES_C_SetLongSystemParameter = 120,
    ES_C_GetLongSystemParameter = 121,
    ES_C_GetMeasurementStatusInfo = 122,
    ES_C_GetCompensations2 = 123,                  
    ES_C_GetCurrentPrismPosition = 124,            
    
    
    ES_C_SetDoubleSystemParameter = 125,
    ES_C_GetDoubleSystemParameter = 126,
    ES_C_GetObjectTemperature = 127,               
    ES_C_GetTriggerBoardInfo = 128,                
    ES_C_GetOverviewCameraInfo = 129,                   
    ES_C_ClearCommandQueue = 130,                  
    ES_C_GetADMInfo2 = 131, 
    ES_C_GetTrackerInfo = 132,
    ES_C_GetNivelInfo2 = 133,
    ES_C_RestoreStartupConditions = 134,
    ES_C_GoAndMeasure = 135,                       
    ES_C_GetTipToProbeCompensations2 = 136,        

    
    ES_C_SetTipAdapter = 137,                      
    ES_C_GetATRInfo = 138,
    ES_C_GetMeteoStationInfo = 139,
    ES_C_GetATInfo = 140,                            
    ES_C_GetAT4xxInfo = 140,        
    
    
    ES_C_GetSystemSoftwareVersion = 142,           

    
    ES_C_SystemPowerDown = 144,                    
};


enum ES_MeasMode
{
    ES_MM_Stationary = 0,                          
    ES_MM_ContinuousTime = 1,                      
    ES_MM_ContinuousDistance = 2,                  
    ES_MM_Grid = 3,                                
    ES_MM_SphereCenter = 4,                        
    ES_MM_CircleCenter = 5,                        
    ES_MM_6DStationary = 6,                        
    ES_MM_6DContinuousTime = 7,                    
    ES_MM_6DContinuousDistance = 8,                
    ES_MM_6DGrid = 9,                              
    ES_MM_6DSphereCenter = 10,                     
    ES_MM_6DCircleCenter = 11,                     
    ES_MM_Fast = 20,                               
    ES_MM_Standard = 21,                           
    ES_MM_Precise = 22,                            
    ES_MM_Outdoor = 23,                            
};


enum ES_TargetType
{
    ES_TT_Unknown = 0,
    ES_TT_CornerCube = 1,
    ES_TT_CatsEye = 2,
    ES_TT_GlassPrism = 3,
    ES_TT_RFIPrism = 4,
    ES_TT_RRR15 = 5,
    ES_TT_RRR05 = 6,
    ES_TT_BRR15 = 7,
    ES_TT_BRR05 = 8,
    ES_TT_TBR05 = 9,
    ES_TT_AutoCollMirror = 10,
    ES_TT_RRR0875 = 11,
};


enum ES_TrackerTemperatureRange
{
    ES_TR_Low = 0,
    ES_TR_Medium = 1,
    ES_TR_High = 2,
    ES_TR_Automatic = 3,
};


enum ES_TrackerStatus
{
    ES_TS_NotReady = 0,
    ES_TS_Busy = 1,
    ES_TS_Ready = 2,
    ES_TS_6DStatusInvalid = 3,
};


enum ES_ResultStatus
{
    ES_RS_AllOK = 0,
    ES_RS_ServerBusy = 1,                          
    ES_RS_NotImplemented = 2,
    ES_RS_WrongParameter = 3,
    ES_RS_WrongParameter1 = 4,
    ES_RS_WrongParameter2 = 5,
    ES_RS_WrongParameter3 = 6,
    ES_RS_WrongParameter4 = 7,
    ES_RS_WrongParameter5 = 8,
    ES_RS_WrongParameter6 = 9,
    ES_RS_WrongParameter7 = 10,
    ES_RS_Parameter1OutOfRangeOK = 11,
    ES_RS_Parameter1OutOfRangeNOK = 12,
    ES_RS_Parameter2OutOfRangeOK = 13,
    ES_RS_Parameter2OutOfRangeNOK = 14,
    ES_RS_Parameter3OutOfRangeOK = 15,
    ES_RS_Parameter3OutOfRangeNOK = 16,
    ES_RS_Parameter4OutOfRangeOK = 17,
    ES_RS_Parameter4OutOfRangeNOK = 18,
    ES_RS_Parameter5OutOfRangeOK = 19,
    ES_RS_Parameter5OutOfRangeNOK = 20,
    ES_RS_Parameter6OutOfRangeOK = 21,
    ES_RS_Parameter6OutOfRangeNOK = 22,
    ES_RS_WrongCurrentReflector = 23,
    ES_RS_NoCircleCenterFound = 24,                
    ES_RS_NoSphereCenterFound = 25,                
    ES_RS_NoTPFound = 26,
    ES_RS_NoWeathermonitorFound = 27,
    ES_RS_NoLastMeasuredPoint = 28,
    ES_RS_NoVideoCamera = 29,
    ES_RS_NoAdm = 30,
    ES_RS_NoNivel = 31,
    ES_RS_WrongTPFirmware = 32,
    ES_RS_DataBaseNotFound = 33,                   
    ES_RS_LicenseExpired = 34,                     
    ES_RS_UsageConflict = 35,
    ES_RS_Unknown = 36,

    
    ES_RS_NoDistanceSet = 37,
    ES_RS_NoTrackerConnected = 38,
    ES_RS_TrackerNotInitialized = 39,              
    ES_RS_ModuleNotStarted = 40,                   
    ES_RS_ModuleTimedOut = 41,                     
    ES_RS_ErrorReadingModuleDb = 42,               
    ES_RS_ErrorWritingModuleDb = 43,               
    ES_RS_NotInCameraPosition = 44,                
    ES_RS_TPHasServiceFirmware = 45,               
    ES_RS_TPExternalControl = 46,                  
    ES_RS_WrongParameter8 = 47,
    ES_RS_WrongParameter9 = 48,
    ES_RS_WrongParameter10 = 49,
    ES_RS_WrongParameter11 = 50,
    ES_RS_WrongParameter12 = 51,
    ES_RS_WrongParameter13 = 52,
    ES_RS_WrongParameter14 = 53,
    ES_RS_WrongParameter15 = 54,
    ES_RS_WrongParameter16 = 55,

    
    ES_RS_NoSuchCompensation = 56,                 
    ES_RS_MeteoDataOutOfRange = 57,
    ES_RS_InCompensationMode = 58,                 
    ES_RS_InternalProcessActive = 59,              
    ES_RS_NoCopyProtectionDongleFound = 60,        
    ES_RS_ModuleNotActivated = 61,                 
    ES_RS_ModuleWrongVersion = 62,                 
    ES_RS_DemoDongleExpired = 63,                  

    
    ES_RS_ParameterImportFromProbeFailed = 64,     
    ES_RS_ParameterExportToProbeFailed = 65,       
    ES_RS_TrkCompMeasCameraMismatch = 66,          
    ES_RS_NoMeasurementCamera = 67,                
    ES_RS_NoActiveMeasurementCamera = 68,          
    ES_RS_NoMeasurementCamerasInDb = 69,           
    ES_RS_NoCameraToTrackerCompSet = 70,           
    ES_RS_NoCameraToTrackerCompInDb = 71,          
    ES_RS_ProblemStoringCameraToTrackerFactorySet = 72, 
    ES_RS_ProblemWithCameraInternalCalibration = 73, 
    ES_RS_CommunicationWithMeasurementCameraFailed = 74, 
    ES_RS_NoMeasurementProbe = 75,
    ES_RS_NoActiveMeasurementProbe = 76,           
    ES_RS_NoMeasurementProbesInDb = 77,            
    ES_RS_NoMeasurementProbeCompSet = 78,          
    ES_RS_NoMeasurementProbeCompInDb = 79,         
    ES_RS_ProblemStoringProbeFactorySet = 80,      
    ES_RS_WrongActiveMeasurementProbeCompInDb = 81, 
    ES_RS_CommunicationWithMeasurementProbeFailed = 82, 
    ES_RS_NoMeasurementTip = 83,                   
    ES_RS_NoActiveMeasurementTip = 84,             
    ES_RS_NoMeasurementTipsInDb = 85,              
    ES_RS_NoMeasurementTipCompInDb = 86,           
    ES_RS_NoMeasurementTipCompSet = 87,            
    ES_RS_ProblemStoringTipAssembly = 88,          
    ES_RS_ProblemReadingCompensationDb = 89,       
    ES_RS_NoDataToImport = 90,                     
    ES_RS_ProblemSettingTriggerSource = 91,        
    ES_RS_6DModeNotAllowed = 92,
    ES_RS_Bad6DResult = 93,                        
    ES_RS_NoTemperatureFromWM = 94,
    ES_RS_NoPressureFromWM = 95,
    ES_RS_NoHumidityFromWM = 96,
    ES_RS_6DMeasurementFace2NotAllowed = 97,

    
    ES_RS_InvalidInputData = 98,
    ES_RS_NoTriggerBoard = 99,                                 
    ES_RS_NoMeasurementShankCompSet = ES_API_ERROR_OFFSET + 1, 

    
    ES_RS_NoValidADMCompensation = ES_API_ERROR_OFFSET + 2,    
    ES_RS_PressureSensorProblem = ES_API_ERROR_OFFSET + 3,     
    ES_RS_MeasurementStatusNotReady = ES_API_ERROR_OFFSET + 4,
    ES_RS_AIFMStartUpBusy = ES_API_ERROR_OFFSET + 5,           
    ES_RS_ADMStartUpBusy = ES_API_ERROR_OFFSET + 5,            

    
    ES_RS_InvalidTipAdapter = ES_API_ERROR_OFFSET + 6,
    ES_RS_NoAtr = ES_API_ERROR_OFFSET + 7,
    ES_RS_NoOVC = ES_API_ERROR_OFFSET + 8,
    ES_RS_NoStationaryResult = ES_API_ERROR_OFFSET + 9,        
    ES_RS_SensorNotLeveled = ES_API_ERROR_OFFSET + 10,
    ES_RS_MultiConnectionsNotAllowed = ES_API_ERROR_OFFSET + 11,

    
    ES_RS_SensorNotWarmedUp = ES_API_ERROR_OFFSET + 12,        
    ES_RS_SensorNotStable = ES_API_ERROR_OFFSET + 13,
    ES_RS_SystemNotReadyForMeasurement = ES_API_ERROR_OFFSET + 14,
    ES_RS_CommunicationWithSensorFailed = ES_API_ERROR_OFFSET + 15,
    ES_RS_No_Sensor_Battery = ES_API_ERROR_OFFSET + 16,
    ES_RS_CompensatorNotAllowed = ES_API_ERROR_OFFSET + 17,
    ES_RS_WarmedUpStateReached = ES_API_ERROR_OFFSET + 18,
    ES_RS_NotLeveledForInitialization = ES_API_ERROR_OFFSET + 19,
    ES_RS_ADMHardwareProblem = ES_API_ERROR_OFFSET + 20,
    ES_RS_ATRHardwareProblem = ES_API_ERROR_OFFSET + 21,
    ES_RS_MaxEntriesExceeded = ES_API_ERROR_OFFSET + 22,
    ES_RS_InvalidMeasurementProfile = ES_API_ERROR_OFFSET + 23,
    ES_RS_6DoFModeSettingFailed = ES_API_ERROR_OFFSET + 24,
    ES_RS_ItemSelectionFailed = ES_API_ERROR_OFFSET + 25,
};


enum ES_MeasurementStatus
{
    ES_MS_AllOK = 0,
    ES_MS_SpeedWarning = 1,
    ES_MS_SpeedExeeded = 2,
    ES_MS_PrismError = 3,           
    ES_MS_TriggerTimeViolation = 4, 
};


enum ES_TriggerStatus
{
    ES_TS_TriggerNotPressed = 0,
    ES_TS_TriggerPressed = 1,    
};


enum ES_MeasurementTipStatus
{
    ES_PTS_TipOK = 0,
    ES_PTS_UnknownTip = 1,           
    ES_PTS_MultipleTipsAttached = 2, 
};


enum ES_TrackerProcessorStatus
{
    ES_TPS_NoTPFound = 0,
    ES_TPS_TPFound = 1,
    ES_TPS_NBOpen = 2,                             
    ES_TPS_Booted = 3,
    ES_TPS_CompensationSet = 4,
    ES_TPS_Initialized = 5,
};


enum ES_LaserProcessorStatus
{
    ES_LPS_LCPCommFailed = 0,                      
    ES_LPS_LCPNotAvail = 1,                        
    ES_LPS_LaserHeatingUp = 2,                     
    ES_LPS_LaserReady = 3,
    ES_LPS_UnableToStabilize = 4,                  
    ES_LPS_LaserOff = 5,                           
};


enum ES_ADMStatus
{
    ES_AS_NoADM = 0,                               
    ES_AS_ADMCommFailed = 1,                       
    ES_AS_ADMReady = 2,
    ES_AS_ADMBusy = 3,                             
    ES_AS_HWError = 4,                             
    ES_AS_SecurityLockActive = 5,                  
    ES_AS_NotCompensated = 6,                      
};


enum ES_NivelStatus
{
    ES_NS_AllOK = 0,
    ES_NS_OutOfRangeOK = 1,
    ES_NS_OutOfRangeNOK = 2,
    ES_NS_NoNivel = 3,
};


enum ES_WeatherMonitorStatus
{
    ES_WMS_NotConnected = 0,
    ES_WMS_ReadOnly = 1,
    ES_WMS_ReadAndCalculateRefractions = 2,
};


enum ES_SystemStatusChange
{
    ES_SSC_DistanceSet = 0,                        
    ES_SSC_LaserWarmedUp = 1,                      
                                                   
    
    ES_SSC_EnvironmentParamsChanged = 2,
    ES_SSC_RefractionParamsChanged = 3,
    ES_SSC_SearchParamsChanged = 4,
    ES_SSC_AdmParamsChanged = 5,
    ES_SSC_UnitsChanged = 6,
    ES_SSC_ReflectorChanged = 7,
    ES_SSC_SystemSettingsChanged = 8,
    ES_SSC_TemperatureRangeChanged = 9,
    ES_SSC_CameraParamsChanged = 10,
    ES_SSC_CompensationChanged = 11,
    ES_SSC_CoordinateSystemTypeChanged = 12,
    ES_SSC_BoxRegionParamsChanged = 13,            
    ES_SSC_SphereRegionParamsChanged = 14,         
    ES_SSC_StationOrientationParamsChanged = 15,
    ES_SSC_TransformationParamsChanged = 16,
    ES_SSC_MeasurementModeChanged = 17,
    ES_SSC_StationaryModeParamsChanged = 18,
    ES_SSC_ContinuousTimeModeParamsChanged = 19,
    ES_SSC_ContinuousDistanceModeParamsChanged = 20,
    ES_SSC_GridModeParamsChanged = 21,             
    ES_SSC_CircleCenterModeParamsChanged = 22,     
    ES_SSC_SphereCenterModeParamsChanged = 23,     
    ES_SSC_StatisticModeChanged = 24,
    ES_SSC_MeasStatus_NotReady = 25,
    ES_SSC_MeasStatus_Busy = 26,
    ES_SSC_MeasStatus_Ready = 27,
    ES_SSC_MeasurementCountReached = 28,
    ES_SSC_TriggerSourceChanged = 29,              
    ES_SSC_IsFace1 = 30,
    ES_SSC_IsFace2 = 31,
    ES_SSC_ExternalControlActive = 32,             
    ES_SSC_ServiceSoftwareActive = 33,             
    ES_SSC_MeasurementCameraChanged = 34,          
    ES_SSC_MeasurementCameraModeChanged = 35,      
    ES_SSC_ProbeChanged = 36,
    ES_SSC_TipChanged = 37,                        
    ES_SSC_TCamToTrackerCompensationChanged = 38,  
    ES_SSC_ProbeCompensationChanged = 39,          
    ES_SSC_TipToProbeCompensationChanged = 40,     
    ES_SSC_ExternTriggerParamsChanged = 41,        
    ES_SSC_TCamToTrackerCompensationDeleted = 42,  
    ES_SSC_MeasurementProbeCompensationDeleted = 43, 
    ES_SSC_MeasurementTipCompensationDeleted = 44, 
    ES_SSC_ManyMechanicalCompensationsInDB = 45,   
    ES_SSC_MeasStatus_6DStatusInvalid = 99,
    ES_SSC_MeasurementProbeButtonDown = 100,       
    ES_SSC_MeasurementProbeButtonUp = 101,         
    ES_SSC_ExternalTriggerEvent = 102,             
    ES_SSC_ExternalTriggerStartEvent = 103,        
    ES_SSC_ExternalTriggerStopEvent = 104,         
    ES_SSC_ObjectTemperatureChanged = 105,               
    ES_SSC_OverviewCameraChanged = 106,            
    ES_SSC_NivelSensorChanged = 107,               
    ES_SSC_ProbeButton1Down = 110,
    ES_SSC_ProbeButton1Up = 111,
    ES_SSC_ProbeButton1DoubleClick = 112,          
    ES_SSC_ProbeButton2Down = 120,
    ES_SSC_ProbeButton2Up = 121,
    ES_SSC_ProbeButton2DoubleClick = 122,          
    ES_SSC_ProbeButton3Down = 130,
    ES_SSC_ProbeButton3Up = 131,
    ES_SSC_ProbeButton3DoubleClick = 132,          
    ES_SSC_ProbeButton4Down = 140,
    ES_SSC_ProbeButton4Up = 141,
    ES_SSC_ProbeButton4DoubleClick = 142,          
                                                   
    
    ES_SSC_QuickReleaseOpend = 143,                
    ES_SSC_QuickReleaseClosed = 144,               
    ES_SSC_LaserReachingLimit = 145,               
    ES_SSC_LaserNotStabilized = 146,               
                                                   
    
    ES_SSC_MultipleTipAdapterConnected = 150,      
    
    
    ES_SSC_InitializationStatusChanged = 151,      
    ES_SCC_InitializationStatusChanged = ES_SSC_InitializationStatusChanged, 
    ES_SSC_TiltSensorStatusChanged = 152,          
    ES_SCC_TiltSensorStatusChanged = ES_SSC_TiltSensorStatusChanged, 


    
    ES_SSC_CompensationModeStart = 800,            
    ES_SSC_CompensationModeEnd = 801,              
    ES_SSC_EmsysFilesImported = 820,

    
    ES_SSC_SensorDetected = 850,     
    ES_SSC_SensorDisconnected = 851,

    
    ES_SSC_CompensatorStatusChanged = 852,         
    ES_SSC_BatteryStatusChanged = 853,             

    
    ES_SSC_CopyProtectionRemoved = 996,            
    ES_SSC_TPConnectionClosing = 997,
    ES_SSC_ServerClosing = 998,
    ES_SSC_ServerStarted = 999,
};


enum ES_NivelPosition
{
    ES_NP_Pos1 = 0,
    ES_NP_Pos2 = 1,
    ES_NP_Pos3 = 2,
    ES_NP_Pos4 = 3,
};


enum ES_RegionType
{
    ES_RT_Sphere = 0,                              
    ES_RT_Box = 1,                                 
    ES_RT_NA = 10,                                 
};


enum ES_StatisticMode
{
    ES_SM_Standard = 0,
    ES_SM_Extended = 1,
};


enum ES_StillImageFileType
{
    ES_SI_Bitmap = 0,
    ES_SI_Jpeg = 1,
};


enum ES_TransResultType
{
    ES_TR_AsTransformation = 0,
    ES_TR_AsOrientation = 1,
};


enum ES_TrackerProcessorType
{
    ES_TT_Undefined = 0,
    ES_TT_SMART310 = 1,                            
    ES_TT_LT_Controller = 2,                       
    ES_TT_EmbeddedController = 3,                  
    ES_TT_EmbeddedController600 = 4,               
    ES_TT_ATC900 = 6,                              
    ES_TT_ATC400 = 20,
};


enum ES_TPMicroProcessorType
{
    ES_TPM_Undefined = 0,
    ES_TPM_i486 = 1,                               
    ES_TPM_686 = 2,                                
    ES_TPM_PXA250 = 20,
    ES_TPM_PXA250_PCB_V4 = 21,
};


enum ES_LTSensorType
{
    ES_LTS_Undefined = 0,
    ES_LTS_SMARTOptodyne = 1,                      
    ES_LTS_SMARTLeica = 2,                         
    ES_LTS_LT_D_500 = 3,                           
    ES_LTS_LT300 = 4,                              
    ES_LTS_LT301 = 5,                              
    ES_LTS_LT_D_800 = 6,                           
    ES_LTS_LT_D_700 = 7,                           
    ES_LTS_LT_D_600 = 8,                           
    ES_LTS_LT_D_640 = 9,                           
    ES_LTS_LT_D_706 = 10,                          
    ES_LTS_LT_D_709 = 11,                          
    ES_LTS_LT_D_840 = 12,                          
    ES_LTS_AT901_B  = 13,                          
    ES_LTS_AT901_MR = 14,                          
    ES_LTS_AT901_LR = 15,                          
    ES_LTS_AT401 = 70,
    ES_LTS_AT402 = 72,
    ES_LTS_AT403 = 73,
    ES_LTS_NoSensor = 99,
};


enum ES_TriggerSource
{
    ES_TS_Undefined = 0,
    ES_TS_Internal_Application = 1,                
    ES_TS_External = 2,
    ES_TS_External_EventMessage = 3,
};


enum ES_DisplayCoordinateConversionType
{
    ES_DCC_BaseToCurrent = 0,
    ES_DCC_CurrentToBase = 1,
};


enum ES_TrackerFace
{
    ES_TF_Unknown = 0,
    ES_TF_Face1 = 1,
    ES_TF_Face2 = 2,
};


enum ES_MeasurementCameraMode
{  
   ES_MCM_Measure = 0,  
   ES_MCM_Overview = 1,
};


enum ES_MeasurementCameraType
{  
   ES_MC_None = 0,
   ES_MC_TCam700 = 1,
   ES_MC_TCam800 = 2,
   ES_MC_TCam706 = 3,
   ES_MC_TCam709 = 4,
   ES_MC_TCam_LR = 5,
   ES_MC_TCam_MR = 6,
   ES_MC_TCam_XR = 7,
};


enum ES_ProbeType
{  
   ES_PT_None = 0,
   ES_PT_Reflector = 1,
   ES_PT_TProbe = 2,                       
   ES_PT_TScan = 3,                        
   ES_PT_MachineControlProbe = 4,          
   ES_PT_MachineControlProbeMultiSide = 5, 
   ES_PT_BProbe = 6,
   ES_PT_LAS = 7,                          
   ES_PT_TMC30E = 8,                       
   ES_PT_TCamToTrackerTool = 100,          
   ES_PT_ZoomArtifactTool = 200,           
};


enum ES_ProbeConnectionType
{  
   ES_PCT_None = 0,
   ES_PCT_CableController = 1, 
   ES_PCT_CableSensor = 2,     
   ES_PCT_IRLaser = 3,         
   ES_PCT_IRWideAngle = 4,     
};

enum ES_ProbeButtonType
{
   ES_PBT_None = 0,
   ES_PBT_Measurement = 1,     
   ES_PBT_4Button = 2,             
};


enum ES_SocketType
{
    ES_ST_Accurate = 0,                            
    ES_ST_ThreadWithID = 100,                      
    ES_ST_Thread = 200,                            
    ES_ST_Virtual = 999,                         
};

enum ES_TipType
{  
   ES_TT_None = 0,
   ES_TT_Fixed = 1,                                
   ES_TT_Scanner = 2,                              
   ES_TT_TouchTrigger = 3,                         
   ES_TT_OpticalTrigger = 4,                       
   ES_TT_ThreadWithID_Fixed = ES_ST_ThreadWithID + ES_TT_Fixed,                   
   ES_TT_ThreadWithID_Scanner = ES_ST_ThreadWithID + ES_TT_Scanner,               
   ES_TT_ThreadWithID_TouchTrigger = ES_ST_ThreadWithID + ES_TT_TouchTrigger,     
   ES_TT_ThreadWithID_OpticalTrigger = ES_ST_ThreadWithID + ES_TT_OpticalTrigger, 
   ES_TT_Thread = ES_ST_Thread,                                                   
   ES_TT_Virtual = ES_ST_Virtual,                                                 
   ES_TT_PassiveTip = 400, 
};


enum ES_ClockTransition
{
   ES_CT_Positive = 1,
   ES_CT_Negative = 0,
};

enum ES_TriggerMode
{
   ES_TM_EventTrigger = 0,
   ES_TM_ContinuousExternalClockWithStartStop = 1,
   ES_TM_InternalClockWithExternalStartStop = 2,
};

enum ES_TriggerStartSignal
{
   ES_TSS_High = 1,
   ES_TSS_Low = 0,
};


enum ES_ProbeConfigButton
{
    ES_PCB_SingleClick = 0,
    ES_PCB_StartStop = 1,    
    ES_PCB_4ButtonMode = 2,                        
};

enum ES_ProbeButtonEvent
{
    ES_PBE_DisableEvents = 0,                      
    ES_PBE_EnableEvents = 1,                       
};

enum ES_ProbeConfigTip
{
    ES_PCT_OnlyWithTip = 0,
    ES_PCT_NoTipAllowed = 1,
    ES_PCT_OnlyWithShankCompensation = 2,          
};

enum ES_QuickReleaseStatus
{
    ES_QRS_NotExisting = -1,                       
    ES_QRS_Closed = 0,
    ES_QRS_Open = 1,
};


enum ES_PowerLockMode
{
    ES_PLM_InDoor = 0,                             
    ES_PLM_OutDoor = 1,                            
    ES_PLM_OutDoor_LongRange = 2,                  
};

enum ES_SystemParameter
{
    ES_SP_KeepLastPositionFlag = 0,                
    ES_SP_WeatherMonitorSetting = 1,               
    ES_SP_ShowAll6DMeasurements = 2,               
    ES_SP_LaserPointerCaptureBeam = 3,             
    ES_SP_DisplayReflectorPosition = 10,           
    ES_SP_ProbeConfig_Button = 50,                 
    ES_SP_ProbeConfig_ButtonEvent = 51,            
    ES_SP_ProbeConfig_Tip = 52,                    
    ES_SP_ProbeConfig_SoundVolume = 53,            
    ES_SP_ProbeConfig_PowerOffTime = 54,           
    ES_SP_QuickReleaseStatus = 60,                 
    ES_SP_TcpCommandQueueSize = 200,               
    ES_SP_SystemMax6DDataRate = 300,               
    ES_SP_TcpDataPacketRate = 400,                 
    ES_SP_PowerLockFunctionAvailable = 410,        
    ES_SP_PowerLockFunctionActive = 411,           
    ES_SP_PowerLockMode = 450,                     
    ES_SP_D_TemperatureThreshold = 1000,           
    ES_SP_D_PressureThreshold = 1001,              
    ES_SP_D_HumidityThreshold = 1002,              
    ES_SP_D_SystemLongest3DDistanceIFM = 1100,     
    ES_SP_D_SystemLongest3DDistanceADM = 1101,     
    ES_SP_D_SystemLongest6DDistance = 1102,        
    ES_SP_ControllerBatteryStatus = 5000,          
    ES_SP_AT4xxControllerBatteryStatus = ES_SP_ControllerBatteryStatus, 
    ES_SP_SensorBatteryStatus = 5001,              
    ES_SP_AT4xxSensorBatteryStatus = ES_SP_SensorBatteryStatus, 
    ES_SP_InclinationSensorState = 5002,           
    ES_SP_AT4xxInclinationSensorState = ES_SP_InclinationSensorState, 
    ES_SP_ReflectorTiltDetection = 5003,           
    ES_SP_AT4xxReflectorTiltDetection = ES_SP_ReflectorTiltDetection, 
    ES_SP_StableProbingTrigger = 5004,             
    ES_SP_TwoFaceAverageMode = 5005,               
    ES_SP_StableProbingCriteriaTime = 5006,        
    ES_SP_PowerOverrideSupported = 5010,           
    ES_SP_PowerOverrideEnabled = 5011,             
    ES_SP_InitializationQualityCheckMode = 5020,   
    ES_SP_D_StableProbingCriteriaRegion= 6000,     
};

enum ES_MeasurementStatusInfo
{
    ES_MSI_Unknown = 0,
    ES_MSI_TrackerFound = 1,
    ES_MSI_TrackerCompensationFound = 2,
    ES_MSI_ADMFound = 4,
    ES_MSI_ADMCompensationFound = 8,
    ES_MSI_MeasurementCameraFound = 16,
    ES_MSI_InternalCameraParamsOK = 32,
    ES_MSI_CameraToTrackerParamsFound = 64,         
    ES_MSI_MeasurementProbeFound = 128,
    ES_MSI_ProbeParamsFound = 256,
    ES_MSI_MeasurementTipFound = 512,
    ES_MSI_TipParamsFound = 1024,
    ES_MSI_ReflectorFound = 2048,
    ES_MSI_InFace1 = 4096,
    ES_MSI_ShankParamsFound = 8192,                 
    ES_MSI_SensorBatteryMounted = 16384,
    ES_MSI_NivelInWorkingRange = 32768,
    ES_MSI_Initialized = 65536,
};

enum ES_ClearCommandQueueType
{
    ES_CCQ_ClearOwnOnly = 0,                       
    ES_CCQ_ClearAll = 1,                           
};

enum ES_OverviewCameraType
{
    ES_OCT_Unknown = 0,
    ES_OCT_Classic = 1,                            
    ES_OCT_TCam_Integrated = 2,                    
    ES_OCT_AT_Integrated = 20,                     
    ES_OCT_AT4xx_Integrated = ES_OCT_AT_Integrated,
};

enum ES_TriggerCardType
{
    ES_TCT_None = 0,
    ES_TCT_SingleTracker = 1,
};

enum ES_ADMType
{
    ES_AMT_Unknown = 0,
    ES_AMT_LeicaADM = 1,                           
    ES_AMT_LeicaAIFM = 2,                          
    ES_AMT_LeicaADM2 = 3,                          
    ES_AMT_LeicaADM3 = 4,                          
};

enum ES_ATRType
{
    ES_ATR_None = 0,
    ES_ATR_4 = 1,
    ES_ATR_5i = 2,                                 
};

enum ES_TrkAccuracyModel
{
    ES_TAM_Unknown = 0,
    ES_TAM_2005 = 1,
};

enum ES_NivelType
{
    ES_NT_Unknown = 0,
    ES_NT_Nivel20 = 1,                              
    ES_NT_Nivel230 = 2,                            
    ES_NT_NivelAT = 3,                             
    ES_NT_NivelAT4xx = ES_NT_NivelAT,              
};

enum ES_TipToProbeCompensationType
{
    ES_TCT_Unknown = 0,
    ES_TCT_TipOnly = 1,
    ES_TCT_ShankEnabled = 2,  
};

enum ES_MeteoStationType
{
    ES_MST_None = 0,
    ES_MST_Thommen = 1,
    ES_MST_AT = 2,
};

enum ES_WLANType
{
    ES_WLAN_None = 0,
    ES_WLAN_BGW211 = 1,
    ES_WLAN_OWL221a = 2,
    ES_WLAN_Morin = 3,
};

enum ES_InclinationSensorState
{
    ES_ISS_Off = 0,
    ES_ISS_ApplyCorrections = 2,
};

enum ES_InitializationQualityCheckMode
{
    ES_IQM_OnlyGood = 0,
    ES_IQM_Warning = 1,
};








struct PacketHeaderT
{
    long             lPacketSize;
    enum ES_DataType type;
};


struct ReturnDataT
{
    struct PacketHeaderT packetHeader;
    enum ES_ResultStatus status;   
};


struct BasicCommandCT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
};

struct BasicCommandRT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
    enum ES_ResultStatus status;
};


struct RotationStatus
{
    unsigned Status6D:1;                           
    unsigned Error6D:1;                            
    unsigned NotEnoughLED:1;                       
    unsigned RMSToHigh:1;                          
    unsigned AngleOutOfRange:1;                    
    unsigned Frozen6DValues:1;                     
    unsigned DistanceOutOfRange:1;                 
    unsigned Reserved1:1;                          
    unsigned RotStatLeftRight:3;                   
    unsigned RotStatUpDown:3;                      
    unsigned GoodGauge:2;                          
    unsigned Face2:1;                              
    unsigned Reserved2:1;                          
    unsigned NumOfLedsUsedChanged:1;               
    unsigned NumOfLedsUsedInCalc:4;                
    unsigned Reserved3:9;                          
};

union URotationStatus
{
    long                  l;
    struct RotationStatus rotStat;
};



struct NivelResultT
{
    struct ReturnDataT  packetInfo;
    enum ES_NivelStatus nivelStatus;
    double              dXTilt;
    double              dYTilt;
    double              dNivelTemperature;
};


struct ReflectorPosResultT
{
    struct ReturnDataT packetInfo;
    double             dVal1;
    double             dVal2;
    double             dVal3;
};




struct ProbePosResultT
{
    struct ReturnDataT           packetInfo;
    long                         lRotationStatus;
    enum ES_MeasurementTipStatus tipStatus;
    int                          iInternalTipAdapterId;
    int                          iTipAdapterInterface;
    double                       dPosition1;
    double                       dPosition2;
    double                       dPosition3;
    double                       dQuaternion0;
    double                       dQuaternion1;
    double                       dQuaternion2;
    double                       dQuaternion3;
    double                       dRotationAngleX;
    double                       dRotationAngleY;
    double                       dRotationAngleZ;
};


struct SingleMeasResultT
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dVal1;
    double             dVal2;
    double             dVal3;
    double             dStd1;
    double             dStd2;
    double             dStd3;
    double             dStdTotal;
    double             dPointingError1;
    double             dPointingError2;
    double             dPointingError3;
    double             dAprioriStd1;
    double             dAprioriStd2;
    double             dAprioriStd3;
    double             dAprioriStdTotal;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
};


struct SingleMeasResult2T
{
    struct ReturnDataT packetInfo;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dVal1;
    double             dVal2;
    double             dVal3;
    double             dStd1;
    double             dStd2;
    double             dStd3;
    double             dStdTotal;
    double             dCovar12;
    double             dCovar13;
    double             dCovar23;
    double             dPointingErrorH;
    double             dPointingErrorV;
    double             dPointingErrorD;
    double             dAprioriStd1;
    double             dAprioriStd2;
    double             dAprioriStd3;
    double             dAprioriStdTotal;
    double             dAprioriCovar12;
    double             dAprioriCovar13;
    double             dAprioriCovar23;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
};


struct MeasValueT
{
    enum ES_MeasurementStatus status;
    long                      lTime1;
    long                      lTime2;
    double                    dVal1;
    double                    dVal2;
    double                    dVal3;
};


struct MeasValue2T
{
    enum ES_MeasurementStatus status;
    long                      lTime1;
    long                      lTime2;
    double                    dVal1;
    double                    dVal2;
    double                    dVal3;
    double                    dAprioriStd1;
    double                    dAprioriStd2;
    double                    dAprioriStd3;
    double                    dAprioriStdTotal;
    double                    dAprioriCovar12;
    double                    dAprioriCovar13;
    double                    dAprioriCovar23;
};


struct MultiMeasResultT
{
    struct ReturnDataT packetInfo;
    long               lNumberOfResults;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
    struct MeasValueT  data[1];                    
};


struct MultiMeasResult2T
{
    struct ReturnDataT packetInfo;
    long               lNumberOfResults;
    enum ES_MeasMode   measMode;
    int            bIsTryMode;
    double             dTemperature;
    double             dPressure;
    double             dHumidity;
    struct MeasValue2T data[1];                    
};                         












struct ProbeStationaryResultT
{
    struct ReturnDataT           packetInfo;
    enum ES_MeasMode             measMode;
    int                      bIsTryMode;
    enum ES_TriggerStatus        triggerStatus;
    long                         lRotationStatus;
    int                          iInternalProbeId;        
    int                          iFieldNumber;        
    enum ES_MeasurementTipStatus tipStatus;
    int                          iInternalTipAdapterId;
    int                          iTipAdapterInterface;
    double                       dPosition1;
    double                       dPosition2;
    double                       dPosition3;
    double                       dStdDevPosition1;
    double                       dStdDevPosition2;
    double                       dStdDevPosition3;
    double                       dStdDevPositionTotal;
    double                       dCovarPosition12;
    double                       dCovarPosition13;
    double                       dCovarPosition23;
    double                       dAprioriStdDevPosition1;
    double                       dAprioriStdDevPosition2;
    double                       dAprioriStdDevPosition3;
    double                       dAprioriStdDevPositionTotal;
    double                       dAprioriCovarPosition12;
    double                       dAprioriCovarPosition13;
    double                       dAprioriCovarPosition23;
    double                       dQuaternion0;
    double                       dQuaternion1;
    double                       dQuaternion2;
    double                       dQuaternion3;
    double                       dRotationAngleX;
    double                       dRotationAngleY;
    double                       dRotationAngleZ;
    double                       dStdDevRotationAngleX;
    double                       dStdDevRotationAngleY;
    double                       dStdDevRotationAngleZ;
    double                       dStdDevRotationAngleTotal; 
    double                       dCovarRotationAngleXY;
    double                       dCovarRotationAngleXZ;
    double                       dCovarRotationAngleYZ;
    double                       dAprioriStdDevRotationAngleX;
    double                       dAprioriStdDevRotationAngleY;
    double                       dAprioriStdDevRotationAngleZ;
    double                       dAprioriStdDevRotationAngleTotal; 
    double                       dAprioriCovarRotationAngleXY;
    double                       dAprioriCovarRotationAngleXZ;
    double                       dAprioriCovarRotationAngleYZ;
    double                       dTemperature;
    double                       dPressure;
    double                       dHumidity;
}; 




struct ProbeMeasValueT
{
    enum ES_MeasurementStatus status;
    enum ES_TriggerStatus     triggerStatus;   
    long                      lRotationStatus;     
    long                      lTime1;
    long                      lTime2;
    double                    dPosition1;
    double                    dPosition2;
    double                    dPosition3;
    double                    dStdDevPosition1;
    double                    dStdDevPosition2;
    double                    dStdDevPosition3;
    double                    dStdDevPositionTotal;
    double                    dCovarPosition12;
    double                    dCovarPosition13;
    double                    dCovarPosition23;
    double                    dQuaternion0;
    double                    dQuaternion1;
    double                    dQuaternion2;
    double                    dQuaternion3;
    double                    dRotationAngleX;
    double                    dRotationAngleY;
    double                    dRotationAngleZ;
    double                    dStdDevRotationAngleX;
    double                    dStdDevRotationAngleY;
    double                    dStdDevRotationAngleZ;
    double                    dStdDevRotationAngleTotal;
    double                    dCovarRotationAngleXY;
    double                    dCovarRotationAngleXZ;
    double                    dCovarRotationAngleYZ;
};




struct ProbeContinuousResultT
{
    struct ReturnDataT           packetInfo;
    long                         lNumberOfResults;
    enum ES_MeasMode             measMode;
    int                      bIsTryMode;
    int                          iInternalProbeId;
    int                          iFieldNumber;        
    enum ES_MeasurementTipStatus tipStatus;
    int                          iInternalTipAdapterId;
    int                          iTipAdapterInterface;
    double                       dTemperature;
    double                       dPressure;
    double                       dHumidity;
    struct ProbeMeasValueT       data[1];          
};


struct SystemStatusChangeT
{
    struct PacketHeaderT       packetHeader;
    enum ES_SystemStatusChange systemStatusChange;
};

struct ErrorResponseT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
    enum ES_ResultStatus status;
};





struct InitializeCT
{
    struct BasicCommandCT packetInfo;
};

struct InitializeRT
{
    struct BasicCommandRT packetInfo;
};


struct ReleaseMotorsCT
{
    struct BasicCommandCT packetInfo;
};

struct ReleaseMotorsRT
{
    struct BasicCommandRT packetInfo;
};


struct ActivateCameraViewCT
{
    struct BasicCommandCT packetInfo;
};

struct ActivateCameraViewRT
{
    struct BasicCommandRT packetInfo;
};


struct ParkCT
{
    struct BasicCommandCT packetInfo;
};

struct ParkRT
{
    struct BasicCommandRT packetInfo;
};


struct GoBirdBathCT
{
    struct BasicCommandCT packetInfo;
};

struct GoBirdBathRT
{
    struct BasicCommandRT packetInfo;
};



struct GoBirdBath2CT
{
    struct BasicCommandCT packetInfo;
    int               bClockWise;
};

struct GoBirdBath2RT
{
    struct BasicCommandRT packetInfo;
};


struct ChangeFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct ChangeFaceRT
{
    struct BasicCommandRT packetInfo;
};


struct StartNivelMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartNivelMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct StartMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StartMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct StopMeasurementCT
{
    struct BasicCommandCT packetInfo;
};

struct StopMeasurementRT
{
    struct BasicCommandRT packetInfo;
};


struct ExitApplicationCT
{
    struct BasicCommandCT packetInfo;
};

struct ExitApplicationRT
{
    struct BasicCommandRT packetInfo;
};



struct GoLastMeasuredPointCT
{
    struct BasicCommandCT packetInfo;
};

struct GoLastMeasuredPointRT
{
    struct BasicCommandRT packetInfo;
};



struct SwitchLaserCT
{
    struct BasicCommandCT packetInfo;
    int               bIsOn;
};

struct SwitchLaserRT
{
    struct BasicCommandRT packetInfo;
};



struct FindReflectorCT
{
    struct BasicCommandCT packetInfo;
    double                dAproxDistance;
};

struct FindReflectorRT
{
    struct BasicCommandRT packetInfo;
};



struct SetCoordinateSystemTypeCT
{
    struct BasicCommandCT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};

struct SetCoordinateSystemTypeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCoordinateSystemTypeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCoordinateSystemTypeRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_CoordinateSystemType coordSysType;
};



struct SetTemperatureRangeCT
{
    struct BasicCommandCT           packetInfo;
    enum ES_TrackerTemperatureRange temperatureRange;
};

struct SetTemperatureRangeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTemperatureRangeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTemperatureRangeRT
{
    struct BasicCommandRT           packetInfo;
    enum ES_TrackerTemperatureRange temperatureRange;
};



struct SetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
    enum ES_MeasMode      measMode;
};

struct SetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetMeasurementModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementModeRT
{
    struct BasicCommandRT packetInfo;
    enum ES_MeasMode      measMode;
};



struct SearchParamsDataT
{
    double dSearchRadius;
    long   lTimeOut;                               
};

struct SetSearchParamsCT
{
    struct BasicCommandCT    packetInfo;
    struct SearchParamsDataT searchParams;
};

struct SetSearchParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSearchParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSearchParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct SearchParamsDataT searchParams;
};



struct AdmParamsDataT
{
    double dTargetStabilityTolerance;
    long   lRetryTimeFrame;                        
    long   lNumberOfRetrys;
};

struct SetAdmParamsCT
{
    struct BasicCommandCT packetInfo;
    struct AdmParamsDataT admParams;
};

struct SetAdmParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetAdmParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetAdmParamsRT
{
    struct BasicCommandRT packetInfo;
    struct AdmParamsDataT admParams;
};



struct StationaryModeDataT
{
    long    lMeasTime;
    int bUseADM;                               
};

struct SetStationaryModeParamsCT
{
    struct BasicCommandCT      packetInfo;
    struct StationaryModeDataT stationaryModeData;
};

struct SetStationaryModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStationaryModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationaryModeParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct StationaryModeDataT stationaryModeData;
};



struct ContinuousTimeModeDataT
{
    long               lTimeSeparation;
    long               lNumberOfPoints;            
    int            bUseRegion;
    enum ES_RegionType regionType;    
};

struct SetContinuousTimeModeParamsCT
{
    struct BasicCommandCT          packetInfo;
    struct ContinuousTimeModeDataT continuousTimeModeData;
};

struct SetContinuousTimeModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetContinuousTimeModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetContinuousTimeModeParamsRT
{
    struct BasicCommandRT          packetInfo;
    struct ContinuousTimeModeDataT continuousTimeModeData;
};



struct ContinuousDistanceModeDataT
{
    double             dSpatialDistance;
    long               lNumberOfPoints;            
    int            bUseRegion;
    enum ES_RegionType regionType;    
};

struct SetContinuousDistanceModeParamsCT
{
    struct BasicCommandCT              packetInfo;
    struct ContinuousDistanceModeDataT continuousDistanceModeData;
};

struct SetContinuousDistanceModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetContinuousDistanceModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetContinuousDistanceModeParamsRT
{
    struct BasicCommandRT              packetInfo;
    struct ContinuousDistanceModeDataT continuousDistanceModeData;
};



struct SphereCenterModeDataT
{
    double  dSpatialDistance;
    long    lNumberOfPoints;                       
    int bFixRadius;
    double  dRadius;
};

struct SetSphereCenterModeParamsCT
{
    struct BasicCommandCT        packetInfo;
    struct SphereCenterModeDataT sphereCenterModeData;
};

struct SetSphereCenterModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSphereCenterModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSphereCenterModeParamsRT
{
    struct BasicCommandRT        packetInfo;
    struct SphereCenterModeDataT sphereCenterModeData;
};



struct CircleCenterModeDataT
{
    double  dSpatialDistance;
    long    lNumberOfPoints;                       
    int bFixRadius;
    double  dRadius;
};

struct SetCircleCenterModeParamsCT
{
    struct BasicCommandCT        packetInfo;
    struct CircleCenterModeDataT circleCenterModeData;
};

struct SetCircleCenterModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCircleCenterModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCircleCenterModeParamsRT
{
    struct BasicCommandRT        packetInfo;
    struct CircleCenterModeDataT circleCenterModeData;
};



struct GridModeDataT
{
    double             dVal1;
    double             dVal2;
    double             dVal3;
    long               lNumberOfPoints;            
    int            bUseRegion;
    enum ES_RegionType regionType;    
};

struct SetGridModeParamsCT
{
    struct BasicCommandCT packetInfo;
    struct GridModeDataT  gridModeData;
};

struct SetGridModeParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetGridModeParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetGridModeParamsRT
{
    struct BasicCommandRT packetInfo;
    struct GridModeDataT  gridModeData;
};



struct SystemSettingsDataT
{
    enum ES_WeatherMonitorStatus weatherMonitorStatus;
    int                      bApplyTransformationParams;
    int                      bApplyStationOrientationParams;
    int                      bKeepLastPosition;
    int                      bSendUnsolicitedMessages;
    int                      bSendReflectorPositionData;
    int                      bTryMeasurementMode;
    int                      bHasNivel;
    int                      bHasVideoCamera;
};                                  

struct SetSystemSettingsCT
{
    struct BasicCommandCT      packetInfo;
    struct SystemSettingsDataT systemSettings;
};

struct SetSystemSettingsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSystemSettingsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSettingsRT
{
    struct BasicCommandRT      packetInfo;
    struct SystemSettingsDataT systemSettings;
};



struct SystemUnitsDataT
{
    enum ES_LengthUnit      lenUnitType;
    enum ES_AngleUnit       angUnitType;
    enum ES_TemperatureUnit tempUnitType;
    enum ES_PressureUnit    pressUnitType;
    enum ES_HumidityUnit    humUnitType;
};

struct SetUnitsCT
{
    struct BasicCommandCT   packetInfo;
    struct SystemUnitsDataT unitsSettings;
};

struct SetUnitsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetUnitsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetUnitsRT
{
    struct BasicCommandRT   packetInfo;
    struct SystemUnitsDataT unitsSettings;
};



struct ESVersionNumberT
{
    int iMajorVersionNumber;
    int iMinorVersionNumber;
    int iBuildNumber;
    
};

struct GetSystemStatusCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemStatusRT
{
    struct BasicCommandRT          packetInfo;
    enum ES_ResultStatus           lastResultStatus;
    enum ES_TrackerProcessorStatus trackerProcessorStatus;
    enum ES_LaserProcessorStatus   laserStatus;
    enum ES_ADMStatus              admStatus;
    struct ESVersionNumberT        esVersionNumber;
    enum ES_WeatherMonitorStatus   weatherMonitorStatus;
    long                           lFlagsValue;                     
    long                           lTrackerSerialNumber;
};                                



struct GetMeasurementStatusInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementStatusInfoRT
{
    struct BasicCommandRT packetInfo;
    enum ES_ResultStatus  lastResultStatus;
    long                  lMeasurementStatusInfo;
};                                



struct GetTrackerStatusCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerStatusRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerStatus trackerStatus;
};



struct SetReflectorCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalReflectorId;
};

struct SetReflectorRT
{
    struct BasicCommandRT packetInfo;
};



struct GetReflectorsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetReflectorsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalReflectors;
    int                   iInternalReflectorId;
    enum ES_TargetType    targetType;
    double                dSurfaceOffset;
    unsigned short        cReflectorName[32];      
};



struct GetReflectorCT
{
    struct BasicCommandCT packetInfo;
};

struct GetReflectorRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalReflectorId;
};



struct EnvironmentDataT
{
    double dTemperature;
    double dPressure;
    double dHumidity;
};

struct SetEnvironmentParamsCT
{
    struct BasicCommandCT   packetInfo;
    struct EnvironmentDataT environmentData;
};

struct SetEnvironmentParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetEnvironmentParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetEnvironmentParamsRT
{
    struct BasicCommandRT   packetInfo;
    struct EnvironmentDataT environmentData;
};



struct RefractionDataT
{
    double dIfmRefractionIndex;
    double dAdmRefractionIndex;
};

struct SetRefractionParamsCT
{
    struct BasicCommandCT  packetInfo;
    struct RefractionDataT refractionData;
};

struct SetRefractionParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetRefractionParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetRefractionParamsRT
{
    struct BasicCommandRT  packetInfo;
    struct RefractionDataT refractionData;
};



struct StationOrientationDataT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dRot1;
    double dRot2;
    double dRot3;
};

struct SetStationOrientationParamsCT
{
    struct BasicCommandCT          packetInfo;
    struct StationOrientationDataT stationOrientation;
};

struct SetStationOrientationParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStationOrientationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStationOrientationParamsRT
{
    struct BasicCommandRT          packetInfo;
    struct StationOrientationDataT stationOrientation;
};



struct TransformationDataT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dRot1;
    double dRot2;
    double dRot3;
    double dScale;
};

struct SetTransformationParamsCT
{
    struct BasicCommandCT      packetInfo;
    struct TransformationDataT transformationData;
};

struct SetTransformationParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTransformationParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTransformationParamsRT
{
    struct BasicCommandRT      packetInfo;
    struct TransformationDataT transformationData;
};



struct BoxRegionDataT
{
    double dP1Val1;
    double dP1Val2;
    double dP1Val3;
    double dP2Val1;
    double dP2Val2;
    double dP2Val3;
};

struct SetBoxRegionParamsCT
{
    struct BasicCommandCT packetInfo;
    struct BoxRegionDataT boxRegionData;
};

struct SetBoxRegionParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetBoxRegionParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetBoxRegionParamsRT
{
    struct BasicCommandRT packetInfo;
    struct BoxRegionDataT boxRegionData;
};



struct SphereRegionDataT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dRadius;
};

struct SetSphereRegionParamsCT
{
    struct BasicCommandCT    packetInfo;
    struct SphereRegionDataT sphereRegionData;
};

struct SetSphereRegionParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetSphereRegionParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSphereRegionParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct SphereRegionDataT sphereRegionData;
};



struct GoPositionCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
    int               bUseADM;
};

struct GoPositionRT
{
    struct BasicCommandRT packetInfo;
};



struct LookForTargetCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
    double                dSearchRadius;
};

struct LookForTargetRT
{
    struct BasicCommandRT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
};



struct GetDirectionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetDirectionRT
{
    struct BasicCommandRT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
};



struct GoPositionHVDCT
{
    struct BasicCommandCT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
    double                dDistance;
    int               bUseADM;
};

struct GoPositionHVDRT
{
    struct BasicCommandRT packetInfo;
};



struct PointLaserCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};

struct PointLaserRT
{
    struct BasicCommandRT packetInfo;
};



struct PositionRelativeHVCT
{
    struct BasicCommandCT packetInfo;
    double                dHzVal;
    double                dVtVal;
};

struct PositionRelativeHVRT
{
    struct BasicCommandRT packetInfo;
};



struct PointLaserHVDCT
{
    struct BasicCommandCT packetInfo;
    double                dHzAngle;
    double                dVtAngle;
    double                dDistance;
};

struct PointLaserHVDRT
{
    struct BasicCommandRT packetInfo;
};



struct MoveHVCT
{
    struct BasicCommandCT packetInfo;
    int                   iHzSpeed;
    int                   iVtSpeed;
};

struct MoveHVRT
{
    struct BasicCommandRT packetInfo;
};



struct GoNivelPositionCT
{
    struct BasicCommandCT packetInfo;
    enum ES_NivelPosition nivelPosition;
};

struct GoNivelPositionRT
{
    struct BasicCommandRT packetInfo;
};



struct CallOrientToGravityCT
{
    struct BasicCommandCT packetInfo;
};

struct CallOrientToGravityRT
{
    struct BasicCommandRT packetInfo;
    double                dOmega;
    double                dPhi;
};



struct CallIntermediateCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct CallIntermediateCompensationRT
{
    struct BasicCommandRT packetInfo;
    double                dTotalRMS;
    double                dMaxDev;
    long                  lWarningFlags;
};



struct CallTransformationCT
{
    struct BasicCommandCT packetInfo;
};

struct CallTransformationRT
{
    struct BasicCommandRT packetInfo;
    double                dTransVal1;
    double                dTransVal2;
    double                dTransVal3;
    double                dRotVal1;
    double                dRotVal2;
    double                dRotVal3;
    double                dScale;
    double                dTransStdVal1;
    double                dTransStdVal2;
    double                dTransStdVal3;
    double                dRotStdVal1;
    double                dRotStdVal2;
    double                dRotStdVal3;
    double                dScaleStd;
    double                dRMS;
    double                dMaxDev;
    double                dVarianceFactor;
};                            



struct TransformationInputDataT
{
    enum ES_TransResultType resultType;  
    double                  dTransVal1;
    double                  dTransVal2;
    double                  dTransVal3;
    double                  dRotVal1;
    double                  dRotVal2;
    double                  dRotVal3;
    double                  dScale;
    double                  dTransStdVal1;
    double                  dTransStdVal2;
    double                  dTransStdVal3;
    double                  dRotStdVal1;
    double                  dRotStdVal2;
    double                  dRotStdVal3;
    double                  dScaleStd;
};



struct SetTransformationInputParamsCT
{
    struct BasicCommandCT           packetInfo;
    struct TransformationInputDataT transformationData;
};

struct SetTransformationInputParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTransformationInputParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTransformationInputParamsRT
{
    struct BasicCommandRT           packetInfo;
    struct TransformationInputDataT transformationData;
};



struct ClearTransformationNominalPointListCT
{
    struct BasicCommandCT packetInfo;
};

struct ClearTransformationNominalPointListRT
{
    struct BasicCommandRT packetInfo;
};



struct ClearTransformationActualPointListCT
{
    struct BasicCommandCT packetInfo;
};

struct ClearTransformationActualPointListRT
{
    struct BasicCommandRT packetInfo;
};



struct TransformationPointT
{
    double dVal1;
    double dVal2;
    double dVal3;
    double dStd1;
    double dStd2;
    double dStd3;   
    double dCovar12;
    double dCovar13;
    double dCovar23;   
};



struct AddTransformationNominalPointCT
{
    struct BasicCommandCT       packetInfo;
    struct TransformationPointT transformationPoint;
};

struct AddTransformationNominalPointRT
{
    struct BasicCommandRT packetInfo;
};



struct AddTransformationActualPointCT
{
    struct BasicCommandCT        packetInfo;
    struct TransformationPointT transformationPoint;
};

struct AddTransformationActualPointRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTransformedPointsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTransformedPointsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalPoints;
    double                dVal1;
    double                dVal2;
    double                dVal3;
    double                dStd1;
    double                dStd2;
    double                dStd3;
    double                dStdTotal;
    double                dCovar12;
    double                dCovar13;
    double                dCovar23;
    double                dResidualVal1;
    double                dResidualVal2;
    double                dResidualVal3;   
};



struct ClearDrivePointListCT
{
    struct BasicCommandCT packetInfo;
};

struct ClearDrivePointListRT
{
    struct BasicCommandRT packetInfo;
};



struct AddDrivePointCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalReflectorId;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};

struct AddDrivePointRT
{
    struct BasicCommandRT packetInfo;
};



struct SetCompensationCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalCompensationId;
};

struct SetCompensationRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalCompensationId;
};



struct GetCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];      
    unsigned short        cTrackerCompensationComment[128];  
    unsigned short        cADMCompensationName[32];          
    int               bHasMeasurementCameraMounted;      
};



struct GetCompensations2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetCompensations2RT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalCompensationId;
    unsigned short        cTrackerCompensationName[32];      
    unsigned short        cTrackerCompensationComment[128];  
    unsigned short        cADMCompensationName[32];          
    unsigned short        cADMCompensationComment[128];      
    int               bHasMeasurementCameraMounted;      
    int               bIsActive;                         
};



struct SetStatisticModeCT
{
    struct BasicCommandCT   packetInfo;
    enum   ES_StatisticMode stationaryMeasurements;
    enum   ES_StatisticMode continuousMeasurements;
};

struct SetStatisticModeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetStatisticModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetStatisticModeRT
{
    struct BasicCommandRT   packetInfo;
    enum   ES_StatisticMode stationaryMeasurements;
    enum   ES_StatisticMode continuousMeasurements;
};



struct CameraParamsDataT
{
    int iContrast;
    int iBrightness;
    int iSaturation;
};

struct SetCameraParamsCT
{
    struct BasicCommandCT    packetInfo;
    struct CameraParamsDataT cameraParams;
};

struct SetCameraParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetCameraParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCameraParamsRT
{
    struct BasicCommandRT    packetInfo;
    struct CameraParamsDataT cameraParams;
};



struct GetStillImageCT
{
    struct BasicCommandCT        packetInfo;
    enum   ES_StillImageFileType imageFileType;
};

struct GetStillImageRT
{
    struct BasicCommandRT        packetInfo;
    enum   ES_StillImageFileType imageFiletype;
    long                         lFileSize;
    char                         cFileStart;
};



struct CheckBirdBathCT
{
    struct BasicCommandCT packetInfo;
};

struct CheckBirdBathRT
{
    struct BasicCommandRT packetInfo;
    double                dInitialHzAngle;
    double                dInitialVtAngle;
    double                dInitialDistance;
    double                dHzAngleDiff;
    double                dVtAngleDiff;
    double                dDistanceDiff;
};



struct GetTrackerDiagnosticsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerDiagnosticsRT
{
    struct BasicCommandRT packetInfo;
    double                dTrkPhotoSensorXVal;
    double                dTrkPhotoSensorYVal;
    double                dTrkPhotoSensorIVal;
    double                dRefPhotoSensorXVal;
    double                dRefPhotoSensorYVal;
    double                dRefPhotoSensorIVal;
    double                dADConverterRange;
    double                dServoControlPointX;
    double                dServoControlPointY;
    double                dLaserLightRatio;
    int                   iLaserControlMode;
    double                dSensorInsideTemperature;
    int                   iLCPRunTime;
    int                   iLaserTubeRunTime;
};



struct GetADMInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetADMInfoRT
{
    struct BasicCommandRT packetInfo;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    long                  lSerialNumber;
};



struct GetADMInfo2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetADMInfo2RT
{
    struct BasicCommandRT packetInfo;
    enum ES_ADMType       admType;
    unsigned short        cADMName[32];                  
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMaxDistance;                  
    double                dMinDistance;                  
    int                   iMaxDataRate;                  
    double                dAccuracyADMDistance;
};



struct GetNivelInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetNivelInfoRT
{
    struct BasicCommandRT packetInfo;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    long                  lSerialNumber;
};

struct GetNivelInfo2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetNivelInfo2RT
{
    struct BasicCommandRT packetInfo;
    enum ES_NivelType     nivelType;
    unsigned short        cNivelName[32];                
    long                  lSerialNumber;
    int                   iFirmwareMajorVersionNumber;
    int                   iFirmwareMinorVersionNumber;
    double                dMeasurementRange;             
    double                dMeasurementAccuracyOffset;    
    double                dMeasurementAccuracyFactor;                
};



struct GetTPInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTPInfoRT
{
    struct BasicCommandRT        packetInfo;
    int                          iTPBootMajorVersionNumber;
    int                          iTPBootMinorVersionNumber;
    int                          iTPFirmwareMajorVersionNumber;
    int                          iTPFirmwareMinorVersionNumber;
    int                          iLCPFirmwareMajorVersionNumber;
    int                          iLCPFirmwareMinorVersionNumber;
    enum ES_TrackerProcessorType trackerprocessorType;
    enum ES_TPMicroProcessorType microProcessorType;
    int                          iMicroProcessorClockSpeed;
    enum ES_LTSensorType         laserTrackerSensorType;
};



struct GetTrackerInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTrackerInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_LTSensorType     trackerType;
    unsigned short           cTrackerName[32];           
    long                     lSerialNumber;
    long                     lCompensationIdNumber;      
    int                  bHasADM;
    int                  bHasOverviewCamera;
    int                  bHasNivel;
    double                   dNivelMountOffset;
    double                   dMaxDistance;               
    double                   dMinDistance;               
    int                      iMaxDataRate;               
    int                      iNumberOfFaces;
    double                   dHzAngleRange;              
    double                   dVtAngleRange;
    enum ES_TrkAccuracyModel accuracyModel;
    int                      iMajLCPFirmwareVersion;
    int                      iMinLCPFirmwareVersion;
};



struct GetATRInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetATRInfoRT
{
    struct BasicCommandRT packetInfo;
    enum ES_ATRType       atrType;
    unsigned short        cATRName[32];                  
    long                  lMajFirmwareVersion;
    long                  lMinFirmwareVersion;
    long                  lBuildFirmwareVersion;
    long                  lHardwareVersion;
    long                  lErrorcode;                    
    long                  lFPGAVersion;
    double                dMaxDistance;
    double                dMinDistance;
    double                dFieldOfView;
    double                dMaxTrackingSpeed;             
};



struct SetLaserOnTimerCT
{
    struct BasicCommandCT packetInfo;
    int                   iLaserOnTimeOffsetHour;
    int                   iLaserOnTimeOffsetMinute;
};

struct SetLaserOnTimerRT
{
    struct BasicCommandRT packetInfo;
};



struct GetLaserOnTimerCT
{
    struct BasicCommandCT packetInfo;
};

struct GetLaserOnTimerRT
{
    struct BasicCommandRT packetInfo;
    int                   iLaserOnTimeOffsetHour;
    int                   iLaserOnTimeOffsetMinute;
};



struct ConvertDisplayCoordinatesCT
{
    struct BasicCommandCT                   packetInfo;
    enum ES_DisplayCoordinateConversionType conversionType; 
    double                                  dVal1;
    double                                  dVal2;
    double                                  dVal3;
};

struct ConvertDisplayCoordinatesRT
{
    struct BasicCommandRT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};                            



struct SetTriggerSourceCT
{
    struct BasicCommandCT packetInfo;
    enum ES_TriggerSource triggerSource;
};

struct SetTriggerSourceRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTriggerSourceCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTriggerSourceRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TriggerSource triggerSource;
};



struct GetFaceCT
{
    struct BasicCommandCT packetInfo;
};

struct GetFaceRT
{
    struct BasicCommandRT packetInfo;
    enum ES_TrackerFace   trackerFace;
};



struct GetCamerasCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCamerasRT
{
    struct BasicCommandRT         packetInfo;
    int                           iTotalCameras;
    int                           iInternalCameraId;
    long                          lSerialNumber;
    enum ES_MeasurementCameraType cameraType;
    unsigned short                cName[32];       
    unsigned short                cComment[128];
};



struct GetCameraCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCameraRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalCameraId;
    int               bMeasurementCameraIsMounted;
};



struct SetMeasurementCameraModeCT
{
    struct BasicCommandCT         packetInfo;
    enum ES_MeasurementCameraMode cameraMode;
};

struct SetMeasurementCameraModeRT
{
    struct BasicCommandRT packetInfo;
};



struct GetMeasurementCameraModeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementCameraModeRT
{
    struct BasicCommandRT         packetInfo;
    enum ES_MeasurementCameraMode cameraMode;
};



struct GetProbesCT
{
    struct BasicCommandCT packetInfo;
};

struct GetProbesRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalProbes;
    int                   iInternalProbeId;
    long                  lSerialNumber; 
    enum ES_ProbeType     probeType;
    int                   iNumberOfFields;         
    unsigned short        cName[32];               
    unsigned short        cComment[128];
};



struct GetProbeCT
{
    struct BasicCommandCT packetInfo;
};

struct GetProbeRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalProbeId;
};



struct GetTipAdaptersCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTipAdaptersRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalTipAdapters;
    int                   iInternalTipAdapterId;
    long                  lAssemblyId;
    long                  lSerialNumberLowPart;
    long                  lSerialNumberHighPart;
    enum ES_TipType       tipType;
    double                dRadius; 
    double                dLength;
    unsigned short        cName[32];               
    unsigned short        cComment[128];
};



struct GetTipAdapterCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTipAdapterRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalTipAdapterId;
    int                   iTipAdapterInterface;
};



struct GetTCamToTrackerCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTCamToTrackerCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalTCamToTrackerCompensationId;
    int                   iInternalTrackerCompensationId;
    int                   iInternalCameraId;
    int               bIsActive;
    long                  lTrackerSerialNumber;
    unsigned short        cTCamToTrackerCompensationName[32];  
    unsigned short        cTCamToTrackerCompensationComment[128];
};



struct SetTCamToTrackerCompensationCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalTCamToTrackerCompensationId;
};

struct SetTCamToTrackerCompensationRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTCamToTrackerCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTCamToTrackerCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalTCamToTrackerCompensationId;
};



struct GetProbeCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetProbeCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalProbeCompensationId;
    int                   iInternalProbeId;
    int                   iFieldNumber;
    int               bIsActive;
    int               bMarkedForExport;
    int               bPreliminary;
    unsigned short        cProbeCompensationName[32];        
    unsigned short        cProbeCompensationComment[128]; 
};



struct GetProbeCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetProbeCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalProbeCompensationId;
};



struct SetProbeCompensationCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalProbeCompensationId;
};

struct SetProbeCompensationRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTipToProbeCompensationsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTipToProbeCompensationsRT
{
    struct BasicCommandRT packetInfo;
    int                   iTotalCompensations;
    int                   iInternalTipToProbeCompensationId;
    int                   iInternalTipAdapterId;
    int                   iTipAdapterInterface;
    int                   iInternalProbeCompensationId;
    int               bMarkedForExport;
    unsigned short        cTipToProbeCompensationName[32];   
    unsigned short        cTipToProbeCompensationComment[128];
};

struct GetTipToProbeCompensations2CT
{
    struct BasicCommandCT packetInfo;
};

struct GetTipToProbeCompensations2RT
{
    struct BasicCommandRT              packetInfo;
    int                                iTotalCompensations;
    int                                iInternalTipToProbeCompensationId;
    int                                iInternalTipAdapterId;
    int                                iTipAdapterInterface;
    int                                iInternalProbeCompensationId;
    int                            bMarkedForExport;
    enum ES_TipToProbeCompensationType compensationType;
    unsigned short                     cTipToProbeCompensationName[32];  
    unsigned short                     cTipToProbeCompensationComment[128];
    unsigned short                     cShankCompensationName[32];
};



struct GetTipToProbeCompensationCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTipToProbeCompensationRT
{
    struct BasicCommandRT packetInfo;
    int                   iInternalTipToProbeCompensationId;
};



struct ExternTriggerParamsT
{
   enum ES_ClockTransition    clockTransition;
   enum ES_TriggerMode        triggerMode;
   enum ES_TriggerStartSignal startSignal;
   long                       lMinimalTimeDelay;
};

struct SetExternTriggerParamsCT
{
    struct BasicCommandCT       packetInfo;
    struct ExternTriggerParamsT triggerParams;
};

struct SetExternTriggerParamsRT
{
    struct BasicCommandRT packetInfo;
};



struct GetExternTriggerParamsCT
{
    struct BasicCommandCT packetInfo;
};

struct GetExternTriggerParamsRT
{
    struct BasicCommandRT       packetInfo;
    struct ExternTriggerParamsT triggerParams;
};



struct GetErrorEllipsoidCT
{
    struct BasicCommandCT packetInfo;
    double                dCoord1; 
    double                dCoord2; 
    double                dCoord3; 
    double                dStdDev1; 
    double                dStdDev2; 
    double                dStdDev3; 
    double                dCovar12; 
    double                dCovar13; 
    double                dCovar23;
};

struct GetErrorEllipsoidRT
{
    struct BasicCommandRT packetInfo;
    double                dStdDevX; 
    double                dStdDevY; 
    double                dStdDevZ; 
    double                dRotationAngleX; 
    double                dRotationAngleY; 
    double                dRotationAngleZ;
};



struct GetMeasurementCameraInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementCameraInfoRT
{
    struct BasicCommandRT         packetInfo;
    int                           iFirmwareMajorVersionNumber;
    int                           iFirmwareMinorVersionNumber;
    long                          lSerialNumber;
    enum ES_MeasurementCameraType cameraType;
    unsigned short                cName[32];                 
    long                          lCompensationIdNumber;     
    long                          lZoomSerialNumber;
    long                          lZoomAdjustmentIdNumber;
    long                          lZoom2DCompensationIdNumber;
    long                          lZoomProjCenterCompIdNumber;
    double                        dMaxDistance;
    double                        dMinDistance;
    long                          lNrOfPixelsX;
    long                          lNrOfPixelsY;
    double                        dPixelSizeX;
    double                        dPixelSizeY;
    long                          lMaxDataRate;              
};



struct GetMeasurementProbeInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeasurementProbeInfoRT
{
    struct BasicCommandRT       packetInfo;
    int                         iFirmwareMajorVersionNumber;
    int                         iFirmwareMinorVersionNumber;
    long                        lSerialNumber;
    enum ES_ProbeType           probeType;
    long                        lCompensationIdNumber;       
    long                        lActiveField;                
    enum ES_ProbeConnectionType connectionType;
    long                        lNumberOfTipAdapters;        
    enum ES_ProbeButtonType     probeButtonType;
    long                        lNumberOfFields;             
    int                     bHasWideAngleReceiver;
    long                        lNumberOfTipDataSets;        
    long                        lNumberOfMelodies;           
    long                        lNumberOfLoudnesSteps;       
};



struct SetLongSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
    long                    lParameter;
};

struct SetLongSystemParamRT
{
    struct BasicCommandRT packetInfo;
};



struct GetLongSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
};

struct GetLongSystemParamRT
{
    struct BasicCommandRT   packetInfo;
    enum ES_SystemParameter systemParam;
    long                    lParameter;
};



struct GetCurrentPrismPositionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetCurrentPrismPositionRT
{
    struct BasicCommandRT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};



struct GetObjectTemperatureCT
{
    struct BasicCommandCT packetInfo;
};

struct GetObjectTemperatureRT
{
    struct BasicCommandRT packetInfo;
    double                dObjectTemperature;
};



struct ClearCommandQueueCT
{
    struct BasicCommandCT         packetInfo;
    enum ES_ClearCommandQueueType clearQueueType;
};

struct ClearCommandQueueRT
{
    struct BasicCommandRT packetInfo;
};



struct GetTriggerBoardInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetTriggerBoardInfoRT
{
    struct BasicCommandRT   packetInfo;
    enum ES_TriggerCardType triggerCardType;                                    
    long                    lFPGAVersion;
    long                    lMaxTriggerFrequency;
    long                    lErrorCode;            
};



struct GetOverviewCameraInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetOverviewCameraInfoRT
{
    struct BasicCommandRT      packetInfo;
    enum ES_OverviewCameraType cameraType;
    unsigned short             cCameraName[32];    
    int                    bIsColorCamera;
    double                     dFocalLength;
    double                     dHorizontalChipSize;
    double                     dVerticalChipSize;
    int                    bMirrorImageHz;
    int                    bMirrorImageVt;
};



struct GetDoubleSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
};

struct GetDoubleSystemParamRT
{
    struct BasicCommandRT   packetInfo;
    enum ES_SystemParameter systemParam;
    double                  dParameter;
};



struct SetDoubleSystemParamCT
{
    struct BasicCommandCT   packetInfo;
    enum ES_SystemParameter systemParam;
    double                  dParameter;
};

struct SetDoubleSystemParamRT
{
    struct BasicCommandRT packetInfo;
};



struct RestoreStartupConditionsCT
{
    struct BasicCommandCT packetInfo;
};

struct RestoreStartupConditionsRT
{
    struct BasicCommandRT packetInfo;
};



struct GoAndMeasureCT
{
    struct BasicCommandCT packetInfo;
    double                dVal1;
    double                dVal2;
    double                dVal3;
};

struct GoAndMeasureRT
{
    struct BasicCommandRT packetInfo;
};



struct SetTipAdapterCT
{
    struct BasicCommandCT packetInfo;
    int                   iInternalTipAdapterId;
};

struct SetTipAdapterRT
{
    struct BasicCommandRT packetInfo;
};



struct GetMeteoStationInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetMeteoStationInfoRT
{
    struct BasicCommandRT    packetInfo;
    enum ES_MeteoStationType meteoStationType;
    unsigned short           cIdentifier[32];      
    int                      iFirmwareMajorVersionNumber;
    int                      iFirmwareMinorVersionNumber;
};







struct GetATInfoCT
{
    struct BasicCommandCT packetInfo;
};

struct GetATInfoRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_LTSensorType         trackerType;
    unsigned short               cTrackerName[32]; 
    long                         lSerialNumber;
    long                         lMajorFirmwareVersion;
    long                         lMinorFirmwareVersion;
    long                         lProcessorBoardFWBuildNumber;
    long                         lSensorBoardFWBuildNumber;
    long                         lMajorOSVersion;
    long                         lMinorOSVersion;
    long                         lMajorServerSoftwareVersion;
    long                         lMinorServerSoftwareVersion;
    long                         lServerSoftwareBuildNumber;
    enum ES_WLANType             wlanType;
    enum ES_TPMicroProcessorType xscaleType;
    long                         lMinMeasureTime;
    double                       dMinDistance;
    double                       dMaxDistance;
    double                       dStdDevDistOffsetADM;
    double                       dStdDevAngleConst;
    double                       dStdDevAngleOffset;
    double                       dStdDevAngleFactor;
};







struct GetAT4xxInfoCT
{
    struct BasicCommandCT packetInfo;
};


struct GetAT4xxInfoRT
{
    struct BasicCommandRT        packetInfo;
    enum ES_LTSensorType         trackerType;
    unsigned short               cTrackerName[32]; 
    long                         lSerialNumber;
    long                         lMajorFirmwareVersion;
    long                         lMinorFirmwareVersion;
    long                         lProcessorBoardFWBuildNumber;
    long                         lSensorBoardFWBuildNumber;
    long                         lMajorOSVersion;
    long                         lMinorOSVersion;
    long                         lMajorServerSoftwareVersion;
    long                         lMinorServerSoftwareVersion;
    long                         lServerSoftwareBuildNumber;
    enum ES_WLANType             wlanType;
    enum ES_TPMicroProcessorType xscaleType;
    long                         lMinMeasureTime;
    double                       dMinDistance;
    double                       dMaxDistance;
    double                       dStdDevDistOffsetADM;
    double                       dStdDevAngleConst;
    double                       dStdDevAngleOffset;
    double                       dStdDevAngleFactor;
};



struct GetSystemSoftwareVersionCT
{
    struct BasicCommandCT packetInfo;
};

struct GetSystemSoftwareVersionRT
{
    struct BasicCommandRT packetInfo;
    unsigned short        cSoftwareVersion[32]; 
};



struct SystemPowerDownCT
{
    struct BasicCommandCT packetInfo;
};

struct SystemPowerDownRT
{
    struct BasicCommandRT packetInfo;
};




