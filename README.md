# push-swap
Ecole 42 project
## number of moves :
| numbers to sort | mean moves |
|---------:|------------:|
| 5 | 6 |
| 100 | 531 |
| 500  | 4021 |
   
## usage :
```
$> ARG=`python3 myrandom.py 1 5` ; echo $ARG > numbers ; ./push_swap $ARG | tee moves |./checker $ARG ; wc -l < moves 
OK
6
$> cat numbers
5 1 3 2 4
$> cat moves
pb
pb
sa
pa
pa
ra
```
