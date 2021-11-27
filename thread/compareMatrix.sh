#! /bin/bash
if [ -f "resultMatrixSimple.data" ]; then
    rm resultMatrixSimple.data
fi
if [ -f "resultMatrixThread.data" ]; then
    rm resultMatrixThread.data
fi
SIZE=5
while [ ${SIZE} -le 5000 ] 
do
    echo -n "${SIZE} " >> resultMatrixSimple.data
    (\time -f "%U %S %e" ./simpleMatrix ${SIZE}) 2>> resultMatrixSimple.data
    SIZE=$((SIZE * 10))
done