# 🏛️ Low-Level Systems & Structural Programming Lab

Ši saugykla nėra tik kodo rinkinys – tai sistemų inžinerijos fundamentų studija. Čia demonstruojami sprendimai, kurie reikalauja gilaus supratimo apie tai, kaip programinė įranga sąveikauja su kompiuterio architektūra.

### 🎯 Inžineriniai prioritetai:
* **Atminties valdymas:** Jokių "memory leaks". Naudoju `Valgrind` ir `GDB` kiekvieno modulio derinimui.
* **Modulinė architektūra:** Griežtas funkcinis skaidymas (`.c` / `.h` atskyrimas) užtikrinant kodo skaitomumą ir testuojamumą.
* **Tinklų stack'as:** Darbas su žemo lygio tinklo sąsajomis (POSIX sockets, TCP/UDP).
* **Efektyvumas:** Algoritmų optimizavimas atsižvelgiant į procesoriaus registrus ir atminties hierarchiją.

### 🛠️ Įrankių grandinė (Toolchain):
* **Compiler:** `GCC` su `-Wall -Wextra -Werror` (tik nulinė tolerancija įspėjimams).
* **Build System:** Custom `Makefiles` automatizuotam kompiliavimui.
* **Analysis:** `Static analysis` ir dinaminis atminties tikrinimas.
