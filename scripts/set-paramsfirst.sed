#!/bin/sed -f
:loop
$!{
N
/\n$/!b loop
}
s~CUBA~CUDA~g
s~// PARAMS FIRST //~/\* PARAMS FIRST \*/~g
s/,\([ \t\n\r]*\(const [A-Za-z:][A-Za-z:]*Params *\*[^,()]*\(([^()]*)[^()]*\)*\)[ \t\n\r]*\))/,@@@@\1@@@@)/g
s/,\([ \t\n\r]*\(&\?\(this->\)\?m\?_\?[a-z]\?[pP]arams\)[ \t\n\r]*\))/,@@@@\1@@@@)/g
s/,\([ \t\n\r]*\([A-Za-z:][A-Za-z:]*Params::defaultInstance()\)[ \t\n\r]*\))/,@@@@\1@@@@)/g
s/(\([^()]*\(([^()]*\(([^()]*\(([^()]*)[^()]*\)*)[^()]*\)*)[^()]*\)*\),@@@@/(@@@@\1@@@@,@@@@/g
s~(@@@@\( *\)\([^@]*[^@ ]\) *@@@@,@@@@ *\([^@=]*[^@= ]\)\( *=[^@]*\*/\)\( *\)@@@@)~(\1\3\4 /\* PARAMS FIRST \*/, \2\5)~g
s~(@@@@\( *\)\([^@]*[^@ ]\) *@@@@,@@@@ *\([^@=]*[^@= ]\)\( *=[^@]*[^@ ]\)\( *\)@@@@)~(\1\3 /\* PARAMS FIRST \4\*/, \2\5)~g
s~(@@@@\( *\)\([^@]*[^@ ]\) *@@@@,@@@@ *\([^@]*[^@ ]\)\( *\)@@@@)~(\1\3 /\* PARAMS FIRST \*/, \2\4)~g
:comments
s~\(/\*\**\([^\*]*\(\*\**[^/\*]\)*\)*\)/\* PARAMS FIRST \*/~\1 // PARAMS FIRST //~g
t comments
