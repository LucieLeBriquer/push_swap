# push_swap

## Barême
- Pour 3 values = entre 2 / 3 opérations
- Pour 5 values = max 12
- Pour 100 values = barème de 1 à 5
  - moins de 700: 5
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1 
- Pour 500 values = barème de 1 à 5
  - moins de 5500: 5
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1

## TODO
- arguments dans des strings
- go faire un isomorphisme de [min, max] vers [0, max - min + 1]

## Notes
step1:
- push sur la stackB les elements <= max / 2 E\E1
- repush sur la stackA les elements >= max / 4 E2
- repush sur la stackA les elements >= max / 8 E3
- repush sur la stackA les elements >= max / 16 E4
- repush le reste
- trier E4 en s'aidant de la stackB (du style moit-moit sur les deux stack)
- trier E3 same way
- trier E2 same way
- trier E1 same way