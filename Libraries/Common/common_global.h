#ifndef COMMON_GLOBAL_H
#define COMMON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COMMON_LIBRARY)
#  define COMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

#define NOTIFY_UPGRADE_WILL_INSTALL             "box will install upgrade"
#define NOTIFY_BOX_WILL_RESTART                 "box will restart"

#define NOTIFY_LOGIN_LOGGED_IN                  "logged in"
#define NOTIFY_LOGIN_RELOGGED_IN                "reconnect and logged in"
#define NOTIFY_LOGIN_LOGGED_OUT                 "logged out"
#define NOTIFY_LOGIN_DISCONNECTED               "box disconnected"

#define NOTIFY_FEATURE_UPDATE                   "feature support update"
#define NOTIFY_DISK_UPDATE                      "disk status update"
#define NOTIFY_ANNOTATION_STATUS_CHANGED        "annotation status changed"
#define NOTIFY_CAST_STATUS_CHANGED              "cast status changed"
#define NOTIFY_RECORD_STATUS_CHANGED            "record status changed"
#define NOTIFY_RECORD_SPACE_LEFT_TIME_CHANGED   "record space left time changed"
#define NOTIFY_SHARE_STATUS_CHANGED             "share status changed"
#define NOTIFY_THIRD_PART_APP_STATUS_CHANGED    "third part app status changed"

#define NOTIFY_EVENT_WALLPAPER_SET              "wallpaper set successed"

#endif // COMMON_GLOBAL_H
