<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: CEComServer - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP42.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "_USRDLL" /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/CEComServer.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\9\CEComServer\CEComServer.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\9\CEComServer\Simple.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP42.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP43.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:yes /pdb:"X86Dbg/CEComServer.pdb" /debug /def:".\CEComServer.def" /out:"X86Dbg/CEComServer.dll" /implib:"X86Dbg/CEComServer.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\CEComServer.obj"
".\X86Dbg\Simple.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\CEComServer.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP43.tmp"
<h3>Output Window</h3>
Compiling...
CEComServer.cpp
Simple.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/CEComServer.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\CEComServer.sbr" ".\X86Dbg\Simple.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
CEComServer.dll - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
