/*
 * Filename: define_struct_code.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/11/03 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-11-03
 * LastChange: 2020-11-03
 *    Version: v0.0.01
 *
 */
//#include <iostream>
//#include <string.h>
#define char_toupper(c) (u_char) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)



#define PRINT_DMS_MSG(msg_name,type)  if(resp.has_##msg_name()) { \
		if(resp.##msg_name && ! current_wns.##msg_name) { \
			current_wns.##msg_name++; \
			msg_can[1] = DmsWarningType::##type;\
			msg_media_server[1] = DmsWarningType::type \
			msg_media_server[2] = resp.##msg_name(); \
			DLT_LOG(untouch_app, DLT_LOG_INFO, DLT_STRING("[dms_msg_receiver]"), DLT_STRING(#msg_name))); \
			DLT_LOG(untouch_app, DLT_LOG_INFO, DLT_STRING("[dms_msg_receiver]"#msg_name" !")); \
		} \
	} \





PRINT_DMS_MSG(is_close_eye,IS_CLOSE_EYE)
