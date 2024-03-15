# algo

This repository contains code snippets of various algorithms to streamline participation in programming contests. Currently, we target the `C++17` language standard.

Run the following command to generate `VS Code` snippets (file `cpp.code-snippets`).

```bash
python3 generate.py --out=<output_folder>
```

Define the following functions in `.bashrc` or `.profile`.

```bash
cps() {
    g++ $1 -o a.out -Wall -Wconversion -Wduplicated-cond -Wextra -Wfloat-equal -Wlogical-op -Wno-sign-conversion -Wno-unused-const-variable -Wshadow -pedantic -std=c++17 -fsanitize=address,undefined -DLOCAL -D_GLIBCXX_DEBUG
    ./a.out
}

cpf() {
    g++ $1 -o a.out -Wall -std=c++17 -O2 -DLOCAL
    ./a.out
}
```

## Credits

The repository has been built upon many sources scattered all over the Internet. To preserve the purpose of templating, all links, proofs, and additional information are placed in `<algorithm_name>.md` files.
