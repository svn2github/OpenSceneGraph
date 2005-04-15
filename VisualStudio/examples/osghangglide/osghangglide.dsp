# Microsoft Developer Studio Project File - Name="Example osghangglide" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Example osghangglide - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "osghangglide.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "osghangglide.mak" CFG="Example osghangglide - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Example osghangglide - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Example osghangglide - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Example osghangglide - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../../include" /I "../../../../OpenThreads/include" /I "../../../../Producer/include" /I "../../../../3rdParty/include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 OpenThreadsWin32.lib /nologo /subsystem:console /pdb:none /machine:I386 /out:"../../../bin/osghangglide.exe" /libpath:"../../../lib" /libpath:"../../../../OpenThreads/lib/win32" /libpath:"../../../../Producer/lib" /libpath:"../../../../3rdParty/lib"

!ELSEIF  "$(CFG)" == "Example osghangglide - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /dv1 /GR /GX /Zi /Od /I "../../../include" /I "../../../../OpenThreads/include" /I "../../../../Producer/include" /I "../../../../3rdParty/include" /D "_CONSOLE" /D "_MBCS" /D "FL_DLL" /D "WIN32" /D "_DEBUG" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 OpenThreadsWin32d.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"libcmt" /out:"../../../bin/osghangglided.exe" /pdbtype:sept /libpath:"../../../lib" /libpath:"../../../../OpenThreads/lib/win32" /libpath:"../../../../Producer/lib" /libpath:"../../../../3rdParty/lib"
# SUBTRACT LINK32 /incremental:no

!ENDIF 

# Begin Target

# Name "Example osghangglide - Win32 Release"
# Name "Example osghangglide - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Base.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\GliderManipulator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Hat.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\osghangglide.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Sky.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Tank.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Terrain.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Trees.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ";h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\GliderManipulator.h
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\Hat.h
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\terrain_coords.h
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\terrain_normals.h
# End Source File
# Begin Source File

SOURCE=..\..\..\examples\osghangglide\terrain_texcoords.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# End Group
# End Target
# End Project
