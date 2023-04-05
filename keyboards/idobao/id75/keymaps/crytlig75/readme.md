# Keymap for 75 key (5x15) ortholinear keyboard


```bash
# Setup for Mac M2 -- This could probably be done in Nix-Shell but I am too lazy..
brew tap osx-cross/avr 
brew install avr-gcc     # Setup GCC c & c++
brew install pkg-config  # Add config packages for legacy Python Pillow lib
brew install qmk/qmk/qmk # Install QMK
```

```bash
# Build with make
make idobao/id75/v2:crytlig75
make --jobs=1 idobao/id75/v2:crytlig75
```

```bash
# Build with QMK
qmk compile -kb idobao/id75/v2 -km crytlig75
```

```bash
# Flash

# Paste the following line to terminal and enter.
# When it asks for bootloading mode, press m2+fn
qmk flash -kb idobao/id75/v2 -km crytlig75
```