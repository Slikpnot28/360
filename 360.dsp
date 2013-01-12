# Microsoft Developer Studio Project File - Name="360" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=360 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "360.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "360.mak" CFG="360 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "360 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "360 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "360 - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "360 - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /WX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "360 - Win32 Release"
# Name "360 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\360.cpp
# End Source File
# Begin Source File

SOURCE=.\360.rc
# End Source File
# Begin Source File

SOURCE=.\360Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BmpBtn.cpp
# End Source File
# Begin Source File

SOURCE=.\Page1.cpp
# End Source File
# Begin Source File

SOURCE=.\Page2.cpp
# End Source File
# Begin Source File

SOURCE=.\Page3.cpp
# End Source File
# Begin Source File

SOURCE=.\Page4.cpp
# End Source File
# Begin Source File

SOURCE=.\Page5.cpp
# End Source File
# Begin Source File

SOURCE=.\Page6.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\360.h
# End Source File
# Begin Source File

SOURCE=.\360Dlg.h
# End Source File
# Begin Source File

SOURCE=.\BmpBtn.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\Page1.h
# End Source File
# Begin Source File

SOURCE=.\Page2.h
# End Source File
# Begin Source File

SOURCE=.\Page3.h
# End Source File
# Begin Source File

SOURCE=.\Page4.h
# End Source File
# Begin Source File

SOURCE=.\Page5.h
# End Source File
# Begin Source File

SOURCE=.\Page6.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\img\11.bmp
# End Source File
# Begin Source File

SOURCE=.\img\12.bmp
# End Source File
# Begin Source File

SOURCE=.\img\13.bmp
# End Source File
# Begin Source File

SOURCE=.\img\2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\21.bmp
# End Source File
# Begin Source File

SOURCE=.\img\22.bmp
# End Source File
# Begin Source File

SOURCE=.\img\23.bmp
# End Source File
# Begin Source File

SOURCE=.\img\31.bmp
# End Source File
# Begin Source File

SOURCE=.\img\31.ico
# End Source File
# Begin Source File

SOURCE=.\img\32.bmp
# End Source File
# Begin Source File

SOURCE=.\img\33.bmp
# End Source File
# Begin Source File

SOURCE=.\res\360.ico
# End Source File
# Begin Source File

SOURCE=.\res\360.rc2
# End Source File
# Begin Source File

SOURCE=.\img\41.bmp
# End Source File
# Begin Source File

SOURCE=.\img\42.bmp
# End Source File
# Begin Source File

SOURCE=.\img\43.bmp
# End Source File
# Begin Source File

SOURCE=.\img\51.bmp
# End Source File
# Begin Source File

SOURCE=.\img\52.bmp
# End Source File
# Begin Source File

SOURCE=.\img\53.bmp
# End Source File
# Begin Source File

SOURCE=.\img\61.bmp
# End Source File
# Begin Source File

SOURCE=.\img\62.bmp
# End Source File
# Begin Source File

SOURCE=.\img\63.bmp
# End Source File
# Begin Source File

SOURCE=.\img\all1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\all2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\all3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\back.bmp
# End Source File
# Begin Source File

SOURCE=.\img\close1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\close2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\close3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\fast1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\fast2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\fast3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\menu1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\menu2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\menu3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\mini1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\mini2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\mini3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page3.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page4.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page5.bmp
# End Source File
# Begin Source File

SOURCE=.\img\page6.bmp
# End Source File
# Begin Source File

SOURCE=.\img\point1.bmp
# End Source File
# Begin Source File

SOURCE=.\img\point2.bmp
# End Source File
# Begin Source File

SOURCE=.\img\point3.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
