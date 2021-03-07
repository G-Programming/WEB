<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ResDll - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"X86Dbg/Script1.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "_X86_" /d "x86" /d "_i386_" /r "F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDll\Script1.rc"" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3DE.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "_i386_" /D UNDER_CE=300 /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_USRDLL" /D "RESDLL_EXPORTS" /Fp"X86Dbg/ResDll.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDll\ResDll.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3DE.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3DF.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "_i386_" /D UNDER_CE=300 /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_USRDLL" /D "RESDLL_EXPORTS" /Fp"X86Dbg/ResDll.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDll\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3DF.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3E0.tmp" with contents
[
commctrl.lib coredll.lib corelibc.lib /nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:yes /pdb:"X86Dbg/ResDll.pdb" /debug /nodefaultlib:"OLDNAMES.lib" /nodefaultlib:libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib /out:"X86Dbg/ResDll.dll" /implib:"X86Dbg/ResDll.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\ResDll.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\Script1.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3E0.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
ResDll.cpp
Linking...




<h3>Results</h3>
ResDll.dll - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
