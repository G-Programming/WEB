<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: SeriesSample - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"X86Dbg/SeriesSample.res" /d UNDER_CE=400 /d _WIN32_WCE=400 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WCE_PLATFORM_STANDARDSDK" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\SeriesSample.rc"" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP5F.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=400 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/SeriesSample.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\CESeries.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\DlgSeriesSetup.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\SeriesSample.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\SeriesSampleDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP5F.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP60.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=400 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/SeriesSample.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\9\SeriesSample\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP60.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP61.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/SeriesSample.pdb" /debug /out:"X86Dbg/SeriesSample.exe" /subsystem:windowsce,4.00 /MACHINE:IX86 
".\X86Dbg\CESeries.obj"
".\X86Dbg\DlgSeriesSetup.obj"
".\X86Dbg\SeriesSample.obj"
".\X86Dbg\SeriesSampleDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\SeriesSample.res"
]
Creating command line "link.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP61.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
CESeries.cpp
DlgSeriesSetup.cpp
SeriesSample.cpp
SeriesSampleDlg.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/SeriesSample.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\CESeries.sbr" ".\X86Dbg\DlgSeriesSetup.sbr" ".\X86Dbg\SeriesSample.sbr" ".\X86Dbg\SeriesSampleDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
SeriesSample.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
