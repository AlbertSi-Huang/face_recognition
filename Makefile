#############################################################################
# Makefile for building: face_recognition
# Generated by qmake (3.1) (Qt 5.12.10)
# Project:  face_recognition.pro
# Template: app
# Command: D:\application\qt5\5.12.10\msvc2017_64\bin\qmake.exe -o Makefile face_recognition.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = D:\application\qt5\5.12.10\msvc2017_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\application\qt5\5.12.10\msvc2017_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\application\qt5\5.12.10\msvc2017_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: $(MAKEFILE) FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE) FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: face_recognition.pro ..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\win32-msvc\qmake.conf ..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\spec_pre.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\angle.conf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\windows_vulkan_sdk.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\windows-vulkan.conf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\msvc-desktop.conf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\qconfig.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3danimation.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3danimation_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dextras.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dextras_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dlogic.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dlogic_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3drender.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3drender_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_accessibility_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axbase.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axserver.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_charts.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_charts_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_core.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_core_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_dbus.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designer.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_edid_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_egl_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_fb_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gamepad.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gamepad_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gui.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_help.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_help_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_location.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_location_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_network.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_network_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_nfc.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_opengl.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioning.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioningquick.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioningquick_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qml.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmldebug_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quick.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickshapes_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_repparser.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_repparser_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_scxml.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_scxml_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sensors.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialbus.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialbus_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialport.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sql.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_svg.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_testlib.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_texttospeech.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_texttospeech_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_theme_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uitools.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_vulkan_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webengine.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_websockets.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webview.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_widgets.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_windowsuiautomation_support_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_winextras.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xml.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_zlib_private.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt_functions.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt_config.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\win32-msvc\qmake.conf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\spec_post.prf \
		.qmake.stash \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exclusive_builds.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\msvc-version.conf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\toolchain.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\default_pre.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\default_pre.prf \
		module\algorithm\algorithm.pri \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\resolve_config.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exclusive_builds_post.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\default_post.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\resources.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qtquickcompiler.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\precompile_header.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\warn_on.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\moc.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\opengl.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\uic.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qmake_use.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\file_copies.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\windows.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\testcase_targets.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exceptions.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\yacc.prf \
		..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\lex.prf \
		face_recognition.pro \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebEngineWidgets.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebEngineCore.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Quick.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5PrintSupport.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Widgets.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Gui.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebChannel.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Qml.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Network.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Positioning.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5TextToSpeech.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Core.prl \
		..\..\..\application\qt5\5.12.10\msvc2017_64\lib\qtmain.prl
	$(QMAKE) -o Makefile face_recognition.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\spec_pre.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\angle.conf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\windows_vulkan_sdk.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\windows-vulkan.conf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\msvc-desktop.conf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\qconfig.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3danimation.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3danimation_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dcore.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dextras.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dextras_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dinput.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dlogic.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dlogic_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquick.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickanimation_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickextras_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickinput_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickrender_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3dquickscene2d_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3drender.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_3drender_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_accessibility_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_charts.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_charts_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_core.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_core_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_dbus.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designer.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designer_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_edid_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_egl_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_fb_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gamepad.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gamepad_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gui.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_gui_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_help.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_help_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_location.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_location_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_network.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_network_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_nfc.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_packetprotocol_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioning.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioningquick.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_positioningquick_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qml.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qml_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmldebug_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quick.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quick_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickshapes_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_remoteobjects_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_repparser.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_repparser_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_scxml.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_scxml_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sensors.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialbus.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialbus_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sql.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_sql_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_svg.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_svg_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_texttospeech.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_texttospeech_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_theme_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_vulkan_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webchannel.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webengine.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_websockets.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webview.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_webview_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_windowsuiautomation_support_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_winextras.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xml.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xml_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\modules\qt_lib_zlib_private.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt_functions.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt_config.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\win32-msvc\qmake.conf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\spec_post.prf:
.qmake.stash:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exclusive_builds.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\common\msvc-version.conf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\toolchain.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\default_pre.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\default_pre.prf:
module\algorithm\algorithm.pri:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\resolve_config.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exclusive_builds_post.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\default_post.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\resources.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qtquickcompiler.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\precompile_header.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\warn_on.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qt.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\moc.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\opengl.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\uic.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\qmake_use.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\file_copies.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\win32\windows.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\testcase_targets.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\exceptions.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\yacc.prf:
..\..\..\application\qt5\5.12.10\msvc2017_64\mkspecs\features\lex.prf:
face_recognition.pro:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebEngineWidgets.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebEngineCore.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Quick.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5PrintSupport.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Widgets.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Gui.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5WebChannel.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Qml.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Network.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Positioning.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5TextToSpeech.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\Qt5Core.prl:
..\..\..\application\qt5\5.12.10\msvc2017_64\lib\qtmain.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile face_recognition.pro -spec win32-msvc "CONFIG+=qtquickcompiler"

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
