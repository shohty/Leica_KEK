
import logging
import time
from CESAPI.packet import *

logging.basicConfig()
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)


class CommandSync(object):
  def __init__(self, connection):
    self.__connection = connection
    self.__timeout = 10000

  def execute(self, packet):
    logger.debug('Executing command {}'.format(packet.packetInfo.command))
    self.__executing = True
    stream = self.__connection._Connection__stream
    stream.write(packet)

    in_packet = None
    return_packet = None
    current_time_ms = lambda: int(round(time.time() * 1000))
    start_time = current_time_ms()
    timeout = self.__timeout
    if packet.packetInfo.command == ES_C_Initialize:
        timeout = 90000
    done = False
    while (self.__executing and not done):
      unread_count = stream.unreadCount()
      if unread_count > 0:
        in_packet = stream.read()
        packet_type = packetType(in_packet)
        if packetType(in_packet) == ES_DT_Command and in_packet.packetInfo.command == packet.packetInfo.command:
          logger.debug('Received response packet for command {}'.format(packet.packetInfo.command))
          return_packet = in_packet
          if in_packet.packetInfo.status != ES_RS_AllOK:
              raise Exception("Command {} failed with status {}".format(in_packet.packetInfo.command, in_packet.packetInfo.status))
          if in_packet.packetInfo.command != ES_C_StartMeasurement and in_packet.packetInfo.command != ES_C_StartNivelMeasurement:
            done = True
        elif packetType(in_packet) == ES_DT_Error:
          raise Exception("Command {} failed with status {}".format(in_packet.command, in_packet.status))
        elif packet_type == ES_DT_SingleMeasResult or packet_type == ES_DT_SingleMeasResult2:
          return_packet = in_packet
          done = True
        elif packet_type == ES_DT_NivelResult:
          self.nivel_measurement = in_packet
          done = True
        elif packet_type == ES_DT_ReflectorPosResult:
          pass
        elif packet_type == ES_DT_SystemStatusChange:
          if packet.packetInfo.command == ES_C_SetCoordinateSystemType and              in_packet.systemStatusChange == ES_SSC_CoordinateSystemTypeChanged:
            done = True
        else:
          logger.debug('Waiting for command response...')
          time.sleep(0.2)
      elapsed_time = current_time_ms() - start_time
      if not done and elapsed_time > timeout:
        raise Exception("Command {} timed out.".format(packet.packetInfo.command))
    self.__executing = False
    logger.debug('Exiting CommandSync.execute(). Elapsed time of command: {} ms'.format(elapsed_time))
    return return_packet
    
  def ActivateCameraView(self):
    packet = ActivateCameraViewCT()
    return self.execute(packet)

  def AddDrivePoint(self, dVal1, dVal2, dVal3, iInternalReflectorId):
    packet = AddDrivePointCT()
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    packet.iInternalReflectorId = iInternalReflectorId
    return self.execute(packet)

  def AddTransformationActualPoint(self, transformationPoint):
    packet = AddTransformationActualPointCT()
    packet.transformationPoint = transformationPoint
    return self.execute(packet)

  def AddTransformationNominalPoint(self, transformationPoint):
    packet = AddTransformationNominalPointCT()
    packet.transformationPoint = transformationPoint
    return self.execute(packet)

  def CallIntermediateCompensation(self):
    packet = CallIntermediateCompensationCT()
    return self.execute(packet)

  def CallOrientToGravity(self):
    packet = CallOrientToGravityCT()
    return self.execute(packet)

  def CallTransformation(self):
    packet = CallTransformationCT()
    return self.execute(packet)

  def ChangeFace(self):
    packet = ChangeFaceCT()
    return self.execute(packet)

  def CheckBirdBath(self):
    packet = CheckBirdBathCT()
    return self.execute(packet)

  def ClearCommandQueue(self, clearQueueType):
    packet = ClearCommandQueueCT()
    packet.clearQueueType = clearQueueType
    return self.execute(packet)

  def ClearDrivePointList(self):
    packet = ClearDrivePointListCT()
    return self.execute(packet)

  def ClearTransformationActualPointList(self):
    packet = ClearTransformationActualPointListCT()
    return self.execute(packet)

  def ClearTransformationNominalPointList(self):
    packet = ClearTransformationNominalPointListCT()
    return self.execute(packet)

  def ConvertDisplayCoordinates(self, conversionType, dVal1, dVal2, dVal3):
    packet = ConvertDisplayCoordinatesCT()
    packet.conversionType = conversionType
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def ExitApplication(self):
    packet = ExitApplicationCT()
    return self.execute(packet)

  def FindReflector(self, dAproxDistance):
    packet = FindReflectorCT()
    packet.dAproxDistance = dAproxDistance
    return self.execute(packet)

  def GetADMInfo2(self):
    packet = GetADMInfo2CT()
    return self.execute(packet)

  def GetADMInfo(self):
    packet = GetADMInfoCT()
    return self.execute(packet)

  def GetAT4xxInfo(self):
    packet = GetAT4xxInfoCT()
    return self.execute(packet)

  def GetATInfo(self):
    packet = GetATInfoCT()
    return self.execute(packet)

  def GetATRInfo(self):
    packet = GetATRInfoCT()
    return self.execute(packet)

  def GetAdmParams(self):
    packet = GetAdmParamsCT()
    return self.execute(packet)

  def GetBoxRegionParams(self):
    packet = GetBoxRegionParamsCT()
    return self.execute(packet)

  def GetCamera(self):
    packet = GetCameraCT()
    return self.execute(packet)

  def GetCameraParams(self):
    packet = GetCameraParamsCT()
    return self.execute(packet)

  def GetCameras(self):
    packet = GetCamerasCT()
    return self.execute(packet)

  def GetCircleCenterModeParams(self):
    packet = GetCircleCenterModeParamsCT()
    return self.execute(packet)

  def GetCompensation(self):
    packet = GetCompensationCT()
    return self.execute(packet)

  def GetCompensations2(self):
    packet = GetCompensations2CT()
    return self.execute(packet)

  def GetCompensations(self):
    packet = GetCompensationsCT()
    return self.execute(packet)

  def GetContinuousDistanceModeParams(self):
    packet = GetContinuousDistanceModeParamsCT()
    return self.execute(packet)

  def GetContinuousTimeModeParams(self):
    packet = GetContinuousTimeModeParamsCT()
    return self.execute(packet)

  def GetCoordinateSystemType(self):
    packet = GetCoordinateSystemTypeCT()
    return self.execute(packet)

  def GetCurrentPrismPosition(self):
    packet = GetCurrentPrismPositionCT()
    return self.execute(packet)

  def GetDirection(self):
    packet = GetDirectionCT()
    return self.execute(packet)

  def GetDoubleSystemParam(self, systemParam):
    packet = GetDoubleSystemParamCT()
    packet.systemParam = systemParam
    return self.execute(packet)

  def GetEnvironmentParams(self):
    packet = GetEnvironmentParamsCT()
    return self.execute(packet)

  def GetErrorEllipsoid(self, dCoord1, dCoord2, dCoord3, dCovar12, dCovar13, dCovar23, dStdDev1, dStdDev2, dStdDev3):
    packet = GetErrorEllipsoidCT()
    packet.dCoord1 = dCoord1
    packet.dCoord2 = dCoord2
    packet.dCoord3 = dCoord3
    packet.dCovar12 = dCovar12
    packet.dCovar13 = dCovar13
    packet.dCovar23 = dCovar23
    packet.dStdDev1 = dStdDev1
    packet.dStdDev2 = dStdDev2
    packet.dStdDev3 = dStdDev3
    return self.execute(packet)

  def GetExternTriggerParams(self):
    packet = GetExternTriggerParamsCT()
    return self.execute(packet)

  def GetFace(self):
    packet = GetFaceCT()
    return self.execute(packet)

  def GetGridModeParams(self):
    packet = GetGridModeParamsCT()
    return self.execute(packet)

  def GetLaserOnTimer(self):
    packet = GetLaserOnTimerCT()
    return self.execute(packet)

  def GetLongSystemParam(self, systemParam):
    packet = GetLongSystemParamCT()
    packet.systemParam = systemParam
    return self.execute(packet)

  def GetMeasurementCameraInfo(self):
    packet = GetMeasurementCameraInfoCT()
    return self.execute(packet)

  def GetMeasurementCameraMode(self):
    packet = GetMeasurementCameraModeCT()
    return self.execute(packet)

  def GetMeasurementMode(self):
    packet = GetMeasurementModeCT()
    return self.execute(packet)

  def GetMeasurementProbeInfo(self):
    packet = GetMeasurementProbeInfoCT()
    return self.execute(packet)

  def GetMeasurementStatusInfo(self):
    packet = GetMeasurementStatusInfoCT()
    return self.execute(packet)

  def GetMeteoStationInfo(self):
    packet = GetMeteoStationInfoCT()
    return self.execute(packet)

  def GetNivelInfo2(self):
    packet = GetNivelInfo2CT()
    return self.execute(packet)

  def GetNivelInfo(self):
    packet = GetNivelInfoCT()
    return self.execute(packet)

  def GetObjectTemperature(self):
    packet = GetObjectTemperatureCT()
    return self.execute(packet)

  def GetOverviewCameraInfo(self):
    packet = GetOverviewCameraInfoCT()
    return self.execute(packet)

  def GetProbe(self):
    packet = GetProbeCT()
    return self.execute(packet)

  def GetProbeCompensation(self):
    packet = GetProbeCompensationCT()
    return self.execute(packet)

  def GetProbeCompensations(self):
    packet = GetProbeCompensationsCT()
    return self.execute(packet)

  def GetProbes(self):
    packet = GetProbesCT()
    return self.execute(packet)

  def GetReflector(self):
    packet = GetReflectorCT()
    return self.execute(packet)

  def GetReflectors(self):
    packet = GetReflectorsCT()
    return self.execute(packet)

  def GetRefractionParams(self):
    packet = GetRefractionParamsCT()
    return self.execute(packet)

  def GetSearchParams(self):
    packet = GetSearchParamsCT()
    return self.execute(packet)

  def GetSphereCenterModeParams(self):
    packet = GetSphereCenterModeParamsCT()
    return self.execute(packet)

  def GetSphereRegionParams(self):
    packet = GetSphereRegionParamsCT()
    return self.execute(packet)

  def GetStationOrientationParams(self):
    packet = GetStationOrientationParamsCT()
    return self.execute(packet)

  def GetStationaryModeParams(self):
    packet = GetStationaryModeParamsCT()
    return self.execute(packet)

  def GetStatisticMode(self):
    packet = GetStatisticModeCT()
    return self.execute(packet)

  def GetStillImage(self, imageFileType):
    packet = GetStillImageCT()
    packet.imageFileType = imageFileType
    return self.execute(packet)

  def GetSystemSettings(self):
    packet = GetSystemSettingsCT()
    return self.execute(packet)

  def GetSystemSoftwareVersion(self):
    packet = GetSystemSoftwareVersionCT()
    return self.execute(packet)

  def GetSystemStatus(self):
    packet = GetSystemStatusCT()
    return self.execute(packet)

  def GetTCamToTrackerCompensation(self):
    packet = GetTCamToTrackerCompensationCT()
    return self.execute(packet)

  def GetTCamToTrackerCompensations(self):
    packet = GetTCamToTrackerCompensationsCT()
    return self.execute(packet)

  def GetTPInfo(self):
    packet = GetTPInfoCT()
    return self.execute(packet)

  def GetTemperatureRange(self):
    packet = GetTemperatureRangeCT()
    return self.execute(packet)

  def GetTipAdapter(self):
    packet = GetTipAdapterCT()
    return self.execute(packet)

  def GetTipAdapters(self):
    packet = GetTipAdaptersCT()
    return self.execute(packet)

  def GetTipToProbeCompensation(self):
    packet = GetTipToProbeCompensationCT()
    return self.execute(packet)

  def GetTipToProbeCompensations2(self):
    packet = GetTipToProbeCompensations2CT()
    return self.execute(packet)

  def GetTipToProbeCompensations(self):
    packet = GetTipToProbeCompensationsCT()
    return self.execute(packet)

  def GetTrackerDiagnostics(self):
    packet = GetTrackerDiagnosticsCT()
    return self.execute(packet)

  def GetTrackerInfo(self):
    packet = GetTrackerInfoCT()
    return self.execute(packet)

  def GetTrackerStatus(self):
    packet = GetTrackerStatusCT()
    return self.execute(packet)

  def GetTransformationInputParams(self):
    packet = GetTransformationInputParamsCT()
    return self.execute(packet)

  def GetTransformationParams(self):
    packet = GetTransformationParamsCT()
    return self.execute(packet)

  def GetTransformedPoints(self):
    packet = GetTransformedPointsCT()
    return self.execute(packet)

  def GetTriggerBoardInfo(self):
    packet = GetTriggerBoardInfoCT()
    return self.execute(packet)

  def GetTriggerSource(self):
    packet = GetTriggerSourceCT()
    return self.execute(packet)

  def GetUnits(self):
    packet = GetUnitsCT()
    return self.execute(packet)

  def GoAndMeasure(self, dVal1, dVal2, dVal3):
    packet = GoAndMeasureCT()
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def GoBirdBath2(self, bClockWise):
    packet = GoBirdBath2CT()
    packet.bClockWise = bClockWise
    return self.execute(packet)

  def GoBirdBath(self):
    packet = GoBirdBathCT()
    return self.execute(packet)

  def GoLastMeasuredPoint(self):
    packet = GoLastMeasuredPointCT()
    return self.execute(packet)

  def GoNivelPosition(self, nivelPosition):
    packet = GoNivelPositionCT()
    packet.nivelPosition = nivelPosition
    return self.execute(packet)

  def GoPosition(self, bUseADM, dVal1, dVal2, dVal3):
    packet = GoPositionCT()
    packet.bUseADM = bUseADM
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def GoPositionHVD(self, bUseADM, dDistance, dHzAngle, dVtAngle):
    packet = GoPositionHVDCT()
    packet.bUseADM = bUseADM
    packet.dDistance = dDistance
    packet.dHzAngle = dHzAngle
    packet.dVtAngle = dVtAngle
    return self.execute(packet)

  def Initialize(self):
    packet = InitializeCT()
    return self.execute(packet)

  def LookForTarget(self, dSearchRadius, dVal1, dVal2, dVal3):
    packet = LookForTargetCT()
    packet.dSearchRadius = dSearchRadius
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def MoveHV(self, iHzSpeed, iVtSpeed):
    packet = MoveHVCT()
    packet.iHzSpeed = iHzSpeed
    packet.iVtSpeed = iVtSpeed
    return self.execute(packet)

  def Park(self):
    packet = ParkCT()
    return self.execute(packet)

  def PointLaser(self, dVal1, dVal2, dVal3):
    packet = PointLaserCT()
    packet.dVal1 = dVal1
    packet.dVal2 = dVal2
    packet.dVal3 = dVal3
    return self.execute(packet)

  def PointLaserHVD(self, dDistance, dHzAngle, dVtAngle):
    packet = PointLaserHVDCT()
    packet.dDistance = dDistance
    packet.dHzAngle = dHzAngle
    packet.dVtAngle = dVtAngle
    return self.execute(packet)

  def PositionRelativeHV(self, dHzVal, dVtVal):
    packet = PositionRelativeHVCT()
    packet.dHzVal = dHzVal
    packet.dVtVal = dVtVal
    return self.execute(packet)

  def ReleaseMotors(self):
    packet = ReleaseMotorsCT()
    return self.execute(packet)

  def RestoreStartupConditions(self):
    packet = RestoreStartupConditionsCT()
    return self.execute(packet)

  def SetAdmParams(self, admParams):
    packet = SetAdmParamsCT()
    packet.admParams = admParams
    return self.execute(packet)

  def SetBoxRegionParams(self, boxRegionData):
    packet = SetBoxRegionParamsCT()
    packet.boxRegionData = boxRegionData
    return self.execute(packet)

  def SetCameraParams(self, cameraParams):
    packet = SetCameraParamsCT()
    packet.cameraParams = cameraParams
    return self.execute(packet)

  def SetCircleCenterModeParams(self, circleCenterModeData):
    packet = SetCircleCenterModeParamsCT()
    packet.circleCenterModeData = circleCenterModeData
    return self.execute(packet)

  def SetCompensation(self, iInternalCompensationId):
    packet = SetCompensationCT()
    packet.iInternalCompensationId = iInternalCompensationId
    return self.execute(packet)

  def SetContinuousDistanceModeParams(self, continuousDistanceModeData):
    packet = SetContinuousDistanceModeParamsCT()
    packet.continuousDistanceModeData = continuousDistanceModeData
    return self.execute(packet)

  def SetContinuousTimeModeParams(self, continuousTimeModeData):
    packet = SetContinuousTimeModeParamsCT()
    packet.continuousTimeModeData = continuousTimeModeData
    return self.execute(packet)

  def SetCoordinateSystemType(self, coordSysType):
    packet = SetCoordinateSystemTypeCT()
    packet.coordSysType = coordSysType
    return self.execute(packet)

  def SetDoubleSystemParam(self, dParameter, systemParam):
    packet = SetDoubleSystemParamCT()
    packet.dParameter = dParameter
    packet.systemParam = systemParam
    return self.execute(packet)

  def SetEnvironmentParams(self, environmentData):
    packet = SetEnvironmentParamsCT()
    packet.environmentData = environmentData
    return self.execute(packet)

  def SetExternTriggerParams(self, triggerParams):
    packet = SetExternTriggerParamsCT()
    packet.triggerParams = triggerParams
    return self.execute(packet)

  def SetGridModeParams(self, gridModeData):
    packet = SetGridModeParamsCT()
    packet.gridModeData = gridModeData
    return self.execute(packet)

  def SetLaserOnTimer(self, iLaserOnTimeOffsetHour, iLaserOnTimeOffsetMinute):
    packet = SetLaserOnTimerCT()
    packet.iLaserOnTimeOffsetHour = iLaserOnTimeOffsetHour
    packet.iLaserOnTimeOffsetMinute = iLaserOnTimeOffsetMinute
    return self.execute(packet)

  def SetLongSystemParam(self, lParameter, systemParam):
    packet = SetLongSystemParamCT()
    packet.lParameter = lParameter
    packet.systemParam = systemParam
    return self.execute(packet)

  def SetMeasurementCameraMode(self, cameraMode):
    packet = SetMeasurementCameraModeCT()
    packet.cameraMode = cameraMode
    return self.execute(packet)

  def SetMeasurementMode(self, measMode):
    packet = SetMeasurementModeCT()
    packet.measMode = measMode
    return self.execute(packet)

  def SetProbeCompensation(self, iInternalProbeCompensationId):
    packet = SetProbeCompensationCT()
    packet.iInternalProbeCompensationId = iInternalProbeCompensationId
    return self.execute(packet)

  def SetReflector(self, iInternalReflectorId):
    packet = SetReflectorCT()
    packet.iInternalReflectorId = iInternalReflectorId
    return self.execute(packet)

  def SetRefractionParams(self, refractionData):
    packet = SetRefractionParamsCT()
    packet.refractionData = refractionData
    return self.execute(packet)

  def SetSearchParams(self, searchParams):
    packet = SetSearchParamsCT()
    packet.searchParams = searchParams
    return self.execute(packet)

  def SetSphereCenterModeParams(self, sphereCenterModeData):
    packet = SetSphereCenterModeParamsCT()
    packet.sphereCenterModeData = sphereCenterModeData
    return self.execute(packet)

  def SetSphereRegionParams(self, sphereRegionData):
    packet = SetSphereRegionParamsCT()
    packet.sphereRegionData = sphereRegionData
    return self.execute(packet)

  def SetStationOrientationParams(self, stationOrientation):
    packet = SetStationOrientationParamsCT()
    packet.stationOrientation = stationOrientation
    return self.execute(packet)

  def SetStationaryModeParams(self, stationaryModeData):
    packet = SetStationaryModeParamsCT()
    packet.stationaryModeData = stationaryModeData
    return self.execute(packet)

  def SetStatisticMode(self, continuousMeasurements, stationaryMeasurements):
    packet = SetStatisticModeCT()
    packet.continuousMeasurements = continuousMeasurements
    packet.stationaryMeasurements = stationaryMeasurements
    return self.execute(packet)

  def SetSystemSettings(self, systemSettings):
    packet = SetSystemSettingsCT()
    packet.systemSettings = systemSettings
    return self.execute(packet)

  def SetTCamToTrackerCompensation(self, iInternalTCamToTrackerCompensationId):
    packet = SetTCamToTrackerCompensationCT()
    packet.iInternalTCamToTrackerCompensationId = iInternalTCamToTrackerCompensationId
    return self.execute(packet)

  def SetTemperatureRange(self, temperatureRange):
    packet = SetTemperatureRangeCT()
    packet.temperatureRange = temperatureRange
    return self.execute(packet)

  def SetTipAdapter(self, iInternalTipAdapterId):
    packet = SetTipAdapterCT()
    packet.iInternalTipAdapterId = iInternalTipAdapterId
    return self.execute(packet)

  def SetTransformationInputParams(self, transformationData):
    packet = SetTransformationInputParamsCT()
    packet.transformationData = transformationData
    return self.execute(packet)

  def SetTransformationParams(self, transformationData):
    packet = SetTransformationParamsCT()
    packet.transformationData = transformationData
    return self.execute(packet)

  def SetTriggerSource(self, triggerSource):
    packet = SetTriggerSourceCT()
    packet.triggerSource = triggerSource
    return self.execute(packet)

  def SetUnits(self, unitsSettings):
    packet = SetUnitsCT()
    packet.unitsSettings = unitsSettings
    return self.execute(packet)

  def StartMeasurement(self):
    packet = StartMeasurementCT()
    return self.execute(packet)

  def StartNivelMeasurement(self):
    packet = StartNivelMeasurementCT()
    return self.execute(packet)

  def SwitchLaser(self, bIsOn):
    packet = SwitchLaserCT()
    packet.bIsOn = bIsOn
    return self.execute(packet)

  def SystemPowerDown(self):
    packet = SystemPowerDownCT()
    return self.execute(packet)

