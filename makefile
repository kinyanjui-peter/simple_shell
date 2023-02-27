elf_header:
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 elfdata.c abitypeofelf.c classofelf.c iself.c magic.c main.h osabi.c version.c 100-elf_header.c -o elf_header
