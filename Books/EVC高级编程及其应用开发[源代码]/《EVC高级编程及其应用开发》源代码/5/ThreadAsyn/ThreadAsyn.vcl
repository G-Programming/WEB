<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ThreadAsyn - Win32 (WCE ARMV4) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"ARMV4Dbg/ThreadAsyn.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "DEBUG" /d "UNICODE" /d "_UNICODE" /d "WIN32_PLATFORM_PSPC=400" /d "ARM" /d "_ARM_" /d "ARMV4" /d "_AFXDLL" /r "K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\5\ThreadAsyn\ThreadAsyn.rc"" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSPBF.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WIN32_PLATFORM_PSPC=400" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /FR"ARMV4Dbg/" /Fp"ARMV4Dbg/ThreadAsyn.pch" /Yu"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\5\ThreadAsyn\ThreadAsyn.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\5\ThreadAsyn\ThreadAsynDlg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSPBF.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSPC0.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WIN32_PLATFORM_PSPC=400" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /FR"ARMV4Dbg/" /Fp"ARMV4Dbg/ThreadAsyn.pch" /Yc"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\5\ThreadAsyn\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSPC0.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSPC1.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"ARMV4Dbg/ThreadAsyn.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4Dbg/ThreadAsyn.exe" /subsystem:windowsce,4.20 /MACHINE:IX86 
".\ARMV4Dbg\StdAfx.obj"
".\ARMV4Dbg\ThreadAsyn.obj"
".\ARMV4Dbg\ThreadAsyn.res"
".\ARMV4Dbg\ThreadAsynDlg.obj"
]
Creating command line "link.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSPC1.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
StdAfx.cpp
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
ThreadAsyn.cpp
ThreadAsynDlg.cpp
Generating Code...
Linking...
.\ARMV4Dbg\StdAfx.obj : fatal error LNK1112: module machine type 'ARM' conflicts with target machine type 'X86'
Error executing link.exe.
Creating command line "bscmake.exe /nologo /o"ARMV4Dbg/ThreadAsyn.bsc"  ".\ARMV4Dbg\StdAfx.sbr" ".\ARMV4Dbg\ThreadAsyn.sbr" ".\ARMV4Dbg\ThreadAsynDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
ThreadAsyn.exe - 1 error(s), 2 warning(s)
</pre>
</body>
</html>
