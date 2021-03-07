<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ResDllTest - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"X86Dbg/ResDllTest.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDllTest\ResDllTest.rc"" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F2.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /Fp"X86Dbg/ResDllTest.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDllTest\ResDllTest.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDllTest\ResDllTestDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F2.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F3.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /Fp"X86Dbg/ResDllTest.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\8\ResDllTest\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F3.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F4.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/ResDllTest.pdb" /debug /out:"X86Dbg/ResDllTest.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\ResDllTest.obj"
".\X86Dbg\ResDllTestDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\ResDllTest.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP3F4.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
ResDllTest.cpp
ResDllTestDlg.cpp
Generating Code...
Linking...




<h3>Results</h3>
ResDllTest.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
