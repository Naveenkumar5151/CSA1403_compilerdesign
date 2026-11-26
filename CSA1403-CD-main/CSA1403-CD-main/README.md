# Compiler Design Lab – C Programs (Experiments 1–18)

This project contains the **C-language experiments 1–18** from the supplied Compiler Design lab list.
LEX/FLEX experiments 19–40 are intentionally excluded.

## Requirements
- Visual Studio Code
- GCC compiler (MinGW-w64 on Windows, or GCC on Linux)
- VS Code C/C++ extension (recommended)

Check GCC:
```bash
gcc --version
```

## Project structure
Each experiment has its own folder and `main.c` file. Open this folder in VS Code.

## Compile and run
Open the VS Code terminal in the experiment folder and run:

**Windows PowerShell**
```powershell
gcc main.c -o main.exe
.\main.exe
```

**Linux/macOS**
```bash
gcc main.c -o main
./main
```

For file-based experiments, provide the filename when prompted or use the sample files included in that experiment's folder.

## Experiments
1. Lexical analyzer: identifiers, constants and operators; ignores whitespace and comments
2. Detect whether a given line is a C comment
3. Lexical analyzer that skips whitespace and comments
4. Recognize arithmetic operators (+, -, *, /)
5. Count whitespace and newline characters
6. Validate an identifier
7. FIRST sets for the supplied grammar
8. FOLLOW sets for the supplied grammar
9. Eliminate immediate left recursion for the supplied CFG
10. Eliminate left factoring for the supplied CFG
11. Symbol table operations
12. Recursive-descent parser for the supplied expression grammar
13. Top-down parser: recognizes strings in S -> aSb | ab
14. Generate three-address code for an arithmetic expression
15. Count characters, words and lines in a file
16. Simple compiler back end: translate three-address statements to pseudo-assembly
17. LEADING/FIRSTVT sets for the supplied expression grammar
18. TRAILING/LASTVT sets for the supplied expression grammar

## Notes
- These are educational lab implementations, not production compiler tools.
- Experiment 2 classifies a single input line as a complete `//...` or `/*...*/` comment.
- Experiment 13 uses the clearly stated grammar `S -> aSb | ab`; it demonstrates top-down recursive parsing.
- Experiment 14 supports single-character operands (letters/digits), `+ - * /`, and parentheses.
- Experiment 16 accepts simple three-address statements such as `t1 = a + b`, `t2 = t1 * c`, or `x = t2`.
- Experiments 7, 8, 17 and 18 compute the sets for the exact grammar in the question.

## Push to GitHub
Create an empty repository on GitHub, then run these commands from this project folder:
```bash
git init
git add .
git commit -m "Add Compiler Design Lab C experiments 1-18"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
git push -u origin main
```
Replace the remote URL with your own GitHub repository URL.
