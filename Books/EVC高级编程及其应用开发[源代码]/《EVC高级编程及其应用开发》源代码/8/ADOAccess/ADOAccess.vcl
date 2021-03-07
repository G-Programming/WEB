<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ADOAccess - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE4.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/ADOAccess.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\6\ADOAccess\ADOAccess.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\6\ADOAccess\ADOAccessDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE4.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE5.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/ADOAccess.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\6\ADOAccess\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE5.tmp" 
<h3>Output Window</h3>
Compiling...
StdAfx.cpp
Compiling...
ADOAccess.cpp
ADOAccessDlg.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\6\ADOAccess\ADOAccessDlg.cpp(73) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
F:\工作项目\EVC编程入门及项目开发\例子程序\6\ADOAccess\ADOAccessDlg.cpp(74) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
Generating Code...
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE6.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/ADOAccess.pdb" /debug /out:"X86Dbg/ADOAccess.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\ADOAccess.obj"
".\X86Dbg\ADOAccessDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\ADOAccess.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSPE6.tmp"
<h3>Output Window</h3>
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/ADOAccess.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\ADOAccess.sbr" ".\X86Dbg\ADOAccessDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
ADOAccess.exe - 0 error(s), 2 warning(s)
</pre>
</body>
</html>
