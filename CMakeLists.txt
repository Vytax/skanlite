cmake_minimum_required(VERSION 2.8.12)

project(skanlite)

set(SKANLITE_VERSION_STRING "2.2.0.0")

# ECM setup (Extended Cmake Modules)
find_package(ECM 1.2.0 REQUIRED NO_MODULE)
# ECM setup2 and include find same cmake module (copied from /usr/share/kde4/apps/cmake/modules/FindSane.cmake)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_SOURCE_DIR}/cmake-modules)

include(FeatureSummary)
include(ECMSetupVersion) # yiels ecm_setup_version
include(ECMGenerateHeaders)
include(CMakePackageConfigHelpers)
include(CheckFunctionExists)
include(KDEInstallDirs) # yields ${XDG_APPS_INSTALL_DIR}
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(GenerateExportHeader)
include(ECMQtDeclareLoggingCategory)

# be not so strict with the poor developer who just wants to use strings
remove_definitions(-DQT_NO_CAST_FROM_BYTEARRAY)

set(REQUIRED_QT_VERSION "5.7.0")
set(KF5_MIN_VERSION "5.55.0")

ecm_setup_version(
  ${SKANLITE_VERSION_STRING}
  VARIABLE_PREFIX SKANLITE
  VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/src/skanlite_version.h"
)

# Dependencies
find_package(Qt5 ${REQUIRED_QT_VERSION} NO_MODULE REQUIRED Core Widgets)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
        CoreAddons # KAboutData
        DocTools # yields kdoctools_create_handbook
        I18n
        KIO # contains the KIOWidgets which we use in target_link_libraries
        XmlGui # KAboutApplicationDialog
)

find_package(KF5Sane ${KF5_MIN_VERSION} REQUIRED)

add_definitions(-DQT_NO_URL_CAST_FROM_STRING)

# Subdirectories
add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(autotests)
add_subdirectory(tests)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
