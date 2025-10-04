
/******************************************************************************

Copyright (C) Leica Geosystems AG, 2001..2018

Filename: ES_MCPP_API_Def.h 

Description: Managed C++ wrapper for Leica Embedded Systems, for use 
             by C#- Applications.   

Notes: 
This file comprises the interface for all Leica Tracker- types (3D, 6DoF).     
If addressing AT401 Trackers exclusively, it is recommended rather using the   
related include file (of same name) that is delivered with the AT401 SDK).     
4xx symbols should no longer be used. Use compatible non-4xx symbols instead.  
******************************************************************************/

// Note: 
//
// The notation in this file still applies to .NET 1.0. It is still compatible with .NET 3.5
// applications, although the notation has changed for .NET 3.5. In order to leave this file
// compatible to .NET 1.0, these changes intentionally have not been applied yet. 
//
// Here are the main changes for .NET 3.5:
// 
// '__value struct'  becomes  'value struct'  (i.e. omit the leading double-underscores)
//
// 'public __value'  keywords in front of struct members are no longer necessary
//
// Example: the current notation...
//
// [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
// __value struct ContinuousTimeModeDataT
// {
//      public __value long lTimeSeparation;
//      public __value long lNumberOfPoints;    
//      public __value bool /*ES_BOOL*/ bUseRegion;
//      public __value ES_RegionType regionType;    
// };
//
// ...under .NET 3.5 becomes:
//
// [StructLayout(LayoutKind::Sequential, Pack=4)]
// value struct ContinuousTimeModeDataT
// {
//      long lTimeSeparation;
//      long lNumberOfPoints;    
//      bool /*ES_BOOL*/ bUseRegion;
//      ES_RegionType regionType;    
// };
//
// There is a new notation for array-type parameters (templates), Examples:
//
// virtual bool SendPacket(Byte packetAddress __gc [], int packetSize) = 0;
//
// becomes
//
// virtual bool SendPacket(array<Byte>^ packetAddress, int packetSize) abstract;
//
//
// bool DispatchData(void *data, int nSize)
// {
//     Byte pData __gc[] = new Byte __gc [nSize];
//     Byte __pin * pDest = &pData[0];
//     memcpy(pDest, data, nSize);
//     return SendPacket(pData, nSize);
// }
//
// becomes
//
// bool DispatchData(void *data, int nSize)
// {
//     array<Byte> ^ pData=gcnew array<Byte>(nSize);
//     pin_ptr<Byte> pDest = &pData[0];
//     memcpy(pDest, data, nSize);
//     return SendPacket(pData, nSize);
// }
//
//
// virtual void OnGetCamerasAnswer(int iCameraID, 
//                  int /*long*/ lSerialNumber, 
//                  ES_MeasurementCameraType cameraType,
//                  unsigned char cCameraName __gc [],
//                  unsigned char cComment __gc [], 
//                  int iCamerasTotal) {;}
//
// becomes
//
// virtual void OnGetCamerasAnswer(int iCameraID, 
//                  int /*long*/ lSerialNumber, 
//                  ES_MeasurementCameraType cameraType,
//                  array<unsigned char>^ cCameraName,
//                  array<unsigned char>^ cComment, 
//                  int iCamerasTotal) {;}
//
//
// Generally spoken, all keywords starting with double underscores
// (__gc, __value...) have become obsolete and Templates are 
// available for array-type parameters.
//
// Please note that above remarks are only hints - The definitive 
// syntax may still be slightly different or my change again with
// future versions. No tests have been performed with new .NET 3.5
// notation so far.
//
/////////////////////////////////////////////////////////////////////////////

// system include files
#include <memory.h> // used for memcpy()

// rather define TRUE locally instead of including <windef.h> 
#ifndef TRUE
#define TRUE  1
#endif

// CPP include files serve as base for the C# interface
#include "ES_CPP_API_Def.h"

#define ES_MCPP_API_MAJOR_VERSION 3  /* EmScon TPI/SDK V3.8 - Note: TPI/SDK Version..  */ 
#define ES_MCPP_API_MINOR_VERSION 8  /* not necessarily matches EmScon server version! */

#if ES_API_MAJOR_VERSION != ES_MCPP_API_MAJOR_VERSION
   #error Version conflict with EmScon API definition file (ES_C_API_Def.h) !
#endif
#if ES_API_MINOR_VERSION != ES_MCPP_API_MINOR_VERSION
   #error Version conflict with EmScon API definition file (ES_C_API_Def.h)!
#endif

// MC++/C# specific 'includes'
#using <mscorlib.dll>
using namespace System;
using namespace System::Runtime::InteropServices;

/////////////////////////////////////////////////////////////////////////////
// namespace EmScon

namespace EmScon
{
   // provide Enum types local to namespace EmScon

   #define  ES_MCPP_SUPPORT

   #undef ES_ENUM_H // force re-include
   #include "enum.h"

   #undef ES_C_API_DEF_H // force re-include
   #include "ES_C_API_Def.h"

   ///////////////////////////////////////////////////////////////////////////
   // class CESCSAPICommand

