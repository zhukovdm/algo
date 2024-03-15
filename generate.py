import argparse, json, os
from itertools import dropwhile

HPP = "hpp"

SKIPPED_FILES = {
    "debug.hpp"
}

TEMPLATES = {
    "codeforces.cpp",
    "leetcode.cpp"
}

def drop_cpp(_: str):
    return False

def drop_hpp(s: str):
    return s.startswith("#") or s == ""

def main():
    snippets = {}

    parser = argparse.ArgumentParser()
    parser.add_argument("--out", type=str, default=".")

    out = parser.parse_args().out

    for subdir in os.walk("."):
        if ".git" in subdir[0]:
            continue

        for filename in subdir[2]:

            if not "." in filename:
                continue

            name, ext = filename.split(".")

            if filename in SKIPPED_FILES or (ext != HPP and filename not in TEMPLATES):
                continue

            if name in snippets:
                raise Exception(f"duplicated snippet {name}")

            path = f"{subdir[0]}/{filename}"

            with open(path, "r") as file:
                snippet = {
                    "prefix": name,
                    "scope": "cpp",
                    "body": list(dropwhile(drop_hpp if ext == HPP else drop_cpp, [line.rstrip() for line in file.readlines()]))
                }
                snippets[name] = snippet

            print(f"generated snippet {name}")

    with open(f"{out}/cpp.code-snippets", "w") as f:
        f.write(json.dumps(snippets, indent=4))

    print("done")
    return 0

main()
