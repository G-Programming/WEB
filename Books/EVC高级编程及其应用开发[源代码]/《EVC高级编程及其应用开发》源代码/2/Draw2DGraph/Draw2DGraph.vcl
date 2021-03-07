<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Draw2DGraph - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP128.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/Draw2DGraph.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP128.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP129.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/Draw2DGraph.pdb" /debug /out:"X86Dbg/Draw2DGraph.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\2DGraph.obj"
".\X86Dbg\Draw2DGraph.obj"
".\X86Dbg\Draw2DGraphDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\Draw2DGraph.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP129.tmp"
<h3>Output Window</h3>
Compiling...
2DGraph.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.h(9) : warning C4067: unexpected tokens following preprocessor directive - expected a newline
F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.cpp(110) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.cpp(111) : warning C4244: '=' : conversion from 'double' to 'long', possible loss of data
F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.cpp(233) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
F:\工作项目\EVC编程入门及项目开发\例子程序\2\Draw2DGraph\2DGraph.cpp(233) : warning C4244: 'argument' : conversion from 'double' to 'int', possible loss of data
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/Draw2DGraph.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\2DGraph.sbr" ".\X86Dbg\Draw2DGraph.sbr" ".\X86Dbg\Draw2DGraphDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
Draw2DGraph.exe - 0 error(s), 5 warning(s)
</pre>
</body>
</html>
