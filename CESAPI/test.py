# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 12:41:29 2018

@author: Peter G. Lane (petergwinlane@gmail.com)
"""

import logging
import os
import platform
import signal
import socket
import sys
import threading
from CESAPI.packet import *
from CESAPI.connection import *

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

class LTSimulator(threading.Thread):
    def __init__(self):
        super().__init__()
        self.__running = True
        self.host = 'localhost'
        self.port = 700
        self.initialized = False

    def stop(self):
        self.__running = False

    def packets(self, data):
        packet_header = PacketHeaderT()
        packet_header.unpack(data)
        packets = None
        if packet_header.type == ES_DT_Command:
            packet_info = BasicCommandCT()
            packet_info.unpack(data)
            if packet_header.type != ES_DT_Command:
              pass
            elif packet_info.command == ES_C_Initialize:
              packet = InitializeCT()
              packet.unpack(data)
              packets = (packet, InitializeRT())
              packet.unpack(data)
              packets = (packet, InitializeRT())
            elif packet_info.command == ES_C_ActivateCameraView:
              packet = ActivateCameraViewCT()
              packet.unpack(data)
              packets = (packet, ActivateCameraViewRT())
            elif packet_info.command == ES_C_Park:
              packet = ParkCT()
              packet.unpack(data)
              packets = (packet, ParkRT())
            elif packet_info.command == ES_C_GoBirdBath:
              packet = GoBirdBathCT()
              packet.unpack(data)
              packets = (packet, GoBirdBathRT())
            elif packet_info.command == ES_C_GoBirdBath2:
              packet = GoBirdBath2CT()
              packet.unpack(data)
              packets = (packet, GoBirdBath2RT())
            elif packet_info.command == ES_C_ChangeFace:
              packet = ChangeFaceCT()
              packet.unpack(data)
              packets = (packet, ChangeFaceRT())
            elif packet_info.command == ES_C_StartNivelMeasurement:
              packet = StartNivelMeasurementCT()
              packet.unpack(data)
              packets = (packet, StartNivelMeasurementRT())
            elif packet_info.command == ES_C_StartMeasurement:
              packet = StartMeasurementCT()
              packet.unpack(data)
              packets = (packet, StartMeasurementRT())
            elif packet_info.command == ES_C_StopMeasurement:
              packet = StopMeasurementCT()
              packet.unpack(data)
              packets = (packet, StopMeasurementRT())
            elif packet_info.command == ES_C_ExitApplication:
              packet = ExitApplicationCT()
              packet.unpack(data)
              packets = (packet, ExitApplicationRT())
            elif packet_info.command == ES_C_GoLastMeasuredPoint:
              packet = GoLastMeasuredPointCT()
              packet.unpack(data)
              packets = (packet, GoLastMeasuredPointRT())
            elif packet_info.command == ES_C_FindReflector:
              packet = FindReflectorCT()
              packet.unpack(data)
              packets = (packet, FindReflectorRT())
            elif packet_info.command == ES_C_SetCoordinateSystemType:
              packet = SetCoordinateSystemTypeCT()
              packet.unpack(data)
              packets = (packet, SetCoordinateSystemTypeRT())
            elif packet_info.command == ES_C_GetCoordinateSystemType:
              packet = GetCoordinateSystemTypeCT()
              packet.unpack(data)
              packets = (packet, GetCoordinateSystemTypeRT())
            elif packet_info.command == ES_C_SetMeasurementMode:
              packet = SetMeasurementModeCT()
              packet.unpack(data)
              packets = (packet, SetMeasurementModeRT())
            elif packet_info.command == ES_C_GetMeasurementMode:
              packet = GetMeasurementModeCT()
              packet.unpack(data)
              packets = (packet, GetMeasurementModeRT())
            elif packet_info.command == ES_C_SetSearchParams:
              packet = SetSearchParamsCT()
              packet.unpack(data)
              packets = (packet, SetSearchParamsRT())
            elif packet_info.command == ES_C_GetSearchParams:
              packet = GetSearchParamsCT()
              packet.unpack(data)
              packets = (packet, GetSearchParamsRT())
            elif packet_info.command == ES_C_SetStationaryModeParams:
              packet = SetStationaryModeParamsCT()
              packet.unpack(data)
              packets = (packet, SetStationaryModeParamsRT())
            elif packet_info.command == ES_C_GetStationaryModeParams:
              packet = GetStationaryModeParamsCT()
              packet.unpack(data)
              packets = (packet, GetStationaryModeParamsRT())
            elif packet_info.command == ES_C_SetSystemSettings:
              packet = SetSystemSettingsCT()
              packet.unpack(data)
              packets = (packet, SetSystemSettingsRT())
            elif packet_info.command == ES_C_GetSystemSettings:
              packet = GetSystemSettingsCT()
              packet.unpack(data)
              packets = (packet, GetSystemSettingsRT())
            elif packet_info.command == ES_C_SetUnits:
              packet = SetUnitsCT()
              packet.unpack(data)
              packets = (packet, SetUnitsRT())
            elif packet_info.command == ES_C_GetUnits:
              packet = GetUnitsCT()
              packet.unpack(data)
              packets = (packet, GetUnitsRT())
            elif packet_info.command == ES_C_GetSystemStatus:
              packet = GetSystemStatusCT()
              packet.unpack(data)
              packets = (packet, GetSystemStatusRT())
            elif packet_info.command == ES_C_GetMeasurementStatusInfo:
              packet = GetMeasurementStatusInfoCT()
              packet.unpack(data)
              packets = (packet, GetMeasurementStatusInfoRT())
            elif packet_info.command == ES_C_GetTrackerStatus:
              packet = GetTrackerStatusCT()
              packet.unpack(data)
              packets = (packet, GetTrackerStatusRT())
            elif packet_info.command == ES_C_SetReflector:
              packet = SetReflectorCT()
              packet.unpack(data)
              packets = (packet, SetReflectorRT())
            elif packet_info.command == ES_C_GetReflectors:
              packet = GetReflectorsCT()
              packet.unpack(data)
              packets = (packet, GetReflectorsRT())
            elif packet_info.command == ES_C_GetReflector:
              packet = GetReflectorCT()
              packet.unpack(data)
              packets = (packet, GetReflectorRT())
            elif packet_info.command == ES_C_SetEnvironmentParams:
              packet = SetEnvironmentParamsCT()
              packet.unpack(data)
              packets = (packet, SetEnvironmentParamsRT())
            elif packet_info.command == ES_C_GetEnvironmentParams:
              packet = GetEnvironmentParamsCT()
              packet.unpack(data)
              packets = (packet, GetEnvironmentParamsRT())
            elif packet_info.command == ES_C_SetRefractionParams:
              packet = SetRefractionParamsCT()
              packet.unpack(data)
              packets = (packet, SetRefractionParamsRT())
            elif packet_info.command == ES_C_GetRefractionParams:
              packet = GetRefractionParamsCT()
              packet.unpack(data)
              packets = (packet, GetRefractionParamsRT())
            elif packet_info.command == ES_C_SetStationOrientationParams:
              packet = SetStationOrientationParamsCT()
              packet.unpack(data)
              packets = (packet, SetStationOrientationParamsRT())
            elif packet_info.command == ES_C_GetStationOrientationParams:
              packet = GetStationOrientationParamsCT()
              packet.unpack(data)
              packets = (packet, GetStationOrientationParamsRT())
            elif packet_info.command == ES_C_SetTransformationParams:
              packet = SetTransformationParamsCT()
              packet.unpack(data)
              packets = (packet, SetTransformationParamsRT())
            elif packet_info.command == ES_C_GetTransformationParams:
              packet = GetTransformationParamsCT()
              packet.unpack(data)
              packets = (packet, GetTransformationParamsRT())
            elif packet_info.command == ES_C_GoPosition:
              packet = GoPositionCT()
              packet.unpack(data)
              packets = (packet, GoPositionRT())
            elif packet_info.command == ES_C_GetDirection:
              packet = GetDirectionCT()
              packet.unpack(data)
              packets = (packet, GetDirectionRT())
            elif packet_info.command == ES_C_GoPositionHVD:
              packet = GoPositionHVDCT()
              packet.unpack(data)
              packets = (packet, GoPositionHVDRT())
            elif packet_info.command == ES_C_PointLaser:
              packet = PointLaserCT()
              packet.unpack(data)
              packets = (packet, PointLaserRT())
            elif packet_info.command == ES_C_PositionRelativeHV:
              packet = PositionRelativeHVCT()
              packet.unpack(data)
              packets = (packet, PositionRelativeHVRT())
            elif packet_info.command == ES_C_PointLaserHVD:
              packet = PointLaserHVDCT()
              packet.unpack(data)
              packets = (packet, PointLaserHVDRT())
            elif packet_info.command == ES_C_MoveHV:
              packet = MoveHVCT()
              packet.unpack(data)
              packets = (packet, MoveHVRT())
            elif packet_info.command == ES_C_GoNivelPosition:
              packet = GoNivelPositionCT()
              packet.unpack(data)
              packets = (packet, GoNivelPositionRT())
            elif packet_info.command == ES_C_CallOrientToGravity:
              packet = CallOrientToGravityCT()
              packet.unpack(data)
              packets = (packet, CallOrientToGravityRT())
            elif packet_info.command == ES_C_SetCompensation:
              packet = SetCompensationCT()
              packet.unpack(data)
              packets = (packet, SetCompensationRT())
            elif packet_info.command == ES_C_GetCompensation:
              packet = GetCompensationCT()
              packet.unpack(data)
              packets = (packet, GetCompensationRT())
            elif packet_info.command == ES_C_GetCompensations:
              packet = GetCompensationsCT()
              packet.unpack(data)
              packets = (packet, GetCompensationsRT())
            elif packet_info.command == ES_C_GetCompensations2:
              packet = GetCompensations2CT()
              packet.unpack(data)
              # packets = (packet, GetCompensations2RT())
              packets = (packet, GetCompensationsRT())
            elif packet_info.command == ES_C_SetStatisticMode:
              packet = SetStatisticModeCT()
              packet.unpack(data)
              packets = (packet, SetStatisticModeRT())
            elif packet_info.command == ES_C_GetStatisticMode:
              packet = GetStatisticModeCT()
              packet.unpack(data)
              packets = (packet, GetStatisticModeRT())
            elif packet_info.command == ES_C_SetCameraParams:
              packet = SetCameraParamsCT()
              packet.unpack(data)
              packets = (packet, SetCameraParamsRT())
            elif packet_info.command == ES_C_GetCameraParams:
              packet = GetCameraParamsCT()
              packet.unpack(data)
              packets = (packet, GetCameraParamsRT())
            elif packet_info.command == ES_C_GetADMInfo2:
              packet = GetADMInfo2CT()
              packet.unpack(data)
              packets = (packet, GetADMInfo2RT())
            elif packet_info.command == ES_C_GetNivelInfo:
              packet = GetNivelInfoCT()
              packet.unpack(data)
              packets = (packet, GetNivelInfoRT())
            elif packet_info.command == ES_C_GetNivelInfo2:
              packet = GetNivelInfo2CT()
              packet.unpack(data)
              packets = (packet, GetNivelInfo2RT())
            elif packet_info.command == ES_C_GetTPInfo:
              packet = GetTPInfoCT()
              packet.unpack(data)
              packets = (packet, GetTPInfoRT())
            elif packet_info.command == ES_C_GetTrackerInfo:
              packet = GetTrackerInfoCT()
              packet.unpack(data)
              packets = (packet, GetTrackerInfoRT())
            elif packet_info.command == ES_C_GetATRInfo:
              packet = GetATRInfoCT()
              packet.unpack(data)
              packets = (packet, GetATRInfoRT())
            elif packet_info.command == ES_C_SetLaserOnTimer:
              packet = SetLaserOnTimerCT()
              packet.unpack(data)
              packets = (packet, SetLaserOnTimerRT())
            elif packet_info.command == ES_C_GetLaserOnTimer:
              packet = GetLaserOnTimerCT()
              packet.unpack(data)
              packets = (packet, GetLaserOnTimerRT())
            elif packet_info.command == ES_C_GetFace:
              packet = GetFaceCT()
              packet.unpack(data)
              packets = (packet, GetFaceRT())
            elif packet_info.command == ES_C_SetLongSystemParameter:
              packet = SetLongSystemParamCT()
              packet.unpack(data)
              packets = (packet, SetLongSystemParamRT())
            elif packet_info.command == ES_C_GetLongSystemParameter:
              packet = GetLongSystemParamCT()
              packet.unpack(data)
              packets = (packet, GetLongSystemParamRT())
            elif packet_info.command == ES_C_GetObjectTemperature:
              packet = GetObjectTemperatureCT()
              packet.unpack(data)
              packets = (packet, GetObjectTemperatureRT())
            elif packet_info.command == ES_C_ClearCommandQueue:
              packet = ClearCommandQueueCT()
              packet.unpack(data)
              packets = (packet, ClearCommandQueueRT())
            elif packet_info.command == ES_C_GetOverviewCameraInfo:
              packet = GetOverviewCameraInfoCT()
              packet.unpack(data)
              packets = (packet, GetOverviewCameraInfoRT())
            elif packet_info.command == ES_C_GetDoubleSystemParameter:
              packet = GetDoubleSystemParamCT()
              packet.unpack(data)
              packets = (packet, GetDoubleSystemParamRT())
            elif packet_info.command == ES_C_SetDoubleSystemParameter:
              packet = SetDoubleSystemParamCT()
              packet.unpack(data)
              packets = (packet, SetDoubleSystemParamRT())
            elif packet_info.command == ES_C_RestoreStartupConditions:
              packet = RestoreStartupConditionsCT()
              packet.unpack(data)
              packets = (packet, RestoreStartupConditionsRT())
            elif packet_info.command == ES_C_GoAndMeasure:
              packet = GoAndMeasureCT()
              packet.unpack(data)
              packets = (packet, GoAndMeasureRT())
            elif packet_info.command == ES_C_GetMeteoStationInfo:
              packet = GetMeteoStationInfoCT()
              packet.unpack(data)
              packets = (packet, GetMeteoStationInfoRT())
            elif packet_info.command == ES_C_GetAT4xxInfo:
              packet = GetAT4xxInfoCT()
              packet.unpack(data)
              packets = (packet, GetAT4xxInfoRT())
            elif packet_info.command == ES_C_GetSystemSoftwareVersion:
              packet = GetSystemSoftwareVersionCT()
              packet.unpack(data)
              packets = (packet, GetSystemSoftwareVersionRT())
        elif packet_header.type == ES_DT_Error:
            packet = ErrorResponseT()
            packet.unpack(data)
            packets = (packet, packet)
        elif packet_header.type == ES_DT_SingleMeasResult:
            packet = SingleMeasResultT()
            packet.unpack(data)
            packets = (packet, packet)
        elif packet_header.type == ES_DT_NivelResult:
            packet = StartNivelMeasurementRT()
            packet.unpack(data)
            packets = (packet, packet)
        elif packet_header.type == ES_DT_ReflectorPosResult:
            packet = ReflectorPosResultT()
            packet.unpack(data)
            packets = (packet, packet)
        elif packet_header.type == ES_DT_SystemStatusChange:
            packet = SystemStatusChangeT()
            packet.unpack(data)
            packets = (packet, packet)
        elif packet_header.type == ES_DT_SingleMeasResult2:
            packet = SingleMeasResult2T()
            packet.unpack(data)
            packets = (packet, packet)
        return packets

    def populateReturnPacket(self, thing):
        # Generic filling of attribute data
        for (index, name) in enumerate(dir(thing)):
            if '__' not in name and 'pack' not in name:
                attribute = getattr(thing, name)
                if type(attribute) == int:
                    setattr(thing, name, index)
                elif type(attribute) == float:
                    setattr(thing, name, float(index)+index/10.0)
                else:
                    self.populateReturnPacket(attribute)

        # Specialized treatment of select responses
        if packetType(thing) == ES_DT_Command:
            logger.debug('Populating response for command {}.'.format(thing.packetInfo.command))
            thing.status = ES_RS_AllOK
            if thing.packetInfo.command == ES_C_GetSystemStatus:
                if self.initialized:
                    thing.trackerProcessorStatus = ES_TPS_Initialized  # ES_TrackerProcessorStatus
                else:
                    thing.trackerProcessorStatus = ES_TPS_Booted  # ES_TrackerProcessorStatus
                thing.lastResultStatus = 0
                thing.laserStatus = ES_LPS_LaserReady  # ES_LaserProcessorStatus
                thing.admStatus = ES_AS_ADMReady  # ES_ADMStatus
                thing.esVersionNumber.iMajorVersionNumber = 3  # ESVersionNumberT
                thing.esVersionNumber.iMinorVersionNumber = 8
                thing.esVersionNumber.iBuildNumber = 900
                thing.weatherMonitorStatus = ES_WMS_ReadOnly  # ES_WeatherMonitorStatus
                thing.lFlagsValue = 0
                thing.lTrackerSerialNumber = 390793
            elif thing.packetInfo.command == ES_C_GetTrackerStatus:
                thing.trackerStatus = ES_TS_Ready  # ES_TrackerStatus
            elif thing.packetInfo.command == ES_C_GetEnvironmentParams:
                thing.environmentData.dTemperature = 22.0
                thing.environmentData.dPressure = 1013.25
                thing.environmentData.dHumidity = 0.42
            elif thing.packetInfo.command == ES_C_GetReflectors:
                thing.iTotalReflectors = 0
                thing.iInternalReflectorId = 0
                thing.targetType = ES_TT_Unknown  # ES_TargetType
                thing.dSurfaceOffset = 3.14
                thing.cReflectorName = 'Rocinante'.encode('UTF-16')[2:]  # 32 bytes max
            elif thing.packetInfo.command == ES_C_GetFace:
                thing.trackerFace = ES_TF_Face1
            elif thing.packetInfo.command == ES_C_GetMeasurementStatusInfo:
                thing.lMeasurementStatusInfo = 0b11101100000001111
            elif thing.packetInfo.command == ES_C_GetCompensations2:
                thing.iTotalCompensations = 0
                thing.iInternalCompensationId = 0
                thing.cTrackerCompensationName = 'DarkSword'.encode('UTF-16')[2:]  # 32 2-byte characters max
                thing.cTrackerCompensationComment = 'There are bats in the belfry.'.encode('UTF-16')[2:]  # 128 2-byte characters max
                thing.cADMCompensationName = 'Talladega'.encode('UTF-16')[2:]  # 32 bytes max
                # thing.cADMCompensationComment = "I'm all jacked up on Mountain Dew!".encode('UTF-16')[2:]  # 128 2-byte characters max
                thing.bHasMeasurementCameraMounted = 0
                thing.bIsActive = 0
            elif thing.packetInfo.command == ES_C_GetRefractionParams:
                thing.refractionData.dIfmRefractionIndex = 1.00027  # RefractionDataT()
                thing.refractionData.dAdmRefractionIndex = 1.00027  # RefractionDataT()

    def run(self):
        PACKET_HEADER_SIZE = 8  # lPacketSize, type
        packet_factory = PacketFactory()
        
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.bind((self.host, self.port))
        sock.listen(1)
        sock.settimeout(1)
        connection = None
        logger.debug('Laser tracker simulator was started on port {}.'.format(self.port))

        while self.__running:
            try:
                logger.debug('Waiting for connection...')
                connection, client_address = sock.accept()
                connection.settimeout(1)
                logger.debug('Laser tracker simulator accepted a connection from {}.'.format(client_address))
                
                while self.__running:
                    try:
                        logger.debug('Attempting to receive a packet...')
                        header_data = connection.recv(PACKET_HEADER_SIZE)
                        if len(header_data) == 0:
                            logger.debug('Laser Tracker is waiting to receive data...')
                            time.sleep(0.2)
                            continue
                        logger.debug('Laser Tracker header data: {}'.format(header_data))
                        packet_header = PacketHeaderT()
                        packet_header.unpack(header_data)
                        logger.debug('Laser Tracker packet size: {}'.format(packet_header.lPacketSize))
            
                        data = header_data + connection.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
                        logger.debug('Laser Tracker data in: {}'.format(data))
                        logger.debug('Laser tracker received {} byte packet'.format(len(data)))
                        packets = self.packets(data)
                        if packets != None:
                            (command_packet, return_packet) = packets
                            logger.debug('Preparing response for command {}...'.format(command_packet.packetInfo.command))
                            self.populateReturnPacket(return_packet)
                            return_data = return_packet.pack()
                            connection.sendall(return_data)
                            logger.debug('Laser tracker data out {}.'.format(return_data))
                            logger.debug('Laser tracker sent a {} byte packet'.format(len(return_data)))

                            # Send expected extra packets
                            if command_packet.packetInfo.command == ES_C_StartNivelMeasurement:
                                nivel_result = NivelResultT()
                                nivel_result.nivelStatus = ES_NS_AllOK  # ES_NivelStatus
                                nivel_result.dXTilt = -0.00010258352964641699
                                nivel_result.dYTilt = -3.748960724910917e-05
                                nivel_result.dNivelTemperature = 0.0
                                return_data = nivel_result.pack()
                                connection.sendall(return_data)
                                logger.debug('Laser tracker nivel result data out {}.'.format(return_data))
                                logger.debug('Laser tracker sent a {} byte packet'.format(len(return_data)))
                            elif command_packet.packetInfo.command == ES_C_Initialize:
                                self.initialized = True
                                status_change = SystemStatusChangeT()
                                status_change.systemStatusChange = ES_SCC_InitializationStatusChanged
                                return_data = status_change.pack()
                                connection.sendall(return_data)
                                logger.debug('Laser tracker status change data out {}.'.format(return_data))
                                logger.debug('Laser tracker sent a {} byte packet'.format(len(return_data)))

                                status_change.systemStatusChange = ES_SSC_MeasStatus_Ready
                                return_data = status_change.pack()
                                connection.sendall(return_data)
                                logger.debug('Laser tracker status change data out {}.'.format(return_data))
                                logger.debug('Laser tracker sent a {} byte packet'.format(len(return_data)))

                                status_change.systemStatusChange = ES_SSC_StatisticModeChanged
                                return_data = status_change.pack()
                                connection.sendall(return_data)
                                logger.debug('Laser tracker status change data out {}.'.format(return_data))
                                logger.debug('Laser tracker sent a {} byte packet'.format(len(return_data)))

                    except socket.timeout:
                        logger.debug('Socket timed out waiting for client packets.')
            except ConnectionResetError:
                logger.debug('Client connection was reset.')
            except ConnectionAbortedError as cae:
                logger.debug('Client connection was aborted.')
            except socket.timeout as ste:
                pass
            finally:
                if connection != None:
                    connection.close()

        sock.close()
        logger.debug('Laser tracker simulator has stopped.')

if __name__ == '__main__':
    sim = LTSimulator()

    sim.start()
    print('<<< Server running. Press Ctrl+C stop... >>>')
    sys.stdout.flush()
    try:
        while True:
            time.sleep(0.2)
    except KeyboardInterrupt:
        sim.stop()
    sim.join()
    print('Laser Tracker Simulator has terminated.')
    
