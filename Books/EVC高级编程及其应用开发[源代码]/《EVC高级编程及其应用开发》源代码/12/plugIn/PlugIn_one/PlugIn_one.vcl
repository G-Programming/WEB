<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: PlugIn_one - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"X86Dbg/PlugIn_one.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "F:\工作项目\EVC编程入门及项目开发\例子程序\8\plugIn\PlugIn_one\PlugIn_one.rc"" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33B.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /D "_USRDLL" /FR"X86Dbg/" /Fp"X86Dbg/PlugIn_one.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\plugIn\PlugIn_one\PlugIn_one.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33B.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33C.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /D "_USRDLL" /FR"X86Dbg/" /Fp"X86Dbg/PlugIn_one.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\plugIn\PlugIn_one\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33C.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33D.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:yes /pdb:"X86Dbg/PlugIn_one.pdb" /debug /def:".\PlugIn_one.def" /out:"X86Dbg/PlugIn_one.plx" /implib:"X86Dbg/PlugIn_one.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\PlugIn_one.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\PlugIn_one.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP33D.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
PlugIn_one.cpp
Linking...
   Creating library X86Dbg/PlugIn_one.lib and object X86Dbg/PlugIn_one.exp
Creating command line "bscmake.exe /nologo /o"X86Dbg/PlugIn_one.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\PlugIn_one.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
PlugIn_one.plx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
