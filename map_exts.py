#!/usr/bin/env python3

content = ""
with open("extensions.h", "r") as f:
    content = f.read()

lines = content.splitlines()
lines_iter = iter(lines)
for index, line in enumerate(lines):
    line = line.strip()
    if line.startswith("/*"):
        language = line[8:].split("-")[0]
        print(language)
        extensions = lines[index + 1].strip()
        print(extensions)
    
