brainfucker
===========

Turns ASCII into Brainfuck programs

Compile
-------

    gcc -o brainfucker brainfucker.c

Run
---

    brainfucker < input > output.bf

Examples
--------

Outputs a Brainfuck program that outputs `foo` when executed.

    echo foo | brainfucker

Outputs its source code.

    brainfucker < brainfucker.c | bf /dev/stdin

ASCII art in Brainfuck.

    brainfucker < ascii-art.txt > ascii-art.bf

Wastes even more time.

    echo foo | brainfucker | brainfucker | brainfucker | brainfucker

License
-------
Released under the Modified BSD License.
