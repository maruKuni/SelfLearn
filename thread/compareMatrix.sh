#! /bin/bash
if [ -f "resultMatrixSimple.data" ]; then
    rm resultMatrixSimple.data
fi
if [ -f "resultMatrixThread.data" ]; then
    rm resultMatrixThread.data
fi
SIZE=3
while [ ${SIZE} -le 3000 ] 
do
    echo -n "${SIZE} " >> resultMatrixSimple.data
    echo -n "${SIZE} " >> resultMatrixThread.data
    (\time -f "%U %S %e" ./simpleMatrix ${SIZE}) 2>> resultMatrixSimple.data
    (\time -f "%U %S %e" ./T_Matrix_proved ${SIZE}) 2>> resultMatrixThread.data
    SIZE=$((SIZE * 10))
done