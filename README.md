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

## Utilisation
```
entries=($(shuf -i 0-1000 -n 100)) && ./push_swap $entries | ./checker $entries
```

## Utilisation du tester
Pour tester pour les tailles `n1` `n2` `n3` : 
```
./tester.sh n1 n2 n3
```
Pour en plus checker les leaks :
```
./tester.sh -v n1 n2 n3
```

## TODO
- split des arguments
- fix la valeur non initialisée