   public __gc __abstract class CESCSAPICommand
   {
   public:
      // structures related to class CESCSAPICommand

      // Remark: These (input parameter) structs are duplicated ones from ES_C_API_Def.h 
      // file. Make sure these always match those in ES_C_API_Def.h.

      // Important: ES_BOOL is defined as int. However, C# applications do not
      // allow casting int to bool. Since boolean variables in C# applications
      // should accept true/false as values rather than 0/1, all boolean 
      // variables defined as ES_BOOL in the C/C++ API have been replaced by 
      // 'bool' for the duplicated MCPP structures.
      // Comments /*ES_BOOL*/ have been left for documentation.

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationaryModeDataT
      {
         public __value long lMeasTime;
         public __value bool /*ES_BOOL*/ bUseADM;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ContinuousTimeModeDataT
      {
         public __value long lTimeSeparation;
         public __value long lNumberOfPoints;    
         public __value bool /*ES_BOOL*/ bUseRegion;
         public __value ES_RegionType regionType;    
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ContinuousDistanceModeDataT
      {
         public __value double dSpatialDistance;
         public __value long   lNumberOfPoints;    
         public __value bool   /*ES_BOOL*/ bUseRegion;
         public __value ES_RegionType regionType;    
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SphereCenterModeDataT
      {
         public __value double dSpatialDistance;
         public __value long   lNumberOfPoints;    
         public __value bool   /*ES_BOOL*/ bFixRadius;
         public __value double dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CircleCenterModeDataT
      {
         public __value double dSpatialDistance;
         public __value long   lNumberOfPoints;    
         public __value bool   /*ES_BOOL*/ bFixRadius;
         public __value double dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GridModeDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value long   lNumberOfPoints;
         public __value bool   /*ES_BOOL*/ bUseRegion;
         public __value ES_RegionType regionType;   
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemUnitsDataT
      {
         public __value ES_LengthUnit      lenUnitType;
         public __value ES_AngleUnit       angUnitType;
         public __value ES_TemperatureUnit tempUnitType;
         public __value ES_PressureUnit    pressUnitType;
         public __value ES_HumidityUnit    humUnitType;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemSettingsDataT
      {
         public __value ES_WeatherMonitorStatus weatherMonitorStatus;
         public __value bool /*ES_BOOL*/ bApplyTransformationParams;
         public __value bool /*ES_BOOL*/ bApplyStationOrientationParams;
         public __value bool /*ES_BOOL*/ bKeepLastPosition;
         public __value bool /*ES_BOOL*/ bSendUnsolicitedMessages;
         public __value bool /*ES_BOOL*/ bSendReflectorPositionData;
         public __value bool /*ES_BOOL*/ bTryMeasurementMode;
         public __value bool /*ES_BOOL*/ bHasNivel;
         public __value bool /*ES_BOOL*/ bHasVideoCamera;
      };  

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct EnvironmentDataT
      {
         public __value double dTemperature;
         public __value double dPressure;
         public __value double dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct AdmParamsDataT
      {
         public __value double dTargetStabilityTolerance;
         public __value long   lRetryTimeFrame;
         public __value long   lNumberOfRetrys;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SearchParamsDataT
      {
         public __value double dSearchRadius;
         public __value long   lTimeOut;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationOrientationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
         public __value double dScale;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct BoxRegionDataT
      {
         public __value double dP1Val1;
         public __value double dP1Val2;
         public __value double dP1Val3;
         public __value double dP2Val1;
         public __value double dP2Val2;
         public __value double dP2Val3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SphereRegionDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationPointT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dStd1;
         public __value double dStd2;
         public __value double dStd3;   
         public __value double dCovar12;
         public __value double dCovar13;
         public __value double dCovar23;   
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationInputDataT
      {
         public __value ES_TransResultType resultType;  
         public __value double dTransVal1;
         public __value double dTransVal2;
         public __value double dTransVal3;
         public __value double dRotVal1;
         public __value double dRotVal2;
         public __value double dRotVal3;
         public __value double dScale;
         public __value double dTransStdVal1;
         public __value double dTransStdVal2;
         public __value double dTransStdVal3;
         public __value double dRotStdVal1;
         public __value double dRotStdVal2;
         public __value double dRotStdVal3;
         public __value double dScaleStd;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CameraParamsDataT
      {
         public __value int iContrast;
         public __value int iBrightness;
         public __value int iSaturation;
      };

   public:
      // SendPacket is a pure virtual function - MUST be overridden in derived class in C# client
      virtual bool SendPacket(Byte packetAddress __gc [], int packetSize) = 0;

   public:
      // Wrapped MC++ emScon API command methods that can be called from C# client
      bool Initialize() {CInitialize Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ReleaseMotors() {CReleaseMotors Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool ActivateCameraView() {CActivateCameraView Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool Park() {CPark Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoLastMeasuredPoint() {CGoLastMeasuredPoint Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetSystemStatus() {CGetSystemStatus Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTrackerStatus() {CGetTrackerStatus Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SwitchLaserOn(bool bOn) {CSwitchLaser Data(bOn); return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool SetCoordinateSystemType(ES_CoordinateSystemType sysType) {CSetCoordinateSystemType Data((::ES_CoordinateSystemType)sysType); return DispatchData(&Data, sizeof(Data.DataPacket));}  
      bool GetCoordinateSystemType() {CGetCoordinateSystemType  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetMeasurementMode(ES_MeasMode mode) {CSetMeasurementMode Data((::ES_MeasMode)mode); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementMode() {CGetMeasurementMode Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetStationaryModeParams(long lMeasTime, bool bUseADM) {CSetStationaryModeParams Data(lMeasTime, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationaryModeParams(StationaryModeDataT stationaryModeData) {::StationaryModeDataT smd; 
         smd.lMeasTime = stationaryModeData.lMeasTime; 
         smd.bUseADM = stationaryModeData.bUseADM;
         CSetStationaryModeParams Data(smd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetStationaryModeParams() {CGetStationaryModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetContinuousTimeModeParams(long lTimeSeparation, long lNumberOfPoints, bool bUseRegion, ES_RegionType regionType) {CSetContinuousTimeModeParams Data(lTimeSeparation, lNumberOfPoints, bUseRegion, (::ES_RegionType)regionType); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetContinuousTimeModeParams(ContinuousTimeModeDataT continuousTimeModeData) {::ContinuousTimeModeDataT ctmd; 
         ctmd.lTimeSeparation = continuousTimeModeData.lTimeSeparation;
         ctmd.lNumberOfPoints = continuousTimeModeData.lNumberOfPoints;
         ctmd.bUseRegion = continuousTimeModeData.bUseRegion;
         ctmd.regionType = (::ES_RegionType)continuousTimeModeData.regionType;
         CSetContinuousTimeModeParams Data(ctmd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetContinuousTimeModeParams() {CGetContinuousTimeModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetContinuousDistanceModeParams(double dSpatialDistance, long lNumberOfPoints, bool bUseRegion, ES_RegionType regionType) {CSetContinuousDistanceModeParams Data(dSpatialDistance, lNumberOfPoints, bUseRegion, (::ES_RegionType)regionType); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetContinuousDistanceModeParams(ContinuousDistanceModeDataT continuousDistanceModeData) {::ContinuousDistanceModeDataT cdmd; 
         cdmd.dSpatialDistance = continuousDistanceModeData.dSpatialDistance;
         cdmd.lNumberOfPoints = continuousDistanceModeData.lNumberOfPoints;
         cdmd.bUseRegion = continuousDistanceModeData.bUseRegion;
         cdmd.regionType = (::ES_RegionType)continuousDistanceModeData.regionType;
         CSetContinuousDistanceModeParams Data(cdmd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetContinuousDistanceModeParams() {CGetContinuousDistanceModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetSphereCenterModeParams(double dSpatialDistance, long lNumberOfPoints, bool bFixRadius, double dRadius) {CSetSphereCenterModeParams Data(dSpatialDistance, lNumberOfPoints, bFixRadius, dRadius); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSphereCenterModeParams(SphereCenterModeDataT sphereCenterModeData) {::SphereCenterModeDataT scmd;
         scmd.dSpatialDistance = sphereCenterModeData.dSpatialDistance;
         scmd.lNumberOfPoints = sphereCenterModeData.lNumberOfPoints;
         scmd.bFixRadius = sphereCenterModeData.bFixRadius;
         scmd.dRadius = sphereCenterModeData.dRadius;
         CSetSphereCenterModeParams Data(scmd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSphereCenterModeParams() {CGetSphereCenterModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetCircleCenterModeParams(double dSpatialDistance, long lNumberOfPoints, bool bFixRadius, double dRadius) {CSetCircleCenterModeParams Data(dSpatialDistance, lNumberOfPoints, bFixRadius, dRadius); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetCircleCenterModeParams(CircleCenterModeDataT circleCenterModeData) {::CircleCenterModeDataT ccmd;
         ccmd.dSpatialDistance = circleCenterModeData.dSpatialDistance;
         ccmd.lNumberOfPoints = circleCenterModeData.lNumberOfPoints;
         ccmd.bFixRadius = circleCenterModeData.bFixRadius;
         ccmd.dRadius = circleCenterModeData.dRadius;
         CSetCircleCenterModeParams Data(ccmd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetCircleCenterModeParams() {CGetCircleCenterModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetGridModeParams(double dXDistance, double dYDistance, double dZDistance, long lNumberOfPoints, bool bUseRegion, ES_RegionType regionType) {CSetGridModeParams Data(dXDistance, dYDistance, dZDistance, lNumberOfPoints, bUseRegion, (::ES_RegionType)regionType); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetGridModeParams(GridModeDataT gridModeData) {::GridModeDataT gmd;
         gmd.dVal1 = gridModeData.dVal1;
         gmd.dVal2 = gridModeData.dVal2;
         gmd.dVal3 = gridModeData.dVal3;            
         gmd.lNumberOfPoints = gridModeData.lNumberOfPoints;
         gmd.bUseRegion = gridModeData.bUseRegion;
         gmd.regionType = (::ES_RegionType)gridModeData.regionType;
         CSetGridModeParams Data(gmd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetGridModeParams() {CGetGridModeParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetReflectors() {CGetReflectors Data;return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetReflector() {CGetReflector Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetReflector(int reflID) {CSetReflector Data(reflID);return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetUnits(SystemUnitsDataT unitsSettings) {::SystemUnitsDataT su;
         su.lenUnitType = (::ES_LengthUnit)unitsSettings.lenUnitType;
         su.angUnitType = (::ES_AngleUnit)unitsSettings.angUnitType;
         su.tempUnitType = (::ES_TemperatureUnit)unitsSettings.tempUnitType;
         su.pressUnitType = (::ES_PressureUnit)unitsSettings.pressUnitType;
         su.humUnitType = (::ES_HumidityUnit)unitsSettings.humUnitType;
         CSetUnits Data(su); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetUnits(ES_LengthUnit lenUnitType, ES_AngleUnit angUnitType, ES_TemperatureUnit tempUnitType, ES_PressureUnit pressUnitType, ES_HumidityUnit humUnitType) {CSetUnits Data((::ES_LengthUnit)lenUnitType, (::ES_AngleUnit)angUnitType, (::ES_TemperatureUnit)tempUnitType, (::ES_PressureUnit)pressUnitType, (::ES_HumidityUnit)humUnitType); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetUnits() {CGetUnits Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSystemSettings(SystemSettingsDataT settings) {::SystemSettingsDataT ssd;
         ssd.weatherMonitorStatus = (::ES_WeatherMonitorStatus)settings.weatherMonitorStatus;
         ssd.bApplyStationOrientationParams = settings.bApplyStationOrientationParams;
         ssd.bApplyTransformationParams = settings.bApplyTransformationParams;
         ssd.bHasNivel = settings.bHasNivel;
         ssd.bHasVideoCamera = settings.bHasVideoCamera;
         ssd.bKeepLastPosition = settings.bKeepLastPosition;
         ssd.bSendReflectorPositionData = settings.bSendReflectorPositionData;
         ssd.bSendUnsolicitedMessages = settings.bSendUnsolicitedMessages;
         ssd.bTryMeasurementMode = settings.bTryMeasurementMode;
         CSetSystemSettings Data(ssd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSystemSettings() {CGetSystemSettings Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTemperatureRange(ES_TrackerTemperatureRange temperatureRange) {CSetTemperatureRange Data((::ES_TrackerTemperatureRange)temperatureRange); return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetTemperatureRange() {CGetTemperatureRange Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool SetEnvironmentParams(double dTemperature, double dPressure, double dHumidity) {CSetEnvironmentParams Data(dTemperature, dPressure, dHumidity); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetEnvironmentParams(EnvironmentDataT environmentData) {::EnvironmentDataT ed;
         ed.dTemperature = environmentData.dTemperature;
         ed.dPressure = environmentData.dPressure;
         ed.dHumidity = environmentData.dHumidity;
         CSetEnvironmentParams Data(ed); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetEnvironmentParams() {CGetEnvironmentParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetRefractionParams() {CGetRefractionParams  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetRefractionParams(double  ifmIndex, double admIndex) {CSetRefractionParams Data(ifmIndex, admIndex); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetAdmParams() {CGetAdmParams  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetAdmParams(AdmParamsDataT admParams) {::AdmParamsDataT admd;
         admd.dTargetStabilityTolerance = admParams.dTargetStabilityTolerance;
         admd.lNumberOfRetrys = admParams.lNumberOfRetrys;
         admd.lRetryTimeFrame = admParams.lRetryTimeFrame;
         CSetAdmParams Data(admd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSearchParams() {CGetSearchParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSearchParams(SearchParamsDataT searchParams) {::SearchParamsDataT sp;
         sp.dSearchRadius = searchParams.dSearchRadius;
         sp.lTimeOut = searchParams.lTimeOut;
         CSetSearchParams Data(sp); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationOrientationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3) {CSetStationOrientationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetStationOrientationParams(StationOrientationDataT stationOrientation) {::StationOrientationDataT sod;
         sod.dVal1 = stationOrientation.dVal1;
         sod.dVal2 = stationOrientation.dVal2;
         sod.dVal3 = stationOrientation.dVal3;
         sod.dRot1 = stationOrientation.dRot1;
         sod.dRot2 = stationOrientation.dRot2;
         sod.dRot3 = stationOrientation.dRot3;
         CSetStationOrientationParams Data(sod); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetStationOrientationParams() {CGetStationOrientationParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTransformationParams(double dVal1, double dVal2, double dVal3, double dRot1, double dRot2, double dRot3, double dScale) {CSetTransformationParams Data(dVal1, dVal2, dVal3, dRot1, dRot2, dRot3, dScale); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetTransformationParams(TransformationDataT transformationData) {::TransformationDataT td;
         td.dVal1 = transformationData.dVal1;
         td.dVal2 = transformationData.dVal2;
         td.dVal3 = transformationData.dVal3;
         td.dRot1 = transformationData.dRot1;
         td.dRot2 = transformationData.dRot2;
         td.dRot3 = transformationData.dRot3;
         td.dScale = transformationData.dScale;
         CSetTransformationParams Data(td); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetTransformationParams() {CGetTransformationParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetBoxRegionParams(double dX1, double dY1, double dZ1, double dX2, double dY2, double dZ2) {CSetBoxRegionParams Data(dX1, dY1, dZ1, dX2, dY2, dZ2); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetBoxRegionParams(BoxRegionDataT boxRegionData) {::BoxRegionDataT brd;
         brd.dP1Val1 = boxRegionData.dP1Val1;
         brd.dP1Val2 = boxRegionData.dP1Val2;
         brd.dP1Val3 = boxRegionData.dP1Val3;
         brd.dP2Val1 = boxRegionData.dP2Val1;
         brd.dP2Val2 = boxRegionData.dP2Val2;
         brd.dP2Val3 = boxRegionData.dP2Val3;
         CSetBoxRegionParams Data(brd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetBoxRegionParams() {CGetBoxRegionParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetSphereRegionParams(double dX1, double dY1, double dZ1, double dRadius) {CSetSphereRegionParams Data(dX1, dY1, dZ1, dRadius); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetSphereRegionParams(SphereRegionDataT sphereRegionData) {::SphereRegionDataT srd;
         srd.dVal1 = sphereRegionData.dVal1;
         srd.dVal2 = sphereRegionData.dVal2;
         srd.dVal3 = sphereRegionData.dVal3;
         srd.dRadius = sphereRegionData.dRadius;
         CSetSphereRegionParams Data(srd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetSphereRegionParams() {CGetSphereRegionParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoPosition(double dVal1, double dVal2, double dVal3, bool bUseADM) {CGoPosition Data(dVal1, dVal2, dVal3, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoPositionHVD(double dHzAngle, double dVtAngle, double dDistance, bool bUseADM) {CGoPositionHVD Data(dHzAngle, dVtAngle, dDistance, bUseADM); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PointLaser(double dVal1, double dVal2, double dVal3) {CPointLaser Data(dVal1, dVal2, dVal3); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PointLaserHVD(double dHzAngle, double dVtAngle, double dDistance) {CPointLaserHVD Data(dHzAngle, dVtAngle, dDistance); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoNivelPosition(ES_NivelPosition position) {CGoNivelPosition Data((::ES_NivelPosition)position); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool MoveHV(long lHzSpeed, long lVtSpeed) {CMoveHV Data(lHzSpeed, lVtSpeed); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool PositionRelativeHV(double dHz, double dVt) {CPositionRelativeHV Data(dHz, dVt); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoBirdBath() {CGoBirdBath Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ChangeFace() {CChangeFace Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool FindReflector(double dAproxDistance) {CFindReflector Data(dAproxDistance); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StartMeasurement() {CStartMeasurement Data;return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StartNivelMeasurement() {CStartNivelMeasurement Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool StopMeasurement() {CStopMeasurement Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ExitApplication() {CExitApplication Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool LookForTarget(double dval1, double dval2, double dval3, double Radius) {CLookForTarget Data(dval1, dval2, dval3, Radius); return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetDirection() {CGetDirection Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool CallOrientToGravity() {CCallOrientToGravity Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ClearTransformationNominalPointList() {CClearTransformationNominalPointList Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ClearTransformationActualPointList() {CClearTransformationActualPointList Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool AddTransformationNominalPoint(double dVal1, double dVal2, double dVal3, double dStd1, double dStd2, double dStd3, double dCovar12, double dCovar13, double dCovar23) {CAddTransformationNominalPoint Data(dVal1, dVal2, dVal3, dStd1, dStd2, dStd3, dCovar12, dCovar13, dCovar23); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool AddTransformationNominalPoint(TransformationPointT transformationPoint) {::TransformationPointT tp;
         tp.dVal1 = transformationPoint.dVal1;
         tp.dVal2 = transformationPoint.dVal2;
         tp.dVal3 = transformationPoint.dVal3;
         tp.dStd1 = transformationPoint.dStd1;
         tp.dStd2 = transformationPoint.dStd2;
         tp.dStd3 = transformationPoint.dStd3;
         tp.dCovar12 = transformationPoint.dCovar12;
         tp.dCovar13 = transformationPoint.dCovar13;
         tp.dCovar23 = transformationPoint.dCovar23;
         CAddTransformationNominalPoint Data(tp); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool AddTransformationActualPoint(double dVal1, double dVal2, double dVal3, double dStd1, double dStd2, double dStd3, double dCovar12, double dCovar13, double dCovar23) {CAddTransformationActualPoint Data(dVal1, dVal2, dVal3, dStd1, dStd2, dStd3, dCovar12, dCovar13, dCovar23); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool AddTransformationActualPoint(TransformationPointT transformationPoint) {::TransformationPointT tp;
         tp.dVal1 = transformationPoint.dVal1;
         tp.dVal2 = transformationPoint.dVal2;
         tp.dVal3 = transformationPoint.dVal3;
         tp.dStd1 = transformationPoint.dStd1;
         tp.dStd2 = transformationPoint.dStd2;
         tp.dStd3 = transformationPoint.dStd3;
         tp.dCovar12 = transformationPoint.dCovar12;
         tp.dCovar13 = transformationPoint.dCovar13;
         tp.dCovar23 = transformationPoint.dCovar23;
         CAddTransformationActualPoint Data(tp); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool GetTransformationInputParams() {CGetTransformationInputParams  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTransformationInputParams(ES_TransResultType transResultType, double dTransVal1, double dTransVal2, double dTransVal3, double dRotVal1, double dRotVal2, double dRotVal3, double dScale, double dTransStdVal1, double dTransStdVal2, double dTransStdVal3, double dRotStdVal1, double dRotStdVal2, double dRotStdVal3, double dScaleStd) {CSetTransformationInputParams Data((::ES_TransResultType)transResultType, dTransVal1, dTransVal2, dTransVal3, dRotVal1, dRotVal2, dRotVal3, dScale, dTransStdVal1, dTransStdVal2, dTransStdVal3, dRotStdVal1, dRotStdVal2, dRotStdVal3, dScaleStd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetTransformationInputParams(TransformationInputDataT transformationData) {::TransformationInputDataT tid;
         tid.resultType = (::ES_TransResultType)transformationData.resultType;  
         tid.dTransVal1 = transformationData.dTransVal1;
         tid.dTransVal2 = transformationData.dTransVal2;
         tid.dTransVal3 = transformationData.dTransVal3;
         tid.dRotVal1 = transformationData.dRotVal1;
         tid.dRotVal2 = transformationData.dRotVal2;
         tid.dRotVal3 = transformationData.dRotVal3;
         tid.dScale = transformationData.dScale;
         tid.dTransStdVal1 = transformationData.dTransStdVal1;
         tid.dTransStdVal2 = transformationData.dTransStdVal2;
         tid.dTransStdVal3 = transformationData.dTransStdVal3;
         tid.dRotStdVal1 = transformationData.dRotStdVal1;
         tid.dRotStdVal2 = transformationData.dRotStdVal2;
         tid.dRotStdVal3 = transformationData.dRotStdVal3;
         tid.dScaleStd = transformationData.dScaleStd;
         CSetTransformationInputParams Data(tid); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool CallTransformation() {CCallTransformation  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTransformedPoints() {CGetTransformedPoints Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ClearDrivePointList() {CClearDrivePointList Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool AddDrivePoint(int iInternalReflectorId, double dVal1, double dVal2, double dVal) {CAddDrivePoint Data(iInternalReflectorId, dVal1, dVal2, dVal); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool CallIntermediateCompensation() {CCallIntermediateCompensation Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetCompensation(int iInternalCompensationId) {CSetCompensation  Data(iInternalCompensationId); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetStatisticMode(ES_StatisticMode stationaryMeasurements, ES_StatisticMode continuousMeasurements) {CSetStatisticMode Data((::ES_StatisticMode)stationaryMeasurements, (::ES_StatisticMode)continuousMeasurements); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetStatisticMode() {CGetStatisticMode  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCameraParams() {CGetCameraParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetCameraParams(CameraParamsDataT cameraParams) {::CameraParamsDataT cpd;
         cpd.iContrast = cameraParams.iContrast;
         cpd.iBrightness = cameraParams.iBrightness;
         cpd.iSaturation = cameraParams.iSaturation;
         CSetCameraParams Data(cpd); return DispatchData(&Data, sizeof(Data.DataPacket));}

      bool SetCameraParams(int iContrast, int iBrightness, int iSaturation) {CSetCameraParams Data(iContrast, iBrightness, iSaturation); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetStillImage(ES_StillImageFileType imageFileType) {CGetStillImage  Data((::ES_StillImageFileType)imageFileType); return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetCompensation() {CGetCompensation  Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCompensations() {CGetCompensations Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCompensations2() {CGetCompensations2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool CheckBirdBath() {CCheckBirdBath Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetTrackerDiagnostics() {CGetTrackerDiagnostics  Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetADMInfo() {CGetADMInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetTPInfo() {CGetTPInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetNivelInfo() {CGetNivelInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetLaserOnTimer() {CGetLaserOnTimer Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetLaserOnTimer(int iTimeOffsetHour, int iTimeOffsetMinute) {CSetLaserOnTimer Data(iTimeOffsetHour, iTimeOffsetMinute); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoBirdBath2(bool bClockwise) {CGoBirdBath2 Data(bClockwise); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTriggerSource(ES_TriggerSource triggerSource) {CSetTriggerSource Data((::ES_TriggerSource)triggerSource); return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetTriggerSource() {CGetTriggerSource Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetFace() {CGetFace Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ConvertDisplayCoordinates(ES_DisplayCoordinateConversionType conversionType,double dVal1, double dVal2, double dVal3) {CConvertDisplayCoordinates Data((::ES_DisplayCoordinateConversionType)conversionType, dVal1, dVal2, dVal3); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCameras() {CGetCameras Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCamera() {CGetCamera Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetMeasurementCameraMode(ES_MeasurementCameraMode cameraMode) {CSetMeasurementCameraMode Data((::ES_MeasurementCameraMode)cameraMode); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementCameraMode() {CGetMeasurementCameraMode Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetProbes() {CGetProbes Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetProbe() {CGetProbe Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTipAdapters() {CGetTipAdapters Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTipAdapter() {CGetTipAdapter Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTCamToTrackerCompensations() {CGetTCamToTrackerCompensations Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTCamToTrackerCompensation(long tCamToTrackerCompensationID) {CSetTCamToTrackerCompensation Data(tCamToTrackerCompensationID); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTCamToTrackerCompensation() {CGetTCamToTrackerCompensation Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetProbeCompensations() {CGetProbeCompensations Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetProbeCompensation() {CGetProbeCompensation Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetProbeCompensation(long lProbeCompensationID) {CSetProbeCompensation Data(lProbeCompensationID); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTipToProbeCompensations() {CGetTipToProbeCompensations Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTipToProbeCompensation() {CGetTipToProbeCompensation Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetExternTriggerParams(ES_ClockTransition clockTransition, ES_TriggerMode triggerMode, ES_TriggerStartSignal startSignal, long lMinimalTimeDelay) {CSetExternTriggerParams Data((::ES_ClockTransition)clockTransition, (::ES_TriggerMode)triggerMode, (::ES_TriggerStartSignal)startSignal, lMinimalTimeDelay); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetExternTriggerParams() {CGetExternTriggerParams Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetErrorEllipsoid(double dCoord1, double dCoord2, double dCoord3, double dStdDev1, double dStdDev2, double dStdDev3, double dCovar12, double dCovar13, double dCovar23) {CGetErrorEllipsoid Data(dCoord1, dCoord2, dCoord3, dStdDev1, dStdDev2, dStdDev3, dCovar12, dCovar13, dCovar23); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementCameraInfo() {CGetMeasurementCameraInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementProbeInfo() {CGetMeasurementProbeInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetLongSystemParameter(ES_SystemParameter systemParam, long lParameter) {CSetLongSystemParam Data((::ES_SystemParameter)systemParam, lParameter); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetLongSystemParameter(ES_SystemParameter systemParam) {CGetLongSystemParam Data((::ES_SystemParameter)systemParam); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeasurementStatusInfo() {CGetMeasurementStatusInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetCurrentPrismPosition() {CGetCurrentPrismPosition Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool SetDoubleSystemParameter(ES_SystemParameter systemParam, double dParameter) {CSetDoubleSystemParam Data((::ES_SystemParameter)systemParam, dParameter); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetDoubleSystemParameter(ES_SystemParameter systemParam) {CGetDoubleSystemParam Data((::ES_SystemParameter)systemParam); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetObjectTemperature() {CGetObjectTemperature Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTriggerBoardInfo() {CGetTriggerBoardInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));} 
      bool GetOverviewCameraInfo() {CGetOverviewCameraInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool ClearCommandQueue(ES_ClearCommandQueueType ccqType) {CClearCommandQueue Data((::ES_ClearCommandQueueType)ccqType); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetADMInfo2() {CGetADMInfo2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTrackerInfo() {CGetTrackerInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetNivelInfo2() {CGetNivelInfo2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool RestoreStartupConditions() {CRestoreStartupConditions Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GoAndMeasure(double dval1, double dval2, double dval3) {CGoAndMeasure Data(dval1, dval2, dval3); return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetTipToProbeCompensations2() {CGetTipToProbeCompensations2 Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SetTipAdapter(int tipAdapterID) {CSetTipAdapter Data(tipAdapterID);return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetATRInfo() {CGetATRInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetMeteoStationInfo() {CGetMeteoStationInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetATInfo() {CGetATInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool GetAT4xxInfo() {CGetAT4xxInfo Data; return DispatchData(&Data, sizeof(Data.DataPacket));} // deprecated - rather use GetATInfo
      bool GetSystemSoftwareVersion() {CGetSystemSoftwareVersion Data; return DispatchData(&Data, sizeof(Data.DataPacket));}
      bool SystemPowerDown() {CSystemPowerDown Data; return DispatchData(&Data, sizeof(Data.DataPacket));}

   private:
      bool DispatchData(void *data, int nSize)
      {
         Byte pData __gc[] = new Byte __gc [nSize];  // Managed destination array
         Byte __pin * pDest = &pData[0];             // Pin the destination array
         memcpy(pDest, data, nSize);                 // Copy source to destination
         return SendPacket(pData, nSize);            // Send managed data to socket
      } // DispatchData()
   };  // class CESCSAPICommand


   ///////////////////////////////////////////////////////////////////////////
   // class CESCSAPIReceive

   public __gc __abstract class CESCSAPIReceive
   {
   public:
      // structures related to class CESCSAPICommand

      // Remark: These structs (for output paramters of virtual data  
      // receive handlers) are duplicated ones from ES_C_API_Def.h file.
      // Make sure these always match those in ES_C_API_Def.h.

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct PacketHeaderT
      {
         public __value long        lPacketSize;
         public __value ES_DataType type;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct BasicCommandRT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_Command      command;
         public __value ES_ResultStatus status;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ReturnDataT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_ResultStatus status;   
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ErrorResponseT
      {
         public __value PacketHeaderT   packetHeader;
         public __value ES_Command      command;
         public __value ES_ResultStatus status;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemStatusChangeT
      {
         public __value PacketHeaderT         packetHeader;
         public __value ES_SystemStatusChange systemStatusChange;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemUnitsDataT
      {
         public __value ES_LengthUnit      lenUnitType;
         public __value ES_AngleUnit       angUnitType;
         public __value ES_TemperatureUnit tempUnitType;
         public __value ES_PressureUnit    pressUnitType;
         public __value ES_HumidityUnit    humUnitType;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationOrientationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRot1;
         public __value double dRot2;
         public __value double dRot3;
         public __value double dScale;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GridModeDataT
      {
         public __value double        dVal1;
         public __value double        dVal2;
         public __value double        dVal3;
         public __value long          lNumberOfPoints;
         public __value ES_BOOL       bUseRegion;
         public __value ES_RegionType regionType;   
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct BoxRegionDataT
      {
         public __value double dP1Val1;
         public __value double dP1Val2;
         public __value double dP1Val3;
         public __value double dP2Val1;
         public __value double dP2Val2;
         public __value double dP2Val3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SphereRegionDataT
      {
         public __value double dVal1;
         public __value double dVal2;
         public __value double dVal3;
         public __value double dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct EnvironmentDataT
      {
         public __value double dTemperature;
         public __value double dPressure;
         public __value double dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct RefractionDataT
      {
         public __value double dIfmRefractionIndex;
         public __value double dAdmRefractionIndex;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct StationaryModeDataT
      {
         public __value long    lMeasTime;
         public __value ES_BOOL bUseADM;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ContinuousTimeModeDataT
      {
         public __value long          lTimeSeparation;
         public __value long          lNumberOfPoints;    
         public __value ES_BOOL       bUseRegion;
         public __value ES_RegionType regionType;    
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ContinuousDistanceModeDataT
      {
         public __value double        dSpatialDistance;
         public __value long          lNumberOfPoints;    
         public __value ES_BOOL       bUseRegion;
         public __value ES_RegionType regionType;    
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SphereCenterModeDataT
      {
         public __value double  dSpatialDistance;
         public __value long    lNumberOfPoints;    
         public __value ES_BOOL bFixRadius;
         public __value double  dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CircleCenterModeDataT
      {
         public __value double  dSpatialDistance;
         public __value long    lNumberOfPoints;    
         public __value ES_BOOL bFixRadius;
         public __value double  dRadius;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SearchParamsDataT
      {
         public __value double dSearchRadius;
         public __value long   lTimeOut;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct AdmParamsDataT
      {
         public __value double dTargetStabilityTolerance;
         public __value long   lRetryTimeFrame; 
         public __value long   lNumberOfRetrys;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SystemSettingsDataT
      {
         public __value ES_WeatherMonitorStatus weatherMonitorStatus;
         public __value ES_BOOL                 bApplyTransformationParams;
         public __value ES_BOOL                 bApplyStationOrientationParams;
         public __value ES_BOOL                 bKeepLastPosition;
         public __value ES_BOOL                 bSendUnsolicitedMessages;
         public __value ES_BOOL                 bSendReflectorPositionData;
         public __value ES_BOOL                 bTryMeasurementMode;
         public __value ES_BOOL                 bHasNivel;
         public __value ES_BOOL                 bHasVideoCamera;
      };  

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct TransformationInputDataT
      {
         public __value ES_TransResultType resultType;  
         public __value double             dTransVal1;
         public __value double             dTransVal2;
         public __value double             dTransVal3;
         public __value double             dRotVal1;
         public __value double             dRotVal2;
         public __value double             dRotVal3;
         public __value double             dScale;
         public __value double             dTransStdVal1;
         public __value double             dTransStdVal2;
         public __value double             dTransStdVal3;
         public __value double             dRotStdVal1;
         public __value double             dRotStdVal2;
         public __value double             dRotStdVal3;
         public __value double             dScaleStd;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct CameraParamsDataT
      {
         public __value int iContrast;
         public __value int iBrightness;
         public __value int iSaturation;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetGridModeParamsRT
      {
         public __value BasicCommandRT packetInfo;
         public __value GridModeDataT  gridModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetUnitsRT
      {
         public __value BasicCommandRT   packetInfo;
         public __value SystemUnitsDataT unitsSettings;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetStationOrientationParamsRT
      {
         public __value  BasicCommandRT          packetInfo;
         public __value  StationOrientationDataT stationOrientation;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetTransformationParamsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  TransformationDataT transformationData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetBoxRegionParamsRT
      {
         public __value  BasicCommandRT packetInfo;
         public __value  BoxRegionDataT boxRegionData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSphereRegionParamsRT
      {
         public __value  BasicCommandRT    packetInfo;
         public __value  SphereRegionDataT sphereRegionData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetEnvironmentParamsRT
      {
         public __value  BasicCommandRT   packetInfo;
         public __value  EnvironmentDataT environmentData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetRefractionParamsRT
      {
         public __value  BasicCommandRT  packetInfo;
         public __value  RefractionDataT refractionData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetStationaryModeParamsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  StationaryModeDataT stationaryModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetContinuousTimeModeParamsRT
      {
         public __value  BasicCommandRT          packetInfo;
         public __value  ContinuousTimeModeDataT continuousTimeModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetContinuousDistanceModeParamsRT
      {
         public __value  BasicCommandRT              packetInfo;
         public __value  ContinuousDistanceModeDataT continuousDistanceModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSphereCenterModeParamsRT
      {
         public __value  BasicCommandRT        packetInfo;
         public __value  SphereCenterModeDataT sphereCenterModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetCircleCenterModeParamsRT
      {
         public __value  BasicCommandRT         packetInfo;
         public __value  CircleCenterModeDataT circleCenterModeData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSearchParamsRT
      {
         public __value  BasicCommandRT    packetInfo;
         public __value  SearchParamsDataT searchParams;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetAdmParamsRT
      {
         public __value  BasicCommandRT packetInfo;
         public __value  AdmParamsDataT admParams;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetSystemSettingsRT
      {
         public __value  BasicCommandRT      packetInfo;
         public __value  SystemSettingsDataT systemSettings;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetTransformationInputParamsRT
      {
         public __value  BasicCommandRT           packetInfo;
         public __value  TransformationInputDataT transformationData;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct GetCameraParamsRT
      {
         public __value  BasicCommandRT    packetInfo;
         public __value  CameraParamsDataT cameraParams;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ESVersionNumberT
      {
         public __value int iMajorVersionNumber;
         public __value int iMinorVersionNumber;
         public __value int iBuildNumber;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SingleMeasResultT
      {
         public __value ReturnDataT packetInfo;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dVal1;
         public __value double      dVal2;
         public __value double      dVal3;
         public __value double      dStd1;
         public __value double      dStd2;
         public __value double      dStd3;
         public __value double      dStdTotal;
         public __value double      dPointingError1;
         public __value double      dPointingError2;
         public __value double      dPointingError3;
         public __value double      dAprioriStd1;
         public __value double      dAprioriStd2;
         public __value double      dAprioriStd3;
         public __value double      dAprioriStdTotal;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct SingleMeasResult2T
      {
         public __value ReturnDataT packetInfo;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dVal1;
         public __value double      dVal2;
         public __value double      dVal3;
         public __value double      dStd1;
         public __value double      dStd2;
         public __value double      dStd3;
         public __value double      dStdTotal;
         public __value double      dCovar12;
         public __value double      dCovar13;
         public __value double      dCovar23;
         public __value double      dPointingErrorH;
         public __value double      dPointingErrorV;
         public __value double      dPointingErrorD;
         public __value double      dAprioriStd1;
         public __value double      dAprioriStd2;
         public __value double      dAprioriStd3;
         public __value double      dAprioriStdTotal;
         public __value double      dAprioriCovar12;
         public __value double      dAprioriCovar13;
         public __value double      dAprioriCovar23;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MeasValueT
      {
         public __value ES_MeasurementStatus status;
         public __value long                 lTime1;
         public __value long                 lTime2;
         public __value double               dVal1;
         public __value double               dVal2;
         public __value double               dVal3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MeasValue2T
      {
         public __value ES_MeasurementStatus status;
         public __value long                 lTime1;
         public __value long                 lTime2;
         public __value double               dVal1;
         public __value double               dVal2;
         public __value double               dVal3;
         public __value double               dAprioriStd1;
         public __value double               dAprioriStd2;
         public __value double               dAprioriStd3;
         public __value double               dAprioriStdTotal;
         public __value double               dAprioriCovar12;
         public __value double               dAprioriCovar13;
         public __value double               dAprioriCovar23;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MultiMeasResultT
      {
         public __value ReturnDataT packetInfo;
         public __value long        lNumberOfResults;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      }; 

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct MultiMeasResult2T
      {
         public __value ReturnDataT packetInfo;
         public __value long        lNumberOfResults;
         public __value ES_MeasMode measMode;
         public __value ES_BOOL     bIsTryMode;
         public __value double      dTemperature;
         public __value double      dPressure;
         public __value double      dHumidity;
      }; 

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ProbeStationaryResultT
      {
         public __value  ReturnDataT             packetInfo;
         public __value  ES_MeasMode             measMode;
         public __value  ES_BOOL                 bIsTryMode;
         public __value  ES_TriggerStatus        triggerStatus;
         public __value  long                    lRotationStatus;
         public __value  int                     iInternalProbeId;        
         public __value  int                     iFieldNumber;        
         public __value  ES_MeasurementTipStatus tipStatus;
         public __value  int                     iInternalTipAdapterId;
         public __value  int                     iTipAdapterInterface;
         public __value  double                  dPosition1;
         public __value  double                  dPosition2;
         public __value  double                  dPosition3;
         public __value  double                  dStdDevPosition1;
         public __value  double                  dStdDevPosition2;
         public __value  double                  dStdDevPosition3;
         public __value  double                  dStdDevPositionTotal;
         public __value  double                  dCovarPosition12;
         public __value  double                  dCovarPosition13;
         public __value  double                  dCovarPosition23;
         public __value  double                  dAprioriStdDevPosition1;
         public __value  double                  dAprioriStdDevPosition2;
         public __value  double                  dAprioriStdDevPosition3;
         public __value  double                  dAprioriStdDevPositionTotal;
         public __value  double                  dAprioriCovarPosition12;
         public __value  double                  dAprioriCovarPosition13;
         public __value  double                  dAprioriCovarPosition23;
         public __value  double                  dQuaternion0;
         public __value  double                  dQuaternion1;
         public __value  double                  dQuaternion2;
         public __value  double                  dQuaternion3;
         public __value  double                  dRotationAngleX;
         public __value  double                  dRotationAngleY;
         public __value  double                  dRotationAngleZ;
         public __value  double                  dStdDevRotationAngleX;
         public __value  double                  dStdDevRotationAngleY;
         public __value  double                  dStdDevRotationAngleZ;
         public __value  double                  dStdDevRotationAngleTotal; 
         public __value  double                  dCovarRotationAngleXY;
         public __value  double                  dCovarRotationAngleXZ;
         public __value  double                  dCovarRotationAngleYZ;
         public __value  double                  dAprioriStdDevRotationAngleX;
         public __value  double                  dAprioriStdDevRotationAngleY;
         public __value  double                  dAprioriStdDevRotationAngleZ;
         public __value  double                  dAprioriStdDevRotationAngleTotal; 
         public __value  double                  dAprioriCovarRotationAngleXY;
         public __value  double                  dAprioriCovarRotationAngleXZ;
         public __value  double                  dAprioriCovarRotationAngleYZ;
         public __value  double                  dTemperature;
         public __value  double                  dPressure;
         public __value  double                  dHumidity;
      }; 

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ProbeMeasValueT
      {
         public __value ES_MeasurementStatus status;
         public __value ES_TriggerStatus     triggerStatus;   
         public __value long                 lRotationStatus;
         public __value long                 lTime1;
         public __value long                 lTime2;
         public __value double               dPosition1;
         public __value double               dPosition2;
         public __value double               dPosition3;
         public __value double               dStdDevPosition1;
         public __value double               dStdDevPosition2;
         public __value double               dStdDevPosition3;
         public __value double               dStdDevPositionTotal;
         public __value double               dCovarPosition12;
         public __value double               dCovarPosition13;
         public __value double               dCovarPosition23;
         public __value double               dQuaternion0;
         public __value double               dQuaternion1;
         public __value double               dQuaternion2;
         public __value double               dQuaternion3;
         public __value double               dRotationAngleX;
         public __value double               dRotationAngleY;
         public __value double               dRotationAngleZ;
         public __value double               dStdDevRotationAngleX;
         public __value double               dStdDevRotationAngleY;
         public __value double               dStdDevRotationAngleZ;
         public __value double               dStdDevRotationAngleTotal;
         public __value double               dCovarRotationAngleXY;
         public __value double               dCovarRotationAngleXZ;
         public __value double               dCovarRotationAngleYZ;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ProbeContinuousResultT
      {
         public __value ReturnDataT             packetInfo;
         public __value long                    lNumberOfResults;
         public __value ES_MeasMode             measMode;
         public __value ES_BOOL                 bIsTryMode;
         public __value int                     iInternalProbeId;
         public __value int                     iFieldNumber;        
         public __value ES_MeasurementTipStatus tipStatus;
         public __value int                     iInternalTipAdapterId;
         public __value int                     iTipAdapterInterface;
         public __value double                  dTemperature;
         public __value double                  dPressure;
         public __value double                  dHumidity;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct NivelResultT
      {
         public __value ReturnDataT    packetInfo;
         public __value ES_NivelStatus nivelStatus;
         public __value double         dXTilt;
         public __value double         dYTilt;
         public __value double         dNivelTemperature;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ReflectorPosResultT
      {
         public __value ReturnDataT packetInfo;
         public __value double       dVal1;
         public __value double       dVal2;
         public __value double       dVal3;
      };

      [System::Runtime::InteropServices::StructLayout(LayoutKind::Sequential, Pack=4)]
      __value struct ProbePosResultT
      {
         public __value ReturnDataT             packetInfo;
         public __value long                    lRotationStatus;
         public __value ES_MeasurementTipStatus tipStatus;
         public __value int                     iInternalTipAdapterId;
         public __value int                     iTipAdapterInterface;
         public __value double                  dPosition1;
         public __value double                  dPosition2;
         public __value double                  dPosition3;
         public __value double                  dQuaternion0;
         public __value double                  dQuaternion1;
         public __value double                  dQuaternion2;
         public __value double                  dQuaternion3;
         public __value double                  dRotationAngleX;
         public __value double                  dRotationAngleY;
         public __value double                  dRotationAngleZ;
      };

   public:
      CESCSAPIReceive() {m_pDataArrived = 0;} // constructor
      

      // ReceiveData to be called by client upon data arrival on socket.
      // Packets are assumed to be complete and single.
      //
      bool ReceiveData(Byte packetAddress __gc [], int packetSize) 
      { 
         if (packetAddress && packetSize > 0)
         {
            void __pin* pDat = &packetAddress[0];
            return ProcessData(pDat, packetSize);
         }
         else
            return false;
      } // ReceiveData


      // GetPacketHeader() allows extracting packet header info 
      // from byte streams (as received from socket in C# clients)
      //
      void GetPacketHeader(Byte packetAddress __gc [], [System::Runtime::InteropServices::Out] PacketHeaderT __gc *header)
      {
         PacketHeaderT dest;
         Byte __pin* pSrc = &packetAddress[0];

         memcpy(&dest, pSrc, sizeof(PacketHeaderT));
         *header = dest;
      } // ByteArrayToHeader()


      // Note: The continuous measurement receiving technique differs from 
      // the approach used in C++ since it is not possible to easily pass 
      // varaibale sized structures from MC++ to C# applications. Use the 
      // 'GetAt...()' functions to access the (indexed) cont measurements.

      bool MultiMeasValueGetAt(int index, [System::Runtime::InteropServices::Out] MeasValueT __gc *measValue)
      {
         MultiMeasResultT *pData = (MultiMeasResultT *)m_pDataArrived;

         if (pData->packetInfo.packetHeader.type != ES_DT_MultiMeasResult)
            return false;

         if (index < 0 || index > pData->lNumberOfResults - 1)
            return false;

         size_t nByteOffset = sizeof(MultiMeasResultT);
         MeasValueT* pData2 = (MeasValueT*)((((unsigned char *)m_pDataArrived)+nByteOffset) + index * sizeof(MeasValueT));
         *measValue = *pData2;
         return true;
      } // MultiMeasValueGetAt()


      bool MultiMeasValue2GetAt(int index, [System::Runtime::InteropServices::Out] MeasValue2T __gc *measValue)
      {
         MultiMeasResult2T *pData = (MultiMeasResult2T *)m_pDataArrived;

         if (pData->packetInfo.packetHeader.type != ES_DT_MultiMeasResult2)
            return false;

         if (index < 0 || index > pData->lNumberOfResults - 1)
            return false;

         size_t nByteOffset = sizeof(MultiMeasResult2T);
         MeasValue2T* pData2 = (MeasValue2T*)((((unsigned char *)m_pDataArrived)+nByteOffset) + index * sizeof(MeasValue2T));
         *measValue = *pData2;
         return true;
      } // MultiMeasValue2GetAt()


      bool ProbeMeasValueGetAt(int index, [System::Runtime::InteropServices::Out] ProbeMeasValueT __gc *measValue)
      {
         ProbeContinuousResultT *pData = (ProbeContinuousResultT *)m_pDataArrived;

         if (pData->packetInfo.packetHeader.type != ES_DT_ContinuousProbeMeasResult)
            return false;

         if (index < 0 || index > pData->lNumberOfResults - 1)
            return false;

         size_t nByteOffset = sizeof(ProbeContinuousResultT);
         ProbeMeasValueT* pData2 = (ProbeMeasValueT*)((((unsigned char *)m_pDataArrived)+nByteOffset) + index * sizeof(ProbeMeasValueT));
         *measValue = *pData2;
         return true;
      } // ProbeMeasValueGetAt()


   protected:
      // Virtual answer handlers - to be overridden by derived class  
      // as far as answers are of interest for client

      // Important: The 'long' data type in C/C++ is 4 bytes (the same as 'int'), 
      // but 8 bytes in C#. Indeed, 'long' data coming from emscon server is 
      // always 4 bytes. Virtual functions defined in MCPP class with 'long' 
      // parameters in fact must use 'int' parameters in derived C# classes.
      // To avoid confusion, all 'long' paramters have been changed to 'int'.
      // Comments /*long*/ have been left for documentation.

      // General handlers
      virtual void OnCommandAnswer(BasicCommandRT) {;}
      virtual void OnErrorAnswer(ErrorResponseT) {;}
      virtual void OnSystemStatusChange(SystemStatusChangeT) {;}
      virtual void OnUnknownAnswer() {;}

      // Measurement and Reflectors data handlers
      virtual void OnSingleMeasurementAnswer(SingleMeasResultT) {;}
      virtual void OnStationaryProbeMeasurementAnswer(ProbeStationaryResultT) {;}
      virtual void OnMultiMeasurementAnswer(MultiMeasResultT) {;} // Not yet supported
      virtual void OnContinuousProbeMeasurementAnswer(ProbeContinuousResultT) {;} // Not yet supported
      virtual void OnNivelMeasurementAnswer(NivelResultT) {;}
      virtual void OnReflectorPosAnswer(ReflectorPosResultT) {;}
      virtual void OnSingleMeasurement2Answer(SingleMeasResult2T) {;}
      virtual void OnMultiMeasurement2Answer(MultiMeasResult2T) {;} // Not yet supported
      virtual void OnProbePosAnswer(ProbePosResultT) {;} 

      // Particular command handlers (called in addition to OnCommandAnswer)

      virtual void OnExitApplicationAnswer() {;}

      virtual void OnGetSystemStatusAnswer(ES_ResultStatus           lastResultStatus,
                                           ES_TrackerProcessorStatus trackerProcessorStatus,
                                           ES_LaserProcessorStatus   laserStatus,
                                           ES_ADMStatus              admStatus,
                                           ESVersionNumberT          esVersionNumber,
                                           ES_WeatherMonitorStatus   weatherMonitorStatus,
                                           int /*long*/              lFlagsValue, // 'long' in C++ is 'int' in C# ! 
                                           int /*long*/              lTrackerSerialNumber) {;}

      virtual void OnGetTrackerStatusAnswer(ES_TrackerStatus) {;}
      virtual void OnSetTemperatureRangeAnswer() {;} 
      virtual void OnGetTemperatureRangeAnswer(ES_TrackerTemperatureRange) {;} 
      virtual void OnSetUnitsAnswer() {;}
      virtual void OnGetUnitsAnswer(SystemUnitsDataT) {;}
      virtual void OnInitializeAnswer() {;}
      virtual void OnReleaseMotorsAnswer() {;} 
      virtual void OnActivateCameraViewAnswer() {;}
      virtual void OnParkAnswer() {;}
      virtual void OnSwitchLaserAnswer() {;} 
      virtual void OnSetStationOrientationParamsAnswer() {;}
      virtual void OnGetStationOrientationParamsAnswer(StationOrientationDataT) {;}
      virtual void OnSetTransformationParamsAnswer() {;}
      virtual void OnGetTransformationParamsAnswer(TransformationDataT) {;}
      virtual void OnSetBoxRegionParamsAnswer() {;} 
      virtual void OnGetBoxRegionParamsAnswer(BoxRegionDataT) {;} 
      virtual void OnSetSphereRegionParamsAnswer() {;} 
      virtual void OnGetSphereRegionParamsAnswer(SphereRegionDataT) {;} 
      virtual void OnSetEnvironmentParamsAnswer() {;} 
      virtual void OnGetEnvironmentParamsAnswer(EnvironmentDataT) {;}
      virtual void OnSetRefractionParamsAnswer() {;}
      virtual void OnGetRefractionParamsAnswer(RefractionDataT) {;}
      virtual void OnSetMeasurementModeAnswer() {;}
      virtual void OnGetMeasurementModeAnswer(ES_MeasMode) {;}
      virtual void OnSetCoordinateSystemTypeAnswer() {;}
      virtual void OnGetCoordinateSystemTypeAnswer(ES_CoordinateSystemType) {;}
      virtual void OnSetStationaryModeParamsAnswer() {;}
      virtual void OnGetStationaryModeParamsAnswer(StationaryModeDataT) {;}
      virtual void OnSetContinuousTimeModeParamsAnswer() {;}
      virtual void OnGetContinuousTimeModeParamsAnswer(ContinuousTimeModeDataT) {;}
      virtual void OnSetContinuousDistanceModeParamsAnswer() {;}
      virtual void OnGetContinuousDistanceModeParamsAnswer(ContinuousDistanceModeDataT) {;}
      virtual void OnSetSphereCenterModeParamsAnswer() {;} 
      virtual void OnGetSphereCenterModeParamsAnswer(SphereCenterModeDataT) {;} 
      virtual void OnSetCircleCenterModeParamsAnswer() {;} 
      virtual void OnGetCircleCenterModeParamsAnswer(CircleCenterModeDataT) {;} 
      virtual void OnSetGridModeParamsAnswer() {;} 
      virtual void OnGetGridModeParamsAnswer(GridModeDataT) {;} 
      virtual void OnSetReflectorAnswer() {;}
      virtual void OnGetReflectorAnswer(int iInternalReflectorId) {;}

      virtual void OnGetReflectorsAnswer(int           iTotalReflectors,
                                         int           iInternalReflectorId,
                                         ES_TargetType targetType,
                                         double        dSurfaceOffset,
                                         unsigned char cReflectorName __gc []) {;}

      virtual void OnSetSearchParamsAnswer() {;}
      virtual void OnGetSearchParamsAnswer(SearchParamsDataT) {;}
      virtual void OnSetAdmParamsAnswer() {;} 
      virtual void OnGetAdmParamsAnswer(AdmParamsDataT) {;} 
      virtual void OnSetSystemSettingsAnswer() {;}
      virtual void OnGetSystemSettingsAnswer(SystemSettingsDataT) {;}
      virtual void OnStartMeasurementAnswer() {;}
      virtual void OnStartNivelMeasurementAnswer() {;}
      virtual void OnStopMeasurementAnswer() {;}
      virtual void OnChangeFaceAnswer() {;}
      virtual void OnGoBirdBathAnswer() {;}
      virtual void OnGoPositionAnswer() {;}
      virtual void OnGoPositionHVDAnswer() {;}
      virtual void OnPositionRelativeHVAnswer() {;}
      virtual void OnPointLaserAnswer() {;}
      virtual void OnPointLaserHVDAnswer() {;}
      virtual void OnMoveHVAnswer() {;}
      virtual void OnGoNivelPositionAnswer() {;}
      virtual void OnGoLastMeasuredPointAnswer() {;}
      virtual void OnFindReflectorAnswer() {;}

      virtual void OnLookForTargetAnswer(double dHzAngle,     
                                         double dVtAngle) {;} 

      virtual void OnGetDirectionAnswer(double dHzAngle,
                                        double dVtAngle) {;}

      virtual void OnCallOrientToGravityAnswer(double dOmega,
                                               double dPhi) {;}

      virtual void OnClearTransformationNominalPointListAnswer() {;}
      virtual void OnClearTransformationActualPointListAnswer() {;}
      virtual void OnAddTransformationNominalPointAnswer() {;}
      virtual void OnAddTransformationActualPointAnswer() {;}
      virtual void OnSetTransformationInputParamsAnswer() {;}
      virtual void OnGetTransformationInputParamsAnswer(TransformationInputDataT) {;}

      virtual void OnCallTransformationAnswer(double dTransVal1,
                                              double dTransVal2,
                                              double dTransVal3,
                                              double dRotVal1,
                                              double dRotVal2,
                                              double dRotVal3,
                                              double dScale,
                                              double dTransStdVal1,
                                              double dTransStdVal2,
                                              double dTransStdVal3,
                                              double dRotStdVal1,
                                              double dRotStdVal2,
                                              double dRotStdVal3,
                                              double dScaleStd,
                                              double dRMS,
                                              double dMaxDev,
                                              double dVarianceFactor) {;}

      virtual void OnGetTransformedPointsAnswer(int iTotalPoints,
                                                double dVal1,
                                                double dVal2,
                                                double dVal3,
                                                double dStd1,
                                                double dStd2,
                                                double dStd3,
                                                double dStdTotal,
                                                double dCovar12,
                                                double dCovar13,
                                                double dCovar23,
                                                double dResidualVal1,
                                                double dResidualVal2,
                                                double dResidualVal3) {;}

      virtual void OnClearDrivePointListAnswer() {;}
      virtual void OnAddDrivePointAnswer() {;}

      virtual void OnCallIntermediateCompensationAnswer(double dTotalRMS,
                                                        double dMaxDev,
                                                        int /*long*/ lWarningFlags) {;}

      virtual void OnSetCompensationAnswer() {;}

      virtual void OnSetStatisticModeAnswer() {;}

      virtual void OnGetStatisticModeAnswer(ES_StatisticMode stationaryMeasurements,
                                            ES_StatisticMode continuousMeasurements) {;}

      virtual void OnSetCameraParamsAnswer() {;}
      virtual void OnGetCameraParamsAnswer(CameraParamsDataT) {;}

      virtual void OnGetStillImageAnswer(ES_StillImageFileType imageFiletype,
                                         int /*long*/ lFileSize,
                                         unsigned char cFileData __gc []) {;}

      virtual void OnGetCompensationAnswer(int iInternalCompensationId) {;}

      virtual void OnGetCompensationsAnswer(int iTotalCompensations,
                                            int iInternalCompensationId,
                                            unsigned char cTrackerCompensationName __gc [],
                                            unsigned char cTrackerCompensationComment __gc [],
                                            unsigned char cADMCompensationName __gc [],
                                            bool bHasMeasurementCameraMounted) {;}

      virtual void OnGetCompensations2Answer(int iTotalCompensations,
                                             int iInternalCompensationId,
                                             unsigned char cTrackerCompensationName __gc [],
                                             unsigned char cTrackerCompensationComment __gc [],
                                             unsigned char cADMCompensationName __gc [],
                                             unsigned char cADMCompensationComment __gc [],
                                             bool bHasMeasurementCameraMounted,
                                             bool bIsActive) {;}

      virtual void OnCheckBirdBathAnswer(double dInitialHzAngle,
                                         double dInitialVtAngle,
                                         double dInitialDistance,
                                         double dHzAngleDiff,
                                         double dVtAngleDiff,
                                         double dDistanceDiff) {;}

      virtual void OnGetTrackerDiagnosticsAnswer(double dTrkPhotoSensorXVal,
                                                 double dTrkPhotoSensorYVal,
                                                 double dTrkPhotoSensorIVal,
                                                 double dRefPhotoSensorXVal,
                                                 double dRefPhotoSensorYVal,
                                                 double dRefPhotoSensorIVal,
                                                 double dADConverterRange,
                                                 double dServoControlPointX,
                                                 double dServoControlPointY,
                                                 double dLaserLightRatio,
                                                 int    iLaserControlMode,
                                                 double dSensorInsideTemperature,
                                                 int    iLCPRunTime,
                                                 int    iLaserTubeRunTime) {;}

      virtual void OnGetADMInfoAnswer(int iFirmwareMajorVersionNumber,
                                      int iFirmwareMinorVersionNumber,
                                      int /*long*/ lSerialNumber) {;}

      virtual void OnGetTPInfoAnswer(int iTPBootMajorVersionNumber,
                                     int iTPBootMinorVersionNumber,
                                     int iTPFirmwareMajorVersionNumber,
                                     int iTPFirmwareMinorVersionNumber,
                                     int iLCPFirmwareMajorVersionNumber,
                                     int iLCPFirmwareMinorVersionNumber,
                                     ES_TrackerProcessorType trackerprocessorType,
                                     ES_TPMicroProcessorType microProcessorType,
                                     int iMicroProcessorClockSpeed,
                                     ES_LTSensorType laserTrackerSensorType) {;}

      virtual void OnGetNivelInfoAnswer(int iFirmwareMajorVersionNumber,
                                        int iFirmwareMinorVersionNumber,
                                        int /*long*/ lSerialNumber) {;}

      virtual void OnSetLaserOnTimerAnswer() {;}

      virtual void OnGetLaserOnTimerAnswer(int iLaserOnTimeOffsetHour,
                                           int iLaserOnTimeOffsetMinute) {;}

      virtual void OnGoBirdBath2Answer() {;}

      virtual void OnConvertDisplayCoordinatesAnswer(double dVal1, 
                                                     double dVal2, 
                                                     double dVal3) {;}

      virtual void OnSetTriggerSourceAnswer() {;}

      virtual void OnGetTriggerSourceAnswer(ES_TriggerSource) {;}

      virtual void OnGetFaceAnswer(ES_TrackerFace) {;}

      virtual void OnGetCamerasAnswer(int iCameraID, 
                                      int /*long*/ lSerialNumber, 
                                      ES_MeasurementCameraType cameraType,
                                      unsigned char cCameraName __gc [],
                                      unsigned char cComment __gc [], 
                                      int iCamerasTotal) {;}

      virtual void OnGetCameraAnswer(int iCameraID, 
                                     bool bIsMounted) {;}

      virtual void OnSetMeasurementCameraModeAnswer() {;}
      virtual void OnGetMeasurementCameraModeAnswer(ES_MeasurementCameraMode) {;}

      virtual void OnGetProbesAnswer(int iProbeID,
                                     int /*long*/ lSerialNumber, 
                                     ES_ProbeType probeType,
                                     int iNumberOfFields,
                                     unsigned char cProbeName __gc [],
                                     unsigned char cProbeComment __gc [],
                                     int iProbesTotal) {;}

      virtual void OnGetProbeAnswer(int iProbeID) {;}

      virtual void OnGetTipAdaptersAnswer(int iTipAdapterID,
                                          int /*long*/ lAssemblyId,
                                          int /*long*/ lSerialNumberLowPart,
                                          int /*long*/ lSerialNumberHighPart,
                                          ES_TipType tipType,
                                          double dRadius, 
                                          double dLength,
                                          unsigned char cTipName __gc[],
                                          unsigned char cTipComment __gc[],
                                          int iTipAdaptersTotal) {;}

      virtual void OnGetTipAdapterAnswer(int iTipAdapterID,
                                         int iTipAdapterInterface) {;}

      virtual void OnGetTCamToTrackerCompensationsAnswer(int iTCamToTrackerCompensationID,
                                                         int iTrackerCompensationID,
                                                         int iCameraID,
                                                         bool bIsActive,
                                                         int /*long*/ lTrackerSerialNumber,
                                                         unsigned char cTCamToTrackerCompensationName __gc [],
                                                         unsigned char  cTCamToTrackerCompensationComment __gc [],
                                                         int iCompensationsTotal) {;}

      virtual void OnGetTCamToTrackerCompensationAnswer(int iTCamToTrackerCompensationId) {;}
      virtual void OnSetTCamToTrackerCompensationAnswer() {;}

      virtual void OnGetProbeCompensationsAnswer(int iProbeCompensationID,
                                                 int iProbeID,
                                                 int iFieldNumber,
                                                 bool bIsActive,
                                                 bool bMarkedForExport,
                                                 bool bPreliminary,
                                                 unsigned char cProbeCompensationName __gc[],
                                                 unsigned char cProbeCompensationComment __gc [],
                                                 int iCompensationsTotal) {;}

      virtual void OnGetProbeCompensationAnswer(int iProbeCompensationID) {;}

      virtual void OnSetProbeCompensationAnswer() {;}


      virtual void OnGetTipToProbeCompensationsAnswer(int iTipToProbeCompensationID,
                                                      int iTipID,
                                                      int iTipInterface,
                                                      int iProbeCompensationID,
                                                      bool bMarkedForExport,
                                                      unsigned char cTipToProbeCompensationName __gc [],
                                                      unsigned char cTipToProbeCompensationComment __gc[],
                                                      int iCompensationsTotal) {;}

      virtual void OnGetTipToProbeCompensationAnswer(int iTipToProbeCompensationID) {;}

      virtual void OnSetExternTriggerParamsAnswer() {;}

      virtual void OnGetExternTriggerParamsAnswer(ES_ClockTransition clockTransition,
                                                  ES_TriggerMode triggerMode,
                                                  ES_TriggerStartSignal startSignal,
                                                  int /*long*/ lMinimalTimeDelay) {;}

      virtual void OnGetErrorEllipsoidAnswer(double dStdDevX, 
                                             double dStdDevY, 
                                             double dStdDevZ, 
                                             double dRotationAngleX, 
                                             double dRotationAngleY, 
                                             double dRotationAngleZ) {;}

      virtual void OnGetMeasurementCameraInfoAnswer(int iFirmwareMajorVersionNumber,
                                                    int iFirmwareMinorVersionNumber,
                                                    int /*long*/ lSerialNumber,
                                                    ES_MeasurementCameraType cameraType,
                                                    unsigned char cName __gc[],
                                                    int /*long*/ lCompensationIdNumber,
                                                    int /*long*/ lZoomSerialNumber,
                                                    int /*long*/ lZoomAdjustmentIdNumber,
                                                    int /*long*/ lZoom2DCompensationIdNumber,
                                                    int /*long*/ lZoomProjCenterCompIdNumber,
                                                    double dMaxDistance,
                                                    double dMinDistance,
                                                    int /*long*/ lNrOfPixelsX,
                                                    int /*long*/ lNrOfPixelsY,
                                                    double dPixelSizeX,
                                                    double dPixelSizeY,
                                                    int /*long*/ lMaxDataRate) {;}

      virtual void OnGetMeasurementProbeInfoAnswer(int  iFirmwareMajorVersionNumber,
                                                   int  iFirmwareMinorVersionNumber,
                                                   int /*long*/ lSerialNumber,
                                                   ES_ProbeType probeType,
                                                   int /*long*/ lCompensationIdNumber,
                                                   int /*long*/ lActiveField,
                                                   ES_ProbeConnectionType connectionType,
                                                   int /*long*/ lNumberOfTipAdapters,
                                                   ES_ProbeButtonType probeButtonType,
                                                   int /*long*/ lNumberOfFields,
                                                   bool bHasWideAngleReceiver,
                                                   int /*long*/ lNumberOfTipDataSets,
                                                   int /*long*/ lNumberOfMelodies,
                                                   int /*long*/ lNumberOfLoudnesSteps) {;}

      virtual void OnSetLongSystemParamAnswer() {;}
      virtual void OnGetLongSystemParamAnswer(int /*long*/ lParameter) {;}
      virtual void OnGetMeasurementStatusInfoAnswer(int /*long*/ measurementStatusInfo) {;}

      virtual void OnGetCurrentPrismPositionAnswer(double dVal1,
                                                   double dVal2,
                                                   double dVal3) {;}

      virtual void OnSetDoubleSystemParamAnswer() {;}
      virtual void OnGetDoubleSystemParamAnswer(double dParameter) {;}
   
      virtual void OnGetObjectTemperatureAnswer(double dObjectTemperature) {;}

      virtual void OnGetTriggerBoardInfoAnswer(ES_TriggerCardType triggerCardType,                                    
                                               int /*long*/ lFPGAVersion,
                                               int /*long*/ lMaxTriggerFrequency,
                                               int /*long*/ lErrorCode) {;}

      virtual void OnGetOverviewCameraInfoAnswer(const ES_OverviewCameraType cameraType,
                                                 unsigned char cCameraName __gc[],
                                                 bool bIsColorCamera,
                                                 double dFocalLength,
                                                 double dHorizontalChipSize,
                                                 double dVerticalChipSize,
                                                 bool bMirrorImageHz,
                                                 bool bMirrorImageVt) {;}
  
      virtual void OnClearCommandQueueAnswer() {;}

      virtual void OnGetADMInfo2Answer(ES_ADMType admType,
                                       unsigned char cADMName __gc[],
                                       int /*long*/ lSerialNumber,
                                       int iFirmwareMajorVersionNumber,
                                       int iFirmwareMinorVersionNumber,
                                       double dMaxDistance,
                                       double dMinDistance,
                                       int iMaxDataRate,
                                       double dAccuracyADMDistance) {;}
   
      virtual void OnGetTrackerInfoAnswer(ES_LTSensorType trackerType,
                                          unsigned char cTrackerName __gc[],
                                          int /*long*/ lSerialNumber,
                                          int /*long*/ lCompensationIdNumber, 
                                          bool bHasADM,
                                          bool bHasOverviewCamera,
                                          bool bHasNivel,
                                          double dNivelMountOffset,
                                          double dMaxDistance,
                                          double dMinDistance,
                                          int iMaxDataRate,
                                          int iNumberOfFaces,
                                          double dHzAngleRange,
                                          double dVtAngleRange,
                                          ES_TrkAccuracyModel accuracyModel,
                                          int iMajLCPFirmwareVersion,
                                          int iMinLCPFirmwareVersion) {;}
   
      virtual void OnGetNivelInfo2Answer(ES_NivelType nivelType,
                                         unsigned char cNivelName __gc[],
                                         int /*long*/ lSerialNumber,
                                         int iFirmwareMajorVersionNumber,
                                         int iFirmwareMinorVersionNumber,
                                         double dMeasurementRange,
                                         double dMeasurementAccuracyOffset,
                                         double dMeasurementAccuracyFactor) {;}

      virtual void OnRestoreStartupConditionsAnswer() {;}

      virtual void OnGetTipToProbeCompensations2Answer(int iTipToProbeCompensationID,
                                                       int iTipID,
                                                       int iTipInterface,
                                                       int iProbeCompensationID,
                                                       bool bMarkedForExport,
                                                       ES_TipToProbeCompensationType compensationType,
                                                       unsigned char cTipToProbeCompensationName __gc [],
                                                       unsigned char cTipToProbeCompensationComment __gc[],
                                                       unsigned char cShankCompensationName __gc [],
                                                       int iCompensationsTotal) {;}

      virtual void OnSetTipAdapterAnswer() {;}

      virtual void OnGetATRInfoAnswer(ES_ATRType atrType,
                                      unsigned char cATRName __gc[],
                                      int /*long*/ lMajFirmwareVersion,
                                      int /*long*/ lMinFirmwareVersion,
                                      int /*long*/ lBuildFirmwareVersion, 
                                      int /*long*/ lHardwareVersion, 
                                      int /*long*/ lErrorcode, 
                                      int /*long*/ lFPGAVersion,
                                      double dMaxDistance,
                                      double dMinDistance,
                                      double dFieldOfView,
                                      double dMaxTrackingSpeed) {;}

      virtual void OnGetMeteoStationInfoAnswer(ES_MeteoStationType meteoStationType,
                                               unsigned char cMeteoStationIdentifier __gc[],
                                               int /*long*/ lMajFirmwareVersion,
                                               int /*long*/ lMinFirmwareVersion) {;}
      
      virtual void OnGetATInfoAnswer(ES_LTSensorType trackerType,
                                     unsigned char cTrackerName __gc[],
                                     int /*long*/ lSerialNumber,
                                     int /*long*/ lMajorFirmwareVersion,
                                     int /*long*/ lMinorFirmwareVersion,
                                     int /*long*/ lProcessorBoardFWBuildNumber,
                                     int /*long*/ lSensorBoardFWBuildNumber,
                                     int /*long*/ lMajorOSVersion,
                                     int /*long*/ lMinorOSVersion,
                                     int /*long*/ lMajorServerSoftwareVersion,
                                     int /*long*/ lMinorServerSoftwareVersion,
                                     int /*long*/ lServerSoftwareBuildNumber,
                                     ES_WLANType wlanType,
                                     ES_TPMicroProcessorType xscaleType,
                                     int /*long*/ lMinMeasureTime,
                                     double dMinDistance,
                                     double dMaxDistance,
                                     double dStdDevDistOffsetADM,
                                     double dStdDevAngleConst,
                                     double dStdDevAngleOffset,
                                     double dStdDevAngleFactor) {;}

      // deprecated - use OnGetATInfoAnswer instead
      virtual void OnGetAT4xxInfoAnswer(ES_LTSensorType trackerType,
                                        unsigned char cTrackerName __gc[],
                                        int /*long*/ lSerialNumber,
                                        int /*long*/ lMajorFirmwareVersion,
                                        int /*long*/ lMinorFirmwareVersion,
                                        int /*long*/ lProcessorBoardFWBuildNumber,
                                        int /*long*/ lSensorBoardFWBuildNumber,
                                        int /*long*/ lMajorOSVersion,
                                        int /*long*/ lMinorOSVersion,
                                        int /*long*/ lMajorServerSoftwareVersion,
                                        int /*long*/ lMinorServerSoftwareVersion,
                                        int /*long*/ lServerSoftwareBuildNumber,
                                        ES_WLANType wlanType,
                                        ES_TPMicroProcessorType xscaleType,
                                        int /*long*/ lMinMeasureTime,
                                        double dMinDistance,
                                        double dMaxDistance,
                                        double dStdDevDistOffsetADM,
                                        double dStdDevAngleConst,
                                        double dStdDevAngleOffset,
                                        double dStdDevAngleFactor) {;}

      virtual void OnGetSystemSoftwareVersionAnswer(unsigned char cSoftwareVersion __gc[]) {;}

      virtual void OnSystemPowerDownAnswer() {;}


   protected:
      virtual bool ProcessData(void* pDataArrived, long lBytes)
      {
         // See ProcessData() equivalent in ES_CPP_API_Def.h file for further explanation.

         // mask arrived data with RT structure in order to figure out type/status
         PacketHeaderT *pData = (PacketHeaderT*)pDataArrived;

         // Diagnostics and overflow prevention.
         if (pData->lPacketSize != lBytes)
         {
            // Beep(300, 50); // info tracing in debug mode only!
            //TRACE2("PacketSize (%ld) differs from TotalBytes (%ld) !\n", pData->lPacketSize, lBytes);

            return false; // causes to signal a data receive error
         } // if

         switch (pData->type)
         {
            case ES_DT_Command: // A 'command- type' answer has arrived
            {
               // decode type of command
               BasicCommandRT *pData2 = (BasicCommandRT *)pDataArrived;

               // call general virtual function for commands
               OnCommandAnswer(*pData2);

               // handle error
               if (pData2->status != ES_RS_AllOK)
                  return true; // Exit here, but make sure pData2->status gets forwared.
                            // Do not return false, since data was correctly received.

               // decode type of command
               switch (pData2->command)
               {
                  case ES_C_ExitApplication:
                     OnExitApplicationAnswer();
                     break;

                  case ES_C_GetSystemStatus:
                     {
                     ESVersionNumberT versionNumber;

                     // Compiler does not directly accept '((GetSystemStatusRT*)pDataArrived)->esVersionNumber' as parameter.
                     versionNumber.iBuildNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iBuildNumber;
                     versionNumber.iMajorVersionNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iMajorVersionNumber;
                     versionNumber.iMinorVersionNumber = ((GetSystemStatusRT*)pDataArrived)->esVersionNumber.iMinorVersionNumber;

                     OnGetSystemStatusAnswer((ES_ResultStatus)((GetSystemStatusRT*)pDataArrived)->lastResultStatus,
                                             (ES_TrackerProcessorStatus)((GetSystemStatusRT*)pDataArrived)->trackerProcessorStatus,
                                             (ES_LaserProcessorStatus)((GetSystemStatusRT*)pDataArrived)->laserStatus,
                                             (ES_ADMStatus)((GetSystemStatusRT*)pDataArrived)->admStatus,
                                             versionNumber, // workaround for problem mentioned above
                                             (ES_WeatherMonitorStatus)((GetSystemStatusRT*)pDataArrived)->weatherMonitorStatus,
                                             ((GetSystemStatusRT*)pDataArrived)->lFlagsValue,
                                             ((GetSystemStatusRT*)pDataArrived)->lTrackerSerialNumber);
                     }
                     break;
    
                  case ES_C_GetTrackerStatus:
                     OnGetTrackerStatusAnswer((ES_TrackerStatus)((GetTrackerStatusRT*)pDataArrived)->trackerStatus);
                     break;

                  case ES_C_SetTemperatureRange:
                     OnSetTemperatureRangeAnswer();
                     break;

                  case ES_C_GetTemperatureRange:
                     OnGetTemperatureRangeAnswer((ES_TrackerTemperatureRange)((GetTemperatureRangeRT*)pDataArrived)->temperatureRange);
                     break;

                  case ES_C_SetUnits:
                     OnSetUnitsAnswer();
                     break;

                  case ES_C_GetUnits:
                     OnGetUnitsAnswer(((GetUnitsRT*)pDataArrived)->unitsSettings);
                     break;
    
                  case ES_C_Initialize:
                     OnInitializeAnswer();
                     break;

                  case ES_C_ReleaseMotors:
                     OnReleaseMotorsAnswer();
                     break;

                  case ES_C_ActivateCameraView:
                     OnActivateCameraViewAnswer();
                     break;

                  case ES_C_Park:
                     OnParkAnswer();
                     break;

                  case ES_C_SwitchLaser:
                     OnSwitchLaserAnswer();
                     break;

                  case ES_C_SetStationOrientationParams:
                     OnSetStationOrientationParamsAnswer();
                     break;

                  case ES_C_GetStationOrientationParams:
                     OnGetStationOrientationParamsAnswer(((GetStationOrientationParamsRT*)pDataArrived)->stationOrientation);
                     break;

                  case ES_C_SetTransformationParams:
                     OnSetTransformationParamsAnswer();
                     break;

                  case ES_C_GetTransformationParams:
                     OnGetTransformationParamsAnswer(((GetTransformationParamsRT*)pDataArrived)->transformationData);
                     break;

                  case ES_C_SetBoxRegionParams:
                     OnSetBoxRegionParamsAnswer();
                     break;

                  case ES_C_GetBoxRegionParams:
                     OnGetBoxRegionParamsAnswer(((GetBoxRegionParamsRT*)pDataArrived)->boxRegionData);
                     break;

                  case ES_C_SetSphereRegionParams:
                     OnSetSphereRegionParamsAnswer();
                     break;

                  case ES_C_GetSphereRegionParams:
                     OnGetSphereRegionParamsAnswer(((GetSphereRegionParamsRT*)pDataArrived)->sphereRegionData);
                     break;

                  case ES_C_SetEnvironmentParams:
                     OnSetEnvironmentParamsAnswer();
                     break;

                  case ES_C_GetEnvironmentParams:
                     OnGetEnvironmentParamsAnswer(((GetEnvironmentParamsRT*)pDataArrived)->environmentData);
                     break;

                  case ES_C_SetRefractionParams:
                     OnSetRefractionParamsAnswer();
                     break;

                  case ES_C_GetRefractionParams:
                     OnGetRefractionParamsAnswer(((GetRefractionParamsRT*)pDataArrived)->refractionData);
                     break;

                  case ES_C_SetMeasurementMode:
                     OnSetMeasurementModeAnswer();
                     break;

                  case ES_C_GetMeasurementMode:
                     OnGetMeasurementModeAnswer((ES_MeasMode)((GetMeasurementModeRT*)pDataArrived)->measMode);
                     break;

                  case ES_C_SetCoordinateSystemType:
                     OnSetCoordinateSystemTypeAnswer();
                     break;

                  case ES_C_GetCoordinateSystemType:
                     OnGetCoordinateSystemTypeAnswer((ES_CoordinateSystemType)((GetCoordinateSystemTypeRT*)pDataArrived)->coordSysType);
                     break;

                  case ES_C_SetStationaryModeParams:
                     OnSetStationaryModeParamsAnswer();
                     break;

                  case ES_C_GetStationaryModeParams:
                     OnGetStationaryModeParamsAnswer(((GetStationaryModeParamsRT*)pDataArrived)->stationaryModeData);
                     break;

                  case ES_C_SetContinuousTimeModeParams:
                     OnSetContinuousTimeModeParamsAnswer();
                     break;

                  case ES_C_GetContinuousTimeModeParams:
                     OnGetContinuousTimeModeParamsAnswer(((GetContinuousTimeModeParamsRT*)pDataArrived)->continuousTimeModeData);
                     break;

                  case ES_C_SetContinuousDistanceModeParams:
                     OnSetContinuousDistanceModeParamsAnswer();
                     break;

                  case ES_C_GetContinuousDistanceModeParams:
                     OnGetContinuousDistanceModeParamsAnswer(((GetContinuousDistanceModeParamsRT*)pDataArrived)->continuousDistanceModeData);
                     break;

                  case ES_C_SetSphereCenterModeParams:
                     OnSetSphereCenterModeParamsAnswer();
                     break;

                  case ES_C_GetSphereCenterModeParams:
                     OnGetSphereCenterModeParamsAnswer(((GetSphereCenterModeParamsRT*)pDataArrived)->sphereCenterModeData);
                     break;

                  case ES_C_SetCircleCenterModeParams:
                     OnSetCircleCenterModeParamsAnswer();
                     break;

                  case ES_C_GetCircleCenterModeParams:
                     OnGetCircleCenterModeParamsAnswer(((GetCircleCenterModeParamsRT*)pDataArrived)->circleCenterModeData);
                     break;

                  case ES_C_SetGridModeParams:
                     OnSetGridModeParamsAnswer();
                     break;
    
                  case ES_C_GetGridModeParams:
                     OnGetGridModeParamsAnswer(((GetGridModeParamsRT*)pDataArrived)->gridModeData);
                     break;

                  case ES_C_GetReflector:
                     OnGetReflectorAnswer(((GetReflectorRT*)pDataArrived)->iInternalReflectorId);
                     break;

                  case ES_C_SetReflector:
                     OnSetReflectorAnswer();
                     break;

                  case ES_C_GetReflectors:
                     {
                        Byte pName __gc[] = StringToByteArray(sizeof(((GetReflectorsRT*)pDataArrived)->cReflectorName),
                                                              &((GetReflectorsRT*)pDataArrived)->cReflectorName[0]);

                        OnGetReflectorsAnswer(((GetReflectorsRT*)pDataArrived)->iTotalReflectors,
                                              ((GetReflectorsRT*)pDataArrived)->iInternalReflectorId,
                                              (ES_TargetType)((GetReflectorsRT*)pDataArrived)->targetType,
                                              ((GetReflectorsRT*)pDataArrived)->dSurfaceOffset,
                                               pName);
                     }
                     break;

                  case ES_C_SetSearchParams:
                     OnSetSearchParamsAnswer();
                     break;

                  case ES_C_GetSearchParams:
                     OnGetSearchParamsAnswer(((GetSearchParamsRT*)pDataArrived)->searchParams);
                     break;

                  case ES_C_SetAdmParams:
                     OnSetAdmParamsAnswer();
                     break;

                  case ES_C_GetAdmParams:
                     OnGetAdmParamsAnswer(((GetAdmParamsRT*)pDataArrived)->admParams);
                     break;

                  case ES_C_SetSystemSettings:
                     OnSetSystemSettingsAnswer();
                     break;

                  case ES_C_GetSystemSettings:
                     OnGetSystemSettingsAnswer(((GetSystemSettingsRT*)pDataArrived)->systemSettings);
                     break;

                  case ES_C_StartMeasurement:
                     OnStartMeasurementAnswer();
                     break;

                  case ES_C_StartNivelMeasurement:
                     OnStartNivelMeasurementAnswer(); // Never called - leave for completeness
                     break;

                  case ES_C_StopMeasurement:
                     OnStopMeasurementAnswer();
                     break;

                  case ES_C_ChangeFace:
                     OnChangeFaceAnswer();
                     break;

                  case ES_C_GoBirdBath:
                     OnGoBirdBathAnswer();
                     break;

                  case ES_C_GoPosition:
                     OnGoPositionAnswer();
                     break;

                  case ES_C_GoPositionHVD:
                     OnGoPositionHVDAnswer();
                     break;

                  case ES_C_PositionRelativeHV:
                     OnPositionRelativeHVAnswer();
                     break;

                  case ES_C_PointLaser:
                     OnPointLaserAnswer();
                     break;

                  case ES_C_PointLaserHVD:
                     OnPointLaserHVDAnswer();
                     break;

                  case ES_C_MoveHV:
                     OnMoveHVAnswer();
                     break;

                  case ES_C_GoNivelPosition:
                     OnGoNivelPositionAnswer();
                     break;

                  case ES_C_GoLastMeasuredPoint:
                     OnGoLastMeasuredPointAnswer();
                     break;

                  case ES_C_FindReflector:
                     OnFindReflectorAnswer();
                     break;

                  case ES_C_Unknown:
                     OnUnknownAnswer();
                     break;

                  case ES_C_LookForTarget:
                     OnLookForTargetAnswer(((LookForTargetRT*)pDataArrived)->dHzAngle,
                                           ((LookForTargetRT*)pDataArrived)->dVtAngle);
                     break;

                  case ES_C_GetDirection:
                     OnGetDirectionAnswer(((GetDirectionRT*)pDataArrived)->dHzAngle,
                                          ((GetDirectionRT*)pDataArrived)->dVtAngle);
                     break;

                  case ES_C_CallOrientToGravity:
                     OnCallOrientToGravityAnswer(((CallOrientToGravityRT*)pDataArrived)->dOmega,
                                                 ((CallOrientToGravityRT*)pDataArrived)->dPhi);
                     break;

                  case ES_C_ClearTransformationNominalPointList:
                     OnClearTransformationNominalPointListAnswer();
                     break;

                  case ES_C_ClearTransformationActualPointList:
                     OnClearTransformationActualPointListAnswer();
                     break;

                  case ES_C_AddTransformationNominalPoint:
                     OnAddTransformationNominalPointAnswer();
                     break;

                  case ES_C_AddTransformationActualPoint:
                     OnAddTransformationActualPointAnswer();
                     break;

                  case ES_C_SetTransformationInputParams:
                     OnSetTransformationInputParamsAnswer();
                     break;

                  case ES_C_GetTransformationInputParams:
                     OnGetTransformationInputParamsAnswer(((GetTransformationInputParamsRT*)pDataArrived)->transformationData);
                     break;

                  case ES_C_CallTransformation:
                     OnCallTransformationAnswer(((CallTransformationRT*)pDataArrived)->dTransVal1,
                                                ((CallTransformationRT*)pDataArrived)->dTransVal2,
                                                ((CallTransformationRT*)pDataArrived)->dTransVal3,
                                                ((CallTransformationRT*)pDataArrived)->dRotVal1,
                                                ((CallTransformationRT*)pDataArrived)->dRotVal2,
                                                ((CallTransformationRT*)pDataArrived)->dRotVal3,
                                                ((CallTransformationRT*)pDataArrived)->dScale,
                                                ((CallTransformationRT*)pDataArrived)->dTransStdVal1,
                                                ((CallTransformationRT*)pDataArrived)->dTransStdVal2,
                                                ((CallTransformationRT*)pDataArrived)->dTransStdVal3,
                                                ((CallTransformationRT*)pDataArrived)->dRotStdVal1,
                                                ((CallTransformationRT*)pDataArrived)->dRotStdVal2,
                                                ((CallTransformationRT*)pDataArrived)->dRotStdVal3,
                                                ((CallTransformationRT*)pDataArrived)->dScaleStd,
                                                ((CallTransformationRT*)pDataArrived)->dRMS,
                                                ((CallTransformationRT*)pDataArrived)->dMaxDev,
                                                ((CallTransformationRT*)pDataArrived)->dVarianceFactor);
                     break;

                  case ES_C_GetTransformedPoints:
                     OnGetTransformedPointsAnswer(((GetTransformedPointsRT*)pDataArrived)->iTotalPoints,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dVal1,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dVal2,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dVal3,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dStd1,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dStd2,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dStd3,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dStdTotal,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dCovar12,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dCovar13,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dCovar23,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dResidualVal1,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dResidualVal2,
                                                  ((GetTransformedPointsRT*)pDataArrived)->dResidualVal3);
                     break;

                  case ES_C_ClearDrivePointList:
                     OnClearDrivePointListAnswer();
                     break;

                  case ES_C_AddDrivePoint:
                     OnAddDrivePointAnswer();
                     break;

                  case ES_C_CallIntermediateCompensation:
                     OnCallIntermediateCompensationAnswer(((CallIntermediateCompensationRT*)pDataArrived)->dTotalRMS,
                                                          ((CallIntermediateCompensationRT*)pDataArrived)->dMaxDev,
                                                          ((CallIntermediateCompensationRT*)pDataArrived)->lWarningFlags);
                     break;

                  case ES_C_SetCompensation:
                     OnSetCompensationAnswer();
                     break;

                  case ES_C_SetStatisticMode:
                     OnSetStatisticModeAnswer();
                     break;

                  case ES_C_GetStatisticMode:
                     OnGetStatisticModeAnswer((ES_StatisticMode)((GetStatisticModeRT*)pDataArrived)->stationaryMeasurements,
                                              (ES_StatisticMode)((GetStatisticModeRT*)pDataArrived)->continuousMeasurements);
                     break;

                  case ES_C_GetStillImage:
                     {
                        Byte pData __gc[] = new Byte __gc [((GetStillImageRT*)pDataArrived)->lFileSize];
                        Byte __pin* pDest = &pData[0];
                        memcpy(pDest, &((GetStillImageRT*)pDataArrived)->cFileStart, ((GetStillImageRT*)pDataArrived)->lFileSize);

                        OnGetStillImageAnswer((ES_StillImageFileType)((GetStillImageRT*)pDataArrived)->imageFiletype,
                                              ((GetStillImageRT*)pDataArrived)->lFileSize,
                                              pData);
                     }
                     break;

                  case ES_C_SetCameraParams:
                     OnSetCameraParamsAnswer();
                     break;

                  case ES_C_GetCameraParams:
                     OnGetCameraParamsAnswer(((GetCameraParamsRT*)pDataArrived)->cameraParams);
                     break;

                  case ES_C_GetCompensation:
                     OnGetCompensationAnswer(((GetCompensationRT*)pDataArrived)->iInternalCompensationId);
                     break;

                  case ES_C_GetCompensations:
                     {
                        Byte pTrkCompName __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cTrackerCompensationName),
                                                                     &((GetCompensationsRT*)pDataArrived)->cTrackerCompensationName[0]);

                        Byte pTrkCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cTrackerCompensationComment),
                                                                    &((GetCompensationsRT*)pDataArrived)->cTrackerCompensationComment[0]);

                        Byte pAdmCompName __gc[] = StringToByteArray(sizeof(((GetCompensationsRT*)pDataArrived)->cADMCompensationName),
                                                                     &((GetCompensationsRT*)pDataArrived)->cADMCompensationName[0]);

                        OnGetCompensationsAnswer(((GetCompensationsRT*)pDataArrived)->iTotalCompensations,
                                                 ((GetCompensationsRT*)pDataArrived)->iInternalCompensationId,
                                                  pTrkCompName,
                                                  pTrkCompCmt,
                                                  pAdmCompName,
                                                  ((GetCompensationsRT*)pDataArrived)->bHasMeasurementCameraMounted != 0);
                     }
                     break;

                     case ES_C_GetCompensations2:
                     {
                        Byte pTrkCompName __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cTrackerCompensationName),
                                                                     &((GetCompensations2RT*)pDataArrived)->cTrackerCompensationName[0]);

                        Byte pTrkCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cTrackerCompensationComment),
                                                                    &((GetCompensations2RT*)pDataArrived)->cTrackerCompensationComment[0]);

                        Byte pAdmCompName __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cADMCompensationName),
                                                                     &((GetCompensations2RT*)pDataArrived)->cADMCompensationName[0]);

                        Byte pAdmCompCmt __gc[] = StringToByteArray(sizeof(((GetCompensations2RT*)pDataArrived)->cADMCompensationComment),
                                                                    &((GetCompensations2RT*)pDataArrived)->cADMCompensationComment[0]);

                        OnGetCompensations2Answer(((GetCompensations2RT*)pDataArrived)->iTotalCompensations,
                                                  ((GetCompensations2RT*)pDataArrived)->iInternalCompensationId,
                                                  pTrkCompName,
                                                  pTrkCompCmt,
                                                  pAdmCompName,
                                                  pAdmCompCmt,
                                                  ((GetCompensations2RT*)pDataArrived)->bHasMeasurementCameraMounted != 0,
                                                  ((GetCompensations2RT*)pDataArrived)->bIsActive != 0);
                     }
                     break;

                  case ES_C_CheckBirdBath:
                     OnCheckBirdBathAnswer(((CheckBirdBathRT*)pDataArrived)->dInitialHzAngle,
                                           ((CheckBirdBathRT*)pDataArrived)->dInitialVtAngle,
                                           ((CheckBirdBathRT*)pDataArrived)->dInitialDistance,
                                           ((CheckBirdBathRT*)pDataArrived)->dHzAngleDiff,
                                           ((CheckBirdBathRT*)pDataArrived)->dVtAngleDiff,
                                           ((CheckBirdBathRT*)pDataArrived)->dDistanceDiff);
                     break;

                  case ES_C_GetTrackerDiagnostics:
                     OnGetTrackerDiagnosticsAnswer(((GetTrackerDiagnosticsRT*)pDataArrived)->dTrkPhotoSensorXVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dTrkPhotoSensorYVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dTrkPhotoSensorIVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dRefPhotoSensorXVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dRefPhotoSensorYVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dRefPhotoSensorIVal,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dADConverterRange,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dServoControlPointX,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dServoControlPointY,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dLaserLightRatio,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->iLaserControlMode,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->dSensorInsideTemperature,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->iLCPRunTime,
                                                   ((GetTrackerDiagnosticsRT*)pDataArrived)->iLaserTubeRunTime);
                     break;

                  case ES_C_GetADMInfo:
                     OnGetADMInfoAnswer(((GetADMInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                        ((GetADMInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                        ((GetADMInfoRT*)pDataArrived)->lSerialNumber);
                     break;

                  case ES_C_GetTPInfo:
                     OnGetTPInfoAnswer(((GetTPInfoRT*)pDataArrived)->iTPBootMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPBootMinorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iTPFirmwareMinorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMajorVersionNumber,
                                       ((GetTPInfoRT*)pDataArrived)->iLCPFirmwareMinorVersionNumber,
                                       (ES_TrackerProcessorType)((GetTPInfoRT*)pDataArrived)->trackerprocessorType,
                                       (ES_TPMicroProcessorType)((GetTPInfoRT*)pDataArrived)->microProcessorType,
                                       ((GetTPInfoRT*)pDataArrived)->iMicroProcessorClockSpeed,
                                       (ES_LTSensorType)((GetTPInfoRT*)pDataArrived)->laserTrackerSensorType);
                     break;

                  case ES_C_GetNivelInfo:
                     OnGetNivelInfoAnswer(((GetNivelInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                          ((GetNivelInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                          ((GetNivelInfoRT*)pDataArrived)->lSerialNumber);
                     break;

                  case ES_C_SetLaserOnTimer:
                     OnSetLaserOnTimerAnswer();
                     break;

                  case ES_C_GetLaserOnTimer:
                     OnGetLaserOnTimerAnswer(((GetLaserOnTimerRT*)pDataArrived)->iLaserOnTimeOffsetHour,
                                             ((GetLaserOnTimerRT*)pDataArrived)->iLaserOnTimeOffsetMinute);
                     break;

                  case ES_C_ConvertDisplayCoordinates:
                     OnConvertDisplayCoordinatesAnswer(((ConvertDisplayCoordinatesRT*)pDataArrived)->dVal1,
                                                       ((ConvertDisplayCoordinatesRT*)pDataArrived)->dVal2,
                                                       ((ConvertDisplayCoordinatesRT*)pDataArrived)->dVal3);
                     break;

                  case ES_C_GoBirdBath2:
                     OnGoBirdBath2Answer();
                     break;

                  case ES_C_GetTriggerSource:
                     OnGetTriggerSourceAnswer((ES_TriggerSource)((GetTriggerSourceRT*)pDataArrived)->triggerSource);
                     break;

                  case ES_C_SetTriggerSource:
                     OnSetTriggerSourceAnswer();
                     break;

                  case ES_C_GetFace:
                     OnGetFaceAnswer((ES_TrackerFace)((GetFaceRT*)pDataArrived)->trackerFace);
                     break;

                  case ES_C_GetCameras:
                     {
                     Byte pCameraName __gc[] = StringToByteArray(sizeof(((GetCamerasRT*)pDataArrived)->cName),
                                                                 &((GetCamerasRT*)pDataArrived)->cName[0]);

                     Byte pCameraCmt __gc[] = StringToByteArray(sizeof(((GetCamerasRT*)pDataArrived)->cComment),
                                                                &((GetCamerasRT*)pDataArrived)->cComment[0]);

                     OnGetCamerasAnswer(((GetCamerasRT*)pDataArrived)->iInternalCameraId,
                                        ((GetCamerasRT*)pDataArrived)->lSerialNumber,
                                        (ES_MeasurementCameraType)((GetCamerasRT*)pDataArrived)->cameraType,
                                        pCameraName,
                                        pCameraCmt,
                                        ((GetCamerasRT*)pDataArrived)->iTotalCameras);
                     }
                     break;

                  case ES_C_GetCamera:
                     OnGetCameraAnswer(((GetCameraRT*)pDataArrived)->iInternalCameraId,
                                       ((GetCameraRT*)pDataArrived)->bMeasurementCameraIsMounted != 0);
                     break;

                  case ES_C_SetMeasurementCameraMode:
                     OnSetMeasurementCameraModeAnswer();
                     break;

                  case ES_C_GetMeasurementCameraMode:
                     OnGetMeasurementCameraModeAnswer((ES_MeasurementCameraMode)((GetMeasurementCameraModeRT*)pDataArrived)->cameraMode);
                     break;

                  case ES_C_GetProbes:
                     {
                        Byte pProbeName __gc[] = StringToByteArray(sizeof(((GetProbesRT*)pDataArrived)->cName),
                                                                   &((GetProbesRT*)pDataArrived)->cName[0]);

                        Byte pProbeCmt __gc[] = StringToByteArray(sizeof(((GetProbesRT*)pDataArrived)->cComment),
                                                                  &((GetProbesRT*)pDataArrived)->cComment[0]);

                        OnGetProbesAnswer(((GetProbesRT*)pDataArrived)->iInternalProbeId,
                                          ((GetProbesRT*)pDataArrived)->lSerialNumber,
                                          (ES_ProbeType)((GetProbesRT*)pDataArrived)->probeType,
                                          ((GetProbesRT*)pDataArrived)->iNumberOfFields,
                                          pProbeName,
                                          pProbeCmt,
                                          ((GetProbesRT*)pDataArrived)->iTotalProbes);
                     }
                     break;

                  case ES_C_GetProbe:
                     OnGetProbeAnswer(((GetProbeRT*)pDataArrived)->iInternalProbeId);
                     break;

                  case ES_C_GetTipAdapters:
                     {
                        Byte pTipAdapterName __gc[] = StringToByteArray(sizeof(((GetTipAdaptersRT*)pDataArrived)->cName),
                                                                        &((GetTipAdaptersRT*)pDataArrived)->cName[0]);

                        Byte pTipAdapterCmt __gc[] = StringToByteArray(sizeof(((GetTipAdaptersRT*)pDataArrived)->cComment),
                                                                       &((GetTipAdaptersRT*)pDataArrived)->cComment[0]);

                        OnGetTipAdaptersAnswer(((GetTipAdaptersRT*)pDataArrived)->iInternalTipAdapterId,
                                               ((GetTipAdaptersRT*)pDataArrived)->lAssemblyId,
                                               ((GetTipAdaptersRT*)pDataArrived)->lSerialNumberLowPart,
                                               ((GetTipAdaptersRT*)pDataArrived)->lSerialNumberHighPart,
                                               (ES_TipType)((GetTipAdaptersRT*)pDataArrived)->tipType,
                                               ((GetTipAdaptersRT*)pDataArrived)->dRadius,
                                               ((GetTipAdaptersRT*)pDataArrived)->dLength,
                                               pTipAdapterName,
                                               pTipAdapterCmt,
                                               ((GetTipAdaptersRT*)pDataArrived)->iTotalTipAdapters);
                     }
                     break;

                  case ES_C_GetTipAdapter:
                     OnGetTipAdapterAnswer(((GetTipAdapterRT*)pDataArrived)->iInternalTipAdapterId, 
                                           ((GetTipAdapterRT*)pDataArrived)->iTipAdapterInterface);
                     break;

                  case ES_C_GetTCamToTrackerCompensations:
                     {
                        Byte pCompName __gc[] = StringToByteArray(sizeof(((GetTCamToTrackerCompensationsRT*)pDataArrived)->cTCamToTrackerCompensationName),
                                                                  &((GetTCamToTrackerCompensationsRT*)pDataArrived)->cTCamToTrackerCompensationName[0]);

                        Byte pCompCmt __gc[] = StringToByteArray(sizeof(((GetTCamToTrackerCompensationsRT*)pDataArrived)->cTCamToTrackerCompensationComment),
                                                                 &((GetTCamToTrackerCompensationsRT*)pDataArrived)->cTCamToTrackerCompensationComment[0]);

                        OnGetTCamToTrackerCompensationsAnswer(((GetTCamToTrackerCompensationsRT*)pDataArrived)->iInternalTCamToTrackerCompensationId,
                                                              ((GetTCamToTrackerCompensationsRT*)pDataArrived)->iInternalTrackerCompensationId,
                                                              ((GetTCamToTrackerCompensationsRT*)pDataArrived)->iInternalCameraId,
                                                              ((GetTCamToTrackerCompensationsRT*)pDataArrived)->bIsActive != 0,
                                                              ((GetTCamToTrackerCompensationsRT*)pDataArrived)->lTrackerSerialNumber,
                                                              pCompName,
                                                              pCompCmt,
                                                              ((GetTCamToTrackerCompensationsRT*)pDataArrived)->iTotalCompensations);
                     }
                     break;

                  case ES_C_GetTCamToTrackerCompensation:
                     OnGetTCamToTrackerCompensationAnswer(((GetTCamToTrackerCompensationRT*)pDataArrived)->iInternalTCamToTrackerCompensationId);
                     break;

                  case ES_C_SetTCamToTrackerCompensation:
                     OnSetTCamToTrackerCompensationAnswer();
                     break;

                  case ES_C_GetProbeCompensations:
                     {
                        Byte pProbeCompName __gc[] = StringToByteArray(sizeof(((GetProbeCompensationsRT*)pDataArrived)->cProbeCompensationName),
                                                                       &((GetProbeCompensationsRT*)pDataArrived)->cProbeCompensationName[0]);

                        Byte pProbeCompCmt __gc[] = StringToByteArray(sizeof(((GetProbeCompensationsRT*)pDataArrived)->cProbeCompensationComment),
                                                                      &((GetProbeCompensationsRT*)pDataArrived)->cProbeCompensationComment[0]);

                        OnGetProbeCompensationsAnswer(((GetProbeCompensationsRT*)pDataArrived)->iInternalProbeCompensationId,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->iInternalProbeId,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->iFieldNumber,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->bIsActive != 0,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->bMarkedForExport != 0,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->bPreliminary != 0,
                                                      pProbeCompName,
                                                      pProbeCompCmt,
                                                      ((GetProbeCompensationsRT*)pDataArrived)->iTotalCompensations);
                     }
                     break;

                  case ES_C_GetProbeCompensation:
                     OnGetProbeCompensationAnswer(((GetProbeCompensationRT*)pDataArrived)->iInternalProbeCompensationId);
                     break;

                  case ES_C_SetProbeCompensation:
                     OnSetProbeCompensationAnswer();
                     break;

                  case ES_C_GetTipToProbeCompensations:
                     {
                        Byte pCompName __gc[] = StringToByteArray(sizeof(((GetTipToProbeCompensationsRT*)pDataArrived)->cTipToProbeCompensationName),
                                                                  &((GetTipToProbeCompensationsRT*)pDataArrived)->cTipToProbeCompensationName[0]);

                        Byte pCompCmt __gc[] = StringToByteArray(sizeof(((GetTipToProbeCompensationsRT*)pDataArrived)->cTipToProbeCompensationComment),
                                                                 &((GetTipToProbeCompensationsRT*)pDataArrived)->cTipToProbeCompensationComment[0]);

                        OnGetTipToProbeCompensationsAnswer(((GetTipToProbeCompensationsRT*)pDataArrived)->iInternalTipToProbeCompensationId,
                                                           ((GetTipToProbeCompensationsRT*)pDataArrived)->iInternalTipAdapterId,
                                                           ((GetTipToProbeCompensationsRT*)pDataArrived)->iTipAdapterInterface,
                                                           ((GetTipToProbeCompensationsRT*)pDataArrived)->iInternalProbeCompensationId,
                                                           ((GetTipToProbeCompensationsRT*)pDataArrived)->bMarkedForExport != 0,
                                                           pCompName,
                                                           pCompCmt,
                                                           ((GetTipToProbeCompensationsRT*)pDataArrived)->iTotalCompensations);
                     }
                     break;

                  case ES_C_GetTipToProbeCompensation:
                     OnGetTipToProbeCompensationAnswer(((GetTipToProbeCompensationRT*)pDataArrived)->iInternalTipToProbeCompensationId);
                     break;

                  case ES_C_SetExternTriggerParams:
                     OnSetExternTriggerParamsAnswer();
                     break;

                  case ES_C_GetExternTriggerParams:
                     OnGetExternTriggerParamsAnswer((ES_ClockTransition)((GetExternTriggerParamsRT*)pDataArrived)->triggerParams.clockTransition,
                                                    (ES_TriggerMode)((GetExternTriggerParamsRT*)pDataArrived)->triggerParams.triggerMode,
                                                    (ES_TriggerStartSignal)((GetExternTriggerParamsRT*)pDataArrived)->triggerParams.startSignal,
                                                    ((GetExternTriggerParamsRT*)pDataArrived)->triggerParams.lMinimalTimeDelay);
                     break;

                  case ES_C_GetErrorEllipsoid:
                     OnGetErrorEllipsoidAnswer(((GetErrorEllipsoidRT*)pDataArrived)->dStdDevX,
                                               ((GetErrorEllipsoidRT*)pDataArrived)->dStdDevY,
                                               ((GetErrorEllipsoidRT*)pDataArrived)->dStdDevZ,
                                               ((GetErrorEllipsoidRT*)pDataArrived)->dRotationAngleX,
                                               ((GetErrorEllipsoidRT*)pDataArrived)->dRotationAngleY,
                                               ((GetErrorEllipsoidRT*)pDataArrived)->dRotationAngleZ);
                     break;

                  case ES_C_GetMeasurementCameraInfo:
                     {
                        Byte pName __gc[] = StringToByteArray(sizeof(((GetMeasurementCameraInfoRT*)pDataArrived)->cName),
                                                              &((GetMeasurementCameraInfoRT*)pDataArrived)->cName[0]);

                        OnGetMeasurementCameraInfoAnswer(((GetMeasurementCameraInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lSerialNumber,
                                                         (ES_MeasurementCameraType)((GetMeasurementCameraInfoRT*)pDataArrived)->cameraType,
                                                         pName,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lCompensationIdNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lZoomSerialNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lZoomAdjustmentIdNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lZoom2DCompensationIdNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lZoomProjCenterCompIdNumber,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->dMaxDistance,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->dMinDistance,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lNrOfPixelsX,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lNrOfPixelsY,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->dPixelSizeX,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->dPixelSizeY,
                                                         ((GetMeasurementCameraInfoRT*)pDataArrived)->lMaxDataRate);
                     }
                     break;

                  case ES_C_GetMeasurementProbeInfo:
                     OnGetMeasurementProbeInfoAnswer(((GetMeasurementProbeInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lSerialNumber,
                                                     (ES_ProbeType)((GetMeasurementProbeInfoRT*)pDataArrived)->probeType,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lCompensationIdNumber,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lActiveField,
                                                     (ES_ProbeConnectionType)((GetMeasurementProbeInfoRT*)pDataArrived)->connectionType,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lNumberOfTipAdapters,
                                                     (ES_ProbeButtonType)((GetMeasurementProbeInfoRT*)pDataArrived)->probeButtonType,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lNumberOfFields,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->bHasWideAngleReceiver != 0,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lNumberOfTipDataSets,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lNumberOfMelodies,
                                                     ((GetMeasurementProbeInfoRT*)pDataArrived)->lNumberOfLoudnesSteps);
                     break;

                  case ES_C_SetLongSystemParameter:
                     OnSetLongSystemParamAnswer();
                     break;

                  case ES_C_GetLongSystemParameter:
                     OnGetLongSystemParamAnswer(((GetLongSystemParamRT*)pDataArrived)->lParameter);
                     break;

                  case ES_C_GetMeasurementStatusInfo:
                     OnGetMeasurementStatusInfoAnswer(((GetMeasurementStatusInfoRT*)pDataArrived)->lMeasurementStatusInfo);
                     break;

                  case ES_C_GetCurrentPrismPosition:
                     OnGetCurrentPrismPositionAnswer(((GetCurrentPrismPositionRT*)pDataArrived)->dVal1,
                                                     ((GetCurrentPrismPositionRT*)pDataArrived)->dVal2,
                                                     ((GetCurrentPrismPositionRT*)pDataArrived)->dVal3);
                     break;

                  case ES_C_SetDoubleSystemParameter:
                     OnSetDoubleSystemParamAnswer();
                     break;

                  case ES_C_GetDoubleSystemParameter:
                     OnGetDoubleSystemParamAnswer(((GetDoubleSystemParamRT*)pDataArrived)->dParameter);
                     break;

                  case ES_C_GetObjectTemperature:
                     OnGetObjectTemperatureAnswer(((GetObjectTemperatureRT*)pDataArrived)->dObjectTemperature);
                     break;

                  case ES_C_GetTriggerBoardInfo:
                     OnGetTriggerBoardInfoAnswer((ES_TriggerCardType)((GetTriggerBoardInfoRT*)pDataArrived)->triggerCardType,                            
                                                 ((GetTriggerBoardInfoRT*)pDataArrived)->lFPGAVersion,
                                                 ((GetTriggerBoardInfoRT*)pDataArrived)->lMaxTriggerFrequency,
                                                 ((GetTriggerBoardInfoRT*)pDataArrived)->lErrorCode);
                     break;

                  case ES_C_GetOverviewCameraInfo:
                     {
                        Byte pCameraName __gc[] = StringToByteArray(sizeof(((GetOverviewCameraInfoRT*)pDataArrived)->cCameraName),
                                    &((GetOverviewCameraInfoRT*)pDataArrived)->cCameraName[0]);

                        OnGetOverviewCameraInfoAnswer((ES_OverviewCameraType)((GetOverviewCameraInfoRT*)pDataArrived)->cameraType,    
                                                      pCameraName, 
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bIsColorCamera != 0,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dFocalLength,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dHorizontalChipSize,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->dVerticalChipSize,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageHz != 0,
                                                      ((GetOverviewCameraInfoRT*)pDataArrived)->bMirrorImageVt != 0);
                     }
                     break;

                  case ES_C_ClearCommandQueue:
                     OnClearCommandQueueAnswer();
                     break;

                  case ES_C_GetADMInfo2:
                     {
                        Byte pADMName __gc[] = StringToByteArray(sizeof(((GetADMInfo2RT*)pDataArrived)->cADMName),
                                    &((GetADMInfo2RT*)pDataArrived)->cADMName[0]);

                        OnGetADMInfo2Answer(((ES_ADMType)((GetADMInfo2RT*)pDataArrived)->admType),
                                            pADMName,
                                            ((GetADMInfo2RT*)pDataArrived)->lSerialNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                            ((GetADMInfo2RT*)pDataArrived)->dMaxDistance,
                                            ((GetADMInfo2RT*)pDataArrived)->dMinDistance,
                                            ((GetADMInfo2RT*)pDataArrived)->iMaxDataRate,
                                            ((GetADMInfo2RT*)pDataArrived)->dAccuracyADMDistance);
                     }
                     break;

                  case ES_C_GetTrackerInfo:
                     {
                        Byte pTrackerName __gc[] = StringToByteArray(sizeof(((GetTrackerInfoRT*)pDataArrived)->cTrackerName),
                                    &((GetTrackerInfoRT*)pDataArrived)->cTrackerName[0]);

                        OnGetTrackerInfoAnswer((ES_LTSensorType)((GetTrackerInfoRT*)pDataArrived)->trackerType,
                                               pTrackerName,
                                               ((GetTrackerInfoRT*)pDataArrived)->lSerialNumber,
                                               ((GetTrackerInfoRT*)pDataArrived)->lCompensationIdNumber, 
                                               ((GetTrackerInfoRT*)pDataArrived)->bHasADM != 0,
                                               ((GetTrackerInfoRT*)pDataArrived)->bHasOverviewCamera != 0,
                                               ((GetTrackerInfoRT*)pDataArrived)->bHasNivel != 0,
                                               ((GetTrackerInfoRT*)pDataArrived)->dNivelMountOffset,
                                               ((GetTrackerInfoRT*)pDataArrived)->dMaxDistance,
                                               ((GetTrackerInfoRT*)pDataArrived)->dMinDistance,
                                               ((GetTrackerInfoRT*)pDataArrived)->iMaxDataRate,
                                               ((GetTrackerInfoRT*)pDataArrived)->iNumberOfFaces,
                                               ((GetTrackerInfoRT*)pDataArrived)->dHzAngleRange,
                                               ((GetTrackerInfoRT*)pDataArrived)->dVtAngleRange,
                                               ((ES_TrkAccuracyModel)((GetTrackerInfoRT*)pDataArrived)->accuracyModel),
                                               ((GetTrackerInfoRT*)pDataArrived)->iMajLCPFirmwareVersion,
                                               ((GetTrackerInfoRT*)pDataArrived)->iMinLCPFirmwareVersion);
                     }
                     break;

                  case ES_C_GetNivelInfo2:
                     {
                        Byte pNivelName __gc[] = StringToByteArray(sizeof(((GetNivelInfo2RT*)pDataArrived)->cNivelName),
                                    &((GetNivelInfo2RT*)pDataArrived)->cNivelName[0]);

                        OnGetNivelInfo2Answer(((ES_NivelType)((GetNivelInfo2RT*)pDataArrived)->nivelType),
                                              pNivelName,
                                              ((GetNivelInfo2RT*)pDataArrived)->lSerialNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->iFirmwareMinorVersionNumber,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementRange,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyOffset,
                                              ((GetNivelInfo2RT*)pDataArrived)->dMeasurementAccuracyFactor);
                     }
                     break;

                  case ES_C_RestoreStartupConditions:
                     OnRestoreStartupConditionsAnswer();
                     break;

                  case ES_C_GetTipToProbeCompensations2:
                     {
                        Byte pCompName __gc[] = StringToByteArray(sizeof(((GetTipToProbeCompensations2RT*)pDataArrived)->cTipToProbeCompensationName),
                                                                  &((GetTipToProbeCompensations2RT*)pDataArrived)->cTipToProbeCompensationName[0]);

                        Byte pCompCmt __gc[] = StringToByteArray(sizeof(((GetTipToProbeCompensations2RT*)pDataArrived)->cTipToProbeCompensationComment),
                                                                 &((GetTipToProbeCompensations2RT*)pDataArrived)->cTipToProbeCompensationComment[0]);

                        Byte pShankCompName __gc[] = StringToByteArray(sizeof(((GetTipToProbeCompensations2RT*)pDataArrived)->cShankCompensationName),
                                                                 &((GetTipToProbeCompensations2RT*)pDataArrived)->cShankCompensationName[0]);

                        OnGetTipToProbeCompensations2Answer(((GetTipToProbeCompensations2RT*)pDataArrived)->iInternalTipToProbeCompensationId,
                                                            ((GetTipToProbeCompensations2RT*)pDataArrived)->iInternalTipAdapterId,
                                                            ((GetTipToProbeCompensations2RT*)pDataArrived)->iTipAdapterInterface,
                                                            ((GetTipToProbeCompensations2RT*)pDataArrived)->iInternalProbeCompensationId,
                                                            ((GetTipToProbeCompensations2RT*)pDataArrived)->bMarkedForExport != 0,
                                                            ((ES_TipToProbeCompensationType)((GetTipToProbeCompensations2RT*)pDataArrived)->compensationType),
                                                            pCompName,
                                                            pCompCmt,
                                                            pShankCompName,
                                                            ((GetTipToProbeCompensations2RT*)pDataArrived)->iTotalCompensations);
                     }
                  break;

                  case ES_C_SetTipAdapter:
                     OnSetTipAdapterAnswer();
                     break;

                  case ES_C_GetATRInfo:
                     {
                        Byte pATRName __gc[] = StringToByteArray(sizeof(((GetATRInfoRT*)pDataArrived)->cATRName),
                                    &((GetATRInfoRT*)pDataArrived)->cATRName[0]);

                        OnGetATRInfoAnswer((ES_ATRType)((GetATRInfoRT*)pDataArrived)->atrType,
                                           pATRName,
                                           ((GetATRInfoRT*)pDataArrived)->lMajFirmwareVersion,
                                           ((GetATRInfoRT*)pDataArrived)->lMinFirmwareVersion, 
                                           ((GetATRInfoRT*)pDataArrived)->lBuildFirmwareVersion,
                                           ((GetATRInfoRT*)pDataArrived)->lHardwareVersion,
                                           ((GetATRInfoRT*)pDataArrived)->lErrorcode,
                                           ((GetATRInfoRT*)pDataArrived)->lFPGAVersion,
                                           ((GetATRInfoRT*)pDataArrived)->dMaxDistance,
                                           ((GetATRInfoRT*)pDataArrived)->dMinDistance,
                                           ((GetATRInfoRT*)pDataArrived)->dFieldOfView,
                                           ((GetATRInfoRT*)pDataArrived)->dMaxTrackingSpeed);
                     }
                     break;

                  case ES_C_GetMeteoStationInfo:
                     {
                        Byte pMeteoStatIdent __gc[] = StringToByteArray(sizeof(((GetMeteoStationInfoRT*)pDataArrived)->cIdentifier),
                                    &((GetMeteoStationInfoRT*)pDataArrived)->cIdentifier[0]);

                        OnGetMeteoStationInfoAnswer((ES_MeteoStationType)((GetMeteoStationInfoRT*)pDataArrived)->meteoStationType,
                                                    pMeteoStatIdent,
                                                    ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMajorVersionNumber,
                                                    ((GetMeteoStationInfoRT*)pDataArrived)->iFirmwareMinorVersionNumber);
                     }
                     break;

                   case ES_C_GetATInfo:
                   //case ES_C_GetAT4xxInfo: // deprecated
                     {
                        Byte pATIdent __gc[] = StringToByteArray(sizeof(((GetATInfoRT*)pDataArrived)->cTrackerName),
                                    &((GetATInfoRT*)pDataArrived)->cTrackerName[0]);

                        OnGetATInfoAnswer((ES_LTSensorType)((GetATInfoRT*)pDataArrived)->trackerType,
                                             pATIdent,
                                             ((GetATInfoRT*)pDataArrived)->lSerialNumber,
                                             ((GetATInfoRT*)pDataArrived)->lMajorFirmwareVersion,
                                             ((GetATInfoRT*)pDataArrived)->lMinorFirmwareVersion,
                                             ((GetATInfoRT*)pDataArrived)->lProcessorBoardFWBuildNumber,
                                             ((GetATInfoRT*)pDataArrived)->lSensorBoardFWBuildNumber,
                                             ((GetATInfoRT*)pDataArrived)->lMajorOSVersion,
                                             ((GetATInfoRT*)pDataArrived)->lMinorOSVersion,
                                             ((GetATInfoRT*)pDataArrived)->lMajorServerSoftwareVersion,
                                             ((GetATInfoRT*)pDataArrived)->lMinorServerSoftwareVersion,
                                             ((GetATInfoRT*)pDataArrived)->lServerSoftwareBuildNumber,
                                             (ES_WLANType)((GetATInfoRT*)pDataArrived)->wlanType,
                                             (ES_TPMicroProcessorType)((GetATInfoRT*)pDataArrived)->xscaleType,
                                             ((GetATInfoRT*)pDataArrived)->lMinMeasureTime,
                                             ((GetATInfoRT*)pDataArrived)->dMinDistance,
                                             ((GetATInfoRT*)pDataArrived)->dMaxDistance,
                                             ((GetATInfoRT*)pDataArrived)->dStdDevDistOffsetADM,
                                             ((GetATInfoRT*)pDataArrived)->dStdDevAngleConst,
                                             ((GetATInfoRT*)pDataArrived)->dStdDevAngleOffset,
                                             ((GetATInfoRT*)pDataArrived)->dStdDevAngleFactor);

                        // deprecated method also called for compatibility reasons. New projects should rather use
                        // OnGetATInfoAnswer. In any case, only ONE of these two virtual methods must be overloaded!
                        OnGetAT4xxInfoAnswer((ES_LTSensorType)((GetAT4xxInfoRT*)pDataArrived)->trackerType,
                                             pATIdent,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lSerialNumber,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMajorFirmwareVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMinorFirmwareVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lProcessorBoardFWBuildNumber,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lSensorBoardFWBuildNumber,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMajorOSVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMinorOSVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMajorServerSoftwareVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMinorServerSoftwareVersion,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lServerSoftwareBuildNumber,
                                             (ES_WLANType)((GetAT4xxInfoRT*)pDataArrived)->wlanType,
                                             (ES_TPMicroProcessorType)((GetAT4xxInfoRT*)pDataArrived)->xscaleType,
                                             ((GetAT4xxInfoRT*)pDataArrived)->lMinMeasureTime,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dMinDistance,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dMaxDistance,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevDistOffsetADM,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleConst,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleOffset,
                                             ((GetAT4xxInfoRT*)pDataArrived)->dStdDevAngleFactor);
                     }
                     break;

                  case ES_C_GetSystemSoftwareVersion:
                     {
                        Byte pSoftwareVersion __gc[] = StringToByteArray(sizeof(((GetSystemSoftwareVersionRT*)pDataArrived)->cSoftwareVersion),
                                    &((GetSystemSoftwareVersionRT*)pDataArrived)->cSoftwareVersion[0]);

                        OnGetSystemSoftwareVersionAnswer(pSoftwareVersion);
                     }
                     break;

                  case ES_C_SystemPowerDown:
                     OnSystemPowerDownAnswer();
                     break;


                  default:
                     ASSERT(false); // uexpected answer
                     return false;  // treat as data receive error
                     break;
               } // switch

               break;
            } // ES_DT_Command


            case ES_DT_Error: 
               OnErrorAnswer(*(ErrorResponseT *)pDataArrived);
               break;

            case ES_DT_SingleMeasResult: 
               OnSingleMeasurementAnswer(*(SingleMeasResultT *)pDataArrived);
               break;

            case ES_DT_StationaryProbeMeasResult: 
               OnStationaryProbeMeasurementAnswer(*(ProbeStationaryResultT *)pDataArrived);
               break;

            case ES_DT_MultiMeasResult: 
               m_pDataArrived = pDataArrived; // save pointer for calling GetNextMeasurement()
               OnMultiMeasurementAnswer(*(MultiMeasResultT *)pDataArrived);
               break;

            case ES_DT_ContinuousProbeMeasResult:
               m_pDataArrived = pDataArrived; // save pointer for calling GetNextMeasurement()
               OnContinuousProbeMeasurementAnswer(*(ProbeContinuousResultT *)pDataArrived);
               break;

            case ES_DT_NivelResult: 
               OnNivelMeasurementAnswer(*(NivelResultT *)pDataArrived);
               break;

            case ES_DT_ReflectorPosResult: 
               OnReflectorPosAnswer(*(ReflectorPosResultT *)pDataArrived);
               break;

            case ES_DT_SystemStatusChange: 
               OnSystemStatusChange(*(SystemStatusChangeT *)pDataArrived);
               break;

            case ES_DT_SingleMeasResult2:
               OnSingleMeasurement2Answer(*(SingleMeasResult2T *)pDataArrived);
               break;

            case ES_DT_MultiMeasResult2: 
               m_pDataArrived = pDataArrived; // save pointer for calling GetNextMeasurement()
               OnMultiMeasurement2Answer(*(MultiMeasResult2T *)pDataArrived);
               break;

            case ES_DT_ProbePosResult: 
               OnProbePosAnswer(*(ProbePosResultT *)pDataArrived);
               break;

            default:
               // Do not treat unknown packets as error - just ignore them
               //TRACE(_T("Unexpected data received (ignored)\n"));
               break;
         } // switch

         return true;
      } // ProcessData()

   private:
      Byte StringToByteArray(int nSize, unsigned short* str)[]
      {
         Byte pData __gc[] = new Byte __gc [2*nSize];
         Byte __pin* pDest = &pData[0];
         memcpy(pDest, str, nSize);
         return pData; // caller must free this string!
      } // StringToByteArray()

   private:
      void *m_pDataArrived;

   }; // class CESCSAPIReceive
}; // namespace EmScon

