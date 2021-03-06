/*
 * BLEUtils.h
 *
 *  Created on: Mar 25, 2017
 *      Author: kolban
 */

#ifndef COMPONENTS_CPP_UTILS_BLEUTILS_H_
#define COMPONENTS_CPP_UTILS_BLEUTILS_H_
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)
#include <esp_gattc_api.h>   // ESP32 BLE
#include <esp_gatts_api.h>   // ESP32 BLE
#include <esp_gap_ble_api.h> // ESP32 BLE
#include <string>
#include "BLERemoteDevice.h"

class BLEUtils {
public:
	BLEUtils();
	virtual ~BLEUtils();
	static const char *advTypeToString(uint8_t advType);
	static esp_gatt_id_t buildGattId(esp_bt_uuid_t uuid, uint8_t inst_id=0);

	static esp_gatt_srvc_id_t buildGattSrvcId(esp_gatt_id_t gattId, bool is_primary=true);

	static esp_bt_uuid_t buildUUID(std::string uuid);
	static esp_bt_uuid_t buildUUID(uint16_t uuid);
	static esp_bt_uuid_t buildUUID(uint32_t uuid);
	static char *buildHexData(uint8_t *target, uint8_t *source, uint8_t length);
	static BLERemoteDevice *findByConnId(uint16_t conn_id);
	static BLERemoteDevice *findByAddress(BLEAddress address);
	static std::string gattServiceIdToString(esp_gatt_srvc_id_t srvcId);
	static std::string gattStatusToString(esp_gatt_status_t status);
	static std::string gattServiceToString(uint32_t serviceId);
	static void registerByAddress(BLEAddress address, BLERemoteDevice *pDevice);
	static void registerByConnId(uint16_t conn_id, BLERemoteDevice *pDevice);
	static std::string gattCharacteristicUUIDToString(uint32_t characteristicUUID);
	static void dumpGattClientEvent(
		esp_gattc_cb_event_t event,
		esp_gatt_if_t gattc_if,
		esp_ble_gattc_cb_param_t *evtParam);
	static void dumpGattServerEvent(
		esp_gatts_cb_event_t event,
		esp_gatt_if_t gatts_if,
		esp_ble_gatts_cb_param_t *evtParam);
	static const char* devTypeToString(esp_bt_dev_type_t type);
	static void dumpGapEvent(
		esp_gap_ble_cb_event_t event,
		esp_ble_gap_cb_param_t *param);
	static const char *gapEventToString(uint32_t eventType);
	static const char* searchEventTypeToString(esp_gap_search_evt_t searchEvt);
	static const char* addressTypeToString(esp_ble_addr_type_t type);
	static const char *eventTypeToString(esp_ble_evt_type_t eventType);
};


std::string bt_utils_gatt_client_event_type_to_string(esp_gattc_cb_event_t eventType);
std::string bt_utils_gatt_server_event_type_to_string(esp_gatts_cb_event_t eventType);
#endif // CONFIG_BT_ENABLED
#endif /* COMPONENTS_CPP_UTILS_BLEUTILS_H_ */
