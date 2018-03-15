#ifndef TC_IOT_SHADOW_LOCAL_DATA_H
#define TC_IOT_SHADOW_LOCAL_DATA_H

#include "tc_iot_inc.h"

#define TC_IOT_DEVICE_NAME_LEN  25

typedef struct _tc_iot_shadow_local_data {
    tc_iot_shadow_bool         device_switch; /* true means on, false means off. */
    char         name[TC_IOT_DEVICE_NAME_LEN];  /* name or id */
    tc_iot_shadow_number color; /* ansi color index: 0~255, if greater use color=color%256 */
    tc_iot_shadow_number brightness; /* light brightness*/
}tc_iot_shadow_local_data;


#define TC_IOT_TROUBLE_SHOOTING_URL "https://git.io/vN9le"

typedef struct _tc_iot_shadow_control {
    tc_iot_shadow_local_data current;
    tc_iot_shadow_local_data reported;
} tc_iot_shadow_control;

int _tc_iot_shadow_property_control_callback(tc_iot_event_message *msg, const char * src,  void * context);

#define DECLARE_PROPERTY_DEF(var, reported, name, shadow_type, callback) {#name, TC_IOT_PROP_ ## name, sizeof(var), shadow_type, &var, &reported, callback}

#endif /* end of include guard */
