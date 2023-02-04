# push-swap
Ecole 42 project
## number of moves :
| numbers to sort | mean moves | (min-max)|
|---------:|------------:|:----------:|
| 5 | 8 | (4-10) |
| 100 | 535 | (452-607) |
| 500  | 4040 | (3782-4322) |
   
## usage :
```
$> ARG=`python3 myrandom.py 1 5` ; echo $ARG > numbers ; ./push_swap $ARG | tee moves |./checker $ARG ; wc -l < moves 
OK
6
$> cat numbers
5 1 3 2 4
$> cat moves
>>>>>>> 551808e284575328e7acb539a92e3208d7dfaece
pb
pb
sa
pa
pa
ra
```
